// **********************************************************************
//
// Copyright (c) 2003-2008 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.3.0
// Generated from file `network.ice'

#ifndef ________rebecca_impl________rebecca_impl__network_h__
#define ________rebecca_impl________rebecca_impl__network_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/UserExceptionFactory.h>
#include <Ice/FactoryTable.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 303
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace rebecca
{

namespace impl
{

class CallBacksIce;

class NetworkGraphBuilderIce;

}

}

}

namespace rebecca
{

namespace impl
{

class CallBacksIce;
bool operator==(const CallBacksIce&, const CallBacksIce&);
bool operator<(const CallBacksIce&, const CallBacksIce&);

class NetworkGraphBuilderIce;
bool operator==(const NetworkGraphBuilderIce&, const NetworkGraphBuilderIce&);
bool operator<(const NetworkGraphBuilderIce&, const NetworkGraphBuilderIce&);

}

}

namespace IceInternal
{

::Ice::Object* upCast(::rebecca::impl::CallBacksIce*);
::IceProxy::Ice::Object* upCast(::IceProxy::rebecca::impl::CallBacksIce*);

::Ice::Object* upCast(::rebecca::impl::NetworkGraphBuilderIce*);
::IceProxy::Ice::Object* upCast(::IceProxy::rebecca::impl::NetworkGraphBuilderIce*);

}

namespace rebecca
{

namespace impl
{

typedef ::IceInternal::Handle< ::rebecca::impl::CallBacksIce> CallBacksIcePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::rebecca::impl::CallBacksIce> CallBacksIcePrx;

void __read(::IceInternal::BasicStream*, CallBacksIcePrx&);
void __patch__CallBacksIcePtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::rebecca::impl::NetworkGraphBuilderIce> NetworkGraphBuilderIcePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::rebecca::impl::NetworkGraphBuilderIce> NetworkGraphBuilderIcePrx;

void __read(::IceInternal::BasicStream*, NetworkGraphBuilderIcePrx&);
void __patch__NetworkGraphBuilderIcePtr(void*, ::Ice::ObjectPtr&);

}

}

namespace rebecca
{

namespace impl
{

typedef ::std::vector< ::std::string> StringSeq;

class ExceptionIce : public ::Ice::UserException
{
public:

    ExceptionIce() {}
    explicit ExceptionIce(const ::std::string&);
    virtual ~ExceptionIce() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string what;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

static ExceptionIce __ExceptionIce_init;

class FileNotFoundExceptionIce : public ::rebecca::impl::ExceptionIce
{
public:

    FileNotFoundExceptionIce() {}
    explicit FileNotFoundExceptionIce(const ::std::string&);
    virtual ~FileNotFoundExceptionIce() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class IllegalArgumentExceptionIce : public ::rebecca::impl::ExceptionIce
{
public:

    IllegalArgumentExceptionIce() {}
    explicit IllegalArgumentExceptionIce(const ::std::string&);
    virtual ~IllegalArgumentExceptionIce() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class DirectoryNotFoundExceptionIce : public ::rebecca::impl::ExceptionIce
{
public:

    DirectoryNotFoundExceptionIce() {}
    explicit DirectoryNotFoundExceptionIce(const ::std::string&);
    virtual ~DirectoryNotFoundExceptionIce() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class XMLErrorExceptionIce : public ::rebecca::impl::ExceptionIce
{
public:

    XMLErrorExceptionIce() {}
    explicit XMLErrorExceptionIce(const ::std::string&);
    virtual ~XMLErrorExceptionIce() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

}

}

namespace IceProxy
{

namespace rebecca
{

namespace impl
{

class CallBacksIce : virtual public ::IceProxy::Ice::Object
{
public:

    void storeGossip(const ::std::string& gossip, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        storeGossip(gossip, userId, botId, endUserId, 0);
    }
    void storeGossip(const ::std::string& gossip, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        storeGossip(gossip, userId, botId, endUserId, &__ctx);
    }
    
private:

    void storeGossip(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void categoryLoaded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        categoryLoaded(userId, botId, endUserId, 0);
    }
    void categoryLoaded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        categoryLoaded(userId, botId, endUserId, &__ctx);
    }
    
private:

    void categoryLoaded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void filePreLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        filePreLoad(fileName, userId, botId, endUserId, 0);
    }
    void filePreLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        filePreLoad(fileName, userId, botId, endUserId, &__ctx);
    }
    
private:

    void filePreLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void filePostLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        filePostLoad(fileName, userId, botId, endUserId, 0);
    }
    void filePostLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        filePostLoad(fileName, userId, botId, endUserId, &__ctx);
    }
    
private:

    void filePostLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void symbolicReduction(const ::std::string& symbol, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        symbolicReduction(symbol, userId, botId, endUserId, 0);
    }
    void symbolicReduction(const ::std::string& symbol, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        symbolicReduction(symbol, userId, botId, endUserId, &__ctx);
    }
    
private:

