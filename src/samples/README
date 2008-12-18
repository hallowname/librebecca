------------------------------------------------------------------
* WELCOME!

What's this all about? 

These are samples in which you should be able to build against the 
RebeccaAIML engine.  You should be able to go into each directory 
and build each example with either the provided Linux Makefile or 
the Windows provided Visual Studio solution file.
------------------------------------------------------------------

* [console] sample

In this directory is a bare bones simple console example.  In a few 
lines of code it shows how to integrate the Rebecca engine into your
C++ code.

------------------------------------------------------------------

* [qtgui] sample

In this directory is a QT GUI application.  This sample shows you 
how to integrate the Rebecca engine into your QT GUI applications.  
If you are new to QT you can find more out about it at
http://www.trolltech.com/

A few notes about building this sample for Linux and Windows.  You need 
at least QT 4.1.x.  For Linux, install this version of QT normally as per 
their LINUX instructions.  Then build your makefile by calling "qmake" 
in the directory [src\samples\qtgui].  Finally, call "gmake" and it should 
build correctly.

For Windows, you have two options.  You can either buy the commercial 
supported version, or follow these instructions to patch the GPL
version to work with Visual Studio .NET.  

To Patch Qt4/OpenSource using Qt/Win:
Go to the site: http://prdownloads.sourceforge.net/qtwin/ and download
the latest acs4qt.zip file.  They'll have several named 
acs4qt${version}.zip, get the latest dated version.  Unzip that file
into your Qt/OpenSource installation directory. Read the readme inside
of the zip and follow the instructions.

For example, following the instructions I:
* copied the patch into C:\Qt\4.1.0 and unziped it there
* ran installpatch41.bat
* Opened Microsoft Visual C++ .NET development console by running 
      Start|Programs|Microsoft Visual .NET 2003|Visual Studio .NET Tools|Visual Studio .NET 2003 Command Prompt.
* From that console typed: "cd c:\qt\4.1.0"
* Then from that same console typed: "qconfigure msvc.net"
* Finally from that same console typed "nmake" to build it.

Under Windows after getting QT installed, ensure that you change your environment 
variable QMAKESPEC to win32-msvc.net before trying to build this sample.  Lastly, open
a command prompt in the directory [src\samples\qtgui] and run "qmake".  Now, open
the resulting project file with Visual Studio .NET and you should be able to 
build it.

------------------------------------------------------------------

* [consoleHtmlConverter_tag_layer] sample

In this directory is a complete program that converts AIML XML files
into html pages with links.  The html pages provide a way to "cruise" 
through the AIML brain and see how the brain would look like in memory.

This example is to show how to override the AIML tags and provide your
own functionality.  You can use this complete example to see how to 
add your own custom tag layers.  A tag layer is a layer in which you
can either extend from the normal AIML XML set and add your own 
specialized AIML XML tags or you can override the current existing
AIML XML tags and add your own custom behvaior for the tags.

How to compile this under Windows:

For this sample to compile, you have to install the C++ boost library and
define a few variables.  You can get the most current boost library from
http://www.boost.org/.  The variables you have to define are:

BOOST_INCLUDE -- Point this to the location of your boost header files.
BOOST_LIB     -- Point this to the location of your boost release library.
BOOST_LIBD    -- Point this to the location of your boost debug library.

For example, on a fresh install on the Windows platform I have them set
to:

BOOST_INCLUDE : C:\Boost\include\boost_1_32
BOOST_LIB     : C:\Boost\lib
BOOST_LIBD    : C:\Boost\lib

Notice how I have BOOST_LIB and BOOST_LIBD pointing to the same directory.
That's because by default Boost installs its debug and release library into
the same directory.

How to compile this under Linux:

Simply ensure you have installed the boost libary and that the headers and 
libs are available.  For example, I have /usr/include/boost with the headers
and I have /usr/lib/<boost_libs> boost library files.


