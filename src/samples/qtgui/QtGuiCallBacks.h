#ifndef QTGUI_QTGUICALLBACKS_H
#define QTGUI_QTGUICALLBACKS_H

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
#include <rebecca/StringPimpl.h>
//std includes
#include <iostream>

//Qt includes
#include <QTextEdit>
#include <QScrollBar>
#include <QObject>

namespace qtgui
{

using namespace rebecca;
using namespace std;

/**
 * My Custom CallBacks class.
 * 
 * This class inherits from Rebecca's 
 * CallBacks class and implements the 
 * callbacks for error reporting and 
 * informational reporting purposes.
 *
 *
 * I override the callbacks and put
 * the callbacks into the Qt 
 * MainWindow to display
 */
class QtGuiCallBacks : public QObject, public CallBacks
{
	Q_OBJECT

	public:
		
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
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		void storeGossip(const StringPimpl &gossip,
                         const StringPimpl &userId,
						 const StringPimpl &botId,
						 const StringPimpl &endUserId) 
		{ 
			QString output;
			output += "[Gossip: ";
			output += gossip.c_str();
			output += " ]";
			emit addText(output);
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
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		void categoryLoaded(const StringPimpl &userId,
						    const StringPimpl &botId,
						    const StringPimpl &endUserId)
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
				QString num;
				num.setNum(i);
				QString output;
				output += "[";
				output += num;
				output += " categories loaded]";
				emit addText(output);
			}
		}

		/**
		 * Before each AIML file is parsed this method is called.
         *
		 * @param fileName The name of the file about to be parsed.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		void filePreLoad(const StringPimpl &fileName,
                         const StringPimpl &userId,
						 const StringPimpl &botId,
						 const StringPimpl &endUserId)
		{
			QString output;
			output += "[Loading      ";
			output += fileName.c_str();
			output += "]";
			emit addText(output);
		}
		
		/**
		 * After each AIML file is parsed, this method is called.
         *
		 * @param fileName The name of the file just parsed.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		void filePostLoad(const StringPimpl &fileName,
                          const StringPimpl &userId,
						  const StringPimpl &botId,
						  const StringPimpl &endUserId)
		{
			QString output;
			output += "[Done loading ";
			output += fileName.c_str();
			output += "]";
			emit addText(output);
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
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		void symbolicReduction(const StringPimpl &symbol,
                               const StringPimpl &userId,
						       const StringPimpl &botId,
						       const StringPimpl &endUserId)
		{
			QString output;
			output += "Symbolic reduction: ";
			output += symbol.c_str();
			emit addText(output);
		}

		/**
		 * A infinite symbolic reduction has occured and 
		 * has been terminated.
		 *
		 * This method is called when symbolic reduction ends
		 * up in a infinite loop and has been terminated.  This
		 * is just to alert you to the fact.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		void infiniteSymbolicReduction(const StringPimpl &userId,
						               const StringPimpl &botId,
						               const StringPimpl &endUserId)
		{
			emit addText("[Infinite Symbolic reduction detected]");
		}
		
		/**
		 * Sends you a message about a XMLParseError. 
		 *
		 * Either with AIML files or RebeccaAIML configuration
		 * files.
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */ 
		virtual void XMLParseError(const StringPimpl &message,
                                   const StringPimpl &userId,
						           const StringPimpl &botId,
						           const StringPimpl &endUserId)
		{ 
			emit addText(message.c_str());
		} 

		/**
		 * Sends you a message about a XMLParseWarning. 
		 *
		 * Either with AIML files or RebeccaAIML configuration
		 * files.
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */ 
		virtual void XMLParseWarning(const StringPimpl &message,
                                     const StringPimpl &userId,
						             const StringPimpl &botId,
						             const StringPimpl &endUserId)
		{ 
			emit addText(message.c_str());
		} 

