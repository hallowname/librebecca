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

//Rebecca includes
#include <rebecca/all.h>
using namespace rebecca;

//Std includes
#include <iostream>
#include <string>
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
class myCallBacks : public CallBacks
{
	public:

		/**
		 * This is called for each AIML 
		 * "Gossip" tag.
		 *
		 * I am just printing out the gossip.
		 * You can do other things like store it 
		 * in a file and then reload the file at 
		 * startup as a type of persistance.
		 */
		void storeGossip(const StringPimpl &gossip,
                         const StringPimpl &userId,
						 const StringPimpl &botId,
						 const StringPimpl &endUserId) 
		{ 
			cout << "[Gossip: " << gossip.c_str() << " ]" << endl;
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
			cout << "[Loading      " << fileName.c_str() << "]" << endl;
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
			cout << "[Done loading " << fileName.c_str() << "]" << endl;
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
			cout << "Symbolic reduction: " << symbol.c_str() << endl;
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
			cout << "[Infinite Symbolic reduction detected]" << endl;
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
			cout << message.c_str() << endl;
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
			cout << message.c_str() << endl;
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
			cout << message.c_str() << endl;
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
			cout << "[Warning thatStar Tag Size Exceeded]" << endl;
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
			cout << "[Warning topicStar Tag Size Exceeded]" << endl;		
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
			cout << "[Warning star Tag Size Exceeded]" << endl;
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
			cout << "inputTagNuermicConversionError:" << message.c_str() << endl;		
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
			cout << "[Warning input Tag Size Exceeded]" << endl;
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
			cout << "starTagNuermicConversionError:" << message.c_str() << endl;				
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
			cout << "thatTagNumericConversionError:" << message.c_str() << endl;
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
		{ }

};

/**
 * Console version to query a AIML set.
 * 
 * I use the annotated alice data set that's 
 * provided as an example.
 */
int main (int argc, char* args[]) 
{
	try
	{ 

		/*
		 * This is responsible for memory management of 
		 * GraphBuilder.
		 */
		AimlFacade aiml;

		/*
		 * Get the GraphBuilder concrete class that 
		 * was created inside of AimlFacade.
		 * DO NOT try to delete GraphBuilder.  Let
		 * AimlFacade handle that when it falls out 
		 * of scope.
		 */
		GraphBuilder &builder = aiml.getGraphBuilder();

		StringPimpl userId = "Frank";
		StringPimpl botId = "my bot";
		StringPimpl endUserId = "End User 1";

		builder.setUserIdBotIdEndUserId(userId, botId, endUserId);

		/*
		 * Create an instantiation of our custom 
		 * callbacks we created above.
		 */
		myCallBacks callback;

		/* Give the address to Rebecca for usesage.
		 * Rebecca DOES NOT delete it.  
		 */
		builder.setCallBacks(&callback);

//		builder.addCustomTagLibrary("customGraphvizTagLayer");

		cout << "[Rebecca loading]" << endl;

		/* 
		 * Set the schemas for the AIML XML (AIML.xsd)
		 * and for Rebecca's own configuration files.
		 * The schema's have to be relative to where the files
		 * you are going to parse are going to be at.
		 */
		builder.setAIMLSchema("../../resources/schema/AIML.xsd");
		builder.setCommonTypesSchema("../../resources/schema/common-types.xsd");
		builder.setBotConfigurationSchema("../../resources/schema/bot-configuration.xsd");

		/* 
		 * Set that "yes" we do want to do XML validation on
		 * both the AIML XML and Rebecca's own configuration 
		 * files.
		 */
		builder.setAIMLValidation();
		builder.setBotConfigurationValidation();

		/*
		 * Parse Rebecca's configuration files to setup 
		 * Rebecca's ability to handle input subsitutions, 
		 * what a sentence splitter is, and what bot properties
		 * she should have.
		 */
		builder.parseSubstitutionFile("../../conf/substitutions.xml");
		builder.parseSentenceSplitterFile("../../conf/sentence-splitters.xml");
		builder.parsePropertiesFile("../../conf/properties.xml");
		
		/*
		 * Add the entire directory.  Every file that has the 
		 * extension ".aiml" will be added to the internal queue 
		 * for latter processing.
		 */
 		builder.addDirectoryUnlessAlreadyAdded("../../aiml/annotated_alice");
// 		builder.addFile("../../aiml/annotated_alice/Default.aiml");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/basic_aiml");
//		builder.addFile("../../aiml/basic_aiml/basics.aiml");
//		builder.addFile("../../aiml/basic_aiml/basics.aiml");
//		builder.addString("<category><pattern>string test</pattern><template>test works</template></category>");
//		builder.addString("<category><pattern>string test2</pattern><template>test works</template></category>");
//		builder.addFile("../../aiml/basic_aiml/basics2.aiml");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/test1");
//		builder.addDirectoryUnlessAlreadyAdded("../../resources/testing");
		builder.createGraph();

//		builder.removeFile("../../aiml/basic_aiml/basics.aiml");
//		builder.removeDirectory("../../aiml/basic_aiml");
//		builder.removeGraph();
//		cout << builder.getAIMLFileListSize(userId, botId, endUserId) << endl;

//		builder.addFile("../../aiml/basic_aiml/basics.aiml");
//		builder.createGraph();

//		builder.removeFile("../../aiml/basic_aiml/basics.aiml");
//		builder.removeFile("../../aiml/basic_aiml/basics2.aiml");
//		builder.removeGraph();


//		builder.removeFile("../../aiml/basic_aiml/basics.aiml");
//		builder.removeGraph();

//		StringPimpl::clearIntern();

//		builder.setUserIdBotId("Don", "");
//		builder.parsePropertiesFile("../../conf/properties.xml");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/basic_aiml");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/annotated_alice");
//		builder.createGraph();

//		builder.setUserIdBotId("Mom", "");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/annotated_alice");
//		builder.createGraph();


//		builder.setUserIdBotId("Frank", "");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/testing");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/basic_aiml");
//		builder.addDirectoryUnlessAlreadyAdded("../../resources/testing");
//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/testRandom");

//		builder.addDirectoryUnlessAlreadyAdded("../../aiml/aaa");
//		builder.addFile("../../resources/testing/AIML.aiml");
		//builder.addDirectoryUnlessAlreadyAdded("../../aiml/custom_tags");

		/*
		 * No other files to add to the internal queue.  
		 * So, let's create the AIML graph, the internal 
		 * data structures.
		 */
		//builder.createGraph();
		//exit(0);

		/*
		 * Get the number of AIML categories loaded in total.
		 */
		int size = builder.getSize();

		//Print out the number of categories loaded.
		cout << endl << endl;
		cout << "[Rebecca now fully loaded]" << endl;
		cout << "[Number of categories loaded: " << size << "]" << endl;
		cout << "[Type /exit to exit]" << endl << endl << endl;

		/*
		 * Get the botName which should be Rebecca since that is 
		 * the name give in the configuration file properties.xml
		 * which we parsed above.
		 */
		string botName = builder.getBotPredicate("name").c_str();

		/*
		 * Send a initial conversation of "connect" to 
		 * annotated alice and get the response.
		 */
		StringPimpl response = builder.getResponse("connect");		

		//Send the initial opening line of the bot
		cout << botName << " says: " << response.c_str() << endl;
		/*
		 * The main loop to get the input 
		 * from the user until the user types '/exit'
		 */
		while(true)
		{
			string input;
			cout << "You say> ";

			//Get input from the user from the keyboard
			getline(cin, input); 
			
			if(input == "/exit")
			{
				/*
				 * The user wants to exit so break
				 * out of the while(true) loop
				 */
				break;
			}
			else if(input == "/set ids")
			{
				cout << "[Currently " << userId.c_str() << "]" << " set new User id to>";
				getline(cin, input);
				userId = input.c_str();
				cout << "[Currently " << botId.c_str() << "]" << " set new Bot id to>";
				getline(cin, input);
				botId = input.c_str();
				cout << "[Currently " << endUserId.c_str() << "]" << " set new End User id to>";
				getline(cin, input);
				endUserId = input.c_str();
				builder.setUserIdBotIdEndUserId(userId, botId, endUserId);
				cout << endl
					<< "Internal information:" << endl 
					<< "=====================" << endl
					<< input << " : " 
					<< builder.getThat().c_str() << " : "
					<< builder.getTopic().c_str() << endl;
				cout << "=====================" << endl << endl;
			}
			else if(input == "/removeFile")
			{
				cout << "[Name file] ";
				getline(cin, input);
				StringPimpl fileToRemove = input.c_str();
				try
				{
					builder.removeFile(fileToRemove);
					builder.removeGraph();
				}
				catch(FileNotFoundException &)
				{
					cout << "File not found" << endl;
				}
			}
			else if(input == "/addFile")
			{
				cout << "[Name file] ";
				getline(cin, input);
				StringPimpl fileToAdd = input.c_str();
				try
				{
					builder.addFile(fileToAdd);
					builder.createGraph();
				}
				catch(FileNotFoundException &)
				{
					cout << "File not found" << endl;
				}
			}
			else if(input == "/removeDirectory")
			{
				cout << "[Name directory] ";
				getline(cin, input);
				StringPimpl dirToRemove = input.c_str();
				try
				{
					builder.removeDirectory(dirToRemove);
					builder.removeGraph();
				}
				catch(DirectoryNotFoundException &)
				{
					cout << "File not found" << endl;
				}
			}
			else if(input == "/addDirectory")
			{
				cout << "[Name directory] ";
				getline(cin, input);
				StringPimpl dirToAdd = input.c_str();
				try
				{
					builder.addDirectoryUnlessAlreadyAdded(dirToAdd);
					builder.createGraph();
				}
				catch(DirectoryNotFoundException &)
				{
					cout << "File not found" << endl;
				}
			}
			else if(input == "/removeString")
			{
				cout << "[Name string] ";
				getline(cin, input);
				StringPimpl stringToRemove = input.c_str();
				builder.removeString(stringToRemove);
				builder.removeGraph();
			}
			else if(input == "/addString")
			{
				cout << "[Name string] ";
				getline(cin, input);
				StringPimpl stringToAdd = input.c_str();
				builder.addString(stringToAdd);
				builder.createGraph();
			}
			else if(input == "/printDB")
			{
				builder.printEntireDatabase();
			}
			else //The user gave an input to the bot
			{
				//Here we get some internal Rebecca information.
				cout << endl
					<< "Internal information:" << endl 
					<< "=====================" << endl
					<< input << " : " 
					<< builder.getThat().c_str() << " : "
					<< builder.getTopic().c_str() << endl;

				/*
				 * Ahhh finally.  We give the user input to Rebecca Aiml's loaded 
				 * AIML and get the response back.
				 */
				StringPimpl response = builder.getResponse(input.c_str());
				
				cout << "=====================" << endl << endl;
				
				//Print out what Rebecca says.
				cout << botName << " says: " << response.c_str() << endl;
			}
		}

		/*
		 * Synchronize everything from memory to the 
		 * database.
		 */
		builder.synchronizeDatabase();
	}
	/* 
	 * All the exceptions are grouped here but you 
	 * might not want this since it's a bit harder 
	 * to determine where they came from.
	 */
	catch(DirectoryNotFoundException &e)
	{
		cout << "[A Directory Was Not Found Terminating]" << endl;
		cout << "[" << e.what() << "]" << endl;
		return 1;
	}
	catch(FileNotFoundException &e)
	{
		cout << "[A File Was Not Found Terminating]" << endl;
		cout << "[" << e.what() << "]" << endl;
		return 1;
	}
	catch(IllegalArgumentException &e)
	{
		cout << "[IllegalArgument Found Terminating]" << endl;
		cout << "[" << e.what() << "]" << endl;
		return 1;
	}
	catch(InitializationException &e)
	{
		cout << "[Initialization Exception Found Terminating]" << endl;
		cout << "[" << e.what() << "]" << endl;
		return 1;
	}
	catch(XMLErrorException &e)
	{
		cout << "[XMLError Exception Found Terminating]" << endl;
		cout << "[" << e.what() << "]" << endl;
		return 1;
	}
	catch(Exception &e)
	{
		cout << "[An uknown exception occured, Terminating program]" << endl;
		cout << "[" << e.what() << "]";
		return 1;
	}

	//Everything smooth.  Exit normally.
	return 0;
}
