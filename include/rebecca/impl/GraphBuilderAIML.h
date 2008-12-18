#ifndef REBECCA_IMPL_GRAPHBUILDERAIML_H
#define REBECCA_IMPL_GRAPHBUILDERAIML_H

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
#include <rebecca/impl/NodeMapper.h>
#include <rebecca/impl/GraphBuilderInternal.h>
#include <rebecca/impl/ConfigurationHandler.h>
#include <rebecca/impl/GraphHandler.h>

//Boost includes
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/tss.hpp>

namespace rebecca
{
namespace framework
{
namespace impl
{

//Forward decleration
class CustomTags;
class IdentificationManager;

}
using rebecca::framework::impl::CustomTags;
using rebecca::framework::impl::IdentificationManager;
}
	
namespace impl
{
//Forward declerations
class DatabaseManager;
class StarsManager;
class PredicateManager;
class PreviousResponsesManager;
class XercesSAXXMLManager;

XERCES_CPP_NAMESPACE_USE
using namespace boost;
using namespace std;

class GraphBuilderAIML : public GraphBuilderInternal
{
	public:

		//These are methods from GraphBuilderInternal

		virtual void createGraph() 
			throw(XMLErrorException &, Exception &);

		virtual void createGraph(const StringPimpl &userId,
			                     const StringPimpl &botId,
								 const StringPimpl &endUserId) 
			throw(XMLErrorException &, Exception &);

		virtual void removeGraph() 
			throw(XMLErrorException &, Exception &);

		virtual void removeGraph(const StringPimpl &userId,
			                     const StringPimpl &botId,
								 const StringPimpl &endUserId) 
			throw(XMLErrorException &, Exception &);

		virtual StringPimpl getStar(const unsigned int &index,
			                        const StringPimpl &userId,
									const StringPimpl &botId,
									const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getStar(const unsigned int &index) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getThatStar(const unsigned int &index,
			                            const StringPimpl &userId,
										const StringPimpl &botId,
										const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getThatStar(const unsigned int &index) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getTopicStar(const unsigned int &index) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getTopicStar(const unsigned int &index,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl genderSubstitute(const StringPimpl &input) const
			throw(Exception &);

		virtual StringPimpl inputSubstitute(const StringPimpl &input);


		virtual StringPimpl personSubstitute(const StringPimpl &input) const
			throw(Exception &);

		virtual StringPimpl person2Substitute(const StringPimpl &input) const
			throw(Exception &);

		virtual CallBacks &getCallBacks()
			throw(Exception &);

		virtual StringPimpl checkedInfiniteLoopGetResponse(const StringPimpl &userInput, 
			                                               bool keepPreviousUserInput = true)
			throw(RecursionException &, Exception &);

		virtual StringPimpl checkedInfiniteLoopGetResponse(const StringPimpl &userInput, 
			                                               const StringPimpl &userId,
														   const StringPimpl &botId,
														   const StringPimpl &endUserId,
			                                               bool keepPreviousUserInput = true)
			throw(RecursionException &, Exception &);

		virtual void setSize(const unsigned int newSize);

		virtual void addFile(const StringPimpl &file)
			throw(FileNotFoundException &, Exception &);	

		virtual void addFile(const StringPimpl &file,
			                 const StringPimpl &userId,
							 const StringPimpl &botId,
							 const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &);		

		virtual void addFileUnlessAlreadyAdded(const StringPimpl &file)
			throw(FileNotFoundException &, Exception &);	

		virtual void addFileUnlessAlreadyAdded(const StringPimpl &file,
			                                   const StringPimpl &userId,
							                   const StringPimpl &botId,
							                   const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &);		

		virtual void removeFile(const StringPimpl &file) 
			throw(FileNotFoundException &, Exception &);		

		virtual void removeFile(const StringPimpl &file,
			                 const StringPimpl &userId,
							 const StringPimpl &botId,
							 const StringPimpl &endUserId) 
			throw(FileNotFoundException &, Exception &);		

		virtual void addDirectory(const StringPimpl &directory, 
			                      const StringPimpl &userId, 
								  const StringPimpl &botId,
								  const StringPimpl &endUserId,
								  const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void removeDirectory(const StringPimpl &directory, 
			                      const StringPimpl &userId, 
								  const StringPimpl &botId,
								  const StringPimpl &endUserId,
								  const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);


		virtual void addDirectory(const StringPimpl &directory, 
			                      const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
			                                        const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
			                                        const StringPimpl &userId, 
								                    const StringPimpl &botId,
								                    const StringPimpl &endUserId,
								                    const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void removeDirectory(const StringPimpl &directory, 
			                         const StringPimpl &regularExpression = ".*\\.aiml")
			throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &);

		virtual void addString(const StringPimpl &stringContainingAIML)
			throw(Exception &);

		virtual void addString(const StringPimpl &stringContainingAIML,
							   const StringPimpl &userId,
							   const StringPimpl &botId,
							   const StringPimpl &endUserId)
			throw(Exception &);

		virtual void removeString(const StringPimpl &stringContainingAIML)
			throw(Exception &);

		virtual void removeString(const StringPimpl &stringContainingAIML,
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

		virtual StringPimpl getResponse(const StringPimpl &input)
			throw(Exception &);

		virtual StringPimpl getResponse(const StringPimpl &input, 
			                            const StringPimpl &userId, 
										const StringPimpl &botId,
										const StringPimpl &endUserId) 
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

		virtual ~GraphBuilderAIML();

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

		virtual void setPredicate(const StringPimpl &name, 
			                      const StringPimpl &value)
			throw(Exception &);

		virtual void setPredicate(const StringPimpl &name, 
			                      const StringPimpl &value,
								  const StringPimpl &userId,
								  const StringPimpl &botId,
								  const StringPimpl &endUserId)
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

		virtual StringPimpl getPredicate(const StringPimpl &name) const
			throw(Exception &);

		virtual StringPimpl getPredicate(const StringPimpl &name,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId) const
			throw(Exception &);

		virtual bool predicateMatch(const StringPimpl &predicateName, 
			                        const StringPimpl &aimlPattern) const
			throw(Exception &);

		virtual bool predicateMatch(const StringPimpl &predicateName, 
			                        const StringPimpl &aimlPattern,
									const StringPimpl &userId,
									const StringPimpl &botId,
									const StringPimpl &endUserId) const
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

		virtual StringPimpl getPreviousUserInput(const unsigned int &previousUserInput, 
			                                     const unsigned int &sentence,
												 const StringPimpl &userId,
												 const StringPimpl &botId,
												 const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &);

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

		virtual void setBotConfigurationSchema(const StringPimpl &schema)
			throw(Exception &, FileNotFoundException &);

		virtual void setBotConfigurationValidation(const bool trueOrFalse = true)
			throw(Exception &);

		virtual void parseSubstitutionFile(const StringPimpl &fileName)
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

		virtual void setInputSubstitution(const StringPimpl &find, const StringPimpl &replace)
			throw(IllegalArgumentException &, Exception &);

		virtual void setGenderSubstitution(const StringPimpl &find, const StringPimpl &replace)
			throw(IllegalArgumentException &, Exception &);

		virtual void setPersonSubstitution(const StringPimpl &find, const StringPimpl &replace)
			throw(IllegalArgumentException &, Exception &);

		virtual void setPerson2Substitution(const StringPimpl &find, const StringPimpl &replace)
			throw(IllegalArgumentException &, Exception &);

		virtual void parseSentenceSplitterFile(const StringPimpl &fileName)
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

		virtual void parsePropertiesFile(const StringPimpl &fileName)
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

		virtual void parsePropertiesFile(const StringPimpl &fileName,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId)
			throw(XMLErrorException &, FileNotFoundException &, Exception &);

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

		virtual void setCallBacks(CallBacks *callBacks)
			throw(Exception &);

		virtual void setSentenceSplitter(const StringPimpl &splitter)
			throw(Exception &);

		virtual int getSize() const
			throw(Exception &);

		virtual int getSize(const StringPimpl &userId,
							const StringPimpl &botId,
							const StringPimpl &endUserId) const
			throw(Exception &);

		virtual StringPimpl getVersion() const
			throw(Exception &);

		virtual void storeGossip(const StringPimpl &gossip)
			throw(Exception &);

		virtual StringPimpl getId() const
			throw(Exception &);

		virtual void setUserIdBotIdEndUserId(const StringPimpl &userId, 
			                                 const StringPimpl &botId,
											 const StringPimpl &endUserId)
			throw(Exception &);

		virtual StringPimpl getPreviousBotResponsePunctuation(const unsigned int &previousBotResponse, 
			                                                  const unsigned int &sentence) const
			throw(IllegalArgumentException &, Exception &);

		virtual StringPimpl getPreviousBotResponsePunctuation(const unsigned int &previousBotResponse, 
                                                              const unsigned int &sentence,
															  const StringPimpl &userId,
															  const StringPimpl &botId,
															  const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &);

		virtual void synchronizeDatabase() const
			throw(Exception &);

		virtual void addCustomTagLibrary(const StringPimpl &library)
			throw(FileNotFoundException &, Exception &);

		virtual void removeCustomTagLibrary(const StringPimpl &library)
			throw(FileNotFoundException &, Exception &);

		virtual NodeMapper &getRootNodeMapper()
		{
			return m_NodeMapperRoot;
		}

		virtual map<StringPimpl, CustomTagWithDelete> &getCustomTagsMapRef()
		{
			return m_customTags;
		}

		virtual StringPimpl callSystemCommand(const StringPimpl &command) const
			throw(Exception &);

		virtual void setDBEnvironmentDirectory(const StringPimpl &directory)
			throw(Exception &);

		static GraphBuilderAIML *getInstance()
			throw(InitializationException &, Exception &);
		
		static GraphBuilderAIML *reset();

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

	private:

		GraphBuilderAIML() 
			throw(InitializationException &, Exception &);
		
		static GraphBuilderAIML *m_instance;
		virtual StringPimpl convertAndCheckXSD(const StringPimpl &schema);

		virtual void makeGraph(const InputSource &source, 
			                   const StringPimpl &file, 
							   bool removal = false); 		

		virtual void initializeXerces();
		virtual void parseConfigurationFile(const StringPimpl &fileName);

		virtual StringPimpl getResponseInternal(const StringPimpl &input, 
			                                    bool keepPreviousUserInput = true);
		virtual void init()
			throw(XMLException &, Exception &);

		class SubstitutionRegEx
		{
			public:
				SubstitutionRegEx(const regex &find, const string &replace)
					: m_find(find),
					  m_replace(replace)
				{ }

				regex m_find;
				string m_replace;
		};

		virtual StringPimpl substitute(const StringPimpl &input, 
			                           const std::vector<SubstitutionRegEx> &substitution) const;
		
		bool m_dbEnvironmentInitialized;

		StringPimpl m_dbEnvironmentDirectory;

		StringPimpl m_aimlHeader;
		StringPimpl m_aimlFooter;

		bool m_setAIMLValidation;
		bool m_doConfigurationValidation;

		StringPimpl m_aimlSchema;
		StringPimpl m_configurationSchema;
		StringPimpl m_commonTypesSchema;

		/**
		 * Root of the NodeMapper tree.
		 */
		NodeMapper m_NodeMapperRoot;

		//All of this in this block are set at startup by the bot
		//and all remain in memory.  They are thread safe because 
		//once setup they are never again set.  They should only
		//be set at startup.  If you have someone setting them while
		//they are being accessed you're going to crash
		typedef vector<SubstitutionRegEx> VectorSubstitutionRegEx;
		VectorSubstitutionRegEx m_inputSubstitutions;
		VectorSubstitutionRegEx m_genderSubstitutions;
		VectorSubstitutionRegEx m_personSubstitutions;
		VectorSubstitutionRegEx m_person2Substitutions;
		StringPimpl m_sentenceSplitters;
		//End of the startup memory block portion

		thread_specific_ptr<GraphHandler> m_AIMLDocumentHandler;
		thread_specific_ptr<GraphHandler> m_AIMLRemoveDocumentHandler;
		thread_specific_ptr<ConfigurationHandler> m_configurationDocumentHandler;
		thread_specific_ptr<HandlerBase> m_AIMLErrorHandler;
		thread_specific_ptr<HandlerBase> m_configurationErrorHandler;

		 
		CallBacks m_defaultCallBacks;

		///CallBack pointer.  It will NOT be deleted internally.
		CallBacks *m_callBacks;
		
		StringPimpl m_id;

		typedef CustomTags *(*EntryPointfuncPtr)(void);  
		typedef void(*ExitPointfuncPtr)(CustomTags *);  

		map<StringPimpl, CustomTagWithDelete> m_customTags;

		//Mutex for this class
		mutable recursive_mutex m_this;

		bool isASentenceSplitter(char c);

		StringPimpl handleResponse(const StringPimpl &userInput);

		DatabaseManager *m_databaseManager;
		StarsManager *m_starsManager;
		IdentificationManager *m_identificationManager;
		PredicateManager *m_predicateManager;
		PreviousResponsesManager *m_previousResponsesManager;
		XercesSAXXMLManager *m_xmlManager;
};


} //end of impl namespace
} //end of rebecca namespace

#ifdef _WIN32
#    pragma warning ( pop )
#endif


#endif

