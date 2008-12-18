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
#include <rebecca/impl/ConfigurationHandler.h>
#include <rebecca/impl/utils/Transcode.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/GraphBuilderAIML.h>

//Xerces includes
#include <xercesc/parsers/SAXParser.hpp>

//Stl includes
#include <iostream>
using namespace std;

namespace rebecca
{
namespace impl
{

ConfigurationHandler::ConfigurationHandler()
{ }

void ConfigurationHandler::characters(const XMLCh *const chars, 
									  const unsigned int length)
{
	//Warning, This should not be called
}

void ConfigurationHandler::startElement(const XMLCh* const name, 
										AttributeList& attributes)
{
	Transcode attributeName;
	Transcode attributeType;
	Transcode attributeValue;
	Transcode message;

	try 
	{
		message.translate(name);		
		const string messageString(message.getChar());

		m_currentStartElement = createTagClass(messageString);
		m_tagStack.push(m_currentStartElement);
	}
	catch(nullString &)
	{
		//Do nothing	
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
		}
	}
}

void ConfigurationHandler::endElement(const XMLCh *const name)
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
		Transcode element(name);
		const string messageString(element.getChar());

		if(!m_tagStack.empty())
		{
			Tag *tag = m_tagStack.top();
			m_tagStack.pop();

			if(!m_tagStack.empty())
			{
				m_tagStack.top()->handleInnerTag(tag);
				m_currentStartElement = m_tagStack.top();
			}
			else
			{
				//Tag stack empty, not doing anything
			}
		}
		else
		{
			//Internal programmer Error the stack is empty
			throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::endElement(const XMLCh *const name)] the stack is empty)");
		}
	}	
	catch(nullString &)
	{
		//Do nothing
		//caught nullString on 
		//someChars.getChar()
	}

}

void ConfigurationHandler::endDocument()
{ 
	//delete all of our memory we used
	for(unsigned int i = 0; i < m_tagsToDelete.size(); ++i)
	{
		delete m_tagsToDelete.at(i);
	}
	m_tagsToDelete.clear();
}

Tag *ConfigurationHandler::createTagClass(const string &className)
{
	Tag *tag = 0;
	if(className == "input")
	{
		tag = new Input;
	}
	else if(className == "substitute")
	{
		tag = new Substitute;
	}
	else if(className == "gender")
	{
		tag = new Gender;
	}
	else if(className == "person")
	{
		tag = new Person;
	}
	else if(className == "person2")
	{
		tag = new Person2;
	}
	else if(className == "substitutions")
	{
		tag = new Substitutions;
	}
	else if(className == "sentence-splitters")
	{
		tag = new SentenceSplitters;
	}
	else if(className == "splitter")
	{
		tag = new Splitter;
	}
	else if(className == "properties")
	{
		tag = new Properties;
	}
	else if(className == "property")
	{
		tag = new Property;
	}
	else
	{
		//Warning, unknown className 
		tag = new Substitutions;
	}

	m_tagsToDelete.push_back(tag);
	return tag;
}

ConfigurationHandler::Input::Input()
{ 
	addInstanceOf("Input");
}

void ConfigurationHandler::Input::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("Substitute"))
	{
		Substitute *substitute = static_cast<Substitute *>(tag);
		GraphBuilderAIML::getInstance()->setInputSubstitution(substitute->getFind(), substitute->getReplace());
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a InnerCategory
		throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::Input::handleInnerTag(Tag *tag)] Bad cast, this is not a InnerCategory"); 
	}
}
ConfigurationHandler::Gender::Gender()
{
	addInstanceOf("Gender");
}

ConfigurationHandler::Person::Person()
{
	addInstanceOf("Person");
}

ConfigurationHandler::Person2::Person2()
{
	addInstanceOf("Person2");
}

void ConfigurationHandler::Gender::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("Substitute"))
	{
		Substitute *substitute = static_cast<Substitute *>(tag);
		GraphBuilderAIML::getInstance()->setGenderSubstitution(substitute->getFind(), substitute->getReplace());
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a InnerCategory
		throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::Gender::handleInnerTag(Tag *tag)], Bad cast, this is not a InnerCategory");
	}
}

