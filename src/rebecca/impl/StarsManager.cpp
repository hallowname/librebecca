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
#include <rebecca/impl/StarsManager.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/framework/IdentificationManager.h>
using namespace rebecca::framework;

//boost includes
#include <boost/thread/tss.hpp>
using namespace boost;

//std include
#include <map>
#include <vector>
using namespace std;

namespace rebecca
{
namespace impl
{

///@todo really we don't need map<String, vector<String > > here.  We could just use vector's and skip it.
//The reason we can skip it is because only one thread at a time will be setting and using the star storages
//so I can't see how one thread would be setting it for multiple userid, botid's

class StarsManagerImpl
{
	public:
		StarsManagerImpl() 
			: m_identificationManager(0)
		{ } 

		static StarsManager *m_instance;
		IdentificationManager *m_identificationManager;
		thread_specific_ptr<map<StringPimpl, vector<StringPimpl> > > m_defaultStarStorage;
		thread_specific_ptr<map<StringPimpl, vector<StringPimpl> > > m_thatStarStorage;
		thread_specific_ptr<map<StringPimpl, vector<StringPimpl> > > m_topicStarStorage;
		thread_specific_ptr<map<StringPimpl, bool> >m_useDefaultStar;
		thread_specific_ptr<map<StringPimpl, bool> >m_useThatStar;
		thread_specific_ptr<map<StringPimpl, bool> >m_useTopicStar;

		StringPimpl getFromDefaultStorage(const StringPimpl &key,
			                              unsigned int index,
									      thread_specific_ptr<map<StringPimpl, vector<StringPimpl> > > &defaultStorage)

		{
			if (defaultStorage.get() == 0)
			{
				defaultStorage.reset(new map<StringPimpl, vector<StringPimpl> >);
			}
			typedef map<StringPimpl, vector<StringPimpl> >::const_iterator CI;
			CI it = defaultStorage->find(key);
			if(it != defaultStorage->end())
			{
				if(index > it->second.size())
				{
					throw IllegalArgumentExceptionImpl("Size Exceeded");
				}
				else
				{
					return it->second.at(it->second.size() - index);
				}
			}
			else
			{
				return StringPimpl();
			}
		}
		
		void putIntoDefaultStorage(const StringPimpl &key, 
			                       const StringPimpl &value,
			                       thread_specific_ptr<map<StringPimpl, vector<StringPimpl> > > &defaultStorage)
		{
			if (defaultStorage.get() == 0)
			{
				defaultStorage.reset(new map<StringPimpl, vector<StringPimpl> >);
			}
			typedef map<StringPimpl, vector<StringPimpl> >::iterator I;
			I it = defaultStorage->find(key);
			if(it != defaultStorage->end())
			{
				it->second.push_back(value);
			}
			else
			{                          
				vector<StringPimpl> v;
				v.push_back(value);
				defaultStorage->insert(pair<StringPimpl, vector<StringPimpl> >(key, v));
			}
		}
		
		void clearStorage(thread_specific_ptr<map<StringPimpl, vector<StringPimpl> > > &defaultStorage)
		{
			map<StringPimpl, vector<StringPimpl> > *storagePtr = defaultStorage.get();
			defaultStorage.reset(new map<StringPimpl, vector<StringPimpl> >);
		}
		
		void clearStorage(thread_specific_ptr<map<StringPimpl, bool> > &boolean)
		{
			boolean.reset(new map<StringPimpl, bool>);
		}

		void clearStorage()
		{
			clearStorage(m_defaultStarStorage);
			clearStorage(m_topicStarStorage);
			clearStorage(m_thatStarStorage);
			clearStorage(m_useDefaultStar);
			clearStorage(m_useThatStar);
			clearStorage(m_useTopicStar);
		}
		
		void addTopicStar(const StringPimpl &star)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			putIntoDefaultStorage("_@" + userId + "_@" + botId + "_@" + endUserId + "_@", star, m_topicStarStorage);
		}

		void addThatStar(const StringPimpl &star)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			putIntoDefaultStorage("_@" + userId +"_@" + botId + "_@" + endUserId + "_@", star, m_thatStarStorage);
		}

