#ifndef REBECCA_IMPL_CUSTOMTAGWITHDELETE_H
#define REBECCA_IMPL_CUSTOMTAGWITHDELETE_H

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

#include <rebecca/framework/CustomTags.h>
using namespace rebecca::framework;

#ifdef _WIN32
#    pragma warning( disable : 4290 )
#    include <windows.h>
#else 
#   include <dlfcn.h>	
#endif

namespace rebecca
{
namespace impl
{

class CustomTagWithDelete
{
	public:
		typedef void(*ExitPointfuncPtr)(CustomTags *);  
		CustomTags *m_customTags;
		ExitPointfuncPtr m_deleteFunc;

	#ifdef _WIN32
		HINSTANCE m_dllHandle;
	#else //Linux
		void *m_dllHandle;
	#endif
};

} //end of namespace impl
} //end of namespace rebecca

#endif