    void symbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void infiniteSymbolicReduction(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        infiniteSymbolicReduction(userId, botId, endUserId, 0);
    }
    void infiniteSymbolicReduction(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        infiniteSymbolicReduction(userId, botId, endUserId, &__ctx);
    }
    
private:

    void infiniteSymbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void XMLParseError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        XMLParseError(message, userId, botId, endUserId, 0);
    }
    void XMLParseError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        XMLParseError(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void XMLParseError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void XMLParseWarning(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        XMLParseWarning(message, userId, botId, endUserId, 0);
    }
    void XMLParseWarning(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        XMLParseWarning(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void XMLParseWarning(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void XMLParseFatalError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        XMLParseFatalError(message, userId, botId, endUserId, 0);
    }
    void XMLParseFatalError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        XMLParseFatalError(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void XMLParseFatalError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void thatStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        thatStarTagSizeExceeded(userId, botId, endUserId, 0);
    }
    void thatStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        thatStarTagSizeExceeded(userId, botId, endUserId, &__ctx);
    }
    
private:

    void thatStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void topicStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        topicStarTagSizeExceeded(userId, botId, endUserId, 0);
    }
    void topicStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        topicStarTagSizeExceeded(userId, botId, endUserId, &__ctx);
    }
    
private:

    void topicStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void starTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        starTagSizeExceeded(userId, botId, endUserId, 0);
    }
    void starTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        starTagSizeExceeded(userId, botId, endUserId, &__ctx);
    }
    
private:

    void starTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void inputTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        inputTagNumericConversionError(message, userId, botId, endUserId, 0);
    }
    void inputTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        inputTagNumericConversionError(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void inputTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void inputTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        inputTagSizeExceeded(userId, botId, endUserId, 0);
    }
    void inputTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        inputTagSizeExceeded(userId, botId, endUserId, &__ctx);
    }
    
private:

    void inputTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void starTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        starTagNumericConversionError(message, userId, botId, endUserId, 0);
    }
    void starTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        starTagNumericConversionError(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void starTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void thatTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        thatTagSizeExceeded(userId, botId, endUserId, 0);
    }
    void thatTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        thatTagSizeExceeded(userId, botId, endUserId, &__ctx);
    }
    
private:

    void thatTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void thatTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        thatTagNumericConversionError(message, userId, botId, endUserId, 0);
    }
    void thatTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        thatTagNumericConversionError(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void thatTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void topicStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        topicStarTagNumericConversionError(message, userId, botId, endUserId, 0);
    }
    void topicStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        topicStarTagNumericConversionError(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void topicStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void thatStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        thatStarTagNumericConversionError(message, userId, botId, endUserId, 0);
    }
    void thatStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        thatStarTagNumericConversionError(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void thatStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void learnTagFileNotFound(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        learnTagFileNotFound(message, userId, botId, endUserId, 0);
    }
    void learnTagFileNotFound(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        learnTagFileNotFound(message, userId, botId, endUserId, &__ctx);
    }
    
private:

    void learnTagFileNotFound(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<CallBacksIce> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<CallBacksIce*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<CallBacksIce*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class NetworkGraphBuilderIce : virtual public ::IceProxy::Ice::Object
{
public:

    void addFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        addFile(file, userId, botId, endUserId, 0);
    }
    void addFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        addFile(file, userId, botId, endUserId, &__ctx);
    }
    
private:

    void addFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void addFileUnlessAlreadyAdded(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        addFileUnlessAlreadyAdded(file, userId, botId, endUserId, 0);
    }
    void addFileUnlessAlreadyAdded(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        addFileUnlessAlreadyAdded(file, userId, botId, endUserId, &__ctx);
    }
    
private:

    void addFileUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removeFile(file, userId, botId, endUserId, 0);
    }
    void removeFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removeFile(file, userId, botId, endUserId, &__ctx);
    }
    
private:

    void removeFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void addDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        addDirectory(directory, userId, botId, endUserId, 0);
    }
    void addDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        addDirectory(directory, userId, botId, endUserId, &__ctx);
    }
    
private:

    void addDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void addDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        addDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, 0);
    }
    void addDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        addDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, &__ctx);
    }
    
private:

    void addDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void addDirectoryUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        addDirectoryUnlessAlreadyAdded(directory, userId, botId, endUserId, 0);
    }
    void addDirectoryUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        addDirectoryUnlessAlreadyAdded(directory, userId, botId, endUserId, &__ctx);
    }
    
private:

    void addDirectoryUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(directory, regularExpression, userId, botId, endUserId, 0);
    }
    void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(directory, regularExpression, userId, botId, endUserId, &__ctx);
    }
    
private:

    void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removeDirectory(directory, userId, botId, endUserId, 0);
    }
    void removeDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removeDirectory(directory, userId, botId, endUserId, &__ctx);
    }
    
private:

    void removeDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removeDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, 0);
    }
    void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removeDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, &__ctx);
    }
    
