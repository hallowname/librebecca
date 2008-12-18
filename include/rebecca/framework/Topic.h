#ifndef REBECCA_FRAMEWORK_TOPIC_H
#define REBECCA_FRAMEWORK_TOPIC_H

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

/* Disable Windows VC 7.x warning about 
 * shared_ptr needing dll-interface and
 * about it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4251 )
#    pragma warning( disable : 4290 )
#endif

//rebecca includes
#include <rebecca/framework/InnerAIML.h>

namespace rebecca
{
namespace framework
{
namespace impl
{

/*
 * Forward declerations
 */

/**
 * The private implementation in which
 * you cannot get access to.
 *
 * This class holds the private methods
 * and private attributes of this class.  This 
 * makes ABI (Application Binary Interface) more
 * resilient to change. See the private implementation
 * idiom on the internet for more information about this.
 */
class TopicImpl;

class GraphBuilderFramework;

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
 */
class REBECCA_EXPORT Topic : public InnerAIML
{

	public:

		/** 
		 * Initalizes the private 
		 * implementation (m_pimpl) data and 
		 * sets the private implementation 
		 * with a reference to the 
		 * GraphBuilderFramework.  
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		Topic() 
			throw(InternalProgrammerErrorException &);

		/**
		 * Recieves Category objects in which it adds to the node mapper internal data structure.
		 * 
		 * This method first checks tag through Tag::instanceOf() to ensure it is an object of 
		 * type Category.  If it is not, it will throw a 
		 * rebecca::impl::InternalProgrammerErrorException.  Otherwise it will manipulate and add
		 * the object to the internal node mapper data structure.  The node mapper data structure
		 * is the final step to adding information to the AIML brain.  
		 * 
		 * If this class is inherited from and completely replaced, and yet this handleInnerTag is
		 * *never* called, no information will ever be added to the AIML brain.  This method of 
		 * this class has to be called with a Category object to have the information added to the
		 * AIML brain.
		 * 
		 * @param tag The Category tag which is added to the internal node mapper data structure.
		 *
         * @exception InternalProgrammerErrorException is thrown if the tag is not 
		 * an instance of Category.
		 */
		virtual void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &);

		/**
		 * Sets the attribute "name" to a value.
		 *
		 * The name value attribute determines what type of Topic this is.  If no attribute is given and
		 * this object is instantiated without a name value pair, it will default to "*" according to the
		 * AIML specification.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * if the name attribute is not that of "name"
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the current topic set
		 * through setAttribute
		 *
		 * @return Returns the current topic
		 * 
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual StringPimpl getTopic()
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~Topic();

	private:

	   /**
		* The private implementation in which
		* you cannot get access to.
		*
		* This pointer holds the private methods  
		* and private member variables of this class.  This 
		* makes ABI (Application Binary Interface) more
		* resilient to change. See the private implementation
		* idiom on the internet for more information about this.
		*/
		TopicImpl *m_pimpl;
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::Topic;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

