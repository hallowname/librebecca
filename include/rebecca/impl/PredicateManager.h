#ifndef REBECCA_IMPL_PREDICATEMANAGER_H
#define REBECCA_IMPL_PREDICATEMANAGER_H

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

#include <rebecca/StringPimpl.h>

namespace rebecca
{
namespace impl
{

//Forward declerations
class PredicateManagerImpl;

class PredicateManager
{

	public:
		void setBotPredicate(const StringPimpl &predicateKey, const StringPimpl &predicateValue);
		void setPredicate(const StringPimpl &predicateKey, const StringPimpl &predicateValue);
		StringPimpl getBotPredicate(const StringPimpl &predicateKey);
		StringPimpl getPredicate(const StringPimpl &predicateKey);
		StringPimpl *getBotPredicates(unsigned int &size);
		StringPimpl *getPredicates(unsigned int &size);
		~PredicateManager();
		static PredicateManager *getInstance();
		static PredicateManager *reset();
		unsigned int getBotPredicatesSize();
		unsigned int getPredicatesSize();
		void removePredicate(const StringPimpl &predicateKey);
		void removeBotPredicate(const StringPimpl &predicateKey);
	private:
		PredicateManagerImpl *m_pimpl;
		PredicateManager();
};

} // end of impl namespace
} // end of rebecca namespace
#endif


