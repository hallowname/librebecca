#ifndef REBECCA_FRAMEWORK_AIML_H
#define REBECCA_FRAMEWORK_AIML_H

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
#include <rebecca/framework/Tag.h>
#include <rebecca/framework/Topic.h>

/* Disable Windows VC 7.x warning about 
 * shared_ptr needing dll-interface and
 * about it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4251 )
#    pragma warning( disable : 4290 )
#endif

namespace rebecca
{
namespace framework
{
namespace impl
{

/*
 * Forward declarations
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
class AIMLImpl;

class GraphBuilderFramework;

/**
 * AIML class that represents the 
 * AIML XML tag "aiml".  
 *
 * Every time a XML Tag of AIML is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 */
class REBECCA_EXPORT AIML : public Tag
{
	
	public:

		/** 
		 * Initalizes the private 
		 * implementation (m_pimpl) data and 
		 * sets the private implementation 
		 * with a reference to the 
		 * GraphBuilderFramework.  
         *
		 * Also creates a default Topic object which 
		 * is important for AIML::handleInnerTag
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		AIML() 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Sets its attribute of "version"
         *
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void setAttribute(const StringPimpl &name, 
			                      const StringPimpl &value) 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Calls its internal default Topic Object's Topic::handleInnerTag() 
		 * with this AIML XML tag.
		 *
		 * Whenever the AIML Tag encounters an inner AIML XML Tag it's always either a Category
		 * Tag or a Topic Tag.  If it is a Category Tag it sends the Tag to its internal default 
		 * Topic Tag object by calling its internal Topic Tag's handleInnerTag.  If it is a 
		 * Topic Tag it safetly ignores it.  The default Topic Tag is a Topic Tag with its topic 
		 * set to "*".  When a Topic is not specified in AIML XML, it is to default to "*".  When a 
		 * Topic is not specified, this handleInnerTag gets called with a Category Tag object which 
		 * in turn calls the internal default Topic Tag with the Category Tag object.  When a Topic 
		 * is specified AIML's handleInnerTag gets called with a Topic Object and safetly ignores 
		 * it since it does not need to do anything with it.
		 *
		 * @param tag The Category Tag or Topic Tag
		 *
         * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~AIML();

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
		AIMLImpl *m_pimpl;
};


} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::AIML;

} //end of namespace framework 
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

