#ifndef REBECCA_IMPL_PREVIOUSRESPONSESMANAGER_H
#define REBECCA_IMPL_PREVIOUSRESPONSESMANAGER_H

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

#include <rebecca/StringPimpl.h>
#include <deque>

namespace rebecca
{
namespace impl
{
using namespace std;

//Forward declerations
class PreviousResponsesManagerImpl;

class PreviousResponsesManager
{
	public:
		PreviousResponsesManager();
		StringPimpl getPreviousBotResponse(const unsigned int &previousBotResponse, 
			                               const unsigned int &sentence) const;

		StringPimpl getPreviousUserInput(const unsigned int &previousUserInput, 
			                             const unsigned int &sentence) const;
		StringPimpl getPreviousBotResponseWithPunctuation(const unsigned int &previousBotResponse, 
			                               const unsigned int &sentence) const;

		StringPimpl getPreviousUserInputWithPunctuation(const unsigned int &previousUserInput, 
			                             const unsigned int &sentence) const;
		void addBotResponse(const deque<StringPimpl> &sentences);
		void addUserResponse(const deque<StringPimpl> &sentences);
		void addBotResponseWithPunctuation(const deque<StringPimpl> &sentences);
		void addUserResponseWithPunctuation(const deque<StringPimpl> &sentences);
		static PreviousResponsesManager *reset();	
		static PreviousResponsesManager *getInstance();
		~PreviousResponsesManager();

	private:
		PreviousResponsesManagerImpl *m_pimpl;
};


} // end of impl namespace
} // end of rebecca namespace


#endif
