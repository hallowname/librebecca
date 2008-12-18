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
#include <rebecca/framework/Category.h>
#include <rebecca/StringPimpl.h>

//Custom tag includes
#include "CustomTopic.h"
#include "Links.h"
#include "Html.h"
#include "HtmlConverterInternalProgrammerErrorException.h"

//std includes
#include <sstream>
#include <vector>

namespace customTag
{
namespace impl
{

/*
 * Initialize the default topic to "*".
 * The default topic in AIML XML is always a "*"
 */
CustomTopic::CustomTopic(Html &htmlPage)
	throw(InternalProgrammerErrorException &)
	: m_topic("*"), 
	  m_htmlPage(htmlPage)
{ 
	/*
	 * Add the name of this class.  Otherwise if I 
	 * didn't do this I could not call Tag::instanceOf("CustomTopic")
	 * on a CustomTopic object and get a true back.
	 */
	addInstanceOf("CustomTopic");
} 

void CustomTopic::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	/*
	 * Check if the tag object inherits from the
	 * Category class 
	 */
	if(tag->instanceOf("Category"))
	{
		/*
		 * Downcast the tag to the category it is.
		 * Get the pattern string from it.
		 * Erase all newline characters if any from the
		 * string.
		 */
		Category* category = static_cast<Category *>(tag);
		const StringPimpl &patternString = category->getPatternString();
		vector<StringPimpl> tokens; 
		typedef vector<StringPimpl>::const_iterator CI;
		StringPimpl word;

		/*
		 * Create the individual words from the 
		 * string.  This is tokenizes the words from 
		 * the sentecne into the vector "tokens".
		 */
		for(unsigned int i = 0; i < patternString.length(); ++i)
		{
			//skip the new line character
			if(patternString.at(i) == '\n')
			{
				continue;
			}
			else if(patternString.at(i) == ' ')
			{
				if(!word.empty())
				{
					tokens.push_back(word);
					word.clear();
				}
			}
			else
			{
				word.push_back(patternString.at(i));
			}
		}
		
		if(!word.empty())
		{
			tokens.push_back(word);
			word.clear();
		}

		/*
		 * leftNode is the word on the left side of "->" 
		 * when writing the webpages out.  For example, 
		 * [root] is the first web page and will be the
		 * left node when making the second web page when
		 * the second web page has the title string
		 * of "[root]->blah"
		 */
		string leftNode = "[root]";
		string savedString = leftNode;
		
		/*
		 * Iterate over the invidivual words of the 
		 * pattern string.  Create the web page and 
		 * its links to the words of the pattern string.
		 */
		for(CI it = tokens.begin(); it != tokens.end(); ++it)
		{
			string tokName = it->c_str();
			savedString += " " + tokName;
			m_htmlPage.createLink(savedString, tokName.c_str(), leftNode);		
			leftNode = savedString;			
		}
		tokens.clear();		

		/*
		 * Get the "that" string.  Create the link to the 
		 * that words.  Remove all newline characters
		 * from the "that" string. Break up the "that" string 
		 * into invidiual words.  
		 */
		const StringPimpl &thatString = category->getThatString();
		savedString += string(" ") + "[that]";
		m_htmlPage.createLink(savedString, "[that]", leftNode);
		leftNode = savedString;

		/*
		 * Create the individual words from the 
		 * string.  This is tokenizes the words from 
		 * the sentecne into the vector "tokens".
		 */
		for(unsigned int i = 0; i < thatString.length(); ++i)
		{
			//skip the new line character
			if(thatString.at(i) == '\n')
			{
				continue;
			}
			else if(thatString.at(i) == ' ')
			{
				if(!word.empty())
				{
					tokens.push_back(word);
					word.clear();
				}
			}
			else
			{
				word.push_back(thatString.at(i));
			}
		}
		
		if(!word.empty())
		{
			tokens.push_back(word);
			word.clear();
		}

		/*
		 * Iterate over the invidivual words of the 
		 * "that" string.  Create the web page and 
		 * its links to the words of the pattern string.
		 */
		for(CI it = tokens.begin(); it != tokens.end(); ++it)
		{
			string tokName = it->c_str();
			savedString += " " + tokName;
			m_htmlPage.createLink(savedString, tokName, leftNode);
			leftNode = savedString;			
		}
		tokens.clear();

		/*
		 * Create a link to the topic words.  Break up the 
		 * topic string into invidiual words.  
		 */
		savedString += string(" ") + "[topic]";
		m_htmlPage.createLink(savedString, "[topic]", leftNode);
		leftNode = savedString;

		/*
		 * Create the individual words from the 
		 * string.  This is tokenizes the words from 
		 * the sentecne into the vector "tokens".
		 */
		for(unsigned int i = 0; i < m_topic.length(); ++i)
		{
			//skip the new line character
			if(m_topic.at(i) == '\n')
			{
				continue;
			}
			else if(m_topic.at(i) == ' ')
			{
				if(!word.empty())
				{
					tokens.push_back(word);
					word.clear();
				}
			}
			else
			{
				word.push_back(m_topic.at(i));
			}
		}
		
		if(!word.empty())
		{
			tokens.push_back(word);
			word.clear();
		}

		/*
		 * Iterate over the invidivual words of the 
		 * topic string.  Create the web page and 
		 * its links to the words of the pattern string.
		 *
		 * However, when the last topic string is encountered
		 * we have to create a template string and store that 
		 * on the final web page.  So a general for loop will
		 * not work here.  Instead we use a look ahead token
		 * to find the last web page.
		 */
		CI itLookAhead = tokens.begin();
		if(itLookAhead != tokens.end())
		{
			++itLookAhead;
		}
		
		string tokName;
		for(CI it = tokens.begin(); it != tokens.end(); ++it)
		{
			tokName = it->c_str();
			savedString += " " + tokName;
			m_htmlPage.createLink(savedString, tokName, leftNode);
			leftNode = savedString;			
		}
		
		/*
		 * Store the template string for the final link
		 */
		const StringPimpl templateString = category->getTemplateString();
		m_htmlPage.createTemplateLink("nowhere", templateString.c_str(), leftNode);

	}
	else if(tag->instanceOf("Topic"))
	{
		/*
		 * We have encountered another topic tag.  Just ignore it, it's not fatal.
		 */
	}
	else
	{   
		/*
		 * Invalid Tag object, shut down the AIML engine
		 */
		throw HtmlConverterProgrammerErrorException("Internal programmer error."
			                                        "Bad cast, this is not a Category or Topic");
	}
}

void CustomTopic::setAttribute(const StringPimpl &name, const StringPimpl &value) 
	throw(InternalProgrammerErrorException &)
{
	/*
	 * Put the name and value
	 * into easier to use strings
	 */
	string nameString(name.c_str());
	string valueString(value.c_str());

	if(nameString == "name")
	{
		/*
		 * Store the value of the name attribute
		 */
		m_topic = valueString;
	}
	else
	{
		/*
		 * Invalid attribute and invalid CustomTopic.  Shut down the AIML engine.
		 */
		throw HtmlConverterProgrammerErrorException("Invalid setAttribute on CustomTopic::setAttribute()");
	}
}

} //end of namespace impl
} //end namespace customTag

