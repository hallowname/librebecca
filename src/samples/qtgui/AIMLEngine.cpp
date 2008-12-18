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

//qtgui includes
#include "AIMLEngine.h"

//Qt includes
#include <QDir>

namespace qtgui
{

void AIMLEngine::userInput(const QString &text)
{
	/*
	 * Check the AIML engine is loaded and 
	 * that the user actually entered 
	 * something
	 */
	if((!text.isEmpty()) && m_aiml)
	{

       /*
		* Get the GraphBuilder concrete class that 
		* was created inside of AimlFacade.
		* DO NOT try to delete GraphBuilder.  Let
		* AimlFacade handle that when it falls out 
		* of scope.
		*/
		GraphBuilder &builder = m_aiml->getGraphBuilder();
		
		/*
		 * Emit the internal bot information.  Get
		 * the bot response and emit all of that 
		 * information to anyone wishing to display
		 * it.
		 */
		emit addText("");
		emit addText("");
		emit addText("Internal information:");
		emit addText("=====================");
		
		//construct the match line and emit it.
		QString matchLine = text + " : " + builder.getThat().c_str() + 
			                QString(" : ") + builder.getTopic().c_str();
		emit addText(matchLine);
		
		//Get the bot response
		StringPimpl response = builder.getResponse(text.toAscii().data());

		emit addText("=====================");
		emit addText("");

		//emit the bot response
		emit addBotText(response.c_str());
	}
}

void AIMLEngine::clearAIML()
{
	/*
	 * Emit to anyone wanting to know that we're
	 * going to be a while loading something
	 */
	emit loading();
	emit addText("[Please wait for a second while AIML unloads]");
	emit addText("[You cannot load AIML until this session is unloaded]");

	GraphBuilder &builder = m_aiml->getGraphBuilder();

	/*
	 * Just remove our bot.  We know that we've been using
	 * the default user and default bot id's since we haven't
	 * changed during the entire run of this program.
	 */
	builder.removeBot("default", "default");

	emit addText("[AIML done unloading]");
	emit addText("[No bot is loaded]");
	emit addText("[Use the file Menu to add a bot]");

	/*
	 * Emit to anyone wanting to know that we're
	 * done loading 
	 */
	emit doneLoading();
}


void AIMLEngine::addDirectory(const QString &directoryName)
{
	/*
	 * Emit to anyone wanting to know that we're
	 * going to be a while loading something
	 */
	emit loading();
	emit addText("[Rebecca loading]");

	try
	{
		/*
		 * Create and Load a AIML engine 
		 * if we don't have one.
		 */
		if(!m_aiml)
		{
			initAIML();
		}

	   /*
		* Get the GraphBuilder concrete class that 
		* was created inside of AimlFacade.
		* DO NOT try to delete GraphBuilder.  Let
		* AimlFacade handle that when it falls out 
		* of scope.
		*/
		GraphBuilder &builder = m_aiml->getGraphBuilder();

		/*
		 * Add the entire directory by extracting the
		 * "char *" from the QString and passing it to
		 * the AIML api
		 */
		builder.addDirectoryUnlessAlreadyAdded(directoryName.toAscii().data());

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
		emit addText("[Rebecca now fully loaded]");
		QString stringSize;
		stringSize.setNum(size);
		QString outputCategoriesLoaded("[Number of categories loaded: " + stringSize + "]");
		emit addText(outputCategoriesLoaded);

	   /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
		emit doneLoading();
	}
   /* 
	* All the exceptions are grouped here but you 
	* might not want this since it's a bit harder 
	* to determine where they came from.
	*/
	catch(FileNotFoundException &e)
	{
		emit addText("[A File Was Not Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(IllegalArgumentException &e)
	{
		emit addText("[IllegalArgument Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(InitializationException &e)
	{
		emit addText("[Initialization Exception Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(XMLErrorException &e)
	{
		emit addText("[XMLError Exception Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(Exception &e)
	{
		emit addText("[An uknown exception occured, Terminating program]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}

}


void AIMLEngine::addFile(const QString &fileName)
{
	/*
	 * Emit to anyone wanting to know that we're
	 * going to be a while loading something
	 */
	emit loading();
	emit addText("[Rebecca loading]");

	try
	{
		/*
		 * Create and Load a AIML engine 
		 * if we don't have one.
		 */
		if(!m_aiml)
		{
			initAIML();
		}

	   /*
		* Get the GraphBuilder concrete class that 
		* was created inside of AimlFacade.
		* DO NOT try to delete GraphBuilder.  Let
		* AimlFacade handle that when it falls out 
		* of scope.
		*/
		GraphBuilder &builder = m_aiml->getGraphBuilder();

		/*
		 * Add the file by extracting the
		 * "char *" from the QString and passing it to
		 * the AIML api
		 */
		builder.addFile(fileName.toAscii().data());

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
		emit addText("[Rebecca now fully loaded]");
		QString stringSize;
		stringSize.setNum(size);
		QString outputCategoriesLoaded("[Number of categories loaded: " + stringSize + "]");
		emit addText(outputCategoriesLoaded);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
   /* 
	* All the exceptions are grouped here but you 
	* might not want this since it's a bit harder 
	* to determine where they came from.
	*/
	catch(FileNotFoundException &e)
	{
		emit addText("[A File Was Not Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(IllegalArgumentException &e)
	{
		emit addText("[IllegalArgument Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(InitializationException &e)
	{
		emit addText("[Initialization Exception Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(XMLErrorException &e)
	{
		emit addText("[XMLError Exception Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}
	catch(Exception &e)
	{
		emit addText("[An uknown exception occured, Terminating program]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);

       /*
		* Emit to anyone wanting to know that we're
		* done loading 
		*/
        emit doneLoading();
	}

}

void AIMLEngine::initAIML()
{
	try
	{
		//Create a new AIML engine 
		m_aiml = new AimlFacade;

	   /*
		* Get the GraphBuilder concrete class that 
		* was created inside of AimlFacade.
		* DO NOT try to delete GraphBuilder.  Let
		* AimlFacade handle that when it falls out 
		* of scope.
		*/
		GraphBuilder &builder = m_aiml->getGraphBuilder();

	   /*
        * Give the address to Rebecca for usesage.
		* Rebecca DOES NOT delete it.  
		*/
		builder.setCallBacks(&m_callback);

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
		builder.parsePropertiesFile("../conf/properties.xml");

		/*
		 * Get the botName which should be Rebecca since that is 
		 * the name give in the configuration file properties.xml
		 * which we parsed above.
		 */
		string botName = builder.getBotPredicate("name").c_str();
		
		//Emit what the bot name is
		emit addBotName(botName.c_str());
	}
   /* 
	* All the exceptions are grouped here but you 
	* might not want this since it's a bit harder 
	* to determine where they came from.
	*/
	catch(DirectoryNotFoundException &e)
	{
		emit addText("[A Directory Was Not Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);
	}
	catch(FileNotFoundException &e)
	{
		emit addText("[A File Was Not Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);
	}
	catch(IllegalArgumentException &e)
	{
		emit addText("[IllegalArgument Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);
	}
	catch(InitializationException &e)
	{
		emit addText("[Initialization Exception Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);
	}
	catch(XMLErrorException &e)
	{
		emit addText("[XMLError Exception Found Terminating]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);
	}
	catch(Exception &e)
	{
		emit addText("[An uknown exception occured, Terminating program]");
		QString exception("[");
		exception += e.what();
		exception += "]";
		emit addText(exception);
	}
}


} //end of qtgui namespace 
