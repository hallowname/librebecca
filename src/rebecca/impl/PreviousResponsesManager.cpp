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

#include <rebecca/impl/PreviousResponsesManager.h>
#include <rebecca/framework/IdentificationManager.h>
#include <rebecca/impl/DatabaseManager.h>
#include <rebecca/impl/Exceptions.h>

using namespace rebecca::framework;

namespace rebecca
{
namespace impl
{

class PreviousResponsesManagerImpl
{
	public:
		PreviousResponsesManagerImpl()
			: m_databaseManager(0)
		{ }
		
		DatabaseManager *m_databaseManager;
		IdentificationManager *m_identificationManager;
		static PreviousResponsesManager *m_instance;
		static const StringPimpl m_reservedPredicate;

		static const StringPimpl m_reservedBotPreviousUserInput;
		static const StringPimpl m_reservedBotSentence;
		static const StringPimpl m_reservedUserPreviousResponse;
		static const StringPimpl m_reservedUserSentence;
		static const StringPimpl m_reservedBotPreviousUserInputPunct;
		static const StringPimpl m_reservedBotSentencePunct;
		static const StringPimpl m_reservedUserPreviousResponsePunct;
		static const StringPimpl m_reservedUserSentencePunct;
		static const StringPimpl m_reservedSeperator;
		
		int getPreviousUserInputCount(const StringPimpl &reservedPreviousUserInputToken)
		{
			StringPimpl previousUserInputCount = 
				m_databaseManager->getRecord(m_reservedPredicate + 
											 "_@" + m_identificationManager->getUserId() + 
											 "_@" + m_identificationManager->getBotId() +
											 "_@" + m_identificationManager->getEndUserId() +
											 reservedPreviousUserInputToken, true);
			int previousUserInputCountInt = 0;
			if(!previousUserInputCount.empty()) 
			{
				previousUserInputCountInt = previousUserInputCount.getInteger();
			}
			return previousUserInputCountInt;
		}

		int getPreviousSentenceCount(const StringPimpl &previousUserInputNumber,
			                         const StringPimpl &reservedPreviousUserInputToken,
			                         const StringPimpl &reservedPreviousSentenceToken)
		{
			StringPimpl previousSentenceCount = 
				m_databaseManager->getRecord(m_reservedPredicate + 
											 "_@" + m_identificationManager->getUserId() + 
											 "_@" + m_identificationManager->getBotId() +
											 "_@" + m_identificationManager->getEndUserId() +
											 reservedPreviousUserInputToken + 
											 "_@" + previousUserInputNumber +
											 m_reservedSeperator + 
											 reservedPreviousSentenceToken, true);
			int previousSentenceCountInt = 0;
			if(!previousSentenceCount.empty()) 
			{
				previousSentenceCountInt = previousSentenceCount.getInteger();
			}
			return previousSentenceCountInt;
		}

		void addResponse(const deque<StringPimpl> &sentences, 
			             const StringPimpl &reservedPreviousUserInputToken, 
						 const StringPimpl &reservedPreviousSentenceToken)
		{
			//get the total of the previous user input count
			int previousUserInputCount = getPreviousUserInputCount(reservedPreviousUserInputToken);
			++previousUserInputCount;

			StringPimpl previousUserInputCountString = StringPimpl::getString(previousUserInputCount);

			//increment the number of previous user inputs
			m_databaseManager->addRecord(m_reservedPredicate + 
										 "_@" + m_identificationManager->getUserId() + 
										 "_@" + m_identificationManager->getBotId() +
										 "_@" + m_identificationManager->getEndUserId() +
										 reservedPreviousUserInputToken, 
										 previousUserInputCountString);

			for(unsigned int i = 0; i < sentences.size(); ++i)
			{
				
				StringPimpl sentenceCount = StringPimpl::getString(i + 1);
				m_databaseManager->addRecord(m_reservedPredicate + 
											 "_@" + m_identificationManager->getUserId() + 
											 "_@" + m_identificationManager->getBotId() +
											 "_@" + m_identificationManager->getEndUserId() +
											 reservedPreviousUserInputToken + 
											 reservedPreviousSentenceToken + 
											 "_@" + previousUserInputCountString + 
											 m_reservedSeperator + 
											 "_@" + sentenceCount,
											 sentences.at(i));			  
			}

			//increment the number of sentences user inputs
			m_databaseManager->addRecord(m_reservedPredicate + 
										 "_@" + m_identificationManager->getUserId() + 
										 "_@" + m_identificationManager->getBotId() +
										 "_@" + m_identificationManager->getEndUserId() +
										 reservedPreviousUserInputToken + 
										 "_@" + previousUserInputCountString +
										 m_reservedSeperator + 
										 reservedPreviousSentenceToken,
										 StringPimpl::getString(sentences.size()));

		}

