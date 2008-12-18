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
#include <rebecca/framework/Li.h>
#include <rebecca/framework/PlainWord.h>
using namespace rebecca::impl;

//Std includes
#include <exception>
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

class LiImpl
{
	public:

		LiImpl()
			: m_name(false),
			  m_value(false)
		{ }

		StringPimpl m_predicateName;
		StringPimpl m_aimlPattern;
		bool m_name;
		bool m_value;
};

Li::Li() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new LiImpl)
{
	addInstanceOf("Li");
}

StringPimpl Li::getPredicateName() const
	throw(InternalProgrammerErrorException &)
{ 
	return m_pimpl->m_predicateName; 
}

StringPimpl Li::getAimlPattern() const
	throw(InternalProgrammerErrorException &)
{ 
	return m_pimpl->m_aimlPattern; 
}

bool Li::isDefaultListItem() const
	throw(InternalProgrammerErrorException &)
{
	return ((!m_pimpl->m_name) && (!m_pimpl->m_value));
}

bool Li::isValueOnlyListItem() const
	throw(InternalProgrammerErrorException &)
{
	return (m_pimpl->m_value && !m_pimpl->m_name);
}

bool Li::isNameAndValueListItem() const
	throw(InternalProgrammerErrorException &)
{
	return m_pimpl->m_value && m_pimpl->m_name;
}

void Li::setAttribute(const StringPimpl &name, const StringPimpl &value) 
	throw(InternalProgrammerErrorException &)
{
	if(name == "name" && !value.empty())
	{
		//It has a name attribute so mark that true
		m_pimpl->m_name = true;
		m_pimpl->m_predicateName = value;
	}
	else if(name == "value")
	{
		//It has a value attribute so mark that true
		m_pimpl->m_value = true;
		m_pimpl->m_aimlPattern = value;
	}
	else
	{
		//Warning, empty name and/or empty value given or invalid values given
	}
}

Li::~Li()
{ 
	delete m_pimpl;
}



} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
