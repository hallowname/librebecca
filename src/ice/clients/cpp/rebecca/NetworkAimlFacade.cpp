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
#include <rebecca/NetworkAimlFacade.h>
#include <rebecca/impl/NetworkGraphBuilderAIML.h>
#include <rebecca/impl/ExceptionImpl.h>

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

NetworkAimlFacade::NetworkAimlFacade(int argc, char *argv[]) 
	throw(NetworkException &, Exception &)
{
	try
	{
        #ifdef _WIN32
		locale::global(locale("ENG"));
        #endif
		m_graphBuilder = new NetworkGraphBuilderAIML(argc, argv);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}

	/*
	 * The other exception that can be thrown will be the NetworkExceptionImpl, 
	 * we'll let that exception propage out and not try and catch it. 
	 */
}

NetworkGraphBuilder &NetworkAimlFacade::getNetworkGraphBuilder() throw()
{
	return *(m_graphBuilder);
}


NetworkAimlFacade &NetworkAimlFacade::operator=(const NetworkAimlFacade &networkAimlFacade)
{ 
	///@todo flush this out in the future and expose it as public

	//Do not use this.  It won't work
	return *this;

}

NetworkAimlFacade::NetworkAimlFacade(const NetworkAimlFacade& networkAimlFacade) 
{ 
	///@todo flush this out in the future and expose it as public
}

void *NetworkAimlFacade::operator new(size_t size)
{
	return ::operator new(size);
}

void NetworkAimlFacade::operator delete(void* p) 
{
    ::operator delete(p);
}

NetworkAimlFacade::~NetworkAimlFacade()
{
	NetworkGraphBuilderAIML *builder = dynamic_cast<NetworkGraphBuilderAIML *>(m_graphBuilder);
	if(builder)
	{
		builder->destroy();
	}
	else
	{
		//can't do anything.  Just move on
	}
	delete m_graphBuilder;
}

} //end of namespace impl
} //end of namespace rebecca
