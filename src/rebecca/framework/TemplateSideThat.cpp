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
#include <rebecca/framework/TemplateSideThat.h>
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

class TemplateSideThatImpl
{
	public:
		TemplateSideThatImpl() 
			: m_previousBotResponse(1),
			  m_sentence(1)
		{ }

		~TemplateSideThatImpl() { } 

		StringPimpl m_that;
		int m_previousBotResponse;
		int m_sentence;
};


TemplateSideThat::TemplateSideThat()
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new TemplateSideThatImpl)
{
	addInstanceOf("TemplateSideThat");
}

StringPimpl TemplateSideThat::getString() const
	throw(InternalProgrammerErrorException &)
{
	try
	{
		return FrameworkFactory::getInstance()->getGraphBuilderFramework()->getPreviousBotResponsePunctuation(m_pimpl->m_previousBotResponse, m_pimpl->m_sentence);
	}
	catch(IllegalArgumentException &)
	{
		FrameworkFactory *factory = FrameworkFactory::getInstance();
		IdentificationManager *ident = IdentificationManager::getInstance();
		GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
		builder->getCallBacks().thatTagSizeExceeded(ident->getUserId(), ident->getBotId(), ident->getEndUserId());
		return StringPimpl();
	}
	catch(Exception &)
	{
		//Fatal exception occured
		return StringPimpl();		
	}
}

///@todo redo this without annoying tokenizer.  Use a for loop
void TemplateSideThat::setAttribute(const StringPimpl &name, const StringPimpl &value) throw(InternalProgrammerErrorException &)
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
			string s;
			if(i == 0)
			{				
				try
				{
					//This is the first index which is a previous bot response
					s = *it;
					trim(s);
					m_pimpl->m_previousBotResponse = lexical_cast<int>(s);
				}
				catch(bad_lexical_cast &)
				{
					//User Error, the cast to a numeric value failed
					string msg("First index string is not a valid number, ");
					msg += s.c_str();
					FrameworkFactory *factory = FrameworkFactory::getInstance();
					IdentificationManager *ident = IdentificationManager::getInstance();
					GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
					builder->getCallBacks().thatTagNumericConversionError(msg.c_str(), ident->getUserId(), ident->getBotId(), ident->getEndUserId());
				}
			}
			else if(i == 1)
			{			
				try
				{
					//This is the second index which is a sentence
					s = *it;
					trim(s);
					m_pimpl->m_sentence = lexical_cast<int>(s);
				}
				catch(bad_lexical_cast &)
				{
					string msg("Second index string is not a valid number, ");
					msg += s.c_str();
					FrameworkFactory *factory = FrameworkFactory::getInstance();
					IdentificationManager *ident = IdentificationManager::getInstance();
					GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
					builder->getCallBacks().thatTagNumericConversionError(msg.c_str(), ident->getUserId(), ident->getBotId(), ident->getEndUserId());
					//User Error, the cast to a numeric value failed
				}
			}
			else
			{
				//User error, the i index is past 2
				FrameworkFactory *factory = FrameworkFactory::getInstance();
				IdentificationManager *ident = IdentificationManager::getInstance();
				GraphBuilderFramework *builder = factory->getGraphBuilderFramework();
				builder->getCallBacks().thatTagNumericConversionError("The index is past 2", ident->getUserId(), ident->getBotId(), ident->getEndUserId());
			}
		}	
	}
}

TemplateSideThat::~TemplateSideThat()
{ 
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