		int getUserResponseCount()
		{
			return getPreviousUserInputCount(m_reservedUserPreviousResponse);
		}

		int getUserResponseCountPunct()
		{
			return getPreviousUserInputCount(m_reservedUserPreviousResponsePunct);
		}

		int getBotResponseCount()
		{
			return getPreviousUserInputCount(m_reservedBotPreviousUserInput);
		}

		int getBotResponsePunctCount()
		{
			return getPreviousUserInputCount(m_reservedBotPreviousUserInputPunct);
		}
		
		int getUserSentenceCount(const StringPimpl &userResponseCountIndex)
		{
			return getPreviousSentenceCount(userResponseCountIndex, m_reservedUserPreviousResponse, m_reservedUserSentence);
		}

		int getUserSentencePunctCount(const StringPimpl &userResponseCountIndex)
		{
			return getPreviousSentenceCount(userResponseCountIndex, m_reservedUserPreviousResponsePunct, m_reservedUserSentencePunct);
		}

		int getBotSentenceCount(const StringPimpl &userResponseCountIndex)
		{
			return getPreviousSentenceCount(userResponseCountIndex, m_reservedBotPreviousUserInput, m_reservedBotSentence);
		}

		int getBotSentencePunctCount(const StringPimpl &userResponseCountIndex)
		{
			return getPreviousSentenceCount(userResponseCountIndex, m_reservedBotPreviousUserInputPunct, m_reservedBotSentencePunct);
		}

		int getUserSentenceCount(const int &userResponseCountIndex)
		{
			return getPreviousSentenceCount(StringPimpl::getString(userResponseCountIndex), m_reservedUserPreviousResponse, m_reservedUserSentence);
		}

		int getUserSentencePunctCount(const int &userResponseCountIndex)
		{
			return getPreviousSentenceCount(StringPimpl::getString(userResponseCountIndex), m_reservedUserPreviousResponsePunct, m_reservedUserSentencePunct);
		}

		int getBotSentenceCount(const int &userResponseCountIndex)
		{
			return getPreviousSentenceCount(StringPimpl::getString(userResponseCountIndex), m_reservedBotPreviousUserInput, m_reservedBotSentence);
		}

		int getBotSentencePunctCount(const int &userResponseCountIndex)
		{
			return getPreviousSentenceCount(StringPimpl::getString(userResponseCountIndex), m_reservedBotPreviousUserInputPunct, m_reservedBotSentencePunct);
		}

};

//static variables initialized
PreviousResponsesManager *PreviousResponsesManagerImpl::m_instance = 0;
const StringPimpl PreviousResponsesManagerImpl::m_reservedPredicate = "_@reserved";

const StringPimpl PreviousResponsesManagerImpl::m_reservedBotPreviousUserInput = "_@botPreviousUserInput";
const StringPimpl PreviousResponsesManagerImpl::m_reservedBotSentence = "_@botSentence";
const StringPimpl PreviousResponsesManagerImpl::m_reservedUserPreviousResponse = "_@userPreviousResponse";
const StringPimpl PreviousResponsesManagerImpl::m_reservedUserSentence = "_@userSentence";
const StringPimpl PreviousResponsesManagerImpl::m_reservedBotPreviousUserInputPunct = "_@botPreviousUserInputPunct";
const StringPimpl PreviousResponsesManagerImpl::m_reservedBotSentencePunct = "_@botSentencePunct";
const StringPimpl PreviousResponsesManagerImpl::m_reservedUserPreviousResponsePunct = "_@userPreviousResponsePunct";
const StringPimpl PreviousResponsesManagerImpl::m_reservedUserSentencePunct = "_@userSentencePunct";
const StringPimpl PreviousResponsesManagerImpl::m_reservedSeperator = ":";

PreviousResponsesManager::PreviousResponsesManager()
	: m_pimpl(new PreviousResponsesManagerImpl)
{ 

}

PreviousResponsesManager *PreviousResponsesManager::reset()
{
	if(PreviousResponsesManagerImpl::m_instance != 0)
	{
		delete PreviousResponsesManagerImpl::m_instance;
	}

	PreviousResponsesManagerImpl::m_instance = new PreviousResponsesManager();
	PreviousResponsesManagerImpl::m_instance->m_pimpl->m_databaseManager = DatabaseManager::getInstance();
	PreviousResponsesManagerImpl::m_instance->m_pimpl->m_identificationManager = IdentificationManager::getInstance();
	return PreviousResponsesManagerImpl::m_instance;
}

PreviousResponsesManager *PreviousResponsesManager::getInstance()
{
	return PreviousResponsesManagerImpl::m_instance;
}

StringPimpl PreviousResponsesManager::getPreviousBotResponse(const unsigned int &previousBotResponse,
	                                                         const unsigned int &sentence) const
{
	unsigned int previousInputCount = m_pimpl->getBotResponseCount();
	if(previousBotResponse > previousInputCount)
	{
		throw IllegalArgumentExceptionImpl("previousBotResponse size exceeded");
	}
	
	unsigned int botSentenceCount = m_pimpl->getBotSentenceCount(previousInputCount - (previousBotResponse - 1));
	if(sentence > botSentenceCount)
	{
		throw IllegalArgumentExceptionImpl("sentence size exceeded");
	}
	
	return m_pimpl->m_databaseManager->getRecord(m_pimpl->m_reservedPredicate + 
								                 "_@" + m_pimpl->m_identificationManager->getUserId() + 
								                 "_@" + m_pimpl->m_identificationManager->getBotId() +
												 "_@" + m_pimpl->m_identificationManager->getEndUserId() +
								                 m_pimpl->m_reservedBotPreviousUserInput + 
								                 m_pimpl->m_reservedBotSentence + 
								                 "_@" + StringPimpl::getString(previousInputCount - (previousBotResponse - 1)) + 
								                 m_pimpl->m_reservedSeperator + 
								                 "_@" + StringPimpl::getString(botSentenceCount - (sentence - 1)), true);
}

StringPimpl PreviousResponsesManager::getPreviousBotResponseWithPunctuation(const unsigned int &previousBotResponse,
	                                                                        const unsigned int &sentence) const
{
	unsigned int previousInputCount = m_pimpl->getBotResponsePunctCount();
	if(previousBotResponse > previousInputCount)
	{
		throw IllegalArgumentExceptionImpl("previousBotResponse size exceeded");
	}
	
	unsigned int botSentenceCount = m_pimpl->getBotSentencePunctCount(previousInputCount - (previousBotResponse - 1));
	if(sentence > botSentenceCount)
	{
		throw IllegalArgumentExceptionImpl("sentence size exceeded");
	}
	
	return m_pimpl->m_databaseManager->getRecord(m_pimpl->m_reservedPredicate + 
								                 "_@" + m_pimpl->m_identificationManager->getUserId() + 
								                 "_@" + m_pimpl->m_identificationManager->getBotId() +
												 "_@" + m_pimpl->m_identificationManager->getEndUserId() +
												 m_pimpl->m_reservedBotPreviousUserInputPunct + 
												 m_pimpl->m_reservedBotSentencePunct + 
								                 "_@" + StringPimpl::getString(previousInputCount - (previousBotResponse - 1)) + 
								                 m_pimpl->m_reservedSeperator + 
								                 "_@" + StringPimpl::getString(botSentenceCount - (sentence - 1)), true);
}

StringPimpl PreviousResponsesManager::getPreviousUserInput(const unsigned int &previousUserInput, 
	                                                       const unsigned int &sentence) const
{
	unsigned int previousInputCount = m_pimpl->getUserResponseCount();
	if(previousUserInput > previousInputCount)
	{
		throw IllegalArgumentExceptionImpl("previousUserInputResponse size exceeded");
	}
	
	unsigned int sentenceCount = m_pimpl->getUserSentenceCount(previousInputCount - (previousUserInput - 1));
	if(sentence > sentenceCount)
	{
		throw IllegalArgumentExceptionImpl("sentence size exceeded");
	}
	
	return m_pimpl->m_databaseManager->getRecord(m_pimpl->m_reservedPredicate + 
								                 "_@" + m_pimpl->m_identificationManager->getUserId() + 
								                 "_@" + m_pimpl->m_identificationManager->getBotId() +
												 "_@" + m_pimpl->m_identificationManager->getEndUserId() +
												 m_pimpl->m_reservedUserPreviousResponse + 
												 m_pimpl->m_reservedUserSentence + 
								                 "_@" + StringPimpl::getString(previousInputCount - (previousUserInput - 1)) + 
								                 m_pimpl->m_reservedSeperator + 
								                 "_@" + StringPimpl::getString(sentenceCount - (sentence - 1)), true);
}

StringPimpl PreviousResponsesManager::getPreviousUserInputWithPunctuation(const unsigned int &previousUserInput, 
	                                                                      const unsigned int &sentence) const
{
	unsigned int previousInputCount = m_pimpl->getUserResponseCountPunct();
	if(previousUserInput > previousInputCount)
	{
		throw IllegalArgumentExceptionImpl("previousUserInputResponse size exceeded");
	}
	
	unsigned int sentenceCount = m_pimpl->getUserSentencePunctCount(previousInputCount - (previousUserInput - 1));
	if(sentence > sentenceCount)
	{
		throw IllegalArgumentExceptionImpl("sentence size exceeded");
	}
	
	return m_pimpl->m_databaseManager->getRecord(m_pimpl->m_reservedPredicate + 
								                 "_@" + m_pimpl->m_identificationManager->getUserId() + 
								                 "_@" + m_pimpl->m_identificationManager->getBotId() + 
												 "_@" + m_pimpl->m_identificationManager->getEndUserId() +
												 m_pimpl->m_reservedUserPreviousResponsePunct + 
												 m_pimpl->m_reservedUserSentencePunct + 
								                 "_@" + StringPimpl::getString(previousInputCount - (previousUserInput - 1)) + 
								                 m_pimpl->m_reservedSeperator + 
								                 "_@" + StringPimpl::getString(sentenceCount - (sentence - 1)), true);
}


void PreviousResponsesManager::addBotResponse(const deque<StringPimpl> &sentences)
{
	m_pimpl->addResponse(sentences, 
		                 PreviousResponsesManagerImpl::m_reservedBotPreviousUserInput, 
						 PreviousResponsesManagerImpl::m_reservedBotSentence);
}

void PreviousResponsesManager::addUserResponse(const deque<StringPimpl> &sentences)
{
	m_pimpl->addResponse(sentences, 
		                 PreviousResponsesManagerImpl::m_reservedUserPreviousResponse,
						 PreviousResponsesManagerImpl::m_reservedUserSentence);
}

void PreviousResponsesManager::addBotResponseWithPunctuation(const deque<StringPimpl> &sentences)
{
	m_pimpl->addResponse(sentences, 
		                 PreviousResponsesManagerImpl::m_reservedBotPreviousUserInputPunct, 
						 PreviousResponsesManagerImpl::m_reservedBotSentencePunct);
}

void PreviousResponsesManager::addUserResponseWithPunctuation(const deque<StringPimpl> &sentences)
{
	m_pimpl->addResponse(sentences, 
		                 PreviousResponsesManagerImpl::m_reservedBotPreviousUserInputPunct, 
						 PreviousResponsesManagerImpl::m_reservedBotSentencePunct);
}

PreviousResponsesManager::~PreviousResponsesManager()
{
	delete m_pimpl;
}
} // end of impl namespace
} // end of rebecca namespace
