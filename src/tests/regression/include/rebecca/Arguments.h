#include <string>

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

namespace rebecca
{
namespace impl
{

/*
 * I go ahead and pollute my applicaton's namespace.
 * This is okay, since I am creating an application and
 * am not creating an api.  If this was an api I'd have 
 * used another inner-namespace called something like impl 
 * and then polluted that instead to keep my outter namespace
 * clean.
 */
using namespace std;

/**
 * Parses and sets the 
 * arguments for main().
 */
class Arguments
{
	private:

		/**
		 * Holds the reference to our 
		 * singelton reference
		 */
		static Arguments *m_instance;
		
		/**
		 * Sets the arguments up
		 * from main() as well
		 * as the program name its
		 * self.
		 *
		 * @param argc The number of arguments
		 * sent in.
		 *
		 * @param args The array of arguments 
		 */
		void privateSetArguments(int argc, char *args[])
		{
			/*
			 * Iterate over the arguments
			 * and set them 
			 */
			for(int i = 1; i < argc; ++i)
			{
				//get string of the argument
				string argument(args[i]);
				
				if(m_currentArgument == NO_ARG)
				{
					if(argument == "-aimlSchema" || 
					   argument == "-as")
					{
						m_currentArgument = AIML_SCHEMA;					
					} 
					else if(argument == "-botSchema" ||
				            argument == "-bs")
					{
						m_currentArgument = BOT_SCHEMA;	
					}
					else if(argument == "-commonSchema" || 
						    argument == "-cs")
					{
						m_currentArgument = COMMON_SCHEMA;
					}
					else if(argument == "-configurationDirectory" || 
							argument == "-cd")
					{
						m_currentArgument = CONFIGURATION;
					}
					else if(argument == "-aimlDirectory" || 
						    argument == "-ad")
					{
						m_currentArgument = AIML;	
					}
					else if(argument == "-resourcesDirectory" ||
						    argument == "-rd")
					{
						m_currentArgument = RESOURCES;
					}
					else if(argument == "-help" || 
						    argument == "-h" || 
							argument == "/?" ||
							argument == "--help")
					{
						/*
						 * Display help and exit
						 */
						cout << endl << endl
							 << "[console.exe help]" << endl
							 << "------------------" << endl << endl
							 << "Available switches:" << endl << endl
							 << "[-aimlSchema or -as]" << endl 
							 << "    AIML Schema Path (default is ../../resources/schema/AIML.xsd)" << endl << endl
							 << "[-botSchema or -bs] " << endl 
							 << "    Bot Schema Path (default is ../../resources/schema/bot-configuration.xsd)" << endl << endl
							 << "[-commonSchema or -cs] " << endl
							 << "    Common Schema Path (default is ../../resources/schema/common-types.xsd)" << endl << endl
							 << "[-configurationDirectory or -cd] " << endl
							 << "    Configuration directory (default is ../../conf)" << endl << endl
							 << "[-aimlDirectory or -ad] " << endl
							 << "    AIML directory with *.aiml files (default is ../../aiml/annotated_alice)" << endl << endl
							 << "[-resourcesDirectory or -rd] " << endl
							 << "    AIML directory with resource files (default is ../../resources)" << endl << endl
							 << endl;
						exit(0);
					}
					else
					{
						cout << 
							"[Illegal argument of " +
							string(args[i]) +
							" found]" 
							<< endl;
					}
				}
				else
				{
					/*
					 * We already encountered the switch, 
					 * now we just need to set the argument
					 */
					if(m_currentArgument == AIML)
					{
						m_aimlDirectory = argument;
					}
					else if(m_currentArgument == AIML_SCHEMA)
					{
						m_aimlSchemaPath = argument;
					}
					else if(m_currentArgument == BOT_SCHEMA)
					{
						m_botConfigurationSchemaPath = argument;
					}
					else if(m_currentArgument == COMMON_SCHEMA)
					{
						m_commonTypesSchemaPath = argument;
					}
					else if(m_currentArgument == CONFIGURATION)
					{
						m_configurationDirectory = argument;
					}
					else if(m_currentArgument == RESOURCES)
					{
						m_resourcesDirectory = argument;
					}
					else
					{
						cout << "Programmer error "
							    "this should not be reached"
							 << endl;
					}

					m_currentArgument = NO_ARG;
				}
			}
		}

