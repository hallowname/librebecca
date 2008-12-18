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
#include <rebecca/impl/Factory.h>
#include <rebecca/impl/GraphBuilderAIML.h>
#include <rebecca/impl/StarsManager.h>
#include <rebecca/impl/DatabaseManager.h>
#include <rebecca/impl/PredicateManager.h>
#include <rebecca/impl/PreviousResponsesManager.h>
#include <rebecca/impl/XercesSAXXMLManager.h>
#include <rebecca/framework/IdentificationManager.h>
#include <rebecca/framework/FrameworkFactory.h>

namespace rebecca
{
namespace impl
{

//static initialization
Factory	*Factory::m_instance = 0;

Factory::Factory()
	: m_builder(0),
	  m_starsManager(0),
	  m_databaseManager(0),
	  m_frameworkFactory(0),
	  m_identificationManager(0),
	  m_previousResponsesManager(0),
	  m_xmlManager(0)
{
}

Factory *Factory::reset()
{

	if(m_instance != 0)
	{
		delete m_instance;
	}
	m_instance = new Factory();
	m_instance->deleteAllInstances();

	//set the locale
	///@TODO make this configurable

#ifdef _WIN32
	locale::global(locale("ENG")); 
#endif

	//reset all the other managers
	m_instance->m_databaseManager = m_instance->m_databaseManager->reset();
	m_instance->m_identificationManager = m_instance->m_identificationManager->reset();
	m_instance->m_starsManager = m_instance->m_starsManager->reset();
	m_instance->m_predicateManager = m_instance->m_predicateManager->reset();
	m_instance->m_previousResponsesManager = m_instance->m_previousResponsesManager->reset();
	m_instance->m_xmlManager = m_instance->m_xmlManager->reset();
	m_instance->m_builder = m_instance->m_builder->reset();
	m_instance->m_frameworkFactory = m_instance->m_frameworkFactory->reset();
	return m_instance;
}

Factory *Factory::getInstance()
{
	return m_instance;
}

GraphBuilder *Factory::createGraphBuilder()
{
	return m_builder;
}

StarsManager *Factory::createStarsManager()
{
	return m_starsManager;
}

DatabaseManager *Factory::createDatabaseManager()
{
	return m_databaseManager;
}

void Factory::deleteAllInstances()
{
	delete m_builder;
	m_builder = 0;
	delete m_starsManager;
	m_starsManager = 0;
	delete m_identificationManager;
	m_identificationManager = 0;
	delete m_previousResponsesManager;
	m_previousResponsesManager = 0;
	delete m_databaseManager;
	m_databaseManager = 0;
	delete m_frameworkFactory;
	m_frameworkFactory = 0;
	delete m_xmlManager;
	m_xmlManager = 0;
}

Factory::~Factory()
{
	deleteAllInstances();
}


} //end of namespace impl
} //end of namespace rebecca
