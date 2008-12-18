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
#include <rebecca/impl/NetworkGraphBuilderAIML.h>
#include <rebecca/impl/ExceptionImpl.h>

//std includes
#include <iostream>
#include <sstream>
using namespace std;

#include<IceUtil/IceUtil.h>

namespace rebecca
{
namespace impl
{

namespace
{

//two utility functions whose
//scopes are isolated to this file

wstring convertToWstring(const StringPimpl &narrow)
{
	wchar_t *wchar = new wchar_t[narrow.length() + 1];
	mbstowcs(wchar, narrow.c_str(), narrow.length());
	wchar[narrow.length()] = '\0';
	wstring ws(wchar);
	delete[] wchar;
	return ws;
}

string convertToString(const wstring &wide)
{
	char *nchar = new char[wide.length() + 1];
	wcstombs(nchar, wide.c_str(), wide.length());
	nchar[wide.length()] = '\0';
	string s(nchar);
	delete[] nchar;
	return s;
}

}

NetworkGraphBuilderAIML::NetworkGraphBuilderAIML(int argc, char *argv[])
	throw(NetworkException, Exception)
	: m_callBacksActivated(false), m_userId("default"), m_botId("default"), m_endUserId("default")
{
	try 
	{
		m_iceCommunicator = Ice::initialize(argc, argv);

		m_properties = m_iceCommunicator->getProperties();
		string name = m_properties->getPropertyWithDefault("Rebecca.Client.Config.Name", 
			                                             "rebecca-server");
		string endPoint = m_properties->getPropertyWithDefault("Rebecca.Client.Config.EndPoint", 
			                                                 "default -p 58767");
		string clientCallbackEndPoint = m_properties->getPropertyWithDefault("Rebecca.Server.Config.Callback.EndPoint", 
			                                                 "default -p 58768");
		string proxy = name + ":" + endPoint;
		Ice::ObjectPrx base = m_iceCommunicator->stringToProxy(proxy);
		m_networkGraphBuilderIce = NetworkGraphBuilderIcePrx::checkedCast(base);
		if(!m_networkGraphBuilderIce)
		{
			throw(NetworkExceptionImpl("The network could not be contacted. "
				                       "Do you have the server running?"));
		}

		m_adapter =
			m_iceCommunicator->createObjectAdapter("");
	}
	catch(const Ice::Exception& exeption)
	{
		ostringstream s;
		s << exeption;
		throw(NetworkExceptionImpl(s.str().c_str()));
	}
	catch(exception &e)
	{
		throw(ExceptionImpl(e.what()));
	}
}

void NetworkGraphBuilderAIML::destroy()
	throw(Exception &)
{
	m_iceCommunicator->destroy();
}

StringPimpl NetworkGraphBuilderAIML::getProperty(const StringPimpl &key) const
	throw(Exception &)
{ 
	try
	{
		return StringPimpl((m_properties->getProperty(key.c_str())).c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

StringPimpl NetworkGraphBuilderAIML::getPropertyWithDefault(const StringPimpl &key, const StringPimpl &value) const
	throw(Exception &)
{ 
	try
	{
		return StringPimpl((m_properties->getPropertyWithDefault(key.c_str(), value.c_str())).c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

int NetworkGraphBuilderAIML::getPropertyAsInt(const StringPimpl &key) const
	throw(Exception &)
{ 
	try
	{
		return m_properties->getPropertyAsInt(key.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

int NetworkGraphBuilderAIML::getPropertyAsIntWithDefault(const StringPimpl &key, int value) const
	throw(Exception &)
{ 

	try
	{
		return m_properties->getPropertyAsIntWithDefault(key.c_str(), value);
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
	catch(exception &e)
	{
		throw ExceptionImpl(e.what());
	}
}

void NetworkGraphBuilderAIML::addFile(const StringPimpl &file)
	throw(FileNotFoundException &, Exception &) 
{ 
	addFile(file, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::addFile(const StringPimpl &file,
									  const StringPimpl &userId,
									  const StringPimpl &botId,
									  const StringPimpl &endUserId) 
	throw(FileNotFoundException &, Exception &) 
{ 
	try
	{
		string fileStr = IceUtil::wstringToString(convertToWstring(file));
		m_networkGraphBuilderIce->addFile(fileStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}		


void NetworkGraphBuilderAIML::addDirectory(const StringPimpl &directory, 
	                                       const StringPimpl &userId, 
				                           const StringPimpl &botId,
				                           const StringPimpl &endUserId,
	                                       const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	try
	{
		string directoryStr = IceUtil::wstringToString(convertToWstring(directory));
		m_networkGraphBuilderIce->addDirectoryWithFilesEndingInRegularExpression(directoryStr, regularExpression.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(const DirectoryNotFoundExceptionIce &e)
	{
		throw DirectoryNotFoundExceptionImpl(e.what.c_str());
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}



void NetworkGraphBuilderAIML::addDirectory(const StringPimpl &directory, 
										   const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	addDirectory(directory, m_userId, m_botId, m_endUserId, regularExpression);
}

void NetworkGraphBuilderAIML::addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
	                                                         const StringPimpl &regularExpression)
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	addDirectoryUnlessAlreadyAdded(directory, m_userId, m_botId, m_endUserId, regularExpression);
}

void NetworkGraphBuilderAIML::addDirectoryUnlessAlreadyAdded(const StringPimpl &directory, 
	                                                         const StringPimpl &userId, 
						                                     const StringPimpl &botId,
						                                     const StringPimpl &endUserId,
						                                     const StringPimpl &regularExpression)
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	try
	{
		string directoryStr = IceUtil::wstringToString(convertToWstring(directory));
		m_networkGraphBuilderIce->addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(directoryStr, regularExpression.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(const DirectoryNotFoundExceptionIce &e)
	{
		throw DirectoryNotFoundExceptionImpl(e.what.c_str());
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::addFileUnlessAlreadyAdded(const StringPimpl &file)
	throw(FileNotFoundException &, Exception &)
{
	addFileUnlessAlreadyAdded(file, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::addFileUnlessAlreadyAdded(const StringPimpl &file,
	                                                    const StringPimpl &userId,
					                                    const StringPimpl &botId,
					                                    const StringPimpl &endUserId) 
	throw(FileNotFoundException &, Exception &)
{
	try
	{
		string fileStr = IceUtil::wstringToString(convertToWstring(file));
		m_networkGraphBuilderIce->addFileUnlessAlreadyAdded(fileStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}


void NetworkGraphBuilderAIML::addString(const StringPimpl &stringContainingAIML)
	throw(Exception &) 
{ 
	addString(stringContainingAIML, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::addString(const StringPimpl &stringContainingAIML,
										const StringPimpl &userId,
										const StringPimpl &botId,
										const StringPimpl &endUserId)
	throw(Exception &) 
{
	try
	{
		string stringContainingAIMLStr = IceUtil::wstringToString(convertToWstring(stringContainingAIML));
		m_networkGraphBuilderIce->addString(stringContainingAIMLStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setAddStringAIMLHeader(const StringPimpl &aimlHeader)
	throw(Exception &) 
{ 
	try
	{
		m_networkGraphBuilderIce->setAddStringAIMLHeader(aimlHeader.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setAddStringAIMLFooter(const StringPimpl &aimlFooter)
	throw(Exception &) 
{ 
	try
	{
		m_networkGraphBuilderIce->setAddStringAIMLFooter(aimlFooter.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setAIMLSchema(const StringPimpl &schema) 
	throw(Exception &, FileNotFoundException &) 
{ 
	try
	{
		string schemaStr = IceUtil::wstringToString(convertToWstring(schema));
		m_networkGraphBuilderIce->setAIMLSchema(schemaStr);
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setCommonTypesSchema(const StringPimpl &schema) 
	throw(Exception &, FileNotFoundException &) 
{ 
	try
	{
		string schemaStr = IceUtil::wstringToString(convertToWstring(schema));
		m_networkGraphBuilderIce->setCommonTypesSchema(schemaStr);
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setAIMLValidation(bool trueOrFalse) 
	throw(Exception &) 
{ 
	try
	{
		m_networkGraphBuilderIce->setAIMLValidation(trueOrFalse);
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getResponse(const StringPimpl &input, 
                                                 const StringPimpl &userId, 
						                         const StringPimpl &botId,
												 const StringPimpl &endUserId) 
	throw(Exception &)
{
	try
	{
		string inputStr = IceUtil::wstringToString(convertToWstring(input));
		string responseStr = m_networkGraphBuilderIce->getResponse(inputStr, userId.c_str(), botId.c_str(), endUserId.c_str());
		string str = convertToString(IceUtil::stringToWstring(responseStr));
		return str.c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}


StringPimpl NetworkGraphBuilderAIML::getResponse(const StringPimpl &input) 
	throw(Exception &) 
{ 
	return getResponse(input, m_userId, m_botId, m_endUserId);
}
void NetworkGraphBuilderAIML::setThat(const StringPimpl &that) 
	throw(Exception &) 
{ 
	setThat(that, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::setThat(const StringPimpl &that,
									  const StringPimpl &userId,
									  const StringPimpl &botId,
									  const StringPimpl &endUserId) 
	throw(Exception &) 
{ 
	try
	{
		string thatStr = IceUtil::wstringToString(convertToWstring(that));
		m_networkGraphBuilderIce->setThat(thatStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setTopic(const StringPimpl &topic)
	throw(Exception &) 
{
	setTopic(topic, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::setTopic(const StringPimpl &topic, 
									   const StringPimpl &userId,
									   const StringPimpl &botId,
									   const StringPimpl &endUserId) 
	throw(Exception &) 
{ 
	try
	{
		string topicStr = IceUtil::wstringToString(convertToWstring(topic));
		m_networkGraphBuilderIce->setTopic(topicStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getThat() const
	throw(Exception &) 
{ 
	return getThat(m_userId, m_botId, m_endUserId);
}

StringPimpl NetworkGraphBuilderAIML::getThat(const StringPimpl &userId,
											 const StringPimpl &botId,
											 const StringPimpl &endUserId) const
	throw(Exception &) 
{ 
	try
	{
		string thatStr = m_networkGraphBuilderIce->getThat(userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
		string str = convertToString(IceUtil::stringToWstring(thatStr));
		return str.c_str();

	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getTopic() const
	throw(Exception &) 
{ 
	return getTopic(m_userId, m_botId, m_endUserId);
}

StringPimpl NetworkGraphBuilderAIML::getTopic(const StringPimpl &userId,
											  const StringPimpl &botId,
											  const StringPimpl &endUserId) const
	throw(Exception &) 
{ 
	try
	{
		string topicStr = m_networkGraphBuilderIce->getTopic(userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
		string str = convertToString(IceUtil::stringToWstring(topicStr));
		return str.c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::createGraph() 
	throw(XMLErrorException &, Exception &) 
{ 
	createGraph(m_userId, m_botId, m_endUserId);
}



void NetworkGraphBuilderAIML::createGraph(const StringPimpl &userId,
										  const StringPimpl &botId,
										  const StringPimpl &endUserId) 
	throw(XMLErrorException &, Exception &) 
{ 
	try
	{
		m_networkGraphBuilderIce->createGraph(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(XMLErrorExceptionIce &e)
	{
		throw XMLErrorExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

bool NetworkGraphBuilderAIML::predicateMatch(const StringPimpl &predicateName, 
											 const StringPimpl &aimlPattern) const
	throw(Exception &)
{
	return predicateMatch(predicateName, aimlPattern, m_userId, m_botId, m_endUserId);
}

bool NetworkGraphBuilderAIML::predicateMatch(const StringPimpl &predicateName, 
											 const StringPimpl &aimlPattern,
											 const StringPimpl &userId,
											 const StringPimpl &botId,
											 const StringPimpl &endUserId) const
	throw(Exception &)
{
	try
	{
		string predicateNameStr = IceUtil::wstringToString(convertToWstring(predicateName));
		string aimlPatternStr = IceUtil::wstringToString(convertToWstring(aimlPattern));
		return m_networkGraphBuilderIce->predicateMatch(predicateNameStr, aimlPatternStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setPredicate(const StringPimpl &name, const StringPimpl &value) 
	throw(Exception &) 
{ 
	setPredicate(name, value, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::setPredicate(const StringPimpl &name, 
										   const StringPimpl &value,
										   const StringPimpl &userId,
										   const StringPimpl &botId,
										   const StringPimpl &endUserId) 
	throw(Exception &) 
{ 
	try
	{
		string nameStr = IceUtil::wstringToString(convertToWstring(name));
		string valueStr = IceUtil::wstringToString(convertToWstring(value));
		m_networkGraphBuilderIce->setPredicate(nameStr, valueStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getPredicate(const StringPimpl &name) const
	throw(Exception &) 
{
	return getPredicate(name, m_userId, m_botId, m_endUserId);
}

StringPimpl NetworkGraphBuilderAIML::getPredicate(const StringPimpl &name,
												  const StringPimpl &userId,
												  const StringPimpl &botId,
												  const StringPimpl &endUserId) const
	throw(Exception &) 
{ 
	try
	{
		string nameStr = IceUtil::wstringToString(convertToWstring(name));
		string predicateStr = m_networkGraphBuilderIce->getPredicate(nameStr, userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
		string str = convertToString(IceUtil::stringToWstring(predicateStr));
		return str.c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getBotPredicate(const StringPimpl &name) const
	throw(Exception &) 
{ 
	return getBotPredicate(name, m_userId, m_botId, m_endUserId);
}

StringPimpl NetworkGraphBuilderAIML::getBotPredicate(const StringPimpl &name,
													 const StringPimpl &userId,
													 const StringPimpl &botId,
													 const StringPimpl &endUserId) const
	throw(Exception &) 
{ 
	try
	{
		string nameStr = IceUtil::wstringToString(convertToWstring(name));
		string predicateStr = m_networkGraphBuilderIce->getBotPredicate(nameStr, userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
		string str = convertToString(IceUtil::stringToWstring(predicateStr));
		return str.c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setBotPredicate(const StringPimpl &name, 
											  const StringPimpl &value)
	throw(Exception &) 
{ 
	setBotPredicate(name, value, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::setBotPredicate(const StringPimpl &name, 
											  const StringPimpl &value,
											  const StringPimpl &userId,
											  const StringPimpl &botId,
											  const StringPimpl &endUserId)
	throw(Exception &) 
{ 
	try
	{
		string nameStr = IceUtil::wstringToString(convertToWstring(name));
		string valueStr = IceUtil::wstringToString(convertToWstring(value));
		m_networkGraphBuilderIce->setBotPredicate(nameStr, valueStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getPreviousBotResponse(const unsigned int &previousBotResponse, 
															const unsigned int &sentence) const
	throw(IllegalArgumentException &, Exception &) 
{ 
	return getPreviousBotResponse(previousBotResponse, sentence, m_userId, m_botId, m_endUserId);
}

StringPimpl NetworkGraphBuilderAIML::getPreviousBotResponse(const unsigned int &previousBotResponse, 
															const unsigned int &sentence,
															const StringPimpl &userId, 
															const StringPimpl &botId,
															const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &) 
{ 
	try
	{
		string previousBotResponseStr = m_networkGraphBuilderIce->getPreviousBotResponse(previousBotResponse, sentence, userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
		string str = convertToString(IceUtil::stringToWstring(previousBotResponseStr));
		return str.c_str();
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getPreviousUserInput(const unsigned int &previousUserInput, 
														  const unsigned int &sentence,
														  const StringPimpl &userId,
														  const StringPimpl &botId,
														  const StringPimpl &endUserId) const
	throw(IllegalArgumentException &, Exception &) 
{ 
	try
	{
		string previousUserInputStr = m_networkGraphBuilderIce->getPreviousUserInput(previousUserInput, sentence, userId.c_str(), botId.c_str(), endUserId.c_str()).c_str();
		string str = convertToString(IceUtil::stringToWstring(previousUserInputStr));
		return str.c_str();
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getPreviousUserInput(const unsigned int &previousUserInput, const unsigned int &sentence) const
	throw(IllegalArgumentException &, Exception &) 
{ 
	return getPreviousUserInput(previousUserInput, sentence, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::setBotConfigurationSchema(const StringPimpl &schema) 
	throw(Exception &, FileNotFoundException &) 
{ 
	try
	{
		string schemaStr = IceUtil::wstringToString(convertToWstring(schema));
		m_networkGraphBuilderIce->setBotConfigurationSchema(schemaStr);
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setBotConfigurationValidation(const bool trueOrFalse) 
	throw(Exception &) 
{ 
	try
	{
		m_networkGraphBuilderIce->setBotConfigurationValidation(trueOrFalse);
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::parseSubstitutionFile(const StringPimpl &fileName) 
	throw(XMLErrorException &, FileNotFoundException &, Exception &) 
{ 
	try
	{
		string fileNameStr = IceUtil::wstringToString(convertToWstring(fileName));
		return m_networkGraphBuilderIce->parseSubstitutionFile(fileNameStr);
	}
	catch(XMLErrorExceptionIce &e)
	{
		throw XMLErrorExceptionImpl(e.what.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::parseSentenceSplitterFile(const StringPimpl &fileName) 
	throw(XMLErrorException &, FileNotFoundException &, Exception &) 
{ 
	try
	{
		string fileNameStr = IceUtil::wstringToString(convertToWstring(fileName));
		m_networkGraphBuilderIce->parseSentenceSplitterFile(fileNameStr);
	}
	catch(XMLErrorExceptionIce &e)
	{
		throw XMLErrorExceptionImpl(e.what.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::parsePropertiesFile(const StringPimpl &fileName) 
	throw(XMLErrorException &, FileNotFoundException &, Exception &) 
{ 
	this->parsePropertiesFile(fileName, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::parsePropertiesFile(const StringPimpl &fileName,
												  const StringPimpl &userId,
												  const StringPimpl &botId,
												  const StringPimpl &endUserId) 
	throw(XMLErrorException &, FileNotFoundException &, Exception &) 
{ 
	try
	{
		string fileNameStr = IceUtil::wstringToString(convertToWstring(fileName));
		m_networkGraphBuilderIce->parsePropertiesFile(fileNameStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(XMLErrorExceptionIce &e)
	{
		throw XMLErrorExceptionImpl(e.what.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setSentenceSplitter(const StringPimpl &splitter) 
	throw(Exception &) 
{ 
	try
	{
		string splitterStr = IceUtil::wstringToString(convertToWstring(splitter));
		m_networkGraphBuilderIce->setSentenceSplitter(splitterStr);
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setInputSubstitution(const StringPimpl &find, const StringPimpl &replace) 
	throw(IllegalArgumentException &, Exception &) 
{ 
	try
	{
		string findStr = IceUtil::wstringToString(convertToWstring(find));
		string replaceStr = IceUtil::wstringToString(convertToWstring(replace));
		m_networkGraphBuilderIce->setInputSubstitution(findStr, replaceStr);
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setGenderSubstitution(const StringPimpl &find, const StringPimpl &replace) 
	throw(IllegalArgumentException &, Exception &) 
{ 
	try
	{
		string findStr = IceUtil::wstringToString(convertToWstring(find));
		string replaceStr = IceUtil::wstringToString(convertToWstring(replace));
		m_networkGraphBuilderIce->setGenderSubstitution(findStr, replaceStr);
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setPersonSubstitution(const StringPimpl &find, const StringPimpl &replace) 
	throw(IllegalArgumentException &, Exception &) 
{ 
	try
	{
		string findStr = IceUtil::wstringToString(convertToWstring(find));
		string replaceStr = IceUtil::wstringToString(convertToWstring(replace));
		m_networkGraphBuilderIce->setPersonSubstitution(findStr, replaceStr);
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setPerson2Substitution(const StringPimpl &find, const StringPimpl &replace) 
	throw(IllegalArgumentException &, Exception &)  
{ 
	try
	{
		string findStr = IceUtil::wstringToString(convertToWstring(find));
		string replaceStr = IceUtil::wstringToString(convertToWstring(replace));
		m_networkGraphBuilderIce->setPerson2Substitution(findStr, replaceStr);
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getVersion() const 
	throw(Exception &) 
{ 
	try
	{
		return m_networkGraphBuilderIce->getVersion().c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

int NetworkGraphBuilderAIML::getSize() const 
	throw(Exception &) 
{ 
	return getSize(m_userId, m_botId, m_endUserId);
}

int NetworkGraphBuilderAIML::getSize(const StringPimpl &userId,
									 const StringPimpl &botId,
									 const StringPimpl &endUserId) const 
	throw(Exception &) 
{ 
	try
	{
		return m_networkGraphBuilderIce->getSize(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setCallBacks(CallBacks *callBacks) 
	throw(Exception &) 
{ 
	try
	{
        if(m_callBacksActivated)
		{
			m_callBacksActivated = false;
			m_adapter->remove(m_ident);
		}
        
		if(callBacks == 0)
		{
            return;
		}
		else 
		{           
			m_ident.name = IceUtil::generateUUID();
			m_ident.category = "";
			m_callBacks = new NetworkCallBacks;
			m_adapter->add(m_callBacks, m_ident);
			m_adapter->activate();
			m_networkGraphBuilderIce->ice_getConnection()->setAdapter(m_adapter);
			m_networkGraphBuilderIce->setCallBacks(m_ident.name, m_ident.category);
            m_callBacks->setCallBacks(callBacks);
			m_callBacksActivated = true;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::storeGossip(const StringPimpl &gossip) 
	throw(Exception &) 
{ 
	try
	{
		string gossipStr = IceUtil::wstringToString(convertToWstring(gossip));
		m_networkGraphBuilderIce->storeGossip(gossipStr);
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::getId() const
	throw(Exception &) 
{ 
	try
	{
		return m_networkGraphBuilderIce->getId().c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::setUserIdBotIdEndUserId(const StringPimpl &userId, 
											          const StringPimpl &botId,
											          const StringPimpl &endUserId)
	throw(Exception &)
{
	m_userId = userId;
	m_botId = botId;
	m_endUserId = endUserId;
}

void NetworkGraphBuilderAIML::addCustomTagLibrary(const StringPimpl &library)
	throw(FileNotFoundException &, Exception &) 
{ 
	try
	{
		m_networkGraphBuilderIce->addCustomTagLibrary(library.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeCustomTagLibrary(const StringPimpl &library)
	throw(FileNotFoundException &, Exception &) 
{ 
	try
	{
		m_networkGraphBuilderIce->removeCustomTagLibrary(library.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl NetworkGraphBuilderAIML::callSystemCommand(const StringPimpl &command) const
	throw(Exception &) 
{ 
	try
	{
		return m_networkGraphBuilderIce->callSystemCommand(command.c_str()).c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

//void NetworkGraphBuilderAIML::setDBEnvironmentDirectory(const StringPimpl &directory)
//	throw(Exception &)
//{

/*
///@todo Either add this to the IDL file or remove it from graphbuilder or .... something ;-)
	try
	{
		return m_networkGraphBuilderIce->setDBEnvironmentDirectory(command.c_str()).c_str();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
*/
//}

void NetworkGraphBuilderAIML::setThreadSpecificIds(bool trueOrFalse)
	throw(Exception &)
{

}

void NetworkGraphBuilderAIML::removeFile(const StringPimpl &file) 
	throw(FileNotFoundException &, Exception &)
{
	removeFile(file, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::removeFile(const StringPimpl &file,
	                                     const StringPimpl &userId,
				                         const StringPimpl &botId,
				                         const StringPimpl &endUserId) 
	throw(FileNotFoundException &, Exception &)
{
	try
	{
		string fileStr = IceUtil::wstringToString(convertToWstring(file));
		m_networkGraphBuilderIce->removeFile(fileStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(FileNotFoundExceptionIce &e)
	{
		throw FileNotFoundExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeString(const StringPimpl &stringContainingAIML)
	throw(Exception &)
{
	removeString(stringContainingAIML, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::removeString(const StringPimpl &stringContainingAIML,
	                                       const StringPimpl &userId,
					                       const StringPimpl &botId,
					                       const StringPimpl &endUserId)
	throw(Exception &)
{
	try
	{
		string stringContainingAIMLStr = IceUtil::wstringToString(convertToWstring(stringContainingAIML));
		m_networkGraphBuilderIce->removeString(stringContainingAIMLStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}


void NetworkGraphBuilderAIML::removeGraph(const StringPimpl &userId,
	                                      const StringPimpl &botId,
						                  const StringPimpl &endUserId) 
	throw(XMLErrorException &, Exception &)
{
	try
	{
		m_networkGraphBuilderIce->removeGraph(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(XMLErrorExceptionIce &e)
	{
		throw XMLErrorExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeGraph() 
	throw(XMLErrorException &, Exception &)
{
		removeGraph(m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::removeDirectory(const StringPimpl &directory, 
	                                          const StringPimpl &userId, 
						                      const StringPimpl &botId,
						                      const StringPimpl &endUserId,
	                                          const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	try
	{
		string directoryStr = IceUtil::wstringToString(convertToWstring(directory));
		m_networkGraphBuilderIce->removeDirectoryWithFilesEndingInRegularExpression(directoryStr, regularExpression.c_str(), userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(const DirectoryNotFoundExceptionIce &e)
	{
		throw DirectoryNotFoundExceptionImpl(e.what.c_str());
	}
	catch(IllegalArgumentExceptionIce &e)
	{
		throw IllegalArgumentExceptionImpl(e.what.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeDirectory(const StringPimpl &directory, 
	                      const StringPimpl &regularExpression) 
	throw(IllegalArgumentException &, DirectoryNotFoundException &, Exception &)
{
	removeDirectory(directory, m_userId, m_botId, m_endUserId, regularExpression);
}

void NetworkGraphBuilderAIML::synchronizeDatabase() const
	throw(Exception &)
{
	try
	{
		m_networkGraphBuilderIce->synchronizeDatabase();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl *NetworkGraphBuilderAIML::getAIMLFileList(const StringPimpl &userId, 
	                                                  const StringPimpl &botId, 
							                          const StringPimpl &endUserId,
							                          unsigned int &size) const
	throw(Exception &)
{

	try
	{
		StringSeq seq = m_networkGraphBuilderIce->getAIMLFileList(userId.c_str(), botId.c_str(), endUserId.c_str());
		size = seq.size();
		if(size > 0)
		{
			StringPimpl *arrayList = new StringPimpl[size];
			for(unsigned int i = 0; i < seq.size(); ++i)
			{
				string inputStr = convertToString(IceUtil::stringToWstring(seq.at(i)));
				arrayList[i] = inputStr.c_str();
			}
			return arrayList;
		}
		else
		{
			return 0;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::deleteStringPimplArray(StringPimpl *arrayToDelete) const
	throw(Exception &)
{
	delete[] arrayToDelete;	
}

unsigned int NetworkGraphBuilderAIML::getAIMLFileListSize(const StringPimpl &userId, 
	                                                      const StringPimpl &botId, 
						                                  const StringPimpl &endUserId) const
	throw(Exception &)
{
	try
	{
		return m_networkGraphBuilderIce->getAIMLFileListSize(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl *NetworkGraphBuilderAIML::getAIMLFileList(unsigned int &size) const
	throw(Exception &)
{
	return getAIMLFileList(m_userId, m_botId, m_endUserId, size);
}

unsigned int NetworkGraphBuilderAIML::getAIMLFileListSize() const
	throw(Exception &)
{
	return getAIMLFileListSize(m_userId, m_botId, m_endUserId);
}

StringPimpl *NetworkGraphBuilderAIML::getAIMLStringList(const StringPimpl &userId, 
	                                                    const StringPimpl &botId, 
							                            const StringPimpl &endUserId,
							                            unsigned int &size) const
	throw(Exception &)
{

	try
	{
		StringSeq seq = m_networkGraphBuilderIce->getAIMLStringList(userId.c_str(), botId.c_str(), endUserId.c_str());
		size = seq.size();
		if(size > 0)
		{
			StringPimpl *arrayList = new StringPimpl[size];
			for(unsigned int i = 0; i < seq.size(); ++i)
			{
				string inputStr = convertToString(IceUtil::stringToWstring(seq.at(i)));
				arrayList[i] = inputStr.c_str();
			}
			return arrayList;
		}
		else
		{
			return 0;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

unsigned int NetworkGraphBuilderAIML::getAIMLStringListSize(const StringPimpl &userId, 
	                                                      const StringPimpl &botId, 
						                                  const StringPimpl &endUserId) const
	throw(Exception &)
{
	try
	{
		return m_networkGraphBuilderIce->getAIMLStringListSize(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl *NetworkGraphBuilderAIML::getAIMLStringList(unsigned int &size) const
	throw(Exception &)
{
	return getAIMLStringList(m_userId, m_botId, m_endUserId, size);
}

unsigned int NetworkGraphBuilderAIML::getAIMLStringListSize() const
	throw(Exception &)
{
	return getAIMLStringListSize(m_userId, m_botId, m_endUserId);
}

StringPimpl *NetworkGraphBuilderAIML::getUserIds(unsigned int &size) const
	throw(Exception &)
{
	try
	{
		StringSeq seq = m_networkGraphBuilderIce->getUserIds();
		size = seq.size();
		if(size > 0)
		{
			StringPimpl *arrayList = new StringPimpl[size];
			for(unsigned int i = 0; i < seq.size(); ++i)
			{
				arrayList[i] = seq.at(i).c_str();
			}
			return arrayList;
		}
		else
		{
			return 0;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

unsigned int NetworkGraphBuilderAIML::getUserIdsSize() const
	throw(Exception &)
{
	try
	{
		return m_networkGraphBuilderIce->getUserIdsSize();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl *NetworkGraphBuilderAIML::getBotIds(const StringPimpl &userId, 
	                                            unsigned int &size) const
	throw(Exception &)
{
	try
	{
		StringSeq seq = m_networkGraphBuilderIce->getBotIds(userId.c_str());
		size = seq.size();
		if(size > 0)
		{
			StringPimpl *arrayList = new StringPimpl[size];
			for(unsigned int i = 0; i < seq.size(); ++i)
			{
				arrayList[i] = seq.at(i).c_str();
			}
			return arrayList;
		}
		else
		{
			return 0;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

unsigned int NetworkGraphBuilderAIML::getBotIdsSize(const StringPimpl &userId) const
	throw(Exception &)
{
	try
	{
		return m_networkGraphBuilderIce->getBotIdsSize(userId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl *NetworkGraphBuilderAIML::getEndUserIds(const StringPimpl &userId, 
	                                                const StringPimpl &botId,
	                                                unsigned int &size) const
	throw(Exception &)
{
	try
	{
		StringSeq seq = m_networkGraphBuilderIce->getEndUserIds(userId.c_str(), botId.c_str());
		size = seq.size();
		if(size > 0)
		{
			StringPimpl *arrayList = new StringPimpl[size];
			for(unsigned int i = 0; i < seq.size(); ++i)
			{
				arrayList[i] = seq.at(i).c_str();
			}
			return arrayList;
		}
		else
		{
			return 0;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

unsigned int NetworkGraphBuilderAIML::getEndUserIdsSize(const StringPimpl &userId,
	                                                    const StringPimpl &botId) const
	throw(Exception &)
{
	try
	{
		return m_networkGraphBuilderIce->getEndUserIdsSize(userId.c_str(), botId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::printEntireDatabase() const
	throw(Exception &)
{
	try
	{
		m_networkGraphBuilderIce->printEntireDatabase();
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl *NetworkGraphBuilderAIML::getPredicates(unsigned int &size) const
	throw(Exception &)
{
	return getPredicates(m_userId, m_botId, m_endUserId, size);
}

StringPimpl *NetworkGraphBuilderAIML::getPredicates(const StringPimpl &userId,
													const StringPimpl &botId,
													const StringPimpl &endUserId,
													unsigned int &size) const
	throw(Exception &)
{
	try
	{
		StringSeq seq = m_networkGraphBuilderIce->getPredicates(userId.c_str(), botId.c_str(), endUserId.c_str());
		size = seq.size();
		if(size > 0)
		{
			StringPimpl *arrayList = new StringPimpl[size];
			for(unsigned int i = 0; i < seq.size(); ++i)
			{
				string inputStr = convertToString(IceUtil::stringToWstring(seq.at(i)));
				arrayList[i] = inputStr.c_str();
			}
			return arrayList;
		}
		else
		{
			return 0;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

StringPimpl *NetworkGraphBuilderAIML::getBotPredicates(unsigned int &size) const
	throw(Exception &)
{
	return getBotPredicates(m_userId, m_botId, m_endUserId, size);
}

StringPimpl *NetworkGraphBuilderAIML::getBotPredicates(const StringPimpl &userId,
													   const StringPimpl &botId,
													   const StringPimpl &endUserId, 
													   unsigned int &size) const
	throw(Exception &)
{
	try
	{
		StringSeq seq = m_networkGraphBuilderIce->getBotPredicates(userId.c_str(), botId.c_str(), endUserId.c_str());
		size = seq.size();
		if(size > 0)
		{
			StringPimpl *arrayList = new StringPimpl[size];
			for(unsigned int i = 0; i < seq.size(); ++i)
			{
				string inputStr = convertToString(IceUtil::stringToWstring(seq.at(i)));
				arrayList[i] = inputStr.c_str();
			}
			return arrayList;
		}
		else
		{
			return 0;
		}
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

unsigned int NetworkGraphBuilderAIML::getPredicatesSize(const StringPimpl &userId, 
	                                                    const StringPimpl &botId, 
							                            const StringPimpl &endUserId) const
	throw(Exception &)
{
	try
	{
		return m_networkGraphBuilderIce->getPredicatesSize(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

unsigned int NetworkGraphBuilderAIML::getBotPredicatesSize(const StringPimpl &userId, 
	                                                       const StringPimpl &botId, 
								                           const StringPimpl &endUserId) const
	throw(Exception &)
{
	try
	{
		return m_networkGraphBuilderIce->getBotPredicatesSize(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

unsigned int NetworkGraphBuilderAIML::getPredicatesSize() const
	throw(Exception &)
{
	return getPredicatesSize(m_userId, m_botId, m_endUserId);
}

unsigned int NetworkGraphBuilderAIML::getBotPredicatesSize() const
	throw(Exception &)
{
	return getBotPredicatesSize(m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::removePredicate(const StringPimpl &name)
	throw(Exception &)
{
	removePredicate(name, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::removePredicate(const StringPimpl &name, 
						                      const StringPimpl &userId,
						                      const StringPimpl &botId,
						                      const StringPimpl &endUserId)
	throw(Exception &)
{
	try
	{
		string nameStr = IceUtil::wstringToString(convertToWstring(name));
		m_networkGraphBuilderIce->removePredicate(nameStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeBotPredicate(const StringPimpl &name)
	throw(Exception &)
{
	removeBotPredicate(name, m_userId, m_botId, m_endUserId);
}

void NetworkGraphBuilderAIML::removeBotPredicate(const StringPimpl &name, 
						                         const StringPimpl &userId,
						                         const StringPimpl &botId,
						                         const StringPimpl &endUserId)
	throw(Exception &)
{
	try
	{
		string nameStr = IceUtil::wstringToString(convertToWstring(name));
		m_networkGraphBuilderIce->removeBotPredicate(nameStr, userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeEndUser(const StringPimpl &userId,
	                                        const StringPimpl &botId,
						                    const StringPimpl &endUserId)
	throw(Exception &)
{
	try
	{
		m_networkGraphBuilderIce->removeEndUser(userId.c_str(), botId.c_str(), endUserId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeBot(const StringPimpl &userId,
	                                      const StringPimpl &botId)
	throw(Exception &)
{
	try
	{
		m_networkGraphBuilderIce->removeBot(userId.c_str(), botId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

void NetworkGraphBuilderAIML::removeUser(const StringPimpl &userId)
	throw(Exception &)
{
	try
	{
		m_networkGraphBuilderIce->removeUser(userId.c_str());
	}
	catch(ExceptionIce &e)
	{
		throw ExceptionImpl(e.what.c_str());
	}
	catch(const Ice::Exception& ex)
	{
		ostringstream s;
		s << ex;
		throw ExceptionImpl(s.str().c_str());
	}
}

NetworkGraphBuilderAIML::~NetworkGraphBuilderAIML()
{

}

} //end of namespace impl
} //end of namespace rebecca
