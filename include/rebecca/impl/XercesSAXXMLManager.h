#ifndef XERCESSAXMLMANAGER_IMPL_GRAPHHANDLER_H
#define XERCESSAXMLMANAGER_IMPL_GRAPHHANDLER_H

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
#include <rebecca/StringPimpl.h>

//xerces includes
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
namespace rebecca
{
namespace impl
{
XERCES_CPP_NAMESPACE_USE

class XercesSAXXMLManagerImpl;

class XercesSAXXMLManager
{
	public:	
		static XercesSAXXMLManager *getInstance();
		StringPimpl initializedError();
		bool initializedCorrectly();
		static XercesSAXXMLManager *reset();
		void setDocumentHandler(HandlerBase *handler);
		void setErrorHandler(HandlerBase *errorHandler);
		void parse(const InputSource &source);
		void setDoSchema(bool trueOrFalse);
		void setDoValidation(bool trueOrFalse);
		void setDoNamespaces(bool trueOrFalse);
		void setExternalSchemaLocation(const StringPimpl &schemaLoc);
		void parse(const StringPimpl &fileName);
		StringPimpl parseTemplateString(const StringPimpl templateString);
		void setFileBeingParsed(const StringPimpl &fileName);
		StringPimpl getFileBeingParsed();
		~XercesSAXXMLManager();
	private:
		XercesSAXXMLManagerImpl *m_pimpl;
		XercesSAXXMLManager();
};

} //end namespace impl
} //end namespace rebecca


#endif


