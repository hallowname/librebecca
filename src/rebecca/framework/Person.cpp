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
#include <rebecca/framework/Person.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/framework/Star.h>
#include <rebecca/framework/FrameworkFactory.h>
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

class PersonImpl
{
	public:
		PersonImpl() 
			: m_atomic(true) 
		{ }

		bool m_atomic;
		~PersonImpl() { } 
};

Person::Person() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new PersonImpl)
{
	addInstanceOf("Person");
}

void Person::addCharacters(const StringPimpl &characters) throw(InternalProgrammerErrorException &)
{
	m_pimpl->m_atomic = false;	
	InnerTemplateListImpl::addCharacters(characters);
}

StringPimpl Person::getString() const
	throw(InternalProgrammerErrorException &)
{
	try
	{
		if(m_pimpl->m_atomic)
		{
			//This is an atomic element shortcut
			Star star;
			StringPimpl returnString = star.getString();
			return FrameworkFactory::getInstance()->getGraphBuilderFramework()->personSubstitute(returnString);
		}
		else
		{
			return FrameworkFactory::getInstance()->getGraphBuilderFramework()->personSubstitute(InnerTemplateListImpl::getString());
		}
	}
	catch(Exception &)
	{
		//Fatal exception occured
		return StringPimpl();
	}
}
Person::~Person()
{ 
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
