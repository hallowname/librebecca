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

//Custom tag includes
#include "CustomAIML.h"
#include "typedefs.h"

namespace customTag
{
namespace impl
{

CustomAiml::CustomAiml(Html &htmlPage)
	throw(InternalProgrammerErrorException &)
	: m_defaultStarTopic(htmlPage)
{
	/*
	 * Add the name of this class.  Otherwise if I 
	 * didn't do this I could not call Tag::instanceOf("CustomAiml")
	 * on a CustomAiml object and get a true back.
	 */
	addInstanceOf("CustomAiml");

}

void CustomAiml::handleInnerTag(Tag *tag)
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("Topic"))
	{
		/*
		 * Found instance of topic and am ignoring it.
		 */
	}
	else
	{
       /*
		* Send the tag to our CustomTopic class
		*/
		m_defaultStarTopic.handleInnerTag(tag);
	}
}

} //end of namespace impl
} //end namespace customTag

