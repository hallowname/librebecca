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
#include <rebecca/impl/Exceptions.h>
using namespace rebecca::impl;

#include <rebecca/framework/Pattern.h>
#include <rebecca/framework/PatternSideThat.h>
#include <rebecca/framework/Template.h>
#include <rebecca/framework/FrameworkFactory.h>
#include <rebecca/framework/IdentificationManager.h>
#include <rebecca/framework/Category.h>

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

class CategoryImpl
{
	public:
		CategoryImpl()
			: m_that(0),
			  m_template(0),
			  m_pattern(0)
		{ }

		PatternSideThat *m_that;
		Template *m_template;
		Pattern *m_pattern;
	
		//A const string to the default star of "*"
		static const StringPimpl m_defaultStar;
};

const StringPimpl CategoryImpl::m_defaultStar("*");

Category::Category()   
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new CategoryImpl)
{
	addInstanceOf("Category");
	FrameworkFactory *factory = FrameworkFactory::getInstance();
	IdentificationManager *ident = IdentificationManager::getInstance();
	GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
	builder->getCallBacks().categoryLoaded(ident->getUserId(), ident->getBotId(), ident->getEndUserId());
}


void Category::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("PatternSideThat"))
	{
		PatternSideThat *ic = static_cast<PatternSideThat *>(tag);
		m_pimpl->m_that = ic;
	}
	else if(tag->instanceOf("Template"))
	{
		Template *ic = static_cast<Template *>(tag);
		m_pimpl->m_template = ic;
	}
	else if(tag->instanceOf("Pattern"))
	{
		Pattern *ic = static_cast<Pattern *>(tag);
		m_pimpl->m_pattern = ic;
	}
	else if(tag->instanceOf("PlainWord"))
	{
		//ignore plainwords altogether.  This is necessary for the removeFile to work
		///@todo perhaps a better way?  Right now this could cause eroneous things to pass through
	}
	else
	{
		throw InternalProgrammerErrorExceptionImpl("[Category::handleInnerTag] Bad cast, this is not a InnerCategory");
	}
}

const StringPimpl &Category::getPatternString() 
	throw(InternalProgrammerErrorException &)
{
	return m_pimpl->m_pattern->getStringConstRef();
}

const StringPimpl Category::getTemplateString() 
	throw(InternalProgrammerErrorException &)
{
	return m_pimpl->m_template->getString();
}

const StringPimpl &Category::getThatString() 
	throw(InternalProgrammerErrorException &)
{
	if(m_pimpl->m_that == 0)
	{	
		return m_pimpl->m_defaultStar;
	}
	else
	{
		return m_pimpl->m_that->getStringConstRef();
	}
}

const Template *Category::getTemplate() 
	throw(InternalProgrammerErrorException &)
{
	return m_pimpl->m_template;
}

Category::~Category()
{
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
