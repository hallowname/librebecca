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
#include <rebecca/framework/InnerTemplate.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/impl/getStringFromSentence.h>
using namespace rebecca::impl;

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

InnerTemplate::InnerTemplate()  
	throw(InternalProgrammerErrorException &)
	: m_pimpl(0)
{
	addInstanceOf("InnerTemplate");
}

void InnerTemplate::handleInnerTag(Tag *tag) 
	throw(InternalProgrammerErrorException &)
{
	if(tag->instanceOf("InnerTemplate"))
	{
		InnerTemplate *it = static_cast<InnerTemplate *>(tag);
		add(it);
	}
	else
	{
		//Internal programmer error.  Bad cast, this is not a InnerCategory
		throw InternalProgrammerErrorExceptionImpl(
			"[void InnerTemplate::handleInnerTag(Tag *tag)], Bad cast, this is not an InnerTemplate"
				                                  );
	}
}

StringPimpl InnerTemplate::getString() const 
	throw(InternalProgrammerErrorException &)
{
	//No operations happen within this.  Empty string being returned
	return StringPimpl();
}

void InnerTemplate::add(InnerTemplate *tag) 
	throw(InternalProgrammerErrorException &)
{
	//No operations happen within this
}

InnerTemplate::~InnerTemplate() 
{ 
}



} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
