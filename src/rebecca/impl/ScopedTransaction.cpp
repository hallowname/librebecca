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

//Rebecca includes
#include <rebecca/impl/ScopedTransaction.h>
#include <rebecca/impl/DatabaseManager.h>

namespace rebecca
{
namespace impl
{

ScopedTransaction::ScopedTransaction(DatabaseManager *databaseManager)
	: m_databaseManager(databaseManager)
{
	m_databaseManager->beginTransaction();
}

ScopedTransaction::~ScopedTransaction()
{
	m_databaseManager->endTransaction();
}

} //end of namespace impl
} //end of namespace rebecca
