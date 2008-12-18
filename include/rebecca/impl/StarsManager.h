#ifndef REBECCA_IMPL_STARSMANAGER_H
#define REBECCA_IMPL_STARSMANAGER_H

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
#include <rebecca/StringPimpl.h>

//std includes
#include <map>
#include <vector>

namespace rebecca
{
namespace impl
{

using namespace std;

//Forward declerations
class StarsManagerImpl;

class StarsManager
{
	public:
		void addStar(const StringPimpl &star);

		StringPimpl getStar(unsigned const int &index) const;
		StringPimpl getThatStar(unsigned const int &index) const;
		StringPimpl getTopicStar(unsigned const int &index) const;
		StringPimpl getDefaultStar(unsigned const int &index) const;
		void setUseThatStar();
        void setUseTopicStar();
		void setUseDefaultStar();
		static StarsManager *getInstance();
		virtual ~StarsManager();
		void clearStars();

		map<StringPimpl, vector<StringPimpl> > getDefaultStarMap();
		map<StringPimpl, vector<StringPimpl> > getTopicStarMap();
		map<StringPimpl, vector<StringPimpl> > getThatStarMap();
		void setDefaultStarMap(const map<StringPimpl, vector<StringPimpl> > &starMap);
		void setThatStarMap(const map<StringPimpl, vector<StringPimpl> > &starMap);
		void setTopicStarMap(const map<StringPimpl, vector<StringPimpl> > &starMap);
		static StarsManager *reset();
	private:
		StarsManagerImpl *m_pimpl;
		friend class StarsManagerImpl;
		StarsManager();
};

} // end of impl namespace
} // end of rebecca namespace

#endif

