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

//Custom tag includes
#include "CustomTagsImpl.h"
#include "CustomTopic.h"
#include "CustomAIML.h"
#include "Links.h"
#include "Html.h"
#include "WebPage.h"
#include "InnerTemplateAIMLTags.h"

//Std includes
#include <fstream>


namespace customTag
{
namespace impl
{

CustomTagsImpl::CustomTagsImpl() 
	throw(InternalProgrammerErrorException &)
	: m_templateSideThat(false)
{
 /*
  * Do nothing other than set the 
  * m_templateSideThat to false.
  */
}


Tag *CustomTagsImpl::createTagClass(const StringPimpl &className)
	throw(InternalProgrammerErrorException &)
{
	if(className == "topic")
	{
		/*
		 * Found the tag <topic> so now return an 
		 * instance of the class.
		 */
		return new CustomTopic(m_htmlPage);
	}
	else if(className == "aiml")
	{
		/*
		 * Found the tag <aiml> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomAiml(m_htmlPage);
	}
	else if(className == "gender")
	{
		/*
		 * Found the tag <gender> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomGender;
	}
	else if(className == "bot")
	{
		/*
		 * Found the tag <bot> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomBot;
	}
	else if(className == "condition")
	{
		/*
		 * Found the tag <condition> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomCondition;
	}
	else if(className == "li")
	{
		/*
		 * Found the tag <li> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomLi;
	}
	else if(className == "date")
	{
		/*
		 * Found the tag <date> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomDate;
	}
	else if(className == "formal")
	{
		/*
		 * Found the tag <formal> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomFormal;
	}
	else if(className == "gossip")
	{
		/*
		 * Found the tag <gossip> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomGossip;
	}
	else if(className == "get")
	{
		/*
		 * Found the tag <get> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomGet;
	}
	else if(className == "id")
	{
		/*
		 * Found the tag <id> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomId;
	}
	else if(className == "input")
	{
		/*
		 * Found the tag <input> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomInput;
	}
	else if(className == "lowercase")
	{
		/*
		 * Found the tag <lowercase> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomLowerCase;
	}
	else if(className == "person")
	{
		/*
		 * Found the tag <person> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomPerson;
	}
	else if(className == "person2")
	{
		/*
		 * Found the tag <person2> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomPerson2;
	}
	else if(className == "random")
	{
		/*
		 * Found the tag <random> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomRandom;
	}
	else if(className == "sentence")
	{
		/*
		 * Found the tag <sentence> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomSentence;
	}
	else if(className == "set")
	{
		/*
		 * Found the tag <set> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomSet;
	}
	else if(className == "size")
	{
		/*
		 * Found the tag <size> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomSize;
	}
	else if(className == "srai")
	{
		/*
		 * Found the tag <srai> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomSrai;
	}
	else if(className == "star")
	{
		/*
		 * Found the tag <star> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomStar;
	}
	else if(className == "system")
	{
		/*
		 * Found the tag <system> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomSystem;
	}
	else if(className == "thatstar")
	{
		/*
		 * Found the tag <thatstar> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomThatStar;
	}
	else if(className == "think")
	{
		/*
		 * Found the tag <think> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomThink;
	}
	else if(className == "topicstar")
	{
		/*
		 * Found the tag <topicstar> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomTopicStar;
	}
	else if(className == "uppercase")
	{
		/*
		 * Found the tag <uppercase> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomUpperCase;
	}
	else if(className == "version")
	{
		/*
		 * Found the tag <version> so now return an 
		 * instance of our overriden class 
		 */
		return new CustomVersion;
	}
	else if(className == "sr")
	{
		/*
		 * sr is a AIML shortcut for <srai><star/></srai>
		 * In order to expand this shortcut we create a 
		 * NonImplemented tag and add to the NonImplemented 
		 * tag a srai which has a star added to it.
		 *
		 * So now, on the Rebecca engine will be 
		 * <nonImplemented><srai><star/></srai><nonimplemented>
		 * This is okay, because when nonimplemented is taken
		 * apart by the engine it will in turn call the 
		 * <srai> and <star> tags.
		 * 
		 * The desired functionality will occur.
		 */
		Tag *nonImplemented = new NonImplemented;
		Tag *srai = new CustomSrai;
		Tag *star = new CustomStar;
		srai->handleInnerTag(star);
		nonImplemented->handleInnerTag(srai);
		return nonImplemented;		
	}
	else if(className == "template")
	{
		/*
		 * We use this to figure out that we are now 
		 * within a template and thus should use
		 * a templateSideThat when we see the string "template"
		 */
		m_templateSideThat = true;
		return 0;
	} 
	else if(className == "category")
	{
		/*
		 * We use this to figure out that we are now 
		 * not within a template and thus should not use
		 * a templateSideThat when we see the string "template"
		 */
		m_templateSideThat = false;

	   /*
		* Let rebecca use her default Category.  We do this by
		* returning a 0.  When rebecca sees a
		* 0, she will then use her default 
		* implementation of the category.
		*/
		return 0;
	}
	else if(className == "that")
	{
		if(m_templateSideThat)
		{
			/*
			 * It is a template side that so return
			 * our version of it
			 */
			return new CustomTemplateSideThat;
		}
		else
		{
			/*
			 * Let rebecca use her default Template.  We only 
			 * provide the template side that.  We do this by
			 * returning a 0.  When rebecca sees an
			 * 0, she will then use her default 
			 * implementation of the template.
			 */
			return 0;
		}
	}
	else 
	{
		/*
		 * If you cannot find your custom tag class you 
		 * *must* return a 0.
		 */
		return 0;
	}
}

CustomTagsImpl::~CustomTagsImpl()
{
	/*
	 * Write out the entire web pages
	 * We are about to be destroyed 
	 * so this will complete us
	 */
	m_htmlPage.writeWebPages();	
}

} //end of namespace impl
} //end namespace customTag
