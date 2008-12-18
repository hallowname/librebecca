#ifndef REBECCA_GRAPHBUILDER_H
#define REBECCA_GRAPHBUILDER_H

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


/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif

//Rebecca includes
#include <rebecca/exports.h>
#include <rebecca/StringPimpl.h>
#include <rebecca/CallBacks.h>
#include <rebecca/Exceptions.h>

namespace rebecca 
{
namespace impl 
{

/** 
 * This is the interface from which all 
 * AIML action operations will take place.
 * 
 * This class provides all the operations 
 * from loading the AIML tag data from files 
 * into the embedded database to querying 
 * the AIML data in the embedded database with 
 * user input to get back the response.
 *
 * Use AimlFacade or NetworkAimlFacade to 
 * create the concrete representation of this 
 * interface and for getting a handle to this 
 * interface.  ALWAYS let AimlFacade or 
 * NetworkAimlFacade manage the memory to 
 * this interface. Never try to 
 * delete this interface directly.
 *
 * How to use this interface:
 * 
 * Instantiate a AimlFacade object or 
 * NetworkAimlFacade.  Call 
 * AimlFacade::getGraphBuilder() or 
 * NetworkAimlFacade::getNetworkGraphBuilder() to 
 * get a reference to this interface.
 *
 * Optionally, at this point you can create 
 * an instance of a CallBacks subclass 
 * and call GraphBuilder::setCallBacks() with the 
 * address of your subclass.  GraphBuilder WILL NOT 
 * manage the memory of your CallBacks subclass.  
 * You are responsible for managing the memory of 
 * your subclass.  You can omit this step if you 
 * do not wish to log the AIML gossip tags and if 
 * you do not want informative or error handling 
 * routines during the load and runtime of 
 * RebeccaAIML.
 * 
 * Setup any xsd's for validation of AIML tags 
 * through GraphBuilder::setAIMLSchema().  
 * Activate validation by calling 
 * GraphBuilder::setAIMLValidation(). 
 * Optionally if you are sure that your AIML files 
 * are AIML XML compliant/correct you can omit this 
 * step.  However, if you do omit this step and have 
 * illegal AIML tags in your files, then the illegal AIML 
 * XML tags will cause RebeccaAIML to abort through an 
 * exception or crash altogether.  Or in C++ terms, the
 * behavior of RebeccaAIML is undefined.
 *
 * Setup any xsd's for validation of configuration 
 * files for Substitution, Sentence Splitters, and Bot 
 * properties.  Those methods would be
 * GraphBuilder::setCommonTypesSchema() and 
 * GraphBuilder::setBotConfigurationSchema().  The provided
 * xsd's that should be used are bot-configuration.xsd and 
 * common-types.xsd.  Activate both schema's through 
 * GraphBuilder::setBotConfigurationValidation().
 *
 * Parse RebeccaAIML configuration files through the methods 
 * GraphBuilder::parseSubstitutionFile(),
 * GraphBuilder::parsePropertiesFile(), 
 * and GraphBuilder::parseSentenceSplitterFile() 
 * with their respective XML files. Provided sample 
 * configuration files are bots.xml, properties.xml,
 * sentence-splitters.xml, and substitutions.xml.
 * Optionally, you can ommit this step or augment it 
 * by directly calling 
 * GraphBuilder::setSentenceSplitter(), 
 * GraphBuilder::setPersonSubstitution(),
 * GraphBuilder::setPerson2Substitution(),
 * GraphBuilder::setGenderSubstitution(),
 * GraphBuilder::setBotPredicate()
 * with the appropriate values.  
 * 
 * Call GraphBuilder::addFile() to add one file
 * at a time or call GraphBuilder::addDirectory() to
 * add an entire directory with AIML XML files.
 * Optionally, you can call 
 * GraphBuilder::addFileUnlessAlreadyAdded() or 
 * GraphBuilder::addDirectoryUnlessAlreadyAdded().  This 
 * will only add the files or directories if they 
 * haven't already been added to the embedded database.
 * This latter mechanism is preferred as it will cut 
 * down on unnesessarily adding files which have already 
 * been added to the embedded database bot brain.
 * Call GraphBuilder::createGraph() to begin the 
 * parsing of the AIML files which creates the 
 * embedded database structure. 
 * Call GraphBuilder::getResponse() to query the
 * AIML data structures with input to
 * get RebeccaAIML's bot response back.
 *
 * When your program exits, you will not have to 
 * re-add any of your files you previously have added 
 * as the embedded database has them stored.  It is a good
 * programming practice to use GraphBuilder::addFileUnlessAlreadyAdded() 
 * or GraphBuilder::addDirectoryUnlessAlreadyAdded() to avoid 
 * redundantly re-adding files and/or directories that have already 
 * been added.  If you want to remove a file or directory you can use 
 * GraphBuilder::removeFile() or GraphBuilder::removeDirectory()
 * to remove either a single file or an entire directory
 * with AIML XML files.  Call GraphBuilder::removeGraph() to begin 
 * the parsing of the AIML files to remove them from the embedded 
 * database.
 *
 * RebeccaAIML supports multi-user, multi-bot, and 
 * multi-endUser.  A user is a person or entity which 
 * creates 1 to many different bots.  A bot is a collection 
 * of AIML files and bot predicates that have been added to 
 * the embedded database for querying by end users.  A end 
 * user is someone who queries a user's bot for responses.  A end user 
 * has regular predicates that define certain aspects such as 
 * their name.  RebeccaAIML can have as many different users, 
 * bots, and end users as you would want.  They all share 
 * the same embedded database for all their activities concurrently.  
 * You either set your user, bot, and end user id through 
 * GraphBuilder::setUserIdBotIdEndUserId() or directly 
 * call each method tacking on the user id, bot id, and end 
 * user id as arguments.  Any time a method is called with a
 * new user id, bot id, or end user id which didn't previously 
 * exist, RebeccaAIML will create the user, bot, and/or end user
 * in the embedded database.  You can use GraphBuilder::removeUser(), 
 * GraphBuilder::removeBot(), and GraphBuilder::removeEndUser()
 * to remove any that you have added.  If you do not set the user id,
 * bot id, and end user id, RebeccaAIML will by default assign the 
 * string value of, "default" for all three.
 */
class REBECCA_EXPORT GraphBuilder
{
	public:

		/**
		 * Add one AIML file to the internal queue for 
		 * latter processing by GraphBuilder::createGraph().
		 *
		 * Since this will add the file regardless of whether 
		 * or not it has already been added to the embedded 
		 * database, consider using GraphBuilder::addFileUnlessAlreadyAdded()
		 * instead.
		 *
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 * 
		 * Since parsing and building the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database
		 * separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addFile("/someDir/someFile.aiml");
		   builder.addFile("../../someDir/someFile.aiml");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addFile("C:\\someDir\\someFile.aiml");
		   builder.addFile("C:/someDir/someFile.aiml");
		   builder.addFile("..\\..\\someDir\\someFile.aiml");
		   </pre>
		 * 
		 *
		 * @param file The AIML file to add to the internal 
		 * queue.
		 *
		 * @exception FileNotFoundException If the file is not found, 
		 * this method will throw a FileNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void addFile(const StringPimpl &file) 
			throw(FileNotFoundException &, Exception &) = 0;		

		/**
		 * Add one AIML file to the internal queue for 
		 * latter processing by GraphBuilder::createGraph().
		 *
		 * Since this will add the file regardless of whether 
		 * or not it has already been added to the embedded 
		 * database, consider using GraphBuilder::addFileUnlessAlreadyAdded()
		 * instead.
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * and/or GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 * 
		 * Since parsing and building the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addFile("/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.addFile("../../someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addFile("C:\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.addFile("C:/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.addFile("..\\..\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
		 * 
		 *
		 * @param file The AIML file to add to the internal 
		 * queue.
		 * 
		 * @param userId The id of the user you want to add a 
		 * file to.
		 * 
		 * @param botId The id of the bot this file belongs to.
		 *
		 * @param endUserId The id of the end user that is adding
		 * this file.
		 *
		 * @exception FileNotFoundException If the file is not found, 
		 * this method will throw a FileNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void addFile(const StringPimpl &file,
			                 const StringPimpl &userId,
							 const StringPimpl &botId,
							 const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &) = 0;		

		/**
		 * Add one AIML file to the internal queue for 
		 * latter processing by GraphBuilder::createGraph() unless
		 * the file as already been added to the embedded database.
		 * 
		 * This should be preferred over GraphBuilder::addFile() as it 
		 * will prevent you from re-adding your files needlessly to the 
		 * embedded database bot brain multiple times.  This is also a 
		 * convenient method to use at the initialization of your program 
		 * as it will guarantee that your file will be added to the 
		 * embedded database bot brain if it does not exist, but it will 
		 * not be re-added after your program is shut down and restarted 
		 * since it has already been added once.
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 * 
		 * Since parsing and building the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addFileUnlessAlreadyAdded("/someDir/someFile.aiml");
		   builder.addFileUnlessAlreadyAdded("../../someDir/someFile.aiml");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addFileUnlessAlreadyAdded("C:\\someDir\\someFile.aiml");
		   builder.addFileUnlessAlreadyAdded("C:/someDir/someFile.aiml");
		   builder.addFileUnlessAlreadyAdded("..\\..\\someDir\\someFile.aiml");
		   </pre>
		 * 
		 *
		 * @param file The AIML file to add to the internal 
		 * queue.
		 *
		 * @exception FileNotFoundException If the file is not found, 
		 * this method will throw a FileNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void addFileUnlessAlreadyAdded(const StringPimpl &file) 
			throw(FileNotFoundException &, Exception &) = 0;		

		/**
		 * Add one AIML file to the internal queue for 
		 * latter processing by GraphBuilder::createGraph() unless
		 * the file as already been added to the embedded database.
		 * 
		 * This should be preferred over GraphBuilder::addFile() as it 
		 * will prevent you from re-adding your files needlessly to the 
		 * embedded database bot brain multiple times.  This is also a 
		 * convenient method to use at the initialization of your program 
		 * as it will guarantee that your file will be added to the 
		 * embedded database bot brain if it does not exist, but it will 
		 * not be re-added after your program is shut down and restarted 
		 * since it has already been added once.
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 * 
		 * Since parsing and building the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addFileUnlessAlreadyAdded("/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.addFileUnlessAlreadyAdded("../../someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addFileUnlessAlreadyAdded("C:\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.addFileUnlessAlreadyAdded("C:/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.addFileUnlessAlreadyAdded("..\\..\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
		 * 
		 *
		 * @param file The AIML file to add to the internal 
		 * queue.
		 *
		 * @param userId The id of the user you want to add a 
		 * file to.
		 * 
		 * @param botId The id of the bot this file belongs to.
		 *
		 * @param endUserId The id of the end user that is adding
		 * this file.
		 *
		 * @exception FileNotFoundException If the file is not found, 
		 * this method will throw a FileNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void addFileUnlessAlreadyAdded(const StringPimpl &file,
			                                   const StringPimpl &userId,
							                   const StringPimpl &botId,
							                   const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &) = 0;		

		/**
		 * Add one AIML file to the internal queue for 
		 * latter processing by GraphBuilder::removeGraph().
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::removeFile() and/or GraphBuilder::removeDirectory()
		 * and/or GraphBuilder::removeString(),
		 * call GraphBuilder::removeGraph() to parse and remove
		 * the file(s) from the RebeccaAIML embedded database 
		 * structures.
		 * 
		 * Since parsing and removing from the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually removing from the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.removeFile("/someDir/someFile.aiml");
		   builder.removeFile("../../someDir/someFile.aiml");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.removeFile("C:\\someDir\\someFile.aiml");
		   builder.removeFile("C:/someDir/someFile.aiml");
		   builder.removeFile("..\\..\\someDir\\someFile.aiml");
		   </pre>
		 * 
		 *
		 * @param file The AIML file to add to the internal 
		 * queue for latter removal from the embedded database.
		 *
		 * @exception FileNotFoundException If the file is not found, 
		 * this method will throw a FileNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void removeFile(const StringPimpl &file) 
			throw(FileNotFoundException &, Exception &) = 0;		

		/**
		 * Add one AIML file to the internal queue for 
		 * latter processing by GraphBuilder::removeGraph().
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::removeFile() and/or GraphBuilder::removeDirectory()
		 * and/or GraphBuilder::removeString(),
		 * call GraphBuilder::removeGraph() to parse and remove
		 * the file(s) from the RebeccaAIML embedded database 
		 * structures.
		 * 
		 * Since parsing and removing from the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually removing from the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.removeFile("/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.removeFile("../../someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.removeFile("C:\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.removeFile("C:/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.removeFile("..\\..\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
		 * 
		 *
		 * @param file The AIML file to add to the internal 
		 * queue for latter removal from the embedded database.
		 *
		 * @param userId The id of the user you want to remove a 
		 * file to.
		 * 
		 * @param botId The id of the bot this file belongs to.
		 *
		 * @param endUserId The id of the end user that is removing
		 * this file.
		 *
		 * @exception FileNotFoundException If the file is not found, 
		 * this method will throw a FileNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void removeFile(const StringPimpl &file,
			                    const StringPimpl &userId,
							    const StringPimpl &botId,
							    const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &) = 0;		

		/**
		 * Add entire directory of AIML files to the internal 
		 * queue for latter processing by GraphBuilder::createGraph().
		 *
		 * Since this will add the directory of AIML files 
		 * regardless of whether or not they have already been 
		 * added to the embedded database, consider using 
		 * GraphBuilder::addDirectoryUnlessAlreadyAdded()
		 * instead.
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * and/or GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 *
		 * Since parsing and building the embedded database 
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
		 *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to only use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 *
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addDirectory("/someDir");
		   builder.addDirectory("../../someDir");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addDirectory("C:\\someDir");
		   builder.addDirectory("C:/someDir");
		   builder.addDirectory("..\\..\\someDir");
		   </pre>
		 * 
		 *
		 * @param directory The AIML directory to add to the internal 
		 * queue.
		 *
		 * @param regularExpression The regular expression which defines
		 * what a AIML file is within the directory. The default is all
		 * files which end in ".aiml".
		 *
		 * @exception IllegalArgumentException  If the regular expression is an 
		 * invalid regular expression
		 *
		 * @exception DirectoryNotFoundException If the directory is not found
		 *
		 * @exception Exception If an underlying method throws an exception, 
		 * it will be wrapped and thrown as a Exception
		 */
		virtual void addDirectory(const StringPimpl &directory, 
			                      const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &) = 0;

