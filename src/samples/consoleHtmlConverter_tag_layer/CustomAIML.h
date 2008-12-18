#ifndef CUSTOMHTML_TAG_LAYER_CUSTOMAIML_H
#define CUSTOMHTML_TAG_LAYER_CUSTOMAIML_H

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


//Custom Tag includes
#include "exports.h"
#include "CustomTopic.h"

//Rebecca includes
#include <rebecca/framework/AIML.h>
#include <rebecca/framework/GraphBuilderFramework.h>

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

/*
 * Forward declerations
 */
class Html;

using namespace rebecca::framework;
using namespace rebecca;

/**
 * The custom AIML class that 
 * represents the AIML XML 
 * tag "aiml".  
 *
 * Every time a XML Tag of AIML is 
 * encountered, an instance of 
 * this class will be created.  All text
 * inbetween the begin and end tag, all
 * attributes, and all inner Tags will
 * go through methods of this class.
 *
 * I inherit from AIML and override part of
 * its functionality.  In particular I override
 * AIML to set *my* CustomTopic as the default
 * that it will use.
 */
class CUSTOM_TAG_EXPORT CustomAiml : public AIML
{
	public:

		/**
		 * Set the CustomTopic with the Html 
		 * object reference.
		 *
		 * @param builder The builder to send to
		 * the CustomTopic
		 * 
		 * @param htmlPage The html page to set 
		 * the CustomTopic with.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		CustomAiml(Html &htmlPage)
			throw(InternalProgrammerErrorException &);
		
		/**
		 * Calls the internal default CustomTopic Object's CustomTopic::handleInnerTag() 
		 * with this AIML XML tag.
		 *
		 * Whenever the AIML Tag encounters an inner AIML XML Tag it's always either a Category
		 * Tag or a Topic Tag.  If it is a Category Tag it sends the Tag to its internal default 
		 * Topic Tag object by calling its internal Topic Tag's handleInnerTag.  If it is a 
		 * Topic Tag it safetly ignores it.  The default Topic Tag is a Topic Tag with its topic 
		 * set to "*".  When a Topic is not specified in AIML XML, it is to default to "*".  When a 
		 * Topic is not specified, this handleInnerTag gets called with a Category Tag object which 
		 * in turn calls the internal default Topic Tag with the Category Tag object.  When a Topic 
		 * is specified AIML's handleInnerTag gets called with a Topic Object and safetly ignores 
		 * it since it does not need to do anything with it.
		 *
		 * @param tag A Category Tag or Topic Tag
		 * 
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual void handleInnerTag(Tag *tag) 
			throw(InternalProgrammerErrorException &);

	private:

		/**
		 * My custom topic in which my 
		 * custom AIML will use instead of the
		 * standard AIML using the regular Topic
		 * class
		 */
		CustomTopic m_defaultStarTopic;
};

} //end of namespace impl
} //end namespace customTag

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

