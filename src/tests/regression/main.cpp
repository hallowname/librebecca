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

#include "rebecca/TestCases.h"
#include "rebecca/Arguments.h"
using namespace rebecca;

#include <iostream>
using namespace std;

/*
 * Initialize our static variable that
 * holds our singleton instance for Arguments.h.
 */
Arguments *Arguments::m_instance = 0;

int main (int argc, char* argv[]) 
{
	try
	{
        Arguments::setArguments(argc, argv);
		Arguments *arguments = Arguments::getInstance();
		TestCases test("regressionTest.htm");
		test.addAimlFile(arguments->getResourcesDirectory() + "/testing/AIML.aiml");
		test.addTestFile(arguments->getResourcesDirectory() + "/testing/AIML.xml");
		test.createAimlGraph();
		test.conductTesting();
	}
	catch(Exception &e)
	{
		cout << e.what() << endl;
	}	
	return 0;
}

