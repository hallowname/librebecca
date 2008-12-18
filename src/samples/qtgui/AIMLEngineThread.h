#ifndef QTGUI_AIMLENGINETHREAD_H
#define QTGUI_AIMLENGINETHREAD_H

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

#include <QThread>
#include "QtGuiCallBacks.h"

#include <rebecca/all.h>

/*
 * Forward declerations
 */
class QTextEdit;

namespace qtgui
{
using namespace rebecca;

/**
 * The thread object that
 * encapsulates the AIMLEngine
 * for the gui.
 */
class AIMLEngineThread : public QThread
{
	Q_OBJECT

	public:
		
		/**
		 * This is called from the spun thread
		 * and represents the thread.
		 */
		void run();
		
	signals:

		/**
		 * Emit to anyone listening that 
		 * we have text for them to add
		 *
		 * @param text The text for anyone 
		 * listening to add
		 */
		void addText(const QString &text);

		/**
		 * Emit to anyone listening that 
		 * we have text from the bot for them 
		 * to add
		 *
		 * @param text The text from the bot for 
		 * anyone listening to add
		 */
		void addBotText(const QString &text);

		/**
		 * Emit the name of the bot for anyone
		 * who is listening and interested
		 *
		 * @param text The text of the bot 
		 * name
		 */
		void addBotName(const QString &text);

		/**
		 * Emit that we have user input for
		 * anyone who is listening and interested
		 *
		 * @param text The text of the
		 * user input to the AIML engine.
		 */
		void userInput(const QString &text);

		/**
		 * Emit that the AIML engine should be
		 * destroyed
		 */
		void clearAIML();


		/**
		 * Emit that there's a AIML file to be 
		 * added to the AIML engine to anyone who
		 * is listening and interested.
		 *
		 * @param fileName the file to add to the
		 * AIML engine.
		 */
		void addFile(const QString &fileName);


		/**
		 * Emit that there's a AIML directory filled 
		 * with AIML files all ending in the 
		 * extension ".AIML" to be added to the AIML engine
		 * to anyone who is listening and interested.
		 *
		 * @param directoryName the directory to add
		 * to the AIML engine.
		 */
		void addDirectory(const QString &directoryName);
		
		/**
		 * Emit that a AIML set of files is 
		 * loading.
		 */
		void loading();

		/**
		 * Emit that a AIML set of files is 
		 * done loading.
		 */
		void doneLoading();
};

} //end of qtgui namespace 
#endif