		/**
		 * Add entire directory of AIML files to the internal 
		 * queue for latter processing by GraphBuilder::createGraph().
		 *
		 * Since this will add the directory of AIML files 
		 * regardless of whether or not they have already been 
		 * added to the embedded database, consider using 
		 * GraphBuilder::addDirectoryUnlessAlreadyAdded()
		 * instead.
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * and/or GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 *
		 * Since parsing and building the embedded database
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
		 *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to only use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 *
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addDirectory("/someDir", "myUser", "myBot", "myEndUser");
		   builder.addDirectory("../../someDir", "myUser", "myBot", "myEndUser");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addDirectory("C:\\someDir", "myUser", "myBot", "myEndUser");
		   builder.addDirectory("C:/someDir", "myUser", "myBot", "myEndUser");
		   builder.addDirectory("..\\..\\someDir", "myUser", "myBot", "myEndUser");
		   </pre>
		 * 
		 *
		 * @param directory The AIML directory to add to the internal 
		 * queue.
		 *
		 * @param userId The id of the user you want to add a directory 
		 * to.
		 * 
		 * @param botId The id of the bot this directory of files 
		 * belongs to.
		 *
		 * @param endUserId The id of the end user that is adding this 
		 * list of files from this directory.
		 *
		 * @param regularExpression The regular expression which defines
		 * what a AIML file is within the directory. The default is all
		 * files which end in ".aiml".
		 *
		 * @exception IllegalArgumentException  If the regular expression is an 
		 * invalid regular expression
		 *
		 * @exception DirectoryNotFoundException If the directory is not found
		 *
		 * @exception Exception If an underlying method throws an exception, 
		 * it will be wrapped and thrown as a Exception
		 */
		virtual void addDirectory(const StringPimpl &directory, 
			                      const StringPimpl &userId, 
								  const StringPimpl &botId,
								  const StringPimpl &endUserId,
			                      const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &) = 0;

		/**
		 * Add entire directory of AIML files to the internal 
		 * queue for latter processing by GraphBuilder::createGraph().
		 *
		 * This should be preferred over GraphBuilder::addDirectory() as it 
		 * will prevent you from re-adding your directory of files 
		 * needlessly to the embedded database bot brain multiple times.  
		 * This is also a convenient method to use at the initialization 
		 * of your program as it will guarantee that your directory of files
		 * will be added to the embedded database bot brain if it does not exist, 
		 * but it will not be re-added those files after your program is shut 
		 * down and restarted since it has already been added once.
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * and/or GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 *
		 * Since parsing and building the embedded database
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
		 *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to only use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 *
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addDirectoryUnlessAlreadyAdded("/someDir");
		   builder.addDirectoryUnlessAlreadyAdded("../../someDir");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addDirectoryUnlessAlreadyAdded("C:\\someDir");
		   builder.addDirectoryUnlessAlreadyAdded("C:/someDir");
		   builder.addDirectoryUnlessAlreadyAdded("..\\..\\someDir");
		   </pre>
		 * 
		 *
		 * @param directory The AIML directory to add to the internal 
		 * queue.
		 *
		 * @param regularExpression The regular expression which defines
		 * what a AIML file is within the directory. The default is all
		 * files which end in ".aiml".
		 *
		 * @exception IllegalArgumentException  If the regular expression is an 
		 * invalid regular expression
		 *
		 * @exception DirectoryNotFoundException If the directory is not found
		 *
		 * @exception Exception If an underlying method throws an exception, 
		 * it will be wrapped and thrown as a Exception
		 */
		virtual void addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
			                                        const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &) = 0;

		/**
		 * Add entire directory of AIML files to the internal 
		 * queue for latter processing by GraphBuilder::createGraph().
		 *
		 * This should be preferred over GraphBuilder::addDirectory() as it 
		 * will prevent you from re-adding your directory of files 
		 * needlessly to the embedded database bot brain multiple times.  
		 * This is also a convenient method to use at the initialization 
		 * of your program as it will guarantee that your directory of files
		 * will be added to the embedded database bot brain if it does not exist, 
		 * but it will not be re-added those files after your program is shut 
		 * down and restarted since it has already been added once.
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * and/or GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
		 *
		 * Since parsing and building the embedded database
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * data structures in the embedded database 
		 * separate for convenience.
		 *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to only use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 *
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.addDirectoryUnlessAlreadyAdded("/someDir", "myUser", "myBot", "myEndUser");
		   builder.addDirectoryUnlessAlreadyAdded("../../someDir", "myUser", "myBot", "myEndUser");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.addDirectoryUnlessAlreadyAdded("C:\\someDir", "myUser", "myBot", "myEndUser");
		   builder.addDirectoryUnlessAlreadyAdded("C:/someDir", "myUser", "myBot", "myEndUser");
		   builder.addDirectoryUnlessAlreadyAdded("..\\..\\someDir", "myUser", "myBot", "myEndUser");
		   </pre>
		 * 
		 *
		 * @param directory The AIML directory to add to the internal 
		 * queue.
		 *
		 * @param userId The id of the user you want to add a directory 
		 * to.
		 * 
		 * @param botId The id of the bot this directory of files 
		 * belongs to.
		 *
		 * @param endUserId The id of the end user that is adding this 
		 * list of files from this directory.
		 *
		 * @param regularExpression The regular expression which defines
		 * what a AIML file is within the directory. The default is all
		 * files which end in ".aiml".
		 *
		 * @exception IllegalArgumentException  If the regular expression is an 
		 * invalid regular expression
		 *
		 * @exception DirectoryNotFoundException If the directory is not found
		 *
		 * @exception Exception If an underlying method throws an exception, 
		 * it will be wrapped and thrown as a Exception
		 */
		virtual void addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
			                                        const StringPimpl &userId, 
								                    const StringPimpl &botId,
								                    const StringPimpl &endUserId,
			                                        const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &) = 0;

