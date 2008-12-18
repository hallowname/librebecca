#ifndef REBECCA_IMPL_CONFIGURATIONHANDLERERROR_H
#define REBECCA_IMPL_CONFIGURATIONHANDLERERROR_H

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

//Xerces includes
#include <xercesc/sax/HandlerBase.hpp>

namespace rebecca
{	
namespace impl
{

XERCES_CPP_NAMESPACE_USE

/*
 * Forward declerations
 */ 
class GraphBuilderInternal;


class ConfigurationHandlerError : public HandlerBase
{
	public:
		ConfigurationHandlerError()
			{ }
		void warning(const SAXParseException &exc);
		void error(const SAXParseException &exc);
		void fatalError(const SAXParseException &exc);

	private:
};




} // end of impl namespace
} // end of rebecca namespace
#endif


