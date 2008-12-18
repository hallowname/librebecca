#ifndef REBECCA_EXCEPTIONS_H
#define REBECCA_EXCEPTIONS_H

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


//To get the REBECA_EXPORT macro
#include <rebecca/exports.h>

//See AimlFacade for the explanation of this namespace
namespace rebecca 
{
//See AimlFacade for the explanation of this namespace
namespace impl 
{

/**
 * Base Exception class where all AIML exceptions are 
 * derived from.  
 *
 * This mimicks the Standard Library's exception class.
 * The reason for it and not the standard library is 
 * because the Standard Library cannot be used in any of
 * rebeccaAIML's public interfaces.
 *
 * This constraint gives the users of rebeccaAIML the 
 * choice of their own Standard Library and not become
 * tied to a particular implementation of the Standard 
 * Library.
 * 
 * All Standard Library exceptions that occur inside of 
 * rebeccaAIML are caught and rewrapped inside of this 
 * Exception.  Therefore, no Standard Library exceptions
 * will be thrown outside of rebeccaAIML.
 */
class REBECCA_EXPORT Exception
{
	public:

		/**
		 * Get the message or jist of what occurred 
		 * when the exception was thrown.
		 *
		 * By default, if a sub class does not override
		 * this method and throw a custom message, this 
		 * will return "unknown exception" message.
		 *
		 * @return  Will return the message or jist of
		 * what occured when the exception was thrown.
		 * 
		 * @exception Will not throw any
		 */
		virtual const char* what() const throw() 
		{ 
			return "unknown exception";
		}

		/**
		 * Default Empty virtual destructor.
		 */
		virtual ~Exception() { } 
};

/**
 * When Illegal Arguments are given to a AIML method, the 
 * method will throw this exception.
 *
 * Illegal Arguments are usually invalid text given 
 * to AIML methods.  Examples of invalid text are invalid 
 * constructed regular expressions or locations of files with 
 * invalid text such as invalid path seperators.
 */
class REBECCA_EXPORT IllegalArgumentException : public Exception
{ 
	public:

		/**
		 * Default Empty virtual destructor.
		 */
		virtual ~IllegalArgumentException() { } 
};

/** 
 * When a file is not found from a method, the method 
 * will throw this exception.  
 *
 * When the user indicates that indeed a file does exist
 * at their specified location but it does not, this exception
 * will be thrown.
 */
class REBECCA_EXPORT FileNotFoundException : public Exception
{ 
	public:

		/**
		 * Default Empty virtual destructor.
		 */
		virtual ~FileNotFoundException() { } 
};

/** 
 * When a directory is not found from a method, the method 
 * will throw this exception.  
 *
 * When the user indicates that indeed a directory does exist
 * at their specified location but it does not, this exception
 * will be thrown.
 */
class REBECCA_EXPORT DirectoryNotFoundException : public Exception
{ 
	public:

		/**
		 * Default Empty virtual destructor.
		 */
		virtual ~DirectoryNotFoundException() { }
};

/** 
 * If a initialization of an object does not occur correctly, 
 * resulting in an incomplete or "zombie" object this exception
 * will be thrown.
 *
 * Usually this exception will be thrown if the XML parsing engine
 * inside of RebeccaAIML cannot be started correctly or another 
 * RebeccaAIML subinitialization cannot be started.
 *
 */
class REBECCA_EXPORT InitializationException : public Exception
{
	public:

		/**
		 * Default Empty virtual destructor.
		 */
		virtual ~InitializationException() { } 
};

/** 
 * If an XMLError occurs inside of a user invoked method,
 * this exception will be thrown.
 *
 * Usually the XMLError will be because of invalid 
 * XML.
 */
class REBECCA_EXPORT XMLErrorException : public Exception
{
	public:

		/**
		 * Default Empty virtual destructor.
		 */
		virtual ~XMLErrorException() { } 
};

/**
 * If a recursion of any type occurs this exception will 
 * be thrown.
 */
class REBECCA_EXPORT RecursionException : public Exception
{
	public:
		
		/**
		 * Default Empty Virtual destructor.
		 */
		virtual ~RecursionException() { } 
};

/**
 * If a network exception of any type occurs this exception will 
 * be thrown.  This is used with the NetworkGraphBuilder and 
 * the NetworkAimlFacade classes.
 */
class REBECCA_EXPORT NetworkException : public Exception
{
	public:
		
		/**
		 * Default Empty Virtual destructor.
		 */
		virtual ~NetworkException() { } 
};

/**
 * If a numeric exception of any type occurs this exception will 
 * be thrown.  This is typically used with the StringPimpl class 
 * to designate that the string did not contain a number whenever 
 * StringPimpl::getInteger() is called.
 */
class REBECCA_EXPORT NumberFormatException : public Exception
{
	public:
		
		/**
		 * Default Empty Virtual destructor.
		 */
		virtual ~NumberFormatException() { } 
};

/**
 * This exception occurs because of a programming error
 * inside of RebeccaAIML its self.
 *
 * Rebecca has a series of internal tests which check for 
 * corrupted programming as the result of the programmer 
 * making mistakes or assumptions which turn out to not be
 * true.  When the mistake is grave enough to warrent the 
 * termination of the program, this exception is thrown.
 *
 * Although none of the public interfaces can explicitly 
 * throw this exception it is useful to expose it publicly.
 * 
 * If you are getting a Exception which you suspect is a 
 * InternalProgrammerErrorException try casting to it.  If the cast 
 * succeeds, you know there is a serious bug inside of RebeccaAIML 
 * that needs to be reported.  Take the message from the 
 * Exception::what() and file a bug report.
 *
 * Also, without casting, you can recognize this exception from its 
 * Exception::what() output.  The format of the Exception::what() will 
 * be: 
 * 
 * [ (some Method signature) ] message about the method signature.
 * 
 * Example:  [StringPimpl Condition::getString()] Condition block code is corrupted 
 */
class REBECCA_EXPORT InternalProgrammerErrorException : public Exception
{
	public:
		/**
		 * Default Empty virtual destructor.
		 */
		virtual ~InternalProgrammerErrorException() { } 
};

} //end of namespace impl

//expose the exception handlers to rebecca namespace
using rebecca::impl::Exception;
using rebecca::impl::IllegalArgumentException;
using rebecca::impl::FileNotFoundException;
using rebecca::impl::DirectoryNotFoundException;
using rebecca::impl::InitializationException;
using rebecca::impl::XMLErrorException;
using rebecca::impl::InternalProgrammerErrorException;
using rebecca::impl::RecursionException;
using rebecca::impl::NetworkException;
} //end of namespace rebecca


#endif
