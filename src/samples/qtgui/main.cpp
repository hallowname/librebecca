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

//QT includes
#include <QApplication>
#include <QTimer>

//qtgui includes
#include <MainWindow.h>
using namespace qtgui;

int main(int argc, char *argv[])
{
	/*
	 * Standard QApplication object
	 */
	QApplication app(argc, argv);


	/*
	 * Instantiate our main window 
	 * object, resize it to what
	 * we would like it to be, and
	 * finally show it.
	 */
	MainWindow mainWindow;
	mainWindow.resize(845, 654);
	mainWindow.show();
	return app.exec();
} 