		/**
		 * Add directory of AIML files to the internal queue for 
		 * latter processing by GraphBuilder::removeGraph().
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::removeFile() and/or GraphBuilder::removeDirectory()
		 * and/or GraphBuilder::removeString(),
		 * call GraphBuilder::removeGraph() to parse and remove
		 * the file(s) from the RebeccaAIML embedded database 
		 * structures.
		 * 
		 * Since parsing and removing from the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually removing from the internal 
		 * data embedded database structures separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.removeDirectory("/someDir/someFile.aiml");
		   builder.removeDirectory("../../someDir/someFile.aiml");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.removeDirectory("C:\\someDir\\someFile.aiml");
		   builder.removeDirectory("C:/someDir/someFile.aiml");
		   builder.removeDirectory("..\\..\\someDir\\someFile.aiml");
		   </pre>
		 * 
		 *
		 * @param directory The AIML directory to add to the internal 
		 * queue for removal from the embedded database.
		 *
		 * @param regularExpression The regular expression which defines
		 * what a AIML file is within the directory. The default is all
		 * files which end in ".aiml".
		 *
		 * @exception IllegalArgumentException  If the regular expression is an 
		 * invalid regular expression
		 *
		 * @exception DirectoryNotFoundException If the directory is not found, 
		 * this method will throw a DirectoryNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void removeDirectory(const StringPimpl &directory, 
			                         const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &) = 0;

		/**
		 * Add directory of AIML files to the internal queue for 
		 * latter processing by GraphBuilder::removeGraph().
		 * 
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::removeFile() and/or GraphBuilder::removeDirectory()
		 * and/or GraphBuilder::removeString(),
		 * call GraphBuilder::removeGraph() to parse and remove
		 * the file(s) from the RebeccaAIML embedded database 
		 * structures.
		 * 
		 * Since parsing and removing from the embedded data base
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually removing from the internal 
		 * data embedded database structures separate for convenience.
         *
		 * Both relative and absolute paths are allowed.  Although
		 * you can use Windows paths it's recommended to try to use
		 * unix paths to be cross platform.  Windows paths will only 
		 * work on Windows.  Unix paths will work both on unix's and
		 * under Windows.
		 * 
		 * Examples that work under both Unix and Windows:
		 * <pre>
		   builder.removeDirectory("/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.removeDirectory("../../someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
	     *
		 * Some examples that <b>only</b> work under Windows.
		 * <pre>
		   builder.removeDirectory("C:\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.removeDirectory("C:/someDir/someFile.aiml", "myUser", "myBot", "myEndUser");
		   builder.removeDirectory("..\\..\\someDir\\someFile.aiml", "myUser", "myBot", "myEndUser");
		   </pre>
		 * 
		 *
		 * @param directory The AIML directory to add to the internal 
		 * queue for removal from the embedded database.
		 *
		 * @param userId The id of the user you want to remove a 
		 * directory from.
		 * 
		 * @param botId The id of the bot this directory belongs to.
		 *
		 * @param endUserId The id of the end user that is removing
		 * this directory.
		 *
		 * @param regularExpression The regular expression which defines
		 * what a AIML file is within the directory. The default is all
		 * files which end in ".aiml".
		 *
		 * @exception IllegalArgumentException  If the regular expression is an 
		 * invalid regular expression
		 *
		 * @exception DirectoryNotFoundException If the directory is not found, 
		 * this method will throw a DirectoryNotFoundException.  
		 * 
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void removeDirectory(const StringPimpl &directory, 
			                         const StringPimpl &userId, 
								     const StringPimpl &botId,
								     const StringPimpl &endUserId,
			                         const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &) = 0;


		/**
		 * Add a string containing AIML to the internal queue
		 * for latter processing by GraphBuilder::createGraph().
		 *
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
         *
		 * Since parsing and building the embedded database
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * embedded database structures separate for convenience.
		 * 
		 * A quick example would be:
		 * <pre>
           builder.addString
           (
             "<category>"
             "<pattern>test aiml string</pattern>"
             "<template>it simply works!</template>"
             "</category>"
           );
		 </pre>
		 *
		 * By default a AIML Header attached to the beginning of your 
		 * string is:
		 * <pre>
         <?xml version="1.0" encoding="ISO-8859-1"?>
         <aiml version="1.0.1" xmlns="http://alicebot.org/2001/AIML-1.0.1"
              xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
              xsi:schemaLocation="http://alicebot.org/2001/AIML-1.0.1 http://aitools.org/aiml/schema/AIML.xsd">
	     </pre>
		 *
		 * and a AIML Footer attached to the end of your string is:
		 * <pre>
		 </aiml>
		 </pre>
		 *
		 * These are automatically attached to the beginning and end of 
		 * your string for you to form a correct XML document in memory.
		 * If you want to change either of these two values use
         * GraphBuilder::setAddStringAIMLHeader() and 
		 * GraphBuilder::setAddStringAIMLFooter()
		 * 
		 * @param stringContainingAIML The string that contains the 
		 * AIML to add to the internal queue.
		 *
		 * @exception Exception If an underlying method throws an 
		 * exception, it will be wrapped and thrown as a Exception.
		 */
		virtual void addString(const StringPimpl &stringContainingAIML)
			throw(Exception &) = 0;

		/**
		 * Add a string containing AIML to the internal queue
		 * for latter processing by GraphBuilder::createGraph().
		 *
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::addFile() and/or GraphBuilder::addDirectory()
		 * and/or GraphBuilder::addString(), and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * call GraphBuilder::createGraph() to parse and build
		 * the RebeccaAIML embedded database structures.
         *
		 * Since parsing and building the embedded database
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually creating the internal 
		 * embedded data structures in the embedded database 
		 * separate for convenience.
		 * 
		 * A quick example would be:
		 * <pre>
           builder.addString
           (
             "<category>"
             "<pattern>test aiml string</pattern>"
             "<template>it simply works!</template>"
             "</category>"
           );
		 </pre>
		 *
		 * By default a AIML Header attached to the beginning of your 
		 * string is:
		 * <pre>
         <?xml version="1.0" encoding="ISO-8859-1"?>
         <aiml version="1.0.1" xmlns="http://alicebot.org/2001/AIML-1.0.1"
              xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
              xsi:schemaLocation="http://alicebot.org/2001/AIML-1.0.1 http://aitools.org/aiml/schema/AIML.xsd">
	     </pre>
		 *
		 * and a AIML Footer attached to the end of your string is:
		 * <pre>
		 </aiml>
		 </pre>
		 *
		 * These are automatically attached to the beginning and end of 
		 * your string for you to form a correct XML document in memory.
		 * If you want to change either of these two values use
         * GraphBuilder::setAddStringAIMLHeader() and 
		 * GraphBuilder::setAddStringAIMLFooter()
		 * 
		 * @param stringContainingAIML The string that contains the 
		 * AIML to add to the internal queue.
		 *
		 * @param userId The id of the user you want to add a 
		 * file to.
		 * 
		 * @param botId The id of the bot this file belongs to.
		 *
		 * @param endUserId The id of the end user that is adding
		 * this file.
		 * @exception Exception If an underlying method throws an exception, it will 
		 * be wrapped and thrown as a Exception.
		 */
		virtual void addString(const StringPimpl &stringContainingAIML,
			                   const StringPimpl &userId,
							   const StringPimpl &botId,
							   const StringPimpl &endUserId)
			throw(Exception &) = 0;

		/**
		 * Add a string containing AIML to the internal queue
		 * for latter processing by GraphBuilder::removeGraph().
		 *
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::removeFile() and/or GraphBuilder::removeDirectory()
		 * and/or GraphBuilder::removeString(),
		 * call GraphBuilder::removeGraph() to parse and remove
		 * the file(s) from the RebeccaAIML embedded database 
		 * structures.
         *
		 * Since parsing and removing from the embedded database
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually removing from the internal 
		 * embedded data structures in the embedded database 
		 * separate for convenience.
		 * 
		 * A quick example would be:
		 * <pre>
           builder.removeString
           (
             "<category>"
             "<pattern>test aiml string</pattern>"
             "<template>it simply works!</template>"
             "</category>"
           );
		 </pre>
		 *
		 * By default a AIML Header attached to the beginning of your 
		 * string is:
		 * <pre>
         <?xml version="1.0" encoding="ISO-8859-1"?>
         <aiml version="1.0.1" xmlns="http://alicebot.org/2001/AIML-1.0.1"
              xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
              xsi:schemaLocation="http://alicebot.org/2001/AIML-1.0.1 http://aitools.org/aiml/schema/AIML.xsd">
	     </pre>
		 *
		 * and a AIML Footer attached to the end of your string is:
		 * <pre>
		 </aiml>
		 </pre>
		 *
		 * These are automatically attached to the beginning and end of 
		 * your string for you to form a correct XML document in memory.
		 * If you want to change either of these two values use
         * GraphBuilder::setAddStringAIMLHeader() and 
		 * GraphBuilder::setAddStringAIMLFooter()
		 * 
		 * @param stringContainingAIML The string that contains the 
		 * AIML to add to the internal queue for removal from the 
		 * embedded database.
		 *
		 * @exception Exception If an underlying method throws an exception, it will 
		 * be wrapped and thrown as a Exception.
		 */
		virtual void removeString(const StringPimpl &stringContainingAIML)
			throw(Exception &) = 0;

		/**
		 * Add a string containing AIML to the internal queue
		 * for latter processing by GraphBuilder::removeGraph().
		 *
		 * Once all the the files you want to be parsed 
		 * have been added to the internal queue by 
		 * GraphBuilder::removeFile() and/or GraphBuilder::removeDirectory()
		 * and/or GraphBuilder::removeString(),
		 * call GraphBuilder::removeGraph() to parse and remove
		 * the file(s) from the RebeccaAIML embedded database 
		 * structures.
         *
		 * Since parsing and removing from the embedded database
		 * structures is expensive, it's best to keep the 
		 * functionality for queuing files and the 
		 * functionality for actually removing from the internal 
		 * embedded data structures in the embedded database 
		 * separate for convenience.
		 * 
		 * A quick example would be:
		 * <pre>
           builder.removeString
           (
             "<category>"
             "<pattern>test aiml string</pattern>"
             "<template>it simply works!</template>"
             "</category>",
             "MyUser",
             "MyBot",
             "MyEndUser"
           );
		 </pre>
		 *
		 * By default a AIML Header attached to the beginning of your 
		 * string is:
		 * <pre>
         <?xml version="1.0" encoding="ISO-8859-1"?>
         <aiml version="1.0.1" xmlns="http://alicebot.org/2001/AIML-1.0.1"
              xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
              xsi:schemaLocation="http://alicebot.org/2001/AIML-1.0.1 http://aitools.org/aiml/schema/AIML.xsd">
	     </pre>
		 *
		 * and a AIML Footer attached to the end of your string is:
		 * <pre>
		 </aiml>
		 </pre>
		 *
		 * These are automatically attached to the beginning and end of 
		 * your string for you to form a correct XML document in memory.
		 * If you want to change either of these two values use
         * GraphBuilder::setAddStringAIMLHeader() and 
		 * GraphBuilder::setAddStringAIMLFooter()
		 * 
		 * @param stringContainingAIML The string that contains the 
		 * AIML to add to the internal queue for removal from the 
		 * embedded database.
		 *
		 * @param userId The id of the user you want to remove the 
		 * string from.
		 * 
		 * @param botId The id of the bot this string belongs to.
		 *
		 * @param endUserId The id of the end user that is removing
		 * this string.
		 * 
		 * @exception Exception If an underlying method throws an exception, it will 
		 * be wrapped and thrown as a Exception.
		 */
		virtual void removeString(const StringPimpl &stringContainingAIML,
			                      const StringPimpl &userId,
							      const StringPimpl &botId,
							      const StringPimpl &endUserId)
			throw(Exception &) = 0;

		/**
		 * Sets the string that is automatically attached to the 
		 * the beginning of the string sent to GraphBuilder::addString()
		 * to help form a correct XML document in memory.
		 *
		 * The default string set when Rebecca starts is:
		 * <pre>
         <?xml version="1.0" encoding="ISO-8859-1"?>
         <aiml version="1.0.1" xmlns="http://alicebot.org/2001/AIML-1.0.1"
              xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
              xsi:schemaLocation="http://alicebot.org/2001/AIML-1.0.1 http://aitools.org/aiml/schema/AIML.xsd">
	     </pre>
		 *
		 * @param aimlHeader The string to change which is automatically
		 * attached to the beginning of the string sent to 
		 * GraphBuilder::addString()
		 *
		 * @exception Exception If an underlying method throws an exception, it will 
		 * be wrapped and thrown as a Exception.
		 */
		virtual void setAddStringAIMLHeader(const StringPimpl &aimlHeader)
			throw(Exception &) = 0;

		/**
		 * Sets the string that is automatically attached to the 
		 * the end of the string sent to GraphBuilder::addString()
		 * to help form a correct XML document in memory.
		 *
		 * The default string set when Rebecca starts is:
		 *
		 * <pre>
		 </aiml>
		 </pre>
		 * @param aimlFooter The string to change which is automatically
		 * attached to the end of the string sent to 
		 * GraphBuilder::addString()
		 *
		 * @exception Exception If an underlying method throws an exception, it will 
		 * be wrapped and thrown as a Exception.
		 *
		 */
		virtual void setAddStringAIMLFooter(const StringPimpl &aimlFooter)
			throw(Exception &) = 0;