		void addDefaultStar(const StringPimpl &star)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			putIntoDefaultStorage("_@" + userId + "_@" + botId + "_@" + endUserId + "_@", star, m_defaultStarStorage);
		}

		StringPimpl getTopicStar(unsigned const int &index)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			return getFromDefaultStorage("_@" + userId + "_@" + botId + "_@" + endUserId + "_@", index, m_topicStarStorage);
		}

		StringPimpl getThatStar(unsigned const int &index)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			return getFromDefaultStorage("_@" + userId + "_@" + botId + "_@" + endUserId + "_@", index, m_thatStarStorage);
		}

		StringPimpl getDefaultStar(unsigned const int &index)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			return getFromDefaultStorage("_@" + userId + "_@" + botId + "_@" + endUserId + "_@", index, m_defaultStarStorage);
		}
		
		void addStar(const StringPimpl &star)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			checkStarInitialization();
			StringPimpl key = "_@" + userId + "_@" + botId + "_@" + endUserId + "_@";
			typedef map<StringPimpl, bool>::iterator I;
			I it = m_useTopicStar->find(key);
			if(it != m_useTopicStar->end() && it->second == true)
			{
				addTopicStar(star);
			}
			else
			{
				I ij = m_useThatStar->find(key);
				if(ij != m_useThatStar->end() && ij->second == true)
				{
					addThatStar(star);
				}
				else
				{
					addDefaultStar(star);
				}
			}
		}

		StringPimpl getStar(unsigned const int &index)
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			checkStarInitialization();
			StringPimpl key = "_@" + userId + "_@" + botId + "_@" + endUserId + "_@";
			typedef map<StringPimpl, bool>::iterator I;
			I it = m_useTopicStar->find(key);
			if(it != m_useTopicStar->end() && it->second == true)
			{
				return getTopicStar(index);
			}
			else
			{
				I ij = m_useThatStar->find(key);
				if(ij != m_useThatStar->end() && ij->second == true)
				{
					return getThatStar(index);
				}
				else
				{
					return getDefaultStar(index);
				}
			}
		}

		void checkStarInitialization()
		{
			if(m_useDefaultStar.get() == 0)
			{
				m_useDefaultStar.reset(new map<StringPimpl, bool>);
			}

			if(m_useThatStar.get() == 0)
			{
				m_useThatStar.reset(new map<StringPimpl, bool>);
			}

			if(m_useTopicStar.get() == 0)
			{
				m_useTopicStar.reset(new map<StringPimpl, bool>);
			}
		}

		void setUseThatStar()
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			checkStarInitialization();
			StringPimpl key = "_@" + userId + "_@" + botId + "_@" + endUserId + "_@";
			typedef map<StringPimpl, bool>::iterator I;
			I it = m_useThatStar->find(key);
			if(it != m_useThatStar->end())
			{
				it->second = true;
			}
			else
			{
				m_useThatStar->insert(pair<StringPimpl, bool>(key, true));
			}

			I ij = m_useTopicStar->find(key);
			if(ij != m_useTopicStar->end())
			{
				ij->second = false;
			}
			else
			{
				m_useTopicStar->insert(pair<StringPimpl, bool>(key, false));
			}

			I ik = m_useDefaultStar->find(key);
			if(ik != m_useDefaultStar->end())
			{
				ik->second = false;
			}
			else
			{
				m_useThatStar->insert(pair<StringPimpl, bool>(key, false));
			}
		}

		void setUseDefaultStar()
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			checkStarInitialization();
			StringPimpl key = "_@" + userId + "_@" + botId + "_@" + endUserId + "_@";
			typedef map<StringPimpl, bool>::iterator I;
			I it = m_useThatStar->find(key);
			if(it != m_useThatStar->end())
			{
				it->second = false;
			}
			else
			{
				m_useThatStar->insert(pair<StringPimpl, bool>(key, false));
			}

			I ij = m_useTopicStar->find(key);
			if(ij != m_useTopicStar->end())
			{
				ij->second = false;
			}
			else
			{
				m_useTopicStar->insert(pair<StringPimpl, bool>(key, false));
			}

			I ik = m_useDefaultStar->find(key);
			if(ik != m_useDefaultStar->end())
			{
				ik->second = true;
			}
			else
			{
				m_useThatStar->insert(pair<StringPimpl, bool>(key, true));
			}
		}

		void setUseTopicStar()
		{
			StringPimpl userId = m_identificationManager->getUserId();
			StringPimpl botId = m_identificationManager->getBotId();
			StringPimpl endUserId = m_identificationManager->getEndUserId();

			checkStarInitialization();
			StringPimpl key = "_@" + userId + "_@" + botId + "_@" + endUserId + "_@";
			typedef map<StringPimpl, bool>::iterator I;
			I it = m_useThatStar->find(key);
			if(it != m_useThatStar->end())
			{
				it->second = false;
			}
			else
			{
				m_useThatStar->insert(pair<StringPimpl, bool>(key, false));
			}

			I ij = m_useTopicStar->find(key);
			if(ij != m_useTopicStar->end())
			{
				ij->second = true;
			}
			else
			{
				m_useTopicStar->insert(pair<StringPimpl, bool>(key, true));
			}

			I ik = m_useDefaultStar->find(key);
			if(ik != m_useDefaultStar->end())
			{
				ik->second = false;
			}
			else
			{
				m_useThatStar->insert(pair<StringPimpl, bool>(key, false));
			}
		}
};

