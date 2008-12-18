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
#include <rebecca/impl/RemoveGraphHandler.h>
#include <rebecca/framework/RemoveTopic.h>
#include <rebecca/impl/CustomTagWithDelete.h>
#include <rebecca/impl/GraphBuilderAIML.h>
#include <rebecca/framework/Category.h>
#include <rebecca/framework/Pattern.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/framework/TemplateSideThat.h>
#include <rebecca/framework/RemoveAIML.h>
#include <rebecca/framework/PatternSideThat.h>

namespace rebecca
{
namespace impl
{

RemoveGraphHandler::RemoveGraphHandler(NodeMapper &root) 
	: GraphHandler(root)
{
}

Tag *RemoveGraphHandler::createTagClass(const StringPimpl &className)
{
	
	map<StringPimpl, CustomTagWithDelete> &customTags = GraphBuilderAIML::getInstance()->getCustomTagsMapRef();
	typedef map<StringPimpl, CustomTagWithDelete>::iterator I;

	Tag *tag = 0;
	for(I it = customTags.begin(); it != customTags.end(); ++it)
	{
		tag = (it->second).m_customTags->createTagClass(className);
		if(tag != 0)
		{	
			m_tagsToDelete.push_back(tag);
			return tag;
		}
	}

	if(className == "category") //1
	{
		--m_size;
		m_templateSideThat = false;
		tag = new Category;
	}
	else if(className == "pattern") //2
	{
		tag = new Pattern;
	}
	else if(className == "topic") //4
	{
		tag = new RemoveTopic;
	}
	else if(className == "that") //6
	{
		if(m_templateSideThat)
		{
			tag = new TemplateSideThat;
		}
		else 
		{
			tag = new PatternSideThat;
		}
	}
	else if(className == "template") //3
	{
		m_templateSideThat = true;
		tag = new PlainWord;
	}
	else if(className == "aiml")
	{
		tag = new RemoveAIML;
	}
	else
	{
		tag = new PlainWord;
	}
	m_tagsToDelete.push_back(tag);
	return tag;
}


} // end of namespace impl
} // end of namespace rebecca