		/**
		 * Sets the xsd schema for validating AIML XML files.
		 *
		 * @param schema The xsd schema for validating AIML XML files.
		 *
		 * @exception FileNotFoundException If the schema file is not found
		 *
		 * @exception Exception If an underlying method throws an exception, it will
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setAIMLSchema(const StringPimpl &schema) 
			throw(Exception &, FileNotFoundException &) = 0;

		/**
		 * Sets the common types schema for validating RebeccaAIML 
		 * configuration files.  This has to be set in conjuction with
		 * GraphBuilder::setBotConfigurationSchema.
		 *
		 * @param schema The schema for validating RebeccaAIML 
		 * configuration files.  
		 *
		 * @exception FileNotFoundException If the schema file is not found
		 *
		 * @exception Exception If an underlying method throws an exception, it will
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setCommonTypesSchema(const StringPimpl &schema) 
			throw(Exception &, FileNotFoundException &) = 0;

		/**
		 * Sets whether to use AIML validation from the 
		 * xsd given at GraphBuilder::setAIMLSchema() or not.
		 * 
		 * By default if this is not called, then the AIML 
		 * validation will not be used even if 
		 * GraphBuilder::setAIMLSchema() has been called with a
		 * valid xsd.
		 * 
		 * @param trueOrFalse By default true.  Set this to true
		 * to use validation and false to not use validation.
		 * 
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual void setAIMLValidation(bool trueOrFalse = true) 
			throw(Exception &) = 0;
		
		/** 
		 * Queries the AIML internal embedded database structures 
		 * with conversational input and returns the AIML response.
		 * 
		 * This is the method which ultimately you want to call 
		 * after setup to query the AIML brain/embedded database 
		 * structure and get back a response.
		 *
		 * @param input The human conversational input separated by 
		 * the sentence splitters you setup from either from 
		 * configuration file or GraphBuilder::setSentenceSplitter().
		 * 
		 * @return Returns the AIML response to the human 
		 * conversation.
		 *
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getResponse(const StringPimpl &input) 
			throw(Exception &) = 0;

		/** 
		 * Queries the AIML internal embedded database structures 
		 * with conversational input and returns the AIML response.
		 * 
		 * This is the method which ultimately you want to call 
		 * after setup to query the AIML brain/embedded database 
		 * structure and get back a response.
		 *
		 * @param input The human conversational input separated by 
		 * the sentence splitters you setup from either from 
		 * configuration file or GraphBuilder::setSentenceSplitter().
		 * 
		 * @param userId The id of the user you want to query.
		 * 
		 * @param botId The id of the user's bot you want the response 
		 * from.
		 *
		 * @param endUserId The id of the end user that is making the 
		 * query to the bot.
		 *
		 * @return Returns the AIML response to the human 
		 * conversation.
		 *
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getResponse(const StringPimpl &input, 
			                            const StringPimpl &userId, 
										const StringPimpl &botId,
										const StringPimpl &endUserId) 
			throw(Exception &) = 0;

		/**
		 * This allows you to hand set the current that.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  It sets the internal that 
		 * which is done automatically by RebeccaAiml.  However, 
		 * this is provided in case you want to do testing or 
		 * set the internal that yourself.
		 *
		 * @param that The internal AIML that in which you can
		 * set yourself if you really want to.
		 * 
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual void setThat(const StringPimpl &that) 
			throw(Exception &) = 0;

		/**
		 * This allows you to hand set the current that.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  It sets the internal that 
		 * which is done automatically by RebeccaAiml.  However, 
		 * this is provided in case you want to do testing or 
		 * set the internal that yourself.
		 *
		 * @param that The internal AIML that in which you can
		 * set yourself if you really want to.
		 *
		 * @param userId The id of the user you want to set the 
		 * internal AIML that to.
		 * 
		 * @param botId The id of the user's bot you want to 
		 * set the internal AIML that to.
		 *
		 * @param endUserId The id of the end user that is setting 
		 * the internal AIML that.
		 * 
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual void setThat(const StringPimpl &that,
			                 const StringPimpl &userId,
							 const StringPimpl &botId,
							 const StringPimpl &endUserId) 
			throw(Exception &) = 0;

		/**
		 * This allows you to hand set current topic.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  It sets the internal topic
		 * which is done automatically by RebeccaAiml.  However, 
		 * this is provided in case you want to do testing or 
		 * set the internal topic yourself.
		 *
		 * @param topic The internal AIML topic in which you can
		 * set yourself if you really want to.
		 * 
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual void setTopic(const StringPimpl &topic) 
			throw(Exception &) = 0;

		/**
		 * This allows you to hand set the current topic.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  It sets the internal topic
		 * which is done automatically by RebeccaAiml.  However, 
		 * this is provided in case you want to do testing or 
		 * set the internal topic yourself.
		 *
		 * @param topic The internal AIML topic in which you can
		 * set yourself if you really want to.
		 * 
		 * @param userId The id of the user you want to set the 
		 * internal AIML topic to.
		 * 
		 * @param botId The id of the user's bot you want to 
		 * set the internal AIML topic to.
		 *
		 * @param endUserId The id of the end user that is setting 
		 * the internal AIML topic.
		 *
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual void setTopic(const StringPimpl &topic,
			                  const StringPimpl &userId,
							  const StringPimpl &botId,
							  const StringPimpl &endUserId) 
			throw(Exception &) = 0;

		/**
		 * This returns the current that.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  It returns the AIML data 
		 * structure's current internal that.
		 * However, this is provided in case you want to do 
		 * testing or get the internal that yourself for debugging
		 * purposes.   
		 *
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getThat() const
			throw(Exception &) = 0;

		/**
		 * This returns the current that.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  It returns the AIML data 
		 * structure's current internal that.
		 * However, this is provided in case you want to do 
		 * testing or get the internal that yourself for debugging
		 * purposes.   
		 *
		 * @param userId The id of the user you want to get the 
		 * internal AIML that from.
		 * 
		 * @param botId The id of the user's bot you want to 
		 * get the internal AIML that from.
		 *
		 * @param endUserId The id of the end user that is getting
		 * the internal AIML that.
		 *
		 * @exception Exception This will not directly throw an exception but if
		 * an underlying method throws an exception, it will be 
		 * wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getThat(const StringPimpl &userId,
			                        const StringPimpl &botId,
									const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/**
		 * This returns the current topic.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  This returns the 
		 * current internal topic.  However, this is provided 
		 * in case you want to do testing or get the internal 
		 * topic yourself for debugging purposes.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getTopic() const
			throw(Exception &) = 0;

		/**
		 * This returns the current topic.
		 *
		 * This is a more advanced feature that not a lot of 
		 * people will find useful.  This returns the 
		 * current internal topic.
		 * However, this is provided in case you want to do 
		 * testing or get the internal topic yourself for debugging
		 * purposes.
		 *
		 * @param userId The id of the user you want to get the 
		 * internal AIML topic from.
		 * 
		 * @param botId The id of the user's bot you want to 
		 * get the internal AIML topic from.
		 *
		 * @param endUserId The id of the end user that is getting
		 * the internal AIML topic.
         *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getTopic(const StringPimpl &userId,
			                         const StringPimpl &botId,
									 const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/**
		 * Creates the embedded database structures needed to 
		 * be able to query AIML through GraphBuilder::getResponse().
		 * 
		 * After files from GraphBuilder::addFile(), 
		 * and/or GraphBuilder::addDirectory(), 
		 * and/or GraphBuilder::addString(), 
		 * and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * and/or GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * and other RebeccaAIML setups have taken place this method 
		 * should be called to create the internal data 
		 * structures needed to perform an AIML query.
		 * 
		 * @exception XMLErrorException A possible
		 * XMLErrorException can occur through either illegal 
		 * AIML tags or through a bad initialization of the 
		 * internal XML engine.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.  
		 */
		virtual void createGraph() 
			throw(XMLErrorException &, Exception &) = 0;

		/**
		 * Creates the embedded database structures needed to 
		 * be able to query AIML through GraphBuilder::getResponse().
		 * 
		 * After files from GraphBuilder::addFile(), 
		 * and/or GraphBuilder::addDirectory(), 
		 * and/or GraphBuilder::addString(), 
		 * and/or GraphBuilder::addFileUnlessAlreadyAdded(),
		 * and/or GraphBuilder::addDirectoryUnlessAlreadyAdded(),
		 * and other RebeccaAIML setups have taken place this method 
		 * should be called to create the internal data 
		 * structures needed to perform an AIML query.
		 * 
		 * @param userId The id of the user you want to create 
		 * the embedded database structures for.
		 * 
		 * @param botId The id of the user's bot you want to 
		 * create the embedded database structures for.
		 *
		 * @param endUserId The id of the end user that is requesting
		 * the createGraph.
         *
		 * @exception XMLErrorException A possible
		 * XMLErrorException can occur through either illegal 
		 * AIML tags or through a bad initialization of the 
		 * internal XML engine.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.  
		 */
		virtual void createGraph(const StringPimpl &userId,
			                     const StringPimpl &botId,
								 const StringPimpl &endUserId) 
			throw(XMLErrorException &, Exception &) = 0;

		/**
		 * Removes requested embedded database structures from
		 * the embedded database.
		 * 
		 * After files from GraphBuilder::removeFile(), 
		 * and/or GraphBuilder::removeDirectory(), 
		 * and/or GraphBuilder::removeString(), 
		 * have been added to the internal queue,
		 * this method should be called to remove the 
		 * embedded database structures.
		 * 
		 * @exception XMLErrorException A possible
		 * XMLErrorException can occur through either illegal 
		 * AIML tags or through a bad initialization of the 
		 * internal XML engine.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.  
		 */
		virtual void removeGraph() 
			throw(XMLErrorException &, Exception &) = 0;

		/**
		 * Removes requested embedded database structures from
		 * the embedded database.
		 * 
		 * After files from GraphBuilder::removeFile(), 
		 * and/or GraphBuilder::removeDirectory(), 
		 * and/or GraphBuilder::removeString(), 
		 * have been added to the internal queue,
		 * this method should be called to remove the 
		 * embedded database structures.
		 * 
		 * @param userId The id of the user you want to remove 
		 * the embedded database structures from.
		 * 
		 * @param botId The id of the user's bot you want to 
		 * remove the embedded database structures from.
		 *
		 * @param endUserId The id of the end user that is requesting
		 * the removeGraph.
         *
		 * @exception XMLErrorException A possible
		 * XMLErrorException can occur through either illegal 
		 * AIML tags or through a bad initialization of the 
		 * internal XML engine.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.  
		 */
		virtual void removeGraph(const StringPimpl &userId,
			                     const StringPimpl &botId,
								 const StringPimpl &endUserId) 
			throw(XMLErrorException &, Exception &) = 0;

