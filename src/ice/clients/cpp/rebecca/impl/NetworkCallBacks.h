#ifndef REBECCA_NETWORKCALLBACKS_H
#define REBECCA_NETWORKCALLBACKS_H

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

//Ice includes
#include <rebecca/impl/network.h>

#include <iostream>
using namespace std;

namespace rebecca
{
namespace impl
{
class NetworkCallBacks : public CallBacksIce
{
	public:
		NetworkCallBacks()
			: m_callBacks(0)
		{ }

		void setCallBacks(CallBacks *callBacks)
		{
			m_callBacks = callBacks;
		}

		virtual void storeGossip(const ::std::string& gossip, 
                                 const ::std::string& userId, 
								 const ::std::string& botId, 
								 const ::std::string& endUserId,
			                     const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->storeGossip(gossip.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void categoryLoaded(const ::std::string& userId, 
								    const ::std::string& botId, 
								    const ::std::string& endUserId,
			                        const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->categoryLoaded(userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void filePreLoad(const ::std::string& fileName, 
                                 const ::std::string& userId, 
								 const ::std::string& botId, 
								 const ::std::string& endUserId,
			                     const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->filePreLoad(fileName.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void filePostLoad(const ::std::string& fileName, 
                                  const ::std::string& userId, 
								  const ::std::string& botId, 
								  const ::std::string& endUserId,
			                      const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->filePostLoad(fileName.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void symbolicReduction(const ::std::string& symbol, 
                                       const ::std::string& userId, 
								       const ::std::string& botId, 
								       const ::std::string& endUserId,
			                           const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->symbolicReduction(symbol.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void infiniteSymbolicReduction(const ::std::string& userId, 
								               const ::std::string& botId, 
								               const ::std::string& endUserId,
			                                   const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->infiniteSymbolicReduction(userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void XMLParseError(const ::std::string& message, 
                                   const ::std::string& userId, 
								   const ::std::string& botId, 
								   const ::std::string& endUserId,
			                       const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->XMLParseError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void XMLParseWarning(const ::std::string& message, 
                                     const ::std::string& userId, 
								     const ::std::string& botId, 
								     const ::std::string& endUserId,
			                         const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->XMLParseWarning(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void XMLParseFatalError(const ::std::string& message, 
                                        const ::std::string& userId, 
								        const ::std::string& botId, 
								        const ::std::string& endUserId,
			                            const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->XMLParseFatalError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void thatStarTagSizeExceeded(const ::std::string& userId, 
								             const ::std::string& botId, 
								             const ::std::string& endUserId,
			                                 const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->thatStarTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void topicStarTagSizeExceeded(const ::std::string& userId, 
								              const ::std::string& botId, 
								              const ::std::string& endUserId,
			                                  const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->topicStarTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void starTagSizeExceeded(const ::std::string& userId, 
								         const ::std::string& botId, 
								         const ::std::string& endUserId,
			                             const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->starTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void inputTagNumericConversionError(const ::std::string& message, 
                                                    const ::std::string& userId, 
								                    const ::std::string& botId, 
								                    const ::std::string& endUserId,
			                                        const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->inputTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void inputTagSizeExceeded(const ::std::string& userId, 
								          const ::std::string& botId, 
								          const ::std::string& endUserId,
			                              const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->inputTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void starTagNumericConversionError(const ::std::string& message, 
                                                   const ::std::string& userId, 
								                   const ::std::string& botId, 
								                   const ::std::string& endUserId,
			                                       const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->starTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void thatTagSizeExceeded(const ::std::string& userId, 
								         const ::std::string& botId, 
								         const ::std::string& endUserId,
			                             const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->thatTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void thatTagNumericConversionError(const ::std::string& message, 
                                                   const ::std::string& userId, 
								                   const ::std::string& botId, 
								                   const ::std::string& endUserId,
			                                       const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->thatTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void topicStarTagNumericConversionError(const ::std::string& message, 
                                                        const ::std::string& userId, 
								                        const ::std::string& botId, 
								                        const ::std::string& endUserId,
			                                            const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->topicStarTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

	    virtual void thatStarTagNumericConversionError(const ::std::string& message, 
                                                       const ::std::string& userId, 
								                       const ::std::string& botId, 
								                       const ::std::string& endUserId,
			                                           const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->thatStarTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}

		virtual void learnTagFileNotFound(const ::std::string& message, 
                                          const ::std::string& userId, 
								          const ::std::string& botId, 
								          const ::std::string& endUserId,
			                              const ::Ice::Current& = ::Ice::Current())
		{
			if(m_callBacks)
				m_callBacks->learnTagFileNotFound(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
		}


	private:
		CallBacks *m_callBacks;

};
} //impl namespace
} //rebecca namespace


#endif
