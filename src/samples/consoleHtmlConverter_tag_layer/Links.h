#ifndef CUSTOMHTML_LINKS_H
#define CUSTOMHTML_LINKS_H

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


//Std includes
#include <string>
#include <iostream>

//Custom tags includes
#include "sanitizeString.h"

namespace customTag
{
namespace impl
{

using namespace std;

/**
 * Class that handles information
 * related to html links
 */

class Links
{
	public:
		/**
		 * Sets the url
		 *
		 * @param url the url to set 
		 * 
		 */
		void setUrl(const string &url)
		{
			m_url = url;
		}
		
		/**
		 * Sets what the name of the
		 * url is to be on a web page
		 *
		 * @param displayUrl The string of 
		 * what the url is to be on
		 * the web page
		 */
		void setDisplayUrl(const string &displayUrl)
		{
			m_displayUrl = displayUrl;
		}
		/**
		 * Returns the url
		 *
		 * @return the url
		 */
		string getUrl()
		{
			return m_url;
		}
		/**
		 * Returns the name
		 * of the url is to be
		 * on the web page
		 *
		 * @return the name of
		 * the url on the web page
		 */
		string getDisplayUrl()
		{
			return m_displayUrl;
		}
		
		/**
		 * Returns the html of the
		 * full url
		 *
		 * If the displayUrl is 
		 * empty but the m_templateString
		 * is not, it will not create an
		 * actual link.  Instead it will
		 * display what is in the 
		 * m_templateString.  This is for
		 * the final web page that doesn't 
		 * have any more links but instead
		 * displays the template string
		 *
		 * @return the html of the
		 * full url
		 */
		string getHtmlLink()
		{
			/*
			 * If the display url is not empty use
			 * it otherwise use the template string
			 * which isn't a link at all.  It's just
			 * text
			 */
			if(!m_displayUrl.empty())
			{
				return string("<center><i><a href=\"" + sanitizeString(m_url) + ".html" + "\">" + m_displayUrl + "</a></i></center>");
			}
			else if(!m_templateString.empty())
			{
                return string("<center>" + getTemplateString() + "</center>");
			}
			else
			{
				cout << "Error neither displayUrl or TemplateString have been set" << endl;
				return string();
			}
		}
		
		/**
		 * Sets the template string
		 *
		 * @param templateString the string to set
		 * the internal templateString with.
		 */
		void setTemplateString(string templateString)
		{
			m_templateString = templateString;
		}
		
		/**
		 * Returns the template string.
		 *
		 * @return The template string.
		 *
		 */
		string getTemplateString()
		{
			return m_templateString;
		}

	private:

		/**
		 * The url link
		 */
		string m_url;

		/**
		 * The display name of
		 * the url link on the
		 * web page
		 */
		string m_displayUrl;

		/**
		 * The template string
		 * to use instead of a 
		 * html link.
		 *
		 * If this is set this 
		 * class will use it 
		 * instead of creating
		 * an actual link
		 */
		string m_templateString;
};

} //end of impl namespace
} //end of customTag namespace


#endif
