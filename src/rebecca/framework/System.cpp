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
#include <rebecca/framework/System.h>
#include <rebecca/framework/PlainWord.h>
#include <rebecca/framework/Star.h>
#include <rebecca/framework/FrameworkFactory.h>
using namespace rebecca::impl;

//Std includes
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <string>
using namespace std;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
# include <windows.h>
#include <errno.h>
#include <io.h>
#include <fcntl.h> 
#include <ctype.h>
#endif

namespace rebecca
{
namespace framework
{
namespace impl
{

System::System()
	throw(InternalProgrammerErrorException &)
	: m_pimpl(0)
{
	addInstanceOf("System");
}

StringPimpl System::getString() const
	throw(InternalProgrammerErrorException &)
{
	return FrameworkFactory::getInstance()->getGraphBuilderFramework()->callSystemCommand(InnerTemplateListImpl::getString());
}

System::~System()
{ 
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