		/**
		 * Constructor that
		 * sets the arguments up
		 * from main() as well
		 * as the program name its
		 * self.  This is a default
		 * constructor that sets default
		 * values for everything.
		 *
		 */
		Arguments()
			: m_aimlSchemaPath("../../resources/schema/AIML.xsd"),
			  m_commonTypesSchemaPath("../../resources/schema/common-types.xsd"),
			  m_botConfigurationSchemaPath("../../resources/schema/bot-configuration.xsd"),
			  m_configurationDirectory("../../conf"),
			  m_aimlDirectory("../../aiml/annotated_alice"),
			  m_currentArgument(NO_ARG),
			  m_resourcesDirectory("../../resources")
		{ }

	public:

		/**
		 * Sets the arguments up
		 * from main() as well
		 * as the program name its
		 * self.
		 *
		 * @param argc The number of arguments
		 * sent in.
		 *
		 * @param args The array of arguments 
		 */
		static void setArguments(int argc, char *args[])
		{
			if(m_instance == 0)
			{
				m_instance = new Arguments();
			}

			m_instance->privateSetArguments(argc, args); 
		}
		
		/**
		 * Gets our single instance
		 * of this class
		 *
		 * @return the single instance
		 * of this class
		 */
		static Arguments *getInstance()
		{
			if(m_instance == 0)
			{
				m_instance = new Arguments();
			}

			return m_instance;
		}
		
		/**
		 * Returns the configuration
		 * directory that has been set.
		 *
		 * @return The configuration directory
		 * where needed configuration files 
		 * are stored.
		 */
		string getConfigurationDirectory() const
		{
			return m_configurationDirectory;
		}
		
		/**
		 * Returns the AIML
		 * directory that has been set.
		 *
		 * @return The AIML directory
		 * where aiml files are stored.
		 */
		string getAimlDirectory() const
		{
			return m_aimlDirectory;
		}

		/**
		 * Returns the AIML schema
		 * path that has been set.
		 *
		 * @return The AIML schema 
		 * path that has been set.
		 */
		string getAimlSchemaPath() const
		{
			return m_aimlSchemaPath;
		}

		/**
		 * Returns the common types 
		 * schema path that has been set.
		 *
		 * @return The common types 
		 * schema path that has been set.
		 */
		string getCommonTypesSchemaPath() const
		{
			return m_commonTypesSchemaPath;
		}

		/**
		 * Returns the bot configuration
		 * schema path that has been set.
		 *
		 * @return the bot configuration
		 * schema path that has been set.
		 */
		string getBotConfigurationSchemaPath() const
		{
			return m_botConfigurationSchemaPath;
		}
		
		/**
		 * Returns the resource directory.
		 * 
		 * @return the resource directory.
		 */
		string getResourcesDirectory() const
		{
			return m_resourcesDirectory;
		}
		/** 
		 * Enumeration of possible switches you
		 * can give rebecca
		 */
		enum arguments{ NO_ARG, AIML, AIML_SCHEMA, 
			            COMMON_SCHEMA, BOT_SCHEMA,
						RESOURCES, CONFIGURATION};
		/**
		 * The current argument state.
		 */
		arguments m_currentArgument;

		/**
		 * The location of RebeccaAIML's
		 * configuration directory.  
		 *
		 * If this is not set, it will default 
		 * to the current working directory
		 * + "../../conf".  This is where
		 * needed configuration files are
		 * stored.
		 */
		string m_configurationDirectory;

		/**
		 * The location of a AIML directory.
		 *
		 * If this is not set, it will default
		 * to the current working directory 
		 * + "../../aiml/annotated_alice".
		 */
		string m_aimlDirectory;
		
		/**
		 * The path to the aiml xsd file.
		 * 
		 * If this is not set, it will default
         * to the current working directory + 
		 * "../../resources/schema/AIML.xsd"
		 */
		string m_aimlSchemaPath;

		/**
		 * The path to the the common types
		 * schema file.
		 * 
		 * If this is not set, it will default
         * to the current working directory + 
		 * "../resources/schema/common-types.xsd"
		 */
		string m_commonTypesSchemaPath;
		
		/**
		 * The path to the bot configuration
		 * schema file.
		 * 
		 * If this is not set, it will default
         * to the current working directory + 
		 * "../resources/schema/bot-configuration.xsd"
		 */
		string m_botConfigurationSchemaPath;
		
		/**
		 * The location of the resources
		 * directory.  If this is not set, it
		 * will default to current working directory +
		 * "../../resources"
		 */
		string m_resourcesDirectory;
};

} //end of impl namespace
using rebecca::impl::Arguments;
} //end of rebecca namespace