		/**
		 * Checks if the predicateName matches the aimlPattern and returns true or 
		 * false accordingly.
		 *
		 * This is mostly for just debugging purposes for the user to check against
		 * condition AIML tags since, internally, the condition AIML tags use this 
		 * same method when encountered at runtime during a GraphBuilder::getResponse().
		 *
		 * @param predicateName The variable name to check a AIML pattern against.
		 *
		 * @param aimlPattern The AIML pattern to check against variable name to see 
		 * if the two match.
		 * 
		 * @return Returns true if the AIML pattern matches the predicateName otherwise
		 * returns false.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual bool predicateMatch(const StringPimpl &predicateName, 
			                        const StringPimpl &aimlPattern) const
			throw(Exception &) = 0;

		/**
		 * Checks if the predicateName matches the aimlPattern and returns true or 
		 * false accordingly.
		 *
		 * This is mostly for just debugging purposes for the user to check against
		 * condition AIML tags since, internally, the condition AIML tags use this 
		 * same method when encountered at runtime during a GraphBuilder::getResponse().
		 *
		 * @param predicateName The variable name to check a AIML pattern against.
		 *
		 * @param aimlPattern The AIML pattern to check against variable name to see 
		 * if the two match.
		 * 
		 * @param userId The user you are matching against.
		 *
		 * @param botId The bot of the user you are matching against.
		 *
		 * @param endUserId The end user requesting the match.
		 *
		 * @return Returns true if the AIML pattern matches the predicateName otherwise
		 * returns false.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual bool predicateMatch(const StringPimpl &predicateName, 
			                        const StringPimpl &aimlPattern,
									const StringPimpl &userId,
									const StringPimpl &botId,
									const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/** 
		 * Sets a predicate inside of the AIML embedded database in the same way that a 
		 * AIML "Set" tag does.  
		 * 
		 * This method is called usually whenever the AIML tag "Set" is encountered 
		 * to set a predicate to a value, but it is exposed here so that the user of 
		 * RebeccaAIML api may also set predicates the same way.  After this method is 
		 * called setting up a new predicate with a value, any AIML "Get" tags latter 
		 * encountered querying the predicate name will return the value which was 
		 * set here. 
		 *
		 * @param name The name of the predicate to put into the AIML embedded database.
		 * 
		 * @param value The value of the predicate name to put into the AIML embedded database.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setPredicate(const StringPimpl &name, 
			                      const StringPimpl &value) 
			throw(Exception &) = 0;

		/** 
		 * Sets a predicate inside of the AIML embedded database in the same way that a 
		 * AIML "Set" tag does.  
		 * 
		 * This method is called usually whenever the AIML tag "Set" is encountered 
		 * to set a predicate to a value, but it is exposed here so that the user of 
		 * RebeccaAIML api may also set predicates the same way.  After this method is 
		 * called setting up a new predicate with a value, any AIML "Get" tags latter 
		 * encountered querying the predicate name will return the value which was 
		 * set here. 
		 *
		 * @param name The name of the predicate to put into the AIML embedded database.
		 * 
		 * @param value The value of the predicate name to put into the AIML embedded database.
		 *
		 * @param userId The user you are using to set the predicate for.
		 *
		 * @param botId The bot you are using to set the predicate for.
		 *
		 * @param endUserId The end user you are setting the predicate against.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setPredicate(const StringPimpl &name, 
			                      const StringPimpl &value,
								  const StringPimpl &userId,
								  const StringPimpl &botId,
								  const StringPimpl &endUserId) 
			throw(Exception &) = 0;

		/** 
		 * Gets a predicate inside of the AIML embedded database in the same way that a 
		 * AIML "Get" tag does.  
		 * 
		 * This method is called usually whenever the AIML tag "Get" is encountered 
		 * to retrieve a predicate name's value, but it is exposed here so that the user of 
		 * RebeccaAIML api may also get predicates the same way.
		 *
		 * @param name The name of the predicate to get the value of from 
		 * the AIML embedded database.
		 * 
		 * @return Returns the value of the predicate's name or empty string if the 
		 * predicate name does not exist in the embedded database.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getPredicate(const StringPimpl &name) const
			throw(Exception &) = 0;

		/** 
		 * Gets a predicate inside of the AIML embedded database in the same way that a 
		 * AIML "Get" tag does.  
		 * 
		 * This method is called usually whenever the AIML tag "Get" is encountered 
		 * to retrieve a predicate name's value, but it is exposed here so that the user of 
		 * RebeccaAIML api may also get predicates the same way.
		 *
		 * @param name The name of the predicate to get the value of from 
		 * the AIML embedded database.
		 * 
		 * @param userId The user you are getting the predicate for.
		 *
		 * @param botId The bot you are getting the predicate for.
		 *
		 * @param endUserId The end user you are getting the predicate against.
         *
		 * @return Returns the value of the predicate's name or empty string if the 
		 * predicate name does not exist in the embedded database.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getPredicate(const StringPimpl &name,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/** 
		 * Gets a bot predicate inside of the AIML embedded database in the same way that a 
		 * AIML "Bot" tag does.  
		 * 
		 * This method is called usually whenever the AIML tag "Bot" is encountered 
		 * to retrieve a predicate name's value, but it is exposed here so that the user of 
		 * RebeccaAIML api may also get predicates the same way.
		 *
		 * @param name The name of the predicate to get the value of from 
		 * the embedded database.
		 * 
		 * @return Returns the value of the predicate's name or empty string if the 
		 * predicate name does not exist in the embedded database.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getBotPredicate(const StringPimpl &name) const
			throw(Exception &)  = 0;

		/** 
		 * Gets a bot predicate inside of the AIML embedded database in the same way that a 
		 * AIML "Bot" tag does.  
		 * 
		 * This method is called usually whenever the AIML tag "Bot" is encountered 
		 * to retrieve a predicate name's value, but it is exposed here so that the user of 
		 * RebeccaAIML api may also get predicates the same way.
		 *
		 * @param name The name of the predicate to get the value of from 
		 * the embedded database.
		 * 
		 * @param userId The user you are getting the bot predicate for.
		 *
		 * @param botId The bot you are getting the bot predicate against.
		 *
		 * @param endUserId The end user you are getting the bot predicate for.
         *
		 * @return Returns the value of the predicate's name or empty string if the 
		 * predicate name does not exist in the embedded database.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getBotPredicate(const StringPimpl &name,
			                                const StringPimpl &userId,
											const StringPimpl &botId,
											const StringPimpl &endUserId) const
			throw(Exception &)  = 0;

		/** 
		 * Sets a bot predicate inside of the AIML embedded database.  
		 * 
		 * This is the only means to set a bot Predicate so that during a 
		 * GraphBuilder::getResponse() the "Bot" AIML tag returns the predicate
		 * set here.  After this method is called setting up a new predicate 
		 * with a value, any AIML "Bot" tags latter encountered querying the 
		 * predicate name will return the value which was set here. 
		 *
		 * @param name The name of the predicate to put into the AIML embedded database.
		 * 
		 * @param value The value of the predicate name to put into the AIML embedded database.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setBotPredicate(const StringPimpl &name,
			                         const StringPimpl &value) 
			throw(Exception &) = 0;

		/** 
		 * Sets a bot predicate inside of the AIML embedded database.  
		 * 
		 * This is the only means to set a bot Predicate so that during a 
		 * GraphBuilder::getResponse() the "Bot" AIML tag returns the predicate
		 * set here.  After this method is called setting up a new predicate 
		 * with a value, any AIML "Bot" tags latter encountered querying the 
		 * predicate name will return the value which was set here. 
		 *
		 * @param name The name of the predicate to put into the AIML embedded database.
		 * 
		 * @param value The value of the predicate name to put into the AIML embedded database.
		 * 
		 * @param userId The user you are getting the bot predicate for.
		 *
		 * @param botId The bot you are getting the bot predicate against.
		 *
		 * @param endUserId The end user you are getting the bot predicate for.
         *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setBotPredicate(const StringPimpl &name, 
			                         const StringPimpl &value,
									 const StringPimpl &userId,
									 const StringPimpl &botId,
									 const StringPimpl &endUserId)
			throw(Exception &) = 0;

		/**
		 * Returns a previous RebeccaAIML response.
		 *
		 * Retrieves a previous RebeccaAIML bot response returned from 
		 * GraphBuilder::getResponse().  Useful for debugging or informative purposes, 
		 * or to put other AI logic besides just using AIML tags.
		 *
		 * @param previousBotResponse The index of the previous Bot Response to retrieve.
		 *
		 * @param sentence Which sentence of the previous bot response to retrieve.
		 *
		 * @return Returns the previous Bot Response.
		 *
		 * @exception IllegalArgumentException If the previousBotResponse or sentence
		 * is out of range.  
		 *
		 * @exception Exception If an underlying method throws an exception, it will
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getPreviousBotResponse(const unsigned int &previousBotResponse, 
			                                       const unsigned int &sentence) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns a previous RebeccaAIML response.
		 *
		 * Retrieves a previous RebeccaAIML bot response returned from 
		 * GraphBuilder::getResponse().  Useful for debugging or informative purposes, 
		 * or to put other AI logic besides just using AIML tags.
		 *
		 * @param previousBotResponse The index of the previous Bot Response to retrieve.
		 *
		 * @param sentence Which sentence of the previous bot response to retrieve.
		 *
		 * @param userId The user id to get the previous bot response of.
		 *
		 * @param botId The bot to get the previous bot response against.
         *
		 * @param endUserId The end user requesting the previous bot response.
         *
		 * @return Returns the previous Bot Response.
		 *
		 * @exception IllegalArgumentException If the previousBotResponse or sentence
		 * is out of range.  
		 *
		 * @exception Exception If an underlying method throws an exception, it will
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getPreviousBotResponse(const unsigned int &previousBotResponse, 
			                                       const unsigned int &sentence,
												   const StringPimpl &userId,
												   const StringPimpl &botId,
												   const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns a previous RebeccaAIML user input.
		 *
		 * Retrieves a previous RebeccaAIML user input fed as an argument into 
		 * GraphBuilder::getResponse().  Useful for debugging or informative purposes, 
		 * or to put other AI logic besides just using AIML tags.
		 *
		 * @param previousUserInput The index of the previous user input to retrieve.
		 *
		 * @param sentence Which sentence of the previous user input to retrieve.
		 *
		 * @return Returns the previous user input.
		 *
		 * @exception IllegalArgumentException If the previous user input or sentence
		 * is out of range.  
		 *
		 * @exception Exception If an underlying method throws an exception, it will
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getPreviousUserInput(const unsigned int &previousUserInput, 
			                                     const unsigned int &sentence) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns a previous RebeccaAIML user input.
		 *
		 * Retrieves a previous RebeccaAIML user input fed as an argument into 
		 * GraphBuilder::getResponse().  Useful for debugging or informative purposes, 
		 * or to put other AI logic besides just using AIML tags.
		 *
		 * @param previousUserInput The index of the previous user input to retrieve.
		 *
		 * @param sentence Which sentence of the previous user input to retrieve.
		 *
		 * @param userId The user to get the previous response against.
		 *
		 * @param botId The bot id to get the previous response of.
         *
		 * @param endUserId The end user requesting the previous response.
		 *
		 * @return Returns the previous user input.
		 *
		 * @exception IllegalArgumentException If the previous user input or sentence
		 * is out of range.  
		 *
		 * @exception Exception If an underlying method throws an exception, it will
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getPreviousUserInput(const unsigned int &previousUserInput, 
			                                     const unsigned int &sentence,
												 const StringPimpl &userId,
												 const StringPimpl &botId,
												 const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Sets the bot configuration schema to be used with parsing a RebeccaAIML 
		 * configuration file.
		 *
		 * This should be used in conjunction with 
		 * GraphBuilder::setCommonTypesSchema() and one of the 
		 * parseConfiguration methods of: 
         * GraphBuilder::parseSubstitutionFile(),
         * GraphBuilder::parsePropertiesFile(), 
         * and GraphBuilder::parseSentenceSplitterFile() 
         * with their respective XML files. Provided sample 
         * configuration files are bots.xml, properties.xml,
         * sentence-splitters.xml, and substitutions.xml.
		 *
		 * @param schema The schema for validating RebeccaAIML 
		 * configuration files.  
		 *
		 * @exception FileNotFoundException This will be thrown 
		 * if the file is not found.
         *
		 * @exception Exception If an underlying method throws an exception, it will
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setBotConfigurationSchema(const StringPimpl &schema) 
			throw(Exception &, FileNotFoundException &) = 0;

		/** 
		 * Sets XML Validation with the xml schema files from 
		 * GraphBuilder::setBotConfigurationSchema() and 
		 * GraphBuilder::setCommonTypesSchema().
		 *
		 * By default if this is not called, then the 
		 * validation will not be used even if 
		 * GraphBuilder::setBotConfigurationSchema() and 
		 * GraphBuilder::setCommonTypesSchema() has been called 
		 * with a valid xsd.
		 * 
		 * @param trueOrFalse True to turn on validation and false to 
		 * turn off validation.
		 *
		 * @exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setBotConfigurationValidation(const bool trueOrFalse = true) 
			throw(Exception &) = 0;

		/**
		 * Parses a substitution file and calls setXXXXSubstitution 
		 * methods for substitutions during runtime.
		 *
		 * Look at the sample xml file substitutions.xml and the xsd 
		 * bot-configuration.xsd for an idea of how to write substitution
		 * files.  More than likely you'll want to just use the sample 
		 * xml file provided.  Feel free to add to it for your own custom
		 * substitutions. Note that this will not be stored in the AIML 
		 * embedded database and that this will have to be called at 
		 * initialization of your program at startup each time.
		 * 
		 * Under the covers, as the xml engine parses the substitution
		 * xml file and calls 
		 * GraphBuilder::setInputSubstitution(),
		 * GraphBuilder::setGenderSubstitution(), 
		 * GraphBuilder::setPersonSubstitution(), 
		 * and GraphBuilder::setPerson2Substitution() 
		 * based upon the start tags inside of the xml file.
		 *
		 * @param fileName The name of the substitution file.
		 *
		 * @exception XMLErrorException This will be thrown if an XML error 
		 * is encountered.  
		 *
		 * @exception FileNotFoundException If the file does not exist
		 *
		 * @exception Exception Any underlying exceptions from other methods it 
		 * might call will be wrapped in this.
		 */
		virtual void parseSubstitutionFile(const StringPimpl &fileName) 
			throw(XMLErrorException &, FileNotFoundException &, Exception &) = 0;

