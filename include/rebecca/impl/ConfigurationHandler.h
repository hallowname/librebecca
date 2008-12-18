#ifndef REBECCA_IMPL_CONFIGURATIONHANDLER_H
#define REBECCA_IMPL_CONFIGURATIONHANDLER_H

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
#include <rebecca/framework/Tag.h>

//boost includes
#include <boost/shared_ptr.hpp>

//std includes
#include <stack>
#include <vector>

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif

namespace rebecca
{
namespace impl
{

XERCES_CPP_NAMESPACE_USE
using namespace rebecca::framework;
using namespace boost;
using namespace std;

class ConfigurationHandler : public HandlerBase
{
	public:

		class Input : public Tag
		{
			public:
				Input();
				virtual void handleInnerTag(Tag *tag) 
					throw(InternalProgrammerErrorException &);
		};

		class Substitute : public Tag
		{
			public:
				Substitute();
				virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
					throw(InternalProgrammerErrorException &);
				virtual StringPimpl getFind();
				virtual StringPimpl getReplace();
			private:
				StringPimpl m_find;
				StringPimpl m_replace;
		};
		
		class Gender : public Tag
		{
			public:
				Gender();
				virtual void handleInnerTag(Tag *tag) 
					throw(InternalProgrammerErrorException &);
		};

		class Person : public Tag
		{
			public:
				Person();
				virtual void handleInnerTag(Tag *tag) 
					throw(InternalProgrammerErrorException &);
		};

		class Person2 : public Tag
		{
			public:
				Person2();
				virtual void handleInnerTag(Tag *tag) 
					throw(InternalProgrammerErrorException &);
		};

		class Substitutions : public Tag
		{
			public:
				Substitutions();
		};

		class SentenceSplitters : public Tag
		{
			public:
				SentenceSplitters();
				virtual void handleInnerTag(Tag *tag) 
					throw(InternalProgrammerErrorException &);
		};

		class Splitter : public Tag
		{
			public:
				Splitter();
				virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
					throw(InternalProgrammerErrorException &);
				virtual StringPimpl getValue() { return m_value; }
			
			private:
				StringPimpl m_value;
		};

		class Properties : public Tag
		{
			//Do nothing class.  
			//Needed however to just return when a 
			//<Property> tag is encountered.			
			public:
				Properties();
		};
		
		class Property : public Tag
		{
			public: 
				Property()
				{ }
				virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
					throw(InternalProgrammerErrorException &);
			
			private:
				StringPimpl m_name;
		};

		ConfigurationHandler();

		//Call back's from the sax parser
		virtual void characters(const XMLCh *const chars, const unsigned int length);
		virtual void startElement(const XMLCh* const, AttributeList&);
		virtual void endElement(const XMLCh *const name);
		virtual void endDocument();

		Tag *createTagClass(const string &className);
	private:
		stack<Tag *> m_tagStack;
		Tag *m_currentStartElement;
		vector<Tag *> m_tagsToDelete;

};


} // end of impl namespace
} // end of rebecca namespace

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif
