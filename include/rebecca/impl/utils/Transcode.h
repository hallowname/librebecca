#ifndef REBECCA_IMPL_UTILS_TRANSCODE_H
#define REBECCA_IMPL_UTILS_TRANSCODE_H

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

//rebecca includes
#include <rebecca/Exceptions.h>
#include <rebecca/StringPimpl.h>

//xerces includes
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLString.hpp>
#include <exception>

//std includes
#include <string>
typedef std::basic_string<XMLCh> XercesString;

namespace rebecca
{

namespace impl
{

namespace utils
{

using namespace std;
XERCES_CPP_NAMESPACE_USE

class nullString : public Exception { };

class Transcode
{
	public:

		inline Transcode() { }
		inline Transcode(const XMLCh * const chars)
			: m_XMLch(chars)
		{
	
			if(m_XMLch.isEmpty())
			{
				throw nullString();
			}
		}

		inline Transcode(const char * const chars)
			: m_XMLch(chars)
		{
			if(m_XMLch.isEmpty())
			{
				throw nullString();
			}
		}

		inline void translate(const XMLCh * const chars)
		{
			m_XMLch.translate(chars);	

			if (m_XMLch.isEmpty())
			{
				throw nullString();
			}
		}		
		inline void translate(const char * const chars)
		{
			m_XMLch.translate(chars);

			if(m_XMLch.isEmpty())
			{
				throw nullString();
			}
		}

		inline bool isEmpty() const
		{
			return m_XMLch.isEmpty();
		}

		inline const char *getChar()
		{
			return m_XMLch.getChar();
		}

		inline const XMLCh *getXmlChar()
		{
			return m_XMLch.getXmlChar();
		}

		inline const string getString()
		{
			return string(m_XMLch.getChar());
		}

		inline const StringPimpl getStringPimpl()
		{
			return StringPimpl(m_XMLch.getChar());
		}

		inline ~Transcode() { }

	private:

		class scopedXMLCh 
		{
			public:
				inline scopedXMLCh() 
					: m_char(0), m_xmlChar(0) 
				{ }

				inline scopedXMLCh(const XMLCh * const chars)
					: m_char(XMLString::transcode(chars)), m_xmlChar(0) 
				{ }
				
				inline scopedXMLCh(const char * const chars)
					: m_char(0), m_xmlChar(XMLString::transcode(chars)) 
				{ } 

				inline void translate(const char * const chars)
				{
					if(m_xmlChar)
					{
						XMLString::release(&m_xmlChar);
					}
					m_xmlChar = XMLString::transcode(chars);
				}

				inline void translate(const XMLCh * const chars)
				{					
					if(m_char)
					{
						XMLString::release(&m_char);
					}
					m_char = XMLString::transcode(chars);
				}

				inline const char* getChar()
				{
					if(m_char)
					{
						return m_char;
					}
					else if(m_xmlChar)
					{
						translate(m_xmlChar);
						//should have a m_char now
						if(m_char)
						{
							return m_char;
						}
						else
						{
							throw nullString();
						}
					}
					else //both are null
					{
						throw nullString();
					}
				}
				
				inline const XMLCh *getXmlChar()
				{
					if(m_xmlChar)
					{
						return m_xmlChar;
					}
					else if(m_char)
					{
						translate(m_char);
						//show have a m_xmlChar now
						if(m_xmlChar)
						{
							return m_xmlChar;
						}
						else
						{
							throw nullString();
						}

					}
					else //both are null
					{
						throw nullString();
					}
				}

				inline bool isEmpty() const
				{
					//return false only if both representations are empty
					return (m_char == 0 && m_xmlChar == 0);
				}

				
				inline ~scopedXMLCh()
				{
					XMLString::release(&m_char);
					XMLString::release(&m_xmlChar);
				}

			private:
				char *m_char;
				XMLCh *m_xmlChar;
		};

		scopedXMLCh m_XMLch;
};


} //end of util namespace


//Expose what I want to the 
//impl namespace
using utils::Transcode;
using utils::nullString;

} //end of impl namespace

} //end of bot namespace



#endif
