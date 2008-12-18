#ifndef QTGUI_AIMLENGINE_H
#define QTGUI_AIMLENGINE_H

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

//Qt includes
#include <QObject>
#include <QDir>

//Rebecca includes
#include <rebecca/all.h>
#include "QtGuiCallBacks.h"


/**
 * Namespace 
 * for the qt gui
 * classes 
 */
namespace qtgui
{
using namespace rebecca;


/**
 * The class that performs all
 * RebeccaAIML engine operations.
 */
class AIMLEngine : public QObject
{
	Q_OBJECT

	public:

		/**
		 * Initalize the AIML 
		 * engine.
		 */
		void initAIML();
		
		/**
		 * Default constructor.
		 * Initalizes the AIML engine
		 * pointer to zero and 
		 * hooks up the QtGuiCallBacks::addText() 
		 * signal to this classes signal, 
		 * AIMLEngine::addText().  Now when the 
		 * QtGuiCallBacks emits a 
		 * QtGuiCallBacks::addText(), this class 
		 * will also.  
		 */
		AIMLEngine()
			: m_aiml(0)
		{ 
			bool b = connect(&m_callback, SIGNAL(addText(const QString &)),
	            this, SIGNAL(addText(const QString &)));			
		}
	
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
		 * Emit that a AIML set of files is 
		 * loading.
		 */
		void loading();

		/**
		 * Emit that a AIML set of files is 
		 * done loading.
		 */
		void doneLoading();

	public slots:
		
		/**
		 * This accepts all user input
		 * to the AIML engine.
		 *
		 * @param text The text of the
		 * user input to the AIML engine.
		 */
		void userInput(const QString &text);
		
		/**
		 * Deletes the AIML engine.
		 */
		void clearAIML();
		
		/**
		 * Add a AIML file to the AIML engine.
		 *
		 * @param fileName the file to add to the
		 * AIML engine.
		 */
		void addFile(const QString &fileName);
		
		/**
		 * Add a AIML directory filled with AIML
		 * files all ending in the extension ".AIML"
		 * to the AIML engine.
		 *
		 * @param directoryName the directory to add
		 * to the AIML engine.
		 */
		void addDirectory(const QString &directoryName);

	private:	
		
		/**
		 * This is for the call backs on 
		 * the AIML engine.
		 *
		 * It is used to ultimately update the 
		 * gui.
		 */
		QtGuiCallBacks m_callback;

	   /**
		* This is responsible for memory management of 
		* the AIMLEngine GraphBuilder.
		*/
		AimlFacade *m_aiml;
};


} //end of namespace qtgui

#endif
