#ifndef REBECCA_CALLBACKS_H
#define REBECCA_CALLBACKS_H

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

//To get the REBECA_EXPORT macro
#include <rebecca/exports.h>

//See AimlFacade for the explanation of this namespace
namespace rebecca
{
//See AimlFacade for the explanation of this namespace
namespace impl
{

//Forward decleration of StringPimpl
class StringPimpl;

/** 
 * Inherit from this class and override some or all of the 
 * methods for informative and error handling callbacks.
 *
 * You can pick and choose which callbacks you want to do
 * something about by only overriding the callback methods 
 * that you feel like doing something about.  The remaining
 * methods you do not override will then just remain the 
 * default no-ops (no operations) and do nothing.
 * 
 * After you create your custom subclass of CallBacks, 
 * you instantiate it and call GraphBuilder's method setCallBacks 
 * GraphBuilder::setCallBacks() 
 * giving it the address of your custom subclass of CallBacks. 
 * GraphBuilder will NOT try to delete your subclass.  You are 
 * responsible for the memory management of your CallBacks 
 * subclass.
 *
 * If you do not override this class and call GraphBuilder's 
 * setCallBacks with the address of your instance, then the
 * default one inside GraphBuilder will be used.  The default 
 * CallBacks is an instantiation of this no-ops (No operations) 
 * class.  Therefore nothing will happen when each method is 
 * called and is thus the default behavior.
 */
class REBECCA_EXPORT CallBacks
{
	public:

		/*
		 * Informative callbacks
         *
		 */

		/**
		 * Stores gossip from the aiml gossip tag.
		 * 
		 * Whenever the gossip tag is encountered during 
		 * the runtime of rebecca aiml, this callback 
		 * is called.  This gives the opportunity
		 * to store gossip into a flat file, or something
		 * else deemed appropriate.
		 *
		 * The possibility of this callback being called 
		 * is only during a call to GraphBuilder::getResponse().
		 *
		 * @param gossip The final constructed text between 
		 * a gossip AIML tag.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 * 
		 * @exception Any can be thrown.
		 * 
		 */
		virtual void storeGossip(const StringPimpl &gossip,
			                     const StringPimpl &userId,
								 const StringPimpl &botId,
								 const StringPimpl &endUserId) 
		{ }
		
		/**
		 * During the load time of AIML data this is called 
		 * after each AIML category is loaded.
		 *
		 * This enables an action to be performed after each
		 * category is loaded such as counting the categories 
		 * and periodically outputting that "x" number of categories
		 * has been loaded so far.
		 *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph().
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void categoryLoaded(const StringPimpl &userId,
								    const StringPimpl &botId,
								    const StringPimpl &endUserId) 

		{ }

		/**
		 * During the load time of AIML data this is called 
		 * before a file is parsed for AIML tags.
		 *
		 * This enables an action to be performed before each 
		 * file is loaded such as outputting that "file x" is 
		 * loading or to count the amount of time a file takes 
		 * to load using CallBacks::filePostLoad in conjunction.
		 *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph().
		 *
		 * @param fileName The name of the file that is about
		 * to be parsed for AIML tags.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void filePreLoad(const StringPimpl &fileName,
                                 const StringPimpl &userId,
								 const StringPimpl &botId,
								 const StringPimpl &endUserId) 
        { }

		/**
		 * During the load time of AIML data this is called 
		 * after a file is parsed for AIML tags.
		 *
		 * This enables an action to be performed after each 
		 * file is loaded such as outputting that "file x" was 
		 * loaded or to count the amount of time a file takes 
		 * to load using CallBacks::filePreLoad in conjunction.
		 *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph().
		 *
		 * @param fileName The name of the file that was just
		 * parsed for AIML tags.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 * 
		 * @exception Any can be thrown.
		 */
		virtual void filePostLoad(const StringPimpl &fileName,
			                      const StringPimpl &userId,
								  const StringPimpl &botId,
								  const StringPimpl &endUserId) 
		{ }

