#ifndef REBECCA_IMPL_GRAPHHANDLER_H
#define REBECCA_IMPL_GRAPHHANDLER_H

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

//Xerces includes
#include <xercesc/sax/HandlerBase.hpp>

//Rebecca includes
#include <rebecca/impl/NodeMapper.h>
#include <rebecca/framework/Tag.h>

//Boost includes
#include <boost/shared_ptr.hpp>

//std includes
#include <stack>

namespace rebecca
{
namespace impl
{

XERCES_CPP_NAMESPACE_USE
using namespace boost;
using namespace rebecca;
using namespace std;

class GraphHandler : public HandlerBase
{
	public:

		//Call back's from the sax parser

		GraphHandler(NodeMapper &root);
		virtual void characters(const XMLCh *const chars, const unsigned int length);
		virtual void startElement(const XMLCh* const, AttributeList&);
		virtual void endElement(const XMLCh *const name);
		virtual void endDocument();
		virtual void startDocument();
		//Regular additional public members.

		virtual void setAIMLVersion(const string &version);
		virtual string getAIMLVersion();
		virtual ~GraphHandler() { }

	protected:
		vector<Tag *> m_tagsToDelete;
		int m_size;

	private:
		StringPimpl m_templateString;
		bool m_beginTemplate;

		virtual Tag *createTagClass(const StringPimpl &className);

		stack<Tag *> m_tagStack;
		string m_aimlVersion;

		/**
		 * Reference to the root of the 
		 * NodeMapper tree. As the parser 
		 * encounters <category>
		 * tags, it will begin construction of a 
		 * new node and latter when it encounters a 
		 * </category> tag it will add it to the rootNode.
		 * This is just a reference.  It's location should
		 * reside within a GraphBuilderInternal instance.
		 */
		NodeMapper &m_rootNodeMapper;
		
		/**
		 * Current node being constructed.
		 *
		 */		
		shared_ptr<NodeMapper> m_currentNode;
		Tag *m_currentStartElement;


		bool m_templateSideThat;
};


} // end of impl namespace
} // end of rebecca namespace
#endif
