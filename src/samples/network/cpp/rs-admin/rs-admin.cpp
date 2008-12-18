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
#include <rebecca/network_all.h>
#include <rebecca/all.h>
using namespace rebecca;

//rs-admin includes
#include <usages.h>
using namespace rsAdmin;


//std includes
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

NetworkAimlFacade *networkAimlfacade = 0;
AimlFacade *aimlFacade = 0;

GraphBuilder &createAIMLConnection(bool networkConnection, int argc, char* argv[])
{
	if(networkConnection)
	{
	   /*
		* This is responsible for memory management of 
		* NetworkGraphBuilder as well as for making
		* the initial connection to the server.
		* If it cannot connect it will throw either a 
		* regular Exception or a NetworkExcetpion.
		*/
		networkAimlfacade = new NetworkAimlFacade(argc, argv); 

		/*
		 * Get the NetworkGraphBuilder concrete 
		 * class that was created inside of 
		 * NetworkAimlFacade.
		 * DO NOT try to delete NetworkGraphBuilder.  
		 * Let NetworkAimlFacade handle that when 
		 * it falls out of scope.
		 */
		return networkAimlfacade->getNetworkGraphBuilder();
	}
	else
	{
		//local connection
		aimlFacade = new AimlFacade; 

		/*
		 * Get the GraphBuilder concrete class that 
		 * was created inside of AimlFacade.
		 * DO NOT try to delete GraphBuilder.  Let
		 * AimlFacade handle that when it falls out 
		 * of scope.
		 */
		GraphBuilder &builder = aimlFacade->getGraphBuilder();

		/* 
		 * Set the schemas for the AIML XML (AIML.xsd)
		 * and for Rebecca's own configuration files.
		 * The schema's have to be relative to where the files
		 * you are going to parse are going to be at.
		 */
		builder.setAIMLSchema("../resources/schema/AIML.xsd");
		builder.setCommonTypesSchema("../resources/schema/common-types.xsd");
		builder.setBotConfigurationSchema("../resources/schema/bot-configuration.xsd");

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
		builder.parseSubstitutionFile("../conf/substitutions.xml");
		builder.parseSentenceSplitterFile("../conf/sentence-splitters.xml");
		return builder;
	}
}