		/**
		 * After text in between srai tags is constructed, the 
		 * text is sent to this callback.
		 * 
		 * Usually srai is used for symbolicReduction, hence the 
		 * name of this callback method.  This method is called 
		 * before the GraphBuilder::getResponse() is called with the 
		 * constructed srai text.  This method is mostly useful for
		 * informative purposes of seeing what the AIML is recalling 
		 * its self with during calls to GraphBuilder::getResponse().
		 *
		 * This callback will only be called during a call to 
		 * GraphBuilder::getResponse().
		 * 
		 * @param symbol The final constructed text that was 
		 * constructed from between a srai AIML tag 
		 * encountered.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void symbolicReduction(const StringPimpl &symbol,
			                           const StringPimpl &userId,
								       const StringPimpl &botId,
								       const StringPimpl &endUserId) 
		{ }
		
		/** 
		 * When srai AIML tags cause an infinite recursion, the infinite
		 * recursion is automatically terminated and this method is called.
		 *
		 * This method can be used to send an informative message that 
		 * the AIML tags have infinite recursion with the srai tags or 
		 * to just detect the issue. You DO NOT have to worry about trying 
		 * to terminate the recursion yourself.  The recursion is 
		 * automatically terminated.
		 * 
		 * This callback will only be called during a call to 
		 * GraphBuilder::getResponse().
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
         *
		 * @exception Any can be thrown.
		 */
		virtual void infiniteSymbolicReduction(const StringPimpl &userId,
								               const StringPimpl &botId,
								               const StringPimpl &endUserId) 
 		{ } 

		/*
		 * XML Parse Errors
		 *
		 */

		/**
		 * When a XML Parse Error is encountered during the 
		 * parsing of the AIML tags this method will be called.
		 *
		 * @param message The XML Error Message
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph().
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
         *
		 * @exception Any can be thrown.
		 */
		virtual void XMLParseError(const StringPimpl &message,
			                       const StringPimpl &userId,
								   const StringPimpl &botId,
								   const StringPimpl &endUserId) 
		{ } 

		/**
		 * When a XML Parse Warning is encountered during the 
		 * parsing of the AIML tags this method will be called.
		 *
		 * @param message The XML Warning Message
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph().
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void XMLParseWarning(const StringPimpl &message,
			                         const StringPimpl &userId,
								     const StringPimpl &botId,
								     const StringPimpl &endUserId) 
		{ } 

		/**
		 * When a XML Parse Fatal Error is encountered during the 
		 * parsing of the AIML tags this method will be called.
		 *
		 * @param message The XML Fatal Error Message
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph().
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
         *
		 * @exception Any can be thrown.
		 */
		virtual void XMLParseFatalError(const StringPimpl &message,
			                            const StringPimpl &userId,
								        const StringPimpl &botId,
								        const StringPimpl &endUserId) 
		{ } 

		/*
		 * AIML tag Errors
		 *
		 */

		/** 
		 * When the AIML tag ThatStar's index exceeds its size,
		 * this method is called.
		 *
		 * This is useful to output when the AIML tag ThatStar
		 * during runtime is exceeding its size for informational
		 * purposes or to aid in debugging AIML tags.
		 * 
		 * This callback will only be called during a call to 
		 * GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void thatStarTagSizeExceeded(const StringPimpl &userId,
								             const StringPimpl &botId,
								             const StringPimpl &endUserId) 
		{ }

		/** 
		 * When the AIML tag TopicStar's index exceeds its size,
		 * this method is called.
		 *
		 * This is useful to output when the AIML tag TopicStar
		 * during runtime is exceeding its size for informational
		 * purposes or to aid in debugging AIML tags.
		 * 
		 * This callback will only be called during a call to 
		 * GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void topicStarTagSizeExceeded(const StringPimpl &userId,
								              const StringPimpl &botId,
								              const StringPimpl &endUserId) 
		{ }

		/** 
		 * When the AIML tag Star's index exceeds its size,
		 * this method is called.
		 *
		 * This is useful to output when the AIML tag Star
		 * during runtime is exceeding its size for informational
		 * purposes or to aid in debugging AIML tags.
		 * 
		 * This callback will only be called during a call to 
		 * GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void starTagSizeExceeded(const StringPimpl &userId,
								         const StringPimpl &botId,
								         const StringPimpl &endUserId) 
 		{ }

		/**
		 * When the AIML tag Input has a value inside of its
		 * index attribute which is not a numeric value, this 
		 * method is called.
		 *
		 * This is useful to output when the AIML tag Input
		 * during load time has invalid numeric values for its 
		 * index.
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph()
		 *
		 * @param message A informative message of the error
		 * for humans
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 * 
		 * @exception Any can be thrown.
		 */
		virtual void inputTagNumericConversionError(const StringPimpl &message,
			                                        const StringPimpl &userId,
								                    const StringPimpl &botId,
								                    const StringPimpl &endUserId) 
		{ }

