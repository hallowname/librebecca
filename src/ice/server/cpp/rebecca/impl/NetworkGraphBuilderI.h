#ifndef SERVER_NETWORKGRAPHBUILDERI_H
#define SERVER_NETWORKGRAPHBUILDERI_H

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
#include <rebecca/AimlFacade.h>
#include <rebecca/GraphBuilder.h>
#include <rebecca/impl/readServerSettings.h>
#include <rebecca/impl/ServerCallBacks.h>

//Ice includes
#include <Ice/Ice.h>
#include <Ice/Service.h>

//std includes
#include <sstream>
using namespace std;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif


namespace rebecca
{
namespace impl
{

class NetworkGraphBuilderI : public NetworkGraphBuilderIce
{
	public:

		NetworkGraphBuilderI(Ice::PropertiesPtr properties)
			: m_builder(m_aimlFacade.getGraphBuilder()),
			  m_properties(properties),
			  m_callbacks(Ice::Service::instance()->communicator()->getLogger(), m_aimlFacade.getGraphBuilder()),
			  m_shouldLog(false)
		{ 
			//Log out the properties and such
			Ice::LoggerPtr logger = Ice::Service::instance()->communicator()->getLogger();

			string aimlSchema = 
				m_properties->getPropertyWithDefault("Rebecca.Server.Config.AimlSchema", 
				                                     "../../resources/schema/AIML.xsd");
			string commonTypesSchema = 
				m_properties->getPropertyWithDefault("Rebecca.Server.Config.CommonTypesSchema", 
				                                     "../resources/schema/common-types.xsd");
			string botConfigurationSchema = 
				m_properties->getPropertyWithDefault("Rebecca.Server.Config.BotConfigurationSchema", 
				                                     "../resources/schema/bot-configuration.xsd");
			string substitutionFile = 
                m_properties->getPropertyWithDefault("Rebecca.Server.Config.SubstitutionFile",
				                                     "../../conf/substitutions.xml");
			string sentenceSplitterFile = 
				m_properties->getPropertyWithDefault("Rebecca.Server.Config.SentenceSplitterFile",
				                                     "../../conf/sentence-splitters.xml");
			string propertiesFile = 
				m_properties->getPropertyWithDefault("Rebecca.Server.Config.PropertiesFile",
				                                     "../../conf/properties.xml");
			string startupFile = 
				m_properties->getProperty("Rebecca.Server.Config.StartupFile");
			
			string shouldLog = 
				m_properties->getPropertyWithDefault("Rebecca.Server.Config.Logging", "false");

			//Set that we want the id's to be thread specific
			m_builder.setThreadSpecificIds(true);

			if(shouldLog == "true")
			{
				m_shouldLog = true;
				m_callbacks.setShouldLog(true);
			}

			int numThreads = m_properties->getPropertyAsInt("Ice.ThreadPool.Server.Size");
			if(numThreads < 2)
			{   
				if(m_shouldLog)
					logger->warning("Your threads should be at least 2, otherwise "
									"you risk dead lock issues!");
			}

			if(m_shouldLog)
			{
				logger->print("Property files and schemas loaded:\n"
							  "The AIML Schema:" + aimlSchema + "\n"
						      "The Common Types Schema:" + commonTypesSchema + "\n"
						      "The Bot Configuration Schema:" + botConfigurationSchema + "\n"
						      "The Substitution File:" + substitutionFile + "\n"
						      "The Sentence Splitter File:" + sentenceSplitterFile + "\n"
						      "The Properties File:" + propertiesFile);
			}
			m_builder.setCallBacks(&m_callbacks);
			m_builder.setAIMLSchema(aimlSchema.c_str());
			m_builder.setCommonTypesSchema(commonTypesSchema.c_str());
			m_builder.setBotConfigurationSchema(botConfigurationSchema.c_str());				
            m_builder.setAIMLValidation();
            m_builder.setBotConfigurationValidation();
            m_builder.parseSubstitutionFile(substitutionFile.c_str());
            m_builder.parseSentenceSplitterFile(sentenceSplitterFile.c_str());				
		    m_builder.parsePropertiesFile(propertiesFile.c_str());
			
			if(!startupFile.empty())
			{
				readSettings(startupFile, m_builder, logger, m_shouldLog);
			}
		}

