#ifndef REBECCA_FRAMEWORK_IDENTIFICATION_H
#define REBECCA_FRAMEWORK_IDENTIFICATION_H

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

namespace rebecca
{
namespace framework
{
namespace impl
{

//forward declerations
class IdentificationManagerImpl;

/**
 * Class responsible for setting 
 * and getting the userId, botId, 
 * endUserId through out the entire
 * system.
 *
 * At any given time during run time 
 * you should use this to 
 * set or get id's if you need them.
 * If you do not ever set any of the id's
 * they will all default to the string
 * value of "default"
 */
class IdentificationManager
{
	public:

		/**
		 * Returns the user id currently 
		 * in use.
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		StringPimpl getUserId()
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the bot id currently 
		 * in use.
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		StringPimpl getBotId()
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the end user id currently 
		 * in use.
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		StringPimpl getEndUserId()
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Returns the instance of this class.  Only 
		 * one instance of this class is allowed at a 
		 * time since this is a singelton.
		 *
		 * @return The single instance of 
		 * IdentificationManager
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		static IdentificationManager *getInstance()
			throw(InternalProgrammerErrorException &);

		/**
		 * Set the user bot and end user Id's.
		 *
		 * @param userId The userId to set
		 *
		 * @param botId The botId to set
		 *
		 * @param endUserId The endUserId to set
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		void setUserIdBotIdEndUserId(const StringPimpl &userId, 
			                         const StringPimpl &botId,
							         const StringPimpl &endUserId)
			throw(InternalProgrammerErrorException &);

		/**
		 * Resets the identification manager so that it will delete
		 * its current underlying instance and then recreate it.  You
		 * should rarely if EVER have to call this.  This is usually 
		 * used by internal factory methods.
		 */
		static IdentificationManager *reset()
			throw(InternalProgrammerErrorException &);

		/**
		 * Use this if you want to use thread specific 
		 * Id's or not.
		 *
		 * By default this is false.  Use this method to 
		 * turn this on before you spin up any threads if you 
		 * want thread specific id's.  With thread specific id's 
		 * each new thread which enters a method has its own copy of 
		 * the all the id's.  If you turn this on, you will want to 
		 * ensure you call all the methods which have the userId, 
		 * botId, and endUserId.  If you turn this on, you 
		 * DO NOT want to call any method which does not 
		 * take a userId, botId, endUserId.
		 *
		 * This method is mainly used for multi-threading.  It's 
		 * used in the case where if you have multiple threads 
		 * and different threads might have different user id's, bot id's
		 * or end user id's.  You would want to make a call to a 
		 * method with a userId, botId, endUserId from one thread and know
		 * that if the system switches threads to another in the middle 
		 * of processing with a different user id, bot id, or 
		 * end user id, it will not trump ontop of your first thread.
		 *
		 * @param mode set this to true to use thread specific
		 * user id's, bot id's, and end user id's
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		void setThreadSpecific(bool mode)
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~IdentificationManager();

	private:
		
        /** 
		 * Default constructor to initalize 
		 * the private implementation (m_pimpl)
		 * data.  This is private because this is 
		 * a singelton.  Use 
		 * IdentificationManager::getInstance() to
		 * get an instance of this class.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		IdentificationManager()
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
		IdentificationManagerImpl *m_pimpl;
};

} //end namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::IdentificationManager;

} //end namespace framework
} //end namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

