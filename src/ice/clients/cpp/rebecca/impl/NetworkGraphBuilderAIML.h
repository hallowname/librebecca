#ifndef REBECCA_NETWORKGRAPHBUILDERAIML_H
#define REBECCA_NETWORKGRAPHBUILDERAIML_H

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

//rebecca includes
#include <rebecca/NetworkGraphBuilder.h>

//Ice includes
#include <Ice/Ice.h>

//rebecca ice generated includes
#include <rebecca/impl/network.h>
#include <rebecca/impl/NetworkCallBacks.h>


namespace rebecca
{
namespace impl
{

class NetworkGraphBuilderAIML : public NetworkGraphBuilder
{

	public:
		
		NetworkGraphBuilderAIML(int argc, char *argv[])
			throw(NetworkException, Exception);

		virtual StringPimpl getProperty(const StringPimpl &key) const
			throw(Exception &);

		virtual StringPimpl getPropertyWithDefault(const StringPimpl &key, const StringPimpl &value) const
			throw(Exception &);

		virtual int getPropertyAsInt(const StringPimpl &key) const
			throw(Exception &);

		virtual int getPropertyAsIntWithDefault(const StringPimpl &key, int value) const
			throw(Exception &);

		virtual void addFile(const StringPimpl &file) 
			throw(FileNotFoundException &, Exception &);

		virtual void addFile(const StringPimpl &file,
							 const StringPimpl &userId,
							 const StringPimpl &botId,
							 const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &);

		virtual void addDirectory(const StringPimpl &directory, const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &); 

