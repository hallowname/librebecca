#ifndef REBECCA_FRAMEWORK_CUSTOMTAGS_H
#define REBECCA_FRAMEWORK_CUSTOMTAGS_H

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
#include <rebecca/framework/Tag.h>
#include <rebecca/framework/GraphBuilderFramework.h>

namespace rebecca
{
namespace framework
{
namespace impl
{

/**
 * The class to inherit from
 * when implementing a custom Tag
 * dll or shared object.
 *
 * Inherit from this class within 
 * your dll or shared object and flush
 * out createTagClass to return your 
 * custom Tags.  Register your dll or 
 * shared object 
 * GraphBuilder::addCustomTagLibrary()
 *
 * The .dll or .so that has the custom AIML tags must 
 * conform to the proper format.  The proper format is 
 * that the .dll/.so should have a class that inherits 
 * from this class.  Also the two global C functions of 
 * CustomTags *rebeccaAIMLLoadCustomTags() and 
 * rebeccaAIMLRemoveCustomTags(CustomTagsImpl *customTags) 
 * must be present in your dll or shared object. 
 * rebeccaAIMLLoadCustomTags returns a new instance
 * of the class that inherits from this class and 
 * rebeccaAIMLRemoveCustomTags takes a CustomTags argument 
 * and deletes the object.  If both of these C functions 
 * cannot be found, the dll or shared object will not be 
 * loaded.
 */
class REBECCA_EXPORT CustomTags 
{
	public:
		
		/**
		 * Contract in which you will return a shared_ptr<Tag> 
		 * of your custom Tag class when given the string of the
		 * Tag name.
		 *
		 * You will recieve the className of every Tag encountered 
		 * during the parsing of AIML.  For example, when the Tag
		 * <think> is encountered "think" in all lowercase will be
		 * sent to this method.  Along with the name of the Tag a 
		 * GraphBuilderFramework reference will be sent.  This 
		 * reference is the AIML engine associated with your Tag 
		 * you will return.  The reference is sent because a lot 
		 * of AIML tags rely on it to set and retrieve
		 * information from the AIML engine during runtime.
		 *
		 * If you do not wish to override the tag who's name is 
		 * sent to this method you must return an empty shared_ptr.  
		 * When the AIML engine sees that an empty shared_ptr is 
		 * returned it will use its default AIML Tag.
		 *
		 * @param className The AIML Tag string name you should 
		 * return an instance of your custom AIML Tag to.
		 *
		 * @return Either your custom aiml Tag instance or an empty
		 * shared_ptr if you do not wish to override that particular
		 * AIML Tag.
		 * 
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual Tag *createTagClass(const StringPimpl &className) 
			throw(InternalProgrammerErrorException &) = 0;	

		/**
		 * Default virtual destructor
		 */
		virtual ~CustomTags() { }
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::CustomTags;

} //end of namespace framework
} //end of namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

