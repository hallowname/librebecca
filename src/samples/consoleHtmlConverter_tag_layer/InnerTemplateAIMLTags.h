#ifndef CUSTOMHTML_INNERTEMPLATEAIMLTAGS_H
#define CUSTOMHTML_INNERTEMPLATEAIMLTAGS_H

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


/*
 * All AIML innertemplate tags
 *
 */
#include <rebecca/framework/Gender.h>
#include <rebecca/framework/Bot.h>
#include <rebecca/framework/Condition.h>
#include <rebecca/framework/Date.h>
#include <rebecca/framework/Formal.h>
#include <rebecca/framework/Gender.h>
#include <rebecca/framework/Get.h>
#include <rebecca/framework/Gossip.h>
#include <rebecca/framework/Id.h>
#include <rebecca/framework/Input.h>
#include <rebecca/framework/Li.h>
#include <rebecca/framework/LowerCase.h>
#include <rebecca/framework/Pattern.h>
#include <rebecca/framework/Person.h>
#include <rebecca/framework/Person2.h>
#include <rebecca/framework/Random.h>
#include <rebecca/framework/Sentence.h>
#include <rebecca/framework/Set.h>
#include <rebecca/framework/Size.h>
#include <rebecca/framework/Srai.h>
#include <rebecca/framework/Star.h>
#include <rebecca/framework/System.h>
#include <rebecca/framework/TemplateSideThat.h>
#include <rebecca/framework/ThatStar.h>
#include <rebecca/framework/Think.h>
#include <rebecca/framework/TopicStar.h>
#include <rebecca/framework/UpperCase.h>
#include <rebecca/framework/NonImplemented.h>
#include <rebecca/framework/Version.h>
#include <rebecca/framework/GraphBuilderFramework.h>
#include <string>

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif

namespace customTag
{
namespace impl
{

using namespace rebecca::framework;
using namespace std;

/**
 * The Custom Gender class that overrides
 * the regular Gender AIML XML Tag
 */
class CustomGender : public Gender
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomGender() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomGender");
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;gender&gt;");
			StringPimpl s = InnerTemplateListImpl::getString();
			returnString += s.c_str();
			returnString += "&lt;/gender&gt;";
			return returnString.c_str();
		}
};

/**
 * The Custom Bot class that overrides
 * the regular Bot AIML XML Tag
 */
class CustomBot : public Bot
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomBot() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomBot");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;bot name=\"" + m_value + "\"/&gt;");
			return returnString.c_str();
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			m_value = value.c_str();
		}

	private:

		/**
		 * Attribute value
		 */
		string m_value;
};

/**
 * The Custom Condition class that overrides
 * the regular Condition AIML XML Tag
 */
class CustomCondition : public Condition
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomCondition() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomCondition");		
		} 
		
		/**
		 * Add the tag to the internal data structure
		 *
		 * @param tag The tag to add
		 *
		 * \throw Does not throw anything
		 */
		virtual void add(InnerTemplate *tag) 
			throw(InternalProgrammerErrorException &)
		{
			m_list.add(tag);
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;condition");

			if(!m_name.empty())
			{
				returnString += " name=\"" + m_name + "\"";
			}
			
			if(!m_value.empty())
			{
				returnString += " value=\"" + m_value + "\"";
			}
			
			returnString += "&gt;";
			returnString += m_list.getString().c_str();
			returnString += "&lt;/condition&gt";
			return returnString.c_str();			
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			string stringName(name.c_str());
			string stringValue(value.c_str());
			
			if(stringName == "name")
			{
				m_name = stringValue;
			}
			else if(stringName == "value")
			{
				m_value = stringValue;
			}
		}

	private:

		/**
		 * Use this for the internal data structure
		 * hold values for when add is called on this
		 * class
		 */
		InnerTemplateListImpl m_list;

		/**
		 * The attribute name
		 */
		string m_name;

		/**
		 * The attribute value
		 */
		string m_value;
};

/**
 * The Custom Li class that overrides
 * the regular Li AIML XML Tag
 */
class CustomLi : public Li
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomLi() 
			throw()
		{
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomLi");
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			string stringName(name.c_str());
			string stringValue(value.c_str());
			
			if(stringName == "name")
			{
				m_name = stringValue;
			}
			else if(stringName == "value")
			{
				m_value = stringValue;
			}
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;li");

			if(!m_name.empty())
			{
				returnString += " name=\"" + m_name + "\"";
			}
			
			if(!m_value.empty())
			{
				returnString += " value=\"" + m_value + "\"";
			}
			
			returnString += "&gt;";
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/li&gt";
			return returnString.c_str();			
		}

	private:

		/**
		 * Name of the attribute
		 */

		string m_name;
		/**
		 * Value of the attribute
		 */
		string m_value;

};

