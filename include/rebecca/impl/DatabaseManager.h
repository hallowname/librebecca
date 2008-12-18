#ifndef REBECCA_IMPL_DATABASEMANAGER_H
#define REBECCA_IMPL_DATABASEMANAGER_H

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

//std includes
#include <vector>

namespace rebecca 
{
namespace impl 
{

/**
 * The private implementation in which
 * you cannot get access to.
 *
 * This class holds the private methods
 * and private attributes of this class.  This 
 * makes ABI (Application Binary Interface) more
 * resilient to change. See the private implementation
 * idiom on the internet for more information about this.
 *
 * This is being used here mostly because I do not want the 
 * header files to the database to conflict with the other 
 * files in the system.
 */
class DatabaseManagerImpl;

/**
 * Forward declerations
 */
class StringPimpl;

using namespace std;

class DatabaseManager
{
	public:
		static DatabaseManager *reset();
		void beginTransaction();
		void endTransaction();
		static void setEnvironmentDirectory(const StringPimpl &directory);
		bool recordExists(const StringPimpl &key);
		bool getRecord(const StringPimpl &key, 
					   StringPimpl &data, bool caseSensitive = false);
		void addRecord(const StringPimpl &key,
                       const StringPimpl &value);
		/**
		 * Returns the singelton instance of this
		 * class.
		 */
		static DatabaseManager *getInstance();
		virtual ~DatabaseManager();
		void sync();
		StringPimpl getRecord(const StringPimpl &key, bool caseSensitive = false);
		void deleteRecordRange(const StringPimpl &key,
			                   const StringPimpl &range);
		void deleteRecordRange(const StringPimpl &key);
		void deleteRecord(const StringPimpl &key);
		void addRecordWithCount(const StringPimpl &key,
			                    const StringPimpl &value);

		int getRecordTotalCount(const StringPimpl &key);

		void deleteRecordWithCount(const StringPimpl &key,
								   const StringPimpl &value);
		bool recordCountExists(const StringPimpl &key, const StringPimpl &value);
		bool recordCountExists(const StringPimpl &key);
		void deleteRecordCount(const StringPimpl &key);
		StringPimpl *getRecordCountList(const StringPimpl &key, unsigned int &size);
		vector<StringPimpl> getRecordCountListAsVector(const StringPimpl &key);
		vector<StringPimpl> getRecordRangeAsVector(const StringPimpl &key);
		bool recordExists(const StringPimpl &key, const StringPimpl &value);
		void printEntireDB();
		StringPimpl *getRecordRange(const StringPimpl &key, unsigned int &size);
		bool recordRangeExists(const StringPimpl &key);
		/**
		 * The reserved symbols for anything in the 
		 * database that isn't part of the GraphMaster
		 * algorithm.  Such as stars, meta data, etc...
		 */
		static const StringPimpl m_reserved;

	private:			
		friend class DatabaseManagerImpl;
		DatabaseManagerImpl *m_pimpl;
		DatabaseManager();
};

} //end of namespace impl
} //end of namespace rebecca


#endif

