#ifndef SERVER_SERVERSERVICE_H
#define SERVER_SERVERSERVICE_H

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

//#include <boost/filesystem/operations.hpp>

#include <rebecca/impl/NetworkGraphBuilderI.h>
using namespace rebecca;
using namespace rebecca::impl;

namespace rebecca
{
namespace impl
{

//using namespace boost::filesystem;

class ServerService : public Ice::Service 
{

	protected:
		virtual bool start(int, char*[]);
		virtual bool stop();
	private:
		Ice::ObjectAdapterPtr m_adapter;
};

bool ServerService::stop()
{
	print("[Server shutting down]");
	return true;
}

bool ServerService::start(int argc, char* argv[])
{

	try
	{
		print("[Server starting]");
		Ice::PropertiesPtr properties = communicator()->getProperties();
		string iceConfigFile = properties->getProperty("Ice.Config");
		if(iceConfigFile.empty())
		{
			error("\nThe configuration file was not found.  Please specify this\n"
				  "file by either:\n\n" 
				  "On the command line:\n"
				  "[rebecca-server --Ice.Config=<location of configuration file>]\n\n"
				  "or by setting the environment variable ICE_CONFIG to point to it:");
			error("The RebeccaAIML service cannot be run until the errors mentioned are fixed");
			return false;
		}

		trace("The config file has been found\n"
			  "The location is: " + 
			  properties->getProperty("Ice.Config"));

		string endPoint = properties->getPropertyWithDefault("Rebecca.Server.Config.EndPoint",
												             "default -p 58767");
		string serverName = properties->getPropertyWithDefault("Rebecca.Server.Config.Name",
													           "RebeccaAIML");
		trace("Creating service Name:" + serverName + "\n"
			  "With the EndPoint:" + endPoint);
		m_adapter = communicator()->createObjectAdapterWithEndpoints(serverName, endPoint);
		m_adapter->add(new NetworkGraphBuilderI(properties), communicator()->stringToIdentity(serverName));
		m_adapter->activate();
		print("[Server done loading and is now running]");
		return true;
	}
	catch(const Ice::FileException &fileException)
	{
		error("\nThe configuration file was not found.  Please specify this\n"
			  "file by either:\n\n" 
			  "On the command line:\n"
			  "[rebecca-server --Ice.Config==<location of configuration file>]\n\n"
			  "or by setting the environment variable ICE_CONFIG to point to it:");
		error("The RebeccaAIML service cannot be run until the errors mentioned are fixed");
		
		ostringstream s;
		s << fileException;
		error("The exception caught was:" + s.str());
		return false;
	}
	catch(const Ice::Exception& exception)
	{
		ostringstream s;
		s << exception;
		error("A general ICE exception occured and is:" + s.str());
		error("The RebeccaAIML service cannot be run until the errors mentioned are fixed");
		return false;
	}
	catch(Exception &rebeccaException)
	{
		error("The Rebecca Engine has thrown an exception and it is:" + string(rebeccaException.what()));
		error("The RebeccaAIML service cannot be run until the errors mentioned are fixed");
		return false;
	}
	return false;

}

} //end of impl namespace
} //end of rebecca namespace

#endif