/**
 * The Custom Date class that overrides
 * the regular Date AIML XML Tag
 */
class CustomDate : public Date
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomDate() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomDate");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;date/&gt;");
			return returnString.c_str();
		}
};

/**
 * The Custom Formal class that overrides
 * the regular Formal AIML XML Tag
 */
class CustomFormal : public Formal
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomFormal() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomFormal");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;formal&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/formal&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom Gossip class that overrides
 * the regular Gossip AIML XML Tag
 */
class CustomGossip : public Gossip
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomGossip() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomGossip");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;gossip&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/gossip&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom Get class that overrides
 * the regular Get AIML XML Tag
 */
class CustomGet : public Get
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomGet() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomGet");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;get name=\"" + m_value + "\"/&gt;");
			return returnString.c_str();
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			m_value = value.c_str();
		}

	private:

		/**
		 * Name of the attribute
		 */
		string m_name;

		/**
		 * Value of the attribute
		 */
		string m_value;
};

/**
 * The Custom Id class that overrides
 * the regular Id AIML XML Tag
 */
class CustomId : public Id
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomId()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomId");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;id/&gt;");
			return returnString.c_str();
		}
};

/**
 * The Custom Input class that overrides
 * the regular Input AIML XML Tag
 */
class CustomInput : public Input
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomInput() 
		{
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomInput");
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			string stringValue(value.c_str());
			m_value = stringValue;
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			if(!m_value.empty())
			{
				string returnString("&lt;input");
				returnString += " index=\"" + m_value + "\"/&gt;";
				return returnString.c_str();			
			}
			else
			{
				string returnString("&lt;input/&gt;");
				return returnString.c_str();
			}

		}

	private:

		/**
		 * Value of the attribute
		 */
		string m_value;
};

/**
 * The Custom LowerCase class that overrides
 * the regular LowerCase AIML XML Tag
 */
class CustomLowerCase : public LowerCase
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomLowerCase() throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomLowerCase");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;lowercase&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/lowercase&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom Person class that overrides
 * the regular Person AIML XML Tag
 */
class CustomPerson : public Person
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomPerson() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomPerson");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;person&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/person&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom Person2 class that overrides
 * the regular Person2 AIML XML Tag
 */
class CustomPerson2 : public Person2
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomPerson2() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomPerson2");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;person2&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/person2&gt";
			return returnString.c_str();			
		}
};


/**
 * The Custom Random class that overrides
 * the regular Random AIML XML Tag
 */
class CustomRandom : public Random
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomRandom() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomRandom");		
		} 
		
		/**
		 * Add the tag to the internal data structure
		 *
		 * @param tag The tag to add
		 *
		 * \throw Does not throw anything
		 */
		virtual void add(InnerTemplate *tag) 
			throw(InternalProgrammerErrorException &)
		{
			m_list.add(tag);
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;random&gt;");
			returnString += m_list.getString().c_str();
			returnString += "&lt;/random&gt";
			return returnString.c_str();			
		}

	private:

		/**
		 * Use this for the internal data structure
		 * hold values for when add is called on this
		 * class
		 */		  
		InnerTemplateListImpl m_list;
};

/**
 * The Custom Sentence class that overrides
 * the regular Sentence AIML XML Tag
 */
class CustomSentence : public Sentence
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomSentence() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomSentence");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;sentence&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/sentence&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom Set class that overrides
 * the regular Set AIML XML Tag
 */
class CustomSet : public Set
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomSet() 
			throw()
		{
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomSet");
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			string stringValue(value.c_str());
			m_value = stringValue;
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;set");
			returnString += " name=\"" + m_value + "\"&gt;";
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/set&gt";
			return returnString.c_str();			
		}

	private:

		/**
		 * The value of the attribute
		 */
		string m_value;
};

/**
 * The Custom Size class that overrides
 * the regular Size AIML XML Tag
 */
class CustomSize : public Size
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomSize() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomSize");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;size/&gt;");
			return returnString.c_str();
		}
};

/**
 * The Custom Srai class that overrides
 * the regular Srai AIML XML Tag
 */
class CustomSrai : public Srai
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomSrai() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomSrai");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;srai&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/srai&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom Star class that overrides
 * the regular Star AIML XML Tag
 */