		virtual void addFile(const ::std::string& file,
							 const ::std::string& userId,
							 const ::std::string& botId,
							 const ::std::string& endUserId,
			                 const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				string fileStr = convertToString(IceUtil::stringToWstring(file));
				m_builder.addFile(fileStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}		

		virtual void addFileUnlessAlreadyAdded(const ::std::string& file, 
			                                   const ::std::string& userId, 
											   const ::std::string& botId, 
											   const ::std::string& endUserId, 
											   const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string fileStr = convertToString(IceUtil::stringToWstring(file));
				m_builder.addFileUnlessAlreadyAdded(fileStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeFile(const ::std::string& file,
							    const ::std::string& userId,
							    const ::std::string& botId,
							    const ::std::string& endUserId,
			                    const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				string fileStr = convertToString(IceUtil::stringToWstring(file));
				m_builder.removeFile(fileStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}		


		virtual void addDirectory(const ::std::string& directory, 
							      const ::std::string& userId,
							      const ::std::string& botId,
							      const ::std::string& endUserId,
			                      const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string dirStr = convertToString(IceUtil::stringToWstring(directory));
				m_builder.addDirectory(dirStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(DirectoryNotFoundException &e)
			{
				throw DirectoryNotFoundExceptionIce(e.what());				
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void addDirectoryUnlessAlreadyAdded(const ::std::string& directory, 
			                                        const ::std::string& userId, 
													const ::std::string& botId, 
													const ::std::string& endUserId, 
													const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string dirStr = convertToString(IceUtil::stringToWstring(directory));
				m_builder.addDirectoryUnlessAlreadyAdded(dirStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(DirectoryNotFoundException &e)
			{
				throw DirectoryNotFoundExceptionIce(e.what());				
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeDirectory(const ::std::string& directory, 
							         const ::std::string& userId,
							         const ::std::string& botId,
							         const ::std::string& endUserId,
			                         const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string dirStr = convertToString(IceUtil::stringToWstring(directory));
				m_builder.removeDirectory(dirStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(DirectoryNotFoundException &e)
			{
				throw DirectoryNotFoundExceptionIce(e.what());				
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

        virtual void addDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory,
			                                                        const ::std::string& regularExpression, 
							                                        const ::std::string& userId,
							                                        const ::std::string& botId,
							                                        const ::std::string& endUserId,
																	const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string dirStr = convertToString(IceUtil::stringToWstring(directory));
				m_builder.addDirectory(dirStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str(), regularExpression.c_str());
			}
			catch(DirectoryNotFoundException &e)
			{
				throw DirectoryNotFoundExceptionIce(e.what());				
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string& directory, 
			                                                                          const ::std::string& regularExpression, 
																					  const ::std::string& userId, 
																					  const ::std::string& botId, 
																					  const ::std::string& endUserId, 
																					  const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string dirStr = convertToString(IceUtil::stringToWstring(directory));
				m_builder.addDirectoryUnlessAlreadyAdded(dirStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str(), regularExpression.c_str());
			}
			catch(DirectoryNotFoundException &e)
			{
				throw DirectoryNotFoundExceptionIce(e.what());				
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

        virtual void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory,
			                                                           const ::std::string& regularExpression, 
							                                           const ::std::string& userId,
							                                           const ::std::string& botId,
							                                           const ::std::string& endUserId,
																	   const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string dirStr = convertToString(IceUtil::stringToWstring(directory));
				m_builder.removeDirectory(dirStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str(), regularExpression.c_str());
			}
			catch(DirectoryNotFoundException &e)
			{
				throw DirectoryNotFoundExceptionIce(e.what());				
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void addString(const ::std::string& stringContainingAIML, 
                               const ::std::string& userId,
                               const ::std::string& botId,
                               const ::std::string& endUserId,
			                   const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				string stringContainingAIMLStr = convertToString(IceUtil::stringToWstring(stringContainingAIML));
				m_builder.addString(stringContainingAIMLStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeString(const ::std::string& stringContainingAIML, 
                                  const ::std::string& userId,
                                  const ::std::string& botId,
                                  const ::std::string& endUserId,
			                      const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				string stringContainingAIMLStr = convertToString(IceUtil::stringToWstring(stringContainingAIML));
				m_builder.removeString(stringContainingAIMLStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setAddStringAIMLHeader(const ::std::string& aimlHeader,
			                                const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				m_builder.setAddStringAIMLHeader(aimlHeader.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setAddStringAIMLFooter(const ::std::string& aimlFooter,
			                                const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				m_builder.setAddStringAIMLFooter(aimlFooter.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setAIMLSchema(const ::std::string& schema,
			                       const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string schemaStr = convertToString(IceUtil::stringToWstring(schema));
				m_builder.setAIMLSchema(schemaStr.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setCommonTypesSchema(const ::std::string& schema,
			                              const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string schemaStr = convertToString(IceUtil::stringToWstring(schema));
				m_builder.setCommonTypesSchema(schemaStr.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setAIMLValidation(bool trueOrFalse,
			                           const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				m_builder.setAIMLValidation(trueOrFalse);
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual ::std::string getResponse(const ::std::string& input,
                                          const ::std::string& userId,
                                          const ::std::string& botId,
                                          const ::std::string& endUserId,
			                              const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string inputStr = convertToString(IceUtil::stringToWstring(input));
				StringPimpl responseStr = m_builder.getResponse(inputStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
				return IceUtil::wstringToString(convertToWstring(responseStr));
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual void setThat(const ::std::string& that,
                             const ::std::string& userId,
                             const ::std::string& botId,
                             const ::std::string& endUserId,
			                 const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string thatStr = convertToString(IceUtil::stringToWstring(that));
				m_builder.setThat(thatStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setTopic(const ::std::string& topic,
                              const ::std::string& userId,
                              const ::std::string& botId,
                              const ::std::string& endUserId,
			                  const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string topicStr = convertToString(IceUtil::stringToWstring(topic));
				m_builder.setTopic(topicStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::std::string getThat(const ::std::string& userId,
                                      const ::std::string& botId,
                                      const ::std::string& endUserId,
			                          const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				StringPimpl thatStr = m_builder.getThat(userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
				return IceUtil::wstringToString(convertToWstring(thatStr));
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::std::string getTopic(const ::std::string& userId,
                                       const ::std::string& botId,
                                       const ::std::string& endUserId,
			const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				StringPimpl topicStr = m_builder.getTopic(userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
				return IceUtil::wstringToString(convertToWstring(topicStr));
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void createGraph(const ::std::string& userId,
                                 const ::std::string& botId,
                                 const ::std::string& endUserId,
			                     const ::Ice::Current& = ::Ice::Current()) 
		{  
			try
			{
				m_builder.createGraph(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeGraph(const ::std::string& userId,
                                 const ::std::string& botId,
                                 const ::std::string& endUserId,
			                     const ::Ice::Current& = ::Ice::Current()) 
		{  
			try
			{
				m_builder.removeGraph(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual bool predicateMatch(const ::std::string& predicateName, 
			                        const ::std::string& aimlPattern,
                                    const ::std::string& userId,
                                    const ::std::string& botId,
                                    const ::std::string& endUserId,
									const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				string predicateNameStr = convertToString(IceUtil::stringToWstring(predicateName));
				string aimlPatternStr = convertToString(IceUtil::stringToWstring(aimlPattern));
				return m_builder.predicateMatch(predicateNameStr.c_str(), aimlPatternStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual void setPredicate(const ::std::string& name, 
			                      const ::std::string& value,
                                  const ::std::string& userId,
                                  const ::std::string& botId,
                                  const ::std::string& endUserId,
								  const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string nameStr = convertToString(IceUtil::stringToWstring(name));
				string valueStr = convertToString(IceUtil::stringToWstring(value));
				m_builder.setPredicate(nameStr.c_str(), valueStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::std::string getPredicate(const ::std::string& name,
                                           const ::std::string& userId,
                                           const ::std::string& botId,
                                           const ::std::string& endUserId,
			                               const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				string nameStr = convertToString(IceUtil::stringToWstring(name));
				StringPimpl predicateStr = m_builder.getPredicate(nameStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
				return IceUtil::wstringToString(convertToWstring(predicateStr));
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::std::string getBotPredicate(const ::std::string& name,
                                              const ::std::string& userId,
                                              const ::std::string& botId,
                                              const ::std::string& endUserId,
			                                  const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				string nameStr = convertToString(IceUtil::stringToWstring(name));
				return m_builder.getBotPredicate(nameStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setBotPredicate(const ::std::string& name, 
			                         const ::std::string& value,
                                     const ::std::string& userId,
                                     const ::std::string& botId,
                                     const ::std::string& endUserId,
									 const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string nameStr = convertToString(IceUtil::stringToWstring(name));
				string valueStr = convertToString(IceUtil::stringToWstring(value));
				m_builder.setBotPredicate(nameStr.c_str(), valueStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
				
		virtual ::std::string getPreviousBotResponse(::Ice::Int previousBotResponse, 
			                                         ::Ice::Int sentence,
                                                     const ::std::string& userId,
                                                     const ::std::string& botId,
                                                     const ::std::string& endUserId,
												     const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				StringPimpl previousBotResponseStr = 
					m_builder.getPreviousBotResponse(previousBotResponse, sentence, userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
				return IceUtil::wstringToString(convertToWstring(previousBotResponseStr));
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::std::string getPreviousUserInput(::Ice::Int previousUserInput, 
			                                       ::Ice::Int sentence,
                                                   const ::std::string& userId,
                                                   const ::std::string& botId,
                                                   const ::std::string& endUserId,
												   const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				StringPimpl previousUserInputStr = 
					m_builder.getPreviousUserInput(previousUserInput, sentence, userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
				return IceUtil::wstringToString(convertToWstring(previousUserInputStr));
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual void setBotConfigurationSchema(const ::std::string& schema,
			                                   const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string schemaStr = convertToString(IceUtil::stringToWstring(schema));
				m_builder.setBotConfigurationSchema(schemaStr.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setBotConfigurationValidation(bool trueOrFalse,
			                                       const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				m_builder.setBotConfigurationValidation(trueOrFalse);
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void parseSubstitutionFile(const ::std::string& fileName,
			                               const ::Ice::Current& = ::Ice::Current()) 
		{  
			try
			{
				string fileNameStr = convertToString(IceUtil::stringToWstring(fileName));
				m_builder.parseSubstitutionFile(fileNameStr.c_str());
			}
			catch(XMLErrorException &e)
			{
				throw XMLErrorExceptionIce(e.what());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void parseSentenceSplitterFile(const ::std::string& fileName,
			                                   const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string fileNameStr = convertToString(IceUtil::stringToWstring(fileName));
				m_builder.parseSentenceSplitterFile(fileNameStr.c_str());
			}
			catch(XMLErrorException &e)
			{
				throw XMLErrorExceptionIce(e.what());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void parsePropertiesFile(const ::std::string& fileName, 
			                             const ::std::string& userId, 
										 const ::std::string& botId, 
										 const ::std::string& endUserId, 
										 const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string fileNameStr = convertToString(IceUtil::stringToWstring(fileName));
				m_builder.parsePropertiesFile(fileNameStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(XMLErrorException &e)
			{
				throw XMLErrorExceptionIce(e.what());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setSentenceSplitter(const ::std::string& splitter,
			                             const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string splitterStr = convertToString(IceUtil::stringToWstring(splitter));
				m_builder.setSentenceSplitter(splitterStr.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setInputSubstitution(const ::std::string& find, 
			                              const ::std::string& replace,
										  const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string findStr = convertToString(IceUtil::stringToWstring(find));
				string replaceStr = convertToString(IceUtil::stringToWstring(replace));
				m_builder.setInputSubstitution(findStr.c_str(), replaceStr.c_str());
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setGenderSubstitution(const ::std::string& find, 
			                               const ::std::string& replace,
										   const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string findStr = convertToString(IceUtil::stringToWstring(find));
				string replaceStr = convertToString(IceUtil::stringToWstring(replace));
				m_builder.setGenderSubstitution(findStr.c_str(), replaceStr.c_str());
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setPersonSubstitution(const ::std::string& find, 
			                               const ::std::string& replace,
										   const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string findStr = convertToString(IceUtil::stringToWstring(find));
				string replaceStr = convertToString(IceUtil::stringToWstring(replace));
				m_builder.setPersonSubstitution(findStr.c_str(), replaceStr.c_str());
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setPerson2Substitution(const ::std::string& find, 
			                                const ::std::string& replace,
											const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string findStr = convertToString(IceUtil::stringToWstring(find));
				string replaceStr = convertToString(IceUtil::stringToWstring(replace));
				m_builder.setPerson2Substitution(findStr.c_str(), replaceStr.c_str());
			}
			catch(IllegalArgumentException &e)
			{
				throw IllegalArgumentExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual ::std::string getVersion(const ::Ice::Current& = ::Ice::Current()) const 
		{ 
			try
			{
				return m_builder.getVersion().c_str();
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual ::Ice::Int getSize(const ::std::string& userId, 
			                       const ::std::string& botId, 
								   const ::std::string& endUserId, 
			                       const ::Ice::Current& = ::Ice::Current()) const 
		{ 
			try
			{
				return m_builder.getSize(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void setCallBacks(const ::std::string& name, 
			                      const ::std::string& category, 
								  const ::Ice::Current& current = ::Ice::Current())
		{
			Ice::Identity ident;
			ident.name = name;
			ident.category = category;
			m_remoteCallbacks =
				CallBacksIcePrx::uncheckedCast(current.con->createProxy(ident)->ice_oneway());
			m_callbacks.setLocalCallBack(m_remoteCallbacks);
		}

		virtual void storeGossip(const ::std::string& gossip, 
			                     const ::Ice::Current& = ::Ice::Current()) 
		{ 
			try
			{
				string gossipStr = convertToString(IceUtil::stringToWstring(gossip));
				return m_builder.storeGossip(gossipStr.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual ::std::string getId(const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				return m_builder.getId().c_str();
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual void addCustomTagLibrary(const ::std::string& library,
			                             const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				m_builder.addCustomTagLibrary(library.c_str());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeCustomTagLibrary(const ::std::string& library,
			                                const ::Ice::Current& = ::Ice::Current())
		{ 
			try
			{
				m_builder.removeCustomTagLibrary(library.c_str());
			}
			catch(FileNotFoundException &e)
			{
				throw FileNotFoundExceptionIce(e.what());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}
		
		virtual ::std::string callSystemCommand(const ::std::string& command,
			                                    const ::Ice::Current& = ::Ice::Current()) const
		{ 
			try
			{
				return m_builder.callSystemCommand(command.c_str()).c_str();
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void synchronizeDatabase(const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.synchronizeDatabase();
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string& userId, 
			                                               const ::std::string& botId, 
														   const ::std::string& endUserId, 
														   const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				StringSeq sequence;
				unsigned int size;
				StringPimpl *arrayList = m_builder.getAIMLFileList(userId.c_str(), botId.c_str(), endUserId.c_str(), size);
				for(unsigned i = 0; i < size; ++i)
				{
					string str = IceUtil::wstringToString(convertToWstring(arrayList[i]));
					sequence.push_back(str);
				}
				m_builder.deleteStringPimplArray(arrayList);
				return sequence;
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::Ice::Int getAIMLFileListSize(const ::std::string& userId, 
			                                   const ::std::string& botId, 
											   const ::std::string& endUserId, 
											   const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.getAIMLFileListSize(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string& userId, 
			                                                 const ::std::string& botId, 
														     const ::std::string& endUserId, 
														     const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				StringSeq sequence;
				unsigned int size;
				StringPimpl *arrayList = m_builder.getAIMLStringList(userId.c_str(), botId.c_str(), endUserId.c_str(), size);
				for(unsigned i = 0; i < size; ++i)
				{
					string str = IceUtil::wstringToString(convertToWstring(arrayList[i]));
					sequence.push_back(str);
				}
				m_builder.deleteStringPimplArray(arrayList);
				return sequence;
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::Ice::Int getAIMLStringListSize(const ::std::string& userId, 
			                                     const ::std::string& botId, 
											     const ::std::string& endUserId, 
											     const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.getAIMLStringListSize(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::rebecca::impl::StringSeq getUserIds(const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				StringSeq sequence;
				unsigned int size;
				StringPimpl *arrayList = m_builder.getUserIds(size);
				for(unsigned i = 0; i < size; ++i)
				{
					sequence.push_back(arrayList[i].c_str());
				}
				m_builder.deleteStringPimplArray(arrayList);
				return sequence;
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::Ice::Int getUserIdsSize(const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.getUserIdsSize();
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::rebecca::impl::StringSeq getBotIds(const ::std::string& userId, const ::Ice::Current& = ::Ice::Current()) const
		{

			try
			{
				StringSeq sequence;
				unsigned int size;
				StringPimpl *arrayList = m_builder.getBotIds(userId.c_str(), size);
				for(unsigned i = 0; i < size; ++i)
				{
					sequence.push_back(arrayList[i].c_str());
				}
				m_builder.deleteStringPimplArray(arrayList);
				return sequence;
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::Ice::Int getBotIdsSize(const ::std::string& userId, const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.getBotIdsSize(userId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::rebecca::impl::StringSeq getEndUserIds(const ::std::string& userId, 
			                                             const ::std::string& botId, 
														 const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				StringSeq sequence;
				unsigned int size;
				StringPimpl *arrayList = m_builder.getEndUserIds(userId.c_str(), botId.c_str(), size);
				for(unsigned i = 0; i < size; ++i)
				{
					sequence.push_back(arrayList[i].c_str());
				}
				m_builder.deleteStringPimplArray(arrayList);
				return sequence;
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::Ice::Int getEndUserIdsSize(const ::std::string& userId, 
			                                 const ::std::string& botId, 
											 const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.getEndUserIdsSize(userId.c_str(), botId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void printEntireDatabase(const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.printEntireDatabase();
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::rebecca::impl::StringSeq getBotPredicates(const ::std::string& userId, 
			                                                const ::std::string& botId, 
											                const ::std::string& endUserId, 
			                                                const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				StringSeq sequence;
				unsigned int size;
				StringPimpl *arrayList = m_builder.getBotPredicates(userId.c_str(), botId.c_str(), endUserId.c_str(), size);
				for(unsigned i = 0; i < size; ++i)
				{
					string str = IceUtil::wstringToString(convertToWstring(arrayList[i]));
					sequence.push_back(str);
				}
				m_builder.deleteStringPimplArray(arrayList);
				return sequence;
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::rebecca::impl::StringSeq getPredicates(const ::std::string& userId, 
			                                             const ::std::string& botId, 
											             const ::std::string& endUserId, 
			                                             const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				StringSeq sequence;
				unsigned int size;
				StringPimpl *arrayList = m_builder.getPredicates(userId.c_str(), botId.c_str(), endUserId.c_str(), size);
				for(unsigned i = 0; i < size; ++i)
				{
					string str = IceUtil::wstringToString(convertToWstring(arrayList[i]));
					sequence.push_back(str);
				}
				m_builder.deleteStringPimplArray(arrayList);
				return sequence;
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::Ice::Int getBotPredicatesSize(const ::std::string& userId, 
			                                    const ::std::string& botId, 
												const ::std::string& endUserId, 
												const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.getBotPredicatesSize(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual ::Ice::Int getPredicatesSize(const ::std::string& userId, 
			                                 const ::std::string& botId, 
											 const ::std::string& endUserId, 
											 const ::Ice::Current& = ::Ice::Current()) const
		{
			try
			{
				return m_builder.getPredicatesSize(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removePredicate(const ::std::string& name,
									 const ::std::string& userId, 
									 const ::std::string& botId, 
									 const ::std::string& endUserId, 
									 const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string nameStr = convertToString(IceUtil::stringToWstring(name));
				m_builder.removePredicate(nameStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeBotPredicate(const ::std::string& name,
									    const ::std::string& userId, 
									    const ::std::string& botId, 
									    const ::std::string& endUserId, 
									    const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				string nameStr = convertToString(IceUtil::stringToWstring(name));
				m_builder.removeBotPredicate(nameStr.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeEndUser(const ::std::string& userId, 
			                       const ::std::string& botId, 
								   const ::std::string& endUserId, 
								   const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				return m_builder.removeEndUser(userId.c_str(), botId.c_str(), endUserId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeBot(const ::std::string& userId, 
			                   const ::std::string& botId, 
                               const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				return m_builder.removeBot(userId.c_str(), botId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}

		virtual void removeUser(const ::std::string& userId, 
                                const ::Ice::Current& = ::Ice::Current())
		{
			try
			{
				return m_builder.removeUser(userId.c_str());
			}
			catch(Exception &e)
			{
				throw ExceptionIce(e.what());
			}
		}


	private:

		AimlFacade m_aimlFacade;
		GraphBuilder &m_builder;
		Ice::PropertiesPtr m_properties;
		CallBacksIcePrx m_remoteCallbacks;
		MyCallBacks m_callbacks;
		bool m_shouldLog;

		wstring convertToWstring(const StringPimpl &narrow) const
		{
			wchar_t *wchar = new wchar_t[narrow.length() + 1];
			mbstowcs(wchar, narrow.c_str(), narrow.length());
			wchar[narrow.length()] = '\0';
			wstring ws(wchar);
			delete[] wchar;
			return ws;
		}

		string convertToString(const wstring &wide) const
		{
			char *nchar = new char[wide.length() + 1];
			wcstombs(nchar, wide.c_str(), wide.length());
			nchar[wide.length()] = '\0';
			string s(nchar);
			delete[] nchar;
			return s;
		}
};

} //end of impl namespace
} //end of rebecca namespace

#ifdef _WIN32
#    pragma warning ( pop )
#endif


#endif


