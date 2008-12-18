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

//Custom tags includes
#include "Html.h"
#include "WebPage.h"

//Std includes
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

namespace customTag
{
namespace impl
{


Html::Html()
	: m_directoryName("htmlAiml")
{
	/*
	 * Create the directory and the 
	 * default style sheet if they do
	 * not exist
	 */
	cout << "Creating directory: " + m_directoryName << endl;
	string systemCommand = "mkdir " + m_directoryName;
	system(systemCommand.c_str());
	ifstream is;
	string fullPath = m_directoryName + "/style.css";
	is.open (fullPath.c_str(), ios::binary );
	int length = 0;
	if(is.is_open())
	{
		// get length of file:
		is.seekg (0, ios::end);
		length = is.tellg();
	}
	if(length == 0)
	{
		cout << "Cannot find style sheet writing one out" << endl;
		//file does not exist or it's empty
		writeDefaultStyleSheet(m_directoryName + "/style.css");
	}
}

void Html::writeDefaultStyleSheet(const string &fileName)
{
	/*
	 * Write out a default style sheet with
	 * hardcoded values to the file given.
	 */
	const string styleSheet = "body {  background-color: #D9D9F3; }"
		                      "img {  border-width: 0;  vertical-align: middle;  text-align: center; }"
							  " h1 {  text-align: center; } "
							  " .title {  font-weight: bold;  font-size: larger; } "
							  " .menu {  position: absolute;  width: 7.5em;  top: 1em;  left: 1em;"
							  "  background-color: #E6E8FA;  border-style: inset;  border-width: 1px;  border-color: #000000; "
							  "  padding: 5px; } "
							  " #body {  position: absolute;  left: 10em;  top: 1em;  right: 1em; "
							  "  background-color: #E6E8FA;  border-style: inset;  border-width: 1px;  border-color: #000000;  padding: 5px; } ";

	ofstream file(fileName.c_str());
	file << styleSheet;
}

void Html::to_lower(string &input)
{
	for(unsigned int i = 0; i < input.length(); ++i)
	{
		tolower(input.at(i));
	}
}

void Html::createLink(string urlToLinkTo, string urlDisplayName, string urlToLinkFrom)
{
	/*
	 * Make all the links lowercase 
	 * so they are easier on the eyes
	 * to look at.
	 */
	to_lower(urlToLinkTo);
	to_lower(urlDisplayName);
	to_lower(urlToLinkFrom);

	/*
	 * Setup the link to the url
	 * and the name of the url to 
	 * display on the web page
	 */
	Links link;
	link.setUrl(urlToLinkTo);
	link.setDisplayUrl(urlDisplayName);
	
	/*
	 * Create a webpage.  Set the file 
	 * name of the webpage to the name 
	 * of the url we are linking from. 
	 * Add the webpage to our map of url
	 * links if it does not already exist.
	 * 
	 * Take the handle to the web page and 
	 * add our link to it.
	 */
	WebPage webPage;
	webPage.setFileName(sanitizeString(urlToLinkFrom));
	MapStringLinks urlMap = m_links[webPage];
	urlMap[sanitizeString(urlToLinkTo)] = link;
	m_links[webPage] = urlMap;
}

void Html::createTemplateLink(string urlToLinkTo, string templateString, string urlToLinkFrom)
{

	/*
	 * Make all the links lowercase 
	 * so they are easier on the eyes
	 * to look at.
	 */
	to_lower(urlToLinkTo);
	to_lower(templateString);
	to_lower(urlToLinkFrom);

	/*
	 * Setup the link to the url
	 * but set the link to the text
	 * of the template string.
	 * 
	 * Since it is a template string
	 * there is no more links.  Instead
	 * of displaying a link we want to 
	 * display just the text of the template
	 * string.
	 */
	Links link;
	link.setTemplateString(templateString);

	/*
	 * Create a webpage.  Set the file 
	 * name of the webpage to the name 
	 * of the url we are linking from. 
	 * Add the webpage to our map of url
	 * links if it does not already exist.
	 * 
	 * Take the handle to the web page and 
	 * add our template string to it.
	 */
	WebPage webPage;
	webPage.setFileName(sanitizeString(urlToLinkFrom));
	MapStringLinks urlMap = m_links[webPage];
	urlMap[sanitizeString(urlToLinkTo)] = link;
	m_links[webPage] = urlMap;

}

string Html::replace_all_copy(const string &input, const char &character, const string &whatWith)
{
	string replacementString;
	for(unsigned int i = 0; i < input.length(); ++i)
	{
		if(input.at(i) == character)
		{
			replacementString += whatWith;
		}
		else
		{
			replacementString.push_back(input.at(i));
		}
	}

	return replacementString;
}


void Html::writeWebPages()
{
	/*
	 * Create our types for iterating over
	 * the links and web pages.
	 */
	typedef MapStringLinks::const_iterator CII;
	typedef MapWebPageMapStringLinks::const_iterator CI;

	/*
	 * Display how many web pages based on the links size
	 */
	int size = m_links.size();
	cout << "Writing out " << size << " html webpages" << endl;

	/*
	 * Iterate over the links.  Each link is a web page.
	 */
	int counter = 0;
	for(CI it = m_links.begin(); it != m_links.end(); ++it, ++counter)
	{
		/*
		 * Friendly counter to let the user
		 * know some progress.
		 */
		if((counter % 1000) == 0)
		{
			if(counter != 0) 
			{
				int count=3, N=100;
				float percentage;
				percentage  = static_cast<float>(counter)/size * 100;
				cout << "[" << counter << " web pages written so far, " <<  setprecision(2) << percentage << "% completed]" << endl;
			}
		}
		
		/*
		 * Grab the webpage from the link.
		 * Derive the file name from it and
		 * create a file stream to our new file
		 * name
		 */
		WebPage webPage = it->first;
		string fileName = m_directoryName + "/" + webPage.getFileName() + ".html";
		ofstream file(fileName.c_str());		

		if(file.is_open())
		{
			/* 
			 * Set the caption of the web page.
			 * Write out the header of the web page.
			 */
			m_topCaption = webPage.getFileName();
			m_topCaption = replace_all_copy(m_topCaption, ' ', "->");
			writeHtmlHeader(file);

			/*
			 * Write out the links of the web page
			 */
			for(CII iit = (it->second).begin(); iit != (it->second).end(); ++iit)
			{
				Links link = iit->second;
				file << link.getHtmlLink() << endl;
			}
			
			/*
			 * Write out the html footer page of
			 * the web page and we're through with
			 * this web page.
			 */
			writeHtmlFooter(file);

		}
		else
		{
			//Warning the file did not open
			cout << "Warning file did not open: " << fileName << endl;
		}

	}
}

void Html::writeHtmlHeader(ofstream &file)
{
	/*
	 * Write out generic html header using 
	 * m_caption member variable as our caption
	 */
	
	file << "<html xmlns=\"http://www.w3.org/1999/xhtml\">" << endl;
	file << "<head>" << endl;
	file << "<title>AIML</title>" << endl;
	file << "<link rel=\"stylesheet\" href=\"style.css\" type=\"text/css\" title=\"default\">" << endl;
	file << "</head>" << endl;
	file << "<body>" << endl;
	file << "<center><h2>" << m_topCaption << "</h2></center>" << endl;
}

void Html::writeHtmlFooter(ofstream &file)
{
	/*
	 * Generic footer
	 */
	file << "</body>" << endl;
	file << "</html>" << endl;
}

} //end of namespace impl
} //end namespace customTag
