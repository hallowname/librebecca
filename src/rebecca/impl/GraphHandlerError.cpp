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
#include <rebecca/impl/GraphHandlerError.h>
#include <rebecca/impl/utils/Transcode.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/GraphBuilderAIML.h>
#include <rebecca/framework/FrameworkFactory.h>
#include <rebecca/framework/IdentificationManager.h>

//Boost includes
#include <boost/lexical_cast.hpp>
using namespace boost;


//Xerces includes
#include <xercesc/parsers/SAXParser.hpp>
XERCES_CPP_NAMESPACE_USE


namespace rebecca
{
namespace impl
{

using namespace std;

void GraphHandlerError::fatalError(const SAXParseException& exc)
{
	try
	{
		Transcode sysId(exc.getSystemId());
		Transcode message(exc.getMessage());
		string msg(message.getChar()); 
		msg += ", System Id: " + sysId.getString();
		msg += " at line: " + lexical_cast<string>(exc.getLineNumber());
		msg += " at column: " + lexical_cast<string>(exc.getColumnNumber());

		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().XMLParseFatalError(msg.c_str(), ident->getUserId(), ident->getBotId(), ident->getEndUserId());
	}
	catch(bad_lexical_cast &)
	{
		throw InternalProgrammerErrorExceptionImpl("bad lexical cast within SAXParseException");
	}
}

void GraphHandlerError::warning(const SAXParseException &exc)
{
	try
	{
		Transcode sysId(exc.getSystemId());
		Transcode message(exc.getMessage());
		string msg(message.getChar()); 
		msg += ", System Id: " + sysId.getString();
		msg += " at line: " + lexical_cast<string>(exc.getLineNumber());
		msg += " at column: " + lexical_cast<string>(exc.getColumnNumber());

		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().XMLParseWarning(msg.c_str(), ident->getUserId(), ident->getBotId(), ident->getEndUserId());
	}
	catch(bad_lexical_cast &)
	{
		throw InternalProgrammerErrorExceptionImpl("bad lexical cast within SAXParseException");
	}
}

void GraphHandlerError::error(const SAXParseException &exc)
{

	try
	{
		Transcode sysId(exc.getSystemId());
		Transcode message(exc.getMessage());
		string msg(message.getChar()); 
		msg += ", System Id: " + sysId.getString();
		msg += " at line: " + lexical_cast<string>(exc.getLineNumber());
		msg += " at column: " + lexical_cast<string>(exc.getColumnNumber());

		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().XMLParseError(msg.c_str(), ident->getUserId(), ident->getBotId(), ident->getEndUserId());
	}
	catch(bad_lexical_cast &)
	{
		throw InternalProgrammerErrorExceptionImpl("bad lexical cast within SAXParseException");
	}
}




} // end of impl namespace
} // end of rebecca namespace