class CustomStar : public Star
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomStar() 
			throw()
		{
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomStar");
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) throw(InternalProgrammerErrorException &)
		{
			string stringValue(value.c_str());
			m_value = stringValue;
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			if(!m_value.empty())
			{
				string returnString("&lt;star");
				returnString += " index=\"" + m_value + "\"/&gt;";
				return returnString.c_str();			
			}
			else
			{
				string returnString("&lt;star/&gt;");
				return returnString.c_str();
			}

		}

	private:

		/**
		 * The value of the attribute
		 */
		string m_value;
};

/**
 * The Custom System class that overrides
 * the regular System  AIML XML Tag
 */
class CustomSystem : public System
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomSystem() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomSystem");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;system&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/system&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom TemplateSideThat class that overrides
 * the regular TemplateSideThat AIML XML Tag
 */
class CustomTemplateSideThat : public TemplateSideThat
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomTemplateSideThat() 
			throw()
		{
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomTemplateSideThat");
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			string stringValue(value.c_str());
			m_value = stringValue;
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			if(!m_value.empty())
			{
				string returnString("&lt;that");
				returnString += " index=\"" + m_value + "\"/&gt;";
				return returnString.c_str();			
			}
			else
			{
				string returnString("&lt;that/&gt;");
				return returnString.c_str();
			}

		}

	private:

		/**
		 * The value of the attribute
		 */
		string m_value;
};

/**
 * The Custom ThatStar class that overrides
 * the regular ThatStar AIML XML Tag
 */
class CustomThatStar : public ThatStar
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomThatStar() 
			throw()
		{
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomThatStar");
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			string stringValue(value.c_str());
			m_value = stringValue;
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			if(!m_value.empty())
			{
				string returnString("&lt;thatstar");
				returnString += " index=\"" + m_value + "\"/&gt;";
				return returnString.c_str();			
			}
			else
			{
				string returnString("&lt;thatstar/&gt;");
				return returnString.c_str();
			}

		}

	private:

		/**
		 * The value of the attribute
		 */
		string m_value;
};

/**
 * The Custom Think class that overrides
 * the regular Think AIML XML Tag
 */
class CustomThink : public Think
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomThink() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomThink");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;think&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/think&gt";
			return returnString.c_str();			
		}
};

/**
 * The Custom TopicStar class that overrides
 * the regular TopicStar AIML XML Tag
 */
class CustomTopicStar : public TopicStar
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomTopicStar() 
			throw()
		{
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomTopicStar");
		}

		/**
		 * Sets the attribute to a value.
		 *
		 * This is overriden to gain access to the attribute.
		 * 
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * \throw Does not throw anything
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &)
		{
			string stringValue(value.c_str());
			m_value = stringValue;
		}

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			if(!m_value.empty())
			{
				string returnString("&lt;topicstar");
				returnString += " index=\"" + m_value + "\"/&gt;";
				return returnString.c_str();			
			}
			else
			{
				string returnString("&lt;topicstar/&gt;");
				return returnString.c_str();
			}

		}

	private:

		/**
		 * The value of the attribute
		 */
		string m_value;
};

/**
 * The Custom upperCase class that overrides
 * the regular UpperCase AIML XML Tag
 */
class CustomUpperCase : public UpperCase
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf()
		 */
		CustomUpperCase() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomUpperCase");		
		} 

		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;uppercase&gt;");
			returnString += InnerTemplateListImpl::getString().c_str();
			returnString += "&lt;/uppercase&gt";
			return returnString.c_str();			
		}
};

/**
 * The custom version class that overrides
 * the regular Version AIML XML Tag
 */
class CustomVersion : public Version
{
	public:

		/**
		 * Default constructor to 
		 * call Tag::addInstanceOf() and
		 * to set the builder reference
		 *
		 * @param builder A reference 
		 * to the graph builder framework that 
		 * can be used to set and get information 
		 * from the AIML engine.
		 */
		CustomVersion() 
			throw()
		{ 
           /*
			* Add the name of this class.  Otherwise if I 
			* didn't do this I could not call Tag::instanceOf()
			* this an instance of this class and get back a true.
			*/
			addInstanceOf("CustomVersion");		
		} 
		
		/**
		 * Returns the html string name of
		 * the AIML XML name of this class
		 * and any AIML XML tags that are 
		 * inside of this AIML XML Tag
		 *
		 * @return the htm string name of the
		 * AIML XML Tag and any inner tags
		 *
		 * \throw Does not throw anything
		 */
		virtual StringPimpl getString() const
			throw(InternalProgrammerErrorException &)
		{
			string returnString("&lt;version/&gt;");
			return returnString.c_str();
		}
};

} //end of impl namespace 
} //end of customTag namespace 

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif
