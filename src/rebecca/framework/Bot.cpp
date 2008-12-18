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
#include <rebecca/framework/Bot.h>
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

class BotImpl 
{
	public:
		BotImpl()
		{ }
	StringPimpl m_botPredicateName;
};

Bot::Bot()   
	throw(InternalProgrammerErrorException &)
	: InnerTemplate(), 
	  m_pimpl(new BotImpl())
{
	addInstanceOf("Bot");
}

StringPimpl Bot::getString() const 
	throw(InternalProgrammerErrorException &)
{
	return FrameworkFactory::getInstance()->getGraphBuilderFramework()->getBotPredicate(m_pimpl->m_botPredicateName);
}

void Bot::setAttribute(const StringPimpl &name, 
					   const StringPimpl &value) 
	throw(InternalProgrammerErrorException &)
{
	if(name == "name" && (!value.empty()))
	{
		m_pimpl->m_botPredicateName = value;
	}
}

Bot::~Bot()
{ 
	delete m_pimpl;
}


} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