		/** 
		 * When the AIML tag Input's index exceeds its size,
		 * this method is called.
		 *
		 * This is useful to output when the AIML tag Input
		 * during runtime is exceeding its size for informational
		 * purposes or to aid in debugging AIML tags.
		 * 
		 * This callback will only be called during a call to 
		 * GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void inputTagSizeExceeded(const StringPimpl &userId,
								          const StringPimpl &botId,
								          const StringPimpl &endUserId) 
		{ } 

		/**
		 * When the AIML tag Star has a value inside of its
		 * index attribute which is not a numeric value, this 
		 * method is called.
		 *
		 * This is useful to output when the AIML tag Star
		 * during load time has invalid numeric values for its 
		 * index.
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph()
		 * 
		 * @param message A informative message of the error
		 * for humans
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void starTagNumericConversionError(const StringPimpl &message,
						                           const StringPimpl &userId,
								                   const StringPimpl &botId,
								                   const StringPimpl &endUserId) 
		{ } 

		/** 
		 * When the AIML tag That's index exceeds its size,
		 * this method is called.
		 *
		 * This is useful to output when the AIML tag That
		 * during runtime is exceeding its size for informational
		 * purposes or to aid in debugging AIML tags.
		 * 
		 * This callback will only be called during a call to 
		 * GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void thatTagSizeExceeded(const StringPimpl &userId,
								         const StringPimpl &botId,
								         const StringPimpl &endUserId) 
 		{ }

		/**
		 * When the AIML tag That has a value inside of its
		 * index attribute which is not a numeric value, this 
		 * method is called.
		 *
		 * This is useful to output when the AIML tag That
		 * during load time has invalid numeric values for its 
		 * index.
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph()
		 * 
		 * @param message A informative message of the error
		 * for humans
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void thatTagNumericConversionError(const StringPimpl &message,
						                           const StringPimpl &userId,
								                   const StringPimpl &botId,
								                   const StringPimpl &endUserId) 
		{ } 

		/**
		 * When the AIML tag Topic has a value inside of its
		 * index attribute which is not a numeric value, this 
		 * method is called.
		 *
		 * This is useful to output when the AIML tag Topic
		 * during load time has invalid numeric values for its 
		 * index.
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph()
		 * 
		 * @param message A informative message of the error
		 * for humans
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void topicStarTagNumericConversionError(const StringPimpl &message,
						                                const StringPimpl &userId,
								                        const StringPimpl &botId,
								                        const StringPimpl &endUserId) 
		{ } 

		/**
		 * When the AIML tag ThatStar has a value inside of its
		 * index attribute which is not a numeric value, this 
		 * method is called.
		 *
		 * This is useful to output when the AIML tag ThatStar
		 * during load time has invalid numeric values for its 
		 * index.
         *
		 * This callback will only be called during a call to
		 * GraphBuilder::createGraph()
		 * 
		 * @param message A informative message of the error
		 * for humans
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void thatStarTagNumericConversionError(const StringPimpl &message,
						                               const StringPimpl &userId,
								                       const StringPimpl &botId,
								                       const StringPimpl &endUserId) 
		{ }
		
		/**
		 * When the AIML tag Learn points to a file that cannot
		 * be found this method is called.
		 *
		 * This is useful to output when the AIML tag Learn
		 * cannot find the file it was searching for to load.
		 *
		 * @param message A informative message of the error 
		 * for humans
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 *
		 * @exception Any can be thrown.
		 */
		virtual void learnTagFileNotFound(const StringPimpl &message,
						                  const StringPimpl &userId,
								          const StringPimpl &botId,
								          const StringPimpl &endUserId) 
		{ } 

		/** 
		 * No operations Destructor.
		 *
		 * Put what you need in here when you subclass CallBacks.
		 */
		virtual ~CallBacks() { }
};


} //end namespace impl

//expose CallBacks to Rebecca namespace 
using rebecca::impl::CallBacks;

} //end namespace rebecca

#endif

