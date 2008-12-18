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
#include <rebecca/framework/Srai.h>
#include <rebecca/framework/FrameworkFactory.h>
#include <rebecca/framework/IdentificationManager.h>
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

Srai::Srai() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(0)
{
	addInstanceOf("Srai");
}	

StringPimpl Srai::getString() const
	throw(InternalProgrammerErrorException &)
{
	try
	{
		StringPimpl sentence = InnerTemplateListImpl::getString();	
		StringPimpl returnString;

		if(sentence.empty())
		{
			//Warning returning empty string
		}
		else
		{
			FrameworkFactory *factory = FrameworkFactory::getInstance();
			IdentificationManager *ident = IdentificationManager::getInstance();
			GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
			builder->getCallBacks().symbolicReduction(sentence, ident->getUserId(), ident->getBotId(), ident->getEndUserId());
			returnString = builder->checkedInfiniteLoopGetResponse(sentence, false);
		}

		return returnString;
	}
	catch(RecursionException &)
	{
		//Infinite Symbolic Recursion detected
		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().infiniteSymbolicReduction(ident->getUserId(), ident->getBotId(), ident->getEndUserId());
		return StringPimpl();
	}
	catch(Exception &)
	{
		//Fatal exception occured
		return StringPimpl();
	}
}
Srai::~Srai()
{ 
}


} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
