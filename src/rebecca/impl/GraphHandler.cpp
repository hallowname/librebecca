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
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/GraphHandler.h>
#include <rebecca/impl/utils/Transcode.h>
#include <rebecca/impl/GraphBuilderAIML.h>
#include <rebecca/framework/Category.h>
#include <rebecca/framework/Topic.h>
#include <rebecca/framework/AIML.h>
#include <rebecca/framework/Tag.h>
#include <rebecca/framework/Pattern.h>
#include <rebecca/framework/PatternSideThat.h>
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

void GraphHandler::endDocument()
{ 
	//delete all of our memory we used
	for(unsigned int i = 0; i < m_tagsToDelete.size(); ++i)
	{
		delete m_tagsToDelete.at(i);
	}
	m_tagsToDelete.clear();

	//set the number of categories loaded
	GraphBuilderAIML::getInstance()->setSize(m_size);
}

void GraphHandler::startDocument()
{ 
	m_size = GraphBuilderAIML::getInstance()->getSize();
}

GraphHandler::GraphHandler(NodeMapper &root) 
	: m_rootNodeMapper(root),
	  m_size(0),
	  m_beginTemplate(false)
{
}

Tag *GraphHandler::createTagClass(const StringPimpl &className) 
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
		m_templateSideThat = false;
		++m_size;
		tag = new Category;
	}
	else if(className == "pattern") //2
	{
		tag = new Pattern;
	}
	else if(className == "template") //3
	{
		m_templateSideThat = true;
		tag = new Template;
	}
	else if(className == "topic") //4
	{
		tag = new Topic;
	}
	else if(className == "srai") //5
	{
		tag = new Srai;
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
		m_tagsToDelete.push_back(srai);

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
	else if(className == "aiml") //32
	{
		tag = new AIML;
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

void GraphHandler::characters(const XMLCh * const chars, 
                              const unsigned int length)
{
	try
	{

		Transcode someChars(chars);
		if(m_beginTemplate == true)
		{
			StringPimpl temp = someChars.getStringPimpl();

			temp.transfromByReplacingAll("<", "&lt;");
			temp.transfromByReplacingAll(">", "&gt;");
			temp.transfromByReplacingAll("&", "&amp;");
			temp.transfromByReplacingAll("'", "&apos;");
			temp.transfromByReplacingAll("\"", "&quot;");
				
			m_templateString += temp;
		}
		else
		{
			m_currentStartElement->addCharacters(someChars.getStringPimpl());
		}
	}
	catch(nullString &)
	{
		//Do nothing
		//caught nullString on someChars.getChar()
	}
}


void GraphHandler::startElement(const XMLCh* const name, AttributeList& attributes)
{
	Transcode attributeName;
	Transcode attributeType;
	Transcode attributeValue;
	Transcode message;
	
	try 
	{
		message.translate(name);		

		if(message.getString() == "template")
		{
			m_beginTemplate = true;
			m_templateString.clear();
		}

		if(m_beginTemplate == true)
		{
			m_templateString += "<" + message.getStringPimpl();
		}
		else 
		{
			m_currentStartElement = createTagClass(message.getChar()); 
			m_tagStack.push(m_currentStartElement);
		}
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
			if(!m_beginTemplate)
			{
				m_currentStartElement->setAttribute(attributeName.getStringPimpl(), attributeValue.getStringPimpl());
			}
			else
			{
				m_templateString += " " + attributeName.getStringPimpl() + "=\"" + attributeValue.getStringPimpl() + "\"";
			}
		}
		catch(nullString &)
		{
			//Do nothing	
			//caught nullString on attributeValue.getChar()
		}
	}

	if(m_beginTemplate)
	{
		m_templateString += ">";
	}
}

void GraphHandler::endElement(const XMLCh *const name)
{
	/*
	 * Important note. No error handling needs to take place and match up end tags
	 * with the begining tags.
     *
	 * The reason is that the SAX parser is going to handle all the endElement
	 * Errors.
	 */
	
	try
	{
		Transcode element;
		element.translate(name);
		if(m_tagStack.empty())
		{
			//Internal programmer Error the stack is empty
			InternalProgrammerErrorExceptionImpl("[void GraphHandler::endElement(const XMLCh *const name)], Stack is empty");
		}
		
		if(!m_beginTemplate)
		{
			Tag *tag = m_tagStack.top();
			m_tagStack.pop();
			if(!m_tagStack.empty())
			{
				m_tagStack.top()->handleInnerTag(tag);
				m_currentStartElement = m_tagStack.top();
			}
		}

		if(m_beginTemplate)
		{
			
			///@todo hack workaround xerces 2.6 becuase it has issues with qualifications
			if(element.getStringPimpl() == "html:template")
			{
				m_templateString += "</template>";
			}
			else
			{
				m_templateString += "</" + element.getStringPimpl() + ">";
			}
		}

		if(element.getString() == "template" || element.getString() == "html:template")
		{
			m_beginTemplate = false;
			
			PlainWord *p = new PlainWord(m_templateString);
			m_tagsToDelete.push_back(p);

			Template *t = new Template;
			m_tagsToDelete.push_back(t);

			t->add(p);
			Tag *tag = m_tagStack.top();
			tag->handleInnerTag(t);
		}
	}
	catch(nullString &)
	{
		//Do nothing
		//caught nullString on someChars.getChar()
	}
}

///@todo put this somewhere else or just remove this.
void GraphHandler::setAIMLVersion(const string &version)
{
	m_aimlVersion = version;

	if(version == "1.0")
	{
		//Version of AIML is 1.0
		m_aimlVersion = "1.0";
	}
	else if(version == "1.0.1")
	{
		//Version of AIML is 1.0.1
		m_aimlVersion = "1.0.1";
	}
	else
	{
		//Error, unsupported version of aiml
		string msg("Unsupported version of aiml.  You are trying to use version:" + version);
		throw ExceptionImpl(msg.c_str());
	}

}

string GraphHandler::getAIMLVersion()
{
	return m_aimlVersion;
}

} // end of namespace impl
} // end of namespace rebecca

