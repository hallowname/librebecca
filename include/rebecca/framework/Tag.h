#ifndef REBECCA_FRAMEWORK_TAG_H
#define REBECCA_FRAMEWORK_TAG_H

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
#include <rebecca/StringPimpl.h>
#include <rebecca/exports.h>
#include <rebecca/Exceptions.h>
#include <rebecca/framework/GraphBuilderFramework.h>

//To get the size_t for the deletions
#include <cstddef>

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
class TagImpl;

/**
 * The abstract AIML XML Tag class that all other AIML 
 * XML tags should inherit from.
 *
 * This class contains the methods in which every AIML XML 
 * could have.  It also cotains utility methods in which every
 * XML AIML tag could use.
 */
class REBECCA_EXPORT Tag
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
		Tag() 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Characters inbetween AIML XML begin tags and end
		 * tags are added through this method.
		 * 
		 * Whenver a xml tag has characters inbetween them
		 * such as <srai>blah</srai> the words such as blah 
		 * will be sent to this method.  There's no guarantee
		 * that all the characters inbetween the tags will be 
		 * sent all at once.  It could be the case that one word 
		 * at a time will be sent, or two at a time, or all at a 
		 * time.  But they will be sent in correct order from left 
		 * to right.
		 *
		 * Not all AIML XML tags have character data inbetwen the 
		 * begin and end tags.  Those classes will not implement this 
		 * method.  When not implemented this method is a no-operations
		 * method.  It does nothing when not implemented. 
		 *
		 * @param characters One or more characters that are inbetween 
		 * the AIML XML tag.
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void addCharacters(const StringPimpl &characters) 
			throw(InternalProgrammerErrorException &);

		/**
		 * Whenever a AIML XML end tag is reached, it will be sent as 
		 * an argument to its parent or outermost AIML XML tag.
		 *
		 * As an example look at this InnerTemplate, 
		 * <think><srai>blah</srai></think>. When the Srai end tag is 
		 * reached, </srai>, the entire Srai tag object will be sent 
		 * as an argument to handlerInnerTag on the Think object.
		 *
		 * This gives the outermost tag/parent tag an opportunity to handle each 
		 * inner tag/child tag.  Not all AIML XML tags need to handle inner AIML 
		 * XML tags.  When not implemented this method is a no-operations
		 * method.  It does nothing when not implemented. 
		 * 
		 * @param tag The AIML XML tag that is nested inside of this AIML
		 * XML tag.
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &); 

		/** 
		 * Attributes of the AIML XML tags will be sent through this method.
		 *
		 * As an example, <get name="blah"/> will set name to "name" and value to
		 * "blah".  Not all AIML XML tags have attributes.
		 * When not implemented this method is a no-operations
		 * method.  It does nothing when not implemented. 
		 *
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Determines if the AIML XML tag object inherits from 
		 * another AIML XML tag class somewhere in the hierarchy.
		 *
		 * Use this in conjuction with static_cast<> to downcast 
		 * AIML XML tags safetly as well as to determine if the AIML XML 
		 * tag is an instance of another AIML XML tag.  This only 
		 * works if the object registered its self with Tag::addInstanceOf.
		 * All AIML XML tags in the framework should use Tag::addInstanceOf 
		 * to guarantee this.
		 * 
		 * Sometimes you get an AIML XML tag object in an argument in a method 
		 * such as Tag::handleInnerTag in which you need to downcast it.  Instead 
		 * of blindly downcasting to what the AIML XML tag you think you should have 
		 * recieved you can use this method first to determine if it is indeed 
		 * an instance of that AIML XML tag.  If it is, then you can safetly downcast 
		 * it using static_cast<>.  
		 * 
		 * I use this method in conjunction with static_cast as a replacement
		 * for dynamic_cast<>.  dynamic_cast<> is not guaranteed to work across 
		 * dll boundaries and thus it cannot be used with custom framework dll's.
		 * You SHOULD NEVER USE dynamic_cast<> with RebeccaAIML since it is a dll.
		 * You should always use this method in conjunction with static_cast<> for 
		 * all your downcasting needs.
		 *
		 * @param instance Name of the AIML XML tag class that this 
		 * AIML XML tag object might have inherited from.
		 *
		 * @return Returns true if this object is an instance of the 
		 * AIML XML tag and false if it is not.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		bool instanceOf(const char * const instance) const
			throw(InternalProgrammerErrorException &);

		/**
		 * All delete's will be handled through
		 * this dll.
		 *
		 * This is required for dll boundary safety.
		 * Instead of allowing the compiler to 
		 * choose if it wants to inline this 
		 * we have made it so that it cannot.
		 * If we let the compiler choose to 
		 * inline or not inline this and the 
		 * "new operator" we can run into dll
		 * boundary issues.  The issue would be
		 * that the compiler would inline one 
		 * and not the other.  Thus, your 
		 * executable with its own heap would 
		 * allocate/delete and this dll would 
		 * do the other.  That's a dll boundary
		 * safety violation.
		 * 
         * @param p The pointer to an instance
		 * of this object.
		 */
        void operator delete(void* p);


		/**
		 * All new's will be handled through
		 * this dll.
		 *
		 * This is required for dll boundary safety.
		 * Instead of allowing the compiler to 
		 * choose if it wants to inline this 
		 * we have made it so that it cannot.
		 * If we let the compiler choose to 
		 * inline or not inline this and the 
		 * "delete operator" we can run into dll
		 * boundary issues.  The issue would be
		 * that the compiler would inline one 
		 * and not the other.  Thus, your 
		 * executable with its own heap would 
		 * allocate/delete and this dll would 
		 * do the other.  That's a dll boundary
		 * safety violation.
		 * 
         * @param size The size to allocate 
		 * an instance of this object with.
		 *
		 * @return An instance of this object
		 */
		void *operator new(size_t size);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~Tag();

	protected:

		/**
		 * Whenever a AIML XML tag inherits from any AIML XML tag
		 * it should absolutely use this method in its constructor to add 
		 * its class name.
		 *
		 * For example since Srai inherits from another AIML XML tag it inherits 
		 * this method.  It calls this method in its constructor to add 
		 * its name as in addInstanceOf("Srai").
		 *
		 * The method Tag::instanceOf will not operate correctly if you do not call 
		 * this method within your constructors of AIML Tags.  
		 *
		 * @param instance The name of your class
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		void addInstanceOf(const char * const instance) 
			throw(InternalProgrammerErrorException &);

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
		TagImpl *m_pimpl;

		/**
		 * The assignment operator.
		 *
		 * For now, I am not allowing a copy to be made.  The
		 * tags shouldn't be copied amongst themselves.
		 *
		 * @param tag The standard second reference.
		 */
		Tag &operator=(const Tag &tag);

		/**
		 * The copy constructor.
		 *
		 * For now, I am not allowing this to be invoked. 
		 * The tags shouldn't be allowed to be copied 
		 * amongst themselves.
		 *
		 * @param tag The standard second reference
		 */
		Tag(const Tag& tag);
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::Tag;

/* 
 * Expose the rebecca namespace to the framework namespace.
 * Since all the tags include this file, they will all
 * get the rebecca namespace also.
 */
using namespace rebecca;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif
