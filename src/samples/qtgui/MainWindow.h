#ifndef QTGUI_MAINWINDOW_H
#define QTGUI_MAINWINDOW_H

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
#include <QMainWindow>
#include <QTextEdit>

//qtgui includes
#include "AIMLEngineThread.h"

/*
 * Forward declerations
 */
class QPushButton;
class QLineEdit;
class QMenu;
class QToolBar;

namespace qtgui
{
class CustomTextEdit;

/**
 * The main window of our
 * gui that encapsulates and
 * holds references to everything
 * else.
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT
	
	public:

		/**
		 * Default constructor to initialize
		 * The gui
		 */
		MainWindow();

	public slots:

		/**
		 * Called when the user inputs
		 * something
		 */
		void input();

		/**
		 * Called when there is new
		 * text to add from the bot.
		 *
		 * @param text The text from the bot
		 */
		void addBotText(const QString &text);
		
		/**
		 * Called when the bot's name changes.
		 *
		 * @param text the name of the bot.
		 */
		void addBotName(const QString &text);

		/**
		 * Called when the "about" button is
		 * pressed.
		 */
		void about();

		/**
		 * Called when the "open file" button is
		 * pressed.
		 */
		void openFile();
		
		/**
		 * Called when the "new file" button is 
		 * pressed.
		 */
		void newFile();
		
		/**
		 * Called when the "open directory" button
		 * is pressed.
		 */
		void openDir();

		/**
		 * Called when AIML is loading
		 */
		void aimlLoading();
		
		/**
		 * Called when AIML is done loading
		 */ 
		void aimlDoneLoading();
		
		/**
		 * Called when the "save" button
		 * is pressed.
		 */
		bool save();

		/**
		 * Called when the "save as" button
		 * is pressed.
		 */
		bool saveAs();

	signals:

		/**
		 * Emitted when the user enters
		 * text into the text box.
		 *
		 * @param text The text the user
		 * entered.
		 */
		void userTextEntered(const QString &text);
		
		/**
		 * Emitted when the user selects
		 * a AIML file to open.
		 *
		 * @param fileName The AIML file the 
		 * user selected to open
		 */
		void aimlFileToOpen(const QString &fileName);
		
		/**
		 * Emitted when the AIML engine 
		 * should be destroyed 
		 */
		void aimlClear();
		
		/**
		 * Emitted when the user selects a
		 * directory to open
		 *
		 * @param dirName The Name of the 
		 * directory for the AIML engine to open
		 */
		void aimlDirectoryToOpen(const QString &dirName);

	private:

		/**
		 * Sets up intiial GUI properties
		 */
		void setupInitialProperties();
		
		/**
		 * Creates the GUI status at the
		 * bottom of the GUI
		 */ 
		void createStatusBar();
		
		/**
   		 * Setup the layout so when resizing
		 * happens it does so with grace with
		 * the widgets all moving around together
		 * in a choherient way.
		 */
		void setupLayout();
		
		/**
		 * Sets up the QT connections
		 * to the AIML engine thread
		 */
		void setupConnections();
		
		/**
		 * Creates the menu items in the GUI
		 */
		void createMenus();
		
		/**
		 * Creates the action items in the GUI
		 */
		void createActions();
		
		/**
		 * Creates the Tool bars in the GUI
		 */
		void createToolBars();
		
		/**
		 * Sets the current file to save to
		 * when the user presses the "save"
		 * button
		 *
		 * @param fileName the name of the file
		 * to set the current file to 
		 */
		void setCurrentFile(const QString &fileName);
		
		/**
		 * Saves the bot output to the file
		 *
		 * @param fileName the file to save the 
		 * bot output to
		 */
		bool saveFile(const QString &fileName);
		
		/**
		 * Strips the file name
		 *
		 * @param fullFileName The file name to strip
		 */
		QString strippedName(const QString &fullFileName);

		/**
		 * The GUI "OK" button
		 */
		QPushButton *m_okButton;
		
		/**
		 * The GUI input field the
		 * user inputs to the bot
		 */
		QLineEdit *m_userInputField;
		
		/**
		 * The output field where the
		 * bot/AIML engine sends text to
		 */
		CustomTextEdit *m_botOutputField;

		/**
		 * The AIML Engine thread.
		 *
		 * This is used to offload the
		 * work of the AIML from the GUI
		 * and keeps the GUI repsonsive
		 * by putting all the AIML engine
		 * workload in a seperate thread.
		 */
		AIMLEngineThread m_AIMLEngineThread;
		
		/**
		 * Name of the bot
		 */
		QString m_botName;
		
		/**
		 * Current file we are saving our
		 * output to when the user selects
		 * the "Save" button
		 */
		QString m_curFile;
		
		/**
		 * The GUI "file" Menu item
		 */
		QMenu *m_fileMenu;

		/**
		 * The GUI "help" Menu item
		 */
		QMenu *m_helpMenu;

		/**
		 * The GUI "open File" Action item
		 */
		QAction *m_openAct;

		/**
		 * The GUI "open Directory" Action item
		 */
		QAction *m_openDirAct;

		/**
		 * The GUI "about" Action item
		 */
		QAction *m_aboutAct;

		/**
		 * The GUI "new" item
		 */
		QAction *m_newAct;

		/**
		 * The GUI "save" item
		 */
		QAction *m_saveAct;

		/**
		 * The GUI "save as" item
		 */
		QAction *m_saveAsAct;

		/**
		 * The GUI "exit" item
		 */
		QAction *m_exitAct;

		/**
		 * The GUI file tool bar
		 */
		QToolBar *m_fileToolBar;
};


} //end of qtgui namespace 

#endif


