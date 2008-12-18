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


/*
 * We disable the deprecated usage
 * warning strictly for this boost
 * header file under Windows only.
 */
#ifdef _WIN32
#    pragma warning(push)
#    pragma warning( disable : 4996 )
#endif

//Rebecca includes
#include <rebecca/impl/GraphBuilderAIML.h>
#include <rebecca/impl/DatabaseManager.h>
#include <rebecca/impl/StarsManager.h>
#include <rebecca/impl/PredicateManager.h>
#include <rebecca/impl/PreviousResponsesManager.h>
#include <rebecca/impl/XercesSAXXMLManager.h>
#include <rebecca/framework/IdentificationManager.h>
#include <rebecca/impl/RemoveGraphHandler.h>
#include <rebecca/impl/ScopedTransaction.h>

//Boost includes
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>    
#include <boost/filesystem/exception.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string_regex.hpp>

#ifdef _WIN32
#    pragma warning(pop)
#endif

//Boost includes
using namespace boost;
using namespace boost::filesystem;

//Stl includes
#include <iostream>
#include <sstream>
using namespace std;


//Xerces includes
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
XERCES_CPP_NAMESPACE_USE

//Rebecca includes
#include <rebecca/impl/utils/Transcode.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/GraphHandlerError.h>
#include <rebecca/impl/ConfigurationHandlerError.h>
#include <rebecca/framework/CustomTags.h>
using namespace rebecca;
using namespace rebecca::framework;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 * 4290
 *
 * Disable the warning about "this" 
 * being used in base memeber initializer
 * list.
 * 4355
 *
 * The extra includes under Windows is 
 * for the callCommand() method to 
 * operate under Windows
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
#    pragma warning( disable : 4355 )
#    include <windows.h>
#    include <errno.h>
#    include <io.h>
#    include <fcntl.h> 
#    include <ctype.h>
#else 
#   include <dlfcn.h>	
#endif