		/**
		 * Parses a sentence splitter file and calls 
		 * GraphBuilder::setSentenceSplitter() for sentence splitters 
		 * during run time.
		 *
		 * Look at the sample xml file sentence-splitters.xml and the xsd 
		 * bot-configuration.xsd for an idea of how to write sentence splitter
		 * configuration files.  More than likely you'll want to just use 
		 * the sample xml file provided.  Feel free to add to it for your 
		 * own custom sentence splitters to it. Note that this 
		 * will not be stored in the AIML embedded database and that this will
		 * have to be called at initialization of your program at startup each
		 * time.
		 * 
		 * Under the covers, as the xml engine parses the sentence splitter
		 * xml file, it calls GraphBuilder::setSentenceSplitter() for each
		 * sentence splitter it finds.
		 *
		 * @param fileName The name of the sentence splitter file.
		 * 
		 * @exception XMLErrorException This will be thrown if an XML error 
		 * is encountered.  
		 *
		 * @exception FileNotFoundException If the file does not exist
		 *
		 * @exception Exception Any underlying exceptions from other methods it 
		 * might call will be wrapped in this.
		 */
		virtual void parseSentenceSplitterFile(const StringPimpl &fileName) 
			throw(XMLErrorException &, FileNotFoundException &, Exception &) = 0;

		/**
		 * Parses a properties file and calls GraphBuilder::setBotPredicate() 
		 * for each property encountered.
		 *
		 * Look at the sample xml file properties.xml and the xsd 
		 * bot-configuration.xsd for an idea of how to write bot properties
		 * configuration files.  More than likely you'll want to just use 
		 * the sample xml file provided.  Feel free to add to it for your 
		 * own custom bot properties to it.
		 * 
		 * Under the covers, as the xml engine parses the bot properties 
		 * xml file, it calls GraphBuilder::setBotPredicate() for each
		 * property it finds.
		 *
		 * @param fileName The name of the bot property file.
		 * 
		 * @exception XMLErrorException This will be thrown if an XML error 
		 * is encountered.  
		 *
		 * @exception FileNotFoundException If the file does not exist
		 *
		 * @exception Exception Any underlying exceptions from other methods it 
		 * might call will be wrapped in this.
		 */
		virtual void parsePropertiesFile(const StringPimpl &fileName)
			throw(XMLErrorException &, FileNotFoundException &, Exception &) = 0;

		/**
		 * Parses a properties file and calls GraphBuilder::setBotPredicate() 
		 * for each property encountered.
		 *
		 * Look at the sample xml file properties.xml and the xsd 
		 * bot-configuration.xsd for an idea of how to write bot properties
		 * configuration files.  More than likely you'll want to just use 
		 * the sample xml file provided.  Feel free to add to it for your 
		 * own custom bot properties to it.
		 * 
		 * Under the covers, as the xml engine parses the bot properties 
		 * xml file, it calls GraphBuilder::setBotPredicate() for each
		 * property it finds.
		 *
		 * @param fileName The name of the bot property file.
		 * 
		 * @param userId The user to parse the properties file for.
		 *
		 * @param botId The bot to parse the properties against and for.
		 *
		 * @param endUserId The end user requesting to parse a properties 
		 * file.
		 *
		 * @exception XMLErrorException This will be thrown if an XML error 
		 * is encountered.  
		 *
		 * @exception FileNotFoundException If the file does not exist
		 *
		 * @exception Exception Any underlying exceptions from other methods it 
		 * might call will be wrapped in this.
		 */
		virtual void parsePropertiesFile(const StringPimpl &fileName,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId)
			throw(XMLErrorException &, FileNotFoundException &, Exception &) = 0;

		/** 
		 * Adds a sentence splitter to distinguish the end of a sentence.
		 *
		 * Each time this is called with a character or string, that character or 
		 * string is added as a sentence splitter. Sentence splitters are used 
		 * internally to distinguish the end of a sentence.  See 
		 * GraphBuilder::parseSentenceSplitterFile() for a convenience method for
		 * parsing an example sentence splitter file provided.  Note that this 
		 * will not be stored in the AIML embedded database and that this will
		 * have to be called at initialization of your program at startup each
		 * time.
		 *
		 * @param splitter The character or string to be added as a splitter.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setSentenceSplitter(const StringPimpl &splitter) 
			throw(Exception &) = 0;

		/** 
		 * Sets a input substitution for the input that goes into 
		 * GraphBuilder::getResponse().
		 *
		 * Substitutions are good so as to not write duplicate AIML.  Note 
		 * that this will not be stored in the AIML embedded datbase and that 
		 * this will have to be called at initialization of your program at 
		 * startup each time.  
		 *
		 * A simple example of using this would be: 
		 *
		 * setInputSubstitution("it's", "it is");
		 *
		 * Now, if the input is: 
		 * 
		 * GraphBuilder::getResponse("It's a great day");
		 *
		 * The input will be substituted internally for "It is a great day".  
		 * Take note that the first argument to this method accepts regular 
		 * expressions which make this method more robust.  For example, it 
		 * is more robust to use the word boundary "\b" as in:
		 *
		 * setInputSubstitution("\bit's\b", "it is");
		 *
		 * Now, "it's" will only be substituted for "it is" when there is a 
		 * white space character on each side. 
		 *
		 * See GraphBuilder::parseSubstitutionFile(), a convenience method for
		 * parsing a provided substitution file.
		 *
		 * @param find A regular expression to search for in the input of 
		 * GraphBuilder::getResponse().
		 *
		 * @param replace The text to replace with.  This is NOT a regular 
		 * expression.
		 *
		 * @exception IllegalArgumentException will be thrown if the first 
		 * argument is a illegal regular expression. 
		 *
		 * @exception Exception Will be called from any underlying exceptions from 
		 * other methods it might call. 
		 */
		virtual void setInputSubstitution(const StringPimpl &find, 
			                              const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &) = 0;

		/** 
		 * Sets a gender substitution for AIML tag "Gender"
		 *
		 * Gender AIML tag is to replace all occurrences of one gender 
		 * with that of another.  So, this provided method allows the 
		 * gender substitutions to be set.  None are hardcoded internally
		 * for the "Gender" AIML tag. Note that this will not be stored 
		 * in the AIML embedded database and that this will have to be 
		 * called at initialization of your program at startup each
		 * time.
		 *
		 * A simple example to use this would be: 
		 *
		 * setGenderSubstitution("he", "she");
		 *
		 * Now, when the gender tag is encountered it will replace all 
		 * occurrences of "he" with "she".
		 *
		 * Take note that the first argument to this method accepts regular 
		 * expressions which make this method more robust.  For example, it 
		 * is more robust to use the word boundary "\b" as in:
		 *
		 * setGenderSubstitution("\bhe\b", "she");
		 *
		 * Now, "he" will only be substituted for "she" when there is a 
		 * white space character on each side.
		 *
		 * @param find A regular expression to search for inside of the 
		 * "Gender" AIML tag.
		 *
		 * @param replace The text to replace with.  This is NOT a regular 
		 * expression.
		 *
		 * @exception IllegalArgumentException will be thrown if the first 
		 * argument is a illegal regular expression. 
		 *
		 * @exception Exception Will be called from any underlying exceptions from 
		 * other methods it might call. 
		 */
		virtual void setGenderSubstitution(const StringPimpl &find, 
			                               const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &) = 0;

		/** 
		 * Sets a person substitution for AIML tag "Person"
		 *
		 * From the AIML specification:
		 * 
		 * The "Person" AIML tag is to replace words with first-person aspect 
		 * in the result of processing the contents of the person element 
		 * with words with the grammatically-corresponding third-person aspect; and
         * replace words with third-person aspect in the result of processing the 
		 * contents of the person element with words with the grammatically-corresponding 
		 * first-person aspect. Note that this will not be stored 
		 * in the AIML embedded database and that this will have to be 
		 * called at initialization of your program at startup each
		 * time.
		 *
		 * 
		 * A simple example to use this would be: 
		 *
		 * setPersonSubstitution("he was ", "I was");
		 *
		 * Now when the "Person" tag is encountered it will replace all 
		 * occurrences of "he was" with "I was".
		 *
		 * Take note that the first argument to this method accepts regular 
		 * expressions which make this method more robust.  For example, it 
		 * is more robust to use the word boundary "\b" as in:
		 *
		 * setGenderSubstitution("\bhe was\b", "I was");
		 *
		 * Now, "he was" will only be substituted for "I was" when there is a 
		 * white space character on each side.
		 *
		 * @param find A regular expression to search for inside of the 
		 * "Person" AIML tag.
		 *
		 * @param replace The text to replace with.  This is NOT a regular 
		 * expression.
		 *
		 * @exception IllegalArgumentException will be thrown if the first 
		 * argument is a illegal regular expression. 
		 *
		 * @exception Exception Will be called from any underlying exceptions from 
		 * other methods it might call. 
		 */
		virtual void setPersonSubstitution(const StringPimpl &find, 
			                               const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &) = 0;

