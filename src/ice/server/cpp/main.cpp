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

//Ice includes
#include <Ice/Ice.h>
#include <Ice/Service.h>

//Ice Rebecca generated includes
#include <rebecca/impl/network.h>

//std includes
#include <iostream>
using namespace std;

//rebecca includes
#include <rebecca/impl/NetworkGraphBuilderI.h>
#include <rebecca/impl/ServerService.h>
#include <rebecca/impl/printUsage.h>
using namespace rebecca;
using namespace rebecca::impl;

int main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		printUsage();
	}
	else
	{
		string firstArgument(argv[1]);
		if(firstArgument == "--help" || 
		   firstArgument == "-help" || 
		   firstArgument == "-h" ||
		   firstArgument == "--h")
		{
			printUsage();
		}
		else
		{
			ServerService svc;
			return svc.main(argc, argv);
		}
	}	
}


