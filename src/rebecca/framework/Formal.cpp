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
#include <rebecca/framework/Formal.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/framework/Star.h>
using namespace rebecca::impl;

//Boost includes
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;

//std includes
#include <string>
using namespace std;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
#endif

namespace rebecca
{
namespace framework
{
namespace impl
{

class FormalImpl
{
	public:
		
};

Formal::Formal()  
	throw(InternalProgrammerErrorException &)
	: m_pimpl(0)
{
	addInstanceOf("Formal");
}

StringPimpl Formal::getString() const
	throw(InternalProgrammerErrorException &)
{
	typedef tokenizer<char_separator<char> > tokenize;
	typedef tokenizer<char_separator<char> >::const_iterator CI;

	char_separator<char> sep(" ");
	string stringToTok(InnerTemplateListImpl::getString().c_str());
	tokenize pathTokens(stringToTok, sep);
	string returnString;

	for(CI it = pathTokens.begin(); it != pathTokens.end(); ++it)
	{
		string word(*it);
		word[0] = toupper(word[0]);
		returnString += word + " ";
	}	

	trim_right(returnString);

	return returnString.c_str();
}

Formal::~Formal()
{ 
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