private:

    void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void addString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        addString(stringContainingAIML, userId, botId, endUserId, 0);
    }
    void addString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        addString(stringContainingAIML, userId, botId, endUserId, &__ctx);
    }
    
private:

    void addString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removeString(stringContainingAIML, userId, botId, endUserId, 0);
    }
    void removeString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removeString(stringContainingAIML, userId, botId, endUserId, &__ctx);
    }
    
private:

    void removeString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setAddStringAIMLHeader(const ::std::string& aimlHeader)
    {
        setAddStringAIMLHeader(aimlHeader, 0);
    }
    void setAddStringAIMLHeader(const ::std::string& aimlHeader, const ::Ice::Context& __ctx)
    {
        setAddStringAIMLHeader(aimlHeader, &__ctx);
    }
    
private:

    void setAddStringAIMLHeader(const ::std::string&, const ::Ice::Context*);
    
public:

    void setAddStringAIMLFooter(const ::std::string& aimlFooter)
    {
        setAddStringAIMLFooter(aimlFooter, 0);
    }
    void setAddStringAIMLFooter(const ::std::string& aimlFooter, const ::Ice::Context& __ctx)
    {
        setAddStringAIMLFooter(aimlFooter, &__ctx);
    }
    
private:

    void setAddStringAIMLFooter(const ::std::string&, const ::Ice::Context*);
    
public:

    void setAIMLSchema(const ::std::string& schema)
    {
        setAIMLSchema(schema, 0);
    }
    void setAIMLSchema(const ::std::string& schema, const ::Ice::Context& __ctx)
    {
        setAIMLSchema(schema, &__ctx);
    }
    
private:

    void setAIMLSchema(const ::std::string&, const ::Ice::Context*);
    
public:

    void setCommonTypesSchema(const ::std::string& schema)
    {
        setCommonTypesSchema(schema, 0);
    }
    void setCommonTypesSchema(const ::std::string& schema, const ::Ice::Context& __ctx)
    {
        setCommonTypesSchema(schema, &__ctx);
    }
    
private:

    void setCommonTypesSchema(const ::std::string&, const ::Ice::Context*);
    
public:

    void setAIMLValidation(bool trueOrFalse)
    {
        setAIMLValidation(trueOrFalse, 0);
    }
    void setAIMLValidation(bool trueOrFalse, const ::Ice::Context& __ctx)
    {
        setAIMLValidation(trueOrFalse, &__ctx);
    }
    
private:

    void setAIMLValidation(bool, const ::Ice::Context*);
    
public:

    ::std::string getResponse(const ::std::string& input, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getResponse(input, userId, botId, endUserId, 0);
    }
    ::std::string getResponse(const ::std::string& input, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getResponse(input, userId, botId, endUserId, &__ctx);
    }
    
private:

    ::std::string getResponse(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setThat(const ::std::string& that, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        setThat(that, userId, botId, endUserId, 0);
    }
    void setThat(const ::std::string& that, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        setThat(that, userId, botId, endUserId, &__ctx);
    }
    
private:

    void setThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setTopic(const ::std::string& topic, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        setTopic(topic, userId, botId, endUserId, 0);
    }
    void setTopic(const ::std::string& topic, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        setTopic(topic, userId, botId, endUserId, &__ctx);
    }
    
private:

    void setTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getThat(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getThat(userId, botId, endUserId, 0);
    }
    ::std::string getThat(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getThat(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::std::string getThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getTopic(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getTopic(userId, botId, endUserId, 0);
    }
    ::std::string getTopic(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getTopic(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::std::string getTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void createGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        createGraph(userId, botId, endUserId, 0);
    }
    void createGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        createGraph(userId, botId, endUserId, &__ctx);
    }
    
private:

    void createGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removeGraph(userId, botId, endUserId, 0);
    }
    void removeGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removeGraph(userId, botId, endUserId, &__ctx);
    }
    
private:

    void removeGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    bool predicateMatch(const ::std::string& predicateName, const ::std::string& aimlPattern, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return predicateMatch(predicateName, aimlPattern, userId, botId, endUserId, 0);
    }
    bool predicateMatch(const ::std::string& predicateName, const ::std::string& aimlPattern, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return predicateMatch(predicateName, aimlPattern, userId, botId, endUserId, &__ctx);
    }
    
private:

    bool predicateMatch(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        setPredicate(name, value, userId, botId, endUserId, 0);
    }
    void setPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        setPredicate(name, value, userId, botId, endUserId, &__ctx);
    }
    
private:

    void setPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getPredicate(name, userId, botId, endUserId, 0);
    }
    ::std::string getPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getPredicate(name, userId, botId, endUserId, &__ctx);
    }
    
private:

    ::std::string getPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getBotPredicate(name, userId, botId, endUserId, 0);
    }
    ::std::string getBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getBotPredicate(name, userId, botId, endUserId, &__ctx);
    }
    
private:

    ::std::string getBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setBotPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        setBotPredicate(name, value, userId, botId, endUserId, 0);
    }
    void setBotPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        setBotPredicate(name, value, userId, botId, endUserId, &__ctx);
    }
    
