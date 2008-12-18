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
#include <rebecca/framework/AIML.h>
#include <rebecca/impl/GraphHandler.h>
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

class AIMLImpl
{
	public:
		AIMLImpl()
          { } 

		Topic m_defaultStarTopic;
};

AIML::AIML() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new AIMLImpl())
{
	addInstanceOf("AIML");
}

void AIML::setAttribute(const StringPimpl &name, 
						const StringPimpl &value) 
	throw(InternalProgrammerErrorException &)
{
	if(name == "version")
	{
		///@todo use something else instead of this or just leave it out.
		//		m_parser.setAIMLVersion(valueString);
	}
	else
	{
		//Ignore all the rest for right now.  I don't care about any other attributes.
	}
}

void AIML::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("Topic"))
	{
		//Found instance of topic and am ignoring it
	}
	else
	{
		m_pimpl->m_defaultStarTopic.handleInnerTag(tag);	
	}
}

AIML::~AIML() 
{ 
	delete m_pimpl;
}


} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
