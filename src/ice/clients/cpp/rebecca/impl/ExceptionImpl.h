#ifndef REBECCA_EXCEPTIONIMPL_H
#define REBECCA_EXCEPTIONIMPL_H

//std includes
#include <string>

namespace rebecca
{
namespace impl
{
using namespace std;
class ExceptionImpl : public Exception
{
	public: 
		
		ExceptionImpl(const char * const msg = "Unknown exception")
			: m_msg(msg)
		{ }

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}	

	private:
		string m_msg;		
};

class NetworkExceptionImpl : public NetworkException
{
	public: 
		
		NetworkExceptionImpl(const char * const msg = "Unknown exception")
			: m_msg(msg)
		{ }

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}	

	private:
		string m_msg;		
};

class DirectoryNotFoundExceptionImpl : public DirectoryNotFoundException
{
	public: 
		
		DirectoryNotFoundExceptionImpl(const char * const msg = "Unknown exception")
			: m_msg(msg)
		{ }

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}	

	private:
		string m_msg;		
};

class IllegalArgumentExceptionImpl : public IllegalArgumentException
{
	public: 
		
		IllegalArgumentExceptionImpl(const char * const msg = "Unknown exception")
			: m_msg(msg)
		{ }

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}	

	private:
		string m_msg;		
};

class FileNotFoundExceptionImpl : public FileNotFoundException
{
	public: 
		
		FileNotFoundExceptionImpl(const char * const msg = "Unknown exception")
			: m_msg(msg)
		{ }

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}	

	private:
		string m_msg;		
};

class XMLErrorExceptionImpl : public XMLErrorException
{
	public: 
		
		XMLErrorExceptionImpl(const char * const msg = "Unknown exception")
			: m_msg(msg)
		{ }

		virtual const char* what() const throw()
		{
			return m_msg.c_str();
		}	

	private:
		string m_msg;		
};



} //end of impl namespace
} //end of rebecca namespace

#endif