		/** 
		 * Sets a person2 substitution for AIML tag "Person2"
		 *
		 * From the AIML specification:
		 * 
		 * The "Person2" AIML tag is to replace words with first-person aspect 
		 * in the result of processing the contents of the person2 element with 
		 * words with the grammatically-corresponding second-person aspect; and
		 * replace words with second-person aspect in the result of processing the 
		 * contents of the person2 element with words with the 
		 * grammatically-corresponding first-person aspect. Note that this will 
		 * not be stored in the AIML embedded database and that this will have to be 
		 * called at initialization of your program at startup each
		 * time.
		 *
		 * 
		 * A simple example to use this would be: 
		 *
		 * setPersonSubstitution("with you ", "with me");
		 *
		 * Now when the "Person2" tag is encountered it will replace all 
		 * occurrences of "with you" with "with me".
		 *
		 * Take note that the first argument to this method accepts regular 
		 * expressions which make this method more robust.  For example, it 
		 * is more robust to use the word boundary "\b" as in:
		 *
		 * setGenderSubstitution("\bwith you\b", "with me");
		 *
		 * Now, "with you" will only be substituted for "with me" when there is a 
		 * white space character on each side.
		 *
		 * @param find A regular expression to search for inside of the 
		 * "Person2" AIML tag.
		 *
		 * @param replace The text to replace with.  This is NOT a regular 
		 * expression.
		 *
		 * @exception IllegalArgumentException will be thrown if the first 
		 * argument is a illegal regular expression. 
		 *
		 * @exception Exception Will be called from any underlying exceptions from 
		 * other methods it might call. 
		 */
		virtual void setPerson2Substitution(const StringPimpl &find, 
			                                const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &)  = 0;
		
		/**
		 * Returns the version of RebeccaAIML.
		 *
		 * @return The version of RebeccaAIML.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getVersion() const 
			throw(Exception &) = 0;
		
		/** 
		 * Returns the number of AIML categories loaded
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual int getSize() const 
			throw(Exception &) = 0;

		/** 
		 * Returns the number of AIML categories loaded
		 * 
		 * @param userId The user to get the size of.
		 *
		 * @param botId The bot of the user to get the size
		 * against.
		 *
		 * @param endUserId The end user requesting the size
		 * of the bot.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual int getSize(const StringPimpl &userId, 
			                const StringPimpl &botId, 
							const StringPimpl &endUserId) const 
			throw(Exception &) = 0;

		/** 
		 * Sets the subclass of CallBacks to use for 
		 * RebeccaAIML callbacks.
		 *
		 * SubClass CallBacks with your own custom 
		 * subclass and then instantiate it.  Call this
		 * method with the address of your instantiated 
		 * class.  This method *WILL NOT* try to deallocate 
		 * the memory of your instantiated subclass.  You 
		 * are responsible for the memory management of it.
		 *
		 * @param callBacks The address of the instantiation of 
		 * your subclass.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setCallBacks(CallBacks *callBacks) 
			throw(Exception &) = 0;

		/** 
		 * Stores gossip the same way the AIML tag "Gossip" does.
		 *
		 * This under the covers will just call the callback 
		 * CallBacks::storeGossip().  If no callback is set through
		 * GraphBuilder::setCallBacks() this does nothing.
		 *
		 * @param gossip The textual gossip to store.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void storeGossip(const StringPimpl &gossip) 
			throw(Exception &) = 0;
		
		/** 
		 * Gets the id the same way the AIML tag "Id" does.
		 *
		 * This will return the userId set by 
		 * GraphBuilder::setUserIdBotIdEndUserId().
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl getId() const
			throw(Exception &) = 0;

		/** 
		 * Sets the user id, bot id, and end user id for all calls 
		 * to methods that do not have user id, bot id, and bot id
		 * arguments.
		 *
		 * If this is never called, and methods without user id's, 
		 * bot id's, and end user id's are called than by default 
		 * the user id, bot id, and end user id of "default" will 
		 * be used.
		 *
		 * @param userId The user id to set 
		 * 
		 * @param botId The bot id to set
		 *
		 * @param endUserId The end user id to set
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setUserIdBotIdEndUserId(const StringPimpl &userId, 
			                                 const StringPimpl &botId,
									         const StringPimpl &endUserId)
			throw(Exception &) = 0;

		/**
		 * Adds a custom AIML tag library which should be a 
		 * separate compiled .dll (Windows) or .so (Linux).
		 *
		 * The .dll or .so that has the custom AIML tags must 
		 * conform to the proper format.  The proper format is 
		 * that the .dll/.so should have a class that inherits 
		 * from CustomTags in it.  Also the two global C functions of 
		 * CustomTags *rebeccaAIMLLoadCustomTags() and 
		 * rebeccaAIMLRemoveCustomTags(CustomTagsImpl *customTags) 
		 * must be present. rebeccaAIMLLoadCustomTags returns a new instance
		 * of the class that inherits from CustomTags and 
		 * rebeccaAIMLRemoveCustomTags takes a CustomTags argument and deletes
		 * the object.  If both of these C functions cannot be found, an 
		 * exception will be thrown.
		 * 
		 * @param library The name of the library without the 
		 * extension of .dll or .so on the end.
		 *
		 * @exception Exception This will throw a FileNotFoundException if 
		 * the .dll or .so does not exist on the file system and it 
		 * will throw a generic Exception if it cannot load the 
		 * .dll or .so
		 */
		virtual void addCustomTagLibrary(const StringPimpl &library)
			throw(FileNotFoundException &, Exception &) = 0;

		/**
		 * Removes a custom AIML tag library which should be a 
		 * separate compiled .dll (Windows) or .so (Linux)
		 *
		 * The .dll or .so that has the custom AIML tags must 
		 * conform to the proper format.  The proper format is 
		 * that the .dll/.so should have a class that inherits 
		 * from CustomTags in it.  Also the two global C functions of 
		 * CustomTags *rebeccaAIMLLoadCustomTags() and 
		 * rebeccaAIMLRemoveCustomTags(CustomTagsImpl *customTags) 
		 * must be present. rebeccaAIMLLoadCustomTags returns a new instance
		 * of the class that inherits from CustomTags and 
		 * rebeccaAIMLRemoveCustomTags takes a CustomTags argument and deletes
		 * the object.  If both of these C functions cannot be found, an 
		 * exception will be thrown.
		 *
		 * @param library The name of the library without the 
		 * extension of .dll or .so on the end.
         *
		 * @exception Exception This will throw a FileNotFoundException if 
		 * the .dll or .so was never loaded in the first place.  It 
		 * will throw a generic Exception if it cannot unload the 
		 * .dll or .so
		 */
		virtual void removeCustomTagLibrary(const StringPimpl &library)
			throw(FileNotFoundException &, Exception &) = 0;
		
		/**
		 * This method acts the same as calling the AIML XML tag 
		 * "System" by sending the command to the operating 
		 * system and returning the output of the command.
		 *
		 * For example, if under dos you call this method with the
		 * string "dir" it will return a string with the full 
		 * directory listing.  
         *
		 * Likewise if under unix you call this method with the 
		 * string "ls" it will return a string with the full directory 
		 * listing.
		 * 
		 * @param command The string of the command to send to the 
		 * underlying operating system.
		 * 
		 * @return Returns the output of the Operating System after it
		 * executes the string.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl callSystemCommand(const StringPimpl &command) const
			throw(Exception &) = 0;

		///@todo document this.  Sets the directory.  If the directory is not 
		//found it will create it.  If this is not used and the directory is not 
		//set it will default to %HOMEPATH%/.RebeccaAIMLDB under windows and under 
		//Unix it will deafult to $HOME/.RebeccaAIMLDB.  Typically you set this 
		//method on constructor of GraphBuilderAIML.  Set this before you call 
		//your first createGraph().  Otherwise this method will throw an exception and 
		//the setting will be ignored.
		///@todo figure out how to make this work.  Right now you can't set this because the DB is already created at this point
		//virtual void setDBEnvironmentDirectory(const StringPimpl &directory)
		//	throw(Exception &) = 0;

		/**
		 * Synchronizes the in memory data to the embedded database.
		 *
		 * The database is synchronized on a regular basis but this 
		 * is provided if at any given point you want to ensure all 
		 * in memory data structures are flushed to disk at a particular 
		 * point.  On a normal program exit the database will be 
		 * synchronized so calling this before a normal program exit isn't necessary.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void synchronizeDatabase() const
			throw(Exception &) = 0;

		/**
		 * Returns an array of the currently loaded AIML files in 
		 * the embedded database.
		 * 
		 * Call this to get an array of the AIML files you have 
		 * loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of the AIML files currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getAIMLFileList(unsigned int &size) const
			throw(Exception &) = 0;
            
		/**
		 * Returns an array of the currently loaded AIML files in 
		 * the embedded database.
		 * 
		 * Call this to get an array of the AIML files you have 
		 * loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param userId The user to get the AIML files of.
		 *
		 * @param botId The bot to get the AIML files against.
		 *
		 * @param endUserId The end user requesting to get the AIML
		 * files.
		 * 
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of the AIML files currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getAIMLFileList(const StringPimpl &userId, 
			                                 const StringPimpl &botId, 
											 const StringPimpl &endUserId,
											 unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Call this with any StringPimpl * array to free the memory.
		 *
		 * When getting back arrays from methods such as GraphBuilder::getAIMLFileList()
		 * call this to free the memory once you're done with the array.  DO NOT
		 * try to delete[] the arrays yourself.  Always use this method to free the
		 * memory.  This is for dll boundary safety.
		 *
		 * @param arrayToDelete The array you want to delete.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void deleteStringPimplArray(StringPimpl *arrayToDelete) const
			throw(Exception &) = 0;

		/**
		 * Returns the number of the currently loaded AIML files in 
		 * the embedded database.
		 * 
		 * Call this to get how many AIML files you have 
		 * loaded in the embedded database.  
		 *
		 * @return Returns the number of AIML files currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getAIMLFileListSize() const
			throw(Exception &) = 0;

		/**
		 * Returns the number of the currently loaded AIML files in 
		 * the embedded database.
		 * 
		 * Call this to get how many AIML files you have 
		 * loaded in the embedded database.  
		 *
		 * @param userId The user to get the number of AIML files.
		 *
		 * @param botId The bot to get the number of AIML files against.
		 *
		 * @param endUserId The end user requesting to get the AIML
		 * file size.
		 *
		 * @return Returns the number of AIML files currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getAIMLFileListSize(const StringPimpl &userId, 
			                                     const StringPimpl &botId, 
										         const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/**
		 * Returns an array of the currently loaded AIML strings in 
		 * the embedded database.
		 * 
		 * Call this to get an array of the AIML strings you have 
		 * loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of the AIML strings currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getAIMLStringList(unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Returns an array of the currently loaded AIML strings in 
		 * the embedded database.
		 * 
		 * Call this to get an array of the AIML strings you have 
		 * loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param userId The user to get the AIML strings of.
		 *
		 * @param botId The bot to get the AIML strings against.
		 *
		 * @param endUserId The end user requesting to get the AIML
		 * strings.
		 * 
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of the AIML strings currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getAIMLStringList(const StringPimpl &userId, 
			                                   const StringPimpl &botId, 
											   const StringPimpl &endUserId,
											   unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Returns the number of the currently loaded AIML strings in 
		 * the embedded database.
		 * 
		 * Call this to get how many AIML strings you have 
		 * loaded in the embedded database.  
		 *
		 * @return Returns the number of AIML strings currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getAIMLStringListSize() const
			throw(Exception &) = 0;

		/**
		 * Returns the number of the currently loaded AIML strings in 
		 * the embedded database.
		 * 
		 * Call this to get how many AIML strings you have 
		 * loaded in the embedded database.  
		 *
		 * @param userId The user to get the number of AIML strings.
		 *
		 * @param botId The bot to get the number of AIML strings against.
		 *
		 * @param endUserId The end user requesting to get the AIML
		 * string size.
		 *
		 * @return Returns the number of AIML strings currently loaded
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getAIMLStringListSize(const StringPimpl &userId, 
			                                       const StringPimpl &botId, 
										           const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/**
		 * Returns an array of all the user id's in the embedded database.
		 * 
		 * Call this to get an array of the user id's of users 
		 * which have interacted with the embedded database.  
		 * When you are through with this array DO NOT call delete[] on it.  
		 * Instead pass this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of the user id's of all the users 
		 * that have interacted with the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getUserIds(unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Returns the number of user id's in the embedded database.
		 * 
		 * Call this to get the number of user id's of users which 
		 * have interacted with the embedded database.
		 *
		 * @return Returns the number of user id's which have interacted with
		 * the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getUserIdsSize() const
			throw(Exception &) = 0;

		/**
		 * Returns an array of all the bot id's of a particular user 
		 * in the embedded database.
		 * 
		 * Call this to get an array of the bot id's of a particular user.
		 * When you are through with this array DO NOT call delete[] on it.  
		 * Instead pass this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param userId The user of this bot.
		 * 
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of all the bot id's of a particular user
		 * in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getBotIds(const StringPimpl &userId, 
			                           unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Returns the number of bot id's for a particular user in 
		 * the embedded database.
		 * 
		 * Call this to get the number of bot id's of a particular user.
		 *
		 * @param userId The user of this bot.
         *
		 * @return Returns the number of bot id's for a particular user.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getBotIdsSize(const StringPimpl &userId) const
			throw(Exception &) = 0;

		/**
		 * Returns an array of all the end user id's of a particular user 
		 * and a particular bot of that user in the embedded database.
		 * 
		 * Call this to get an array of the end user id's of a particular user
		 * and a particular bot of that user.
		 * When you are through with this array DO NOT call delete[] on it.  
		 * Instead pass this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param userId The user of this end user.
		 *
		 * @param botId The bot in which this end user belongs to.
         *
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of all the end user id's of a particular user
		 * and a particular bot of that user in the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getEndUserIds(const StringPimpl &userId, 
			                               const StringPimpl &botId,
			                               unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Returns the number of end user id's of a particular user and 
		 * a particular bot of that user in the embedded database.  
		 * 
		 * Call this to get the number of end user id's of a particular user 
		 * and a particular bot of that user in the embedded database.
		 *
		 * @param userId The user this end user.
		 * 
		 * @param botId The bot in which this end user belongs to.
		 * 
		 * @return Returns the number of end user id's of a particular user 
		 * and a particular bot of that user in the embedded database.  
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getEndUserIdsSize(const StringPimpl &userId,
			                                   const StringPimpl &botId) const
			throw(Exception &) = 0;

		/**
		 * Prints the entire contents of the embedded database 
		 * as strings on standard out.
		 *
		 * This is mainly used for debugging and sending in-depth 
		 * bug reports.
		 */
		virtual void printEntireDatabase() const
			throw(Exception &) = 0;


