#ifndef SERVER_READSERVERSETTINGS_H
#define SERVER_READSERVERSETTINGS_H

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
#include <rebecca/GraphBuilder.h>

//boost includes
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

//Ice includes
#include <Ice/Ice.h>

namespace rebecca
{
namespace impl
{

using namespace boost::filesystem;
using namespace boost;

void parseSettings(string line, GraphBuilder &builder, Ice::LoggerPtr logger, int lineCount, bool shouldLog);

void readSettings(string fileName, GraphBuilder &builder, Ice::LoggerPtr logger, bool shouldLog)
{
	try
	{
		//Get the file format in the native string 
		path nativeFileFormat(fileName, native);
			
		//Get the complete path to the file
		path completePath = complete(nativeFileFormat);

		if(!exists(nativeFileFormat))
		{
			if(shouldLog)
				logger->warning("The log file specified was not found:" + completePath.native_file_string());
		}
		else
		{
			string nativeFile = completePath.native_file_string();
			boost::filesystem::ifstream file( completePath );
			string line;
			int lineCount = 0;
			while (!file.eof() )
			{
				++lineCount;
				getline(file,line);
				trim(line);
				if(line.empty() || starts_with(line, "#"))
				{
					continue;
				}
				else
				{
					parseSettings(line, builder, logger, lineCount, shouldLog);
				}
			}
			file.close();			
		}
	}
	catch(exception &e)
	{
		string s = "Exception trying to read the config file:";

		if(shouldLog)
			logger->error(s + e.what());
	}
}


void genericError(int lineCount, string command, string message, Ice::LoggerPtr logger, bool shouldLog)
{
	if(shouldLog)
	{
		stringstream s;
		s << "\nException caught reading server config file, executing line:";
		s << lineCount;
		s << "\ncommand:";
		s << command;
		s << "\n" + message;
		logger->error(s.str());
	}

}

void exceptionCaught(int lineCount, string command, string exception, Ice::LoggerPtr logger, bool shouldLog)
{
	if(shouldLog)
	{
		stringstream s;
		s << "\nException caught reading server config file, executing line:";
		s << lineCount;
		s << "\ncommand:";
		s << command;
		s << "\nException Cause:\n";
		s << exception;
		logger->error(s.str());
	}
}



void parseSettings(string line, GraphBuilder &builder, Ice::LoggerPtr logger, int lineCount, bool shouldLog)
{

	//The command
	string command;

	//The arguments to the command
	vector<string> arguments;

	bool openingQuote = false;
	int j = 0;
	for(unsigned int i = 0; i < line.length(); ++i)
	{
		string c;
		c += line.at(i);
		if(c == " " && command.empty())
		{
			command = line.substr(0, i);
		}
		else if(c == "\"" && (openingQuote == false))
		{
			openingQuote = true;
			j = i;
		}
		else if(c == "\"" && (openingQuote == true))
		{
			arguments.push_back(line.substr(j + 1, i - j - 1));
			openingQuote = false;
		}
	}

	if(command.empty())
	{
		//No arugments, the entire line is just one commmand
		command = line;
	}

	if(openingQuote == true)
	{
		//error unterminated quote
		genericError(lineCount, line, "has an unterminated quote", logger, shouldLog);
		return;
	}

	try
	{
		
		 //Here is the master command 
		 //checking.  During these if/else if's
		 //the command will be checked against the
		 //list of possibilities.  If one is not found
		 //it will terminate with an error message.  If
		 //one is found but the argument size is wrong an
		 //error message will be printed and it will be 
		 //terminated with an error.

		//Add a directory
		if(command == "--addDirectory" || command == "-ad")
		{
			if(arguments.size() == 1)
			{
				builder.addDirectory(arguments.at(0).c_str());
			}
			else if(arguments.size() == 2)
			{
				builder.addDirectory(arguments.at(0).c_str(), arguments.at(1).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		//Add a file
		else if(command == "--addFile" || command == "-af")
		{
			if(arguments.size() == 1)
			{
				builder.addFile(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		//Add a string
		else if(command == "--addString" || command == "-as")
		{
			if(arguments.size() == 1)
			{
				builder.addString(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		//Set the AIML header for the "--addString" command
		else if(command == "--setAddStringAIMLHeader" || command == "-sash")
		{
			if(arguments.size() == 1)
			{
				builder.addString(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setAddStringAIMLFooter" || command == "-sasf")
		{
			if(arguments.size() == 1)
			{
				builder.addString(arguments.at(0).c_str());			
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setAIMLSchema" || command == "-sas")
		{
			if(arguments.size() == 1)
			{
				builder.setAIMLSchema(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setCommonTypesSchema" || command =="-scts")
		{
			if(arguments.size() == 1)
			{
				builder.setCommonTypesSchema(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
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
					genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
				}
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--getResponse" || command =="-gr")
		{
			if(arguments.size() == 1)
			{
				//Get the response but don't print anything.
				builder.getResponse(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setThat" || command == "-st")
		{
			if(arguments.size() == 1)
			{
				builder.setThat(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setTopic" || command == "-stp")
		{
			if(arguments.size() == 1)
			{
				builder.setTopic(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--createGraph" || command =="-cg")
		{
			if(arguments.size() == 0)
			{
				builder.createGraph();
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setPredicate" || command == "-sp")
		{	
			if(arguments.size() == 2)
			{
				builder.setPredicate(arguments.at(0).c_str(), arguments.at(1).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setBotPredicate" || command == "-sbp")
		{
			if(arguments.size() == 2)
			{
				builder.setBotPredicate(arguments.at(0).c_str(), arguments.at(1).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setBotConfigurationSchema" || command =="-sbcs")
		{
			if(arguments.size() == 1)
			{
				builder.setBotConfigurationSchema(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
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
					genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
				}
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--parseSubstitutionFile" || command == "-psf")
		{
			if(arguments.size() == 1)
			{
				builder.parseSubstitutionFile(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--parseSentenceSplitterFile" || command == "-pssf")
		{
			if(arguments.size() == 1)
			{
				builder.parseSentenceSplitterFile(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--parsePropertiesFile" || command == "-ppf")
		{
			if(arguments.size() == 1)
			{
				builder.parsePropertiesFile(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setSentenceSplitter" || command == "-sss")
		{
			if(arguments.size() == 1)
			{
				builder.setSentenceSplitter(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setInputSubstitution" || command == "-sis")
		{
			if(arguments.size() == 2)
			{
				builder.setInputSubstitution(arguments.at(0).c_str(), arguments.at(1).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setGenderSubstitution" || command == "-sgs")
		{
			if(arguments.size() == 2)
			{
				builder.setGenderSubstitution(arguments.at(0).c_str(), arguments.at(1).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setPersonSubstitution" || command == "-sps")
		{
			if(arguments.size() == 2)
			{
				builder.setPersonSubstitution(arguments.at(0).c_str(), arguments.at(1).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--setPerson2Substitution" || command == "sp2s")
		{
			if(arguments.size() == 2)
			{	
				builder.setPerson2Substitution(arguments.at(0).c_str(), arguments.at(1).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--storeGossip" || command == "-sg")
		{
			if(arguments.size() == 1)
			{
				builder.storeGossip(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--addCustomTagLibrary" || command =="-actl")
		{
			if(arguments.size() == 1)
			{
				builder.addCustomTagLibrary(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--removeCustomTagLibrary" || command == "-rctl")
		{
			if(arguments.size() == 1)
			{
				builder.removeCustomTagLibrary(arguments.at(0).c_str());
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else if(command == "--callSystemCommand" || command == "-csc")
		{
			if(arguments.size() == 1)
			{
				StringPimpl sysCmd = builder.callSystemCommand(arguments.at(0).c_str());
				if(!sysCmd.empty())
				{
					cout << sysCmd.c_str() << endl;
				}
			}
			else
			{
				genericError(lineCount, command, "invalid number of arguments given", logger, shouldLog);
			}
		}
		else
		{
			genericError(lineCount, command, "The command was not found", logger, shouldLog);
		}
	}
	 
	// All the exceptions are grouped here but you 
	// might not want this since it's a bit harder 
	// to determine where they came from.
	catch(NetworkException &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}
	catch(DirectoryNotFoundException &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}
	catch(FileNotFoundException &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}
	catch(IllegalArgumentException &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}
	catch(InitializationException &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}
	catch(XMLErrorException &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}
	catch(Exception &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}
	catch(exception &e)
	{
		exceptionCaught(lineCount, command, e.what(), logger, shouldLog);
	}

}

} //end of impl namespace
} //end of rebecca namespace

#endif


