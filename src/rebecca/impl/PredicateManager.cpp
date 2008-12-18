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
#include <rebecca/impl/PredicateManager.h>
#include <rebecca/impl/DatabaseManager.h>
#include <rebecca/framework/IdentificationManager.h>
using namespace rebecca::framework;

namespace rebecca
{
namespace impl
{

class PredicateManagerImpl
{
	public:
		PredicateManagerImpl()
			: m_databaseManager(0),
			m_identificationManager(0)
		{ }

		static PredicateManager *m_instance;
		DatabaseManager *m_databaseManager;
		static const StringPimpl m_reservedPredicate;
		static const StringPimpl m_reservedBotPredicate;
		IdentificationManager *m_identificationManager;
};

//static variables initialized
PredicateManager *PredicateManagerImpl::m_instance = 0;

const StringPimpl PredicateManagerImpl::m_reservedPredicate = "_@reserved";
const StringPimpl PredicateManagerImpl::m_reservedBotPredicate = "_@reserved";

PredicateManager::PredicateManager()
	: m_pimpl(new PredicateManagerImpl)
{

}
PredicateManager *PredicateManager::reset()
{
	if(PredicateManagerImpl::m_instance != 0)
	{
		delete PredicateManagerImpl::m_instance;
	}
	
	PredicateManagerImpl::m_instance = new PredicateManager();

	PredicateManagerImpl::m_instance->m_pimpl->m_databaseManager = DatabaseManager::getInstance();
	PredicateManagerImpl::m_instance->m_pimpl->m_identificationManager = IdentificationManager::getInstance();
	return PredicateManagerImpl::m_instance;
}


StringPimpl *PredicateManager::getPredicates(unsigned int &size)
{
	return m_pimpl->m_databaseManager->getRecordCountList(m_pimpl->m_identificationManager->getUserId() + 
														  "_@" + m_pimpl->m_identificationManager->getBotId() +
														  "_@" + m_pimpl->m_identificationManager->getEndUserId() +
														  PredicateManagerImpl::m_reservedPredicate + 
														  "_@Predicate_@", size);
}

StringPimpl *PredicateManager::getBotPredicates(unsigned int &size)
{
	return m_pimpl->m_databaseManager->getRecordCountList(m_pimpl->m_identificationManager->getUserId() + 
													      "_@" + m_pimpl->m_identificationManager->getBotId() + 
														  PredicateManagerImpl::m_reservedBotPredicate +
														  "_@BotPredicate_@", size);
}

void PredicateManager::setBotPredicate(const StringPimpl &predicateKey, const StringPimpl &predicateValue)
{
	StringPimpl caseInsenitiveKey = predicateKey;
	caseInsenitiveKey.transformToUpperCase();
	m_pimpl->m_databaseManager->addRecord(PredicateManagerImpl::m_reservedBotPredicate + 
		                                  "_@" + m_pimpl->m_identificationManager->getUserId() + 
		                                  "_@" + m_pimpl->m_identificationManager->getBotId() + 
										  PredicateManagerImpl::m_reservedBotPredicate +
										  "_@" + caseInsenitiveKey, 
										  predicateValue);

	m_pimpl->m_databaseManager->addRecordWithCount(m_pimpl->m_identificationManager->getUserId() + 
		                                           "_@" + m_pimpl->m_identificationManager->getBotId() + 
												   PredicateManagerImpl::m_reservedBotPredicate +
												   "_@BotPredicate_@", 
												   caseInsenitiveKey);

}

unsigned int PredicateManager::getBotPredicatesSize()
{
	return m_pimpl->m_databaseManager->getRecordTotalCount(m_pimpl->m_identificationManager->getUserId() + 
		                                                   "_@" + m_pimpl->m_identificationManager->getBotId() + 
												           PredicateManagerImpl::m_reservedBotPredicate +
												           "_@BotPredicate_@");

}

unsigned int PredicateManager::getPredicatesSize()
{
	return m_pimpl->m_databaseManager->getRecordTotalCount(m_pimpl->m_identificationManager->getUserId() + 
													       "_@" + m_pimpl->m_identificationManager->getBotId() + 
													       "_@" + m_pimpl->m_identificationManager->getEndUserId() +
													       PredicateManagerImpl::m_reservedPredicate +
													       "_@Predicate_@");
}

void PredicateManager::removeBotPredicate(const StringPimpl &predicateKey)
{
	StringPimpl caseInsenitiveKey = predicateKey;
	caseInsenitiveKey.transformToUpperCase();
	m_pimpl->m_databaseManager->deleteRecord(PredicateManagerImpl::m_reservedBotPredicate + 
		                                     "_@" + m_pimpl->m_identificationManager->getUserId() + 
		                                     "_@" + m_pimpl->m_identificationManager->getBotId() + 
											 PredicateManagerImpl::m_reservedBotPredicate +
										     "_@" + caseInsenitiveKey);

	m_pimpl->m_databaseManager->deleteRecordWithCount(m_pimpl->m_identificationManager->getUserId() + 
		                                              "_@" + m_pimpl->m_identificationManager->getBotId() + 
													  PredicateManagerImpl::m_reservedBotPredicate +
												      "_@BotPredicate_@", caseInsenitiveKey);
}

void PredicateManager::removePredicate(const StringPimpl &predicateKey)
{
	StringPimpl caseInsenitiveKey = predicateKey;
	caseInsenitiveKey.transformToUpperCase();

	//can't remove topic
	if(caseInsenitiveKey == "TOPIC")
	{
		return;
	}
	else 
	{
		m_pimpl->m_databaseManager->deleteRecord(PredicateManagerImpl::m_reservedPredicate + 
											  "_@" + m_pimpl->m_identificationManager->getUserId() + 
											  "_@" + m_pimpl->m_identificationManager->getBotId() +
											  "_@" + m_pimpl->m_identificationManager->getEndUserId() +
											  PredicateManagerImpl::m_reservedPredicate +
											  "_@" + caseInsenitiveKey);

		m_pimpl->m_databaseManager->deleteRecordWithCount(m_pimpl->m_identificationManager->getUserId() + 
													      "_@" + m_pimpl->m_identificationManager->getBotId() + 
													      "_@" + m_pimpl->m_identificationManager->getEndUserId() +
													      PredicateManagerImpl::m_reservedPredicate +
													      "_@Predicate_@", caseInsenitiveKey);

	}
}

void PredicateManager::setPredicate(const StringPimpl &predicateKey, const StringPimpl &predicateValue)
{
	StringPimpl caseInsenitiveKey = predicateKey;
	caseInsenitiveKey.transformToUpperCase();
	if(caseInsenitiveKey == "TOPIC" && predicateValue.empty())
	{
		m_pimpl->m_databaseManager->addRecord(PredicateManagerImpl::m_reservedPredicate + 
											  "_@" + m_pimpl->m_identificationManager->getUserId() + 
											  "_@" + m_pimpl->m_identificationManager->getBotId() +
											  "_@" + m_pimpl->m_identificationManager->getEndUserId() +
											  PredicateManagerImpl::m_reservedPredicate +
											  "_@" + caseInsenitiveKey, 
											  "*");
		m_pimpl->m_databaseManager->addRecordWithCount(m_pimpl->m_identificationManager->getUserId() + 
													   "_@" + m_pimpl->m_identificationManager->getBotId() + 
													   "_@" + m_pimpl->m_identificationManager->getEndUserId() +
													   PredicateManagerImpl::m_reservedPredicate +
													   "_@Predicate_@", "*");

	}
	else
	{
		m_pimpl->m_databaseManager->addRecord(PredicateManagerImpl::m_reservedPredicate + 
											  "_@" + m_pimpl->m_identificationManager->getUserId() + 
											  "_@" + m_pimpl->m_identificationManager->getBotId() +
											  "_@" + m_pimpl->m_identificationManager->getEndUserId() +
											  PredicateManagerImpl::m_reservedPredicate +
											  "_@" + caseInsenitiveKey, 
											  predicateValue);

		m_pimpl->m_databaseManager->addRecordWithCount(m_pimpl->m_identificationManager->getUserId() + 
													   "_@" + m_pimpl->m_identificationManager->getBotId() + 
													   "_@" + m_pimpl->m_identificationManager->getEndUserId() +
													   PredicateManagerImpl::m_reservedPredicate +
													   "_@Predicate_@", caseInsenitiveKey);
	}
}

StringPimpl PredicateManager::getBotPredicate(const StringPimpl &predicateKey)
{
	StringPimpl caseInsenitiveKey = predicateKey;
	caseInsenitiveKey.transformToUpperCase();
	return m_pimpl->m_databaseManager->getRecord(PredicateManagerImpl::m_reservedBotPredicate +
		                                         "_@" + m_pimpl->m_identificationManager->getUserId() + 
		                                         "_@" + m_pimpl->m_identificationManager->getBotId() + 
												 PredicateManagerImpl::m_reservedBotPredicate +
										         "_@" + caseInsenitiveKey,
												 true);
}

StringPimpl PredicateManager::getPredicate(const StringPimpl &predicateKey)
{
	StringPimpl caseInsenitiveKey = predicateKey;
	caseInsenitiveKey.transformToUpperCase();
	return m_pimpl->m_databaseManager->getRecord(PredicateManagerImpl::m_reservedPredicate +
		                                         "_@" + m_pimpl->m_identificationManager->getUserId() + 
		                                         "_@" + m_pimpl->m_identificationManager->getBotId() + 
												 "_@" + m_pimpl->m_identificationManager->getEndUserId() +
												 PredicateManagerImpl::m_reservedPredicate + 
										         "_@" + caseInsenitiveKey, 
												 true);
}

PredicateManager *PredicateManager::getInstance()
{
	return PredicateManagerImpl::m_instance;
}

PredicateManager::~PredicateManager()
{
	delete m_pimpl;
}

} // end of impl namespace
} // end of rebecca namespace

