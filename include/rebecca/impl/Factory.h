#ifndef REBECCA_IMPL_FACTORY_H
#define REBECCA_IMPL_FACTORY_H

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
namespace framework
{
namespace impl
{
/*
 * Forward declerations 
 */
class IdentificationManager;
class FrameworkFactory;
}
}
namespace impl
{

/*
 * Forward declerations 
 */
class GraphBuilderAIML;
class GraphBuilder;
class StarsManager;
class DatabaseManager;
class PredicateManager;
class PreviousResponsesManager;
class XercesSAXXMLManager;
using namespace rebecca::framework::impl;

class Factory
{

	public:	
		virtual GraphBuilder *createGraphBuilder(); 
		virtual StarsManager *createStarsManager();
		virtual DatabaseManager *createDatabaseManager();
		virtual ~Factory();
		static Factory *getInstance();
		static Factory *reset();
	private:
		void deleteAllInstances();
		static Factory *m_instance;
		GraphBuilderAIML *m_builder;
		StarsManager *m_starsManager;
		DatabaseManager *m_databaseManager;
		IdentificationManager *m_identificationManager;
		FrameworkFactory *m_frameworkFactory;
		PredicateManager *m_predicateManager;
		PreviousResponsesManager *m_previousResponsesManager;
		XercesSAXXMLManager *m_xmlManager;
		Factory();
};

} //end namespace impl
} //end namespace rebecca

#endif
