#ifndef REBECCA_FRAMEWORK_INNERTEMPLATE_H
#define REBECCA_FRAMEWORK_INNERTEMPLATE_H

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
class InnerTemplateImpl;

/**
 * AIML XML abstract class for all the AIML XML Tag classes 
 * inside of the AIML XML "template" to inherit from.
 *
 * This class adds the operations needed by AIML XML 
 * Tag classes that are inside of the <template> AIML XML 
 * tag.
 *
 * If you write a AIML XML tag class such as Li, Srai, 
 * LowerCase, etc... which reside inside of <InnerTemplate>
 * you should either inherit from this class or from another
 * class which already inherits from this class.
 *
 */
class REBECCA_EXPORT InnerTemplate : public InnerCategory
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
		InnerTemplate() 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Calls InnerTemplate::add with the Tag object.
		 *
		 * First using Tag::instanceOf() it checks that the 
		 * AIML XML Tag is an instance of InnerTemplate.  If it is it
		 * calls InnerTemplate::add() with the object, otherwise
		 * it throws a rebecca::impl::InternalProgrammerErrorException
		 * which would shut down the AIML engine altogether.
		 *
		 * @param tag The AIML XML Tag object to add to InnerTemplate.
		 *
		 * @exception InternalProgrammerErrorException If Tag is not an 
		 * instance of InnerTemplate this exception will be thrown 
		 * and shut down the AIML engine.
		 */
		virtual void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &);

		/**
		 * Add an InnerTemplate AIML XML Tag object to the 
		 * underlying data structure.
		 *
		 * This method goes hand-in-hand with InnerTemplate::getString(). 
		 * When a Inner Tag object is "added" it is put into a data structure
		 * for latter retrieval by InnerTemplate::getString().  This method 
		 * is a no-ops (No operations) method and does nothing by its self.
		 * It is up to the inheriting class to determine how to add the Tag 
		 * as well as latter retrieve it by InnerTemplate::getString().
		 *
		 * For example if <think><person>blah</person></think> is encountered, 
		 * the Tag object Person will be sent to the Think object through this 
		 * method after the end element of Person (</person>) is encountered.
		 * It is up to the Think object's implementation of this method to 
		 * "add" or keep track of the person object.  When Think's 
		 * Think::getString() method is called it is up to Think to 
		 * retrieve and call Person's Person::getString() and retrieve
		 * the string of Person before returning Think's string.
		 *
		 * One more example would be:
		 * <formal><person><sentence>blah</sentence></person></formal>  Here 
		 * when </sentence> is encountered the Person object will be sent a 
		 * shared_ptr to the Sentece object through this method.  Next, 
		 * </person> will be encountered and the Formal object will be sent
		 * a shared_ptr to the Person object through this method.  When Formal's 
		 * method Formal::getString() is called, it will in turn call 
		 * Person's Person::getString().  Person in turn will call Sentence's
		 * Sentence::getString().  Sentence returns to Person "blah" as "Blah" 
		 * according to what the AIML XML Sentence Tag is suppose to do.  The Person 
		 * object gets Setence's string, transforms it according to what the AIML XML
		 * Person Tag is suppose to do and returns it to Formal.  Formal's call to 
		 * Person::getString() finally returns and it transforms it according to what
		 * the AIML XML Formal Tag is suppose to transform it to and returns it.
		 *
		 * @param tag The InnerTemplate AIML XML Tag that is inside this AIML XML 
		 * Tag and is to be added to this AIMl XML's underlying data structure for 
		 * latter retrievel through InnerTemplate::getString()
		 * 
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void add(InnerTemplate *tag) 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Return the results of what the AIML XML InnerTemplate Tag is 
		 * suppose to return according to the AIML specification.
		 *
		 * This method goes hand-in-hand with InnerTemplate::add().  When 
		 * this method is called the string representation of the AIML XML
		 * InnerTemplate Tag is returned.  Any string transformations that are to be applied 
		 * to the AIML XML InnerTemplate Tag are applied during this call.  
		 * This method is a no-ops (No operations) method and does nothing 
		 * by its self.		 
		 *
		 * A simple example would be when the InnerTemplate 
		 * <formal>blah</formal> is encountered a Formal Object is created.
		 * When Formal's method Formal::getString() is called, Formal returns 
		 * the string blah tansformed into "Blah".
		 *
		 * For more complex examples see InnerTemplate::add().
		 * 
		 * @return The results of the AIM XML Tag's transformation on any 
		 * text and any AIML XML InnerTemplate Tags that are inside this 
		 * AIML XML Tag. 
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual StringPimpl getString() const 
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~InnerTemplate();

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
		InnerTemplateImpl *m_pimpl;
};


} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::InnerTemplate;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