private:

    void setBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getPreviousBotResponse(::Ice::Int previousBotResponse, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getPreviousBotResponse(previousBotResponse, sentence, userId, botId, endUserId, 0);
    }
    ::std::string getPreviousBotResponse(::Ice::Int previousBotResponse, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getPreviousBotResponse(previousBotResponse, sentence, userId, botId, endUserId, &__ctx);
    }
    
private:

    ::std::string getPreviousBotResponse(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getPreviousUserInput(::Ice::Int previousUserInput, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getPreviousUserInput(previousUserInput, sentence, userId, botId, endUserId, 0);
    }
    ::std::string getPreviousUserInput(::Ice::Int previousUserInput, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getPreviousUserInput(previousUserInput, sentence, userId, botId, endUserId, &__ctx);
    }
    
private:

    ::std::string getPreviousUserInput(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setBotConfigurationSchema(const ::std::string& schema)
    {
        setBotConfigurationSchema(schema, 0);
    }
    void setBotConfigurationSchema(const ::std::string& schema, const ::Ice::Context& __ctx)
    {
        setBotConfigurationSchema(schema, &__ctx);
    }
    
private:

    void setBotConfigurationSchema(const ::std::string&, const ::Ice::Context*);
    
public:

    void setBotConfigurationValidation(bool trueOrFalse)
    {
        setBotConfigurationValidation(trueOrFalse, 0);
    }
    void setBotConfigurationValidation(bool trueOrFalse, const ::Ice::Context& __ctx)
    {
        setBotConfigurationValidation(trueOrFalse, &__ctx);
    }
    
private:

    void setBotConfigurationValidation(bool, const ::Ice::Context*);
    
public:

    void parseSubstitutionFile(const ::std::string& fileName)
    {
        parseSubstitutionFile(fileName, 0);
    }
    void parseSubstitutionFile(const ::std::string& fileName, const ::Ice::Context& __ctx)
    {
        parseSubstitutionFile(fileName, &__ctx);
    }
    
private:

    void parseSubstitutionFile(const ::std::string&, const ::Ice::Context*);
    
public:

    void parseSentenceSplitterFile(const ::std::string& fileName)
    {
        parseSentenceSplitterFile(fileName, 0);
    }
    void parseSentenceSplitterFile(const ::std::string& fileName, const ::Ice::Context& __ctx)
    {
        parseSentenceSplitterFile(fileName, &__ctx);
    }
    
private:

    void parseSentenceSplitterFile(const ::std::string&, const ::Ice::Context*);
    
public:

    void parsePropertiesFile(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        parsePropertiesFile(fileName, userId, botId, endUserId, 0);
    }
    void parsePropertiesFile(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        parsePropertiesFile(fileName, userId, botId, endUserId, &__ctx);
    }
    
private:

    void parsePropertiesFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setSentenceSplitter(const ::std::string& splitter)
    {
        setSentenceSplitter(splitter, 0);
    }
    void setSentenceSplitter(const ::std::string& splitter, const ::Ice::Context& __ctx)
    {
        setSentenceSplitter(splitter, &__ctx);
    }
    
private:

    void setSentenceSplitter(const ::std::string&, const ::Ice::Context*);
    
public:

    void setInputSubstitution(const ::std::string& find, const ::std::string& replace)
    {
        setInputSubstitution(find, replace, 0);
    }
    void setInputSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context& __ctx)
    {
        setInputSubstitution(find, replace, &__ctx);
    }
    
private:

    void setInputSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setGenderSubstitution(const ::std::string& find, const ::std::string& replace)
    {
        setGenderSubstitution(find, replace, 0);
    }
    void setGenderSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context& __ctx)
    {
        setGenderSubstitution(find, replace, &__ctx);
    }
    
private:

    void setGenderSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setPersonSubstitution(const ::std::string& find, const ::std::string& replace)
    {
        setPersonSubstitution(find, replace, 0);
    }
    void setPersonSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context& __ctx)
    {
        setPersonSubstitution(find, replace, &__ctx);
    }
    
private:

    void setPersonSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setPerson2Substitution(const ::std::string& find, const ::std::string& replace)
    {
        setPerson2Substitution(find, replace, 0);
    }
    void setPerson2Substitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context& __ctx)
    {
        setPerson2Substitution(find, replace, &__ctx);
    }
    
private:

    void setPerson2Substitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getVersion()
    {
        return getVersion(0);
    }
    ::std::string getVersion(const ::Ice::Context& __ctx)
    {
        return getVersion(&__ctx);
    }
    
private:

    ::std::string getVersion(const ::Ice::Context*);
    