void ConfigurationHandler::Person::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{

	if(tag->instanceOf("Substitute"))
	{
		Substitute *substitute = static_cast<Substitute *>(tag);
		GraphBuilderAIML::getInstance()->setPersonSubstitution(substitute->getFind(), substitute->getReplace());
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a InnerCategory
		throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::Person::handleInnerTag(Tag *tag)], Bad cast, this is not a InnerCategory");
	}
}

void ConfigurationHandler::Person2::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &) 
{

	if(tag->instanceOf("Substitute"))
	{
		Substitute *substitute = static_cast<Substitute *>(tag);
		GraphBuilderAIML::getInstance()->setPerson2Substitution(substitute->getFind(), substitute->getReplace());
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a InnerCategory
		throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::Person2::handleInnerTag(Tag *tag)], Bad cast, this is not a InnerCategory");
	}
}

ConfigurationHandler::Substitute::Substitute()
{
	addInstanceOf("Substitute");
}

void ConfigurationHandler::Substitute::setAttribute(const StringPimpl &name, const StringPimpl &value) throw(InternalProgrammerErrorException &)
{
	if((name == "find") && (!value.empty()))
	{
		m_find = value;
	}
	else if(name == "replace")
	{
		m_replace = value;
	}
	else
	{
		//Internal programmer Error, unknown name type
		throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::Substitute::setAttribute(const StringPimpl &name, const StringPimpl &value)], unknown name type");
	}
}

StringPimpl ConfigurationHandler::Substitute::getFind()
{
	return m_find;
}

StringPimpl ConfigurationHandler::Substitute::getReplace()
{
	return m_replace;
}

ConfigurationHandler::SentenceSplitters::SentenceSplitters()
{
	addInstanceOf("Substitutions");
}

void ConfigurationHandler::SentenceSplitters::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("Splitter"))
	{
		Splitter *splitter = static_cast<Splitter *>(tag);
		GraphBuilderAIML::getInstance()->setSentenceSplitter(splitter->getValue());
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a InnerCategory
		throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::SentenceSplitters::handleInnerTag(Tag *tag)], Bad cast, this is not a Splitter");
	}
}

void ConfigurationHandler::Splitter::setAttribute(const StringPimpl &name, const StringPimpl &value) throw(InternalProgrammerErrorException &)
{
	if(name == "value")
	{
		if(!value.empty())
		{
			m_value = value;
		}
		else
		{
			//The value is empty
		}
	}
	else if(name != "value")
	{
		//Internal programmer Error, unknown name type
		throw InternalProgrammerErrorExceptionImpl("[void ConfigurationHandler::Splitter::setAttribute(const StringPimpl &name, const StringPimpl &value)], unknown name type");
	}
}

void ConfigurationHandler::Property::setAttribute(const StringPimpl &name, 
												  const StringPimpl &value) 
	throw(InternalProgrammerErrorException &)
{
	if(name == "name")
	{
		if(!value.empty())
		{
			m_name = value;
		}
		else
		{
			//Name is empty
		}
	}
	else if(name == "value")
	{		
		if(!name.empty())
		{
			GraphBuilderAIML::getInstance()->setBotPredicate(m_name, value);
		}
		else
		{
			//value or name is empty
		}
	}
	else
	{
		//Internal programmer Error, unknown name type
		throw InternalProgrammerErrorExceptionImpl("void ConfigurationHandler::Property::setAttribute(const StringPimpl &name, const StringPimpl &value), unknown name type");
	}

}

ConfigurationHandler::Properties::Properties()
{ 
	addInstanceOf("Properties");
}

ConfigurationHandler::Substitutions::Substitutions()
{ 
	addInstanceOf("Substitutions");
}

ConfigurationHandler::Splitter::Splitter()
{ 
	addInstanceOf("Splitter");
}


} // end of namespace impl
} // end of namespace rebecca
