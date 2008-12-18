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
#include <rebecca/framework/TopicStar.h>
#include <rebecca/framework/FrameworkFactory.h>
#include <rebecca/framework/IdentificationManager.h>
using namespace rebecca::impl;

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

class TopicStarImpl
{
	public:
		TopicStarImpl() 
			: m_index(1) 
		{ }
		int m_index;
		~TopicStarImpl() { } 
};

TopicStar::TopicStar()
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new TopicStarImpl)
{
	addInstanceOf("TopicStar");
}

void TopicStar::setAttribute(const StringPimpl &name, const StringPimpl &value) throw(InternalProgrammerErrorException &)
{
	try
	{
		if(name == "index" && (!value.empty()))
		{
			m_pimpl->m_index = value.getInteger();
		}
	}
	catch(NumberFormatException &)
	{
		//Error, the cast to a numeric value failed
		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().topicStarTagNumericConversionError("Index string is not numeric, " + value, ident->getUserId(), ident->getBotId(), ident->getEndUserId()); 
	}
}

StringPimpl TopicStar::getString() const
	throw(InternalProgrammerErrorException &)
{
	try
	{
		return FrameworkFactory::getInstance()->getGraphBuilderFramework()->getTopicStar(m_pimpl->m_index);
	}
	catch(IllegalArgumentException &)
	{
		//Size Exceeded
		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().topicStarTagSizeExceeded(ident->getUserId(), ident->getBotId(), ident->getEndUserId());
		return StringPimpl();
	}
	catch(Exception &)
	{
		//Another exception occured, returning empty string
		return StringPimpl();
	}
}

TopicStar::~TopicStar()
{ 
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
