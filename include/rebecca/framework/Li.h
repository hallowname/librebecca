#ifndef REBECCA_FRAMEWORK_LI_H
#define REBECCA_FRAMEWORK_LI_H

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

//Rebecca includes
#include <rebecca/framework/InnerTemplateListImpl.h>

namespace rebecca
{
namespace framework
{
namespace impl
{

/*
 * Forward declerations
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
class LiImpl;

/**
 * AIML class that represents the 
 * AIML XML tag "li".  
 *
 * Every time a XML Tag of AIML is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 */
class REBECCA_EXPORT Li: public InnerTemplateListImpl
{
	public:

		/** 
		 * Default constructor to initalize 
		 * the private implementation (m_pimpl)
		 * data.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		Li() 
			throw(InternalProgrammerErrorException &);

		/**
		 * Sets its attribute of "name" and "value"
         *
		 * @param name The name of the AIML XML attribute
		 *
		 * @param value The value of the AIML XML attribute
         *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void setAttribute(const StringPimpl &name, const StringPimpl &value) 
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Returns the string set from the "name" attribute
		 * sent to Li::setAttribute()
		 *
		 * @return Returns the string set 
		 * from the "name" attribute.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual StringPimpl getPredicateName() const
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns the string set from the "value" attribute
		 * sent to Li::setAttribute()
		 *
		 * @return Returns the string set 
		 * from the "value" attribute.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual StringPimpl getAimlPattern() const
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Returns true if this is a default list item or not.
		 * 
		 * An li element of the type defaultListItem has no attributes. 
		 * It may contain any AIML template elements.  In other
		 * words if the li does not have a "value" attribute or 
		 * a "name" attribute it is a default list item.  
		 *
		 * @return Returns boolean true if this is a default
		 * list item otherwise it will return false.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual bool isDefaultListItem() const
			throw(InternalProgrammerErrorException &);

		/**
		 * Returns true if this is a value only list item.
		 * 
         * An li element of the type valueOnlyListItem has a 
		 * required attribute value, which must contain a simple 
		 * pattern expression. The element may contain any AIML 
		 * template elements.
		 * 
		 * @return Returns boolean true if this is a value
		 * only list item otherwise it will return false.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual bool isValueOnlyListItem() const
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Returns true if this is a name and value list 
		 * item.
		 * 
         * An li element of the type nameValueListItem has a 
		 * required attribute name, which specifies an AIML 
		 * predicate, and a required attribute value, which 
		 * contains a simple pattern expression. The element may 
		 * contain any AIML template elements.  
		 * 
		 * @return Returns boolean true if this is a name and
		 * value list item otherwise it will return false.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual bool isNameAndValueListItem() const
			throw(InternalProgrammerErrorException &);

		/** 
		 * Default virtual destructor.  Destroys the private implementation
		 * (m_pimpl) data.
		 */
		virtual ~Li();

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
		LiImpl *m_pimpl;
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::Li;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif
