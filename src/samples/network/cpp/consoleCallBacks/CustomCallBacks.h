#ifndef CONSOLECALLBACKSNETWORKCUSTOMCALLBACKS_H
#define CONSOLECALLBACKSNETWORKCUSTOMCALLBACKS_H

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

//rebecca includes
#include <rebecca/CallBacks.h>
using namespace rebecca;

//std includes
#include <iostream>
using namespace std;

/**
 * My Custom CallBacks class.
 * 
 * This class inherits from Rebecca's 
 * CallBacks class and implements the 
 * callbacks for error reporting and 
 * informational reporting purposes.
 *
 * Although, I pain stakenly reimplemnt 
 * every single method, you don't have to.
 * Just pick and choose which ones you 
 * want to implement, and ignore the rest.  
 * All of the methods of CallBacks has a 
 * default do nothing implementation.
 */
class CustomCallBacks : public CallBacks
{
	private:

		/**
		 * Keep our userId so we can filter
		 * and only show callbacks to our 
		 * user Id
		 */
		StringPimpl m_userId;

		/**
		 * Keep our userId so we can filter
		 * and only show callbacks to our 
		 * botId
		 */
		StringPimpl m_botId;

		/**
		 * Keep our userId so we can filter
		 * and only show callbacks to our 
		 * endUserId
		 */
		StringPimpl m_endUserId;

	public:
		
		/**
		 * Default constructor requiring us to create
		 * the call backs with a userId, botId, and endUserId.
		 *
		 * We will use our own id's to filter all the callbacks 
		 * to just ours that we are concerned with
		 */
		CustomCallBacks(StringPimpl userId, StringPimpl botId, StringPimpl endUserId)
			: m_userId(userId), 
			  m_botId(botId), 
			  m_endUserId(endUserId)
		{ }

