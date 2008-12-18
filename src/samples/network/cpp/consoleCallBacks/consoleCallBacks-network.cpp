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
#include <CustomCallBacks.h>
using namespace rebecca;

//Std includes
#include <iostream>
#include <string>
using namespace std;


///@todo ceck and change these comments

/**
 * Console version to query a AIML set.
 * 
 * I use the annotated alice data set that's 
 * provided as an example.
 *
 * Optionally, you can give this a 
 * "-b baseDirectoryOfRebecca" flag.  This
 * flag tells us where we have RebeccaAIML's
 * aiml files and conf files stored at. For
 * example if you have RebeccaAIML stored at
 * /opt/RebeccAIML you would call this program
 * as:
 * 
 * console -b "/opt/RebeccaAIML/".  This sample
 * will then look in /opt/RebeccaAIML/conf for
 * the configuration files and 
 * /opt/RebeccaAIML/aiml/annotated_alice for
 * the annotated alice files.
 * 
 */

/**
 * Print the usage of this program
 */
void printUsage()
{
	cout << "You need to at least give the directory" << endl
		 << "of AIML files to load" << endl << endl
		 << "Example: ConsoleCallBacks-network /rebecca/aiml/annotated_alice" << endl
		 << "Example: ConsoleCallBacks-network /rebecca/aiml/annotated_alice --Ice.Config=/rebecca/conf/clientconfig.properties" << endl
		 << endl
		 << "To load a directory based on a specific userId, botId, endUserId" << endl
		 << "ConsoleCallBacks-network -suids <userId> <botId> <endUserId>" << endl
		 << "Example: ConsoleCallBacks-network -suids user1 bot1 endUser1 /rebecca/aiml/annotated_alice" << endl
		 << "Example: ConsoleCallBacks-network -suids user1 bot1 endUser1 /rebecca/aiml/annotated_alice --Ice.Config=/rebecca/conf/clientconfig.properties" << endl
		 << endl;
}

int main (int argc, char* args[]) 
{
	try
	{		
		StringPimpl directoryName; 
		StringPimpl userId = "default";
		StringPimpl botId = "default";
		StringPimpl endUserId = "default";
		if(argc < 2)
		{
			printUsage();
			return 1;
		}
		else
		{
			StringPimpl arg1 = args[1];
			if(arg1 == "-suids")
			{
				if(argc < 6)
				{
					printUsage();
					return 1;
				}
				else
				{
					userId = args[2];
					botId = args[3];
					endUserId = args[4];
					directoryName = args[5];			
				}
			}
			else
			{
				directoryName = args[1];
			}
		}

		/*
		 * This is responsible for memory management of 
		 * GraphBuilder.
		 */
		NetworkAimlFacade aiml(argc, args);

		/*
		 * Get the GraphBuilder concrete class that 
		 * was created inside of AimlFacade.
		 * DO NOT try to delete GraphBuilder.  Let
		 * AimlFacade handle that when it falls out 
		 * of scope.
		 */
		GraphBuilder &builder = aiml.getNetworkGraphBuilder();

		/*
		 * Set the UserId, botId, endUserId
		 * By default if the user doesn't change this it 
		 * will be "default" for all three
		 */
		builder.setUserIdBotIdEndUserId(userId, botId, endUserId);
		/*
		 * Create an instantiation of our custom 
		 * callbacks we created above.
		 *
		 * Hand it our userId, botId, and endUserId so we
		 * can filter based on them and only show callbacks
		 * based on our userId, botId, and endUserId
		 */
		CustomCallBacks callback(userId, botId, endUserId);

		/* Give the address to Rebecca for usesage.
		 * Rebecca DOES NOT delete it.  
		 */
		builder.setCallBacks(&callback);

		cout << "[Rebecca loading]" << endl;

		/*
		 * Add the entire directory.  Every file that has the 
		 * extension ".aiml" will be added to the internal queue 
		 * for latter processing.  Unless the directory has 
		 * already been added.  In which case it will not be 
		 * added twice.
		 */
		builder.addDirectoryUnlessAlreadyAdded(directoryName);

		/*
		 * No other files to add to the internal queue.  
		 * So, let's create the AIML graph, the internal 
		 * data structures.
		 */
		builder.createGraph();
		
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
		StringPimpl botName = builder.getBotPredicate("name");

		/*
		 * Send a initial conversation of "connect" to 
		 * annotated alice and get the response.
		 */
		StringPimpl response = builder.getResponse("connect");		

		//Send the initial opening line of the bot
		cout << botName.c_str() << " says: " << response.c_str() << endl;

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
				cout << botName.c_str() << " says: " << response.c_str() << endl;
			}
		}
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
	catch(NetworkException &e)
	{
		cout << "[NetworkException Found Terminating]" << endl;
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
