#ifndef SERVER_SERVERCALLBACKS_H
#define SERVER_SERVERCALLBACKS_H

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

#include <set>
#include <boost/thread/mutex.hpp>
#include <rebecca/GraphBuilder.h>


namespace rebecca 
{
namespace impl
{

using namespace std;
using namespace boost;

class MyCallBacks : public CallBacks
{
	private:
		const GraphBuilder &m_builder;
	public:

		MyCallBacks(Ice::LoggerPtr logger, const GraphBuilder &builder)
			: m_logger(logger), 
			  m_shouldLog(false),
			  m_builder(builder)
		{ }

		void setShouldLog(bool shouldOrShouldnt)
		{
			m_shouldLog = shouldOrShouldnt;
		}
		void setLocalCallBack(const CallBacksIcePrx& remoteCallBack)
		{ 
            mutex::scoped_lock synchronize(m_this);
			m_remoteCallBacks.insert(remoteCallBack);
		}

		void storeGossip(const StringPimpl &gossip, 
                         const StringPimpl &userId,
						 const StringPimpl &botId,
						 const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Gossip: " << gossip.c_str() << " ]" 
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->print(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->storeGossip(gossip.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in storeGossip:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in storeGossip callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		void categoryLoaded(const StringPimpl &userId,
						    const StringPimpl &botId,
						    const StringPimpl &endUserId) 
		{

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->categoryLoaded(userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in categoryLoaded:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in categoryLoaded callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		void filePreLoad(const StringPimpl &fileName, 
                         const StringPimpl &userId,
						 const StringPimpl &botId,
						 const StringPimpl &endUserId) 
		{
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Loading      " << fileName.c_str() << "]" 
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->print(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->filePreLoad(fileName.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in filePreLoad:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in filePreLoad callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}
		
		void filePostLoad(const StringPimpl &fileName,
                          const StringPimpl &userId,
						  const StringPimpl &botId,
						  const StringPimpl &endUserId) 
		{
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Done loading " << fileName.c_str() << "]"
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->print(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->filePostLoad(fileName.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in filePostLoad:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in filePostLoad callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		void symbolicReduction(const StringPimpl &symbol,
                               const StringPimpl &userId,
						       const StringPimpl &botId,
						       const StringPimpl &endUserId) 
		{
			if(m_shouldLog)
			{
				ostringstream s;
				s << "Symbolic reduction: " << symbol.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->print(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->symbolicReduction(symbol.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in symbolicReduction:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in symbolicReduction callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		void infiniteSymbolicReduction(const StringPimpl &userId,
						               const StringPimpl &botId,
						               const StringPimpl &endUserId) 
		{
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Infinite Symbolic reduction detected]"
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->print(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->infiniteSymbolicReduction(userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in infiniteSymbolicReduction:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in infiniteSymbolicReduction callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}
		
		virtual void XMLParseError(const StringPimpl &message,
                                   const StringPimpl &userId,
						           const StringPimpl &botId,
						           const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->error(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->XMLParseError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in XMLParseError:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in XMLParseError callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		} 

		virtual void XMLParseWarning(const StringPimpl &message,
                                     const StringPimpl &userId,
						             const StringPimpl &botId,
						             const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->warning(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->XMLParseWarning(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in XMLParseWarning:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in XMLParseWarning callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		} 

		virtual void XMLParseFatalError(const StringPimpl &message,
                                        const StringPimpl &userId,
						                const StringPimpl &botId,
						                const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "Fatal:" << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->error(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->XMLParseFatalError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in XMLParseFatalError:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in XMLParseFatalError callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		} 
		
		virtual void thatStarTagSizeExceeded(const StringPimpl &userId,
						                     const StringPimpl &botId,
						                     const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Warning thatStar Tag Size Exceeded]"
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->print(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->thatStarTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in thatStarTagSizeExceeded:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in thatStarTagSizeExceeded callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}
		
		virtual void topicStarTagSizeExceeded(const StringPimpl &userId,
						                      const StringPimpl &botId,
						                      const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Warning topicStar Tag Size Exceeded]"
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->warning(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->topicStarTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in topicStarTagSizeExceeded:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in topicStarTagSizeExceeded callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		virtual void starTagSizeExceeded(const StringPimpl &userId,
						                 const StringPimpl &botId,
						                 const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Warning star Tag Size Exceeded]"
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->warning(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->starTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in starTagSizeExceeded:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in starTagSizeExceeded callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		virtual void inputTagNumericConversionError(const StringPimpl &message,
                                                    const StringPimpl &userId,
						                            const StringPimpl &botId,
						                            const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "inputTagNuermicConversionError:" << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->error(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->inputTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in inputTagNumericConversionError:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in inputTagNumericConversionError callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		virtual void inputTagSizeExceeded(const StringPimpl &userId,
						                  const StringPimpl &botId,
						                  const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "[Warning input Tag Size Exceeded]"
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->warning(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->inputTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in inputTagSizeExceeded:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in inputTagSizeExceeded callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		} 

		virtual void starTagNumericConversionError(const StringPimpl &message,
                                                   const StringPimpl &userId,
						                           const StringPimpl &botId,
						                           const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "starTagNuermicConversionError:" << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->error(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->starTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in starTagNumericConversionError:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in starTagNumericConversionError callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		} 

		virtual void thatTagSizeExceeded(const StringPimpl &userId,
						                 const StringPimpl &botId,
						                 const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "thatTagSizeExceeded"
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->warning(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->thatTagSizeExceeded(userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in thatTagSizeExceeded:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in thatTagSizeExceeded callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

		virtual void thatTagNumericConversionError(const StringPimpl &message,
                                                   const StringPimpl &userId,
						                           const StringPimpl &botId,
						                           const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "thatTagNumericConversionError:" << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->error(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->thatTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in thatTagNumericConversionError:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in thatTagNumericConversionError callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		} 

		virtual void topicStarTagNumericConversionError(const StringPimpl &message,
                                                        const StringPimpl &userId,
						                                const StringPimpl &botId,
						                                const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "topicStarTagNumericConversionError:" << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->error(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->topicStarTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in topicStarTagNumericConversionError:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in topicStarTagNumericConversionError callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}
		
		virtual void thatStarTagNumericConversionError(const StringPimpl &message,
                                                       const StringPimpl &userId,
						                               const StringPimpl &botId,
						                               const StringPimpl &endUserId) 
		{ 
			if(m_shouldLog)
			{
				ostringstream s;
				s << "thatStarTagNumericConversionError" << message.c_str()
				  << endl
				  << "    [(userId, botId, endUserId) -- (" 
				  << userId.c_str() 
				  << "," 
				  << botId.c_str() 
				  << "," 
				  << endUserId.c_str() 
				  << ")]";

				m_logger->error(s.str());
			}

			/*
			 * Call the remote callbacks
			 * if they are available
			 */
			if(m_remoteCallBacks.size() > 0)
			{
				typedef set<CallBacksIcePrx>::const_iterator CI;
				for(CI it = m_remoteCallBacks.begin(); it != m_remoteCallBacks.end(); ++it)
				{
					if(*it)
					{
						try
						{
							(*it)->thatStarTagNumericConversionError(message.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
						}
						catch(Ice::CloseConnectionException &exception)
						{
							/*
							 * This happens when the connection 
							 * is broken and happens every time a 
							 * program disconnects which is using 
							 * the callback system.  So we have to 
							 * add it to the list of connections to
							 * remove.
							 */
							if(m_shouldLog)
							{
								string warning("CloseConnectionException detected in thatStarTagNumericConversionError:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
						catch(Ice::Exception &exception)
						{
							/*
							 * This error can happen on a connection 
							 * interruption or something else
							 */
							if(m_shouldLog)
							{
								string warning("An Error occured in thatStarTagNumericConversionError callback:\n");
								ostringstream s;
								s << exception;
								m_logger->warning(warning + s.str());
							}
							m_connectionsToRemove.push_back(*it);
						}
					}
				}
				//Remove the dead connections we found
				removeDeadConnections();
			}
		}

	private:
		
		/**
		 * Removes any dead connections
		 * we might have from clients 
		 * disconnecting normally
		 */
		void removeDeadConnections()
		{
			if(m_connectionsToRemove.size() != 0)
			{
				typedef set<CallBacksIcePrx>::iterator I;
				for(unsigned i = 0; i < m_connectionsToRemove.size(); ++i)
				{
					I it = m_remoteCallBacks.find(m_connectionsToRemove.at(i));
					if(it != m_remoteCallBacks.end())
					{
						m_remoteCallBacks.erase(it);
					}
				}
				//All the dead connections are cleaned, so let's empty our datastructure
			    m_connectionsToRemove.clear();
			}
		}
		

		Ice::LoggerPtr m_logger;
		set<CallBacksIcePrx> m_remoteCallBacks;
		CallBacksIcePrx m_remoteCallBack;
		vector<CallBacksIcePrx> m_connectionsToRemove;
		mutex m_this;
		bool m_shouldLog;
};

} //end of impl namespace
} //end or rebecca namespace

#endif



