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

#include <rebecca/impl/DatabaseManager.h>

//DB includes
#include <db4.5/db_cxx.h>

//rebecca includes
#include <rebecca/StringPimpl.h>

//boost includes
#include <boost/thread/mutex.hpp>
#include <boost/thread/tss.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/convenience.hpp>
using namespace boost;
using namespace boost::filesystem;

//std includes
#include <iostream>
#include <vector>
using namespace std;

namespace rebecca 
{
namespace impl 
{

class DatabaseManagerImpl
{
	public:
		DatabaseManagerImpl()
			: m_alreadyInitialized(false),
			  m_databaseEnvironment(0),
			  m_database(0),
			  m_cursorFlags(0)
		{
			m_envFlags =
				DB_CREATE      |  // Create the environment if it does not exist
				DB_INIT_LOCK   |  // Initialize the locking subsystem
				DB_INIT_LOG    |  // Initialize the logging subsystem
				DB_INIT_TXN    |  // Initialize the transactional subsystem. This
								  // also turns on logging.
				DB_INIT_MPOOL  |  // Initialize the memory pool (in-memory cache)
				DB_THREAD;        // Cause the environment to be free-threaded
		}
		bool m_alreadyInitialized;
		mutex m_this;
		static DatabaseManager *m_instance;
		DbEnv *m_databaseEnvironment;
		static mutex *m_databaseEnvironmentMutex;
		Db *m_database;
		static StringPimpl m_dbEnvironmentDirectory;
		thread_specific_ptr<bool> m_transactionInProgress;
		u_int32_t m_cursorFlags;
		u_int32_t m_envFlags;
		
		thread_specific_ptr<DbTxn *> m_transaction;
		
		void setEnvironmentDirectoryDefault()
		{
			//Initialize the db environment variable
	#       ifdef _WIN32
				char *initPath = getenv("ALLUSERSPROFILE");
	#       else
				char *initPath = getenv("HOME");
	#       endif
			
			if(initPath != NULL)
			{
				m_dbEnvironmentDirectory = initPath;
                # ifdef _WIN32
				m_dbEnvironmentDirectory += "\\Application Data\\.RebeccaAIMLDB";
                # else
				m_dbEnvironmentDirectory += "/.RebeccaAIMLDB";                
                # endif
			}
			else
			{
				//Can't find either varialble so just 
				//using the current directory of the process
				m_dbEnvironmentDirectory = "./.RebeccaAIMLDB";
			}
		}

