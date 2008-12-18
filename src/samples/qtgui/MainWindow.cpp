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

//qtgui includes
#include <MainWindow.h>
#include <QtGuiCallBacks.h>
#include "AIMLEngineThread.h"
#include "CustomTextEdit.h"

//QT includes
#include <QtGui>

//rebecca includes
#include <rebecca/all.h>
using namespace rebecca;

namespace qtgui
{

void MainWindow::input()
{
	/*
	 * emit that the user entered
	 * some text and then clear 
	 * the input field
	 */
	emit userTextEntered(m_userInputField->text());
	m_userInputField->clear();
}

void MainWindow::openDir()
{
	/*
	 * Call the open directory gui box.
	 */
	QString directory = QFileDialog::getExistingDirectory(
                    this,
                    "Choose a directory of AIML files to open",
                    "../aiml");

   if(!directory.isEmpty())
   {
		/* 
		 * Emit to anyone interested in the relative 
		 * path to the AIML directory
		 */
		emit aimlDirectoryToOpen(directory);				
   }
}

void MainWindow::openFile()
{

	/*
	 * Call the open file gui box.
	 */
	QStringList fileNames = QFileDialog::getOpenFileNames(
                        this,
                        "Select one or more AIML files to open",
                        "../aiml",
                        "AIML Files (*.aiml)\nAny File (*.*)");

	if(!fileNames.empty())
	{
		/*
		 * Iterate over the file(s), getthe 
		 * relative paths to the file(s)
		 * since RebeccaAIML can only handle
		 * relative paths at the time of writing
		 * this code, and emit them to anyone
		 * listening to handle.
		 */
		foreach(QString fileName, fileNames)
		{
		   /* 
			* Emit to anyone interested in the relative 
			* path to the AIML file(s)
			*/
            emit aimlFileToOpen(fileName);
		}
	}
}
void MainWindow::aimlLoading()
{
	//Set the cursor to the hour glass to indicate "we're busy"
	QApplication::setOverrideCursor(Qt::WaitCursor);
	
	//Show the message that AIML is loading in the bottom of the gui
	statusBar()->showMessage(tr("AIML Loading"));

	/*
	 * Disable the buttons which would cause problems
	 * during the loading of AIML if they are pressed.
	 */
	m_openAct->setEnabled(false);
	m_openDirAct->setEnabled(false);
	m_newAct->setEnabled(false);
	m_saveAct->setEnabled(false);
	m_saveAsAct->setEnabled(false);

	/*
	 * Set the tooltips to let the user know they can't
	 * click the buttons while AIML is loading.
	 */
	m_openDirAct->setToolTip("Cannot open a directory while AIML is loading");
	m_openAct->setToolTip("Cannot open a file while AIML is loading");
	m_newAct->setToolTip("Cannot clear an AIML session while one is loading");
	m_saveAct->setToolTip("Cannot save an AIML session while one is loading");
	m_saveAsAct->setToolTip("Cannot save an AIML session while one is loading");
}

void MainWindow::aimlDoneLoading()
{
	/*
	 * Enable the buttons which would have caused problems
	 * during the loading of AIML if they were pressed.
	 */
	m_openAct->setEnabled(true);
	m_openDirAct->setEnabled(true);
	m_newAct->setEnabled(true);
	m_saveAct->setEnabled(true);
	m_saveAsAct->setEnabled(true);


	/*
	 * Set the tooltips back to "normal".
	 */
	m_openDirAct->setToolTip("Open a AIML directory");
	m_openAct->setToolTip("Open an AIML file");
	m_newAct->setToolTip("Clear a current AIML session");
	m_saveAct->setToolTip("Save the current AIML session as plain text");
	m_saveAsAct->setToolTip("Save the current AIML session as plain text");

	//Show the message that AIML is done loading in the bottom of the gui
	statusBar()->showMessage(tr("AIML done loading"));

	//Set the cursor to the hour glass to indicate "we're *not* busy"
	QApplication::restoreOverrideCursor();
}

bool MainWindow::save()
{
	/*
	 * If we don't have a "current" file that
	 * we've been saving to then let's saveAs
	 * and get one.  Otherwise, just save to 
	 * that "current" file.
	 */
    if (m_curFile.isEmpty()) 
	{
        return saveAs();
    } 
	else 
	{
        return saveFile(m_curFile);
    }
}

void MainWindow::setCurrentFile(const QString &fileName)
{
	/*
	 * Set the object's variable to the fileName
	 * and then use the file Name to display in the
	 * gui window title bar
	 */
	m_curFile = fileName;
	QString shownName;

	if (m_curFile.isEmpty())
	{
		shownName = "untitled.txt";
	}
    else
	{
		shownName = strippedName(m_curFile);
	}

	setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("AIML Simple Qt GUI")));

}

