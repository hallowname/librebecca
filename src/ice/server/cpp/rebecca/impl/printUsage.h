#ifndef SERVER_PRINTUSAGE_H
#define SERVER_PRINTUSAGE_H

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

#include <iostream>

namespace rebecca
{
namespace impl
{

using namespace std;

void printUsage()
{
	cout << "You need at least one argument to specify where the" << endl
	 	 << "Ice Config file is located."
		 << endl << endl
		 << "Synopsis:"
		 << endl
		 << "rebecca-server --Ice.Config=<location of Ice Config file>" << endl
		 << "               Optional arguments:" << endl
		 << "               --install NAME [--display DISP] [--executable EXEC] [args]" << endl
		 << "                 Install as Windows service NAME. If DISP is" << endl
		 << "                 provided, use it as the display name," << endl
		 << "                 otherwise NAME is used. If EXEC is provided," << endl
		 << "                 use it as the service executable, otherwise" << endl
		 << "                 this executable is used. Any additional" << endl
		 << "                 arguments are passed unchanged to the" << endl
		 << "                 service at startup." << endl 
		 << "               --uninstall NAME Uninstall Windows service NAME." << endl
         << "               --start NAME [args] Start Windows service NAME. Any additional" << endl
         << "                 arguments are passed unchanged to the" << endl
         << "                 service." << endl
         << "               --stop NAME Stop Windows service NAME." << endl
		 << "               --daemon  To run as a daemon under a Linux/Unix system" << endl
		 << endl
		 << "Example, run the server local in a shell:" << endl
		 << "rebecca-server --Ice.Config=C:\\rebecca\\conf\\serverconfig.properties"
		 << endl << endl
		 << "Example, install the server as a Windows service:" << endl
		 << "rebecca-server --install RebeccaAIML --Ice.Config=C:\\rebecca\\conf\\serverconfig.properties"
		 << endl << endl
		 << "Example, uninstall the server as a Windows service:" << endl
		 << "rebecca-server --uninstall RebeccaAIML --Ice.Config=C:\\rebecca\\conf\\serverconfig.properties"
		 << endl << endl
		 << "Example, start the service once installed as a Windows service:" << endl
		 << "rebecca-server --start RebeccaAIML"
		 << endl << endl
		 << "Example, stop the service once installed as a Windows service:" << endl
		 << "rebecca-server --stop RebeccaAIML"
		 << endl << endl
		 << "Example, run the service as a Unix daemon:" << endl
		 << "rebecca-server --daemon --Ice.Config=/usr/local/share/Rebecca/conf/serverconfig.properties"
		 << endl << endl;
}

} //end of impl namespace
} //end of rebecca namespace

#endif




