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
#include <rebecca/framework/InnerTemplateListImpl.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/impl/getStringFromSentence.h>
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

class InnerTemplateListImplImpl
{
	public:
		InnerTemplateListImplImpl()
			{ }
		list<InnerTemplate *> m_sentence;

		vector<Tag *> m_tagsToDelete;
		~InnerTemplateListImplImpl()
		{
			for(unsigned int i = 0; i < m_tagsToDelete.size(); ++i)
			{
				delete m_tagsToDelete.at(i);
			}
		}
};

InnerTemplateListImpl::InnerTemplateListImpl()   
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new InnerTemplateListImplImpl)
{
	addInstanceOf("InnerTemplateListImpl");
}
void InnerTemplateListImpl::add(InnerTemplate *tag) 
	throw(InternalProgrammerErrorException &)
{
	m_pimpl->m_sentence.push_back(tag);
}

StringPimpl InnerTemplateListImpl::getString() const
	throw(InternalProgrammerErrorException &)
{
	return getStringFromSentence(m_pimpl->m_sentence);
}

void InnerTemplateListImpl::addCharacters(const StringPimpl &characters) 
	throw(InternalProgrammerErrorException &)
{
	PlainWord *p = new PlainWord(characters);
	m_pimpl->m_tagsToDelete.push_back(p);
	add(p);
}

InnerTemplateListImpl::~InnerTemplateListImpl()
{ 
	delete m_pimpl;
}


} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
