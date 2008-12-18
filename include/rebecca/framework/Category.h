#ifndef REBECCA_FRAMEWORK_CATEGORY_H
#define REBECCA_FRAMEWORK_CATEGORY_H

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

/* Disable Windows VC 7.x warning about 
 * shared_ptr needing dll-interface and
 * about it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4251 )
#    pragma warning( disable : 4290 )
#endif

#include <rebecca/framework/InnerTopic.h>

namespace rebecca
{
namespace framework
{
namespace impl
{

/* 
 * Forward decleration
 */

/**
 * The private implementation in which
 * you cannot get access to.
 *
 * This class holds the private methods
 * and private attributes of this class.  This 
 * makes ABI (Application Binary Interface) more
 * resilient to change. See the private implementation
 * idiom on the internet for more information about this.
 */
class CategoryImpl;
class PatternSideThat;
class Template;
class Pattern;
class GraphBuilderFramework;

/**
 * AIML class that represents the 
 * AIML XML tag "category".  
 *
 * Every time a XML Tag of AIML is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 */
class REBECCA_EXPORT Category : public InnerTopic
{
	public:

		/** 
		 * Initalizes the private 
		 * implementation (m_pimpl) data and 
		 * sets the private implementation 
		 * with a reference to the 
		 * GraphBuilderFramework.  
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		Category() 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * If the Tag is a PatternSideThat, Template, or Pattern it adds the reference
		 * to its self, otherwise it throws a rebecca::impl::InternalProgrammerErrorException.
		 *
		 * The tag is checked with Tag::instanceOf() to determine if it is an 
		 * instance of one of the above mentioned classes.  If it is not, an 
		 * rebecca::impl::InternalProgrammerErrorException will be thrown.  
		 * Otherwise the tag will be downcast using a static_cast<> to the 
		 * appropriate subclass Tag and the reference added to this class. 
		 * 
		 * @param tag PatternSideThat, Template, or Pattern Tag
		 * 
         * @exception InternalProgrammerErrorException is thrown 
		 * if Tag is not PatternSideThat, Template, or Pattern.
		 */
		virtual void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the internal Template reference's string through 
		 * Template::getString()
		 *
		 * This class holds a reference to a Template object it recieved through
		 * Category::handleInnerTag().  When this method is called, it will in turn
		 * call its reference's getString (Template::getString())
		 *
		 * @return Returns the string of the internal Template object's 
		 * Template::getString()
		 *
         * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual const StringPimpl getTemplateString() 
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the internal Pattern reference's string reference through 
		 * Pattern::getStringConstRef()
		 *
		 * This class holds a reference to a Pattern object it recieved through
		 * Category::handleInnerTag().  When this method is called, it will in turn
		 * call its reference's getStringConstRef (Pattern::getStringConstRef()).
		 * This calls the getStringConstRef for efficiency reasons to get a reference
		 * instead of making a copy.
		 *
		 * @return Returns the string of the internal Pattern object's 
		 * Pattern::getStringConstRef()
		 *
         * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual const StringPimpl &getPatternString() 
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the internal That reference's string reference through 
		 * That::getStringConstRef()
		 *
		 * This class holds a reference to a That object it recieved through
		 * Category::handleInnerTag().  When this method is called, it will in turn
		 * call its reference's getStringConstRef (That::getStringConstRef()).
		 * This calls the getStringConstRef for efficiency reasons to get a reference
		 * instead of making a copy.
		 *
		 * @return Returns the string of the internal That object's 
		 * That::getStringConstRef()
		 *
         * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual const StringPimpl &getThatString() 
			throw(InternalProgrammerErrorException &);		
		
		/**
		 * Returns a reference to the internal Template.
		 *
		 * This is used to grab a reference to the internal Template and 
		 * call it's Template::getString() method.  However, Category 
		 * retains ownership over the object.
		 *
		 * @return a reference to the internal Template reference
		 *
         * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual const Template *getTemplate() 
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~Category();

	private:

	   /**
		* The private implementation in which
		* you cannot get access to.
		*
		* This pointer holds the private methods  
		* and private member variables of this class.  This 
		* makes ABI (Application Binary Interface) more
		* resilient to change. See the private implementation
		* idiom on the internet for more information about this.
		*/
		CategoryImpl *m_pimpl;
};


} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::Category;

} //end of namespace framework
} //end of namespace rebecca


#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

