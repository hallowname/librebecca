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
#include <rebecca/impl/getStringFromSentence.h>
#include <rebecca/framework/InnerTemplate.h>

namespace rebecca
{
namespace impl
{

//Not connected to any particular class  Does not need to be.
StringPimpl getStringFromSentence(const list<InnerTemplate *> &sentence) 
{
	if(sentence.empty())
	{
		//WARNING.  No sentence to be had.  Returning empty string
		return StringPimpl();
	}
	else
	{
		//Sentence exists.  Constructing sentence
		StringPimpl returnSentence;
		typedef list<InnerTemplate *>::const_iterator CI;

		for(CI it = sentence.begin(); it != sentence.end(); ++it) 
		{
			StringPimpl sentenceToAppend = (*it)->getString();
			if(sentenceToAppend.empty())
			{
				//Warning, sentence empty, not adding it
			}
			else
			{
				if((!(returnSentence.empty())) && 
					returnSentence.at(returnSentence.size() - 1) == ' ' && 
				    sentenceToAppend.at(0) == ' ')
				{
					sentenceToAppend.transformByTrimmingLeft();
				}
				returnSentence += sentenceToAppend;
			}
		} 
		return returnSentence;
	}
}


} //end of namespace impl
} //end of namespace rebecca