namespace rebecca
{
namespace impl
{

//static initializations
GraphBuilderAIML *GraphBuilderAIML::m_instance = 0;

GraphBuilderAIML::GraphBuilderAIML()
	throw(InitializationException &, Exception &)
	: m_setAIMLValidation(false), 
	  m_doConfigurationValidation(false),
	  m_aimlHeader("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?> "
						"<aiml version=\"1.0.1\" xmlns=\"http://alicebot.org/2001/AIML-1.0.1\" "
						"xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "
						"xsi:schemaLocation=\"http://alicebot.org/2001/AIML-1.0.1 http://aitools.org/aiml/schema/AIML.xsd\">"
	               ),
	  m_aimlFooter("</aiml>"),
	  m_dbEnvironmentInitialized(false),
	  m_databaseManager(0),
	  m_starsManager(0),
	  m_identificationManager(0),
	  m_previousResponsesManager(0),
	  m_xmlManager(0)
{
}

GraphBuilderAIML *GraphBuilderAIML::reset()
{
	///@todo this method can throw exceptions such as InitializationException &, Exception &
	 //since we have initilizeXerces and init in here now.  We should do something about telling the caller about this.

	if(m_instance != 0)
	{
		delete m_instance;
	}
	m_instance = new GraphBuilderAIML();

	m_instance->m_databaseManager = DatabaseManager::getInstance();
	m_instance->m_starsManager = StarsManager::getInstance();
	m_instance->m_identificationManager = IdentificationManager::getInstance();
	m_instance->m_predicateManager = PredicateManager::getInstance();
	m_instance->m_previousResponsesManager = PreviousResponsesManager::getInstance();
	m_instance->m_xmlManager = XercesSAXXMLManager::getInstance();

	try 
	{
		m_instance->initializeXerces();
		m_instance->init();
		m_instance->setUserIdBotIdEndUserId("default", "default", "default");
	}
	catch(const XMLException &toCatch) 
	{
		//ERROR, Caught XMLXMLException exception
		Transcode message(toCatch.getMessage());
		string msg("XMLException during initalization: " + message.getString());
		throw InitializationExceptionImpl(msg.c_str());
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}

	return m_instance;
}

void GraphBuilderAIML::init()
	throw(XMLException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		//defaultCallBacks does nothing.
		m_callBacks = &m_defaultCallBacks;
		
		//Set that and topic to default "*"
		StringPimpl that = getThat();
		if(that.empty())
		{
			setThat("*");
		}
		StringPimpl topic = getTopic();
		if(topic.empty())
		{
			setTopic("*");
		}

		//Allocating the document handlers for the respective parsers
		m_AIMLDocumentHandler.reset(new GraphHandler(m_NodeMapperRoot));
		m_AIMLRemoveDocumentHandler.reset(new RemoveGraphHandler(m_NodeMapperRoot));
		m_configurationDocumentHandler.reset(new ConfigurationHandler);
		
		//Allocating the Error handling routines for the respective parsers
		m_AIMLErrorHandler.reset(new GraphHandlerError);
		m_configurationErrorHandler.reset(new ConfigurationHandlerError);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl *GraphBuilderAIML::getAIMLFileList(const StringPimpl &userId, 
	                                           const StringPimpl &botId, 
									           const StringPimpl &endUserId,
									           unsigned int &size) const
	throw(Exception &)

{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getAIMLFileList(size);
}

unsigned int GraphBuilderAIML::getAIMLFileListSize(const StringPimpl &userId, 
	                                               const StringPimpl &botId, 
									               const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getAIMLFileListSize();
}

void GraphBuilderAIML::deleteStringPimplArray(StringPimpl *arrayToDelete) const
	throw(Exception &)
{
	delete []arrayToDelete;
}

StringPimpl *GraphBuilderAIML::getAIMLFileList(unsigned int &size) const
	throw(Exception &)
{
	StringPimpl userId = m_identificationManager->getUserId();
	StringPimpl botId = m_identificationManager->getBotId();
	StringPimpl endUserId = m_identificationManager->getEndUserId();
	return m_databaseManager->getRecordCountList(userId + "_@" + botId + "_@files_@", size);
}


unsigned int GraphBuilderAIML::getAIMLFileListSize() const
	throw(Exception &)
{
	StringPimpl userId = m_identificationManager->getUserId();
	StringPimpl botId = m_identificationManager->getBotId();
	return m_databaseManager->getRecordTotalCount(userId + "_@" + botId + "_@files_@");
}

StringPimpl *GraphBuilderAIML::getAIMLStringList(const StringPimpl &userId, 
	                                             const StringPimpl &botId, 
									             const StringPimpl &endUserId,
									             unsigned int &size) const
	throw(Exception &)

{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getAIMLStringList(size);
}

unsigned int GraphBuilderAIML::getAIMLStringListSize(const StringPimpl &userId, 
	                                                 const StringPimpl &botId, 
									                 const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getAIMLStringListSize();
}

StringPimpl *GraphBuilderAIML::getAIMLStringList(unsigned int &size) const
	throw(Exception &)
{
	StringPimpl userId = m_identificationManager->getUserId();
	StringPimpl botId = m_identificationManager->getBotId();
	StringPimpl endUserId = m_identificationManager->getEndUserId();
	return m_databaseManager->getRecordCountList(userId + "_@" + botId + "_@strings_@", size);
}

unsigned int GraphBuilderAIML::getAIMLStringListSize() const
	throw(Exception &)
{
	StringPimpl userId = m_identificationManager->getUserId();
	StringPimpl botId = m_identificationManager->getBotId();
	return m_databaseManager->getRecordTotalCount(userId + "_@" + botId + "_@strings_@");
}


void GraphBuilderAIML::addFile(const StringPimpl &file)
	throw(FileNotFoundException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		if(!file.existsAsAFile())
		{
			//USER ERROR, is not a file
			StringPimpl fileNotFoundMsg = "File:" + file + " was not found";
			throw FileNotFoundExceptionImpl(fileNotFoundMsg.c_str());
		}
		else
		{
			//file exists, adding to filesNotGraphed
			file.transformIntoAbsoluteFilePath();

			//See if a vector full with files for this userId and BotId
			//can be found.  If it can't then create the vector and add it.
			//If it does exist, then add this file to it.
			m_databaseManager->addRecordWithCount(userId + "_@" + botId + "_@filesNotGraphed_@", file);
		}
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::addFile(const StringPimpl &file,
                               const StringPimpl &userId,
							   const StringPimpl &botId,
							   const StringPimpl &endUserId) 
	throw(FileNotFoundException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	addFile(file);
}

void GraphBuilderAIML::removeFile(const StringPimpl &file) 
	throw(FileNotFoundException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();

		//Doesn't matter if the file exists on the filesystem or not, adding to filesGraphed
		file.transformIntoAbsoluteFilePath();

		if(!file.existsAsAFile())
		{
			//USER ERROR, is not a file
			StringPimpl fileNotFoundMsg = "File:" + file + " was not found";
			throw FileNotFoundExceptionImpl(fileNotFoundMsg.c_str());
		}
		else
		{
			m_databaseManager->addRecordWithCount(userId + "_@" + botId + "_@filesGraphed_@", file);
		}
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::removeFile(const StringPimpl &file,
	                              const StringPimpl &userId,
				                  const StringPimpl &botId,
				                  const StringPimpl &endUserId) 
	throw(FileNotFoundException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	removeFile(file);
}

void GraphBuilderAIML::removeGraph() 
	throw(XMLErrorException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		
		//Go through the files and graph each one in 
		//turn and then erase all the files from the 
		//map

		//First find the vector of files using the 
		//userId and BotId
		vector<StringPimpl> filesGraphed = m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@filesGraphed_@");
		for(unsigned int i = 0; i < filesGraphed.size(); ++i)
		{
			StringPimpl fileGraphed = filesGraphed.at(i);
			Transcode transcodedString(fileGraphed.c_str());
			LocalFileInputSource lfi(transcodedString.getXmlChar());
			makeGraph(lfi, fileGraphed, true);

			//See if the file exists in the currently addded files for this userId, botId.
			//If it does exist then remove it.
			if((m_databaseManager->recordCountExists(userId + "_@" + botId + "_@files_@", fileGraphed)))
			{
				m_databaseManager->deleteRecordWithCount(userId + "_@" + botId + "_@files_@", fileGraphed);
			}
		}
		m_databaseManager->deleteRecordCount(userId + "_@" + botId + "_@filesGraphed_@");


		//Go through the AIML strings in memory 
		//and graph each one in turn and then 
		//erase all the strings from the 
		//map

		vector<StringPimpl> stringsGraphed = m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@stringsGraphed_@");
		for(unsigned int i = 0; i < stringsGraphed.size(); ++i)
		{
			StringPimpl string = stringsGraphed.at(i);
			MemBufInputSource mis((const XMLByte*)string.c_str(), 
				                   string.size(), 
								   "AIML String", 
								   false);
			makeGraph(mis, "AIML String", true);

			//See if the file exists in the currently addded files for this userId, botId.
			//If it does not exist then add it.
			if((m_databaseManager->recordCountExists(userId + "_@" + botId + "_@strings_@", string)))
			{
				m_databaseManager->deleteRecordWithCount(userId + "_@" + botId + "_@strings_@", string);
			}
		}
		m_databaseManager->deleteRecordCount(userId + "_@" + botId + "_@stringsGraphed_@");

	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::removeGraph(const StringPimpl &userId,
                                   const StringPimpl &botId,
				                   const StringPimpl &endUserId) 
	throw(XMLErrorException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	removeGraph();
}

void GraphBuilderAIML::removeDirectory(const StringPimpl &directory, 
									   const StringPimpl &userId,
									   const StringPimpl &botId,
									   const StringPimpl &endUserId,
									   const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	removeDirectory(directory, regularExpression);
}

void GraphBuilderAIML::removeDirectory(const StringPimpl &directory, 
									   const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, 
	      DirectoryNotFoundException &, 
		  Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		regex rx1(regularExpression.c_str(), boost::regex::icase);
		smatch what;
		
		if (!directory.existsAsADirectory())
		{
			//ERROR, Exception Directory does not exist
			string directoryNotFoundmsg("Directory:" + string(directory.c_str()) + " was not found");
			throw DirectoryNotFoundExceptionImpl(directoryNotFoundmsg.c_str());
		}
		
		// default construction yields past-the-end
		directory_iterator end_itr; 

		//transform into absolute file path
		directory.transformIntoAbsoluteFilePath();

		//Get the native file system's string to pass to xerces
		string nativeDir = directory.c_str();

		//Get the file format in the native string for Xerces
		path nativeFileFormat(directory.c_str(), native);

		//Get the complete path to the file
		path completePath = complete(nativeFileFormat);

		for ( directory_iterator itr(completePath); itr != end_itr; ++itr )
		{
			if ( !is_directory( *itr ) && regex_match(string(itr->leaf()), what, rx1))
			{
				string fileLocation(nativeDir);
				fileLocation += "/" + itr->leaf();
				removeFile(fileLocation.c_str());
			}
		}	
	}
	catch(filesystem_error &)
	{
		//ERROR, filesystem error
		throw IllegalArgumentExceptionImpl("File system error");
	}
	catch(bad_expression &)
	{
		//ERROR, bad expression
		throw IllegalArgumentExceptionImpl("Bad expression with the regular expression argument");
	}
	catch(runtime_error &)
	{
		//ERROR, Runtime error
		throw IllegalArgumentExceptionImpl("Run time error occured, more than likely with the regular expression");
	}
	catch(FileNotFoundException &)
	{
		//FileNotFoundException, you should not be here
		throw IllegalArgumentExceptionImpl("File not found exception occured.  You must have passed a bad directory in.");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::addDirectory(const StringPimpl &directory, 
									const StringPimpl &userId,
									const StringPimpl &botId,
									const StringPimpl &endUserId,
									const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	addDirectory(directory, regularExpression);
}

void GraphBuilderAIML::addDirectory(const StringPimpl &directory, 
									const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, 
	      DirectoryNotFoundException &, 
		  Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		regex rx1(regularExpression.c_str(), boost::regex::icase);
		smatch what;
		
		if (!directory.existsAsADirectory())
		{
			//ERROR, Exception Directory does not exist
			string directoryNotFoundmsg("Directory:" + string(directory.c_str()) + " was not found");
			throw DirectoryNotFoundExceptionImpl(directoryNotFoundmsg.c_str());
		}
		
		// default construction yields past-the-end
		directory_iterator end_itr; 

		//transform into absolute file path
		directory.transformIntoAbsoluteFilePath();

		//Get the native file system's string to pass to xerces
		string nativeDir = directory.c_str();

		//Get the file format in the native string for Xerces
		path nativeFileFormat(directory.c_str(), native);

		//Get the complete path to the file
		path completePath = complete(nativeFileFormat);

		for ( directory_iterator itr(completePath); itr != end_itr; ++itr )
		{
			if ( !is_directory( *itr ) && regex_match(string(itr->leaf()), what, rx1))
			{
				string fileLocation(nativeDir);
				fileLocation += "/" + itr->leaf();
				addFile(fileLocation.c_str());
			}
		}	
	}
	catch(filesystem_error &)
	{
		//ERROR, filesystem error
		throw IllegalArgumentExceptionImpl("File system error");
	}
	catch(bad_expression &)
	{
		//ERROR, bad expression
		throw IllegalArgumentExceptionImpl("Bad expression with the regular expression argument");
	}
	catch(runtime_error &)
	{
		//ERROR, Runtime error
		throw IllegalArgumentExceptionImpl("Run time error occured, more than likely with the regular expression");
	}
	catch(FileNotFoundException &)
	{
		//FileNotFoundException, you should not be here
		throw IllegalArgumentExceptionImpl("File not found exception occured.  You must have passed a bad directory in.");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
	                                                           const StringPimpl &regularExpression)
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);

		//get the list of files from the db
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		vector<StringPimpl> files = m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@files_@");

		regex rx1(regularExpression.c_str(), boost::regex::icase);
		smatch what;
		
		if (!directory.existsAsADirectory())
		{
			//ERROR, Exception Directory does not exist
			string directoryNotFoundmsg("Directory:" + string(directory.c_str()) + " was not found");
			throw DirectoryNotFoundExceptionImpl(directoryNotFoundmsg.c_str());
		}
		
		// default construction yields past-the-end
		directory_iterator end_itr; 

		//transform into absolute file path
		directory.transformIntoAbsoluteFilePath();

		//Get the native file system's string to pass to xerces
		string nativeDir = directory.c_str();

		//Get the file format in the native string for Xerces
		path nativeFileFormat(directory.c_str(), native);

		//Get the complete path to the file
		path completePath = complete(nativeFileFormat);

		for ( directory_iterator itr(completePath); itr != end_itr; ++itr )
		{
			if ( !is_directory( *itr ) && regex_match(string(itr->leaf()), what, rx1))
			{
				string fileLocation(nativeDir);
				fileLocation += "/" + itr->leaf();
				StringPimpl fileLocationPimpl(fileLocation.c_str());
				bool fileExists = false;
				for(unsigned int i = 0; i < files.size(); ++i)
				{
					fileLocationPimpl.transformIntoAbsoluteFilePath();
					if(fileLocationPimpl == files.at(i))
					{
						fileExists = true;
					}
				}

				if(!fileExists) 
				{
					addFile(fileLocationPimpl);
				}
			}
		}	
	}
	catch(filesystem_error &)
	{
		//ERROR, filesystem error
		throw IllegalArgumentExceptionImpl("File system error");
	}
	catch(bad_expression &)
	{
		//ERROR, bad expression
		throw IllegalArgumentExceptionImpl("Bad expression with the regular expression argument");
	}
	catch(runtime_error &)
	{
		//ERROR, Runtime error
		throw IllegalArgumentExceptionImpl("Run time error occured, more than likely with the regular expression");
	}
	catch(FileNotFoundException &)
	{
		//FileNotFoundException, you should not be here
		throw IllegalArgumentExceptionImpl("File not found exception occured.  You must have passed a bad directory in.");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
	                                                  const StringPimpl &userId, 
						                              const StringPimpl &botId,
						                              const StringPimpl &endUserId,
						                              const StringPimpl &regularExpression)
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	addDirectoryUnlessAlreadyAdded(directory, regularExpression);
}

void GraphBuilderAIML::addFileUnlessAlreadyAdded(const StringPimpl &file)
	throw(FileNotFoundException &, Exception &)
{
	StringPimpl userId = m_identificationManager->getUserId();
	StringPimpl botId = m_identificationManager->getBotId();
	vector<StringPimpl> files = m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@files_@");
	file.transformIntoAbsoluteFilePath();
	for(unsigned int i = 0; i < files.size(); ++i)
	{
		if(file == files.at(i))
		{
			return;
		}
	}

	//no files exist so lets add it
	addFile(file);
}

void GraphBuilderAIML::addFileUnlessAlreadyAdded(const StringPimpl &file,
	                                                 const StringPimpl &userId,
					                                 const StringPimpl &botId,
					                                 const StringPimpl &endUserId) 
	throw(FileNotFoundException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	addFileUnlessAlreadyAdded(file);
}


void GraphBuilderAIML::addString(const StringPimpl &stringContainingAIML)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl stringToInsert = m_aimlHeader + stringContainingAIML + m_aimlFooter;

		//See if a vector full with strings for this userId and BotId
		//can be found.  If it can't then create the vector and add it.
		//If it does exist, then add this string to it.
		m_databaseManager->addRecordWithCount(userId + "_@" + botId + "_@stringsNotGraphed_@", stringToInsert);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::removeString(const StringPimpl &stringContainingAIML)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl stringToInsert = m_aimlHeader + stringContainingAIML + m_aimlFooter;

		//See if a vector full with strings for this userId and BotId
		//can be found.  If it can't then create the vector and add it.
		//If it does exist, then add this string to it.
		m_databaseManager->addRecordWithCount(userId + "_@" + botId + "_@stringsGraphed_@", stringToInsert);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::removeString(const StringPimpl &stringContainingAIML,
								 const StringPimpl &userId,
								 const StringPimpl &botId,
								 const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	removeString(stringContainingAIML);
}


void GraphBuilderAIML::addString(const StringPimpl &stringContainingAIML,
								 const StringPimpl &userId,
								 const StringPimpl &botId,
								 const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	addString(stringContainingAIML);
}

void GraphBuilderAIML::setAddStringAIMLHeader(const StringPimpl &aimlHeader)
	throw(Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_aimlHeader = aimlHeader;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setAddStringAIMLFooter(const StringPimpl &aimlFooter)
	throw(Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_aimlFooter = aimlFooter;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}


StringPimpl GraphBuilderAIML::convertAndCheckXSD(const StringPimpl &schema)
//throw Exception, FileNotFoundException
{
  	    /*
		 * Convert it to the full file system path
		 * and code all the spaces to to '%20' since
		 * xerces expects to have all the xsd's with
		 * any spaces on the file system to really be
		 * '%20'. 
		 */
		string stringSchema = schema.c_str();
		path nativeDirFormat(stringSchema, native);
		path completePathSchema = complete(nativeDirFormat);
		if(exists(completePathSchema))
		{
			return replace_all_copy(completePathSchema.native_file_string(), " ", "%20").c_str();
		}
		else 
		{
			StringPimpl error = "File schema not found:" + schema;
			throw FileNotFoundExceptionImpl(error.c_str());
			return "";
		}
}

void GraphBuilderAIML::setAIMLSchema(const StringPimpl &schema)
	throw(Exception &, FileNotFoundException &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_aimlSchema = convertAndCheckXSD(schema);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

///@todo this needs to throw a FileNotFoundException
void GraphBuilderAIML::setCommonTypesSchema(const StringPimpl &schema)
	throw(Exception &, FileNotFoundException &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_commonTypesSchema = convertAndCheckXSD(schema);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

bool GraphBuilderAIML::isASentenceSplitter(char c)
{
	bool sentenceSplitterFound = false;

	//check this character to see if it is a sentence splitter
	for(unsigned int j = 0; j < m_sentenceSplitters.length(); ++j)
	{
		if(c == m_sentenceSplitters.at(j))
		{
			sentenceSplitterFound = true;
			break;
		}
	}

	return sentenceSplitterFound;
}

StringPimpl GraphBuilderAIML::handleResponse(const StringPimpl &userInput)
{
	deque<StringPimpl> sentences;
	deque<StringPimpl> sentencesWithPunctuation;
	StringPimpl response = m_NodeMapperRoot.getTemplateString(userInput);	
	StringPimpl responseCopy;
	StringPimpl returnSentence;
	bool spaceAdded = false;

	for(unsigned int i = 0; i < response.length(); ++i)
	{
		char c = response.at(i);

		//If we have more than one space or tabs it will be 
		//trimmed down to one space.
		if((c == ' ' || c == '\t') && !spaceAdded)
		{
			responseCopy.push_back(' ');
			spaceAdded = true;
			continue;
		}
		else
		{
			//We have encountered a non space character.
			//Allow spaces to be added again.
			spaceAdded = false;
		}
		
		//Get whether or not this character is a sentence
		//splitter.  If it is not a sentence splitter, add
		//the character.
		bool isASplitter = isASentenceSplitter(c);
		if(!isASplitter)
		{
			responseCopy.push_back(c);
		}
		else
		{
			//At this point, char c contains a single sentence splitter.
			//
			// char c = [::sentence splitter::]
			//
			//and responseCopy can have strings of the form:
			//
			//    [::space::]?[::textual::]+[::space::]?
			//
			//optional single space follwed by one or more nonspace (textuals)
			//follwed by another optional single space.
			//
			//or you can have strings of the following form:
			//
			//   [::space::]?
			//
			//optional single space.  Since this is optional, this means that 
			//responseCopy could be completely empty.
			
			//We might be adding empty strings, we might be adding just spaces
			//to the deque.  It's okay, since we have to keep the size of the
			//sentences the same size as the sentencesWithPuncutation.
			sentences.push_back(responseCopy);
			setThat(responseCopy);

			//We might be adding single characters, or just spaces follwed by
			//punctuation to the sentencesWithPunctuation.  It's okay, we have 
			//to add it for the user to be able to call upon it latter if they
			//really need it.
			responseCopy.push_back(c);
			sentencesWithPunctuation.push_back(responseCopy);
			
			//Add the responseCopy to the return string.  Note that at this point
			//returnSentence could contain any of the following strings of the
			//form:
			//
			//   ([::space::]?[::sentenceSplitter::])+
			//
            //Optional single space follwed by a sentence splitter
			//which can be repeated endlessly
            //
			//or 
			//
			//   [::space::]?([::textual::]+[::sentenceSplitter::])+
			//
			//Optional single space follwed by one or more nonspace words 
			//which each have only at most one space inbetween them followed
			//by a sentence splitter.  This can be repeated endlessly.
			returnSentence += responseCopy;

			//Clear responseCopy for the next pass.
			responseCopy.clear();
		}
	}


	//At this point responseCopy can contain the following:
	//
	//    [::null::]
	//
	//Empty string
	//
	//or 
	//
	//    [::space::]
	//
	//One single space
	//
	//or
	//
	//    [::space::]?([::textual::])+[::space::]?
	//
	//Optional single space follwed by one or more 
	//nonspace words which each have at most one space
	//inbetween them follwed by an optional space.
	//
	//or 
	//
    //   ([::space::]?[::sentenceSplitter::])+[::space::]?
    //
    //Optional single space follwed by a sentence splitter
	//which can be repeated endlessly follwed by an optional
	//single space
	//
	//or
	//
	//   [::space::]?([::textual::]+[::sentenceSplitter::])+[::space::]?
	//
	//Optional single space follwed by one or more nonspace words 
	//which each have at most one space inbetween them followed
	//by a sentence splitter.  This can be repeated endlessly.  At the
	//end of this we can have an optional space.

	//If our response is not empty, and it's not a single space push 
	//it onto both the sentencesWithPunctuation as well as sentences 
	//without punctuation.
	if(!responseCopy.empty() &&  
	   !(responseCopy.length() == 1 && responseCopy.at(0) == ' '))
	{
		sentences.push_back(responseCopy);
		setThat(responseCopy);
		sentencesWithPunctuation.push_back(responseCopy);
		
		//Add it to our return sentence.
		returnSentence += responseCopy;
	}
	
	//If we have multiple senteces add them
	if(sentences.size() > 0)
	{
		m_previousResponsesManager->addBotResponse(sentences);
	}
	
	//If we have multiple sentences with punctuation add them
	if(sentencesWithPunctuation.size() > 0)
	{
		m_previousResponsesManager->addBotResponseWithPunctuation(sentencesWithPunctuation);
	}
	
	//At this point our final string might have a single 
	//space at either left of the string or have a single
	//space at the right of the string. We'll trim it
	//and return the final product.
	returnSentence.transformByTrimmingWhiteSpace();
	return returnSentence;
}

StringPimpl GraphBuilderAIML::getResponseInternal(const StringPimpl &input, 
												  bool keepPreviousUserInput)
{

	StringPimpl inputSubstitution = inputSubstitute(input);
	StringPimpl userInput;
	StringPimpl returnSentence;

	//split up the inputs based on the sentence splitters
	for(unsigned int i = 0; i < inputSubstitution.length(); ++i)
	{
		char c = inputSubstitution.at(i);
		bool isASplitter = isASentenceSplitter(c);

		//No setence splitter 
		if(!isASplitter)
		{
			userInput.push_back(c);
		}
		else
		{
			if(keepPreviousUserInput && !userInput.empty())
			{
				deque<StringPimpl> sentences;
				sentences.push_back(userInput);
				m_previousResponsesManager->addUserResponse(sentences);
			}

			StringPimpl response = handleResponse(userInput);
			if(!response.empty())
			{
				if(!returnSentence.empty())
				{
					returnSentence += " ";
				}
				returnSentence += response;
			}
			userInput.clear();
		}
	}

	if(!userInput.empty())
	{
		if(keepPreviousUserInput)
		{
			deque<StringPimpl> sentences;
			sentences.push_back(userInput);
			m_previousResponsesManager->addUserResponse(sentences);
		}

		StringPimpl response = handleResponse(userInput);
		if(!returnSentence.empty())
		{
			returnSentence += " ";
		}
		returnSentence += response;
	}

	return returnSentence;
}

StringPimpl GraphBuilderAIML::getResponse(const StringPimpl &input)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl endUserId = m_identificationManager->getEndUserId();
		m_databaseManager->deleteRecordRange(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@previousSrai_@");
		return getResponseInternal(input);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getResponse(const StringPimpl &input, 
                                          const StringPimpl &userId, 
						                  const StringPimpl &botId,
								          const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getResponse(input);
}

void GraphBuilderAIML::setAIMLValidation(bool trueOrFalse)
	throw(Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_setAIMLValidation = trueOrFalse;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setThat(const StringPimpl &that)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl endUserId = m_identificationManager->getEndUserId();
		StringPimpl finalThat;
		for(unsigned int i = 0; i < that.length(); ++i)
		{
			char c = that.at(i);
			if(isASentenceSplitter(c))
			{
				//Store it as that.  It might be the last one
				//we encounter
				finalThat.transformByTrimmingWhiteSpace();
				finalThat.removePunctuation(m_sentenceSplitters);
				if(!finalThat.empty())
				{
					m_databaseManager->addRecord(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@that_@", finalThat);
				}
				finalThat.clear();
				continue;
			}
			else
			{
				finalThat.push_back(c);
			}
		}

		finalThat.transformByTrimmingWhiteSpace();
		finalThat.removePunctuation(m_sentenceSplitters);

		if(!finalThat.empty())
		{
			m_databaseManager->addRecord(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@that_@", finalThat);
		}
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setThat(const StringPimpl &that,
							   const StringPimpl &userId,
							   const StringPimpl &botId,
							   const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	setThat(that);
}

void GraphBuilderAIML::setTopic(const StringPimpl &topic)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl topicToStore(topic);
		topicToStore.removePunctuation(m_sentenceSplitters);
		if(topicToStore.empty())
		{
			setPredicate("TOPIC", "*");
		}
		else
		{
			setPredicate("TOPIC", topicToStore);
		}
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}

}

void GraphBuilderAIML::setTopic(const StringPimpl &topic,
								const StringPimpl &userId,
								const StringPimpl &botId,
								const StringPimpl &endUserId)

	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	setTopic(topic);
}

StringPimpl GraphBuilderAIML::getThat() const
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl endUserId = m_identificationManager->getEndUserId();
		return m_databaseManager->getRecord(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@that_@", true);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}

}

StringPimpl GraphBuilderAIML::getThat(const StringPimpl &userId,
									  const StringPimpl &botId,
								      const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getThat();
}

StringPimpl GraphBuilderAIML::getTopic() const
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return getPredicate("topic");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getTopic(const StringPimpl &userId,
									   const StringPimpl &botId,
								       const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getTopic();
}

StringPimpl GraphBuilderAIML::getThatStar(const unsigned int &index) const
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_starsManager->getThatStar(index);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getThatStar(const unsigned int &index, 
										  const StringPimpl &userId,
										  const StringPimpl &botId,
								          const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getThatStar(index);
}

StringPimpl GraphBuilderAIML::getTopicStar(const unsigned int &index) const
	throw(IllegalArgumentException &, Exception &)
{

	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_starsManager->getTopicStar(index);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getTopicStar(const unsigned int &index,
										   const StringPimpl &userId,
										   const StringPimpl &botId,
                                           const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getTopicStar(index);
}

void GraphBuilderAIML::setPredicate(const StringPimpl &name, 
									const StringPimpl &value)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		m_predicateManager->setPredicate(name, value);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setPredicate(const StringPimpl &name, 
									const StringPimpl &value,
									const StringPimpl &userId,
									const StringPimpl &botId,
                                    const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	setPredicate(name, value);
}

void GraphBuilderAIML::removePredicate(const StringPimpl &name)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		m_predicateManager->removePredicate(name);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::removePredicate(const StringPimpl &name, 
									   const StringPimpl &userId,
									   const StringPimpl &botId,
                                       const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	removePredicate(name);
}

void GraphBuilderAIML::removeBotPredicate(const StringPimpl &name)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		m_predicateManager->removeBotPredicate(name);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::removeBotPredicate(const StringPimpl &name, 
									      const StringPimpl &userId,
									      const StringPimpl &botId,
                                          const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	removeBotPredicate(name);
}


void GraphBuilderAIML::printEntireDatabase() const
	throw(Exception &)
{
	m_databaseManager->printEntireDB();
}

bool GraphBuilderAIML::predicateMatch(const StringPimpl &predicateName, 
	                                  const StringPimpl &aimlPattern) const
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl predicateValue = getPredicate(predicateName);
		if(!predicateValue.empty())
		{
			Template *templateToAdd = new Template;
			templateToAdd->addCharacters(predicateName);
			queue<StringPimpl> wordStack;
			StringPimpl stringCopy;

			wordStack.push("*");
			wordStack.push("<TOPIC>");
			wordStack.push("*");
			wordStack.push("<THAT>");

			for(unsigned int i = 0; i < aimlPattern.length(); ++i)
			{
				char c = aimlPattern.at(i);
				//If space push it onto the stack
				if(c == ' ')
				{
					stringCopy.transformByTrimmingWhiteSpace();
					if(!stringCopy.empty()) 
					{
						stringCopy.transformByTrimmingWhiteSpace();
						wordStack.push(stringCopy);
						stringCopy.clear();
					}
				}
				else
				{
					//Haven't found the full word yet.
					//Just add the character and keep going.
					//convert it to upper case
					stringCopy.push_back(toupper(c));
				}
			}
			stringCopy.transformByTrimmingWhiteSpace();
			if(!stringCopy.empty()) 
			{
				wordStack.push(stringCopy);
				stringCopy.clear();
			}

			//User id and Bot id 
			wordStack.push("<USERID>");
			wordStack.push(userId);
			wordStack.push("<BOTID>");
			wordStack.push(botId);

			NodeMapper predicateNodeMapper;
			predicateNodeMapper.add(templateToAdd, wordStack);
			StringPimpl s = predicateNodeMapper.getTemplateString(predicateValue, true);
			delete templateToAdd;
			if(!s.empty())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			//The predicate is either truly and empty string
			//or the predicate does not exist.  We check our 
			//aiml pattern and if that is also empty or just 
			//one or spaces we will return true
			if(aimlPattern.empty())
			{
				//empty predicate value return true
				return true;
			}
			else
			{
				//check if it is all spaces
				StringPimpl temp = aimlPattern;
				temp.transformByTrimmingExcessSpaces();
				if(temp == " ")
				{
					return true;
				}
				else
				{
					//Warning, returned empty string on the predicate Name. 
					//The name does not exist and the aimlvalue is not empty
					return false;
				}
			}
		}
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

bool GraphBuilderAIML::predicateMatch(const StringPimpl &predicateName, 
									  const StringPimpl &aimlPattern,
									  const StringPimpl &userId,
									  const StringPimpl &botId,
                                      const StringPimpl &endUserId) const
	throw(Exception &) 
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return predicateMatch(predicateName, aimlPattern);
}

StringPimpl GraphBuilderAIML::getPredicate(const StringPimpl &name) const
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_predicateManager->getPredicate(name);
	}
	catch(exception &e)
	{	
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getPredicate(const StringPimpl &name,
										   const StringPimpl &userId,
										   const StringPimpl &botId,
								           const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getPredicate(name);
}

void GraphBuilderAIML::createGraph()
	throw(XMLErrorException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		
		//Go through the files and graph each one in 
		//turn and then erase all the files from the 
		//map

		//First find the vector of files using the 
		//userId and BotId

		vector<StringPimpl> filesNotGraphed = m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@filesNotGraphed_@");
		for(unsigned int i = 0; i < filesNotGraphed.size(); ++i)
		{
			StringPimpl fileNotGraphed = filesNotGraphed.at(i);
			Transcode transcodedString(fileNotGraphed.c_str());
			LocalFileInputSource lfi(transcodedString.getXmlChar());
			makeGraph(lfi, fileNotGraphed);

			//See if the file exists in the currently addded files for this userId, botId.
			//If it does not exist then add it.
			m_databaseManager->addRecordWithCount(userId + "_@" + botId + "_@files_@", fileNotGraphed);
		}
		m_databaseManager->deleteRecordCount(userId + "_@" + botId + "_@filesNotGraphed_@");

		//Go through the AIML strings in memory 
		//and graph each one in turn and then 
		//erase all the strings from the 
		//map

		vector<StringPimpl> stringsNotGraphed = m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@stringsNotGraphed_@");
		for(unsigned int i = 0; i < stringsNotGraphed.size(); ++i)
		{
			StringPimpl stringNotGraphed = stringsNotGraphed.at(i);
			MemBufInputSource mis((const XMLByte*)stringNotGraphed.c_str(), 
				                   stringNotGraphed.size(), 
								   "AIML String", 
								   false);
			makeGraph(mis, "AIML String");

			//See if the file exists in the currently addded files for this userId, botId.
			//If it does not exist then add it.
			m_databaseManager->addRecordWithCount(userId + "_@" + botId + "_@strings_@", stringNotGraphed);
		}
		m_databaseManager->deleteRecordCount(userId + "_@" + botId + "_@stringsNotGraphed_@");

	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}

}

void GraphBuilderAIML::createGraph(const StringPimpl &userId, 
								   const StringPimpl &botId,
                                   const StringPimpl &endUserId)
	throw(XMLErrorException &, Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	createGraph();
}

void GraphBuilderAIML::makeGraph(const InputSource &source, 
								 const StringPimpl &file,
								 bool removal)
//	throw(XMLErrorException &, Exception &)
{
	try 
	{
		if(removal)
		{
			if(m_AIMLRemoveDocumentHandler.get() == 0)
			{
				m_AIMLRemoveDocumentHandler.reset(new RemoveGraphHandler(m_NodeMapperRoot));
			}
			m_xmlManager->setDocumentHandler(m_AIMLRemoveDocumentHandler.get());
		}
		else
		{
			if(m_AIMLDocumentHandler.get() == 0)
			{
				m_AIMLDocumentHandler.reset(new GraphHandler(m_NodeMapperRoot));
			}
			m_xmlManager->setDocumentHandler(m_AIMLDocumentHandler.get());
		}

		//set the error handler for both the same way.
		if(m_AIMLErrorHandler.get() == 0)
		{
			m_AIMLErrorHandler.reset(new GraphHandlerError);
		}
		m_xmlManager->setErrorHandler(m_AIMLErrorHandler.get());

		if(m_setAIMLValidation && (!m_aimlSchema.empty()))
		{
			StringPimpl schemaLoc = "http://alicebot.org/2001/AIML-1.0.1 " + m_aimlSchema;
			m_xmlManager->setDoSchema(true);
			m_xmlManager->setDoValidation(true);
			m_xmlManager->setDoNamespaces(true);
			m_xmlManager->setExternalSchemaLocation(schemaLoc);
		}
		else
		{
			m_xmlManager->setDoSchema(false);
			m_xmlManager->setDoValidation(false);
			m_xmlManager->setDoNamespaces(false);
		}
		
		//Beginging parsing of file
		m_callBacks->filePreLoad(file, m_identificationManager->getUserId(), 
			m_identificationManager->getBotId(), m_identificationManager->getEndUserId());
		m_xmlManager->setFileBeingParsed(file);
		m_xmlManager->parse(source);
		
		//done parsing file
		m_callBacks->filePostLoad(file, m_identificationManager->getUserId(), 
			m_identificationManager->getBotId(), m_identificationManager->getEndUserId());
	}
	catch (const XMLException& toCatch) 
	{
		Transcode message(toCatch.getMessage());
		//XML Exception from within the parser
		throw XMLErrorExceptionImpl(("XML Exception from within the parser:" + message.getString()).c_str());
	}
	catch (const SAXParseException& toCatch) 
	{
		Transcode message(toCatch.getMessage());
		//XML Exception from within the parser
		throw XMLErrorExceptionImpl(("XML Exception from within the parser:" + message.getString()).c_str());
	}

}

void GraphBuilderAIML::initializeXerces()
//	throw(XMLException &, Exception &)
{
	XMLPlatformUtils::Initialize();
}

StringPimpl GraphBuilderAIML::getStar(unsigned const int &index) const
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_starsManager->getDefaultStar(index);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getStar(unsigned const int &index, 
									  const StringPimpl &userId, 
									  const StringPimpl &botId,
                                      const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getStar(index);
}

GraphBuilderAIML::~GraphBuilderAIML()
{
	typedef map<StringPimpl, CustomTagWithDelete>::iterator I;

	for(I it = m_customTags.begin(); it != m_customTags.end(); ++it)
	{
		/* 
		 * Use the custom tag to delete its self
		 */
		CustomTagWithDelete &tag = it->second;
		(tag.m_deleteFunc)(tag.m_customTags);
		
		///@todo figure out why this can't be free'd.
		///@todo This can't be freed because of a dependency
		//There's a dep where GraphBuilderAIML has a shared_ptr
		//to the guts of the dll.  
		//FreeLibrary(tag.m_dllHandle);
	}
}

StringPimpl GraphBuilderAIML::getPreviousBotResponse(const unsigned int &previousBotResponse, 
	                                       const unsigned int &sentence) const
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_previousResponsesManager->getPreviousBotResponse(previousBotResponse, sentence);	
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getPreviousBotResponse(const unsigned int &previousBotResponse, 
													 const unsigned int &sentence,
													 const StringPimpl &userId,
													 const StringPimpl &botId,
                                                     const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getPreviousBotResponse(previousBotResponse, sentence);
}

StringPimpl GraphBuilderAIML::getPreviousBotResponsePunctuation(const unsigned int &previousBotResponse, 
																const unsigned int &sentence) const
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_previousResponsesManager->getPreviousBotResponseWithPunctuation(previousBotResponse, sentence);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getPreviousBotResponsePunctuation(const unsigned int &previousBotResponse, 
																const unsigned int &sentence,
																const StringPimpl &userId,
																const StringPimpl &botId,
																const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getPreviousBotResponsePunctuation(previousBotResponse, sentence);
}


StringPimpl GraphBuilderAIML::getPreviousUserInput(const unsigned int &previousUserInput, const unsigned int &sentence) const
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_previousResponsesManager->getPreviousUserInput(previousUserInput, sentence);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getPreviousUserInput(const unsigned int &previousUserInput, 
	                                               const unsigned int &sentence,
										           const StringPimpl &userId,
										           const StringPimpl &botId,
										           const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);		
	return getPreviousUserInput(previousUserInput, sentence);
}


StringPimpl GraphBuilderAIML::getBotPredicate(const StringPimpl &name) const
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		return m_predicateManager->getBotPredicate(name);
	}
	catch(exception &e)
	{	
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getBotPredicate(const StringPimpl &name,
											  const StringPimpl &userId,
											  const StringPimpl &botId,
											  const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getBotPredicate(name);
}

void GraphBuilderAIML::setBotPredicate(const StringPimpl &name, 
									   const StringPimpl &value)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		m_predicateManager->setBotPredicate(name, value);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setBotPredicate(const StringPimpl &name, 
									   const StringPimpl &value,
									   const StringPimpl &userId,
									   const StringPimpl &botId,
									   const StringPimpl &endUserId)
	throw(Exception &)
{
	setUserIdBotIdEndUserId(userId, botId, endUserId);
	setBotPredicate(name, value);
}

void GraphBuilderAIML::setBotConfigurationSchema(const StringPimpl &schema)
	throw(Exception &, FileNotFoundException &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_configurationSchema = convertAndCheckXSD(schema);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setBotConfigurationValidation(const bool trueOrFalse)
	throw(Exception &)
{	
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_doConfigurationValidation = trueOrFalse;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}

}

void GraphBuilderAIML::parseSubstitutionFile(const StringPimpl &fileName)
	throw(XMLErrorException &, FileNotFoundException &, Exception &)
{

	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		parseConfigurationFile(fileName);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setInputSubstitution(const StringPimpl &find, const StringPimpl &replace)
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_inputSubstitutions.push_back(SubstitutionRegEx(regex(find.c_str(), boost::regex::icase), replace.c_str()));
	}
	catch(bad_expression &)
	{		
		throw IllegalArgumentExceptionImpl("Bad expression in the find regular expression");
	}
	catch(runtime_error &)
	{		
		throw IllegalArgumentExceptionImpl("Run time error in the find regular expression");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::inputSubstitute(const StringPimpl &input)
//	throw(Exception &)
{
	///@make this part of the user's bot
	typedef vector<SubstitutionRegEx>::const_iterator CI;
	string returnResponse(input.c_str());

	for(CI it = m_inputSubstitutions.begin(); it != m_inputSubstitutions.end(); ++it)
	{
		replace_all_regex(returnResponse, (*it).m_find, (*it).m_replace);
	}

	return returnResponse.c_str();
}

void GraphBuilderAIML::setGenderSubstitution(const StringPimpl &find, const StringPimpl &replace)
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_genderSubstitutions.push_back(SubstitutionRegEx(regex(find.c_str(), boost::regex::icase), replace.c_str()));
	}
	catch(bad_expression &)
	{
		throw IllegalArgumentExceptionImpl("Bad expression in the find regular expression");
	}
	catch(runtime_error &)
	{
		throw IllegalArgumentExceptionImpl("Run time error in the find regular expression");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl *GraphBuilderAIML::getPredicates(unsigned int &size) const
	throw(Exception &)
{
	return m_predicateManager->getPredicates(size);
}

StringPimpl *GraphBuilderAIML::getBotPredicates(unsigned int &size) const
	throw(Exception &)
{
	return m_predicateManager->getBotPredicates(size);
}

StringPimpl *GraphBuilderAIML::getPredicates(const StringPimpl &userId, 
											 const StringPimpl &botId,
											 const StringPimpl &endUserId, 
											 unsigned int &size) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getPredicates(size);
}

StringPimpl *GraphBuilderAIML::getBotPredicates(const StringPimpl &userId, 
											    const StringPimpl &botId,
											    const StringPimpl &endUserId,
												unsigned int &size) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getBotPredicates(size);
}

unsigned int GraphBuilderAIML::getPredicatesSize(const StringPimpl &userId, 
	                                             const StringPimpl &botId, 
							                     const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getPredicatesSize();
}

unsigned int GraphBuilderAIML::getBotPredicatesSize(const StringPimpl &userId, 
	                                                const StringPimpl &botId, 
								                    const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getBotPredicatesSize();
}

unsigned int GraphBuilderAIML::getPredicatesSize() const
	throw(Exception &)
{
	return m_predicateManager->getPredicatesSize();
}

unsigned int GraphBuilderAIML::getBotPredicatesSize() const
	throw(Exception &)
{
	return m_predicateManager->getBotPredicatesSize();
}


StringPimpl *GraphBuilderAIML::getUserIds(unsigned int &size) const
	throw(Exception &)
{
	return m_databaseManager->getRecordCountList("userIds_@", size);
}

unsigned int GraphBuilderAIML::getUserIdsSize() const
	throw(Exception &)
{
	return m_databaseManager->getRecordTotalCount("userIds_@");
}

StringPimpl *GraphBuilderAIML::getBotIds(const StringPimpl &userId, 
	                                     unsigned int &size) const
	throw(Exception &)
{
	return m_databaseManager->getRecordCountList("userIds_@" + 
		                                         userId + 
												 "_@botIds_@", size);
}

unsigned int GraphBuilderAIML::getBotIdsSize(const StringPimpl &userId) const
	throw(Exception &)
{
	return m_databaseManager->getRecordTotalCount("userIds_@" + 
		                                          userId + 
												  "_@botIds_@");
}

StringPimpl *GraphBuilderAIML::getEndUserIds(const StringPimpl &userId, 
	                                         const StringPimpl &botId,
	                                         unsigned int &size) const
	throw(Exception &)
{
	return m_databaseManager->getRecordCountList("userIds_@" + 
												  userId +
												  "_@botIds_@" + 
												  botId +
												 "_@endUserIds_@", size);
}

unsigned int GraphBuilderAIML::getEndUserIdsSize(const StringPimpl &userId,
	                                             const StringPimpl &botId) const
	throw(Exception &)
{
	return m_databaseManager->getRecordTotalCount("userIds_@" + 
												  userId +
												  "_@botIds_@" + 
												  botId +
												  "_@endUserIds_@");
}

void GraphBuilderAIML::setPersonSubstitution(const StringPimpl &find, const StringPimpl &replace)
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_personSubstitutions.push_back(SubstitutionRegEx(regex(find.c_str(), boost::regex::icase), replace.c_str()));
	}
	catch(bad_expression &)
	{
		throw IllegalArgumentExceptionImpl("Bad expression in the find regular expression");
	}
	catch(runtime_error &)
	{
		throw IllegalArgumentExceptionImpl("Run time error in the find regular expression");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setPerson2Substitution(const StringPimpl &find, const StringPimpl &replace)
	throw(IllegalArgumentException &, Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_person2Substitutions.push_back(SubstitutionRegEx(regex(find.c_str(), boost::regex::icase), replace.c_str()));
	}
	catch(bad_expression &)
	{
		throw IllegalArgumentExceptionImpl("Bad expression in the find regular expression");
	}
	catch(runtime_error &)
	{
		throw IllegalArgumentExceptionImpl("Run time error in the find regular expression");
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::genderSubstitute(const StringPimpl &input) const
	throw(Exception &)
{
	try
	{
		return substitute(input, m_genderSubstitutions);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::personSubstitute(const StringPimpl &input) const
	throw(Exception &)
{
	try
	{
		return substitute(input, m_personSubstitutions);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::person2Substitute(const StringPimpl &input) const
	throw(Exception &)
{
	try
	{
		return substitute(input, m_person2Substitutions);
	} 
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::substitute(const StringPimpl &input, const std::vector<SubstitutionRegEx> &substitution) const
//	throw(Exception &)
{
	string inputString(input.c_str());
	map<int, pair<string, string> > mapIntegerMapStringString;
    typedef find_iterator<string::iterator> string_find_iterator;
	typedef vector<SubstitutionRegEx>::const_iterator CI;

	try
	{
		for(CI it = substitution.begin(); it != substitution.end(); ++it)
		{
			for(string_find_iterator ij=
				make_find_iterator(inputString, regex_finder(it->m_find));
				ij!=string_find_iterator();
				++ij)
			{
			   /*
				* Get the index of where the iterator is 
				* at in the string
				*/
				string::difference_type stringIndex;
				stringIndex = distance(inputString.begin(), ij->begin()); 
				
               /*
				* Store the string to be replaced
				* along with the string that will
				* be replacing it.  Store as the key
				* the actual placement of where the 
				* string to be replaced is located at.
				* This way we can iterate over the
				* string and replace the strings in
				* order.
				*
				* Only insert into the map if it already does 
				* not have a replacement for that exact part of 
				* the string.  This gives the replacements at the 
				* begining of the substitutions higher precedence 
				* then any that are lower.
				*/
				if(mapIntegerMapStringString.find(stringIndex) == mapIntegerMapStringString.end())
				{
					stringstream ss;
					ss << *ij;
					mapIntegerMapStringString[stringIndex] = 
						pair<string, string>(ss.str(), it->m_replace);
				}
			}
		}

		typedef map<int, pair<string, string> >::const_iterator CIM;

		/*
		* Iterate over the string in order and replace the strings
		* in order.  Keep track using "diff" how much extra room 
		* to make or to subtract from the string as we replace the
		* olds substrings with our new strings.
		*/
		int diff = 0;
		int stringIndex = 0;
		for(CIM it = mapIntegerMapStringString.begin(); it != mapIntegerMapStringString.end(); ++it)
		{
			int positionInTheString = it->first;

			/*
			 * Check if the replacement string overrlaps with the 
			 * current replacement.  If it does then continue, 
			 * otherwise we'd be stepping on the toes of the previous
			 * replacement.
			 */
			if(positionInTheString < stringIndex)
			{
				continue;
			}

			pair<string, string> wordToReplaceAndBeReplaced = it->second;
			string wordToReplaceWith(wordToReplaceAndBeReplaced.second);
			int sizeOfWordToReplace = wordToReplaceAndBeReplaced.first.size();
			int diffBeforeReplacing = inputString.size();
			inputString.replace(positionInTheString + diff, sizeOfWordToReplace, wordToReplaceWith);
			diff += inputString.size() - diffBeforeReplacing;
			stringIndex = positionInTheString + wordToReplaceWith.size();
		}
		
		//Word all finished replacing and returning
		return inputString.c_str();
	}
	catch(bad_expression &)
	{
		throw ExceptionImpl("Bad expression with regular expression in GraphBuilderAIML::substitute");
	}
	catch(runtime_error &)
	{
		throw ExceptionImpl("RunTime error with regular expression in GraphBuilderAIML::substitute");
	}
}

void GraphBuilderAIML::parseConfigurationFile(const StringPimpl &fileName)
//	throw(XMLErrorException &, FileNotFoundException &, Exception &)
{
	if(!fileName.existsAsAFile())
	{
		//Throw an exception that the file does not exist
		StringPimpl fileNotFoundMsg = "File:" + fileName + " was not found";
		throw FileNotFoundExceptionImpl(fileNotFoundMsg.c_str());
	}

	try 
	{
		if(m_configurationDocumentHandler.get() == 0)
		{
			m_configurationDocumentHandler.reset(new ConfigurationHandler);
		}

		m_xmlManager->setDocumentHandler(m_configurationDocumentHandler.get());

		if(m_configurationErrorHandler.get() == 0)
		{
			m_configurationErrorHandler.reset(new ConfigurationHandlerError);
		}
		m_xmlManager->setErrorHandler(m_configurationErrorHandler.get());

		if(m_doConfigurationValidation && (!m_configurationSchema.empty()) && !(m_commonTypesSchema.empty()))
		{
			StringPimpl schemaLoc = "http://aitools.org/programd/4.5 ";
			schemaLoc += m_commonTypesSchema;
			schemaLoc += " http://aitools.org/programd/4.5/bot-configuration ";
			schemaLoc += m_configurationSchema;

			m_xmlManager->setDoSchema(true);
			m_xmlManager->setDoValidation(true);
			m_xmlManager->setDoNamespaces(true);
			m_xmlManager->setExternalSchemaLocation(schemaLoc);
		}
		else
		{
			m_xmlManager->setDoSchema(false);
			m_xmlManager->setDoValidation(false);
			m_xmlManager->setDoNamespaces(false);
		}

		StringPimpl fileNameTemp(fileName);
		fileNameTemp.transformIntoAbsoluteFilePath();
		m_xmlManager->parse(fileNameTemp);
	}
	catch (const XMLException& toCatch) 
	{
		Transcode message(toCatch.getMessage());
		throw ExceptionImpl(("XMLException: " + message.getString()).c_str());
	}
	catch (const SAXParseException& toCatch) 
	{
		Transcode message(toCatch.getMessage());
		throw ExceptionImpl(("SAXParseException: " + message.getString()).c_str());
	}
}

void GraphBuilderAIML::parsePropertiesFile(const StringPimpl &fileName)
	throw(XMLErrorException &, FileNotFoundException &, Exception &)
{
	try
	{
		parseConfigurationFile(fileName);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::parsePropertiesFile(const StringPimpl &fileName,
										   const StringPimpl &userId,
										   const StringPimpl &botId,
										   const StringPimpl &endUserId)
	throw(XMLErrorException &, FileNotFoundException &, Exception &)
{
	try
	{
		setUserIdBotIdEndUserId(userId, botId, endUserId);
		parseConfigurationFile(fileName);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::parseSentenceSplitterFile(const StringPimpl &fileName)
	throw(XMLErrorException &, FileNotFoundException &, Exception &)
{
	try
	{
		parseConfigurationFile(fileName);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setSentenceSplitter(const StringPimpl &splitter)
	throw(Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_sentenceSplitters += splitter;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}


int GraphBuilderAIML::getSize() const
	throw(Exception &)
{
	try
	{
		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl size = m_databaseManager->getRecord(m_databaseManager->m_reserved + 
			userId + "_@" + botId + "_@categorySize", true);

		if(!size.empty()) 
		{
			return size.getInteger();
		}
		else
		{
			return 0;
		}
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}

}

int GraphBuilderAIML::getSize(const StringPimpl &userId,
							  const StringPimpl &botId,
							  const StringPimpl &endUserId) const
	throw(Exception &)
{
	const_cast<GraphBuilderAIML *>(this)->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return getSize();
}

void GraphBuilderAIML::setSize(const unsigned int newSize)
//	throw(Exception &)
{
	StringPimpl userId = m_identificationManager->getUserId();
	StringPimpl botId = m_identificationManager->getBotId();
	m_databaseManager->addRecord(m_databaseManager->m_reserved + 
		                         userId + "_@" + botId + "_@categorySize", StringPimpl::getString(newSize));
}

void GraphBuilderAIML::setThreadSpecificIds(bool trueOrFalse)
	throw(Exception &)

{
	m_identificationManager->setThreadSpecific(trueOrFalse);
}

StringPimpl GraphBuilderAIML::getVersion() const
	throw(Exception &)
{
	try
	{
		return "1.1tp3";
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setCallBacks(CallBacks *callBacks)
	throw(Exception &)
{
	try
	{
		recursive_mutex::scoped_lock synchronized(m_this);
		m_callBacks = callBacks;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::storeGossip(const StringPimpl &gossip)
	throw(Exception &)
{
	try
	{
		m_callBacks->storeGossip(gossip, m_identificationManager->getUserId(), 
			m_identificationManager->getBotId(), m_identificationManager->getEndUserId());
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

CallBacks &GraphBuilderAIML::getCallBacks()
	throw(Exception &)
{
	try
	{
		return *m_callBacks;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::getId() const
	throw(Exception &)
{
	try
	{
		return m_identificationManager->getUserId();
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::synchronizeDatabase() const
	throw(Exception &)
{
	try
	{
		m_databaseManager->sync();
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void GraphBuilderAIML::setUserIdBotIdEndUserId(const StringPimpl &userId, 
	                                           const StringPimpl &botId,
									           const StringPimpl &endUserId)
	throw(Exception &)
{
	try
	{
		//ScopedTransaction transaction(m_databaseManager);
		m_databaseManager->addRecordWithCount("userIds_@", userId);
		m_databaseManager->addRecordWithCount("userIds_@" + 
											  userId +
											  "_@botIds_@", botId);
		m_databaseManager->addRecordWithCount("userIds_@" + 
											  userId +
											  "_@botIds_@" + 
											  botId +
											  "_@endUserIds_@", endUserId);
        m_identificationManager->setUserIdBotIdEndUserId(userId, botId, endUserId);

		if(getPredicate("topic").empty()) 
		{
			//If the topic is empty then
			//topic and that must not have
			//been initialized for this user
			//so we will hav to do it.

			//Set that and topic to default "*"
			setThat("*");
			setTopic("*");
		}
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::checkedInfiniteLoopGetResponse(const StringPimpl &userInput, 
			                                                 bool keepPreviousUserInput)
			throw(RecursionException &, Exception &)
{
	try
	{
		//We have to reset the That back to "*".  If we 
		//don't reset it to "*" then we can run into an infinite 
		//recursion issue.
		setThat("*");

		StringPimpl userId = m_identificationManager->getUserId();
		StringPimpl botId = m_identificationManager->getBotId();
		StringPimpl endUserId = m_identificationManager->getEndUserId();

		int previousSraiSize = 0;
		StringPimpl previousSraiSizeString = m_databaseManager->getRecord(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@previousSraiSize_@", true);
		if(!previousSraiSizeString.empty())
		{
			previousSraiSize = previousSraiSizeString.getInteger(); 
		}

		StringPimpl iString;
		for(int i = 1; i <= previousSraiSize; ++i)
		{
			iString = StringPimpl::getString(i);
			StringPimpl previousSrai = m_databaseManager->getRecord(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@previousSrai_@" + iString, true);
			if(userInput == previousSrai)
			{
				throw RecursionExceptionImpl("Infinite Recursion detected");
			}
		}
		previousSraiSize++;
		iString = StringPimpl::getString(previousSraiSize);
		
		m_databaseManager->addRecord(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@previousSrai_@" + iString, userInput);
		m_databaseManager->addRecord(m_databaseManager->m_reserved + userId + "_@" + botId + "_@" + endUserId + "_@previousSraiSize_@", iString);

		/*
		 * Save the stars and then restore them
		 * after the call.  The reason is that 
		 * this can be called recursively through
		 * srai and we want to restore the stars 
		 * after each of those calls.
		 */

		///@todo instead, see if we can just copy the vector.  
		//It'll be quicker than the *entire map of a map*  This is potentially expensive.
		///@todo just have map<string1 + string2 + ....>, vector>
		
		///@todo fix this
		map<StringPimpl, vector<StringPimpl> > m_tempStar = m_starsManager->getDefaultStarMap();
		map<StringPimpl, vector<StringPimpl> > m_tempThatStar = m_starsManager->getThatStarMap();
		map<StringPimpl, vector<StringPimpl> > m_tempTopicStar = m_starsManager->getTopicStarMap();
		StringPimpl response = getResponseInternal(userInput, 
			                                       keepPreviousUserInput);
		
		/*
		 * Now restore the stars to before us 
		 * calling getrepsonse.
		 */
		m_starsManager->setDefaultStarMap(m_tempStar);
		m_starsManager->setThatStarMap(m_tempThatStar);
		m_starsManager->setTopicStarMap(m_tempTopicStar);
		return response;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl GraphBuilderAIML::checkedInfiniteLoopGetResponse(const StringPimpl &userInput, 
															 const StringPimpl &userId,
															 const StringPimpl &botId,
															 const StringPimpl &endUserId,
															 bool keepPreviousUserInput)
	throw(RecursionException &, Exception &)
{
    m_identificationManager->setUserIdBotIdEndUserId(userId, botId, endUserId);
	return checkedInfiniteLoopGetResponse(userInput, keepPreviousUserInput);
}

void GraphBuilderAIML::removeCustomTagLibrary(const StringPimpl &library)
	throw(FileNotFoundException &, Exception &)
{
	recursive_mutex::scoped_lock synchronized(m_this);
	typedef map<StringPimpl, CustomTagWithDelete>::iterator I;
	I it = m_customTags.find(library);

	if(it != m_customTags.end())
	{
		CustomTagWithDelete &tag = it->second;
		(tag.m_deleteFunc)(tag.m_customTags);

		///@todo fix this, cannot remove the lib right now.
		//There's a dep on the GraphBuilder shared_ptr to 
		//the dll
		//FreeLibrary(tag.m_dllHandle);

		m_customTags.erase(library);
	}
	else
	{
		StringPimpl msg("Cannot find library to remove:" + library);
		throw ExceptionImpl(msg.c_str());
	}
}

void GraphBuilderAIML::setDBEnvironmentDirectory(const StringPimpl &directory)
	throw(Exception &)
{
	recursive_mutex::scoped_lock synchronized(m_this);
	m_dbEnvironmentDirectory = directory;
}

void GraphBuilderAIML::removeEndUser(const StringPimpl &userId,
	                                 const StringPimpl &botId,
						             const StringPimpl &endUserId)
	throw(Exception &)
{
	//remove the end user data
	this->m_databaseManager->deleteRecordRange(m_databaseManager->m_reserved + 
		                                       userId + "_@" + 
											   botId + "_@" + 
											   endUserId);

	//remove the end user id from the list
	m_databaseManager->deleteRecordWithCount("userIds_@" + 
										     userId +
										     "_@botIds_@" + 
										     botId +
										     "_@endUserIds_@", endUserId);
}

void GraphBuilderAIML::removeBot(const StringPimpl &userId,
	                             const StringPimpl &botId)
	throw(Exception &)
{
	vector<StringPimpl> fileList = 
		m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@files_@");

	vector<StringPimpl> stringList = 
		m_databaseManager->getRecordCountListAsVector(userId + "_@" + botId + "_@strings_@");

	for(unsigned int i = 0; i < fileList.size(); ++i)
	{
		try 
		{
			removeFile(fileList.at(i), userId, botId, "default");
		}
		catch(FileNotFoundException &)
		{
			//might be a file not found but we'll continue trying to remove files
		}
	}
	for(unsigned int i = 0; i < stringList.size(); ++i)
	{
		try 
		{
			removeFile(stringList.at(i), userId, botId, "default");
		}
		catch(FileNotFoundException &)
		{
			//might be a file not found but we'll continue trying to remove files
		}

	}
	removeGraph();
	
	//remove bot data
	m_databaseManager->deleteRecordRange(m_databaseManager->m_reserved + 
		                                 userId + "_@" + 
										 botId + "_@");
	

	//remove all the end user ids
	vector<StringPimpl> endUserIds = m_databaseManager->getRecordCountListAsVector("userIds_@" + 
												                                   userId +
												                                   "_@botIds_@" + 
												                                   botId +
												                                   "_@endUserIds_@"); 
	//remove the end user id list its self
	m_databaseManager->deleteRecordCount("userIds_@" + 
										 userId +
										 "_@botIds_@" + 
										 botId +
										 "_@endUserIds_@");

	//remove the bot id from the id list
	m_databaseManager->deleteRecordWithCount("userIds_@" + 
		                                     userId + 
											 "_@botIds_@", botId);

	//This could cause the bot to be recreated 
	//if you are currently using that bot to destry its self
	//but the that and top must always be set
	setThat("*");
	setTopic("*");
}

void GraphBuilderAIML::removeUser(const StringPimpl &userId)
	throw(Exception &)
{

	vector<StringPimpl> botIds = m_databaseManager->getRecordCountListAsVector("userIds_@" + 
		                                                                       userId + 
												                               "_@botIds_@");
	for(unsigned int i = 0; i < botIds.size(); ++i)
	{
		vector<StringPimpl> fileList = 
			m_databaseManager->getRecordCountListAsVector(userId + "_@" + botIds.at(i) + "_@files_@");
		vector<StringPimpl> stringList = 
			m_databaseManager->getRecordCountListAsVector(userId + "_@" + botIds.at(i) + "_@strings_@");
		for(unsigned int j = 0; j < fileList.size(); ++j)
		{
			removeFile(fileList.at(j), userId, botIds.at(i), "default");
		}
		for(unsigned int j = 0; j < stringList.size(); ++j)
		{
			removeFile(fileList.at(j), userId, botIds.at(i), "default");
		}
		removeGraph();
		m_databaseManager->deleteRecordWithCount("userIds_@" + 
		                                         userId + 
											     "_@botIds_@", botIds.at(i));
	}

	//remove the user data
	m_databaseManager->deleteRecordRange(m_databaseManager->m_reserved + 
		                                 userId + "_@");

	for(unsigned int k = 0; k < botIds.size(); ++k)
	{
		//remove all the end user ids
		vector<StringPimpl> endUserIds = m_databaseManager->getRecordCountListAsVector("userIds_@" + 
																					   userId +
																					   "_@botIds_@" + 
																					   botIds.at(k) +
																					   "_@endUserIds_@");
		//remove the end user id list its self
		m_databaseManager->deleteRecordCount("userIds_@" + 
											 userId +
											 "_@botIds_@" + 
											 botIds.at(k) +
											 "_@endUserIds_@");

	}

		//remove the bot id from the id list
		m_databaseManager->deleteRecordCount("userIds_@" + 
											 userId + 
											 "_@botIds_@");

	//remove the user from the list of user ids
	m_databaseManager->deleteRecordWithCount("userIds_@", userId);

	//This could cause the user to be recreated 
	//if you are currently using that user to destroy its self
	//but the that and topic must always be set
	setThat("*");
	setTopic("*");
}

void GraphBuilderAIML::addCustomTagLibrary(const StringPimpl &library)
	throw(FileNotFoundException &, Exception &)
{
	recursive_mutex::scoped_lock synchronized(m_this);

#ifdef _WIN32
	HINSTANCE hinstLib; 
	EntryPointfuncPtr func;
	ExitPointfuncPtr deleteFunc;	
	BOOL fRunTimeLinkSuccess = FALSE; 
 
    // Get a handle to the DLL module. 
	StringPimpl lib(library);
	lib += ".dll";
    hinstLib = LoadLibrary(lib.c_str()); 
 
    // If the handle is valid, try to get the function address.
    if (hinstLib != NULL) 
    { 
        func = (EntryPointfuncPtr)GetProcAddress(hinstLib, "rebeccaAIMLLoadCustomTags"); 
        deleteFunc = (ExitPointfuncPtr)GetProcAddress(hinstLib, "rebeccaAIMLRemoveCustomTags"); 
		
		if(func == NULL)
		{
			throw ExceptionImpl("rebeccaAIMLLoadCustomTags C function not found in the library");
		}

		if(deleteFunc == NULL)
		{
			throw ExceptionImpl("rebeccaAIMLRemoveCustomTags C function not found in the library");
		}

        // The addresses are valid, call the function.
        fRunTimeLinkSuccess = TRUE;
		
		//Add the tag to the vector of custom tags
		CustomTagWithDelete tag;
		tag.m_customTags = (func) ();
		tag.m_deleteFunc = deleteFunc;
		tag.m_dllHandle = hinstLib;
		m_customTags[library] = tag;
		//m_customTags.push_back(tag); 
    }
   	else 
	{
		throw ExceptionImpl("The library is not a valid dll or shared object");
	}	
#else 
	
	//I am assuming Unix or Linux by default
	//if not windows
	void *handle;
	StringPimpl lib("lib");
    lib	+= library;
	lib += ".so";	
	handle = dlopen(lib.c_str(), RTLD_LAZY);
	EntryPointfuncPtr func;
	ExitPointfuncPtr deleteFunc;
	char * error;
	if(handle)
	{
		func = (EntryPointfuncPtr)dlsym(handle, "rebeccaAIMLLoadCustomTags");	
		error = dlerror();

		if(error != NULL)
		{
			throw ExceptionImpl("rebeccaAIMLLoadCustomTags C function not found in the library");
		}

		deleteFunc = (ExitPointfuncPtr)dlsym(handle, "rebeccaAIMLRemoveCustomTags");
		error = dlerror();

		if(error != NULL)
		{
			throw ExceptionImpl("rebeccaAIMLRemoveCustomTags C function not found in the library");
		}

		CustomTagWithDelete tag;
		tag.m_customTags = (func) ();
		tag.m_deleteFunc = deleteFunc;
		tag.m_dllHandle = handle;
		m_customTags[library] = tag;
	}
	else
	{
		throw ExceptionImpl("The library is not a valid dll or shared object");		
	}
	
#endif

}

GraphBuilderAIML *GraphBuilderAIML::getInstance()
	throw(InitializationException &, Exception &)
{
	return m_instance;
}


StringPimpl GraphBuilderAIML::callSystemCommand(const StringPimpl &command) const
	throw(Exception &)
{
	string commandString(command.c_str());
#ifdef _WIN32

	STARTUPINFO si;
	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;
	PROCESS_INFORMATION pi;
	HANDLE read_pipe, write_pipe;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	int fd, create;
	OSVERSIONINFO osv;
	osv.dwOSVersionInfoSize = sizeof(osv);
	
	GetVersionEx(&osv);

	if (osv.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{
		InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
		SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
		sa.lpSecurityDescriptor = &sd;
	}
	else
	{
		/* Pipe will use ACLs from default descriptor */
		sa.lpSecurityDescriptor = NULL;
	}

	/* Create a new pipe with system's default buffer size */
	if (!CreatePipe(&read_pipe, &write_pipe, &sa, 0))
	{
		//error 
		return StringPimpl();
	}
	
	GetStartupInfo(&si);

	/* Sets the standard output handle for the process to the
	   handle specified in hStdOutput */
	si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;

	si.hStdOutput = write_pipe;
	si.hStdError  = (HANDLE) _get_osfhandle (2);
	si.wShowWindow = SW_HIDE;
	string cmd("cmd.exe /c \"");
	cmd += commandString;
	cmd += "\"";
	char *commandLine = _strdup(cmd.c_str());
	create = CreateProcess(
		NULL,				// The full path of app to launch
		commandLine, // Command line parameters
		NULL,					// Default process security attributes
		NULL,					// Default thread security attributes
		TRUE,					// Inherit handles from the parent
		0,						// Normal priority
		NULL,					// Use the same environment as the parent
		NULL,					// Use app's directory as current
		&si,					// Startup Information
		&pi);					// Process information stored upon return

	if (!create)
	{
		//error
		return StringPimpl();
	}

	/* Associates a file descriptor with the stdout pipe */
	fd = _open_osfhandle((intptr_t)read_pipe, _O_BINARY);

	/* Close the handle that we're not going to use */
	CloseHandle(write_pipe);

	if (!fd)
	{
		//error
		return StringPimpl();
	}
	
	FILE *file = 0;

	/* Open the pipe stream using its file descriptor */
	file = _fdopen(fd, "r");

	if(!file)
	{
		//error
		return StringPimpl();
	}

	if (commandLine)
		free(commandLine);

	int pid = (int)pi.hProcess;
	char c = 0;
	string returnString;
	while (c != EOF)
	{
		c = (char)getc(file);
		
		if(isascii(c))
		{
			returnString += c;
		}
	}

	/* Close the pipe once it's not needed anymore */
	fclose(file);
	return returnString.c_str();

#else

	FILE *file;
	file = popen(commandString.c_str(), "r");
	char c = 0;
	string returnString;
	while (c != EOF)
	{
		c = (char)getc(file);

		if(isascii(c))
		{
			returnString += c;
		}
	}

	fclose(file);
	return returnString.c_str();
#endif

}

} //end of namespace impl
} //end of namespace rebecca
