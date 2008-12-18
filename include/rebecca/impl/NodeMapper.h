#ifndef REBECCA_IMPL_NODEMAPPER_H
#define REBECCA_IMPL_NODEMAPPER_H

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

//Boost includes
#include <boost/algorithm/string.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

//Rebecca includes
#include <rebecca/framework/Template.h>

//std includes
#include <queue>
#include <map>

namespace rebecca
{
namespace framework
{
namespace impl
{
/*
 * Forward declerations
 */
class IdentificationManager;
} //end of impl
} //end of framework

namespace impl
{

/*
 * Forward declerations
 */
class DatabaseManager;
class StarsManager;
class GraphBuilderAIML;
class XercesSAXXMLManager;
using namespace std;
using namespace boost;
using namespace rebecca::framework::impl;
	
class NodeMapper : public enable_shared_from_this<NodeMapper>
{	
	/** 
	 * Keeps track of all the operations you can 
	 * provide to the NodeMapper's links to other
	 * NodeMappers.
	 */
	class Links
	{

		public:
			Links()
			{ }

			/**
			 * It checks if the link already exists 
			 * and adds it if it does, otherwise does 
			 * not add anything since that node is 
			 * already there.
			 */
			inline shared_ptr<NodeMapper> &add(StringPimpl &word);
			inline shared_ptr<NodeMapper> getUnderScoreNode();
			inline shared_ptr<NodeMapper> getWordNode(const StringPimpl &word, bool caseSensitive = false);
			inline shared_ptr<NodeMapper> getStarNode();
	    private:

			/** 
			 * This is the underlying data structure
			 * we are wrapping.
			 * 
			 * We map between the string of either a 
			 * word, a asterisk "*", or an underscore "_"
			 * and then return the node link.
			 */
			map<StringPimpl, shared_ptr<NodeMapper> > m_nodeLink;
	};

	public:

		/**
		 * Recursively addes the node to the node mapper.
         * Creates the other nodes along the way if they do 
		 * not already exist along the way.
		 */
		void add(const Template *templateToAdd, queue<StringPimpl> &wordStack);


		void remove(queue<StringPimpl> &wordStack);

		void add(const StringPimpl &key, 
					         const Template *templateToAdd,
					         queue<StringPimpl> &wordStack);

		shared_ptr<NodeMapper> getNode(queue<StringPimpl> wordStack);

		bool getNodeUsingDB(const StringPimpl &key,
								        StringPimpl &returnString,
	                                    queue<StringPimpl> wordStack);

		NodeMapper();
		~NodeMapper();

		StringPimpl getTemplateString();

		StringPimpl getTemplateString(const StringPimpl &path, 
										          bool predicateGet = false);
		StringPimpl getTemplateStringPredicate();

	private:

		/**
		 * Returns true if there's a template
		 * pointer otherwise false.  In essence, 
		 * it just checks if the pointer is zero
		 * or not.
		 *
		 * @return Returns true if this node has 
		 * a template otherwise returns false.
		 */
		inline bool hasTemplate() const
		{
			return !(m_template == 0);
		}


		/**
		 *  The links of the NodeMapper to the other
		 *  nodes.
		 */
		Links m_links;

		/**
		 * The template composite.
		 */
		const Template *m_template;

		DatabaseManager *m_databaseManager;
		StarsManager *m_starsManager;
		IdentificationManager *m_identificationManager;
		XercesSAXXMLManager *m_xmlManager;
};

} //end of namespace impl
} //end of namespace rebecca



#endif

