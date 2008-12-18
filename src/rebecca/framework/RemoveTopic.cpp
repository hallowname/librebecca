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

//rebecca includes
#include <rebecca/framework/RemoveTopic.h>
#include <rebecca/framework/Category.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/NodeMapper.h>
#include <rebecca/impl/GraphBuilderInternal.h>
#include <rebecca/framework/FrameworkFactory.h>
#include <rebecca/framework/IdentificationManager.h>
using namespace rebecca::impl;

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

class RemoveTopicImpl
{
	public:
		RemoveTopicImpl()
			: m_rootNodeMapper(static_cast<GraphBuilderInternal *>(FrameworkFactory::getInstance()->getGraphBuilderFramework())->getRootNodeMapper())
		{ 
		} 

		NodeMapper &m_rootNodeMapper;
};

RemoveTopic::RemoveTopic() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new RemoveTopicImpl()),
	  Topic()
{
	addInstanceOf("RemoveTopic");
}

void RemoveTopic::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	queue<StringPimpl> wordStack;
	StringPimpl stringCopy;

	if(tag->instanceOf("Category"))
	{
		Category *category = static_cast<Category *>(tag);
		const StringPimpl &patternString = category->getPatternString();
		stringCopy.clear();

		for(unsigned int i = 0; i < getTopic().length(); ++i)
		{
			char c = getTopic().at(i);
			//If space push it onto the stack
			if(c == ' ')
			{
				stringCopy.transformByTrimmingWhiteSpace();
				if(!stringCopy.empty()) 
				{
					stringCopy.transformByTrimmingWhiteSpace();
					wordStack.push(stringCopy);
					stringCopy.clear();
				}
			}
			else
			{
				//Haven't found the full word yet.
				//Just add the character and keep going.
				//convert it to upper case
				stringCopy.push_back(toupper(c));
			}
		}
		stringCopy.transformByTrimmingWhiteSpace();
		if(!stringCopy.empty()) 
		{
			wordStack.push(stringCopy);
            stringCopy.clear();
		}
		wordStack.push("<TOPIC>");

		const StringPimpl &thatString = category->getThatString();
		for(unsigned int i = 0; i < thatString.length(); ++i)
		{
			char c = thatString.at(i);
			//If space push it onto the stack
			if(c == ' ')
			{
				stringCopy.transformByTrimmingWhiteSpace();
				if(!stringCopy.empty()) 
				{
					wordStack.push(stringCopy);
					stringCopy.clear();
				}
			}
			else
			{
				//Haven't found the full word yet.
				//Just add the character and keep going.
				//convert it to upper case
				stringCopy.push_back(toupper(c));
			}
		}
		stringCopy.transformByTrimmingWhiteSpace();
		if(!stringCopy.empty()) 
		{
			wordStack.push(stringCopy);
			stringCopy.clear();
		}
		wordStack.push("<THAT>");

		for(unsigned int i = 0; i < patternString.length(); ++i)
		{
			char c = patternString.at(i);
			//If space push it onto the stack
			if(c == ' ')
			{
				stringCopy.transformByTrimmingWhiteSpace();
				if(!stringCopy.empty()) 
				{
					wordStack.push(stringCopy);
					stringCopy.clear();
				}
			}
			else
			{
				//Haven't found the full word yet.
				//Just add the character and keep going.
				//Convert it to upper case 
				stringCopy.push_back(toupper(c));
			}
		}
		stringCopy.transformByTrimmingWhiteSpace();
		if(!stringCopy.empty()) 
		{
			wordStack.push(stringCopy);
		}
		
		//push the user id and the bot id onto the stack
		wordStack.push("<USERID>");
		wordStack.push(IdentificationManager::getInstance()->getUserId());
		wordStack.push("<BOTID>");
		wordStack.push(IdentificationManager::getInstance()->getBotId());
		m_pimpl->m_rootNodeMapper.remove(wordStack);
	}
	else if(tag->instanceOf("Topic"))
	{
		//We have encountered a topic tag.  Ignoring it
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a Category or Topic
		throw InternalProgrammerErrorExceptionImpl(
			"[void RemoveTopic::handleInnerTag(Tag *tag)], Bad cast, this is not a Category or Topic"
				                                  );
	}
}

RemoveTopic::~RemoveTopic()
{
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
