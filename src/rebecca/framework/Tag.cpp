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
#include <rebecca/framework/Tag.h>

//Std includes
#include <map>
#include <string>
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

using namespace rebecca::impl;

class TagImpl
{
	public:
		map<string, bool> m_instances;
};


Tag::Tag() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new TagImpl)
{
	addInstanceOf("Tag");
}

void Tag::addInstanceOf(const char * const instance) throw(InternalProgrammerErrorException &)
{
	m_pimpl->m_instances.insert(pair<string, bool>(instance, true));
}



void Tag::addCharacters(const StringPimpl &characters) throw(InternalProgrammerErrorException &)
{ }

void Tag::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{ }

void Tag::setAttribute(const StringPimpl &name, const StringPimpl &value) throw(InternalProgrammerErrorException &)
{ }

bool Tag::instanceOf(const char * const instance) const
	throw(InternalProgrammerErrorException &)
{
	typedef map<string, bool>::const_iterator CI;
	CI it = m_pimpl->m_instances.find(instance);
	if(it != m_pimpl->m_instances.end())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void *Tag::operator new(size_t size)
{
	return ::operator new(size);
}

void Tag::operator delete(void* p) 
{
    ::operator delete(p);
}


Tag::~Tag() 
{ 
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
