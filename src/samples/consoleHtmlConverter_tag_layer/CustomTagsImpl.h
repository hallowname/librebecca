#ifndef CUSTOMHTML_TAG_LAYER_CUSTOMTAGSIMPL_H
#define CUSTOMHTML_TAG_LAYER_CUSTOMTAGSIMPL_H

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
 * needing dll-interface 
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4251 )
#    pragma warning( disable : 4290 )
#endif

//Rebecca includes
#include <rebecca/framework/CustomTags.h>

//CustomTag includes
#include "exports.h"
#include "typedefs.h"
#include "Html.h"

//Std lncludes
#include <map>

/**
 * Our customTag namespace 
 * to avoid namespace pollution
 * Any classes that need to be
 * publicly exposed will be 
 * exposed only through this
 * namespace
 */
namespace customTag
{

/**
 * The impl namespace 
 * can be polluted as 
 * much as we want.  If
 * the classes from this
 * namespace need to be 
 * public they'll be exported
 * to the customTag namespace
 */
namespace impl
{

///@todo Put in the impl namespace and document it

using namespace rebecca::framework;
using namespace std;

/**
 * Implementation of the CustomTags class that
 * produces a Tag object for each AIML XML 
 * string
 *
 * You will recieve the className of every Tag encountered 
 * during the parsing of AIML.  For example, when the Tag
 * <think> is encountered "think" in all lowercase will be
 * sent to this method.  Along with the name of the Tag a 
 * GraphBuilderFramework reference will be sent.  This 
 * reference is the AIML engine associated with the Tag 
 * I will return.  The reference is sent because a lot 
 * of AIML tags rely on it to set and retrieve
 * information from the AIML engine during runtime.
 *
 * All the AIML XML tags I wish to override I do through
 * this class.  When I encounter an AIML XML Tag I do not 
 * want to override I return an empty shared_ptr<>.
 */
class CUSTOM_TAG_EXPORT CustomTagsImpl : public CustomTags
{
	public:

		/**
		 * I use this to set m_templateSideThat to false
		 * to start with.
		 *
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		CustomTagsImpl() 
			throw(InternalProgrammerErrorException &);

		/**
		 * Method in which I return a shared_ptr<Tag> for
		 * each of the AIML XML tags I want to override.
		 *
		 * I recieve the className of every Tag encountered 
		 * during the parsing of AIML.  For example, when the Tag
		 * <think> is encountered "think" in all lowercase will be
		 * sent to this method.  Along with the name of the Tag a 
		 * GraphBuilderFramework reference will be sent.  This 
		 * reference is the AIML engine associated with my Tag 
		 * you will return.  The reference is sent because a lot 
		 * of AIML tags rely on it to set and retrieve
		 * information from the AIML engine during runtime.
		 *
		 * For the tags I do not wish to override I return an 
		 * empty shared_ptr.
		 * When the AIML engine sees that an empty shared_ptr is 
		 * returned it will use its default AIML Tag.
		 *
		 * @param className The AIML Tag string name I return an 
		 * instance of my custom AIML Tag to.
		 *
		 * @param builder The AIML engine associated with my Custom
		 * Tag I return.
		 *
		 * @return Either my custom aiml Tag instance or an empty
		 * shared_ptr if I do not wish to override that particular
		 * AIML Tag.
		 * 
		 * @exception InternalProgrammerErrorException is thrown 
		 * only if the error is so grave that the entire AIML 
		 * engine has to be shut down.
		 */
		virtual Tag *createTagClass(const StringPimpl &className) 
			throw(InternalProgrammerErrorException &);

		/**
		 * I call m_htmlPage write web pages to finally write out
		 * all the web pages.
		 *
		 * Once this class is destroyed the program is getting ready
		 * to exit.  Which means I should finally write out all the 
		 * web pages.
		 */
		virtual ~CustomTagsImpl();

	private:

		/**
		 * My internal html page object which I use 
		 * to write out all the pages with.
		 */
		Html m_htmlPage;

		/** 
		 * We use this to figure out if we are 
		 * within a template and should use
		 * a templateSideThat when we see the 
		 * string "template".  Otherwise we will let
		 * rebecca use her default pattern side that
		 */
		bool m_templateSideThat;

};

} //end of namespace impl
} //end namespace customTag


/**
 * This is how the Rebecca engine loads CustomTagsImpl.
 * Rebecca calls LoadLibrary/ldopen on the dll and looks
 * for this global symbol.  If it cannot find the symbol it 
 * will not load the customTag succesfully.  THIS IS REQUIRED
 */
extern "C" CUSTOM_TAG_EXPORT customTag::impl::CustomTags *rebeccaAIMLLoadCustomTags()
{
	return new customTag::impl::CustomTagsImpl;
}


/**
 * This is how the Rebecca engine unloads CustomTagsImpl.
 * Rebecca calls LoadLibrary/ldopen on the dll and looks
 * for this global symbol.  If it cannot find the symbol it 
 * will not load the customTag succesfully. THIS IS REQUIRED
 */
extern "C" CUSTOM_TAG_EXPORT void rebeccaAIMLRemoveCustomTags(customTag::impl::CustomTagsImpl *customTags)
{
	delete customTags;
}

#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif
