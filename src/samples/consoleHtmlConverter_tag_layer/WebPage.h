#ifndef CUSTOMHTML_WEBPAGE_H
#define CUSTOMHTML_WEBPAGE_H

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

#include <string>

namespace customTag
{
namespace impl
{

using namespace std;

/**
 * Class that handles 
 * information related to a
 * web page
 */
class WebPage
{
	public:

		/**
		 * Set the file name of the web page.
		 *
		 * @param fileName File name of the 
		 * web page
		 */
		void setFileName(const string &fileName)
		{
			m_fileName = fileName;
		}
		
		/**
		 * Return the name of the web page.
		 *
		 * @return The name of the web page.
		 */
		string getFileName() const
		{
			return m_fileName;
		}
		
		
		/**
		 * Overidden less than operator
		 * so this can be inserted into a
		 * map.
		 *
		 * @param rhs Right hand side of the
		 * less than expression
		 */
		bool operator<(const WebPage &rhs)
		{
			return this->getFileName() < rhs.getFileName();
		}

	private:

		/**
		 * The file name of the web page
		 */
		string m_fileName;
};

/**
 * Overidden less than operator
 * so this can be inserted into a
 * map.
 *
 * @param lfh Left hand side of the
 * less than expression
 *
 * @param rhs Right hand side of the
 * less than expression
 */
bool operator<(WebPage lfh, WebPage rhs);


} //end of namespace impl
} //end of namespace customTag


#endif
