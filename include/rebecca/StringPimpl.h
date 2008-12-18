#ifndef REBECCA_STRINGPIMPL_H
#define REBECCA_STRINGPIMPL_H

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
#include <rebecca/Exceptions.h>

//To get the size_t for the deletions
#include <cstddef>

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif


//See AimlFacade for the explanation of this namespace
namespace rebecca
{
//See AimlFacade for the explanation of this namespace
namespace impl
{



/*
 * The private string which I do not expose.
 * 
 * This forward decleration is so that the code will 
 * compile but the true string is kept private within
 * this class.
 */	
class StringPrivate;

/**
 * A string Private Implementation.
 *
 * This Private implementation's purpose (also commonly 
 * known on the internet as pimpl) is to not tie the user
 * of RebeccaAIML to a particular Standard Library by 
 * using a Standard Library string.
 *
 * Also, this private implementation handles the memory
 * management of strings inside the RebeccaAIML dll which 
 * is a requirement for Dll memory boundary safety.  
 * Standard Libraries could and sometimes do break Dll 
 * memory boundary safeties, hence another reason this 
 * class is needed.
 * 
 * Only a few needed methods are provided.  Once you get
 * this string object back, you should copy it into your own
 * standard string container.
 * 
 * Example:  StringPimpl s = someFoo(); std::string myString(s.c_str);
 */
class REBECCA_EXPORT StringPimpl
{
	public:

		/**
		 * Constructor that takes no arguments.
		 *
		 * The private string's empty constructor is called.
		 *
		 * @exception This will not explicitly throw an
		 * exception, but an underlying method might.  More
		 * than likely only a (bad_alloc) will be thrown for
		 * a out of memory exception.  If so, the bad_alloc's 
		 * message will be wrapped in the Exception class.
		 */
		StringPimpl() 
			throw(Exception &);

		/**
		 * Constructor that takes in a const char.
		 *
		 * The char is copied to the private String.
		 *
		 * @param stringPimpl The const char which is
		 * copied to the private String.
		 * 
		 * @exception This will not explicitly throw an
		 * exception, but an underlying method might.  More
		 * than likely only a (bad_alloc) will be thrown for
		 * a out of memory exception.  If so, the bad_alloc's 
		 * message will be wrapped in the Exception class.
		 */
		StringPimpl(const char * const stringPimpl) 
			throw(Exception &);
		
		/**
		 * Just like the Standard String's c_str, this 
		 * returns the internal string in the form of 
		 * a const char.
		 *
		 * Use this to copy the string into whichever type
		 * of String you deem suitable.
		 *
		 * @exception It will not explicitly throw an exception,
		 * but an underlying method might.  More than likely
		 * this will never throw an exception.
		 */
		const char *c_str() const 
			throw(Exception &);

		/**
		 * Predicate which returns true if the internal
		 * string is empty and false if it is not empty.
		 * 
		 * @return True if the internal string is empty, 
		 * false if the internal string is not empty.
		 *
		 * @exception It will not explicitly throw an exception,
		 * but an underlying method might.  More than likely
		 * this will never throw an exception.
		 */
		bool empty() const 
			throw(Exception &);

		/**
		 * Standard copy construtor.
		 * 
		 * @param stringPimpl Standard secondary 
		 * const StringPimpl reference needed for a 
		 * copy constructor.
		 * 
		 * @exception This can throw anything but will not 
		 * explicitly throw an exception.
		 */
		StringPimpl(const StringPimpl& stringPimpl);

		/** 
		 * Standard assignment operator.
		 * 
		 * Performs a deep copy of the internal string.
		 * 
		 * @param stringPimpl Standard secondary reference
		 * 
		 * @exception This can throw anything but will not
		 * explicitly throw an exception.
		 */
		StringPimpl &operator=(const StringPimpl &stringPimpl);

		/**
		 * Standard virtual destructor.
		 *
		 * This destorys the internal memory of the internal 
		 * string private implementation.  The deallocation of the
		 * memory occurs inside of the dll, therefore this 
		 * satisfies the requirement to be dll memory boundary safe.
		 */
		virtual ~StringPimpl();
		
		/**
		 * All delete's will be handled through
		 * this dll.
		 *
		 * This is required for dll boundary safety.
		 * Instead of allowing the compiler to 
		 * choose if it wants to inline this 
		 * we have made it so that it cannot.
		 * If we let the compiler choose to 
		 * inline or not inline this and the 
		 * "new operator" we can run into dll
		 * boundary issues.  The issue would be
		 * that the compiler would inline one 
		 * and not the other.  Thus, your 
		 * executable with its own heap would 
		 * allocate/delete and this dll would 
		 * do the other.  That's a dll boundary
		 * safety violation.
		 * 
         * @param p The pointer to an instance
		 * of this object.
		 */
        void operator delete(void* p);

		/**
		 * All new's will be handled through
		 * this dll.
		 *
		 * This is required for dll boundary safety.
		 * Instead of allowing the compiler to 
		 * choose if it wants to inline this 
		 * we have made it so that it cannot.
		 * If we let the compiler choose to 
		 * inline or not inline this and the 
		 * "delete operator" we can run into dll
		 * boundary issues.  The issue would be
		 * that the compiler would inline one 
		 * and not the other.  Thus, your 
		 * executable with its own heap would 
		 * allocate/delete and this dll would 
		 * do the other.  That's a dll boundary
		 * safety violation.
		 * 
         * @param size The size to allocate 
		 * an instance of this object with.
		 *
		 * @return An instance of this object
		 */
		void *operator new(size_t size);

		///@todo document all this

		/** 
		 * Stanard += operator
		 *
		 * @param s The right hand string to 
		 * add to
		 */
		StringPimpl& operator+=(const StringPimpl &s);

		/** 
		 * Stanard += operator
		 *
		 * @param s The right hand string to 
		 * add to
		 */
		StringPimpl& operator+=(const char *s);

		/** 
		 * Stanard != operator
		 *
		 * @param s The right hand string to 
		 * compare to
		 *
		 * @return true if they aren't equal
		 * otherwise false
		 */
		bool operator!=(const char *s) const;

		/** 
		 * Stanard + operator
		 *
		 * @param s The right hand string to 
		 * add to
		 *
		 * @return The string result of the 
		 * addition
		 */
		StringPimpl operator+(const char *s) const;

		/** 
		 * Stanard == operator
		 *
		 * @param s The right hand string to 
		 * compare to
		 *
		 * @return True if they're equal otherwise
		 * false
		 */
		bool operator==(const StringPimpl &s) const;
		
		/** 
		 * Stanard == operator
		 *
		 * @param s The right hand string to 
		 * compare to
		 *
		 * @return True if they're equal otherwise
		 * false
		 */
		bool operator==(const char *s) const;

		/** 
		 * Returns true if this string starts
		 * with the string given as an argument.
		 *
		 * @param right The string to check if this 
		 * string starts with it.
		 *
		 * @return True if this string starts with 
		 * the argument otherwise false.
		 */
		bool startsWith(const StringPimpl &right) const;

		/** 
		 * Returns true if this string ends
		 * with the string given as an argument.
		 *
		 * @param right The string to check if this 
		 * string ends with it.
		 *
		 * @return True if this string ends with 
		 * the argument otherwise false.
		 */
		bool endsWith(const StringPimpl &right) const;

		/**
		 * Returns the substring the same as a regular
		 * standard template string would return.
		 *
		 * @param start The start of the string to use
		 *
		 * @param end The end of the string to use
		 *
		 * @return The substring 
		 */
		StringPimpl substr(unsigned int start, unsigned int end) const;

		/**
		 * Replaces all occurances within the string with a new value.
		 *
		 * @param replace What to search for to replace
		 *
		 * @param newValue The value to replace the found occurance 
		 * in the string with
		 */
		void transfromByReplacingAll(const StringPimpl replace, const StringPimpl newValue);

		/**
		 * Returns the integer representation of 
		 * this string.
		 *
		 * @exception NumberFormatException If this
		 * string does not represent a number this 
		 * will throw a NumberFormatException
		 */
		int getInteger() const
			throw(NumberFormatException &);

		/**
		 * Returns true if this string represents
		 * a file on the file system.
		 *
		 * If you create a string that is a path 
		 * to a file on the file system and call this
		 * method you will get a true.
		 *
		 * @return True if this string represents a 
		 * file on the file system otherwise false
		 *
		 * @exception This will not throw any 
		 * exceptions
		 */
		bool existsAsAFile() const
			throw();

		/**
		 * Returns true if this string represents
		 * a directory on the file system.
		 *
		 * If you create a string that is a path 
		 * to a directory on the file system and 
		 * call this method you will get a true.
		 *
		 * @return True if this string represents a 
		 * directory on the file system otherwise false
		 *
		 * @exception This will not throw any 
		 * exceptions
		 */
		bool existsAsADirectory() const
			throw();
		
		/**
		 * Transform the string to an absolute 
		 * file path to a directory or file 
		 * on the system.
		 *
		 * If this string represents a file or 
		 * directory on the file system you can 
		 * call this method to transform the string
		 * into an absolute path on the file system.
		 *
		 * @exception This will not throw any 
		 * exceptions
		 */
		void transformIntoAbsoluteFilePath() const
			throw();

		/** 
		 * Stanard + operator
		 *
		 * @param s The right hand string to 
		 * compare to
		 *
		 * @return Returns the result string
		 */
		StringPimpl operator+(const StringPimpl &s) const;

		/** 
		 * Stanard = operator
		 *
		 * @param c The right hand string to 
		 * compare to
		 *
		 * @return Returns the result string
		 */
		StringPimpl &operator=(const char *c);

		/** 
		 * Stanard = operator
		 *
		 * @param c The right hand char to 
		 * compare to
		 *
		 * @return Returns the result string
		 */
		StringPimpl &operator=(const char c);

		/** 
		 * Returns the size of this string
		 *
		 * @return Returns the size of this string
		 */
		unsigned int size() const;

		/** 
		 * Returns the length of this string
		 *
		 * @return Returns the length of this string
		 */
		unsigned int length() const;

		/**
		 * Returns a specific char at a location
		 * within the string.
		 *
		 * @param i The position in the string to 
		 * get the char at.
		 *
		 * @return Returns the char at the specified
		 * spot
		 */
		char at(const unsigned int i) const;

		/** 
		 * Stanard < operator
		 *
		 * @param s The right hand string to 
		 * compare to
		 *
		 * @return Returns true if the right
		 * hand string is less than this string
		 */
		bool operator<(const StringPimpl& s) const;

		/** 
		 * Stanard != operator
		 *
		 * @param s The right hand string to 
		 * compare to
		 *
		 * @return Returns true if the right
		 * hand string is not equal to this string
		 */
		bool operator!=(const StringPimpl &s) const;

		/**
		 * Push back a character to the end of 
		 * this string.
		 *
		 * @param c The character to push back to 
		 * the end of this string.
		 */
		void push_back(char c);

		/**
		 * Clears the contents of this string
		 */
		void clear();
	
		/**
		 * Transforms the contents of this 
		 * string to upper case.
		 *
		 * @return Return the string transformed
		 * to upper case
		 */
		StringPimpl &transformToUpperCase()
			throw();

		/**
		 * Transforms the contents of this 
		 * string to lower case.
		 *
		 * @return Return the string transformed
		 * to lower case
		 */
		StringPimpl &transformToLowerCase()
			throw();

		/**
		 * Transforms the contents of this 
		 * string by trimming off any white space 
		 * to the left or right of this string. 
		 *
		 * @return Return the string with excess
		 * white space trimmed off the left and 
		 * right side.
		 */
		StringPimpl &transformByTrimmingWhiteSpace()
			throw();

		/**
		 * Transforms the contents of this 
		 * string's first character to upper case. 
		 *
		 * @return Return the string with the 
		 * frist character an upper case. 
		 */
		StringPimpl &transformFirstCharacterUpperCase()
			throw();

		/**
		 * Transforms the contents of this 
		 * string by trimming off any white space 
		 * to the left of this string. 
		 *
		 * @return Return the string with excess
		 * white space trimmed off the left side.
		 */
		StringPimpl &transformByTrimmingLeft()
			throw();

		/**
		 * Transforms the contents of this 
		 * string by trimming off any white space 
		 * to the right of this string. 
		 *
		 * @return Return the string with excess
		 * white space trimmed off the right side.
		 */
		StringPimpl &transformByTrimmingRight()
			throw();

		/**
		 * Transforms the contents of this 
		 * string by trimming off any white space 
		 * to the left or right of this string 
		 * as well as newline characters and carriage
		 * returns.
		 *
		 * @return Return the string with excess
		 * white space, newline characters, and 
		 * carriage returns trimmed off the left and 
		 * right side.
		 */
		StringPimpl &transformByTrimmingExcessSpaces()
			throw();

		/**
		 * Removes all punctuation from the string given 
		 * a list of puncutation.
		 *
		 * @param sentenceSplitters The list of punctuation
		 * to remove from this string.
		 */
		void removePunctuation(const StringPimpl &sentenceSplitters)
			throw();
	
		/**
		 * Given a number this will return a new string representation
		 * of that number.
		 *
		 * @param number The number to get back the string representation
		 * of
		 *
		 * @exception NumberFormatException If the number can't be 
		 * converted this will throw a NumberFormatException
		 */
		static StringPimpl getString(int number)
			throw(NumberFormatException &);

	private:

		/**
		 * Private method to avoid duplicate code between
		 * the constructor and the copy constructor.
		 *
		 * @param stringPimpl The const char which is
		 * copied to the private String.
		 * 
		 * @exception This can throw anything.
		 *
		 */ 
		void init(const char * const stringPimpl);
		
		/**
		 * The private String which I do not expose.
		 *
		 * The memory for this is handled automatically 
		 * inside of the constructor and destructor of this 
		 * class.
		 */
		StringPrivate *m_pimpl;
};

} //end namespace impl

//expose StringPimpl to Rebecca namespace 
using rebecca::impl::StringPimpl;

/**
 * Standard == 
 *
 * @param c The character to compare with
 *
 * @param s The string to compare with
 *
 * @return Return true if the character and string
 * are equal otherwise return false
 */
REBECCA_EXPORT bool operator==(const char *c, const StringPimpl &s);

/**
 * Standard + 
 *
 * @param c The character to compare with
 *
 * @param s The string to compare with
 *
 * @return Return the string of the character and string
 * added together
 */

REBECCA_EXPORT StringPimpl operator+(const char *c, const StringPimpl &s);

} //end namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif





#endif
