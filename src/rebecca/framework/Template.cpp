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
#include <rebecca/framework/Template.h>
#include <rebecca/framework/Category.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/getStringFromSentence.h>
using namespace rebecca::impl;

//Std includes
#include <iostream>
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

class TemplateImpl
{
	public:
		TemplateImpl()
		{ }
		vector<Tag *> m_tagsToDelete;
		~TemplateImpl()
		{
			for(unsigned int i = 0; i < m_tagsToDelete.size(); ++i)
			{
				delete m_tagsToDelete.at(i);
			}
		}

		list<InnerTemplate *> m_sentence;
};

Template::Template() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new TemplateImpl)
{
	addInstanceOf("Template");
}

void Template::add(InnerTemplate *tag) 
	throw(InternalProgrammerErrorException &)
{ 	
	m_pimpl->m_sentence.push_back(tag);
}

void Template::addCharacters(const StringPimpl &characters) 
	throw(InternalProgrammerErrorException &)
{
	PlainWord *p = new PlainWord(characters);
	m_pimpl->m_tagsToDelete.push_back(p);
	add(p);
}

void Template::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("InnerTemplate"))
	{
		InnerTemplate *it = static_cast<InnerTemplate *>(tag);
		add(it);
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a InnerTemplate
		throw InternalProgrammerErrorExceptionImpl(
			"[void InnerTemplate::handleInnerTag(Tag *tag)], Bad cast, this is not an InnerTemplate"
				                                  );
	}
}

StringPimpl Template::getString() const
	throw(InternalProgrammerErrorException &)
{
	return getStringFromSentence(m_pimpl->m_sentence);
}

Template::~Template()
{ 
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
