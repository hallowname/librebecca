#ifndef REBECCA_FRAMEWORK_TEMPLATE_H
#define REBECCA_FRAMEWORK_TEMPLATE_H

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
#    pragma warning( disable : 4290 )
#    pragma warning( disable : 4251 )
#endif

//Rebecca includes
#include <rebecca/framework/InnerCategory.h>

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
class TemplateImpl;
class InnerTemplate;

/**
 * AIML class that represents the 
 * AIML XML tag "template".  
 *
 * Every time a XML Tag of AIML is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 */
class REBECCA_EXPORT Template : public InnerCategory
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
		Template() 
			throw(InternalProgrammerErrorException &);

		/** 
         * Adds the tag to an internal data structure.
		 *
		 * This method goes hand-in-hand with Template::getString().
		 * This adds the InnerTemplate Tag to the data structure.
		 * Template::getString() retrieves the template's string 
		 * from the data structure.
		 *
		 * The internal data stucture is usually a linked list or
		 * vector of InnerTemplate.  Each new tag is added to 
		 * the end of the data structure.
		 *
		 * @param tag The tag to add to the internal data structure. 
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void add(InnerTemplate *tag) 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Iterates through the internal data structure and calls
		 * InnerTemplate::getString() on each element appending the
		 * output from each call and then returning the appended output.
		 * 
		 * The internal data stucture is usually a linked list or
		 * vector of InnerTemplate.  This method of is usually what the
		 * internal NodeMapper calls to get the response from 
		 * the AIML engine after it does path matching on user input.
		 * 
		 * @return The string after calling InnerTemplate::getString()
		 * on each element of the internal data structure and appending 
		 * the output of each call together.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Creates a PlainWord object, adds the input characters to it 
		 * and then calls Template::add() with the PlainWord object.
		 *
		 * Characters are usually intermingled with other InnerTemplate Tags.
		 * For Template::getString() to work, a PlainWord is created
		 * for each intermingled set of characters and added as an object
		 * among the other InnerTemplate objects in the internal data 
		 * structure.
		 * 
		 * Here is a simple example of intermingled characters, 
		 * <template>Hi, <formal>frank</formal> how are you</template>
		 * When this example occurs, a PlainWord object for "Hi,", and
		 * "how are you" will be created.  Once added through this method
		 * and the other objects are added through 
		 * Template::handleInnerTag(), the internal data structure would 
		 * look something like: PlainWord -> Formal -> PlainWord 
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
         * Calls Template::add() to add the tag to an internal 
		 * data structure if it's a InnerTemplate otherwise it 
		 * throws a rebecca::impl::InternalProgrammerErrorException.
		 *
		 * Using Tag::instanceOf() it first checks to ensure that 
		 * the Tag is an instance of InnerTemplate.  Otherwise it
		 * throws rebecca::impl::InternalProgrammerErrorException.  
		 * After it verifies it is an instance of InnerTemplate it calls
		 * Template::add() to add it to the internal data structure.
		 * 
		 * The internal data stucture is usually a linked list or
		 * vector of InnerTemplate.  Each new tag is added to 
		 * the end of the data structure.
		 *
		 * @param tag The tag to add to the internal data structure. 
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * if the tag is not an instance of an InnerTemplate
		 */
		virtual void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~Template();


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
		TemplateImpl *m_pimpl;

};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::Template;

} //end of namespace framework
} //end of namespace rebecca


#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