		void checkTSSInit()
		{
			if(m_transactionInProgress.get() == 0)
			{
				m_transactionInProgress.reset(new bool);
				(*m_transactionInProgress) = false;
			}

			if(m_transaction.get() == 0)
			{
				m_transaction.reset(new DbTxn *);
				(*m_transaction) = NULL;
			}
		}
};

//static initializations
DatabaseManager *DatabaseManagerImpl::m_instance = 0;
StringPimpl DatabaseManagerImpl::m_dbEnvironmentDirectory = StringPimpl();
mutex *DatabaseManagerImpl::m_databaseEnvironmentMutex = new mutex();
const StringPimpl DatabaseManager::m_reserved = "_@reserved_@";

DatabaseManager::DatabaseManager()
	: m_pimpl(new DatabaseManagerImpl)
{
	mutex::scoped_lock synchronized(m_pimpl->m_this);
	if(m_pimpl->m_alreadyInitialized)
	{
		return;
	}
	m_pimpl->m_alreadyInitialized = true;
	if(m_pimpl->m_dbEnvironmentDirectory.empty())
	{
		m_pimpl->setEnvironmentDirectoryDefault();
	}

	//Create directory for the environment
	//If it already exists then we're good.
	m_pimpl->m_dbEnvironmentDirectory.transformIntoAbsoluteFilePath();
	//Get the file format in the native string for db
	path nativeFileFormat(m_pimpl->m_dbEnvironmentDirectory.c_str(), native);

	//Get the complete path to the file
	path completePath = complete(nativeFileFormat);
	create_directories(completePath);

	//Open the Database environment
    m_pimpl->m_databaseEnvironment = new DbEnv(0);
	m_pimpl->m_databaseEnvironment->open(m_pimpl->m_dbEnvironmentDirectory.c_str(), m_pimpl->m_envFlags, 0);
	m_pimpl->m_database = new Db(m_pimpl->m_databaseEnvironment, 0);
	m_pimpl->m_databaseEnvironment->set_message_stream(&cout);
	m_pimpl->m_database->set_message_stream(&cout);
	//Open the actual RebeccaAIML DB
//	u_int32_t dbflags = DB_CREATE | DB_AUTO_COMMIT | DB_READ_UNCOMMITTED;
	u_int32_t dbflags = DB_CREATE;
    m_pimpl->m_database->open(NULL,             // Txn pointer 
                              "RebeccaAIMLDB",  // File name 
                              NULL,             // Logical db name 
                              DB_BTREE,         // Database type (using btree) 
                              dbflags,          // Open flags 
                              0);               // File mode. Using defaults 
}

DatabaseManager *DatabaseManager::reset()
{
	if(DatabaseManagerImpl::m_instance != 0)
	{
		delete DatabaseManagerImpl::m_instance;
	}
	DatabaseManagerImpl::m_instance = new DatabaseManager();
	return DatabaseManagerImpl::m_instance;
}

void DatabaseManager::setEnvironmentDirectory(const StringPimpl &directory)
{
	//Synchronize entire method
	mutex::scoped_lock synchronized(*DatabaseManagerImpl::m_databaseEnvironmentMutex);
	DatabaseManagerImpl::m_dbEnvironmentDirectory = directory;
}

DatabaseManager *DatabaseManager::getInstance()
{
	return DatabaseManagerImpl::m_instance;
}


void DatabaseManager::beginTransaction()
{ 
	m_pimpl->checkTSSInit();
	if(!(*m_pimpl->m_transactionInProgress))
	{
		m_pimpl->m_databaseEnvironment->txn_begin(NULL, &(*m_pimpl->m_transaction), DB_READ_UNCOMMITTED);
		(*m_pimpl->m_transactionInProgress) = true;
	}
}

void DatabaseManager::endTransaction()
{ 
	m_pimpl->checkTSSInit();
	if((*m_pimpl->m_transactionInProgress))
	{
		(*m_pimpl->m_transaction)->commit(0);
		//m_pimpl->m_transaction.reset(new DbTxn *);
		(*m_pimpl->m_transaction) = NULL;
		*m_pimpl->m_transactionInProgress = false;
	}
}

bool DatabaseManager::recordExists(const StringPimpl &key)
{
	Dbt dbKey, dbData;
	dbKey.set_data((void *)key.c_str());
	dbKey.set_size((key.size() + 1) * sizeof(char));
	Dbc *cursor = NULL;

	try
	{
		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET);
		cursor->close();
		if(ret != DB_NOTFOUND)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (DbException &e) 
	{
        std::cerr << "Error in databse recordExists"
			<< e.what() << e.get_errno() <<  std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
		return false;
    }
}

void DatabaseManager::sync()
{
	m_pimpl->m_database->sync(0);
}

bool DatabaseManager::getRecord(const StringPimpl &key, 
                                StringPimpl &data,
								bool caseSensitive)
{
	Dbt dbKey, dbData;
	StringPimpl caseInsensitive;
	if(!caseSensitive)
	{
		caseInsensitive = key;
		caseInsensitive.transformToUpperCase();
		dbKey.set_data((void *)caseInsensitive.c_str());
		dbKey.set_size((caseInsensitive.size() + 1) * sizeof(char));
	}
	else
	{
		dbKey.set_data((void *)key.c_str());
		dbKey.set_size((key.size() + 1) * sizeof(char));
	}

	Dbc *cursor = NULL;

	try
	{
		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET);
		cursor->close();
		if(ret != DB_NOTFOUND)
		{
			data = StringPimpl((char *) dbData.get_data());
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (DbException &e) 
	{
        std::cerr << "Error in getDatabaseRecord transaction: "
                   << e.what() << e.get_errno() << std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
		return false;
    }
}

StringPimpl DatabaseManager::getRecord(const StringPimpl &key, bool caseSensitive)
{
	Dbt dbKey, dbData;
	StringPimpl caseInsensitive;
	if(!caseSensitive)
	{
		caseInsensitive = key;
		caseInsensitive.transformToUpperCase();
		dbKey.set_data((void *)caseInsensitive.c_str());
		dbKey.set_size((caseInsensitive.size() + 1) * sizeof(char));
	}
	else
	{
		dbKey.set_data((void *)key.c_str());
		dbKey.set_size((key.size() + 1) * sizeof(char));
	}

	Dbc *cursor = NULL;

	try
	{
		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET);
		cursor->close();
		if(ret != DB_NOTFOUND)
		{
			return StringPimpl((char *) dbData.get_data());
		}
		else
		{
			return StringPimpl();
		}
	}
	catch (DbException &e) 
	{
        std::cerr << "Error in getDatabaseRecord transaction: "
                   << e.what() << e.get_errno() << std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
		return StringPimpl();
    }
}

void DatabaseManager::addRecordWithCount(const StringPimpl &key, 
										 const StringPimpl &value)
{
	if(!recordCountExists(key, value))
	{
		int size = getRecordTotalCount(key);
		addRecord(m_reserved + key + "_@size_@", StringPimpl::getString(size + 1));

		//This enables us to do a fast lookup without having to loop through
		//the entire list just to check for the existence of the key
		addRecord(m_reserved + key + "_@existence_@" + value, value);
	}
}

int DatabaseManager::getRecordTotalCount(const StringPimpl &key)
{
	StringPimpl sizeAsString = getRecord(m_reserved + key + "_@size_@", true);
	if(sizeAsString.empty())
	{
		return 0;
	}
	else
	{
		return sizeAsString.getInteger();
	}
}

void DatabaseManager::deleteRecordWithCount(const StringPimpl &key,
											const StringPimpl &value)
{
	vector<StringPimpl> files;

	//decrement the size by one
	if(recordCountExists(key, value))
	{
		int size = getRecordTotalCount(key);
		addRecord(m_reserved + key + "_@size_@", StringPimpl::getString(size - 1));
		deleteRecord(m_reserved + key + "_@existence_@" + value);
	}
}

bool DatabaseManager::recordCountExists(const StringPimpl &key)
{
	return recordExists(m_reserved + key + "_@size_@");
}

bool DatabaseManager::recordExists(const StringPimpl &key, const StringPimpl &value)
{
	StringPimpl record = getRecord(key, true);
	return record == value;
}

bool DatabaseManager::recordCountExists(const StringPimpl &key, const StringPimpl &value)
{
	return recordExists(m_reserved + key + "_@existence_@" + value, value);
}

StringPimpl *DatabaseManager::getRecordRange(const StringPimpl &key, unsigned int &size)
{
	vector<StringPimpl> records = getRecordRangeAsVector(key);
	size = records.size();
	if(records.size() > 0)
	{
		StringPimpl *arrayList = new StringPimpl[records.size()];
		for(unsigned int i = 0; i < records.size(); ++i)
		{
			arrayList[i] = records.at(i);
		}
		return arrayList;
	}
	else
	{
		return 0;
	}
}

StringPimpl *DatabaseManager::getRecordCountList(const StringPimpl &key, unsigned int &size)
{
	return getRecordRange(m_reserved + key + "_@existence_@", size);
}

vector<StringPimpl> DatabaseManager::getRecordCountListAsVector(const StringPimpl &key)
{
	return getRecordRangeAsVector(m_reserved + key + "_@existence_@");
}


bool DatabaseManager::recordRangeExists(const StringPimpl &key)
{
	//Go through the range of the existence keys and 
	//add them to the list
	Dbc *cursor = NULL;
	try 
	{
		Dbt dbKey((void *)key.c_str(), key.size() + 1);
		Dbt dbData;

		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET_RANGE);
		while(ret != DB_NOTFOUND)
		{
			StringPimpl dataString = StringPimpl((char *) dbData.get_data());
			StringPimpl keyString = StringPimpl((char *) dbKey.get_data());
			if(!keyString.startsWith(key) || keyString == key) {
				//We are at the end of the range
				break;
			}
			else 
			{
				cursor->close();
				return true;
			}
		}
		cursor->close();
		return false;
	}
	catch (DbException &e) 
	{
		std::cerr << "Error in deleteRecordRange: "
				   << e.what() << e.get_errno() << std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
		return false;
	}
}

vector<StringPimpl> DatabaseManager::getRecordRangeAsVector(const StringPimpl &key)
{
	vector<StringPimpl> list;

	//Go through the range of the existence keys and 
	//add them to the list
	Dbc *cursor = NULL;
	try 
	{
		Dbt dbKey((void *)key.c_str(), key.size() + 1);
		Dbt dbData;

		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET_RANGE);
		while(ret != DB_NOTFOUND)
		{
			StringPimpl dataString = StringPimpl((char *) dbData.get_data());
			StringPimpl keyString = StringPimpl((char *) dbKey.get_data());
			if(!keyString.startsWith(key) || keyString == key) {
				//We are at the end of the range
				break;
			} 
			list.push_back(dataString);
			ret = cursor->get(&dbKey, &dbData, DB_NEXT);
		}
		cursor->close();
	}
	catch (DbException &e) 
	{
		std::cerr << "Error in deleteRecordRange: "
				   << e.what() << e.get_errno() << std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
	}

