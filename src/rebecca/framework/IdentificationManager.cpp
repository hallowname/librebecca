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
#include <rebecca/framework/IdentificationManager.h>

//boost includes
#include <boost/thread/tss.hpp>
using namespace boost;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
#endif

namespace rebecca
{
namespace framework
{
namespace impl
{

class IdentificationManagerImpl
{
	public:
		IdentificationManagerImpl()
			: m_threadSpecific(false)
		{ }
		StringPimpl m_userIdLocal;
		StringPimpl m_botIdLocal;
		StringPimpl m_endUserIdLocal;
		bool m_threadSpecific;
		thread_specific_ptr<StringPimpl> m_userId;
		thread_specific_ptr<StringPimpl> m_botId;
		thread_specific_ptr<StringPimpl> m_endUserId;
		static IdentificationManager *m_instance;

		void init()
		{
			if(m_userId.get() == 0)
			{
				m_userId.reset(new StringPimpl("default"));
			}
			if(m_botId.get() == 0)
			{
				m_botId.reset(new StringPimpl("default"));
			}
			if(m_endUserId.get() == 0)
			{
				m_endUserId.reset(new StringPimpl("default"));
			}
		}
};

//static initializations
IdentificationManager *IdentificationManagerImpl::m_instance = 0;

IdentificationManager::IdentificationManager()
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new IdentificationManagerImpl)

{

}

IdentificationManager *IdentificationManager::reset()
	throw(InternalProgrammerErrorException &)
{
	if(IdentificationManagerImpl::m_instance != 0)
	{
		delete IdentificationManagerImpl::m_instance;
	}
	
	IdentificationManagerImpl::m_instance = new IdentificationManager();
	return IdentificationManagerImpl::m_instance;
}

IdentificationManager *IdentificationManager::getInstance()
	throw(InternalProgrammerErrorException &)
{
	return IdentificationManagerImpl::m_instance;
}

void IdentificationManager::setThreadSpecific(bool mode)
	throw(InternalProgrammerErrorException &)
{
	m_pimpl->m_threadSpecific = mode;
}

StringPimpl IdentificationManager::getUserId()
	throw(InternalProgrammerErrorException &)
{
	if(m_pimpl->m_threadSpecific)
	{
		m_pimpl->init();
		return (*m_pimpl->m_userId.get());
	}
	else
	{
		return m_pimpl->m_userIdLocal;
	}
}

StringPimpl IdentificationManager::getBotId()
	throw(InternalProgrammerErrorException &)
{
	if(m_pimpl->m_threadSpecific)
	{
		m_pimpl->init();
		return (*m_pimpl->m_botId.get());
	}
	else
	{
		return m_pimpl->m_botIdLocal;
	}
}

StringPimpl IdentificationManager::getEndUserId()
	throw(InternalProgrammerErrorException &)
{
	if(m_pimpl->m_threadSpecific)
	{
		m_pimpl->init();
		return (*m_pimpl->m_endUserId.get());
	}
	else
	{
		return m_pimpl->m_endUserIdLocal;
	}
}

void IdentificationManager::setUserIdBotIdEndUserId(const StringPimpl &userId, 
													const StringPimpl &botId,
													const StringPimpl &endUserId)
	throw(InternalProgrammerErrorException &)
{
	if(m_pimpl->m_threadSpecific)
	{
		m_pimpl->init();
		*(m_pimpl->m_userId.get()) = userId;
		*(m_pimpl->m_botId.get()) = botId;
		*(m_pimpl->m_endUserId.get()) = endUserId;
	}
	else
	{
		m_pimpl->m_userIdLocal = userId;
		m_pimpl->m_botIdLocal = botId;
		m_pimpl->m_endUserIdLocal = endUserId;
	}
}

IdentificationManager::~IdentificationManager()
{
	delete m_pimpl;
}

} //end namespace impl
} //end namespace framework
} //end namespace rebecca