		virtual void addDirectory(const StringPimpl &directory, 
			                      const StringPimpl &userId, 
								  const StringPimpl &botId,
								  const StringPimpl &endUserId,
			                      const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void addString(const StringPimpl &stringContainingAIML)
			throw(Exception &);

		virtual void addString(const StringPimpl &stringContainingAIML,
			                   const StringPimpl &userId,
							   const StringPimpl &botId,
							   const StringPimpl &endUserId)
			throw(Exception &);

		virtual void setAddStringAIMLHeader(const StringPimpl &aimlHeader)
			throw(Exception &);

		virtual void setAddStringAIMLFooter(const StringPimpl &aimlFooter)
			throw(Exception &);

		virtual void setAIMLSchema(const StringPimpl &schema) 
			throw(Exception &, FileNotFoundException &);

		virtual void setCommonTypesSchema(const StringPimpl &schema) 
			throw(Exception &, FileNotFoundException &);

		virtual void setAIMLValidation(bool trueOrFalse = true) 
			throw(Exception &);

		virtual StringPimpl getResponse(const StringPimpl &input, 
			                            const StringPimpl &userId, 
										const StringPimpl &botId,
										const StringPimpl &endUserId) 
			throw(Exception &);

		virtual StringPimpl getResponse(const StringPimpl &input) 
			throw(Exception &);
		
		virtual void setThat(const StringPimpl &that) 
			throw(Exception &);

		virtual void setThat(const StringPimpl &that,
			                 const StringPimpl &userId,
							 const StringPimpl &botId,
							 const StringPimpl &endUserId) 
			throw(Exception &);

		virtual void setTopic(const StringPimpl &topic) 
			throw(Exception &);

		virtual void setTopic(const StringPimpl &topic,
			                  const StringPimpl &userId,
							  const StringPimpl &botId,
							  const StringPimpl &endUserId) 
			throw(Exception &);

		virtual StringPimpl getThat() const
			throw(Exception &);

		virtual StringPimpl getThat(const StringPimpl &userId,
			                        const StringPimpl &botId,
									const StringPimpl &endUserId) const
			throw(Exception &);

		virtual StringPimpl getTopic() const
			throw(Exception &);

		virtual StringPimpl getTopic(const StringPimpl &userId,
			                         const StringPimpl &botId,
									 const StringPimpl &endUserId) const
			throw(Exception &);

		virtual void createGraph() 
			throw(XMLErrorException &, Exception &);

		virtual void createGraph(const StringPimpl &userId,
						         const StringPimpl &botId,
								 const StringPimpl &endUserId) 
			throw(XMLErrorException &, Exception &);

		virtual bool predicateMatch(const StringPimpl &predicateName, 
			                        const StringPimpl &aimlPattern) const
			throw(Exception &); 
		
		virtual bool predicateMatch(const StringPimpl &predicateName, 
			                        const StringPimpl &aimlPattern,
									const StringPimpl &userId,
									const StringPimpl &botId,
									const StringPimpl &endUserId) const
			throw(Exception &);

		virtual void setPredicate(const StringPimpl &name, 
			                      const StringPimpl &value) 
			throw(Exception &);

		virtual void setPredicate(const StringPimpl &name, 
			                      const StringPimpl &value,
								  const StringPimpl &userId,
								  const StringPimpl &botId,
								  const StringPimpl &endUserId) 
			throw(Exception &);

		virtual StringPimpl getPredicate(const StringPimpl &name) const
			throw(Exception &);

		virtual StringPimpl getPredicate(const StringPimpl &name,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId) const
			throw(Exception &);

		virtual StringPimpl getBotPredicate(const StringPimpl &name) const
			throw(Exception &);

		virtual StringPimpl getBotPredicate(const StringPimpl &name,
			                                const StringPimpl &userId,
											const StringPimpl &botId,
											const StringPimpl &endUserId) const
			throw(Exception &);

		virtual void setBotPredicate(const StringPimpl &name, 
			                         const StringPimpl &value) 
			throw(Exception &);

		virtual void setBotPredicate(const StringPimpl &name, 
			                         const StringPimpl &value,
									 const StringPimpl &userId,
									 const StringPimpl &botId,
									 const StringPimpl &endUserId) 
			throw(Exception &);

		virtual StringPimpl getPreviousBotResponse(const unsigned int &previousBotResponse, 
			                                       const unsigned int &sentence) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getPreviousBotResponse(const unsigned int &previousBotResponse, 
			                                       const unsigned int &sentence,
												   const StringPimpl &userId,
												   const StringPimpl &botId,
												   const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getPreviousUserInput(const unsigned int &previousUserInput, 
			                                     const unsigned int &sentence) const
			throw(IllegalArgumentException &, Exception &);
		
		virtual void setBotConfigurationSchema(const StringPimpl &schema) 
			throw(Exception &, FileNotFoundException &);

		virtual void setBotConfigurationValidation(const bool trueOrFalse = true) 
			throw(Exception &);

		virtual void parseSubstitutionFile(const StringPimpl &fileName) 
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

		virtual void parseSentenceSplitterFile(const StringPimpl &fileName) 
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

		virtual void parsePropertiesFile(const StringPimpl &fileName,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId)
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

		virtual void parsePropertiesFile(const StringPimpl &fileName)
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

		virtual void setSentenceSplitter(const StringPimpl &splitter) 
			throw(Exception &);

		virtual void setInputSubstitution(const StringPimpl &find, const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &);

		virtual void setGenderSubstitution(const StringPimpl &find, const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &);

		virtual void setPersonSubstitution(const StringPimpl &find, const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &);

		virtual void setPerson2Substitution(const StringPimpl &find, const StringPimpl &replace) 
			throw(IllegalArgumentException &, Exception &);
		
		virtual StringPimpl getVersion() const 
			throw(Exception &);
		
		virtual int getSize() const 
			throw(Exception &);

		virtual int getSize(const StringPimpl &userId,
			                const StringPimpl  &botId,
							const StringPimpl &endUserId) const 
			throw(Exception &);
		
		virtual void setCallBacks(CallBacks *callBacks) 
			throw(Exception &);

		virtual void storeGossip(const StringPimpl &gossip) 
			throw(Exception &);
		
		virtual StringPimpl getId() const
			throw(Exception &);
		
		virtual void setUserIdBotIdEndUserId(const StringPimpl &userId, 
			                                 const StringPimpl &botId,
											 const StringPimpl &endUserId)
			throw(Exception &);

		virtual void addCustomTagLibrary(const StringPimpl &library)
			throw(FileNotFoundException &, Exception &);

		virtual void removeCustomTagLibrary(const StringPimpl &library)
			throw(FileNotFoundException &, Exception &);
		
		virtual StringPimpl callSystemCommand(const StringPimpl &command) const
			throw(Exception &);

		virtual void destroy()
			throw(Exception &);

		virtual void synchronizeDatabase() const
			throw(Exception &);

//		virtual void setDBEnvironmentDirectory(const StringPimpl &directory)
//			throw(Exception &);
		virtual void removeFile(const StringPimpl &file,
			                    const StringPimpl &userId,
							    const StringPimpl &botId,
							    const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &);		

		virtual void removeFile(const StringPimpl &file) 
			throw(FileNotFoundException &, Exception &);		

		virtual void removeDirectory(const StringPimpl &directory, 
			                      const StringPimpl &userId, 
								  const StringPimpl &botId,
								  const StringPimpl &endUserId,
			                      const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void removeDirectory(const StringPimpl &directory, 
			                      const StringPimpl &regularExpression = ".*\\.aiml") 
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void removeString(const StringPimpl &stringContainingAIML,
			                   const StringPimpl &userId,
							   const StringPimpl &botId,
							   const StringPimpl &endUserId)
			throw(Exception &);

		virtual void removeString(const StringPimpl &stringContainingAIML)
			throw(Exception &);

		virtual void removeGraph(const StringPimpl &userId,
			                     const StringPimpl &botId,
								 const StringPimpl &endUserId) 
			throw(XMLErrorException &, Exception &);

		virtual void removeGraph() 
			throw(XMLErrorException &, Exception &);

		virtual StringPimpl *getAIMLFileList(const StringPimpl &userId, 
			                                 const StringPimpl &botId, 
											 const StringPimpl &endUserId,
											 unsigned int &size) const
			throw(Exception &);

		virtual void deleteStringPimplArray(StringPimpl *arrayToDelete) const
			throw(Exception &);

		virtual unsigned int getAIMLFileListSize(const StringPimpl &userId, 
			                                     const StringPimpl &botId, 
										         const StringPimpl &endUserId) const
			throw(Exception &);

		virtual StringPimpl *getAIMLFileList(unsigned int &size) const
			throw(Exception &);

		virtual unsigned int getAIMLFileListSize() const
			throw(Exception &);

		virtual StringPimpl *getAIMLStringList(const StringPimpl &userId, 
			                                   const StringPimpl &botId, 
											   const StringPimpl &endUserId,
											   unsigned int &size) const
			throw(Exception &);

		virtual unsigned int getAIMLStringListSize(const StringPimpl &userId, 
			                                       const StringPimpl &botId, 
										           const StringPimpl &endUserId) const
			throw(Exception &);

		virtual StringPimpl *getAIMLStringList(unsigned int &size) const
			throw(Exception &);

		virtual unsigned int getAIMLStringListSize() const
			throw(Exception &);

		virtual StringPimpl *getUserIds(unsigned int &size) const
			throw(Exception &);

		virtual unsigned int getUserIdsSize() const
			throw(Exception &);

		virtual StringPimpl *getBotIds(const StringPimpl &userId, 
			                           unsigned int &size) const
			throw(Exception &);

		virtual unsigned int getBotIdsSize(const StringPimpl &userId) const
			throw(Exception &);

		virtual StringPimpl *getEndUserIds(const StringPimpl &userId, 
			                               const StringPimpl &botId,
			                               unsigned int &size) const
			throw(Exception &);

		virtual unsigned int getEndUserIdsSize(const StringPimpl &userId,
			                               const StringPimpl &botId) const
			throw(Exception &);

		virtual void printEntireDatabase() const
			throw(Exception &);

		virtual StringPimpl *getBotPredicates(unsigned int &size) const
			throw(Exception &);

		virtual StringPimpl *getPredicates(unsigned int &size) const
			throw(Exception &);

		virtual StringPimpl *getPredicates(const StringPimpl &userId, 
			                               const StringPimpl &botId, 
										   const StringPimpl &endUserId, 
										   unsigned int &size) const
			throw(Exception &);

		virtual StringPimpl *getBotPredicates(const StringPimpl &userId, 
			                                  const StringPimpl &botId, 
											  const StringPimpl &endUserId, 
											  unsigned int &size) const
			throw(Exception &);

		virtual unsigned int getPredicatesSize(const StringPimpl &userId, 
			                                   const StringPimpl &botId, 
									           const StringPimpl &endUserId) const
			throw(Exception &);

		virtual unsigned int getBotPredicatesSize(const StringPimpl &userId, 
			                                      const StringPimpl &botId, 
										          const StringPimpl &endUserId) const
			throw(Exception &);

		virtual unsigned int getPredicatesSize() const
			throw(Exception &);

		virtual unsigned int getBotPredicatesSize() const
			throw(Exception &);

		virtual void removePredicate(const StringPimpl &name)
			throw(Exception &);

		virtual void removePredicate(const StringPimpl &name, 
								     const StringPimpl &userId,
								     const StringPimpl &botId,
								     const StringPimpl &endUserId)
			throw(Exception &);

		virtual void removeBotPredicate(const StringPimpl &name)
			throw(Exception &);

		virtual void removeBotPredicate(const StringPimpl &name, 
								        const StringPimpl &userId,
								        const StringPimpl &botId,
								        const StringPimpl &endUserId)
			throw(Exception &);

		virtual void removeEndUser(const StringPimpl &userId,
			                       const StringPimpl &botId,
								   const StringPimpl &endUserId)
			throw(Exception &);

		virtual void removeBot(const StringPimpl &userId,
			                   const StringPimpl &botId)
			throw(Exception &);

		virtual void removeUser(const StringPimpl &userId)
			throw(Exception &);

		virtual void setThreadSpecificIds(bool trueOrFalse)
			throw(Exception &);

		virtual void addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
			                                        const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
			                                        const StringPimpl &userId, 
								                    const StringPimpl &botId,
								                    const StringPimpl &endUserId,
								                    const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void addFileUnlessAlreadyAdded(const StringPimpl &file)
			throw(FileNotFoundException &, Exception &);	

		virtual void addFileUnlessAlreadyAdded(const StringPimpl &file,
			                                   const StringPimpl &userId,
							                   const StringPimpl &botId,
							                   const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &);		

		virtual StringPimpl getPreviousUserInput(const unsigned int &previousBotResponse, 
												 const unsigned int &sentence,
												 const StringPimpl &userId, 
												 const StringPimpl &botId,
												 const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &);

		virtual ~NetworkGraphBuilderAIML();

	private:
		StringPimpl m_userId;
		StringPimpl m_botId;
		StringPimpl m_endUserId;
		Ice::CommunicatorPtr m_iceCommunicator;
		NetworkGraphBuilderIcePrx m_networkGraphBuilderIce;
		Ice::PropertiesPtr m_properties;
		NetworkCallBacks *m_callBacks;
		Ice::ObjectAdapterPtr m_adapter;
		bool m_callBacksActivated;
		Ice::Identity m_ident;
};


} //end of impl namespace
} //end of rebecca namespace

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif



