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

//custom tag includes
#include "sanitizeString.h"

namespace customTag
{
namespace impl
{


string sanitizeString(const string dirtyString)
{
	string sanitizedString;
	for(unsigned int i = 0; i < dirtyString.length(); ++i)
	{
		if(dirtyString.at(i) == '*')
		{
			sanitizedString += "[dot]";
		}
		else
		{
			sanitizedString.push_back(dirtyString.at(i));
		}
	}
	return sanitizedString;
}

} //end of namespace impl
} //end namespace customTag