		/**
		 * Sends you a message about a XMLParseFatalError. 
		 *
		 * Either with AIML files or RebeccaAIML configuration
		 * files.
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */ 
		virtual void XMLParseFatalError(const StringPimpl &message,
                                        const StringPimpl &userId,
						                const StringPimpl &botId,
						                const StringPimpl &endUserId)
		{ 
			emit addText(message.c_str());
		} 
		
		/**
		 * During runtime, the "thatStar" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void thatStarTagSizeExceeded(const StringPimpl &userId,
						                     const StringPimpl &botId,
						                     const StringPimpl &endUserId) 
		{ 
			emit addText("[Warning thatStar Tag Size Exceeded]");
		}
		
		/**
		 * During runtime, the "topicStar" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void topicStarTagSizeExceeded(const StringPimpl &userId,
						                      const StringPimpl &botId,
						                      const StringPimpl &endUserId) 
		{ 
			emit addText("[Warning topicStar Tag Size Exceeded]");
		}

		/**
		 * During runtime, the "star" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void starTagSizeExceeded(const StringPimpl &userId,
						                 const StringPimpl &botId,
						                 const StringPimpl &endUserId)
		{ 
			emit addText("[Warning star Tag Size Exceeded]");
		}

		/**
		 * A AIML "Input" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void inputTagNumericConversionError(const StringPimpl &message,
                                                    const StringPimpl &userId,
						                            const StringPimpl &botId,
						                            const StringPimpl &endUserId)
		{ 
			QString output("inputTagNuermicConversionError:");
			output += message.c_str();
			emit addText(message.c_str());
		}

		/**
		 * During runtime, the "input" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void inputTagSizeExceeded(const StringPimpl &userId,
						                  const StringPimpl &botId,
						                  const StringPimpl &endUserId) 
		{ 
			emit addText("[Warning input Tag Size Exceeded]");
		} 

		/**
		 * A AIML "Star" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void starTagNumericConversionError(const StringPimpl &message,
                                                   const StringPimpl &userId,
						                           const StringPimpl &botId,
						                           const StringPimpl &endUserId)
		{ 
			QString output("starTagNuermicConversionError:");
			output += message.c_str();
			emit addText(message.c_str());
		} 

		/**
		 * During runtime, the "that" AIML tag's size is 
		 * exceeded.
		 *
		 * Runtime is during a call to GraphBuilder::getResponse()
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void thatTagSizeExceeded(const StringPimpl &userId,
						                 const StringPimpl &botId,
						                 const StringPimpl &endUserId) 
		{ 
			emit addText("thatTag Size exceeded");
		}

		/**
		 * A AIML "That" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void thatTagNumericConversionError(const StringPimpl &message,
                                                   const StringPimpl &userId,
						                           const StringPimpl &botId,
						                           const StringPimpl &endUserId)
		{ 
			QString output("thatTagNumericConversionError:");
			output += message.c_str();
			emit addText(output);
		} 

		/**
		 * A AIML "TopicStar" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void topicStarTagNumericConversionError(const StringPimpl &message,
                                                        const StringPimpl &userId,
						                                const StringPimpl &botId,
						                                const StringPimpl &endUserId)
		{ 
			QString output("topicStarTagNumericConversionError:");
			output += message.c_str();
			emit addText(output);
		}	
		
		/**
		 * A AIML "thatStar" tag has a non number in its index attribute.
		 *
		 * This method will only be called during loadtime, GraphBuilder::createGraph().
		 *
		 * @param message The human readable message.
		 *
		 * @param userId The user that caused this
		 *
		 * @param botId The bot that caused this
		 *
		 * @param endUserId The end user that caused this
		 */
		virtual void thatStarTagNumericConversionError(const StringPimpl &message,
                                                       const StringPimpl &userId,
						                               const StringPimpl &botId,
						                               const StringPimpl &endUserId)
		{ 
			QString output("thatStarTagNumericConversionError:");
			output += message.c_str();
			emit addText(output);
		}

	signals:

		/**
		 * Signal to emit to anyone interested in
		 * the text we have from our callbacks.
		 *
		 * @param text The text to emit
		 */
		void addText(const QString &text);
};

} //end of qtgui namespace

#endif
