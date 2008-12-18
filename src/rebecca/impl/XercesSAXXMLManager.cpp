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
#include <rebecca/impl/XercesSAXXMLManager.h>
#include <rebecca/impl/utils/Transcode.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/TemplateParser.h>

//xerces includes
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
XERCES_CPP_NAMESPACE_USE

//std  includes
#include <string>
using namespace std;

//boost includes
#include <boost/thread/tss.hpp>
using namespace boost;

namespace rebecca
{
namespace impl
{

class XercesSAXXMLManagerImpl
{
	public:
		XercesSAXXMLManagerImpl()
			: m_initializedCorrectly(true)
		{ }

		thread_specific_ptr<SAXParser> m_saxParser;
		thread_specific_ptr<HandlerBase *> m_documentHandler;
		thread_specific_ptr<HandlerBase *> m_errorHandler;
		thread_specific_ptr<StringPimpl> m_fileName;
		static XercesSAXXMLManager *m_instance;
		StringPimpl m_initializedError;
		bool m_initializedCorrectly;
};

//static initialization
XercesSAXXMLManager *XercesSAXXMLManagerImpl::m_instance = 0;

///@todo have this throw the exception out of the constructor and catch it
XercesSAXXMLManager::XercesSAXXMLManager()
	: m_pimpl(new XercesSAXXMLManagerImpl)
{
	try 
	{
		XMLPlatformUtils::Initialize();
	}
	catch(const XMLException &toCatch)
	{
		//ERROR, Caught XMLXMLException exception
		Transcode message(toCatch.getMessage());
		m_pimpl->m_initializedError = message.getString().c_str();
		m_pimpl->m_initializedCorrectly = false;
	}
}

StringPimpl XercesSAXXMLManager::initializedError()
{
	return m_pimpl->m_initializedError;
}

bool XercesSAXXMLManager::initializedCorrectly()
{
	return m_pimpl->m_initializedCorrectly;
}

XercesSAXXMLManager *XercesSAXXMLManager::getInstance()
{
	return XercesSAXXMLManagerImpl::m_instance;
}

void XercesSAXXMLManager::setDocumentHandler(HandlerBase *handler)
{
	if(m_pimpl->m_documentHandler.get() == 0)
	{
		m_pimpl->m_documentHandler.reset(new HandlerBase *);
	}
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}

	(*m_pimpl->m_documentHandler.get()) = handler;
	m_pimpl->m_saxParser->setDocumentHandler(handler);
}

void XercesSAXXMLManager::setErrorHandler(HandlerBase *errorHandler)
{
	if(m_pimpl->m_errorHandler.get() == 0)
	{
		m_pimpl->m_errorHandler.reset(new HandlerBase *);
	}
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}

	(*m_pimpl->m_errorHandler.get()) = errorHandler;
	m_pimpl->m_saxParser->setErrorHandler(errorHandler);
}

void XercesSAXXMLManager::parse(const InputSource &source)
{
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}
	m_pimpl->m_saxParser->parse(source);
}

void XercesSAXXMLManager::setFileBeingParsed(const StringPimpl &fileName)
{
	if(m_pimpl->m_fileName.get() == 0)
	{
		m_pimpl->m_fileName.reset(new StringPimpl);
	}
	*m_pimpl->m_fileName = fileName;
}

StringPimpl XercesSAXXMLManager::getFileBeingParsed()
{
	if(m_pimpl->m_fileName.get() == 0)
	{
		m_pimpl->m_fileName.reset(new StringPimpl);
	}
	return *m_pimpl->m_fileName;
}

void XercesSAXXMLManager::parse(const StringPimpl &fileName)
{
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}
	if(m_pimpl->m_fileName.get() == 0)
	{
		m_pimpl->m_fileName.reset(new StringPimpl);
	}
	*m_pimpl->m_fileName = fileName;
	m_pimpl->m_saxParser->parse(fileName.c_str());
}

StringPimpl XercesSAXXMLManager::parseTemplateString(const StringPimpl templateString)
{
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}

	TemplateParser docHandler;
	m_pimpl->m_saxParser->setDocumentHandler(&docHandler);
	m_pimpl->m_saxParser->setDoSchema(false);
	//m_pimpl->m_saxParser->setDoValidation(false);
	m_pimpl->m_saxParser->setDoNamespaces(false);
	StringPimpl input = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>";
	input += templateString;
	MemBufInputSource mis((const XMLByte*)input.c_str(), 
						   input.size(), 
						   "NodeMapperInMemory", 
						   false);
	m_pimpl->m_saxParser->parse(mis);
	return docHandler.getTemplateString();
}

void XercesSAXXMLManager::setDoSchema(bool trueOrFalse)
{
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}
	m_pimpl->m_saxParser->setDoSchema(trueOrFalse);
}

void XercesSAXXMLManager::setDoValidation(bool trueOrFalse)
{
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}
	//m_pimpl->m_saxParser->setDoValidation(trueOrFalse);
}

void XercesSAXXMLManager::setDoNamespaces(bool trueOrFalse)
{
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}
	m_pimpl->m_saxParser->setDoNamespaces(trueOrFalse);
}

void XercesSAXXMLManager::setExternalSchemaLocation(const StringPimpl &schemaLoc)
{
	if(m_pimpl->m_saxParser.get() == 0)
	{
		m_pimpl->m_saxParser.reset(new SAXParser);
	}
	m_pimpl->m_saxParser->setExternalSchemaLocation(schemaLoc.c_str());
}

XercesSAXXMLManager *XercesSAXXMLManager::reset()
{
	if(XercesSAXXMLManagerImpl::m_instance != 0)
	{
		delete XercesSAXXMLManagerImpl::m_instance;
	}
	XercesSAXXMLManagerImpl::m_instance = new XercesSAXXMLManager();
	return XercesSAXXMLManagerImpl::m_instance;
}

XercesSAXXMLManager::~XercesSAXXMLManager()
{
	delete m_pimpl;
}

} //end namespace impl
} //end namespace rebecca
