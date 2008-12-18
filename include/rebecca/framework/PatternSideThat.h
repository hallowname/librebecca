#ifndef REBECCA_FRAMEWORK_PATTERNSIDETHAT_H
#define REBECCA_FRAMEWORK_PATTERNSIDETHAT_H

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
class PatternSideThatImpl;
class GraphBuilderFramework;	

/**
 * AIML class that represents the 
 * AIML XML tag "that" that is a 
 * "Pattern side That".  
 *
 * Every time a XML Tag of AIML is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 */
class REBECCA_EXPORT PatternSideThat : public InnerCategory
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
		PatternSideThat() 
			throw(InternalProgrammerErrorException &);

		/**
		 * Sets its internal string to the characters inbetween
		 * its begin and end tag.
		 *
		 * For example, in <that>blah</that>, blah will be added
		 * through this method to an internal string.
		 *
		 * @param characters The characters inbetween its begin and
		 * end tag that are added to the internal string.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void addCharacters(const StringPimpl &characters) 
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns a copy of the internal string.
		 *
		 * @return The internal string
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns a reference of the internal string.
		 *
		 * This is for efficiency's sake.  Be careful because this 
		 * object retains ownership of the string and it
		 * has to stay instantiated while the reference is being
		 * passed around.
		 *
		 * @return A reference to the internal string
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual const StringPimpl &getStringConstRef() const
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~PatternSideThat();

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
		PatternSideThatImpl *m_pimpl;
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::PatternSideThat;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