		/**
		 * Returns an array of all the bot predicates in 
		 * the embedded database.
		 * 
		 * Call this to get an array of all the bot predicates 
		 * you have loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of all the bot predicates in 
		 * the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getBotPredicates(unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Returns an array of all the bot predicates in 
		 * the embedded database.
		 * 
		 * Call this to get an array of all the bot predicates 
		 * you have loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param userId The user to get the bot predicates of.
		 *
		 * @param botId The bot to get the bot predicates against.
		 *
		 * @param endUserId The end user requesting to get the 
		 * bot predicates.
		 * 
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of all the bot predicates in 
		 * the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getBotPredicates(const StringPimpl &userId, 
			                                  const StringPimpl &botId, 
											  const StringPimpl &endUserId, 
											  unsigned int &size) const
			throw(Exception &) = 0;
            
		/**
		 * Returns an array of all the predicates in 
		 * the embedded database.
		 * 
		 * Call this to get an array of all the predicates 
		 * you have loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of all the predicates in 
		 * the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getPredicates(unsigned int &size) const
			throw(Exception &) = 0;

		/**
		 * Returns an array of all the predicates in 
		 * the embedded database.
		 * 
		 * Call this to get an array of all the predicates 
		 * you have loaded into the embedded database.  When you are through
		 * with this array DO NOT call delete[] on it.  Instead pass
		 * this array to GraphBuilder::deleteStringPimplArray() to 
		 * delete the array and free the memory.
		 *
		 * @param userId The user to get the predicates of.
		 *
		 * @param botId The bot to get the predicates of.
		 *
		 * @param endUserId The end user to get the predicates against.
		 * 
		 * @param size Pass in this variable to get back the size 
		 * of the array.  Notice this is pass by non-const reference 
		 * which will give you the size of the array.
		 * 
		 * @return Returns an array of all the predicates in 
		 * the embedded database.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl *getPredicates(const StringPimpl &userId, 
			                               const StringPimpl &botId, 
										   const StringPimpl &endUserId, 
										   unsigned int &size) const
			throw(Exception &) = 0;


		/**
		 * Returns the number of predicates in the embedded database.
		 * 
		 * Call this to get the number of all the predicates 
		 * you have loaded into the embedded database.  
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getPredicatesSize() const
			throw(Exception &) = 0;

		/**
		 * Returns the number of predicates in the embedded database.
		 * 
		 * Call this to get the number of all the predicates 
		 * you have loaded into the embedded database.  
		 *
		 * @param userId The user to get the predicates of.
		 *
		 * @param botId The bot to get the predicates of.
		 *
		 * @param endUserId The end user to get the predicates against.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getPredicatesSize(const StringPimpl &userId, 
			                                   const StringPimpl &botId, 
									           const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/**
		 * Returns the number of bot predicates in the embedded database.
		 * 
		 * Call this to get the number of all the bot predicates 
		 * you have loaded into the embedded database.  
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getBotPredicatesSize() const
			throw(Exception &) = 0;
            
		/**
		 * Returns the number of bot predicates in the embedded database.
		 * 
		 * Call this to get the number of all the bot predicates 
		 * you have loaded into the embedded database.  
		 *
		 * @param userId The user to get the predicates of.
		 *
		 * @param botId The bot to get the predicates against.
		 *
		 * @param endUserId The end user requesting to get the 
		 * bot predicates.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual unsigned int getBotPredicatesSize(const StringPimpl &userId, 
			                                      const StringPimpl &botId, 
										          const StringPimpl &endUserId) const
			throw(Exception &) = 0;

		/**
		 * Removes a predicate from the embedded database.
		 * 
		 * @param name The name of the predicate to remove 
		 * from the embedded database.
         *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void removePredicate(const StringPimpl &name)
			throw(Exception &) = 0;

		/**
		 * Removes a predicate from the embedded database.
		 * 
		 * @param name The name of the predicate to remove 
		 * from the embedded database.
		 * 
		 * @param userId The user to remove the predicate from.
		 *
		 * @param botId The bot to remove the predicate from.
		 *
		 * @param endUserId The end user the predicate is removed
		 * against.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void removePredicate(const StringPimpl &name, 
								     const StringPimpl &userId,
								     const StringPimpl &botId,
								     const StringPimpl &endUserId)
			throw(Exception &) = 0;

		/**
		 * Removes a bot predicate from the embedded database.
		 * 
		 * @param name The name of the bot predicate to remove 
		 * from the embedded database.
         *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void removeBotPredicate(const StringPimpl &name)
			throw(Exception &) = 0;

		/**
		 * Removes a bot predicate from the embedded database.
		 * 
		 * @param name The name of the bot predicate to remove 
		 * from the embedded database.
		 * 
		 * @param userId The user to remove the bot predicate from.
		 *
		 * @param botId The bot the predicate is removed against. 
		 *
		 * @param endUserId The end user requesting the bot predicate
		 * be removed.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void removeBotPredicate(const StringPimpl &name, 
								        const StringPimpl &userId,
								        const StringPimpl &botId,
								        const StringPimpl &endUserId)
			throw(Exception &) = 0;

		/**
		 * Removes an end user from the embedded database.
		 *
		 * This causes the end user and all the end users's 
		 * predicates to be removed from the embedded database.
		 * 
		 * @param userId The user to remove the end user from.
		 *
		 * @param botId The bot the end user is removed from. 
		 *
		 * @param endUserId The end user to remove.
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void removeEndUser(const StringPimpl &userId,
			                       const StringPimpl &botId,
								   const StringPimpl &endUserId)
			throw(Exception &) = 0;

		/**
		 * Removes a user's bot from the embedded database.
		 *
		 * This causes all the bot's end users to be removed,
		 * all of the bot's loaded AIML files to be removed 
		 * through calls to GraphBuilder::removeGraph(), and 
		 * all of the bot's predicates to be removed along 
		 * with all the bot's end users' predicates.
		 *
		 * @param userId The user which owns this bot. 
		 *
		 * @param botId The bot to remove
		 * 
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void removeBot(const StringPimpl &userId,
			                   const StringPimpl &botId)
			throw(Exception &) = 0;

		/**
		 * Removes a user from the embedded database.
		 *
		 * This causes all of the user's bots to be removed.  
		 * Which means all of the user's bots' end users will be removed,
		 * all of the bots' loaded AIML files will be removed 
		 * through calls to GraphBuilder::removeGraph(), and 
		 * all of the bots' predicates will be removed along 
		 * with all of the bots' end users' predicates.
		 *
		 * @param userId The user to remove. 
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void removeUser(const StringPimpl &userId)
			throw(Exception &) = 0;
		
		/**
		 * Use this if you want to use thread specific 
		 * Id's or not.
		 *
		 * By default this is false.  Use this method to 
		 * turn this on before you spin up any threads if you 
		 * want thread specific id's.  With thread specific id's 
		 * each new thread which enters a method has its own copy of 
		 * the all the id's.  If you turn this on, you will want to 
		 * ensure you call all the methods which have the userId, 
		 * botId, and endUserId.  If you turn this on, you 
		 * DO NOT want to call any method which does not 
		 * take a userId, botId, endUserId.
		 *
		 * This method is mainly used for multi-threading.  It's 
		 * used in the case where if you have multiple threads 
		 * and different threads might have different user id's, bot id's
		 * or end user id's.  You would want to make a call to a 
		 * method with a userId, botId, endUserId from one thread and know
		 * that if the system switches threads to another in the middle 
		 * of processing with a different user id, bot id, or 
		 * end user id, it will not trump ontop of your first thread.
		 *
		 * @param trueOrFalse set this to true to use thread specific
		 * user id's, bot id's, and end user id's
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual void setThreadSpecificIds(bool trueOrFalse)
			throw(Exception &) = 0;

		/**
		 * Empty virtual destructor.
		 */
		virtual ~GraphBuilder() { };
};

} //end of namespace impl

//Expose GraphBuilder to rebecca namespace
using rebecca::impl::GraphBuilder;

} //end of namespace rebecca


#ifdef _WIN32
#    pragma warning ( pop )
#endif




#endif
