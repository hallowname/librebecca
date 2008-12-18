#ifndef REBECCA_FRAMEWORK_FRAMEWORKFACTORY_H
#define REBECCA_FRAMEWORK_FRAMEWORKFACTORY_H

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

namespace rebecca
{
namespace framework
{
namespace impl
{

//Forward declerations
class GraphBuilderFramework;
class FrameworkFactoryImpl;

/**
 * This is used to get particular 
 * instances of classes in which 
 * it is not possible to get to their
 * concrete representations any other 
 * way.
 */
class FrameworkFactory
{
	public:	

		/**
		 * Returns an instance of the GraphBuilderFramework
		 *
		 * @return An instance of the GraphBuilderFramework
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual GraphBuilderFramework *getGraphBuilderFramework()
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the instance of this class.  Only 
		 * one instance of this class is allowed at a 
		 * time since this is a singelton.
		 *
		 * @return The single instance of 
		 * FrameworkFactory
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		static FrameworkFactory *getInstance()
			throw(InternalProgrammerErrorException &);

		/**
		 * Resets the FrameworkFactory so that it will delete
		 * its current underlying instance and then recreate it.  You
		 * should rarely if EVER have to call this.  This is usually 
		 * used by internal factory methods.
		 */
		FrameworkFactory *reset()
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~FrameworkFactory();

	private:

        /** 
		 * Default constructor to initalize 
		 * the private implementation (m_pimpl)
		 * data.  This is private because this is 
		 * a singelton.  Use 
		 * FrameworkFactory::getInstance() to
		 * get an instance of this class.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		FrameworkFactory()
			throw(InternalProgrammerErrorException &);

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
		FrameworkFactoryImpl *m_pimpl;
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::FrameworkFactory;

} //end of namespace framework
} //end of namespace rebecca


#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif
