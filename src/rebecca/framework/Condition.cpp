/*
 * RebeccaAIML, Artificial Intelligence Markup Language 
 * C++ api and engine.
 *
 * Copyright (C) 2005,2006,2007 Frank Hassanabad
 *
 * This file is part of RebeccaAIML.
 *
 * RebeccaAIML is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * RebeccaAIML is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//Rebecca includes
#include <rebecca/framework/Condition.h>
#include <rebecca/framework/Set.h>
#include <rebecca/framework/Li.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/getStringFromSentence.h>
#include <rebecca/framework/FrameworkFactory.h>
using namespace rebecca::impl;

//std includes
#include <vector>
using namespace std;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
#endif


namespace rebecca
{
namespace framework
{
namespace impl
{

class ConditionImpl
{
	public:
		ConditionImpl() 
			: m_name(false),
			  m_value(false)
		{ } 

		list<InnerTemplate *> m_sentence;
		StringPimpl m_predicateName;
		StringPimpl m_aimlPattern;
		bool m_value;
		bool m_name;
		vector<Tag *> m_tagsToDelete;
		~ConditionImpl()
		{
			for(unsigned int i = 0; i < m_tagsToDelete.size(); ++i)
			{
				delete m_tagsToDelete.at(i);
			}
		}
};


Condition::Condition()   
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new ConditionImpl)
{
	addInstanceOf("Condition");
}

void Condition::setAttribute(const StringPimpl &name, const StringPimpl &value) 
	throw(InternalProgrammerErrorException &)
{
	if(name == "name")
	{
		m_pimpl->m_name = true;
		m_pimpl->m_predicateName = value;
	}
	else if(name == "value")
	{
		m_pimpl->m_value = true;
		m_pimpl->m_aimlPattern = value;
	}
	else
	{
		//Warning, empty name and/or empty value given or invalid values given
	}
}

void Condition::addCharacters(const StringPimpl &characters) 
	throw(InternalProgrammerErrorException &)
{
	PlainWord *p = new PlainWord(characters);
	m_pimpl->m_tagsToDelete.push_back(p);
	add(p);
}


void Condition::add(InnerTemplate *tag) 
	throw(InternalProgrammerErrorException &)
{
	m_pimpl->m_sentence.push_back(tag);
}

StringPimpl Condition::getString() const
	throw(InternalProgrammerErrorException &)
{
	if(this->isBlockCondition())
	{
		if(FrameworkFactory::getInstance()->getGraphBuilderFramework()->predicateMatch(m_pimpl->m_predicateName, m_pimpl->m_aimlPattern))
		{
			//Matched the aimlpattern to the predicate's pattern");
			//Returning the string
			return getStringFromSentence(m_pimpl->m_sentence);
		}
		else
		{
			//Did not match the aimlpattern, returning empty string
			return StringPimpl();
		}
	}
	else 
	{
		//This is either a single or multi-predicate condition
		
		typedef list<InnerTemplate *>::const_iterator CI;

		for(CI it = m_pimpl->m_sentence.begin(); it != m_pimpl->m_sentence.end(); ++it) 
		{
			if((*it)->instanceOf("Li"))
			{
				Li *li = static_cast<Li *>(*it);
				StringPimpl liPredicateName = li->getPredicateName();
				StringPimpl liAimlPattern = li->getAimlPattern();

				if(li->isDefaultListItem())
				{
					//Encountered default list item.  Returning its string
					return li->getString().transformByTrimmingWhiteSpace();
				}
				else if(this->isSinglePredicateCondition())
				{
					//This is a single Predicate condition
					if(FrameworkFactory::getInstance()->getGraphBuilderFramework()->predicateMatch(m_pimpl->m_predicateName, liAimlPattern))
					{
						return (*it)->getString().transformByTrimmingWhiteSpace();
					}
				}
				else if(isMutliPredicateCondition())
				{
					//This is a multi-predicate condition
					if(FrameworkFactory::getInstance()->getGraphBuilderFramework()->predicateMatch(liPredicateName, liAimlPattern))
					{
						return (*it)->getString().transformByTrimmingWhiteSpace();
					}
				}
				else
				{
					//Inernal programmer Error, the condition block code is corrupted
					throw InternalProgrammerErrorExceptionImpl("[StringPimpl Condition::getString()] Condition block code is corrupted.");
					return StringPimpl();
				}
			}
			else if((*it)->instanceOf("PlainWord"))
			{
				//Check for plain word.  If it is a plain word skip to the next
				continue;	
			}
			else
			{
				//Not a plain word, something else.  Throw a bad cast.
				//Internal programmer error.  Bad cast, was expecting a Li
				throw InternalProgrammerErrorExceptionImpl("[StringPimpl Condition::getString() const].  Bad cast, was expecting a Li");
				return StringPimpl();
			}
		}
			
		//Nothing matched. Returning empty string
		return StringPimpl();

	}
}

bool Condition::isBlockCondition() const
	throw(InternalProgrammerErrorException &)
{
	return m_pimpl->m_name && m_pimpl->m_value;
}

bool Condition::isSinglePredicateCondition() const
	throw(InternalProgrammerErrorException &)
{
	return ( m_pimpl->m_name && (!m_pimpl->m_value) );
}

bool Condition::isMutliPredicateCondition() const
	throw(InternalProgrammerErrorException &)
{
	return ( (!m_pimpl->m_name) && (!m_pimpl->m_value) );
}

Condition::~Condition()
{
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
