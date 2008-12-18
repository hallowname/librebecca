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
#include <rebecca/framework/Learn.h>
#include <rebecca/framework/FrameworkFactory.h>
#include <rebecca/framework/IdentificationManager.h>
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

Learn::Learn() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(0)
{
	addInstanceOf("Learn");
}

StringPimpl Learn::getString() const
	throw(InternalProgrammerErrorException &)
{
	try
	{
		StringPimpl fileToLoad = InnerTemplateListImpl::getString();
		FrameworkFactory::getInstance()->getGraphBuilderFramework()->addFile(fileToLoad);
		FrameworkFactory::getInstance()->getGraphBuilderFramework()->createGraph();
	} 
	catch(FileNotFoundException &e)
	{
		//absorb file not found exception, call the callback and keep going
		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().learnTagFileNotFound(e.what(), ident->getUserId(), ident->getBotId(), ident->getEndUserId());
	}
	catch(XMLErrorException &)
	{
		//absorb the xml error exception and keep going
	}
	catch(Exception &)
	{
		//absorb the general exception and keep going
	}

	//learn returns an empty string
	return StringPimpl();
}

Learn::~Learn()
{ 
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
