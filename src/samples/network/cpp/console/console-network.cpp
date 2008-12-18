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
using namespace rebecca;

//Std includes
#include <iostream>
#include <string>
using namespace std;

///@todo check documentation on this

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
int main (int argc, char* args[]) 
{
	try
	{	
		//set our locale to english
        #ifdef _WIN32
		locale::global(locale("ENG"));
        #endif

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
		NetworkGraphBuilder &builder = aiml.getNetworkGraphBuilder();
		
		/*
		 * Get the number of AIML categories loaded in total.
		 */
		int size = builder.getSize();

		//Print out the number of categories loaded.
		cout << endl << endl;
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
			else //The user gave an input to the bot
			{
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
	}
	/* 
	 * All the exceptions are grouped here but you 
	 * might not want this since it's a bit harder 
	 * to determine where they came from.
	 */
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
