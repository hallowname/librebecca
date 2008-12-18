#ifndef REBECCA_FRAMEWORK_INNERTEMPLATELISTIMPL_H
#define REBECCA_FRAMEWORK_INNERTEMPLATELISTIMPL_H

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

//Rebecca includes
#include <rebecca/framework/InnerTemplate.h>


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
class InnerTemplateListImplImpl;

/**
 * Provides the internal data structure of a linked
 * list for InnerTemplates and flushes out the methods
 * of adding and getting from the data structure for convience.
 *
 * This convience class is for other InnerTemplate Tags to inherit
 * from if they want to use a linked list for their 
 * internal data structure.  If your InnerTemplate Tag inherits 
 * from this class it will not have to necessarily flush out
 * InnerTemplate::add() or InnerTemplate::addCharacters() and can
 * call InnerTemplateListImpl::getString() to get the string from
 * within the data structure.
 */
class REBECCA_EXPORT InnerTemplateListImpl : public InnerTemplate
{

	public:

        /** 
		 * Default constructor to initalize 
		 * the private implementation (m_pimpl)
		 * data.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		InnerTemplateListImpl() 
			throw(InternalProgrammerErrorException &); 
		
		/**
		 * Adds the tag to the end of the internal linked list.
		 *
		 * @param tag The tag to add to the internal linked list.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void add(InnerTemplate *tag) 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Iterates through the internal linked list, calls 
		 * InnerTemplate::getString() on each tag, appends the 
		 * output from each and then returns it.
		 *
		 * This is sometimes used by InnerTemplate Tags to get 
		 * the string representation of the InnerTemplate Tags 
		 * that are inside of them.  They then conduct their 
		 * Tag transformation on it and returns that as their 
		 * return value.
		 *
		 * @return The appended text from every InnerTemplate
		 * object in the linked list.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &);
		
		
		/**
		 * Creates a PlainWord object, adds the input characters to it 
		 * and then calls InnerTemplateListImpl::add() with the PlainWord object.
		 * 
		 * @param characters The characters that will be put into a 
		 * PlainWord object and added by calling Template::add() 
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void addCharacters(const StringPimpl &characters) 
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~InnerTemplateListImpl();

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
		InnerTemplateListImplImpl *m_pimpl;
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::InnerTemplateListImpl;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif
