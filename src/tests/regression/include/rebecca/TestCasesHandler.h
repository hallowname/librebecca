#ifndef REBECCA_TESTCASESHANDLER_H
#define REBECCA_TESTCASESHANDLER_H

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


//Xerces includes
#include <xercesc/sax/HandlerBase.hpp>

//Rebecca includes
#include <rebecca/framework/Tag.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/GraphBuilder.h>

//std includes
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

//Boost includes
#include <boost/algorithm/string.hpp>
#include <boost/shared_ptr.hpp>

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif


namespace rebecca
{
namespace impl
{
class GraphBuilderFramework;
XERCES_CPP_NAMESPACE_USE
using namespace std;
using namespace boost;
using namespace rebecca::framework;

class TestCasesHandler : public HandlerBase
{
	public:
		TestCasesHandler(const string outputFileName, GraphBuilder &builder);
		
		void output(const string &msg)
		{
			m_output << msg << endl;
		}

		void outputln(const string &msg)
		{
			m_output << msg << "<br/>" << endl;
		}

		void setInput(const string &input)
		{
			m_input = input;
		}
		
		void setExpectedKeywords(const string &expectedKeyWord)
		{
			m_keyWords.push_back(expectedKeyWord);
		}
		void setExpectedOutput(const string &expectedOutput)
		{
			m_expectedAnswer = expectedOutput;
		}
		void clear()
		{
			m_expectedAnswer.clear();
			m_input.clear();
			m_keyWords.clear();
		}
		void getResponse();

		class TestSuite : public Tag
		{
			public:
				TestSuite(TestCasesHandler &handler) 
					: m_handler(handler) 
				{ 
					this->addInstanceOf("TestSuite");
				}
				
				virtual void handleInnerTag(Tag *tag) 
					throw(InternalProgrammerErrorException &)
				{
					if(tag->instanceOf("TestSuite"))
					{
						TestSuite *testSuite = static_cast<TestSuite *>(tag);
						testSuite->endTag();
					}
					else
					{
						throw InternalProgrammerErrorExceptionImpl("[TestSuite::handleInnerTag(Tag *tag)" 
							                                       "tag was not an instance of TestSuite");
					}
				}

				virtual void endTag() { } 

			protected: 
				TestCasesHandler &m_handler;
		};

		class TestCase : public TestSuite
		{
			public:
				TestCase(TestCasesHandler &handler) 
					: TestSuite(handler) 
				{ 
					addInstanceOf("TestCase");
				} 
				
				virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) throw(InternalProgrammerErrorException &);		

				virtual void endTag() 
				{
					m_handler.getResponse();
					m_handler.clear();
				}


		};

		class Description : public TestCase
		{
			public:
				Description(TestCasesHandler &handler)
					: TestCase(handler) 
				{ 
					addInstanceOf("Description");
				} 

				virtual void addCharacters(const StringPimpl &characters) throw(InternalProgrammerErrorException &);
				
				virtual void endTag() 
				{
					string outputMsg("Description:" + m_characters);
					m_handler.outputln(outputMsg.c_str());
				}

			private:	
				string m_characters;


		};

		class TestCaseInput : public TestCase
		{
			public:
				TestCaseInput(TestCasesHandler &handler)
					: TestCase(handler) 
				{ 
					addInstanceOf("TestCaseInput");
				} 

				virtual void addCharacters(const StringPimpl &characters) throw(InternalProgrammerErrorException &);
				virtual void endTag() 
				{
					string msg("Input:" + m_characters);
					m_handler.outputln(msg.c_str());
					m_handler.setInput(m_characters);
				}
			private:
				string m_characters;
		};


		class ExpectedAnswer : public TestCase 
		{
			public:
				ExpectedAnswer(TestCasesHandler &handler)
					: TestCase(handler) 
				{ 
					addInstanceOf("ExpectedAnswer");
				} 

				virtual void addCharacters(const StringPimpl &characters) throw(InternalProgrammerErrorException &);
				virtual void endTag() 
				{
					trim(m_characters);
					string outputMsg("Expected Answer:" + m_characters);
					m_handler.outputln(outputMsg.c_str());
					m_handler.setExpectedOutput(m_characters);
				}

			private:
				string m_characters;

		};

		class ExpectedKeyWords : public TestCase 
		{
			public:
				ExpectedKeyWords(TestCasesHandler &handler)
					: TestCase(handler) 
				{ 
					addInstanceOf("ExpectedKeyWords");
				} 

				virtual void addCharacters(const StringPimpl &characters) throw(InternalProgrammerErrorException &);

				virtual void endTag()
				{
					string msg("Expected keywords:" + m_characters); 
					m_handler.outputln(msg); 
				   	m_handler.setExpectedKeywords(m_characters);	
				}

			private:
				string m_characters;

		};

		class NoOps : public TestCase
		{
			public:
				NoOps(TestCasesHandler &handler)
					: TestCase(handler) 
				{ 
					addInstanceOf("NoOps");
				} 
				
				virtual void endTag() { } 

		};

		void startElement(const XMLCh* const name, AttributeList& attributes);
		void characters(const XMLCh * const chars, const unsigned int length);

		void endElement(const XMLCh *const name);

		Tag *createTagClass(const string &className);
		virtual ~TestCasesHandler();

	private:
		
		stack<Tag *> m_tagStack;
		Tag *m_currentStartElement;
		string m_outputFileName;
		ofstream m_output;
		ifstream m_inputFile;

		string m_input;
		string m_expectedAnswer;
		GraphBuilder &m_builder;
		vector<string> m_keyWords;
};


} // end of impl namespace
} // end of rebecca namespace

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

