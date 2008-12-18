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
#include <rebecca/framework/Input.h>
#include <rebecca/framework/FrameworkFactory.h>
#include <rebecca/framework/IdentificationManager.h>
using namespace rebecca::impl;

//Boost includes
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
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

class InputImpl
{
	public:
		InputImpl()
			: m_previousUserResponse(1),
			  m_sentence(1)
		{ } 

		int m_previousUserResponse;
		int m_sentence;
};

Input::Input() 
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new InputImpl)
{
	addInstanceOf("Input");
}

///@todo remove all this tokenizer stuff for simpler for loop
void Input::setAttribute(const StringPimpl &name, const StringPimpl &value) 
	throw(InternalProgrammerErrorException &)
{
	if(name == "index" && (!value.empty()))
	{
		string valueString(value.c_str());
		typedef tokenizer<char_separator<char> > tokenize;
		typedef tokenizer<char_separator<char> >::const_iterator CI;
		char_separator<char> sep(",");
		tokenize pathTokens(valueString, sep);
		int i = 0;
		for(CI it = pathTokens.begin(); it != pathTokens.end(); ++it, ++i)
		{
			StringPimpl s;
			
			if(i == 0)
			{
				try
				{
					//This is the first index which is a previous user response
					s = *it->c_str();
					s.transformByTrimmingWhiteSpace();
					m_pimpl->m_previousUserResponse = s.getInteger();
				}
				catch(NumberFormatException &)
				{
					//User Error, the cast to a numeric value failed
					FrameworkFactory *factory = FrameworkFactory::getInstance();
					IdentificationManager *ident = IdentificationManager::getInstance();
					GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
					builder->getCallBacks().inputTagNumericConversionError("First index string is not a valid number, " + s, ident->getUserId(), ident->getBotId(), ident->getEndUserId());
				}
			}
			else if(i == 1)
			{
				try
				{
					//This is the second index which is a sentence
					s = *it->c_str();
					s.transformByTrimmingWhiteSpace();
					m_pimpl->m_sentence = s.getInteger();
				}
				catch(NumberFormatException &)
				{
					//User Error, the cast to a numeric value failed
					FrameworkFactory *factory = FrameworkFactory::getInstance();
					IdentificationManager *ident = IdentificationManager::getInstance();
					GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
					builder->getCallBacks().inputTagNumericConversionError("Second index string is not a valid number, " + s, ident->getUserId(), ident->getBotId(), ident->getEndUserId());
				}
			}
			else
			{
				//User error, the i index is past 2
				FrameworkFactory *factory = FrameworkFactory::getInstance();
				IdentificationManager *ident = IdentificationManager::getInstance();
				GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
				builder->getCallBacks().inputTagNumericConversionError("The index is past 2", ident->getUserId(), ident->getBotId(), ident->getEndUserId());
			}
		}
	}
}

StringPimpl Input::getString() const
	throw(InternalProgrammerErrorException &)
{
	try
	{
		return FrameworkFactory::getInstance()->getGraphBuilderFramework()->getPreviousUserInput(m_pimpl->m_previousUserResponse, m_pimpl->m_sentence);
	}
	catch(IllegalArgumentException &)
	{
		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().inputTagSizeExceeded(ident->getUserId(), ident->getBotId(), ident->getEndUserId());
		return StringPimpl();
	}
}

Input::~Input()
{ 
	delete m_pimpl;
}


} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
