#ifndef CUSTOMHTML_TAG_LAYER_CUSTOMTOPIC_H
#define CUSTOMHTML_TAG_LAYER_CUSTOMTOPIC_H

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
#include <rebecca/framework/Topic.h>
#include <rebecca/StringPimpl.h>
#include <rebecca/framework/GraphBuilderFramework.h>

//Custom Tag includes
#include "exports.h"
#include "typedefs.h"

//Std includes
#include <iostream>
#include <string>
#include <map>

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
#endif

namespace customTag
{
namespace impl
{

using namespace rebecca::framework;
using namespace rebecca;
using namespace std;

/*
 * Forward declerations
 */
class Html;

/**
 * AIML class that represents the 
 * AIML XML tag "topic".  
 *
 * Every time a XML Tag of Topic is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 *
 * This is my custom version of the AIML 
 * XML Tag Topic. I use this custom version to
 * write the information that normally goes to
 * the Internal AIML data strucuture for the 
 * AIML brain to web pages instead.
 * 
 */
class CUSTOM_TAG_EXPORT CustomTopic : public Topic
{
	/**
	 * Typedef a map of strings and file stream
	 * to a easier to use reference
	 */
	typedef map<string, ofstream *> fileStringMap;
	
	public:
		
		/**
		 * Set the internal GraphBuilderFramework and the 
		 * internal Html object references which this class
		 * requires to operate.
		 *
		 * Also initialized the default Topic, m_topic to "*" 
		 * 
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 *
		 * @param htmlPage A reference to the Html page
		 * object used to set and get information on html
		 * pages.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		CustomTopic(Html &htmlPage)
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Recieves Category objects in which it adds to the Html object, m_htmlPage.
		 * 
		 * This method first checks tag through Tag::instanceOf() to ensure it is an object of 
		 * type Category.  If it is not, it will throw a 
		 * rebecca::impl::InternalProgrammerErrorException.  Otherwise it will manipulate and add
		 * the object to the Html Object.  
		 * 
		 * @param tag The Category tag which is added to the Html object.
		 *
         * @exception InternalProgrammerErrorException is thrown if the tag is not 
		 * an instance of Category.
		 */
		void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Sets the attribute "name" to a value.
		 *
		 * The name value attribute determines what type of Topic this is.  If no attribute is given and
		 * this object is instantiated without a name value pair, it will default to "*" according to the
		 * AIML specification.
		 *
		 * This is overriden to gain access to the value of the name attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * if the name attribute is not that of "name"
		 */
		void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &);

	private:

		/**
		 * The topic.  By default it is "*" by 
		 * the AIML specification.
		 */
		string m_topic;

		/**
		 * Html Object to manipulate and add information
		 * for the web pages.
		 */
		Html &m_htmlPage;
};

} //end of namespace impl
} //end namespace customTag

#endif