//static variables initialized
StarsManager *StarsManagerImpl::m_instance = 0;

StarsManager::StarsManager()
	: m_pimpl(new StarsManagerImpl)
{ 

} 

StarsManager *StarsManager::reset()
{
	if(StarsManagerImpl::m_instance != 0)
	{
		delete StarsManagerImpl::m_instance;
	}
	StarsManagerImpl::m_instance = new StarsManager();
	StarsManagerImpl::m_instance->m_pimpl->m_identificationManager = IdentificationManager::getInstance();
	return StarsManagerImpl::m_instance;
}

map<StringPimpl, vector<StringPimpl> >StarsManager::getDefaultStarMap()
{
	return *(m_pimpl->m_defaultStarStorage.get());
}

map<StringPimpl, vector<StringPimpl> >StarsManager::getThatStarMap()
{
	return *(m_pimpl->m_thatStarStorage.get());
}

map<StringPimpl, vector<StringPimpl> >StarsManager::getTopicStarMap()
{
	return *(m_pimpl->m_topicStarStorage.get());
}

void StarsManager::setDefaultStarMap(const map<StringPimpl, vector<StringPimpl> > &starMap)
{
	m_pimpl->m_defaultStarStorage.reset(new map<StringPimpl, vector<StringPimpl> >);
	*(m_pimpl->m_defaultStarStorage.get()) = starMap;
}

void StarsManager::setTopicStarMap(const map<StringPimpl, vector<StringPimpl> > &starMap)
{
	m_pimpl->m_topicStarStorage.reset(new map<StringPimpl, vector<StringPimpl> >);
	*(m_pimpl->m_topicStarStorage.get()) = starMap;
}

void StarsManager::setThatStarMap(const map<StringPimpl, vector<StringPimpl> > &starMap)
{
	m_pimpl->m_thatStarStorage.reset(new map<StringPimpl, vector<StringPimpl> >);
	*(m_pimpl->m_thatStarStorage.get()) = starMap;
}


void StarsManager::clearStars()
{
	m_pimpl->clearStorage();
}

void StarsManager::addStar(const StringPimpl &star)
{ 
	m_pimpl->addStar(star);
}

StringPimpl StarsManager::getThatStar(unsigned const int &index) const
{
	return m_pimpl->getThatStar(index);
}

StringPimpl StarsManager::getTopicStar(unsigned const int &index) const
{
	return m_pimpl->getTopicStar(index);
}

StringPimpl StarsManager::getDefaultStar(unsigned const int &index) const
{
	return m_pimpl->getDefaultStar(index);
}

StringPimpl StarsManager::getStar(unsigned const int &index) const
{ 
	return m_pimpl->getStar(index);
}
		
void StarsManager::setUseThatStar()
{ 
	m_pimpl->setUseThatStar();
}

void StarsManager::setUseTopicStar()
{ 
	m_pimpl->setUseTopicStar();
}

void StarsManager::setUseDefaultStar()
{ 
	m_pimpl->setUseDefaultStar();
}

StarsManager *StarsManager::getInstance()
{
	return StarsManagerImpl::m_instance;
}

StarsManager::~StarsManager()
{

}

} // end of impl namespace
} // end of rebecca namespace