	return list;
}

void DatabaseManager::printEntireDB()
{
	Dbc *cursor = NULL;
	try 
	{
		Dbt dbKey;
		Dbt dbData;

		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET_RANGE);
		while(ret != DB_NOTFOUND)
		{
			StringPimpl dataString = StringPimpl((char *) dbData.get_data());
			StringPimpl keyString = StringPimpl((char *) dbKey.get_data());
			cout << "key :" << keyString.c_str() << endl << "data:" << dataString.c_str() << endl << endl;
			ret = cursor->get(&dbKey, &dbData, DB_NEXT);
		}
		cursor->close();
	}
	catch (DbException &e) 
	{
		std::cerr << "Error in deleteRecordRange: "
				   << e.what() << e.get_errno() << std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
	}
}

void DatabaseManager::deleteRecordCount(const StringPimpl &key)
{
	deleteRecordRange(m_reserved + key);
}

void DatabaseManager::addRecord(const StringPimpl &key,
								const StringPimpl &value)
{
	//Set up the key
	Dbt dbKey;
	dbKey.set_data((void *)key.c_str());
	dbKey.set_size((key.size() + 1) * sizeof(char));

	//Set up the data to insert
	Dbt dbData;
	dbData.set_data((void *)value.c_str());
	dbData.set_size((value.size() + 1) * sizeof(char));
	
	try 
	{
		m_pimpl->checkTSSInit();
		int ret = m_pimpl->m_database->put(&(**m_pimpl->m_transaction), &dbKey, &dbData, 0);
	}
	catch (DbException &e) 
	{
            std::cerr << "Error in addRecord: "
                       << e.what() << e.get_errno() << std::endl;
    }
}

void DatabaseManager::deleteRecord(const StringPimpl &key)
{
	Dbc *cursor = NULL;
	
	try 
	{
		Dbt dbKey((void *)key.c_str(), key.size() + 1);
		Dbt dbData;

		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET);
		if(ret != DB_NOTFOUND)
		{
			cursor->del(0);
		}
		cursor->close();
	}
	catch (DbException &e) 
	{
        std::cerr << "Error in addRecord: "
                   << e.what() << e.get_errno() << std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
    }

}


void DatabaseManager::deleteRecordRange(const StringPimpl &key)
{
	Dbc *cursor = NULL;

	try 
	{
		Dbt dbKey((void *)key.c_str(), key.size() + 1);
		Dbt dbData;

		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_SET_RANGE);
		
		while(ret != DB_NOTFOUND)
		{
			StringPimpl dataString = StringPimpl((char *) dbData.get_data());
			StringPimpl keyString = StringPimpl((char *) dbKey.get_data());
			if(!keyString.startsWith(key)) {
				//We are at the end of the range
				break;
			} 
			cursor->del(0);
			ret = cursor->get(&dbKey, &dbData, DB_NEXT);
		}
		cursor->close();
	}
	catch (DbException &e) 
	{
        std::cerr << "Error in deleteRecordRange: "
                   << e.what() << e.get_errno() << std::endl;
		if(cursor != NULL)
		{
			cursor->close();
		}
    }
}

void DatabaseManager::deleteRecordRange(const StringPimpl &key,
										const StringPimpl &range)
{
	Dbc *cursor = NULL;

	try 
	{
		Dbt dbKey((void *)key.c_str(), key.size() + 1);
		Dbt dbData((void *) range.c_str(), range.size() + 1);

		m_pimpl->checkTSSInit();
		m_pimpl->m_database->cursor(&(**m_pimpl->m_transaction), &cursor, m_pimpl->m_cursorFlags);
		int ret = cursor->get(&dbKey, &dbData, DB_GET_BOTH_RANGE);
		
		while(ret != DB_NOTFOUND)
		{
			cursor->del(0);
			ret = cursor->get(&dbKey, &dbData, DB_NEXT);
		}
		cursor->close();
	}
	catch (DbException &e) 
	{
            std::cerr << "Error in addRecord: "
                       << e.what() << e.get_errno() << std::endl;
			if(cursor != NULL)
			{
				cursor->close();
			}
    }
}

DatabaseManager::~DatabaseManager()
{
	//Close the database
	if(m_pimpl->m_database != 0)
	{
        try 
		{
			m_pimpl->m_database->close(0);
        } 
		catch (DbException &e) 
		{
            std::cerr << "Error in closing the database: "
                       << e.what() << e.get_errno() << std::endl;
        }
	}

	//Close the DB environment
	if(m_pimpl->m_databaseEnvironment != 0) 
	{
        try 
		{
			m_pimpl->m_databaseEnvironment->close(0);
        } 
		catch (DbException &e) 
		{
            std::cerr << "Error in closing the database environment: "
                       << e.what() << e.get_errno() << std::endl;
        }
	}

	//Delete the databse
	if(m_pimpl->m_database != 0)
	{
		///@todo why can't we delete this without crashing?
		//delete m_pimpl->m_database;
	}

	//Delete the environment
	if(m_pimpl->m_databaseEnvironment != 0)
	{
		///@todo why can't we delete this without crashing?
		//delete m_pimpl->m_databaseEnvironment;
	}

	//delete the pimpl
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace rebecca
