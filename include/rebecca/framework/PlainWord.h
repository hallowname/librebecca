#ifndef REBECCA_FRAMEWORK_PLAINWORD_H
#define REBECCA_FRAMEWORK_PLAINWORD_H

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
class PlainWordImpl;

/**
 * Used by other inner template Tags to be able to
 * add plain text as a InnerTemplate Tag.
 *
 * This is important to be able to add plain text
 * as an inner template and be treated as such.
 *
 * For example, when 
 * <template>Hi <person>frank</person> how are you</template>
 * is encountered it is important to be able to store the
 * plain text, "Hi", "how are you" as PlainWords.
 * This enables the plain text to be added to the internal
 * data structures as InnerTemplate Tags.  Latter when the
 * the internal data structure of InnerTemplate Tags is 
 * traversed and InnerTemplate::getString() is called on 
 * the PlainWord it will return the plain text with no 
 * transformations.
 *
 * When an unimplemented tag is encountered a 
 * PlainWord object can be used to perserve the text 
 * inbetween the tag too.  For example, <html:br>blah</html:br>,
 * <html:br> is not implemented.  However, if we still want
 * the text of "blah" to be treated as plain text we can return 
 * a PlainWord object instead of a NonImplemented Tag which would
 * not return any text what so ever.
 */
class REBECCA_EXPORT PlainWord : public InnerTemplate
{
	public:

		/** 
		 * Initalizes the private 
		 * implementation (m_pimpl) data 
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		PlainWord() 
			throw(InternalProgrammerErrorException &);

		/** 
		 * Initalizes the private 
		 * implementation (m_pimpl) data and sets 
		 * the internal string with value given 
		 * in the constructor.  
         *
		 * @param word The string to initialize the 
		 * PlainWord with.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		PlainWord(const StringPimpl &word)
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the internal string with no 
		 * transformations.
		 *
		 * @return The internal plain string with
		 * no transformations.
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
		virtual ~PlainWord();

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
		PlainWordImpl *m_pimpl;

};


} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::PlainWord;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

