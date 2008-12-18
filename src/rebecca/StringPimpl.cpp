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

//Rebecca includes
#include <rebecca/StringPimpl.h>
#include <rebecca/impl/Exceptions.h>

//Std includes
#include <exception>
#include <vector>
using namespace std;

//Boost includes
#include <boost/lexical_cast.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>    
#include <boost/filesystem/exception.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;
using namespace boost::filesystem;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
#endif

namespace rebecca
{
namespace impl
{
/**
 * Private implementation 
 * sectoin of StringPimpl
 */
class StringPrivate
{
	public:
		/**
		 * Private implementation
		 * of the string.
		 */
		string m_proxy;
};

StringPimpl::StringPimpl() 
	throw(Exception &)
	: m_pimpl(0)
{
	try
	{
		m_pimpl = new StringPrivate;
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl::StringPimpl(const char * const stringPimpl) 
	throw(Exception &)
	: m_pimpl(0)
{
	try
	{
		init(stringPimpl);
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void StringPimpl::init(const char * const stringPimpl)
{
	if(stringPimpl == 0)
	{
		//Error trying to put 0 into a string");
		throw ExceptionImpl("Error in StringPimpl::init, trying to put 0 into a string");
	}
	else
	{
		delete m_pimpl;
		m_pimpl = new StringPrivate;
		m_pimpl->m_proxy = stringPimpl;
	}
}

StringPimpl::StringPimpl(const StringPimpl& stringPimpl)
	: m_pimpl(0)
{	
	try
	{
		init(stringPimpl.c_str());
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

bool StringPimpl::empty() const throw(Exception &) 
{
	try
	{
		return m_pimpl->m_proxy.empty();
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
} 

unsigned int StringPimpl::length() const
{
	return m_pimpl->m_proxy.length();
}

StringPimpl &StringPimpl::operator=(const StringPimpl &stringPimpl)
{
	m_pimpl->m_proxy = stringPimpl.m_pimpl->m_proxy;
	return *this;
}

StringPimpl &StringPimpl::operator=(const char *c)
{
	m_pimpl->m_proxy = c;
	return *this;
}

StringPimpl &StringPimpl::operator=(const char c)
{
	m_pimpl->m_proxy = c;
	return *this;
}

StringPimpl &StringPimpl::transformFirstCharacterUpperCase()
	throw()
{
	if(m_pimpl->m_proxy.length() > 1)
	{
		m_pimpl->m_proxy[0] = toupper(m_pimpl->m_proxy[0]);
	}
	return *this;
}

StringPimpl &StringPimpl::transformByTrimmingLeft()
	throw()
{
	trim_left(m_pimpl->m_proxy);
	return *this;
}

StringPimpl &StringPimpl::transformByTrimmingRight()
	throw()
{
	trim_right(m_pimpl->m_proxy);
	return *this;
}


void StringPimpl::removePunctuation(const StringPimpl &sentenceSplitters)
	throw()
{
	//I use this to set reserve big enough for one character
	string s("x");
	
	//Remove all sentence splitters
	for(unsigned int i = 0; i < sentenceSplitters.m_pimpl->m_proxy.size(); ++i)
	{
		s[0] = sentenceSplitters.m_pimpl->m_proxy.at(i);
		erase_all(m_pimpl->m_proxy, s);
	}
	
	//Also have to erase all instances of comma's
	const string comma(",");
	erase_all(m_pimpl->m_proxy, comma);
}

StringPimpl& StringPimpl::operator+=(const StringPimpl& s)
{
	m_pimpl->m_proxy += s.m_pimpl->m_proxy;
	return *this;
}

bool StringPimpl::operator<(const StringPimpl& s) const
{
	return m_pimpl->m_proxy < s.m_pimpl->m_proxy;
}

bool StringPimpl::operator!=(const char *s) const
{
	return m_pimpl->m_proxy != s;
}

bool StringPimpl::operator!=(const StringPimpl &s) const
{
	return m_pimpl->m_proxy != s.m_pimpl->m_proxy;
}

StringPimpl& StringPimpl::operator+=(const char *s)
{
	m_pimpl->m_proxy += s;
	return *this;
}

StringPimpl StringPimpl::operator+(const char *s) const
{
	return StringPimpl((m_pimpl->m_proxy + s).c_str());
}

StringPimpl StringPimpl::operator+(const StringPimpl &s) const
{
	return StringPimpl((m_pimpl->m_proxy + s.m_pimpl->m_proxy).c_str());
}

bool StringPimpl::operator==(const StringPimpl &s) const
{
	return m_pimpl->m_proxy == s.m_pimpl->m_proxy;
}

bool StringPimpl::operator==(const char *s) const
{
	return m_pimpl->m_proxy == s;
}

char StringPimpl::at(const unsigned int i) const
{
	return m_pimpl->m_proxy.at(i);
}

unsigned int StringPimpl::size() const
{
	return m_pimpl->m_proxy.size();
}

void StringPimpl::push_back(char c)
{
	m_pimpl->m_proxy.push_back(c);
}

void StringPimpl::clear()
{
	m_pimpl->m_proxy.clear();
}

void * StringPimpl::operator new(size_t size)
{
	return ::operator new(size);
}

void StringPimpl::operator delete(void* p) 
{
    ::operator delete(p);
}

const char *StringPimpl::c_str() const throw(Exception &)
{
	try
	{
		return m_pimpl->m_proxy.c_str();
	}
	catch(Exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl StringPimpl::getString(int number) 
	throw(NumberFormatException &)
{
	try
	{
		string s(lexical_cast<string>(number));
		return s.c_str();
	}
	catch(bad_lexical_cast &e)
	{
		throw NumberFormatExceptionImpl(e.what());
		return 0;
	}
}

int StringPimpl::getInteger() const
	throw(NumberFormatException &)
{
	try 
	{
		return lexical_cast<int>(m_pimpl->m_proxy);
	}
	catch(bad_lexical_cast &e)
	{
		throw NumberFormatExceptionImpl(e.what());
		return 0;
	}
}

bool StringPimpl::existsAsAFile() const
	throw()
{
	try
	{
		//Get the file format in the native string for Xerces
		path nativeFileFormat(m_pimpl->m_proxy, native);

		//Get the complete path to the file
		path completePath = complete(nativeFileFormat);
		return exists(completePath) && (!is_directory(completePath));
	}
	catch(exception &)
	{
		return false;
	}
}

bool StringPimpl::existsAsADirectory() const
	throw()
{
	try
	{
		//Get the file format in the native string for Xerces
		path nativeFileFormat(m_pimpl->m_proxy, native);

		//Get the complete path to the file
		path completePath = complete(nativeFileFormat);
		return exists(completePath) && (is_directory(completePath));
	}
	catch(exception &)
	{
		return false;
	}
}

StringPimpl &StringPimpl::transformToUpperCase()
	throw()
{
	to_upper(m_pimpl->m_proxy);
	return *this;
}

StringPimpl &StringPimpl::transformToLowerCase()
	throw()
{
	to_lower(m_pimpl->m_proxy);
	return *this;
}

StringPimpl &StringPimpl::transformByTrimmingExcessSpaces()
	throw()
{
	string copy; 
	copy.reserve(m_pimpl->m_proxy.size());

	typedef string::const_iterator CII;
	bool one_space = false;

	for(CII it = m_pimpl->m_proxy.begin(); it != m_pimpl->m_proxy.end(); ++it)
	{
		//Right off the bat remove all new line's 
		//and treat them as non spaces
		if(*it == '\n')
		{
			continue;
		}

		/*
		 * It is not a empty space of any type,
		 * therefore we want it.
		 */
		if(*it != ' ' || *it == '\t')
		{
			copy.push_back(*it);
			one_space = false;
			continue;
		}

		//Found an empty space, only allow one of these
		if(*it == ' ' || *it == '\t')
		{
			if(!one_space)
			{
				one_space = true;
				copy.push_back(' ');
				continue;
			}
			else
			{
				//ignore extra space
				continue;
			}
		}
	}

	m_pimpl->m_proxy = copy;
	return *this;
}

bool StringPimpl::startsWith(const StringPimpl &right) const
{
	return starts_with(m_pimpl->m_proxy, right.m_pimpl->m_proxy);
}

bool StringPimpl::endsWith(const StringPimpl &right) const
{
	return ends_with(m_pimpl->m_proxy, right.m_pimpl->m_proxy);
}

void StringPimpl::transfromByReplacingAll(const StringPimpl replace, const StringPimpl newValue)
{
	replace_all(m_pimpl->m_proxy, replace.c_str(), newValue.c_str());
}

StringPimpl StringPimpl::substr(unsigned int start, unsigned int end) const
{
	return StringPimpl(m_pimpl->m_proxy.substr(start, end).c_str());
}

void StringPimpl::transformIntoAbsoluteFilePath() const
	throw()
{
	try
	{
		//Get the file format in the native string 
		path nativeFileFormat(m_pimpl->m_proxy, native);

		//Get the complete path to the file
		path completePath = complete(nativeFileFormat);

		//Get the native file system's string to pass to xerces
		m_pimpl->m_proxy = completePath.native_file_string();
	}
	catch(exception &)
	{
		//Do nothing. 
		//No transformation if an exception occurs
	}
}

StringPimpl &StringPimpl::transformByTrimmingWhiteSpace()
	throw()
{
	trim(m_pimpl->m_proxy);
	return *this;
}

StringPimpl::~StringPimpl()
{
	//pool.push_back(m_pimpl);
	delete m_pimpl;
}
} //end of namespace impl

//global functions for overloads
bool operator==(const char *c, const StringPimpl &s)
{
	return s.operator==(c);
}

StringPimpl operator+(const char *c, const StringPimpl &s)
{
	StringPimpl temp(c);
	temp += s;
	return temp;
}

} //end of namespace rebecca

