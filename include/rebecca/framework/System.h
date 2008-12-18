#ifndef REBECCA_FRAMEWORK_SYSTEM_H
#define REBECCA_FRAMEWORK_SYSTEM_H

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
#include <rebecca/framework/InnerTemplateListImpl.h>

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
class SystemImpl;

/**
 * AIML class that represents the 
 * AIML XML tag "system".  
 *
 * Every time a XML Tag of AIML is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 */
class REBECCA_EXPORT System : public InnerTemplateListImpl
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
		System() 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Executes the command given inbetween its
		 * begin and end tag on the current operating system 
		 * by calling InnerTemplateListImpl::getString()
		 *
		 * On Linux and Unix systems the shell executing the 
		 * command will be the default /bin/sh shell. Also on
		 * Linux and Unix systems if you have multiple system 
		 * commands that you want to execute you must seperate 
		 * them all by semicolons and NOT by new lines in your 
		 * AIML code.
		 * 
		 * @return Returns the output from the operating system
		 * after executing the command it gets from 
		 * InnerTemplateListImpl::getString()
		 * 
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~System();

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
		SystemImpl *m_pimpl;
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::System;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif


