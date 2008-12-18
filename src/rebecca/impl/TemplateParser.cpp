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

//Stl includes
#include <iostream>
using namespace std;

//Xerces includes
#include <xercesc/parsers/SAXParser.hpp>
XERCES_CPP_NAMESPACE_USE

//Rebecca includes
#include <rebecca/impl/TemplateParser.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/GraphBuilderInternal.h>
#include <rebecca/impl/utils/Transcode.h>
#include <rebecca/framework/Tag.h>
#include <rebecca/framework/Pattern.h>
#include <rebecca/framework/TemplateSideThat.h>
#include <rebecca/framework/Srai.h>
#include <rebecca/framework/Star.h>
#include <rebecca/framework/Set.h>
#include <rebecca/framework/Get.h>
#include <rebecca/framework/Think.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/framework/Random.h>
#include <rebecca/framework/Li.h>
#include <rebecca/framework/Condition.h>
#include <rebecca/framework/NonImplemented.h>
#include <rebecca/framework/Input.h>
#include <rebecca/framework/ThatStar.h>
#include <rebecca/framework/TopicStar.h>
#include <rebecca/framework/Person.h>
#include <rebecca/framework/Person2.h>
#include <rebecca/framework/Gender.h>
#include <rebecca/framework/Formal.h>
#include <rebecca/framework/UpperCase.h>
#include <rebecca/framework/LowerCase.h>
#include <rebecca/framework/Sentence.h>
#include <rebecca/framework/Bot.h>
#include <rebecca/framework/Date.h>
#include <rebecca/framework/Id.h>
#include <rebecca/framework/Size.h>
#include <rebecca/framework/Version.h>
#include <rebecca/framework/System.h>
#include <rebecca/framework/Gossip.h>
#include <rebecca/framework/CustomTags.h>
#include <rebecca/framework/Learn.h>
using namespace rebecca::impl::utils;

namespace rebecca
{
namespace impl
{

void TemplateParser::endDocument()
{ 
}

TemplateParser::TemplateParser() 
	: m_currentTemplate(0)
{
}

StringPimpl TemplateParser::getTemplateString() 
{ 
	if(m_currentTemplate != 0)
	{
		m_templateString = m_currentTemplate->getString();
		delete m_currentTemplate;
		m_currentTemplate = 0;
	}
	//delete all of our memory we used
	for(unsigned int i = 0; i < m_tagsToDelete.size(); ++i)
	{
		delete m_tagsToDelete.at(i);
	}
	m_tagsToDelete.clear();

	return m_templateString;
}


Tag *TemplateParser::createTagClass(const StringPimpl &className) 
{
	Tag *tag = 0;
	if(className == "template") //3
	{
		//don't push back template
		//we will delete it latter
		tag = new Template;
		return tag;
	}
	else if(className == "srai") //5
	{
		tag = new Srai;
	}
	else if(className == "star") //7
	{
		tag = new Star;
	}
	else if(className == "set") //8
	{
		tag = new Set;
	}
	else if(className == "get") //9
	{
		tag = new Get;
	}
	else if(className == "think") //10
	{
		tag = new Think;
	}
	else if(className == "person") //11
	{
		tag = new Person;
	}
	else if(className == "bot") //12
	{
		tag = new Bot;
	}
	else if(className == "that")
	{
		tag = new TemplateSideThat;
	}
	else if(className == "condition") //13
	{
		tag = new Condition;
	}
	else if(className == "li") //14
	{
		tag = new Li; 
	} 
	else if(className == "random") //15
	{
		tag = new Random;
	}
	else if(className == "sr") //16
	{
		tag = new NonImplemented;

		Tag *srai = new Srai;
		m_tagsToDelete.push_back(srai);

		Tag *star = new Star;
		m_tagsToDelete.push_back(star);

		srai->handleInnerTag(star);
		tag->handleInnerTag(srai);
	}
	else if(className == "input") //17
	{
		tag = new Input;
	}
	else if(className == "thatstar") //18
	{
		tag = new ThatStar;
	}
	else if(className == "topicstar") //19
	{
		tag = new TopicStar;
	}
	else if(className == "person2") //20
	{
		tag = new Person2;
	}
	else if(className == "gender") //21
	{
		tag = new Gender;
	}
	else if(className == "lowercase") //22
	{
		tag = new LowerCase;
	}
	else if(className == "uppercase") //23
	{
		tag = new UpperCase;
	}
	else if(className == "sentence") //24
	{
		tag = new Sentence;
	}
	else if(className == "formal") //25
	{
		tag = new Formal;
	}
	else if(className == "date") //26
	{
		tag = new Date;
	}
	else if(className == "id") //27
	{
		tag = new Id;
	}
	else if(className == "size") //28
	{
		tag = new Size;
	}
	else if(className == "version") //29
	{
		tag = new Version;
	}
	else if(className == "system") //30
	{
		tag = new System;
	}
	else if(className == "gossip") //31
	{
		tag = new Gossip;
	}
	else if(className == "learn") //33
	{
		tag = new Learn;
	}
	else
	{
		//This tag is not implemented.  More than likely a
		//bogus tag such as HTML:(something).  Just return
		//a non implemented tag that just takes the text 
		//inbetween and returns it.  This way if you have a 
		//tag such as <html:em>some text<html:em>  the 
		//unimplemented tag will return "some text"
		//Unimplemeneted tag found.  Name is: className
		tag = new PlainWord;
	}
	m_tagsToDelete.push_back(tag);
	return tag;
}

void TemplateParser::characters(const XMLCh * const chars, 
                              const unsigned int length)
{
	try
	{

		Transcode someChars(chars);
		m_currentStartElement->addCharacters(someChars.getStringPimpl());
	}
	catch(nullString &)
	{
		//Do nothing
		//caught nullString on someChars.getChar()
	}
}


void TemplateParser::startElement(const XMLCh* const name, AttributeList& attributes)
{
	Transcode attributeName;
	Transcode attributeType;
	Transcode attributeValue;
	Transcode message;
	
	try 
	{
		message.translate(name);		
		m_currentStartElement = createTagClass(message.getChar()); 
		m_tagStack.push(m_currentStartElement);
	}
	catch(nullString &)
	{
		//Do nothing	
		//caught nullString on message.getChar()
	}

	for(unsigned int i = 0; i < attributes.getLength(); i++)
	{
		try
		{
			attributeName.translate(attributes.getName(static_cast<unsigned int>(i)));
			attributeValue.translate(attributes.getValue(static_cast<unsigned int>(i)));
			m_currentStartElement->setAttribute(attributeName.getStringPimpl(), attributeValue.getStringPimpl());
		}
		catch(nullString &)
		{
			//Do nothing	
			//caught nullString on attributeValue.getChar()
		}
	}
}

void TemplateParser::endElement(const XMLCh *const name)
{
	try
	{
		Transcode element(name);
		if(m_tagStack.empty())
		{
			//Internal programmer Error the stack is empty
			InternalProgrammerErrorExceptionImpl("[void GraphHandler::endElement(const XMLCh *const name)], Stack is empty");
		}
		
		Tag *tag = m_tagStack.top();
		m_tagStack.pop();
		if(!m_tagStack.empty())
		{
			m_tagStack.top()->handleInnerTag(tag);
			m_currentStartElement = m_tagStack.top();
		}
		else if(m_tagStack.empty() && tag->instanceOf("Template"))
		{
			Template *t = static_cast<Template *>(tag);
			if(t != 0)
			{
				if(m_currentTemplate != 0)
				{
					m_tagsToDelete.push_back(m_currentTemplate);
				}
				m_currentTemplate = t;
			}
		}
	}
	catch(nullString &)
	{
		//Do nothing
		//caught nullString on someChars.getChar()
	}
}

} // end of namespace impl
} // end of namespace rebecca