public:

    ::Ice::Int getSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getSize(userId, botId, endUserId, 0);
    }
    ::Ice::Int getSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getSize(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::Ice::Int getSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setCallBacks(const ::std::string& name, const ::std::string& category)
    {
        setCallBacks(name, category, 0);
    }
    void setCallBacks(const ::std::string& name, const ::std::string& category, const ::Ice::Context& __ctx)
    {
        setCallBacks(name, category, &__ctx);
    }
    
private:

    void setCallBacks(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void storeGossip(const ::std::string& gossip)
    {
        storeGossip(gossip, 0);
    }
    void storeGossip(const ::std::string& gossip, const ::Ice::Context& __ctx)
    {
        storeGossip(gossip, &__ctx);
    }
    
private:

    void storeGossip(const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string getId()
    {
        return getId(0);
    }
    ::std::string getId(const ::Ice::Context& __ctx)
    {
        return getId(&__ctx);
    }
    
private:

    ::std::string getId(const ::Ice::Context*);
    
public:

    void addCustomTagLibrary(const ::std::string& library)
    {
        addCustomTagLibrary(library, 0);
    }
    void addCustomTagLibrary(const ::std::string& library, const ::Ice::Context& __ctx)
    {
        addCustomTagLibrary(library, &__ctx);
    }
    
private:

    void addCustomTagLibrary(const ::std::string&, const ::Ice::Context*);
    
public:

    void removeCustomTagLibrary(const ::std::string& library)
    {
        removeCustomTagLibrary(library, 0);
    }
    void removeCustomTagLibrary(const ::std::string& library, const ::Ice::Context& __ctx)
    {
        removeCustomTagLibrary(library, &__ctx);
    }
    
private:

    void removeCustomTagLibrary(const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string callSystemCommand(const ::std::string& command)
    {
        return callSystemCommand(command, 0);
    }
    ::std::string callSystemCommand(const ::std::string& command, const ::Ice::Context& __ctx)
    {
        return callSystemCommand(command, &__ctx);
    }
    
private:

    ::std::string callSystemCommand(const ::std::string&, const ::Ice::Context*);
    
public:

    void synchronizeDatabase()
    {
        synchronizeDatabase(0);
    }
    void synchronizeDatabase(const ::Ice::Context& __ctx)
    {
        synchronizeDatabase(&__ctx);
    }
    
private:

    void synchronizeDatabase(const ::Ice::Context*);
    
public:

    ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getAIMLFileList(userId, botId, endUserId, 0);
    }
    ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getAIMLFileList(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int getAIMLFileListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getAIMLFileListSize(userId, botId, endUserId, 0);
    }
    ::Ice::Int getAIMLFileListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getAIMLFileListSize(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::Ice::Int getAIMLFileListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getAIMLStringList(userId, botId, endUserId, 0);
    }
    ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getAIMLStringList(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int getAIMLStringListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getAIMLStringListSize(userId, botId, endUserId, 0);
    }
    ::Ice::Int getAIMLStringListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getAIMLStringListSize(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::Ice::Int getAIMLStringListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::rebecca::impl::StringSeq getUserIds()
    {
        return getUserIds(0);
    }
    ::rebecca::impl::StringSeq getUserIds(const ::Ice::Context& __ctx)
    {
        return getUserIds(&__ctx);
    }
    
private:

    ::rebecca::impl::StringSeq getUserIds(const ::Ice::Context*);
    
public:

    ::Ice::Int getUserIdsSize()
    {
        return getUserIdsSize(0);
    }
    ::Ice::Int getUserIdsSize(const ::Ice::Context& __ctx)
    {
        return getUserIdsSize(&__ctx);
    }
    
private:

    ::Ice::Int getUserIdsSize(const ::Ice::Context*);
    
public:

    ::rebecca::impl::StringSeq getBotIds(const ::std::string& userId)
    {
        return getBotIds(userId, 0);
    }
    ::rebecca::impl::StringSeq getBotIds(const ::std::string& userId, const ::Ice::Context& __ctx)
    {
        return getBotIds(userId, &__ctx);
    }
    
private:

    ::rebecca::impl::StringSeq getBotIds(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int getBotIdsSize(const ::std::string& userId)
    {
        return getBotIdsSize(userId, 0);
    }
    ::Ice::Int getBotIdsSize(const ::std::string& userId, const ::Ice::Context& __ctx)
    {
        return getBotIdsSize(userId, &__ctx);
    }
    
private:

    ::Ice::Int getBotIdsSize(const ::std::string&, const ::Ice::Context*);
    
public:

    ::rebecca::impl::StringSeq getEndUserIds(const ::std::string& userId, const ::std::string& botId)
    {
        return getEndUserIds(userId, botId, 0);
    }
    ::rebecca::impl::StringSeq getEndUserIds(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context& __ctx)
    {
        return getEndUserIds(userId, botId, &__ctx);
    }
    
private:

    ::rebecca::impl::StringSeq getEndUserIds(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int getEndUserIdsSize(const ::std::string& userId, const ::std::string& botId)
    {
        return getEndUserIdsSize(userId, botId, 0);
    }
    ::Ice::Int getEndUserIdsSize(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context& __ctx)
    {
        return getEndUserIdsSize(userId, botId, &__ctx);
    }
    
private:

    ::Ice::Int getEndUserIdsSize(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void printEntireDatabase()
    {
        printEntireDatabase(0);
    }
    void printEntireDatabase(const ::Ice::Context& __ctx)
    {
        printEntireDatabase(&__ctx);
    }
    
private:

    void printEntireDatabase(const ::Ice::Context*);
    
public:

    ::rebecca::impl::StringSeq getBotPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getBotPredicates(userId, botId, endUserId, 0);
    }
    ::rebecca::impl::StringSeq getBotPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getBotPredicates(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::rebecca::impl::StringSeq getBotPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::rebecca::impl::StringSeq getPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getPredicates(userId, botId, endUserId, 0);
    }
    ::rebecca::impl::StringSeq getPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getPredicates(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::rebecca::impl::StringSeq getPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int getBotPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getBotPredicatesSize(userId, botId, endUserId, 0);
    }
    ::Ice::Int getBotPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getBotPredicatesSize(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::Ice::Int getBotPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int getPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        return getPredicatesSize(userId, botId, endUserId, 0);
    }
    ::Ice::Int getPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        return getPredicatesSize(userId, botId, endUserId, &__ctx);
    }
    
private:

    ::Ice::Int getPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removePredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removePredicate(name, userId, botId, endUserId, 0);
    }
    void removePredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removePredicate(name, userId, botId, endUserId, &__ctx);
    }
    
private:

    void removePredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removeBotPredicate(name, userId, botId, endUserId, 0);
    }
    void removeBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removeBotPredicate(name, userId, botId, endUserId, &__ctx);
    }
    
private:

    void removeBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeEndUser(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId)
    {
        removeEndUser(userId, botId, endUserId, 0);
    }
    void removeEndUser(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context& __ctx)
    {
        removeEndUser(userId, botId, endUserId, &__ctx);
    }
    
private:

    void removeEndUser(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeBot(const ::std::string& userId, const ::std::string& botId)
    {
        removeBot(userId, botId, 0);
    }
    void removeBot(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context& __ctx)
    {
        removeBot(userId, botId, &__ctx);
    }
    
private:

    void removeBot(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeUser(const ::std::string& userId)
    {
        removeUser(userId, 0);
    }
    void removeUser(const ::std::string& userId, const ::Ice::Context& __ctx)
    {
        removeUser(userId, &__ctx);
    }
    
private:

    void removeUser(const ::std::string&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<NetworkGraphBuilderIce> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<NetworkGraphBuilderIce*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<NetworkGraphBuilderIce*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

}

namespace IceDelegate
{

namespace rebecca
{

namespace impl
{

class CallBacksIce : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void storeGossip(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void categoryLoaded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void filePreLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void filePostLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void symbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void infiniteSymbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void XMLParseError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void XMLParseWarning(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void XMLParseFatalError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void thatStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void topicStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void starTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void inputTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void inputTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void starTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void thatTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void thatTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void topicStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void thatStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void learnTagFileNotFound(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;
};

class NetworkGraphBuilderIce : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void addFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void addFileUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void addDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void addDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void addDirectoryUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void addString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setAddStringAIMLHeader(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setAddStringAIMLFooter(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setAIMLSchema(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setCommonTypesSchema(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setAIMLValidation(bool, const ::Ice::Context*) = 0;

    virtual ::std::string getResponse(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void createGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual bool predicateMatch(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getPreviousBotResponse(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getPreviousUserInput(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setBotConfigurationSchema(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setBotConfigurationValidation(bool, const ::Ice::Context*) = 0;

    virtual void parseSubstitutionFile(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void parseSentenceSplitterFile(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void parsePropertiesFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setSentenceSplitter(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setInputSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setGenderSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setPersonSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setPerson2Substitution(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getVersion(const ::Ice::Context*) = 0;

    virtual ::Ice::Int getSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setCallBacks(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void storeGossip(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string getId(const ::Ice::Context*) = 0;

    virtual void addCustomTagLibrary(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeCustomTagLibrary(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string callSystemCommand(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void synchronizeDatabase(const ::Ice::Context*) = 0;

    virtual ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getAIMLFileListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getAIMLStringListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::rebecca::impl::StringSeq getUserIds(const ::Ice::Context*) = 0;

    virtual ::Ice::Int getUserIdsSize(const ::Ice::Context*) = 0;

    virtual ::rebecca::impl::StringSeq getBotIds(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getBotIdsSize(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::rebecca::impl::StringSeq getEndUserIds(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getEndUserIdsSize(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void printEntireDatabase(const ::Ice::Context*) = 0;

    virtual ::rebecca::impl::StringSeq getBotPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::rebecca::impl::StringSeq getPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getBotPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removePredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeEndUser(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeBot(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeUser(const ::std::string&, const ::Ice::Context*) = 0;
};

}

}

}

namespace IceDelegateM
{

namespace rebecca
{

namespace impl
{

class CallBacksIce : virtual public ::IceDelegate::rebecca::impl::CallBacksIce,
                     virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void storeGossip(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void categoryLoaded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void filePreLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void filePostLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void symbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void infiniteSymbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void XMLParseError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void XMLParseWarning(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void XMLParseFatalError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void topicStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void starTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void inputTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void inputTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void starTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void topicStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void learnTagFileNotFound(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class NetworkGraphBuilderIce : virtual public ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce,
                               virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void addFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addFileUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectoryUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setAddStringAIMLHeader(const ::std::string&, const ::Ice::Context*);

    virtual void setAddStringAIMLFooter(const ::std::string&, const ::Ice::Context*);

    virtual void setAIMLSchema(const ::std::string&, const ::Ice::Context*);

    virtual void setCommonTypesSchema(const ::std::string&, const ::Ice::Context*);

    virtual void setAIMLValidation(bool, const ::Ice::Context*);

    virtual ::std::string getResponse(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void createGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual bool predicateMatch(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getPreviousBotResponse(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getPreviousUserInput(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setBotConfigurationSchema(const ::std::string&, const ::Ice::Context*);

    virtual void setBotConfigurationValidation(bool, const ::Ice::Context*);

    virtual void parseSubstitutionFile(const ::std::string&, const ::Ice::Context*);

    virtual void parseSentenceSplitterFile(const ::std::string&, const ::Ice::Context*);

    virtual void parsePropertiesFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setSentenceSplitter(const ::std::string&, const ::Ice::Context*);

    virtual void setInputSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setGenderSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setPersonSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setPerson2Substitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getVersion(const ::Ice::Context*);

    virtual ::Ice::Int getSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setCallBacks(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void storeGossip(const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getId(const ::Ice::Context*);

    virtual void addCustomTagLibrary(const ::std::string&, const ::Ice::Context*);

    virtual void removeCustomTagLibrary(const ::std::string&, const ::Ice::Context*);

    virtual ::std::string callSystemCommand(const ::std::string&, const ::Ice::Context*);

    virtual void synchronizeDatabase(const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getAIMLFileListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getAIMLStringListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getUserIds(const ::Ice::Context*);

    virtual ::Ice::Int getUserIdsSize(const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getBotIds(const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getBotIdsSize(const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getEndUserIds(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getEndUserIdsSize(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void printEntireDatabase(const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getBotPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getBotPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removePredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeEndUser(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeBot(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeUser(const ::std::string&, const ::Ice::Context*);
};

}

}

}

namespace IceDelegateD
{

namespace rebecca
{

namespace impl
{

class CallBacksIce : virtual public ::IceDelegate::rebecca::impl::CallBacksIce,
                     virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void storeGossip(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void categoryLoaded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void filePreLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void filePostLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void symbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void infiniteSymbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void XMLParseError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void XMLParseWarning(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void XMLParseFatalError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void topicStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void starTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void inputTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void inputTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void starTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void topicStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void thatStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void learnTagFileNotFound(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);
};

class NetworkGraphBuilderIce : virtual public ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce,
                               virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void addFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addFileUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectoryUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void addString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setAddStringAIMLHeader(const ::std::string&, const ::Ice::Context*);

    virtual void setAddStringAIMLFooter(const ::std::string&, const ::Ice::Context*);

    virtual void setAIMLSchema(const ::std::string&, const ::Ice::Context*);

    virtual void setCommonTypesSchema(const ::std::string&, const ::Ice::Context*);

    virtual void setAIMLValidation(bool, const ::Ice::Context*);

    virtual ::std::string getResponse(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void createGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual bool predicateMatch(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getPreviousBotResponse(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getPreviousUserInput(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setBotConfigurationSchema(const ::std::string&, const ::Ice::Context*);

    virtual void setBotConfigurationValidation(bool, const ::Ice::Context*);

    virtual void parseSubstitutionFile(const ::std::string&, const ::Ice::Context*);

    virtual void parseSentenceSplitterFile(const ::std::string&, const ::Ice::Context*);

    virtual void parsePropertiesFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setSentenceSplitter(const ::std::string&, const ::Ice::Context*);

    virtual void setInputSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setGenderSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setPersonSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setPerson2Substitution(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getVersion(const ::Ice::Context*);

    virtual ::Ice::Int getSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setCallBacks(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void storeGossip(const ::std::string&, const ::Ice::Context*);

    virtual ::std::string getId(const ::Ice::Context*);

    virtual void addCustomTagLibrary(const ::std::string&, const ::Ice::Context*);

    virtual void removeCustomTagLibrary(const ::std::string&, const ::Ice::Context*);

    virtual ::std::string callSystemCommand(const ::std::string&, const ::Ice::Context*);

    virtual void synchronizeDatabase(const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getAIMLFileListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getAIMLStringListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getUserIds(const ::Ice::Context*);

    virtual ::Ice::Int getUserIdsSize(const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getBotIds(const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getBotIdsSize(const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getEndUserIds(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getEndUserIdsSize(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void printEntireDatabase(const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getBotPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::rebecca::impl::StringSeq getPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getBotPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int getPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removePredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeEndUser(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeBot(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void removeUser(const ::std::string&, const ::Ice::Context*);
};

}

}

}

namespace rebecca
{

namespace impl
{

class CallBacksIce : virtual public ::Ice::Object
{
public:

    typedef CallBacksIcePrx ProxyType;
    typedef CallBacksIcePtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void storeGossip(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___storeGossip(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void categoryLoaded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___categoryLoaded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void filePreLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___filePreLoad(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void filePostLoad(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___filePostLoad(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void symbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___symbolicReduction(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void infiniteSymbolicReduction(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___infiniteSymbolicReduction(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void XMLParseError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___XMLParseError(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void XMLParseWarning(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___XMLParseWarning(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void XMLParseFatalError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___XMLParseFatalError(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void thatStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___thatStarTagSizeExceeded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void topicStarTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___topicStarTagSizeExceeded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void starTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___starTagSizeExceeded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void inputTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___inputTagNumericConversionError(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void inputTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___inputTagSizeExceeded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void starTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___starTagNumericConversionError(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void thatTagSizeExceeded(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___thatTagSizeExceeded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void thatTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___thatTagNumericConversionError(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void topicStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___topicStarTagNumericConversionError(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void thatStarTagNumericConversionError(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___thatStarTagNumericConversionError(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void learnTagFileNotFound(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___learnTagFileNotFound(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class NetworkGraphBuilderIce : virtual public ::Ice::Object
{
public:

    typedef NetworkGraphBuilderIcePrx ProxyType;
    typedef NetworkGraphBuilderIcePtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void addFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addFile(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addFileUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addFileUnlessAlreadyAdded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeFile(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addDirectory(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addDirectoryWithFilesEndingInRegularExpression(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addDirectoryUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addDirectoryUnlessAlreadyAdded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeDirectory(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeDirectory(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeDirectoryWithFilesEndingInRegularExpression(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeDirectoryWithFilesEndingInRegularExpression(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addString(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeString(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeString(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setAddStringAIMLHeader(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setAddStringAIMLHeader(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setAddStringAIMLFooter(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setAddStringAIMLFooter(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setAIMLSchema(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setAIMLSchema(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setCommonTypesSchema(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setCommonTypesSchema(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setAIMLValidation(bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setAIMLValidation(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getResponse(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getResponse(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setThat(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setTopic(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getThat(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getThat(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::std::string getTopic(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getTopic(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void createGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___createGraph(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeGraph(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeGraph(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool predicateMatch(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___predicateMatch(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void setPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setPredicate(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getPredicate(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::std::string getBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getBotPredicate(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void setBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setBotPredicate(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getPreviousBotResponse(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getPreviousBotResponse(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::std::string getPreviousUserInput(::Ice::Int, ::Ice::Int, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getPreviousUserInput(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void setBotConfigurationSchema(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setBotConfigurationSchema(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setBotConfigurationValidation(bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setBotConfigurationValidation(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void parseSubstitutionFile(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___parseSubstitutionFile(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void parseSentenceSplitterFile(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___parseSentenceSplitterFile(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void parsePropertiesFile(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___parsePropertiesFile(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setSentenceSplitter(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setSentenceSplitter(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setInputSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setInputSubstitution(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setGenderSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setGenderSubstitution(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setPersonSubstitution(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setPersonSubstitution(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setPerson2Substitution(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setPerson2Substitution(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getVersion(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getVersion(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void setCallBacks(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setCallBacks(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void storeGossip(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___storeGossip(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getId(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getId(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void addCustomTagLibrary(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addCustomTagLibrary(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeCustomTagLibrary(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeCustomTagLibrary(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string callSystemCommand(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___callSystemCommand(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void synchronizeDatabase(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___synchronizeDatabase(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::rebecca::impl::StringSeq getAIMLFileList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getAIMLFileList(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getAIMLFileListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getAIMLFileListSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::rebecca::impl::StringSeq getAIMLStringList(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getAIMLStringList(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getAIMLStringListSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getAIMLStringListSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::rebecca::impl::StringSeq getUserIds(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getUserIds(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getUserIdsSize(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getUserIdsSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::rebecca::impl::StringSeq getBotIds(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getBotIds(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getBotIdsSize(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getBotIdsSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::rebecca::impl::StringSeq getEndUserIds(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getEndUserIds(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getEndUserIdsSize(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getEndUserIdsSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void printEntireDatabase(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___printEntireDatabase(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::rebecca::impl::StringSeq getBotPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getBotPredicates(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::rebecca::impl::StringSeq getPredicates(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getPredicates(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getBotPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getBotPredicatesSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getPredicatesSize(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___getPredicatesSize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void removePredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removePredicate(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeBotPredicate(const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeBotPredicate(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeEndUser(const ::std::string&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeEndUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeBot(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeBot(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeUser(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

}

}

#endif
