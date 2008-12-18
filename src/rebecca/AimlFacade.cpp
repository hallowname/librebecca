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
#include <rebecca/AimlFacade.h>
#include <rebecca/GraphBuilder.h>
#include <rebecca/impl/Factory.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/DatabaseManager.h>

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
namespace impl
{

AimlFacade::AimlFacade() 
	throw(Exception &)
{
	try
	{
		m_factory = Factory::getInstance();
		///@todo when AimlFacade is multithreaded it'll check if this is the first instance of it and only do this then.
		m_factory = Factory::getInstance()->reset();
		m_graphBuilder = m_factory->createGraphBuilder();
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

GraphBuilder &AimlFacade::getGraphBuilder() 
	throw(Exception &)
{
	return *(m_graphBuilder);
}


AimlFacade &AimlFacade::operator=(const AimlFacade &aimlFacade)
{ 
	///@todo flush this out in the future and expose it as public

	//Do not use this.  It won't work
	return *this;

}

AimlFacade::AimlFacade(const AimlFacade& aimlFacade) 
{ 
	///@todo flush this out in the future and expose it as public
}

void *AimlFacade::operator new(size_t size)
{
	return ::operator new(size);
}

void AimlFacade::operator delete(void* p) 
{
    ::operator delete(p);
}

AimlFacade::~AimlFacade()
{
	///@todo when AimlFacade is multithreaded it'll only delete this if there's no other AimlFacade's around
	delete m_factory;
}

} //end of namespace impl
} //end of namespace rebecca
