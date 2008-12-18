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
#include <rebecca/impl/GraphBuilderAIML.h>
#include <rebecca/impl/StarsManager.h>
#include <rebecca/impl/DatabaseManager.h>
#include <rebecca/framework/FrameworkFactory.h>

using namespace rebecca::impl;

namespace rebecca
{
namespace framework
{
namespace impl
{

class FrameworkFactoryImpl
{
	public:
		FrameworkFactoryImpl()
			: m_builder(0)		
		{ }
		static FrameworkFactory *m_instance;
		GraphBuilderFramework *m_builder;
};

//static initialization
FrameworkFactory *FrameworkFactoryImpl::m_instance = 0;

FrameworkFactory::FrameworkFactory()
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new FrameworkFactoryImpl)

{
}

FrameworkFactory *FrameworkFactory::reset()
	throw(InternalProgrammerErrorException &)
{
	if(FrameworkFactoryImpl::m_instance != 0)
	{
		delete FrameworkFactoryImpl::m_instance;
	}
	FrameworkFactoryImpl::m_instance = new FrameworkFactory();
	FrameworkFactoryImpl::m_instance->m_pimpl->m_builder = GraphBuilderAIML::getInstance();
	return FrameworkFactoryImpl::m_instance;
}

FrameworkFactory *FrameworkFactory::getInstance()
	throw(InternalProgrammerErrorException &)
{
	//Should have been initialized 
	return FrameworkFactoryImpl::m_instance;
}

GraphBuilderFramework *FrameworkFactory::getGraphBuilderFramework()
	throw(InternalProgrammerErrorException &)
{
	return m_pimpl->m_builder;
}

FrameworkFactory::~FrameworkFactory()
{
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