QString MainWindow::strippedName(const QString &fullFileName)
{
	//Strip the name
    return QFileInfo(fullFileName).fileName();
}

bool MainWindow::saveAs()
{
	//Bring up the GUI dialog to select a file
    QString fileName = QFileDialog::getSaveFileName(
		this,
		"Choose a filename to save this AIML session as plain text",
		"",
		"Text Files(*.txt)\nAll Files (*.*)");
	
	//No file, let's return false
	if (fileName.isEmpty())
        return false;
	
	//We have a file, return if we could save it okay or not.
    return saveFile(fileName);
}



bool MainWindow::saveFile(const QString &fileName)
{
	/*
	 * Try to open the file for writing
	 * and throw an error if we can't
	 */
	QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) 
	{
        QMessageBox::warning(this, tr("Application"),
                                tr("Cannot write file %1:\n%2.")
                                .arg(fileName)
                                .arg(file.errorString()));
        return false;
    }
	
	/*
	 * Write the conversation out as plain text
	 * to the file
	 */
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
	out << m_botOutputField->toPlainText();
    QApplication::restoreOverrideCursor();

	/* 
	 * This file is our "current" file and is to 
	 * be saved to each time we save a file unless
	 * they select "save as"
	 */
    setCurrentFile(fileName);

	//Show on the bottom part of the gui that the file had been saved
	statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}




MainWindow::MainWindow()
	: m_okButton(new QPushButton("Enter")),
	  m_userInputField(new QLineEdit),
	  m_botOutputField(new CustomTextEdit),
	  m_botName("No bot name")
{
	/* 
	 * Start our Aiml engine thread.  We start
	 * it at lowest priority to give the gui a 
	 * bit of extra responsiveness at the expense
	 * that the engine will load slower
	 */
	m_AIMLEngineThread.start(QThread::LowestPriority);

	//Setup QT connections to the AIML engine.
	setupConnections();

	//Setup initial gui properties 
	setupInitialProperties();	
	
	//Show in the lower part of the gui that "The gui is loaded"
	createStatusBar();
	
	//Create the GUI actions from memory
	createActions();
	
	//Create our GUI menus
	createMenus();
	
	//Create our GUI tool bars
	createToolBars();
	
	//Setup the GUI layout
	setupLayout();	

	/*
	 * Set the focus to the user input field so the 
	 * user doesn't have to click it to start
	 * and make it more user friendly
	 */
	m_userInputField->setFocus();
}

void MainWindow::setupConnections()
{

	/*
	 * Make all the signal to signal and 
	 * signal to slot connections from this 
	 * object to the AIMLEngineThread 
	 * object.
	 */
	bool b = connect(m_okButton, SIGNAL(clicked()), 
                     this, SLOT(input()));

	b = connect(this, SIGNAL(userTextEntered(const QString &)),
                &m_AIMLEngineThread, SIGNAL(userInput(const QString &)));

	b = connect(&m_AIMLEngineThread, SIGNAL(addText(const QString &)), 
                m_botOutputField, SLOT(append(const QString &)));

	b = connect(m_userInputField, SIGNAL(returnPressed()),
                this, SLOT(input()));

	b = connect(&m_AIMLEngineThread, SIGNAL(addBotText(const QString &)),
		        this, SLOT(addBotText(const QString &)));

	b = connect(&m_AIMLEngineThread, SIGNAL(loading()),
		        this, SLOT(aimlLoading()));

	b = connect(&m_AIMLEngineThread, SIGNAL(doneLoading()),
				this, SLOT(aimlDoneLoading()));

	b = connect(&m_AIMLEngineThread, SIGNAL(addBotName(const QString &)),
		        this, SLOT(addBotName(const QString &)));

	b = connect(this, SIGNAL(aimlFileToOpen(const QString &)),
		        &m_AIMLEngineThread, SIGNAL(addFile(const QString &)));

	b = connect(this, SIGNAL(aimlDirectoryToOpen(const QString &)),
			    &m_AIMLEngineThread, SIGNAL(addDirectory(const QString &)));

	b = connect(this, SIGNAL(aimlClear()),
		        &m_AIMLEngineThread, SIGNAL(clearAIML()));

}

void MainWindow::addBotText(const QString &text)
{
	/* 
	 * Set the color of the bot text and 
	 * the name, and the image of our bot,
	 * and then send that.  Aftwards set the
	 * color back to normal.
	 */
	m_botOutputField->setTextColor(QColor(Qt::yellow));
	QString botOutput = m_botName + " says: " + text;

	//Get the global arguments set in main()
	QString imgSrc = string("<img src=\"../resources/pictures/beckyface.png\">").c_str();
	m_botOutputField->append(imgSrc);
	m_botOutputField->append(botOutput);
	m_botOutputField->setTextColor(QColor(Qt::white));
}

void MainWindow::addBotName(const QString &text)
{
	//Set our bot name to what we were told it is.
	m_botName = text;
}

void MainWindow::createMenus()
{
	//Standard QT creating and adding menus
	m_fileMenu = menuBar()->addMenu("&File");
    m_fileMenu->addAction(m_newAct);
    m_fileMenu->addAction(m_openAct);
    m_fileMenu->addAction(m_openDirAct);
    m_fileMenu->addAction(m_saveAct);
    m_fileMenu->addAction(m_saveAsAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAct);

	menuBar()->addSeparator();
	m_helpMenu = menuBar()->addMenu(tr("&Help"));
	m_helpMenu->addAction(m_aboutAct);

}

void MainWindow::newFile()
{
	/*
	 * New AIML file.  So clear the 
	 * previous text and tell the 
	 * AIMLEngineThreadthat it should 
	 * destroy the AIMLEngine
	 */
	m_botOutputField->clear();
	m_botOutputField->setTextColor(QColor(Qt::white));
	emit aimlClear();
}


void MainWindow::createActions()
{

	//Standard creating and connecting QT Actions.
	m_newAct = new QAction(QIcon("../resources/pictures/new.png"), tr("&New"), this);
	m_newAct->setShortcut(tr("Ctrl+N"));
	m_newAct->setStatusTip(tr("Unload the current aiml session"));
	connect(m_newAct, SIGNAL(triggered()), this, SLOT(newFile()));

	m_openAct = new QAction(QIcon("../resources/pictures/open.png"), tr("&Open"), this);
    m_openAct->setShortcut(tr("Ctrl+O"));
    m_openAct->setStatusTip("Add an individual AIML file");
	connect(m_openAct, SIGNAL(triggered()), this, SLOT(openFile()));

	m_openDirAct = new QAction(QIcon("../resources/pictures/openDir.png"), tr("&OpenDirectory"), this);
    m_openDirAct->setShortcut(tr("Ctrl+D"));
    m_openDirAct->setStatusTip("Add an entire AIML directory");
	connect(m_openDirAct, SIGNAL(triggered()), this, SLOT(openDir()));


	m_saveAct = new QAction(QIcon("../resources/pictures/save.png"), tr("&Save"), this);
	m_saveAct->setShortcut(tr("Ctrl+S"));
	m_saveAct->setStatusTip(tr("Save the AIML conversation to disk"));
	connect(m_saveAct, SIGNAL(triggered()), this, SLOT(save()));

	m_saveAsAct = new QAction(tr("Save &As..."), this);
	m_saveAsAct->setStatusTip(tr("Save the document under a new name"));
	connect(m_saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

	m_exitAct = new QAction(tr("E&xit"), this);
	m_exitAct->setShortcut(tr("Ctrl+Q"));
	m_exitAct->setStatusTip(tr("Exit the application"));
	connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));

	m_aboutAct = new QAction(tr("&About"), this);
	m_aboutAct->setStatusTip(tr("Show the About box"));
	bool b = connect(m_aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createToolBars()
{
	//Standard QT creating ToolBars
	m_fileToolBar = addToolBar(tr("File"));
	m_fileToolBar->addAction(m_newAct);
	m_fileToolBar->addAction(m_openAct);
	m_fileToolBar->addAction(m_openDirAct);
	m_fileToolBar->addAction(m_saveAct);
}

void MainWindow::createStatusBar()
{
	//Show the gui is loaded, this method is pretty useless actually
	statusBar()->showMessage(tr("GUI Loaded"));
}


void MainWindow::setupInitialProperties()
{
	//Name of our background file
	const QString backgroundFile = string("../resources/pictures/background.png").c_str();

	//Name of the icon file
	const QString iconFile = string("../resources/pictures/beckyface.png").c_str();

	//Set the current saved file to default 
	setCurrentFile("");

	/*
	 * Load our icon for the uppper left
	 * of the GUI
	 */
	QPixmap iconPixmap;
	iconPixmap.load(iconFile);
	if(iconPixmap.load(iconFile))
	{
		QIcon icon(iconPixmap);
		setWindowIcon(icon);
	}

	//Can't write to the where the bot is talking
	m_botOutputField->setReadOnly(true);

	//Setup our pretty font.
	QFont bookFont("Book Antiqua", 12);
	m_botOutputField->setFont(bookFont);

	/*
	 * Load the background file and setup the 
	 * bot output field to the background.
	 */
	QPixmap pixmap;
	if(pixmap.load(backgroundFile))
	{
	    m_botOutputField->setTextColor(QColor(Qt::white));
		m_botOutputField->append("[Loaded pixmap: " + backgroundFile + "]");
		QPalette palette;
		palette.setBrush(QPalette::Base, QBrush(pixmap));
		m_botOutputField->setPalette(palette);
	}
	else
	{
	    m_botOutputField->setTextColor(QColor(Qt::black));
		m_botOutputField->append("[WARNING Failed to load pixmap: " + backgroundFile + "]"); 
	}
}

void MainWindow::setupLayout()
{
	/*
	 * Setup the layout so when resizing
	 * happens it does so with grace with
	 * the widgets all moving around together
	 * in a choherient way.
	 */
	QWidget *widget = new QWidget;
	QVBoxLayout *vlayout = new QVBoxLayout;
	QHBoxLayout *hlayout = new QHBoxLayout;
	hlayout->addWidget(m_userInputField);
	hlayout->addWidget(m_okButton);
	vlayout->addWidget(m_botOutputField);
	vlayout->addLayout(hlayout);
	widget->setLayout(vlayout);
	setCentralWidget(widget);
}

void MainWindow::about()
{
	//Display standard about box.
	QMessageBox::about(this, tr("Rebecca AIML"),
			tr("RebeccaAIML is a Windows/Linux Object Oriented<br>"
			"C++ chatter bot api/interpreter for AIML<br>" 
			"(Artificial Intelligence Markup Language)<br>" 
			"from the ALICE project. It includes comprehensive<br>"
			"documentation and samples as well as showcases/teaches<br>"
			"popular and recent C++ practices.<br><br>"
			"<a href=\"http://rebecca-aiml.sourceforge.net/index.htm\">"
			"http://rebecca-aiml.sourceforge.net/index.htm</a>"));
}




} //end of qtgui namespace 

