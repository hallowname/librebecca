#ifndef REBECCA_IMPL_GETSTRINGFROMSENTENCE_H
#define REBECCA_IMPL_GETSTRINGFROMSENTENCE_H

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

//rebecca includes
#include <rebecca/StringPimpl.h>
#include <rebecca/framework/InnerTemplate.h>

//std includes
#include <list>

namespace rebecca
{
namespace impl
{
using namespace std;
using namespace rebecca::framework;

StringPimpl getStringFromSentence(const list<InnerTemplate *> &sentence);

} //end of namespace impl
} //end of namespace rebecca

#endif