		/**
		 * This is called for each AIML 
		 * "Gossip" tag.
		 *
		 * I am just printing out the gossip.
		 * You can do other things like store it 
		 * in a file and then reload the file at 
		 * startup as a type of persistance.
		 *
		 * @param gossip The gossip sent to be 
		 * stored as you see fit
		 */
		void storeGossip(const StringPimpl &gossip, 
                         const StringPimpl &userId,
						 const StringPimpl &botId,
						 const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Gossip: " << gossip.c_str() << " ]" << endl;
			}
		}

		/**
		 * This is called for each AIML 
		 * category that is loaded into 
		 * memory.  
		 *
		 * Loadtime occurs whenver the call 
		 * GraphBuilder::createGraph() is made.
		 * For every 5000 categories loaded into
		 * Rebecca's internal data structure 
		 * this prints a output message about it.
		 */
		void categoryLoaded(const StringPimpl &userId,
						    const StringPimpl &botId,
						    const StringPimpl &endUserId) 
		{
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				static int i = 0;
				const int numberOfCategories = 5000;
				
				/*
				 * Clever way to say if "i" is a multiple 
				 * of 5000 then print out the number of 
				 * categories loaded so far.
				 */
				if(++i % numberOfCategories == 0)
				{
					cout << "[" << i << " categories loaded]" << endl;
				}
			}
		}

		/**
		 * Before each AIML file is parsed this method is called.
         *
		 * @param fileName The name of the file about to be parsed.
		 */
		void filePreLoad(const StringPimpl &fileName, 
                         const StringPimpl &userId,
						 const StringPimpl &botId,
						 const StringPimpl &endUserId) 
		{
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Loading      " << fileName.c_str() << "]" << endl;
			}
		}
		
		/**
		 * After each AIML file is parsed, this method is called.
         *
		 * @param fileName The name of the file just parsed.
		 */
		void filePostLoad(const StringPimpl &fileName,
                          const StringPimpl &userId,
						  const StringPimpl &botId,
						  const StringPimpl &endUserId) 
		{
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Done loading " << fileName.c_str() << "]" << endl;
			}
		}

		/**
		 * When the "srai" AIML tag is called, the text 
		 * is sent to this method.
		 *
		 * Usually refered to as symbolic reduction, you 
		 * can see what text is being re-fed back into the 
		 * AIML GraphBuilder::getResponse() by AIML its self.
		 *
		 * @param symbol The text which is being sent back
		 * into GraphBuilder::getResponse().
		 */
		void symbolicReduction(const StringPimpl &symbol,
                               const StringPimpl &userId,
						       const StringPimpl &botId,
						       const StringPimpl &endUserId) 
		{
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "Symbolic reduction: " << symbol.c_str() << endl;
			}
		}

		/**
		 * A infinite symbolic reduction has occured and 
		 * has been terminated.
		 *
		 * This method is called when symbolic reduction ends
		 * up in a infinite loop and has been terminated.  This
		 * is just to alert you to the fact.
		 */
		void infiniteSymbolicReduction(const StringPimpl &userId,
						               const StringPimpl &botId,
						               const StringPimpl &endUserId) 
		{
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Infinite Symbolic reduction detected]" << endl;
			}
		}
		
		/**
		 * Sends you a message about a XMLParseError. 
		 *
		 * Either with AIML files or RebeccaAIML configuration
		 * files.
		 *
		 * @param message The human readable message.
		 */ 
		virtual void XMLParseError(const StringPimpl &message,
                                   const StringPimpl &userId,
						           const StringPimpl &botId,
						           const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << message.c_str() << endl;
			}
		} 

		/**
		 * Sends you a message about a XMLParseWarning. 
		 *
		 * Either with AIML files or RebeccaAIML configuration
		 * files.
		 *
		 * @param message The human readable message.
		 */ 
		virtual void XMLParseWarning(const StringPimpl &message,
                                     const StringPimpl &userId,
						             const StringPimpl &botId,
						             const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << message.c_str() << endl;
			}
		} 

		/**
		 * Sends you a message about a XMLParseFatalError. 
		 *
		 * Either with AIML files or RebeccaAIML configuration
		 * files.
		 *
		 * @param message The human readable message.
		 */ 
		virtual void XMLParseFatalError(const StringPimpl &message,
                                        const StringPimpl &userId,
						                const StringPimpl &botId,
						                const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << message.c_str() << endl;
			}
		} 
		
		/**
		 * During runtime, the "thatStar" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 */
		virtual void thatStarTagSizeExceeded(const StringPimpl &userId,
						                     const StringPimpl &botId,
						                     const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Warning thatStar Tag Size Exceeded]" << endl;
			}
		}
		
		/**
		 * During runtime, the "topicStar" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 */
		virtual void topicStarTagSizeExceeded(const StringPimpl &userId,
						                      const StringPimpl &botId,
						                      const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Warning topicStar Tag Size Exceeded]" << endl;		
			}
		}

		/**
		 * During runtime, the "star" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 */
		virtual void starTagSizeExceeded(const StringPimpl &userId,
						                 const StringPimpl &botId,
						                 const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Warning star Tag Size Exceeded]" << endl;
			}
		}

		/**
		 * A AIML "Input" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 */
		virtual void inputTagNumericConversionError(const StringPimpl &message,
                                                    const StringPimpl &userId,
						                            const StringPimpl &botId,
						                            const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "inputTagNuermicConversionError:" << message.c_str() << endl;		
			}
		}

		/**
		 * During runtime, the "input" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 */
		virtual void inputTagSizeExceeded(const StringPimpl &userId,
						                  const StringPimpl &botId,
						                  const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Warning input Tag Size Exceeded]" << endl;
			}
		} 

		/**
		 * A AIML "Star" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 */
		virtual void starTagNumericConversionError(const StringPimpl &message,
                                                   const StringPimpl &userId,
						                           const StringPimpl &botId,
						                           const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "starTagNuermicConversionError:" << message.c_str() << endl;				
			}
		} 

		/**
		 * During runtime, the "that" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 */
		virtual void thatTagSizeExceeded(const StringPimpl &userId,
						                 const StringPimpl &botId,
						                 const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "[Warning ThatTag Size Exceeded]" << endl;
			}
		}

		/**
		 * A AIML "That" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 */
		virtual void thatTagNumericConversionError(const StringPimpl &message,
                                                   const StringPimpl &userId,
						                           const StringPimpl &botId,
						                           const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "thatTagNumericConversionError:" << message.c_str() << endl;
			}
		} 

		/**
		 * A AIML "TopicStar" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 */
		virtual void topicStarTagNumericConversionError(const StringPimpl &message,
                                                        const StringPimpl &userId,
						                                const StringPimpl &botId,
						                                const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "topicStarTagNumericConversionError:" << message.c_str() << endl;
			}
		} 
		
		/**
		 * A AIML "thatStar" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 */
		virtual void thatStarTagNumericConversionError(const StringPimpl &message,
                                                       const StringPimpl &userId,
						                               const StringPimpl &botId,
						                               const StringPimpl &endUserId) 
		{ 
			//Only display messages associated with our userId, botId, and endUserId
			if(m_userId == userId && m_botId == botId && endUserId == m_endUserId)
			{
				cout << "thatStarTagNumericConversionError" << message.c_str() << endl;
			}

		}
};

#endif