int main(int argc, char* argv[])
{
	try
	{

		//The command given
		StringPimpl command;

		//The arguments to the command
		deque<StringPimpl> arguments;

	   /*
		* Get the arguments if any
		* otherwise print the usage 
		* and exit with an error code
		*/
		if(argc > 1)
		{
		   /*
			* The rest of the arguments are going to be
			* arguments to the the command its self.
			* So populate the arguments vector with 
			* this
			*/
			for(int i = 1; i < argc; ++i)
			{

				/*
				 * Fill the arguments vector with the 
				 * strings from the command line 
				 */
				arguments.push_back(StringPimpl(argv[i]));
			}
		}
		else
		{
			//Print the usage and exit with an error
			printUsage();
			return 1;
		}

		//default strings are "default"
		StringPimpl userId = "default";
		StringPimpl botId = "default";
		StringPimpl endUserId = "default";
	
		bool networkConnection = true;
		deque<StringPimpl> temp;

		//extract set local connection if it exists
		for(unsigned int i = 0; i < arguments.size(); ++i)
		{
			if(arguments.at(i) == "--localConnection" ||
		       arguments.at(i) == "-lc")
			{
				if(arguments.size() < 1)
				{
					printUsage();
					return 1;
				}
				else
				{
					networkConnection = false;
				}
			}
			else
			{
				temp.push_back(arguments.at(i));
			}
		}

		//set arguments to remainder
		arguments = temp;
		temp.clear();

		for(unsigned int i = 0; i < arguments.size(); ++i)
		{
			if(arguments.at(i) == "--setIds" 
			   || arguments.at(i) == "-sids")
			{
				if((i + 4) > arguments.size())
				{
					printSetIdsUsage();
					return 1;
				}
				else
				{
					//get the first 4 arguments as 
					//UserId, botId, and EndUserId
					userId = arguments.at(i + 1);
					botId = arguments.at(i + 2);
					endUserId = arguments.at(i + 3);

					//remove the next 4 arguments
					//by skipping them
					i += 3;
				}
			}
			else
			{
				temp.push_back(arguments.at(i));
			}
		}

		//set arguments to remainder
		arguments = temp;
		temp.clear();

		if(arguments.size() == 0)
		{
			printUsage();
			return 1;
		}

		//create either network or local connection
		GraphBuilder &builder = createAIMLConnection(networkConnection, argc, argv);

		//remove the next argument for the command
		command = arguments.front();
		arguments.pop_front();

		/*
		 * Here is the master command 
		 * checking.  During these if/else if's
		 * the command will be checked against the
		 * list of possibilities.  If one is not found
		 * it will terminate with an error message.  If
		 * one is found but the argument size is wrong an
		 * error message will be printed and it will be 
		 * terminated with an error.
		 */
		//Add a directory
		if(command == "--addDirectory" || command == "-ad")
		{
			if(arguments.size() == 1)
			{
				builder.addDirectory(arguments.at(0), userId, botId, endUserId);
			}
			else if(arguments.size() == 2)
			{
				builder.addDirectory(arguments.at(0), arguments.at(1), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printAddDirectoryUsage();
				return 1;
			}
		}
		else if(command == "--addDirectoryUnlessAlreadyAdded" || command == "-aduaa")
		{
			if(arguments.size() == 1)
			{
				builder.addDirectoryUnlessAlreadyAdded(arguments.at(0), userId, botId, endUserId);
			}
			else if(arguments.size() == 2)
			{
				builder.addDirectoryUnlessAlreadyAdded(arguments.at(0), arguments.at(1), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printAddDirectoryUnlessAlreadyAddedUsage();
				return 1;
			}
		}
		else if(command == "--removeDirectory" || command == "-rd")
		{
			if(arguments.size() == 1)
			{
				builder.removeDirectory(arguments.at(0), userId, botId, endUserId);
			}
			else if(arguments.size() == 2)
			{
				builder.removeDirectory(arguments.at(0), arguments.at(1), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printRemoveDirectoryUsage();
				return 1;
			}
		}
		else if(command == "--removeFile" || command == "-rf")
		{
			if(arguments.size() == 1)
			{
				builder.removeFile(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printRemoveFileUsage();
				return 1;
			}
		}
		//Add a file
		else if(command == "--addFile" || command == "-af")
		{
			if(arguments.size() == 1)
			{
				builder.addFile(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printAddFileUsage();
				return 1;
			}
		}
		else if(command == "--addFileUnlessAlreadyAdded" || command == "-afuaa")
		{
			if(arguments.size() == 1)
			{
				builder.addFileUnlessAlreadyAdded(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printAddFileUnlessAlreadyAddedUsage();
				return 1;
			}
		}
		//Add a string
		else if(command == "--addString" || command == "-as")
		{
			if(arguments.size() == 1)
			{
				builder.addString(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printAddStringUsage();
				return 1;
			}
		}
		else if(command == "--removeString" || command == "-rs")
		{
			if(arguments.size() == 1)
			{
				builder.removeString(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printRemoveStringUsage();
				return 1;
			}
		}
		//Set the AIML header for the "--addString" command
		else if(command == "--setAddStringAIMLHeader" || command == "-sash")
		{
			if(arguments.size() == 1)
			{
				builder.addString(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printSetAddStringAIMLHeaderUsage();
				return 1;
			}
		}
		else if(command == "--setAddStringAIMLFooter" || command == "-sasf")
		{
			if(arguments.size() == 1)
			{
				builder.addString(arguments.at(0), userId, botId, endUserId);			
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printSetAddStringAIMLFooterUsage();
				return 1;
			}
		}
		else if(command == "--setAIMLSchema" || command == "-sas")
		{
			if(arguments.size() == 1)
			{
				builder.setAIMLSchema(arguments.at(0));
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printSetAIMLSchemaUsage();
				return 1;
			}
		}
		else if(command == "--setCommonTypesSchema" || command =="-scts")
		{
			if(arguments.size() == 1)
			{
				builder.setCommonTypesSchema(arguments.at(0));
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printSetCommonTypesSchemaUsage();
				return 1;
			}
		}
		else if(command == "--setAIMLValidation" || command =="-sav")
		{
			if(arguments.size() == 1)
			{
				if(arguments.at(0) == "true")
				{
					builder.setAIMLValidation(true);
				}
				else if(arguments.at(0) == "false")
				{
					builder.setAIMLValidation(false);
				}
				else
				{
				   /*
					* print error that the wrong arguments 
					* were given with this command and return 1
					* for an error
					*/
					printSetAIMLValidationUsage();
					return 1;
				}
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printSetAIMLValidationUsage();
				return 1;
			}
		}
		else if(command == "--getResponse" || command =="-gr")
		{
			if(arguments.size() == 1)
			{
				//Get the response and print it on standard out
				StringPimpl response = builder.getResponse(arguments.at(0), userId, botId, endUserId);
				if(!response.empty())
				{
					cout << response.c_str() << endl;
				}
			}
			else
			{
				/*
				 * print error that the wrong arguments 
				 * were given with this command and return 1
				 * for an error
				 */
				printGetResponseUsage();
				return 1;
			}
		}
		else if(command == "--setThat" || command == "-st")
		{
			if(arguments.size() == 1)
			{
				builder.setThat(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printSetThatUsage();
			}
		}
		else if(command == "--setTopic" || command == "-stp")
		{
			if(arguments.size() == 1)
			{
				builder.setTopic(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printSetTopicUsage();
			}
		}
		else if(command == "--getThat" || command == "-gt")
		{
			if(arguments.size() == 0)
			{
				StringPimpl that = builder.getThat(userId, botId, endUserId);
				if(!that.empty())
				{
					cout << that.c_str() << endl;
				}
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printGetThatUsage();
			}
		}
		else if(command == "--getTopic" || command == "-gtp")
		{
			if(arguments.size() == 0)
			{
				StringPimpl topic = builder.getTopic(userId, botId, endUserId);
				if(!topic.empty())
				{
					cout << topic.c_str() << endl;
				}
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printGetTopicUsage();
			}
		}
		else if(command == "--createGraph" || command =="-cg")
		{
			if(arguments.size() == 0)
			{
				builder.createGraph(userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printCreateGraphUsage();
			}
		}
		else if(command == "--removeGraph" || command =="-rg")
		{
			if(arguments.size() == 0)
			{
				builder.removeGraph(userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printRemoveGraphUsage();
			}
		}
		else if(command == "--predicateMatch" || command == "-pm")
		{
			if(arguments.size() == 2)
			{
				/*
				 * print the string true for boolean true and 
				 * the string false for boolean false 
				 */
				bool b = builder.predicateMatch(arguments.at(0), arguments.at(1), userId, botId, endUserId);
				if(b == true)
				{
					cout << "true" << endl;
				}
				else
				{
					cout << "false" << endl;
				}
			}
			else
			{
				printPredicateMatchUsage();
			}
		}
		else if(command == "--setPredicate" || command == "-sp")
		{	
			if(arguments.size() == 2)
			{
				builder.setPredicate(arguments.at(0), arguments.at(1), userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printSetPredicateUsage();
			}
		}
		else if(command == "--getPredicate" || command == "-gp")
		{
			if(arguments.size() == 1)
			{
				//Get the predicate and print it on standard output.
				StringPimpl value = builder.getPredicate(arguments.at(0), userId, botId, endUserId);
				if(!value.empty())
				{
					cout << value.c_str() << endl;
				}
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printGetPredicateUsage();
			}
		}
		else if(command == "--getBotPredicate" || command == "-gbp")
		{
			if(arguments.size() == 1)
			{
				//Get the predicate and print it on standard output.
				StringPimpl value = builder.getBotPredicate(arguments.at(0), userId, botId, endUserId);
				if(!value.empty())
				{
					cout << value.c_str() << endl;
				}
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printBotPredicateUsage();
			}

		}
		else if(command == "--setBotPredicate" || command == "-sbp")
		{
			if(arguments.size() == 2)
			{
				builder.setBotPredicate(arguments.at(0), arguments.at(1), userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printSetBotPredicateUsage();
			}
		}
		else if(command == "--getPreviousBotResponse" || command == "-gpbr")
		{
			if(arguments.size() == 2)
			{
				//Convert the two arguments to integers
				int previousBotResponse = arguments.at(0).getInteger();
				int sentence = arguments.at(1).getInteger(); 

				//Send the integers to the method
				StringPimpl response = builder.getPreviousBotResponse(previousBotResponse, sentence, userId, botId, endUserId);
				if(!response.empty())
				{
					cout << response.c_str() << endl;
				}
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printGetPreviousBotResponseUsage();
			}
		}
		else if(command == "--getPreviousUserInput" || command == "-gpui")
		{
			if(arguments.size() == 2)
			{
				//Convert the two arguments to integers
				int previousUserInput = arguments.at(0).getInteger();
				int sentence = arguments.at(1).getInteger();

				//Send the integers to the method
				StringPimpl response = builder.getPreviousUserInput(previousUserInput, sentence, userId, botId, endUserId);
				if(!response.empty())
				{
					cout << response.c_str() << endl;
				}
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printGetPreviousUserInput();
			}

		}
		else if(command == "--setBotConfigurationSchema" || command =="-sbcs")
		{
			if(arguments.size() == 1)
			{
				builder.setBotConfigurationSchema(arguments.at(0));
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printSetBotConfigurationSchemaUsage();
			}
		}
		else if(command == "--setBotConfigurationValidation" || command == "-sbcv")
		{
			if(arguments.size() == 1)
			{
				if(arguments.at(0) == "true")
				{
					builder.setBotConfigurationValidation(true);
				}
				else if(arguments.at(0) == "false")
				{
					builder.setBotConfigurationValidation(false);
				}
				else
				{
				   /*
					* print error that the wrong arguments 
					* were given with this command and return 1
					* for an error
					*/
					printSetBotConfigurationValidationUsage();
				}
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printSetBotConfigurationValidationUsage();
			}
		}
		else if(command == "--parseSubstitutionFile" || command == "-psf")
		{
			if(arguments.size() == 1)
			{
				builder.parseSubstitutionFile(arguments.at(0));
			}
			else
			{
				printParseSubstitutionFileUsage();
			}
		}
		else if(command == "--parseSentenceSplitterFile" || command == "-pssf")
		{
			if(arguments.size() == 1)
			{
				builder.parseSentenceSplitterFile(arguments.at(0));
			}
			else
			{
				printParseSentenceSplitterFileUsage();
			}
		}
		else if(command == "--parsePropertiesFile" || command == "-ppf")
		{
			if(arguments.size() == 1)
			{
				builder.parsePropertiesFile(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
				printParsePropertiesFileUsage();
			}
		}
		else if(command == "--setSentenceSplitter" || command == "-sss")
		{
			if(arguments.size() == 1)
			{
				builder.setSentenceSplitter(arguments.at(0));
			}
			else
			{
				printSetSentenceSplitterUsage();
			}
		}
		else if(command == "--setInputSubstitution" || command == "-sis")
		{
			if(arguments.size() == 2)
			{
				builder.setInputSubstitution(arguments.at(0), arguments.at(1));
			}
			else
			{
				printSetInputSubstitutionUsage();
			}
		}
		else if(command == "--setGenderSubstitution" || command == "-sgs")
		{
			if(arguments.size() == 2)
			{
				builder.setGenderSubstitution(arguments.at(0), arguments.at(1));
			}
			else
			{
				printSetGenderSubstitutionUsage();
			}
		}
		else if(command == "--setPersonSubstitution" || command == "-sps")
		{
			if(arguments.size() == 2)
			{
				builder.setPersonSubstitution(arguments.at(0), arguments.at(1));
			}
			else
			{
				printSetPersonSubstitutionUsage();
			}
		}
		else if(command == "--setPerson2Substitution" || command == "sp2s")
		{
			if(arguments.size() == 2)
			{	
				builder.setPerson2Substitution(arguments.at(0), arguments.at(1));
			}
			else
			{
				printSetPerson2SubstitutionUsage();
			}
		}
		else if(command == "--getVersion" || command =="-gv")
		{
			if(arguments.size() == 0)
			{
				StringPimpl version = builder.getVersion();
				if(!version.empty())
				{
					cout << version.c_str() << endl;
				}
			}
			else
			{
				printGetVersionUsage();
			}
		}
		else if(command == "--getSize" || command == "-gs")
		{
			if(arguments.size() == 0)
			{
				int i  = builder.getSize(userId, botId, endUserId);
				cout << i << endl;
			}
			else
			{
				printGetSizeUsage();
			}
		} 
		else if(command == "--storeGossip" || command == "-sg")
		{
			if(arguments.size() == 1)
			{
				builder.storeGossip(arguments.at(0));
			}
			else
			{
				printStoreGossipUsage();
			}
		}
		else if(command == "--getId" || command == "-gi")
		{
			if(arguments.size() == 0)
			{
				StringPimpl id = builder.getId();
				if(!id.empty())
				{
					cout << id.c_str() << endl;
				}
			}
			else
			{
				printGetIdUsage();
			}
		}
		else if(command == "--addCustomTagLibrary" || command =="-actl")
		{
			if(arguments.size() == 1)
			{
				builder.addCustomTagLibrary(arguments.at(0));
			}
			else
			{
				printAddCustomTagLibraryUsage();
			}
		}
		else if(command == "--removeCustomTagLibrary" || command == "-rctl")
		{
			if(arguments.size() == 1)
			{
				builder.removeCustomTagLibrary(arguments.at(0));
			}
			else
			{
				printRemoveCustomTagLibraryUsage();
			}
		}
		else if(command == "--callSystemCommand" || command == "-csc")
		{
			if(arguments.size() == 1)
			{
				StringPimpl sysCmd = builder.callSystemCommand(arguments.at(0));
				if(!sysCmd.empty())
				{
					cout << sysCmd.c_str() << endl;
				}
			}
			else
			{
				printCallSystemCommandUsage();
			}
		}
		else if(command == "--getAIMLFileList" || command == "-gafl")
		{
			if(arguments.size() == 0)
			{
				unsigned int size;
				StringPimpl *arrayList = builder.getAIMLFileList(userId, botId, endUserId, size);
				for(unsigned int i = 0; i < size; ++i)
				{
					cout << arrayList[i].c_str() << endl;
				}
			}
			else
			{
				printGetAIMLFileListUsage();
			}
		}
		else if(command == "--getAIMLFileListSize" || command == "-gafls")
		{
			if(arguments.size() == 0)
			{
				unsigned int size = builder.getAIMLFileListSize(userId, botId, endUserId);
				cout << size << endl;
			}
			else
			{
				printGetAIMLFileListSizeUsage();
			}
		}
		else if(command == "--getAIMLStringList" || command == "-gasl")
		{
			if(arguments.size() == 0)
			{
				unsigned int size;
				StringPimpl *arrayList = builder.getAIMLStringList(userId, botId, endUserId, size);
				for(unsigned int i = 0; i < size; ++i)
				{
					cout << arrayList[i].c_str() << endl;
				}
			}
			else
			{
				printGetAIMLStringListUsage();
			}
		}
		else if(command == "--getAIMLStringListSize" || command == "-gasls")
		{
			if(arguments.size() == 0)
			{
				unsigned int size = builder.getAIMLStringListSize(userId, botId, endUserId);
				cout << size << endl;
			}
			else
			{
				printGetAIMLStringListSizeUsage();
			}
		}
		else if(command == "--getUserIds" || command == "-guid")
		{
			if(arguments.size() == 0)
			{
				unsigned int size;
				StringPimpl *arrayList = builder.getUserIds(size);
				for(unsigned int i = 0; i < size; ++i)
				{
					cout << arrayList[i].c_str() << endl;
				}
			}
			else
			{
				printGetUserIdsUsage();
			}
		}
		else if(command == "--getUserIdsSize" || command == "-guids")
		{
			if(arguments.size() == 0)
			{
				unsigned int size = builder.getUserIdsSize();
				cout << size << endl;
			}
			else
			{
				printGetUserIdsSizeUsage();
			}
		}
		else if(command == "--getBotIds" || command == "-gbid")
		{
			if(arguments.size() == 1)
			{
				unsigned int size;
				StringPimpl *arrayList = builder.getBotIds(arguments.at(0), size);
				for(unsigned int i = 0; i < size; ++i)
				{
					cout << arrayList[i].c_str() << endl;
				}
			}
			else
			{
				printGetBotIdsUsage();
			}
		}
		else if(command == "--getBotIdsSize" || command == "-gbids")
		{
			if(arguments.size() == 1)
			{
				unsigned int size = builder.getBotIdsSize(arguments.at(0));
				cout << size << endl;
			}
			else
			{
				printGetBotIdsSizeUsage();
			}
		}
		else if(command == "--getEndUserIds" || command == "-geuid")
		{
			if(arguments.size() == 2)
			{
				unsigned int size;
				StringPimpl *arrayList = builder.getEndUserIds(arguments.at(0), arguments.at(1), size);
				for(unsigned int i = 0; i < size; ++i)
				{
					cout << arrayList[i].c_str() << endl;
				}
			}
			else
			{
				printGetEndUserIdsUsage();
			}
		}
		else if(command == "--getEndUserIdsSize" || command == "-geuids")
		{
			if(arguments.size() == 2)
			{
				unsigned int size = builder.getEndUserIdsSize(arguments.at(0), arguments.at(1));
				cout << size << endl;
			}
			else
			{
				printGetEndUserIdsSizeUsage();
			}
		}
		else if(command == "--printEntireDatabase" || command == "-ped")
		{
			if(arguments.size() == 0)
			{
				builder.printEntireDatabase();
			}
			else
			{
				printPrintEntireDatabaseUsage();
			}
		}
		else if(command == "--getBotPredicates" || command == "-gbps")
		{
			if(arguments.size() == 0)
			{
				unsigned int size;
				StringPimpl *arrayList = builder.getBotPredicates(userId, botId, endUserId, size);
				for(unsigned int i = 0; i < size; ++i)
				{
					cout << arrayList[i].c_str() << endl;
				}
			}
			else
			{
				printGetBotPredicatesUsage();
			}
		}
		else if(command == "--getPredicates" || command == "-gps")
		{
			if(arguments.size() == 0)
			{
				unsigned int size;
				StringPimpl *arrayList = builder.getPredicates(userId, botId, endUserId, size);
				for(unsigned int i = 0; i < size; ++i)
				{
					cout << arrayList[i].c_str() << endl;
				}
			}
			else
			{
				printGetPredicatesUsage();
			}
		}
		else if(command == "--getPredicatesSize" || command == "-gpss")
		{
			if(arguments.size() == 0)
			{
				int size = builder.getPredicatesSize();
				cout << size << endl;
			}
			else
			{
				printGetPredicatesSizeUsage();
			}
		}
		else if(command == "--getBotPredicatesSize" || command == "-gbpss")
		{
			if(arguments.size() == 0)
			{
				int size = builder.getBotPredicatesSize();
				cout << size << endl;
			}
			else
			{
				printGetBotPredicatesSizeUsage();
			}
		}
		else if(command == "--removePredicate" || command == "-rp")
		{	
			if(arguments.size() == 1)
			{
				builder.removePredicate(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printRemovePredicateUsage();
			}
		}
		else if(command == "--removeBotPredicate" || command == "-rbp")
		{	
			if(arguments.size() == 1)
			{
				builder.removeBotPredicate(arguments.at(0), userId, botId, endUserId);
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printRemoveBotPredicateUsage();
			}
		}
		else if(command == "--removeEndUser" || command == "-reu")
		{	
			if(arguments.size() == 3)
			{
				builder.removeEndUser(arguments.at(0), arguments.at(1), arguments.at(2));
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printRemoveEndUserUsage();
			}
		}
		else if(command == "--removeBot" || command == "-rb")
		{	
			if(arguments.size() == 2)
			{
				builder.removeBot(arguments.at(0), arguments.at(1));
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printRemoveBotUsage();
			}
		}
		else if(command == "--removeUser" || command == "-ru")
		{	
			if(arguments.size() == 1)
			{
				builder.removeUser(arguments.at(0));
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printRemoveUserUsage();
			}
		}
		else if(command == "--synchronizeDatabase" || command == "-sd")
		{
			if(arguments.size() == 0)
			{
				builder.synchronizeDatabase();
			}
			else
			{
			   /*
				* print error that the wrong arguments 
				* were given with this command and return 1
				* for an error
				*/
				printSynchronizeDatabaseUsage();
			}
		}
		else
		{
			printUsage();
		}
	}
	/* 
	 * All the exceptions are grouped here but you 
	 * might not want this since it's a bit harder 
	 * to determine where they came from.
	 */
	catch(NetworkException &e)
	{
		cout << "[Network Exception Found Terminating]" << endl;
		cout << "[" << e.what() << "]" << endl;
		return 1;
	}
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
	catch(exception &e)
	{
		cout << "[An exception local to this code occured, Terminating program]" << endl;
		cout << "[" << e.what() << "]";
		return 1;
	}
	delete networkAimlfacade;
	delete aimlFacade;
	return 0;
}

