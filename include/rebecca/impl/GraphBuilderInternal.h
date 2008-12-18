#ifndef REBECCA_IMPL_GRAPHBUILDERINTERNAL_H
#define REBECCA_IMPL_GRAPHBUILDERINTERNAL_H

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
#include <rebecca/framework/GraphBuilderFramework.h>
#include <rebecca/impl/CustomTagWithDelete.h>

//Std includes
#include <map>
namespace rebecca
{
namespace impl
{

/*
 * Forward declerations
 */
class NodeMapper;
using namespace rebecca::framework;
using namespace std;

class GraphBuilderInternal : public GraphBuilderFramework
{
	public:
		virtual NodeMapper &getRootNodeMapper() = 0;
		virtual StringPimpl inputSubstitute(const StringPimpl &input) = 0;
		virtual void setSize(const unsigned int newSize) = 0;
		virtual map<StringPimpl, CustomTagWithDelete> &getCustomTagsMapRef() = 0;
};

} //end of namespace impl
} //end of namespace rebecca

#endif

