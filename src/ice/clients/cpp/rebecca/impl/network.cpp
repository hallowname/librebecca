// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `network.ice'

#include <../../rebecca/impl/network.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 302
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

static const ::std::string __rebecca__impl__CallBacksIce__storeGossip_name = "storeGossip";

static const ::std::string __rebecca__impl__CallBacksIce__categoryLoaded_name = "categoryLoaded";

static const ::std::string __rebecca__impl__CallBacksIce__filePreLoad_name = "filePreLoad";

static const ::std::string __rebecca__impl__CallBacksIce__filePostLoad_name = "filePostLoad";

static const ::std::string __rebecca__impl__CallBacksIce__symbolicReduction_name = "symbolicReduction";

static const ::std::string __rebecca__impl__CallBacksIce__infiniteSymbolicReduction_name = "infiniteSymbolicReduction";

static const ::std::string __rebecca__impl__CallBacksIce__XMLParseError_name = "XMLParseError";

static const ::std::string __rebecca__impl__CallBacksIce__XMLParseWarning_name = "XMLParseWarning";

static const ::std::string __rebecca__impl__CallBacksIce__XMLParseFatalError_name = "XMLParseFatalError";

static const ::std::string __rebecca__impl__CallBacksIce__thatStarTagSizeExceeded_name = "thatStarTagSizeExceeded";

static const ::std::string __rebecca__impl__CallBacksIce__topicStarTagSizeExceeded_name = "topicStarTagSizeExceeded";

static const ::std::string __rebecca__impl__CallBacksIce__starTagSizeExceeded_name = "starTagSizeExceeded";

static const ::std::string __rebecca__impl__CallBacksIce__inputTagNumericConversionError_name = "inputTagNumericConversionError";

static const ::std::string __rebecca__impl__CallBacksIce__inputTagSizeExceeded_name = "inputTagSizeExceeded";

static const ::std::string __rebecca__impl__CallBacksIce__starTagNumericConversionError_name = "starTagNumericConversionError";

static const ::std::string __rebecca__impl__CallBacksIce__thatTagSizeExceeded_name = "thatTagSizeExceeded";

static const ::std::string __rebecca__impl__CallBacksIce__thatTagNumericConversionError_name = "thatTagNumericConversionError";

static const ::std::string __rebecca__impl__CallBacksIce__topicStarTagNumericConversionError_name = "topicStarTagNumericConversionError";

static const ::std::string __rebecca__impl__CallBacksIce__thatStarTagNumericConversionError_name = "thatStarTagNumericConversionError";

static const ::std::string __rebecca__impl__CallBacksIce__learnTagFileNotFound_name = "learnTagFileNotFound";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addFile_name = "addFile";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addFileUnlessAlreadyAdded_name = "addFileUnlessAlreadyAdded";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeFile_name = "removeFile";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addDirectory_name = "addDirectory";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpression_name = "addDirectoryWithFilesEndingInRegularExpression";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addDirectoryUnlessAlreadyAdded_name = "addDirectoryUnlessAlreadyAdded";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded_name = "addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeDirectory_name = "removeDirectory";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeDirectoryWithFilesEndingInRegularExpression_name = "removeDirectoryWithFilesEndingInRegularExpression";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addString_name = "addString";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeString_name = "removeString";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLHeader_name = "setAddStringAIMLHeader";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLFooter_name = "setAddStringAIMLFooter";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setAIMLSchema_name = "setAIMLSchema";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setCommonTypesSchema_name = "setCommonTypesSchema";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setAIMLValidation_name = "setAIMLValidation";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getResponse_name = "getResponse";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setThat_name = "setThat";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setTopic_name = "setTopic";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getThat_name = "getThat";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getTopic_name = "getTopic";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__createGraph_name = "createGraph";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeGraph_name = "removeGraph";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__predicateMatch_name = "predicateMatch";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setPredicate_name = "setPredicate";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getPredicate_name = "getPredicate";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getBotPredicate_name = "getBotPredicate";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setBotPredicate_name = "setBotPredicate";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getPreviousBotResponse_name = "getPreviousBotResponse";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getPreviousUserInput_name = "getPreviousUserInput";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationSchema_name = "setBotConfigurationSchema";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationValidation_name = "setBotConfigurationValidation";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__parseSubstitutionFile_name = "parseSubstitutionFile";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__parseSentenceSplitterFile_name = "parseSentenceSplitterFile";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__parsePropertiesFile_name = "parsePropertiesFile";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setSentenceSplitter_name = "setSentenceSplitter";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setInputSubstitution_name = "setInputSubstitution";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setGenderSubstitution_name = "setGenderSubstitution";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setPersonSubstitution_name = "setPersonSubstitution";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setPerson2Substitution_name = "setPerson2Substitution";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getVersion_name = "getVersion";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getSize_name = "getSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__setCallBacks_name = "setCallBacks";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__storeGossip_name = "storeGossip";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getId_name = "getId";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__addCustomTagLibrary_name = "addCustomTagLibrary";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeCustomTagLibrary_name = "removeCustomTagLibrary";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__callSystemCommand_name = "callSystemCommand";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__synchronizeDatabase_name = "synchronizeDatabase";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getAIMLFileList_name = "getAIMLFileList";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getAIMLFileListSize_name = "getAIMLFileListSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getAIMLStringList_name = "getAIMLStringList";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getAIMLStringListSize_name = "getAIMLStringListSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getUserIds_name = "getUserIds";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getUserIdsSize_name = "getUserIdsSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getBotIds_name = "getBotIds";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getBotIdsSize_name = "getBotIdsSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getEndUserIds_name = "getEndUserIds";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getEndUserIdsSize_name = "getEndUserIdsSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__printEntireDatabase_name = "printEntireDatabase";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getBotPredicates_name = "getBotPredicates";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getPredicates_name = "getPredicates";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getBotPredicatesSize_name = "getBotPredicatesSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__getPredicatesSize_name = "getPredicatesSize";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removePredicate_name = "removePredicate";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeBotPredicate_name = "removeBotPredicate";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeEndUser_name = "removeEndUser";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeBot_name = "removeBot";

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce__removeUser_name = "removeUser";

void
IceInternal::incRef(::rebecca::impl::CallBacksIce* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::rebecca::impl::CallBacksIce* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::rebecca::impl::CallBacksIce* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::rebecca::impl::CallBacksIce* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::rebecca::impl::NetworkGraphBuilderIce* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::rebecca::impl::NetworkGraphBuilderIce* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::rebecca::impl::NetworkGraphBuilderIce* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::rebecca::impl::NetworkGraphBuilderIce* p)
{
    p->__decRef();
}

void
rebecca::impl::__write(::IceInternal::BasicStream* __os, const ::rebecca::impl::CallBacksIcePrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
rebecca::impl::__read(::IceInternal::BasicStream* __is, ::rebecca::impl::CallBacksIcePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::rebecca::impl::CallBacksIce;
        v->__copyFrom(proxy);
    }
}

void
rebecca::impl::__write(::IceInternal::BasicStream* __os, const ::rebecca::impl::CallBacksIcePtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
rebecca::impl::__write(::IceInternal::BasicStream* __os, const ::rebecca::impl::NetworkGraphBuilderIcePrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
rebecca::impl::__read(::IceInternal::BasicStream* __is, ::rebecca::impl::NetworkGraphBuilderIcePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::rebecca::impl::NetworkGraphBuilderIce;
        v->__copyFrom(proxy);
    }
}

void
rebecca::impl::__write(::IceInternal::BasicStream* __os, const ::rebecca::impl::NetworkGraphBuilderIcePtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
rebecca::impl::__addObject(const CallBacksIcePtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
rebecca::impl::__usesClasses(const CallBacksIcePtr& p)
{
    return p->__usesClasses();
}

void
rebecca::impl::__decRefUnsafe(const CallBacksIcePtr& p)
{
    p->__decRefUnsafe();
}

void
rebecca::impl::__clearHandleUnsafe(CallBacksIcePtr& p)
{
    p.__clearHandleUnsafe();
}

rebecca::impl::ExceptionIce::ExceptionIce(const ::std::string& __ice_what) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    UserException(),
#else
    ::Ice::UserException(),
#endif
    what(__ice_what)
{
}

rebecca::impl::ExceptionIce::~ExceptionIce() throw()
{
}

static const char* __rebecca__impl__ExceptionIce_name = "rebecca::impl::ExceptionIce";

::std::string
rebecca::impl::ExceptionIce::ice_name() const
{
    return __rebecca__impl__ExceptionIce_name;
}

::Ice::Exception*
rebecca::impl::ExceptionIce::ice_clone() const
{
    return new ExceptionIce(*this);
}

void
rebecca::impl::ExceptionIce::ice_throw() const
{
    throw *this;
}

void
rebecca::impl::ExceptionIce::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::rebecca::impl::ExceptionIce"), false);
    __os->startWriteSlice();
    __os->write(what);
    __os->endWriteSlice();
}

void
rebecca::impl::ExceptionIce::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(what);
    __is->endReadSlice();
}

void
rebecca::impl::ExceptionIce::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::ExceptionIce was not generated with stream support";
    throw ex;
}

void
rebecca::impl::ExceptionIce::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::ExceptionIce was not generated with stream support";
    throw ex;
}

struct __F__rebecca__impl__ExceptionIce : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::rebecca::impl::ExceptionIce();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__rebecca__impl__ExceptionIce__Ptr = new __F__rebecca__impl__ExceptionIce;

const ::IceInternal::UserExceptionFactoryPtr&
rebecca::impl::ExceptionIce::ice_factory()
{
    return __F__rebecca__impl__ExceptionIce__Ptr;
}

class __F__rebecca__impl__ExceptionIce__Init
{
public:

    __F__rebecca__impl__ExceptionIce__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::rebecca::impl::ExceptionIce", ::rebecca::impl::ExceptionIce::ice_factory());
    }

    ~__F__rebecca__impl__ExceptionIce__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::rebecca::impl::ExceptionIce");
    }
};

static __F__rebecca__impl__ExceptionIce__Init __F__rebecca__impl__ExceptionIce__i;

#ifdef __APPLE__
extern "C" { void __F__rebecca__impl__ExceptionIce__initializer() {} }
#endif

rebecca::impl::FileNotFoundExceptionIce::FileNotFoundExceptionIce(const ::std::string& __ice_what) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce(__ice_what)
#else
    ::rebecca::impl::ExceptionIce(__ice_what)
#endif
{
}

rebecca::impl::FileNotFoundExceptionIce::~FileNotFoundExceptionIce() throw()
{
}

static const char* __rebecca__impl__FileNotFoundExceptionIce_name = "rebecca::impl::FileNotFoundExceptionIce";

::std::string
rebecca::impl::FileNotFoundExceptionIce::ice_name() const
{
    return __rebecca__impl__FileNotFoundExceptionIce_name;
}

::Ice::Exception*
rebecca::impl::FileNotFoundExceptionIce::ice_clone() const
{
    return new FileNotFoundExceptionIce(*this);
}

void
rebecca::impl::FileNotFoundExceptionIce::ice_throw() const
{
    throw *this;
}

void
rebecca::impl::FileNotFoundExceptionIce::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::rebecca::impl::FileNotFoundExceptionIce"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__write(__os);
#else
    ::rebecca::impl::ExceptionIce::__write(__os);
#endif
}

void
rebecca::impl::FileNotFoundExceptionIce::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__read(__is, true);
#else
    ::rebecca::impl::ExceptionIce::__read(__is, true);
#endif
}

void
rebecca::impl::FileNotFoundExceptionIce::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::FileNotFoundExceptionIce was not generated with stream support";
    throw ex;
}

void
rebecca::impl::FileNotFoundExceptionIce::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::FileNotFoundExceptionIce was not generated with stream support";
    throw ex;
}

struct __F__rebecca__impl__FileNotFoundExceptionIce : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::rebecca::impl::FileNotFoundExceptionIce();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__rebecca__impl__FileNotFoundExceptionIce__Ptr = new __F__rebecca__impl__FileNotFoundExceptionIce;

const ::IceInternal::UserExceptionFactoryPtr&
rebecca::impl::FileNotFoundExceptionIce::ice_factory()
{
    return __F__rebecca__impl__FileNotFoundExceptionIce__Ptr;
}

class __F__rebecca__impl__FileNotFoundExceptionIce__Init
{
public:

    __F__rebecca__impl__FileNotFoundExceptionIce__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::rebecca::impl::FileNotFoundExceptionIce", ::rebecca::impl::FileNotFoundExceptionIce::ice_factory());
    }

    ~__F__rebecca__impl__FileNotFoundExceptionIce__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::rebecca::impl::FileNotFoundExceptionIce");
    }
};

static __F__rebecca__impl__FileNotFoundExceptionIce__Init __F__rebecca__impl__FileNotFoundExceptionIce__i;

#ifdef __APPLE__
extern "C" { void __F__rebecca__impl__FileNotFoundExceptionIce__initializer() {} }
#endif

rebecca::impl::IllegalArgumentExceptionIce::IllegalArgumentExceptionIce(const ::std::string& __ice_what) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce(__ice_what)
#else
    ::rebecca::impl::ExceptionIce(__ice_what)
#endif
{
}

rebecca::impl::IllegalArgumentExceptionIce::~IllegalArgumentExceptionIce() throw()
{
}

static const char* __rebecca__impl__IllegalArgumentExceptionIce_name = "rebecca::impl::IllegalArgumentExceptionIce";

::std::string
rebecca::impl::IllegalArgumentExceptionIce::ice_name() const
{
    return __rebecca__impl__IllegalArgumentExceptionIce_name;
}

::Ice::Exception*
rebecca::impl::IllegalArgumentExceptionIce::ice_clone() const
{
    return new IllegalArgumentExceptionIce(*this);
}

void
rebecca::impl::IllegalArgumentExceptionIce::ice_throw() const
{
    throw *this;
}

void
rebecca::impl::IllegalArgumentExceptionIce::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::rebecca::impl::IllegalArgumentExceptionIce"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__write(__os);
#else
    ::rebecca::impl::ExceptionIce::__write(__os);
#endif
}

void
rebecca::impl::IllegalArgumentExceptionIce::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__read(__is, true);
#else
    ::rebecca::impl::ExceptionIce::__read(__is, true);
#endif
}

void
rebecca::impl::IllegalArgumentExceptionIce::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::IllegalArgumentExceptionIce was not generated with stream support";
    throw ex;
}

void
rebecca::impl::IllegalArgumentExceptionIce::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::IllegalArgumentExceptionIce was not generated with stream support";
    throw ex;
}

struct __F__rebecca__impl__IllegalArgumentExceptionIce : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::rebecca::impl::IllegalArgumentExceptionIce();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__rebecca__impl__IllegalArgumentExceptionIce__Ptr = new __F__rebecca__impl__IllegalArgumentExceptionIce;

const ::IceInternal::UserExceptionFactoryPtr&
rebecca::impl::IllegalArgumentExceptionIce::ice_factory()
{
    return __F__rebecca__impl__IllegalArgumentExceptionIce__Ptr;
}

class __F__rebecca__impl__IllegalArgumentExceptionIce__Init
{
public:

    __F__rebecca__impl__IllegalArgumentExceptionIce__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::rebecca::impl::IllegalArgumentExceptionIce", ::rebecca::impl::IllegalArgumentExceptionIce::ice_factory());
    }

    ~__F__rebecca__impl__IllegalArgumentExceptionIce__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::rebecca::impl::IllegalArgumentExceptionIce");
    }
};

static __F__rebecca__impl__IllegalArgumentExceptionIce__Init __F__rebecca__impl__IllegalArgumentExceptionIce__i;

#ifdef __APPLE__
extern "C" { void __F__rebecca__impl__IllegalArgumentExceptionIce__initializer() {} }
#endif

rebecca::impl::DirectoryNotFoundExceptionIce::DirectoryNotFoundExceptionIce(const ::std::string& __ice_what) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce(__ice_what)
#else
    ::rebecca::impl::ExceptionIce(__ice_what)
#endif
{
}

rebecca::impl::DirectoryNotFoundExceptionIce::~DirectoryNotFoundExceptionIce() throw()
{
}

static const char* __rebecca__impl__DirectoryNotFoundExceptionIce_name = "rebecca::impl::DirectoryNotFoundExceptionIce";

::std::string
rebecca::impl::DirectoryNotFoundExceptionIce::ice_name() const
{
    return __rebecca__impl__DirectoryNotFoundExceptionIce_name;
}

::Ice::Exception*
rebecca::impl::DirectoryNotFoundExceptionIce::ice_clone() const
{
    return new DirectoryNotFoundExceptionIce(*this);
}

void
rebecca::impl::DirectoryNotFoundExceptionIce::ice_throw() const
{
    throw *this;
}

void
rebecca::impl::DirectoryNotFoundExceptionIce::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::rebecca::impl::DirectoryNotFoundExceptionIce"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__write(__os);
#else
    ::rebecca::impl::ExceptionIce::__write(__os);
#endif
}

void
rebecca::impl::DirectoryNotFoundExceptionIce::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__read(__is, true);
#else
    ::rebecca::impl::ExceptionIce::__read(__is, true);
#endif
}

void
rebecca::impl::DirectoryNotFoundExceptionIce::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::DirectoryNotFoundExceptionIce was not generated with stream support";
    throw ex;
}

void
rebecca::impl::DirectoryNotFoundExceptionIce::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::DirectoryNotFoundExceptionIce was not generated with stream support";
    throw ex;
}

struct __F__rebecca__impl__DirectoryNotFoundExceptionIce : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::rebecca::impl::DirectoryNotFoundExceptionIce();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__rebecca__impl__DirectoryNotFoundExceptionIce__Ptr = new __F__rebecca__impl__DirectoryNotFoundExceptionIce;

const ::IceInternal::UserExceptionFactoryPtr&
rebecca::impl::DirectoryNotFoundExceptionIce::ice_factory()
{
    return __F__rebecca__impl__DirectoryNotFoundExceptionIce__Ptr;
}

class __F__rebecca__impl__DirectoryNotFoundExceptionIce__Init
{
public:

    __F__rebecca__impl__DirectoryNotFoundExceptionIce__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::rebecca::impl::DirectoryNotFoundExceptionIce", ::rebecca::impl::DirectoryNotFoundExceptionIce::ice_factory());
    }

    ~__F__rebecca__impl__DirectoryNotFoundExceptionIce__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::rebecca::impl::DirectoryNotFoundExceptionIce");
    }
};

static __F__rebecca__impl__DirectoryNotFoundExceptionIce__Init __F__rebecca__impl__DirectoryNotFoundExceptionIce__i;

#ifdef __APPLE__
extern "C" { void __F__rebecca__impl__DirectoryNotFoundExceptionIce__initializer() {} }
#endif

rebecca::impl::XMLErrorExceptionIce::XMLErrorExceptionIce(const ::std::string& __ice_what) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce(__ice_what)
#else
    ::rebecca::impl::ExceptionIce(__ice_what)
#endif
{
}

rebecca::impl::XMLErrorExceptionIce::~XMLErrorExceptionIce() throw()
{
}

static const char* __rebecca__impl__XMLErrorExceptionIce_name = "rebecca::impl::XMLErrorExceptionIce";

::std::string
rebecca::impl::XMLErrorExceptionIce::ice_name() const
{
    return __rebecca__impl__XMLErrorExceptionIce_name;
}

::Ice::Exception*
rebecca::impl::XMLErrorExceptionIce::ice_clone() const
{
    return new XMLErrorExceptionIce(*this);
}

void
rebecca::impl::XMLErrorExceptionIce::ice_throw() const
{
    throw *this;
}

void
rebecca::impl::XMLErrorExceptionIce::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::rebecca::impl::XMLErrorExceptionIce"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__write(__os);
#else
    ::rebecca::impl::ExceptionIce::__write(__os);
#endif
}

void
rebecca::impl::XMLErrorExceptionIce::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    ExceptionIce::__read(__is, true);
#else
    ::rebecca::impl::ExceptionIce::__read(__is, true);
#endif
}

void
rebecca::impl::XMLErrorExceptionIce::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::XMLErrorExceptionIce was not generated with stream support";
    throw ex;
}

void
rebecca::impl::XMLErrorExceptionIce::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception rebecca::impl::XMLErrorExceptionIce was not generated with stream support";
    throw ex;
}

struct __F__rebecca__impl__XMLErrorExceptionIce : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::rebecca::impl::XMLErrorExceptionIce();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__rebecca__impl__XMLErrorExceptionIce__Ptr = new __F__rebecca__impl__XMLErrorExceptionIce;

const ::IceInternal::UserExceptionFactoryPtr&
rebecca::impl::XMLErrorExceptionIce::ice_factory()
{
    return __F__rebecca__impl__XMLErrorExceptionIce__Ptr;
}

class __F__rebecca__impl__XMLErrorExceptionIce__Init
{
public:

    __F__rebecca__impl__XMLErrorExceptionIce__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::rebecca::impl::XMLErrorExceptionIce", ::rebecca::impl::XMLErrorExceptionIce::ice_factory());
    }

    ~__F__rebecca__impl__XMLErrorExceptionIce__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::rebecca::impl::XMLErrorExceptionIce");
    }
};

static __F__rebecca__impl__XMLErrorExceptionIce__Init __F__rebecca__impl__XMLErrorExceptionIce__i;

#ifdef __APPLE__
extern "C" { void __F__rebecca__impl__XMLErrorExceptionIce__initializer() {} }
#endif

void
rebecca::impl::__addObject(const NetworkGraphBuilderIcePtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
rebecca::impl::__usesClasses(const NetworkGraphBuilderIcePtr& p)
{
    return p->__usesClasses();
}

void
rebecca::impl::__decRefUnsafe(const NetworkGraphBuilderIcePtr& p)
{
    p->__decRefUnsafe();
}

void
rebecca::impl::__clearHandleUnsafe(NetworkGraphBuilderIcePtr& p)
{
    p.__clearHandleUnsafe();
}

void
IceProxy::rebecca::impl::CallBacksIce::storeGossip(const ::std::string& gossip, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->storeGossip(gossip, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::categoryLoaded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->categoryLoaded(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::filePreLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->filePreLoad(fileName, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::filePostLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->filePostLoad(fileName, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::symbolicReduction(const ::std::string& symbol, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->symbolicReduction(symbol, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::infiniteSymbolicReduction(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->infiniteSymbolicReduction(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::XMLParseError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->XMLParseError(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::XMLParseWarning(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->XMLParseWarning(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::XMLParseFatalError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->XMLParseFatalError(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::thatStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->thatStarTagSizeExceeded(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::topicStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->topicStarTagSizeExceeded(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::starTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->starTagSizeExceeded(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::inputTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->inputTagNumericConversionError(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::inputTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->inputTagSizeExceeded(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::starTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->starTagNumericConversionError(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::thatTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->thatTagSizeExceeded(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::thatTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->thatTagNumericConversionError(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::topicStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->topicStarTagNumericConversionError(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::thatStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->thatStarTagNumericConversionError(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::CallBacksIce::learnTagFileNotFound(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::CallBacksIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::CallBacksIce*>(__delBase.get());
            __del->learnTagFileNotFound(message, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::rebecca::impl::CallBacksIce::ice_staticId()
{
    return ::rebecca::impl::CallBacksIce::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::rebecca::impl::CallBacksIce::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::rebecca::impl::CallBacksIce);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::rebecca::impl::CallBacksIce::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::rebecca::impl::CallBacksIce);
}

bool
IceProxy::rebecca::impl::operator==(const ::IceProxy::rebecca::impl::CallBacksIce& l, const ::IceProxy::rebecca::impl::CallBacksIce& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::rebecca::impl::operator!=(const ::IceProxy::rebecca::impl::CallBacksIce& l, const ::IceProxy::rebecca::impl::CallBacksIce& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::rebecca::impl::operator<(const ::IceProxy::rebecca::impl::CallBacksIce& l, const ::IceProxy::rebecca::impl::CallBacksIce& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::rebecca::impl::operator<=(const ::IceProxy::rebecca::impl::CallBacksIce& l, const ::IceProxy::rebecca::impl::CallBacksIce& r)
{
    return l < r || l == r;
}

bool
IceProxy::rebecca::impl::operator>(const ::IceProxy::rebecca::impl::CallBacksIce& l, const ::IceProxy::rebecca::impl::CallBacksIce& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::rebecca::impl::operator>=(const ::IceProxy::rebecca::impl::CallBacksIce& l, const ::IceProxy::rebecca::impl::CallBacksIce& r)
{
    return !(l < r);
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addFile_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addFile(file, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addFileUnlessAlreadyAdded(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addFileUnlessAlreadyAdded_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addFileUnlessAlreadyAdded(file, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeFile_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeFile(file, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addDirectory_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addDirectory(directory, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpression_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addDirectoryUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addDirectoryUnlessAlreadyAdded_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addDirectoryUnlessAlreadyAdded(directory, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(directory, regularExpression, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeDirectory_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeDirectory(directory, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeDirectoryWithFilesEndingInRegularExpression_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addString_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addString(stringContainingAIML, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeString_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeString(stringContainingAIML, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setAddStringAIMLHeader(const ::std::string& aimlHeader, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLHeader_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setAddStringAIMLHeader(aimlHeader, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setAddStringAIMLFooter(const ::std::string& aimlFooter, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLFooter_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setAddStringAIMLFooter(aimlFooter, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setAIMLSchema(const ::std::string& schema, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setAIMLSchema_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setAIMLSchema(schema, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setCommonTypesSchema(const ::std::string& schema, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setCommonTypesSchema_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setCommonTypesSchema(schema, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setAIMLValidation(bool trueOrFalse, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setAIMLValidation_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setAIMLValidation(trueOrFalse, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getResponse(const ::std::string& input, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getResponse_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getResponse(input, userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setThat(const ::std::string& that, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setThat_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setThat(that, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setTopic(const ::std::string& topic, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setTopic_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setTopic(topic, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getThat(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getThat_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getThat(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getTopic(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getTopic_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getTopic(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::createGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__createGraph_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->createGraph(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeGraph_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeGraph(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

bool
IceProxy::rebecca::impl::NetworkGraphBuilderIce::predicateMatch(const ::std::string& predicateName, const ::std::string& aimlPattern, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__predicateMatch_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->predicateMatch(predicateName, aimlPattern, userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setPredicate_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setPredicate(name, value, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getPredicate_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getPredicate(name, userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getBotPredicate_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getBotPredicate(name, userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setBotPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setBotPredicate_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setBotPredicate(name, value, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getPreviousBotResponse(::Ice::Int previousBotResponse, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getPreviousBotResponse_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getPreviousBotResponse(previousBotResponse, sentence, userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getPreviousUserInput(::Ice::Int previousUserInput, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getPreviousUserInput_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getPreviousUserInput(previousUserInput, sentence, userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setBotConfigurationSchema(const ::std::string& schema, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationSchema_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setBotConfigurationSchema(schema, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setBotConfigurationValidation(bool trueOrFalse, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationValidation_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setBotConfigurationValidation(trueOrFalse, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::parseSubstitutionFile(const ::std::string& fileName, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__parseSubstitutionFile_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->parseSubstitutionFile(fileName, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::parseSentenceSplitterFile(const ::std::string& fileName, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__parseSentenceSplitterFile_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->parseSentenceSplitterFile(fileName, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::parsePropertiesFile(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__parsePropertiesFile_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->parsePropertiesFile(fileName, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setSentenceSplitter(const ::std::string& splitter, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setSentenceSplitter_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setSentenceSplitter(splitter, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setInputSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setInputSubstitution_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setInputSubstitution(find, replace, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setGenderSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setGenderSubstitution_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setGenderSubstitution(find, replace, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setPersonSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setPersonSubstitution_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setPersonSubstitution(find, replace, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setPerson2Substitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setPerson2Substitution_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setPerson2Substitution(find, replace, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getVersion(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getVersion_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getVersion(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getSize(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::setCallBacks(const ::std::string& name, const ::std::string& category, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__setCallBacks_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->setCallBacks(name, category, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::storeGossip(const ::std::string& gossip, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__storeGossip_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->storeGossip(gossip, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getId(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getId_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getId(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::addCustomTagLibrary(const ::std::string& library, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__addCustomTagLibrary_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->addCustomTagLibrary(library, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeCustomTagLibrary(const ::std::string& library, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeCustomTagLibrary_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeCustomTagLibrary(library, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::std::string
IceProxy::rebecca::impl::NetworkGraphBuilderIce::callSystemCommand(const ::std::string& command, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__callSystemCommand_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->callSystemCommand(command, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::synchronizeDatabase(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__synchronizeDatabase_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->synchronizeDatabase(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::rebecca::impl::StringSeq
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getAIMLFileList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getAIMLFileList_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getAIMLFileList(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getAIMLFileListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getAIMLFileListSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getAIMLFileListSize(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::rebecca::impl::StringSeq
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getAIMLStringList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getAIMLStringList_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getAIMLStringList(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getAIMLStringListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getAIMLStringListSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getAIMLStringListSize(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::rebecca::impl::StringSeq
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getUserIds(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getUserIds_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getUserIds(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getUserIdsSize(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getUserIdsSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getUserIdsSize(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::rebecca::impl::StringSeq
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getBotIds(const ::std::string& userId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getBotIds_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getBotIds(userId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getBotIdsSize(const ::std::string& userId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getBotIdsSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getBotIdsSize(userId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::rebecca::impl::StringSeq
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getEndUserIds(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getEndUserIds_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getEndUserIds(userId, botId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getEndUserIdsSize(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getEndUserIdsSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getEndUserIdsSize(userId, botId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::printEntireDatabase(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__printEntireDatabase_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->printEntireDatabase(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::rebecca::impl::StringSeq
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getBotPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getBotPredicates_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getBotPredicates(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::rebecca::impl::StringSeq
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getPredicates_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getPredicates(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getBotPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getBotPredicatesSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getBotPredicatesSize(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Int
IceProxy::rebecca::impl::NetworkGraphBuilderIce::getPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__getPredicatesSize_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            return __del->getPredicatesSize(userId, botId, endUserId, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removePredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removePredicate_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removePredicate(name, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeBotPredicate_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeBotPredicate(name, userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeEndUser(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeEndUser_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeEndUser(userId, botId, endUserId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeBot(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeBot_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeBot(userId, botId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::rebecca::impl::NetworkGraphBuilderIce::removeUser(const ::std::string& userId, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__rebecca__impl__NetworkGraphBuilderIce__removeUser_name);
            __delBase = __getDelegate();
            ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce* __del = dynamic_cast< ::IceDelegate::rebecca::impl::NetworkGraphBuilderIce*>(__delBase.get());
            __del->removeUser(userId, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::rebecca::impl::NetworkGraphBuilderIce::ice_staticId()
{
    return ::rebecca::impl::NetworkGraphBuilderIce::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::rebecca::impl::NetworkGraphBuilderIce::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::rebecca::impl::NetworkGraphBuilderIce);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::rebecca::impl::NetworkGraphBuilderIce::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::rebecca::impl::NetworkGraphBuilderIce);
}

bool
IceProxy::rebecca::impl::operator==(const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& l, const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::rebecca::impl::operator!=(const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& l, const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::rebecca::impl::operator<(const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& l, const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::rebecca::impl::operator<=(const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& l, const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return l < r || l == r;
}

bool
IceProxy::rebecca::impl::operator>(const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& l, const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::rebecca::impl::operator>=(const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& l, const ::IceProxy::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return !(l < r);
}

void
IceDelegateM::rebecca::impl::CallBacksIce::storeGossip(const ::std::string& gossip, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__storeGossip_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(gossip);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::categoryLoaded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__categoryLoaded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::filePreLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__filePreLoad_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(fileName);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::filePostLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__filePostLoad_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(fileName);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::symbolicReduction(const ::std::string& symbol, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__symbolicReduction_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(symbol);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::infiniteSymbolicReduction(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__infiniteSymbolicReduction_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::XMLParseError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__XMLParseError_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::XMLParseWarning(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__XMLParseWarning_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::XMLParseFatalError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__XMLParseFatalError_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::thatStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__thatStarTagSizeExceeded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::topicStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__topicStarTagSizeExceeded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::starTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__starTagSizeExceeded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::inputTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__inputTagNumericConversionError_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::inputTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__inputTagSizeExceeded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::starTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__starTagNumericConversionError_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::thatTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__thatTagSizeExceeded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::thatTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__thatTagNumericConversionError_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::topicStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__topicStarTagNumericConversionError_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::thatStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__thatStarTagNumericConversionError_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::CallBacksIce::learnTagFileNotFound(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__CallBacksIce__learnTagFileNotFound_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(message);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addFile_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(file);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addFileUnlessAlreadyAdded(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addFileUnlessAlreadyAdded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(file);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeFile_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(file);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addDirectory_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(directory);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpression_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(directory);
        __os->write(regularExpression);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addDirectoryUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addDirectoryUnlessAlreadyAdded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(directory);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(directory);
        __os->write(regularExpression);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeDirectory_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(directory);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeDirectoryWithFilesEndingInRegularExpression_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(directory);
        __os->write(regularExpression);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addString_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(stringContainingAIML);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeString_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(stringContainingAIML);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setAddStringAIMLHeader(const ::std::string& aimlHeader, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLHeader_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(aimlHeader);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setAddStringAIMLFooter(const ::std::string& aimlFooter, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLFooter_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(aimlFooter);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setAIMLSchema(const ::std::string& schema, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setAIMLSchema_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(schema);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setCommonTypesSchema(const ::std::string& schema, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setCommonTypesSchema_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(schema);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setAIMLValidation(bool trueOrFalse, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setAIMLValidation_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(trueOrFalse);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getResponse(const ::std::string& input, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getResponse_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(input);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setThat(const ::std::string& that, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setThat_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(that);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setTopic(const ::std::string& topic, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setTopic_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(topic);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getThat(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getThat_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getTopic(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getTopic_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::createGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__createGraph_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::XMLErrorExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeGraph_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::XMLErrorExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::predicateMatch(const ::std::string& predicateName, const ::std::string& aimlPattern, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__predicateMatch_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(predicateName);
        __os->write(aimlPattern);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        bool __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setPredicate_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(value);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getPredicate_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getBotPredicate_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setBotPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setBotPredicate_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(value);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getPreviousBotResponse(::Ice::Int previousBotResponse, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getPreviousBotResponse_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(previousBotResponse);
        __os->write(sentence);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getPreviousUserInput(::Ice::Int previousUserInput, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getPreviousUserInput_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(previousUserInput);
        __os->write(sentence);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setBotConfigurationSchema(const ::std::string& schema, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationSchema_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(schema);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setBotConfigurationValidation(bool trueOrFalse, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationValidation_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(trueOrFalse);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::parseSubstitutionFile(const ::std::string& fileName, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__parseSubstitutionFile_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(fileName);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::XMLErrorExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::parseSentenceSplitterFile(const ::std::string& fileName, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__parseSentenceSplitterFile_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(fileName);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::XMLErrorExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::parsePropertiesFile(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__parsePropertiesFile_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(fileName);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::XMLErrorExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setSentenceSplitter(const ::std::string& splitter, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setSentenceSplitter_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(splitter);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setInputSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setInputSubstitution_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(find);
        __os->write(replace);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setGenderSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setGenderSubstitution_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(find);
        __os->write(replace);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setPersonSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setPersonSubstitution_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(find);
        __os->write(replace);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setPerson2Substitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setPerson2Substitution_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(find);
        __os->write(replace);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::IllegalArgumentExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getVersion(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getVersion_name, ::Ice::Idempotent, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getSize_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::setCallBacks(const ::std::string& name, const ::std::string& category, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__setCallBacks_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(category);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::storeGossip(const ::std::string& gossip, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__storeGossip_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(gossip);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getId(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getId_name, ::Ice::Idempotent, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::addCustomTagLibrary(const ::std::string& library, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__addCustomTagLibrary_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(library);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeCustomTagLibrary(const ::std::string& library, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeCustomTagLibrary_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(library);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::FileNotFoundExceptionIce&)
            {
                throw;
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::callSystemCommand(const ::std::string& command, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__callSystemCommand_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(command);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::std::string __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::synchronizeDatabase(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__synchronizeDatabase_name, ::Ice::Normal, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rebecca::impl::StringSeq
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getAIMLFileList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getAIMLFileList_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::rebecca::impl::StringSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getAIMLFileListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getAIMLFileListSize_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rebecca::impl::StringSeq
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getAIMLStringList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getAIMLStringList_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::rebecca::impl::StringSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getAIMLStringListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getAIMLStringListSize_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rebecca::impl::StringSeq
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getUserIds(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getUserIds_name, ::Ice::Idempotent, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::rebecca::impl::StringSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getUserIdsSize(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getUserIdsSize_name, ::Ice::Idempotent, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rebecca::impl::StringSeq
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getBotIds(const ::std::string& userId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getBotIds_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::rebecca::impl::StringSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getBotIdsSize(const ::std::string& userId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getBotIdsSize_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rebecca::impl::StringSeq
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getEndUserIds(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getEndUserIds_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::rebecca::impl::StringSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getEndUserIdsSize(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getEndUserIdsSize_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::printEntireDatabase(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__printEntireDatabase_name, ::Ice::Idempotent, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rebecca::impl::StringSeq
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getBotPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getBotPredicates_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::rebecca::impl::StringSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::rebecca::impl::StringSeq
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getPredicates_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::rebecca::impl::StringSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getBotPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getBotPredicatesSize_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::getPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__getPredicatesSize_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Int __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removePredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removePredicate_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeBotPredicate_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeEndUser(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeEndUser_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
        __os->write(endUserId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeBot(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeBot_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
        __os->write(botId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::rebecca::impl::NetworkGraphBuilderIce::removeUser(const ::std::string& userId, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __rebecca__impl__NetworkGraphBuilderIce__removeUser_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userId);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::rebecca::impl::ExceptionIce&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::storeGossip(const ::std::string& gossip, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__storeGossip_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->storeGossip(gossip, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::categoryLoaded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__categoryLoaded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->categoryLoaded(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::filePreLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__filePreLoad_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->filePreLoad(fileName, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::filePostLoad(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__filePostLoad_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->filePostLoad(fileName, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::symbolicReduction(const ::std::string& symbol, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__symbolicReduction_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->symbolicReduction(symbol, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::infiniteSymbolicReduction(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__infiniteSymbolicReduction_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->infiniteSymbolicReduction(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::XMLParseError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__XMLParseError_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->XMLParseError(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::XMLParseWarning(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__XMLParseWarning_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->XMLParseWarning(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::XMLParseFatalError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__XMLParseFatalError_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->XMLParseFatalError(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::thatStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__thatStarTagSizeExceeded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->thatStarTagSizeExceeded(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::topicStarTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__topicStarTagSizeExceeded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->topicStarTagSizeExceeded(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::starTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__starTagSizeExceeded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->starTagSizeExceeded(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::inputTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__inputTagNumericConversionError_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->inputTagNumericConversionError(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::inputTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__inputTagSizeExceeded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->inputTagSizeExceeded(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::starTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__starTagNumericConversionError_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->starTagNumericConversionError(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::thatTagSizeExceeded(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__thatTagSizeExceeded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->thatTagSizeExceeded(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::thatTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__thatTagNumericConversionError_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->thatTagNumericConversionError(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::topicStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__topicStarTagNumericConversionError_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->topicStarTagNumericConversionError(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::thatStarTagNumericConversionError(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__thatStarTagNumericConversionError_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->thatStarTagNumericConversionError(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::CallBacksIce::learnTagFileNotFound(const ::std::string& message, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__CallBacksIce__learnTagFileNotFound_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::CallBacksIce* __servant = dynamic_cast< ::rebecca::impl::CallBacksIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->learnTagFileNotFound(message, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addFile_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addFile(file, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addFileUnlessAlreadyAdded(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addFileUnlessAlreadyAdded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addFileUnlessAlreadyAdded(file, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeFile(const ::std::string& file, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeFile_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeFile(file, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addDirectory_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addDirectory(directory, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpression_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addDirectoryUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addDirectoryUnlessAlreadyAdded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addDirectoryUnlessAlreadyAdded(directory, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(directory, regularExpression, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeDirectory(const ::std::string& directory, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeDirectory_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeDirectory(directory, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeDirectoryWithFilesEndingInRegularExpression(const ::std::string& directory, const ::std::string& regularExpression, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeDirectoryWithFilesEndingInRegularExpression_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addString_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addString(stringContainingAIML, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeString(const ::std::string& stringContainingAIML, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeString_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeString(stringContainingAIML, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setAddStringAIMLHeader(const ::std::string& aimlHeader, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLHeader_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setAddStringAIMLHeader(aimlHeader, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setAddStringAIMLFooter(const ::std::string& aimlFooter, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setAddStringAIMLFooter_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setAddStringAIMLFooter(aimlFooter, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setAIMLSchema(const ::std::string& schema, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setAIMLSchema_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setAIMLSchema(schema, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setCommonTypesSchema(const ::std::string& schema, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setCommonTypesSchema_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setCommonTypesSchema(schema, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setAIMLValidation(bool trueOrFalse, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setAIMLValidation_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setAIMLValidation(trueOrFalse, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getResponse(const ::std::string& input, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getResponse_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getResponse(input, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setThat(const ::std::string& that, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setThat_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setThat(that, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setTopic(const ::std::string& topic, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setTopic_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setTopic(topic, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getThat(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getThat_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getThat(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getTopic(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getTopic_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getTopic(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::createGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__createGraph_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->createGraph(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeGraph(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeGraph_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeGraph(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

bool
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::predicateMatch(const ::std::string& predicateName, const ::std::string& aimlPattern, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__predicateMatch_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        bool __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->predicateMatch(predicateName, aimlPattern, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setPredicate_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setPredicate(name, value, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getPredicate_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getPredicate(name, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getBotPredicate_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getBotPredicate(name, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setBotPredicate(const ::std::string& name, const ::std::string& value, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setBotPredicate_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setBotPredicate(name, value, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getPreviousBotResponse(::Ice::Int previousBotResponse, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getPreviousBotResponse_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getPreviousBotResponse(previousBotResponse, sentence, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getPreviousUserInput(::Ice::Int previousUserInput, ::Ice::Int sentence, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getPreviousUserInput_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getPreviousUserInput(previousUserInput, sentence, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setBotConfigurationSchema(const ::std::string& schema, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationSchema_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setBotConfigurationSchema(schema, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setBotConfigurationValidation(bool trueOrFalse, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setBotConfigurationValidation_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setBotConfigurationValidation(trueOrFalse, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::parseSubstitutionFile(const ::std::string& fileName, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__parseSubstitutionFile_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->parseSubstitutionFile(fileName, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::parseSentenceSplitterFile(const ::std::string& fileName, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__parseSentenceSplitterFile_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->parseSentenceSplitterFile(fileName, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::parsePropertiesFile(const ::std::string& fileName, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__parsePropertiesFile_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->parsePropertiesFile(fileName, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setSentenceSplitter(const ::std::string& splitter, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setSentenceSplitter_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setSentenceSplitter(splitter, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setInputSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setInputSubstitution_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setInputSubstitution(find, replace, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setGenderSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setGenderSubstitution_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setGenderSubstitution(find, replace, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setPersonSubstitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setPersonSubstitution_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setPersonSubstitution(find, replace, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setPerson2Substitution(const ::std::string& find, const ::std::string& replace, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setPerson2Substitution_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setPerson2Substitution(find, replace, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getVersion(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getVersion_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getVersion(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getSize(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::setCallBacks(const ::std::string& name, const ::std::string& category, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__setCallBacks_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setCallBacks(name, category, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::storeGossip(const ::std::string& gossip, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__storeGossip_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->storeGossip(gossip, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getId(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getId_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getId(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::addCustomTagLibrary(const ::std::string& library, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__addCustomTagLibrary_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addCustomTagLibrary(library, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeCustomTagLibrary(const ::std::string& library, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeCustomTagLibrary_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeCustomTagLibrary(library, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::std::string
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::callSystemCommand(const ::std::string& command, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__callSystemCommand_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::std::string __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->callSystemCommand(command, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::synchronizeDatabase(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__synchronizeDatabase_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->synchronizeDatabase(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::rebecca::impl::StringSeq
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getAIMLFileList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getAIMLFileList_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::rebecca::impl::StringSeq __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getAIMLFileList(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getAIMLFileListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getAIMLFileListSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getAIMLFileListSize(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::rebecca::impl::StringSeq
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getAIMLStringList(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getAIMLStringList_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::rebecca::impl::StringSeq __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getAIMLStringList(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getAIMLStringListSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getAIMLStringListSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getAIMLStringListSize(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::rebecca::impl::StringSeq
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getUserIds(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getUserIds_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::rebecca::impl::StringSeq __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getUserIds(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getUserIdsSize(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getUserIdsSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getUserIdsSize(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::rebecca::impl::StringSeq
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getBotIds(const ::std::string& userId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getBotIds_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::rebecca::impl::StringSeq __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getBotIds(userId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getBotIdsSize(const ::std::string& userId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getBotIdsSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getBotIdsSize(userId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::rebecca::impl::StringSeq
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getEndUserIds(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getEndUserIds_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::rebecca::impl::StringSeq __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getEndUserIds(userId, botId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getEndUserIdsSize(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getEndUserIdsSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getEndUserIdsSize(userId, botId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::printEntireDatabase(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__printEntireDatabase_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->printEntireDatabase(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::rebecca::impl::StringSeq
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getBotPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getBotPredicates_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::rebecca::impl::StringSeq __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getBotPredicates(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::rebecca::impl::StringSeq
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getPredicates(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getPredicates_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::rebecca::impl::StringSeq __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getPredicates(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getBotPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getBotPredicatesSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getBotPredicatesSize(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Int
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::getPredicatesSize(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__getPredicatesSize_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Int __ret;
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getPredicatesSize(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removePredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removePredicate_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removePredicate(name, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeBotPredicate(const ::std::string& name, const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeBotPredicate_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeBotPredicate(name, userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeEndUser(const ::std::string& userId, const ::std::string& botId, const ::std::string& endUserId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeEndUser_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeEndUser(userId, botId, endUserId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeBot(const ::std::string& userId, const ::std::string& botId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeBot_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeBot(userId, botId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::rebecca::impl::NetworkGraphBuilderIce::removeUser(const ::std::string& userId, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __rebecca__impl__NetworkGraphBuilderIce__removeUser_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::rebecca::impl::NetworkGraphBuilderIce* __servant = dynamic_cast< ::rebecca::impl::NetworkGraphBuilderIce*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->removeUser(userId, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::Ice::ObjectPtr
rebecca::impl::CallBacksIce::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __rebecca__impl__CallBacksIce_ids[2] =
{
    "::Ice::Object",
    "::rebecca::impl::CallBacksIce"
};

bool
rebecca::impl::CallBacksIce::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__rebecca__impl__CallBacksIce_ids, __rebecca__impl__CallBacksIce_ids + 2, _s);
}

::std::vector< ::std::string>
rebecca::impl::CallBacksIce::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__rebecca__impl__CallBacksIce_ids[0], &__rebecca__impl__CallBacksIce_ids[2]);
}

const ::std::string&
rebecca::impl::CallBacksIce::ice_id(const ::Ice::Current&) const
{
    return __rebecca__impl__CallBacksIce_ids[1];
}

const ::std::string&
rebecca::impl::CallBacksIce::ice_staticId()
{
    return __rebecca__impl__CallBacksIce_ids[1];
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___storeGossip(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string gossip;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(gossip);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    storeGossip(gossip, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___categoryLoaded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    categoryLoaded(userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___filePreLoad(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string fileName;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(fileName);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    filePreLoad(fileName, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___filePostLoad(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string fileName;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(fileName);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    filePostLoad(fileName, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___symbolicReduction(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string symbol;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(symbol);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    symbolicReduction(symbol, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___infiniteSymbolicReduction(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    infiniteSymbolicReduction(userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___XMLParseError(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    XMLParseError(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___XMLParseWarning(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    XMLParseWarning(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___XMLParseFatalError(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    XMLParseFatalError(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___thatStarTagSizeExceeded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    thatStarTagSizeExceeded(userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___topicStarTagSizeExceeded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    topicStarTagSizeExceeded(userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___starTagSizeExceeded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    starTagSizeExceeded(userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___inputTagNumericConversionError(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    inputTagNumericConversionError(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___inputTagSizeExceeded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    inputTagSizeExceeded(userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___starTagNumericConversionError(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    starTagNumericConversionError(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___thatTagSizeExceeded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    thatTagSizeExceeded(userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___thatTagNumericConversionError(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    thatTagNumericConversionError(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___topicStarTagNumericConversionError(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    topicStarTagNumericConversionError(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___thatStarTagNumericConversionError(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    thatStarTagNumericConversionError(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::___learnTagFileNotFound(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string message;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(message);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    learnTagFileNotFound(message, userId, botId, endUserId, __current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __rebecca__impl__CallBacksIce_all[] =
{
    "XMLParseError",
    "XMLParseFatalError",
    "XMLParseWarning",
    "categoryLoaded",
    "filePostLoad",
    "filePreLoad",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "infiniteSymbolicReduction",
    "inputTagNumericConversionError",
    "inputTagSizeExceeded",
    "learnTagFileNotFound",
    "starTagNumericConversionError",
    "starTagSizeExceeded",
    "storeGossip",
    "symbolicReduction",
    "thatStarTagNumericConversionError",
    "thatStarTagSizeExceeded",
    "thatTagNumericConversionError",
    "thatTagSizeExceeded",
    "topicStarTagNumericConversionError",
    "topicStarTagSizeExceeded"
};

::IceInternal::DispatchStatus
rebecca::impl::CallBacksIce::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__rebecca__impl__CallBacksIce_all, __rebecca__impl__CallBacksIce_all + 24, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __rebecca__impl__CallBacksIce_all)
    {
        case 0:
        {
            return ___XMLParseError(in, current);
        }
        case 1:
        {
            return ___XMLParseFatalError(in, current);
        }
        case 2:
        {
            return ___XMLParseWarning(in, current);
        }
        case 3:
        {
            return ___categoryLoaded(in, current);
        }
        case 4:
        {
            return ___filePostLoad(in, current);
        }
        case 5:
        {
            return ___filePreLoad(in, current);
        }
        case 6:
        {
            return ___ice_id(in, current);
        }
        case 7:
        {
            return ___ice_ids(in, current);
        }
        case 8:
        {
            return ___ice_isA(in, current);
        }
        case 9:
        {
            return ___ice_ping(in, current);
        }
        case 10:
        {
            return ___infiniteSymbolicReduction(in, current);
        }
        case 11:
        {
            return ___inputTagNumericConversionError(in, current);
        }
        case 12:
        {
            return ___inputTagSizeExceeded(in, current);
        }
        case 13:
        {
            return ___learnTagFileNotFound(in, current);
        }
        case 14:
        {
            return ___starTagNumericConversionError(in, current);
        }
        case 15:
        {
            return ___starTagSizeExceeded(in, current);
        }
        case 16:
        {
            return ___storeGossip(in, current);
        }
        case 17:
        {
            return ___symbolicReduction(in, current);
        }
        case 18:
        {
            return ___thatStarTagNumericConversionError(in, current);
        }
        case 19:
        {
            return ___thatStarTagSizeExceeded(in, current);
        }
        case 20:
        {
            return ___thatTagNumericConversionError(in, current);
        }
        case 21:
        {
            return ___thatTagSizeExceeded(in, current);
        }
        case 22:
        {
            return ___topicStarTagNumericConversionError(in, current);
        }
        case 23:
        {
            return ___topicStarTagSizeExceeded(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
rebecca::impl::CallBacksIce::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
rebecca::impl::CallBacksIce::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
rebecca::impl::CallBacksIce::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rebecca::impl::CallBacksIce was not generated with stream support";
    throw ex;
}

void
rebecca::impl::CallBacksIce::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rebecca::impl::CallBacksIce was not generated with stream support";
    throw ex;
}

void 
rebecca::impl::__patch__CallBacksIcePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::rebecca::impl::CallBacksIcePtr* p = static_cast< ::rebecca::impl::CallBacksIcePtr*>(__addr);
    assert(p);
    *p = ::rebecca::impl::CallBacksIcePtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::rebecca::impl::CallBacksIce::ice_staticId();
        throw e;
    }
}

bool
rebecca::impl::operator==(const ::rebecca::impl::CallBacksIce& l, const ::rebecca::impl::CallBacksIce& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
rebecca::impl::operator!=(const ::rebecca::impl::CallBacksIce& l, const ::rebecca::impl::CallBacksIce& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
rebecca::impl::operator<(const ::rebecca::impl::CallBacksIce& l, const ::rebecca::impl::CallBacksIce& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
rebecca::impl::operator<=(const ::rebecca::impl::CallBacksIce& l, const ::rebecca::impl::CallBacksIce& r)
{
    return l < r || l == r;
}

bool
rebecca::impl::operator>(const ::rebecca::impl::CallBacksIce& l, const ::rebecca::impl::CallBacksIce& r)
{
    return !(l < r) && !(l == r);
}

bool
rebecca::impl::operator>=(const ::rebecca::impl::CallBacksIce& l, const ::rebecca::impl::CallBacksIce& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
rebecca::impl::NetworkGraphBuilderIce::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __rebecca__impl__NetworkGraphBuilderIce_ids[2] =
{
    "::Ice::Object",
    "::rebecca::impl::NetworkGraphBuilderIce"
};

bool
rebecca::impl::NetworkGraphBuilderIce::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__rebecca__impl__NetworkGraphBuilderIce_ids, __rebecca__impl__NetworkGraphBuilderIce_ids + 2, _s);
}

::std::vector< ::std::string>
rebecca::impl::NetworkGraphBuilderIce::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__rebecca__impl__NetworkGraphBuilderIce_ids[0], &__rebecca__impl__NetworkGraphBuilderIce_ids[2]);
}

const ::std::string&
rebecca::impl::NetworkGraphBuilderIce::ice_id(const ::Ice::Current&) const
{
    return __rebecca__impl__NetworkGraphBuilderIce_ids[1];
}

const ::std::string&
rebecca::impl::NetworkGraphBuilderIce::ice_staticId()
{
    return __rebecca__impl__NetworkGraphBuilderIce_ids[1];
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addFile(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string file;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(file);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        addFile(file, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addFileUnlessAlreadyAdded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string file;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(file);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        addFileUnlessAlreadyAdded(file, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeFile(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string file;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(file);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removeFile(file, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addDirectory(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string directory;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(directory);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        addDirectory(directory, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addDirectoryWithFilesEndingInRegularExpression(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string directory;
    ::std::string regularExpression;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(directory);
    __is->read(regularExpression);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        addDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addDirectoryUnlessAlreadyAdded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string directory;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(directory);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        addDirectoryUnlessAlreadyAdded(directory, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string directory;
    ::std::string regularExpression;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(directory);
    __is->read(regularExpression);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(directory, regularExpression, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeDirectory(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string directory;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(directory);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removeDirectory(directory, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeDirectoryWithFilesEndingInRegularExpression(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string directory;
    ::std::string regularExpression;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(directory);
    __is->read(regularExpression);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removeDirectoryWithFilesEndingInRegularExpression(directory, regularExpression, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::DirectoryNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addString(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string stringContainingAIML;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(stringContainingAIML);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        addString(stringContainingAIML, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeString(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string stringContainingAIML;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(stringContainingAIML);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removeString(stringContainingAIML, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setAddStringAIMLHeader(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string aimlHeader;
    __is->read(aimlHeader);
    try
    {
        setAddStringAIMLHeader(aimlHeader, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setAddStringAIMLFooter(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string aimlFooter;
    __is->read(aimlFooter);
    try
    {
        setAddStringAIMLFooter(aimlFooter, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setAIMLSchema(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string schema;
    __is->read(schema);
    try
    {
        setAIMLSchema(schema, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setCommonTypesSchema(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string schema;
    __is->read(schema);
    try
    {
        setCommonTypesSchema(schema, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setAIMLValidation(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    bool trueOrFalse;
    __is->read(trueOrFalse);
    try
    {
        setAIMLValidation(trueOrFalse, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getResponse(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string input;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(input);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::std::string __ret = getResponse(input, userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setThat(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string that;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(that);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        setThat(that, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setTopic(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string topic;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(topic);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        setTopic(topic, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getThat(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::std::string __ret = getThat(userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getTopic(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::std::string __ret = getTopic(userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___createGraph(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        createGraph(userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::XMLErrorExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeGraph(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removeGraph(userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::XMLErrorExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___predicateMatch(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string predicateName;
    ::std::string aimlPattern;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(predicateName);
    __is->read(aimlPattern);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        bool __ret = predicateMatch(predicateName, aimlPattern, userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setPredicate(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string value;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(name);
    __is->read(value);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        setPredicate(name, value, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getPredicate(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(name);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::std::string __ret = getPredicate(name, userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getBotPredicate(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(name);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::std::string __ret = getBotPredicate(name, userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setBotPredicate(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string value;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(name);
    __is->read(value);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        setBotPredicate(name, value, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getPreviousBotResponse(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int previousBotResponse;
    ::Ice::Int sentence;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(previousBotResponse);
    __is->read(sentence);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::std::string __ret = getPreviousBotResponse(previousBotResponse, sentence, userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getPreviousUserInput(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int previousUserInput;
    ::Ice::Int sentence;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(previousUserInput);
    __is->read(sentence);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::std::string __ret = getPreviousUserInput(previousUserInput, sentence, userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setBotConfigurationSchema(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string schema;
    __is->read(schema);
    try
    {
        setBotConfigurationSchema(schema, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setBotConfigurationValidation(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    bool trueOrFalse;
    __is->read(trueOrFalse);
    try
    {
        setBotConfigurationValidation(trueOrFalse, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___parseSubstitutionFile(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string fileName;
    __is->read(fileName);
    try
    {
        parseSubstitutionFile(fileName, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::XMLErrorExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___parseSentenceSplitterFile(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string fileName;
    __is->read(fileName);
    try
    {
        parseSentenceSplitterFile(fileName, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::XMLErrorExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___parsePropertiesFile(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string fileName;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(fileName);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        parsePropertiesFile(fileName, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::XMLErrorExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setSentenceSplitter(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string splitter;
    __is->read(splitter);
    try
    {
        setSentenceSplitter(splitter, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setInputSubstitution(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string find;
    ::std::string replace;
    __is->read(find);
    __is->read(replace);
    try
    {
        setInputSubstitution(find, replace, __current);
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setGenderSubstitution(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string find;
    ::std::string replace;
    __is->read(find);
    __is->read(replace);
    try
    {
        setGenderSubstitution(find, replace, __current);
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setPersonSubstitution(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string find;
    ::std::string replace;
    __is->read(find);
    __is->read(replace);
    try
    {
        setPersonSubstitution(find, replace, __current);
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setPerson2Substitution(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string find;
    ::std::string replace;
    __is->read(find);
    __is->read(replace);
    try
    {
        setPerson2Substitution(find, replace, __current);
    }
    catch(const ::rebecca::impl::IllegalArgumentExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getVersion(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        ::std::string __ret = getVersion(__current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::Ice::Int __ret = getSize(userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___setCallBacks(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string category;
    __is->read(name);
    __is->read(category);
    try
    {
        setCallBacks(name, category, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___storeGossip(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string gossip;
    __is->read(gossip);
    try
    {
        storeGossip(gossip, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getId(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        ::std::string __ret = getId(__current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___addCustomTagLibrary(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string library;
    __is->read(library);
    try
    {
        addCustomTagLibrary(library, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeCustomTagLibrary(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string library;
    __is->read(library);
    try
    {
        removeCustomTagLibrary(library, __current);
    }
    catch(const ::rebecca::impl::FileNotFoundExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___callSystemCommand(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string command;
    __is->read(command);
    try
    {
        ::std::string __ret = callSystemCommand(command, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___synchronizeDatabase(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        synchronizeDatabase(__current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getAIMLFileList(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::rebecca::impl::StringSeq __ret = getAIMLFileList(userId, botId, endUserId, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getAIMLFileListSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::Ice::Int __ret = getAIMLFileListSize(userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getAIMLStringList(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::rebecca::impl::StringSeq __ret = getAIMLStringList(userId, botId, endUserId, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getAIMLStringListSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::Ice::Int __ret = getAIMLStringListSize(userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getUserIds(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        ::rebecca::impl::StringSeq __ret = getUserIds(__current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getUserIdsSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        ::Ice::Int __ret = getUserIdsSize(__current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getBotIds(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    __is->read(userId);
    try
    {
        ::rebecca::impl::StringSeq __ret = getBotIds(userId, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getBotIdsSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    __is->read(userId);
    try
    {
        ::Ice::Int __ret = getBotIdsSize(userId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getEndUserIds(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    __is->read(userId);
    __is->read(botId);
    try
    {
        ::rebecca::impl::StringSeq __ret = getEndUserIds(userId, botId, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getEndUserIdsSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    __is->read(userId);
    __is->read(botId);
    try
    {
        ::Ice::Int __ret = getEndUserIdsSize(userId, botId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___printEntireDatabase(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        printEntireDatabase(__current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getBotPredicates(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::rebecca::impl::StringSeq __ret = getBotPredicates(userId, botId, endUserId, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getPredicates(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::rebecca::impl::StringSeq __ret = getPredicates(userId, botId, endUserId, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getBotPredicatesSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::Ice::Int __ret = getBotPredicatesSize(userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___getPredicatesSize(::IceInternal::Incoming&__inS, const ::Ice::Current& __current) const
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        ::Ice::Int __ret = getPredicatesSize(userId, botId, endUserId, __current);
        __os->write(__ret);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removePredicate(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(name);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removePredicate(name, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeBotPredicate(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(name);
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removeBotPredicate(name, userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeEndUser(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    ::std::string endUserId;
    __is->read(userId);
    __is->read(botId);
    __is->read(endUserId);
    try
    {
        removeEndUser(userId, botId, endUserId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeBot(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    ::std::string botId;
    __is->read(userId);
    __is->read(botId);
    try
    {
        removeBot(userId, botId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::___removeUser(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string userId;
    __is->read(userId);
    try
    {
        removeUser(userId, __current);
    }
    catch(const ::rebecca::impl::ExceptionIce& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

static ::std::string __rebecca__impl__NetworkGraphBuilderIce_all[] =
{
    "addCustomTagLibrary",
    "addDirectory",
    "addDirectoryUnlessAlreadyAdded",
    "addDirectoryWithFilesEndingInRegularExpression",
    "addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded",
    "addFile",
    "addFileUnlessAlreadyAdded",
    "addString",
    "callSystemCommand",
    "createGraph",
    "getAIMLFileList",
    "getAIMLFileListSize",
    "getAIMLStringList",
    "getAIMLStringListSize",
    "getBotIds",
    "getBotIdsSize",
    "getBotPredicate",
    "getBotPredicates",
    "getBotPredicatesSize",
    "getEndUserIds",
    "getEndUserIdsSize",
    "getId",
    "getPredicate",
    "getPredicates",
    "getPredicatesSize",
    "getPreviousBotResponse",
    "getPreviousUserInput",
    "getResponse",
    "getSize",
    "getThat",
    "getTopic",
    "getUserIds",
    "getUserIdsSize",
    "getVersion",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "parsePropertiesFile",
    "parseSentenceSplitterFile",
    "parseSubstitutionFile",
    "predicateMatch",
    "printEntireDatabase",
    "removeBot",
    "removeBotPredicate",
    "removeCustomTagLibrary",
    "removeDirectory",
    "removeDirectoryWithFilesEndingInRegularExpression",
    "removeEndUser",
    "removeFile",
    "removeGraph",
    "removePredicate",
    "removeString",
    "removeUser",
    "setAIMLSchema",
    "setAIMLValidation",
    "setAddStringAIMLFooter",
    "setAddStringAIMLHeader",
    "setBotConfigurationSchema",
    "setBotConfigurationValidation",
    "setBotPredicate",
    "setCallBacks",
    "setCommonTypesSchema",
    "setGenderSubstitution",
    "setInputSubstitution",
    "setPerson2Substitution",
    "setPersonSubstitution",
    "setPredicate",
    "setSentenceSplitter",
    "setThat",
    "setTopic",
    "storeGossip",
    "synchronizeDatabase"
};

::IceInternal::DispatchStatus
rebecca::impl::NetworkGraphBuilderIce::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__rebecca__impl__NetworkGraphBuilderIce_all, __rebecca__impl__NetworkGraphBuilderIce_all + 73, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __rebecca__impl__NetworkGraphBuilderIce_all)
    {
        case 0:
        {
            return ___addCustomTagLibrary(in, current);
        }
        case 1:
        {
            return ___addDirectory(in, current);
        }
        case 2:
        {
            return ___addDirectoryUnlessAlreadyAdded(in, current);
        }
        case 3:
        {
            return ___addDirectoryWithFilesEndingInRegularExpression(in, current);
        }
        case 4:
        {
            return ___addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(in, current);
        }
        case 5:
        {
            return ___addFile(in, current);
        }
        case 6:
        {
            return ___addFileUnlessAlreadyAdded(in, current);
        }
        case 7:
        {
            return ___addString(in, current);
        }
        case 8:
        {
            return ___callSystemCommand(in, current);
        }
        case 9:
        {
            return ___createGraph(in, current);
        }
        case 10:
        {
            return ___getAIMLFileList(in, current);
        }
        case 11:
        {
            return ___getAIMLFileListSize(in, current);
        }
        case 12:
        {
            return ___getAIMLStringList(in, current);
        }
        case 13:
        {
            return ___getAIMLStringListSize(in, current);
        }
        case 14:
        {
            return ___getBotIds(in, current);
        }
        case 15:
        {
            return ___getBotIdsSize(in, current);
        }
        case 16:
        {
            return ___getBotPredicate(in, current);
        }
        case 17:
        {
            return ___getBotPredicates(in, current);
        }
        case 18:
        {
            return ___getBotPredicatesSize(in, current);
        }
        case 19:
        {
            return ___getEndUserIds(in, current);
        }
        case 20:
        {
            return ___getEndUserIdsSize(in, current);
        }
        case 21:
        {
            return ___getId(in, current);
        }
        case 22:
        {
            return ___getPredicate(in, current);
        }
        case 23:
        {
            return ___getPredicates(in, current);
        }
        case 24:
        {
            return ___getPredicatesSize(in, current);
        }
        case 25:
        {
            return ___getPreviousBotResponse(in, current);
        }
        case 26:
        {
            return ___getPreviousUserInput(in, current);
        }
        case 27:
        {
            return ___getResponse(in, current);
        }
        case 28:
        {
            return ___getSize(in, current);
        }
        case 29:
        {
            return ___getThat(in, current);
        }
        case 30:
        {
            return ___getTopic(in, current);
        }
        case 31:
        {
            return ___getUserIds(in, current);
        }
        case 32:
        {
            return ___getUserIdsSize(in, current);
        }
        case 33:
        {
            return ___getVersion(in, current);
        }
        case 34:
        {
            return ___ice_id(in, current);
        }
        case 35:
        {
            return ___ice_ids(in, current);
        }
        case 36:
        {
            return ___ice_isA(in, current);
        }
        case 37:
        {
            return ___ice_ping(in, current);
        }
        case 38:
        {
            return ___parsePropertiesFile(in, current);
        }
        case 39:
        {
            return ___parseSentenceSplitterFile(in, current);
        }
        case 40:
        {
            return ___parseSubstitutionFile(in, current);
        }
        case 41:
        {
            return ___predicateMatch(in, current);
        }
        case 42:
        {
            return ___printEntireDatabase(in, current);
        }
        case 43:
        {
            return ___removeBot(in, current);
        }
        case 44:
        {
            return ___removeBotPredicate(in, current);
        }
        case 45:
        {
            return ___removeCustomTagLibrary(in, current);
        }
        case 46:
        {
            return ___removeDirectory(in, current);
        }
        case 47:
        {
            return ___removeDirectoryWithFilesEndingInRegularExpression(in, current);
        }
        case 48:
        {
            return ___removeEndUser(in, current);
        }
        case 49:
        {
            return ___removeFile(in, current);
        }
        case 50:
        {
            return ___removeGraph(in, current);
        }
        case 51:
        {
            return ___removePredicate(in, current);
        }
        case 52:
        {
            return ___removeString(in, current);
        }
        case 53:
        {
            return ___removeUser(in, current);
        }
        case 54:
        {
            return ___setAIMLSchema(in, current);
        }
        case 55:
        {
            return ___setAIMLValidation(in, current);
        }
        case 56:
        {
            return ___setAddStringAIMLFooter(in, current);
        }
        case 57:
        {
            return ___setAddStringAIMLHeader(in, current);
        }
        case 58:
        {
            return ___setBotConfigurationSchema(in, current);
        }
        case 59:
        {
            return ___setBotConfigurationValidation(in, current);
        }
        case 60:
        {
            return ___setBotPredicate(in, current);
        }
        case 61:
        {
            return ___setCallBacks(in, current);
        }
        case 62:
        {
            return ___setCommonTypesSchema(in, current);
        }
        case 63:
        {
            return ___setGenderSubstitution(in, current);
        }
        case 64:
        {
            return ___setInputSubstitution(in, current);
        }
        case 65:
        {
            return ___setPerson2Substitution(in, current);
        }
        case 66:
        {
            return ___setPersonSubstitution(in, current);
        }
        case 67:
        {
            return ___setPredicate(in, current);
        }
        case 68:
        {
            return ___setSentenceSplitter(in, current);
        }
        case 69:
        {
            return ___setThat(in, current);
        }
        case 70:
        {
            return ___setTopic(in, current);
        }
        case 71:
        {
            return ___storeGossip(in, current);
        }
        case 72:
        {
            return ___synchronizeDatabase(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
rebecca::impl::NetworkGraphBuilderIce::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
rebecca::impl::NetworkGraphBuilderIce::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
rebecca::impl::NetworkGraphBuilderIce::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rebecca::impl::NetworkGraphBuilderIce was not generated with stream support";
    throw ex;
}

void
rebecca::impl::NetworkGraphBuilderIce::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type rebecca::impl::NetworkGraphBuilderIce was not generated with stream support";
    throw ex;
}

void 
rebecca::impl::__patch__NetworkGraphBuilderIcePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::rebecca::impl::NetworkGraphBuilderIcePtr* p = static_cast< ::rebecca::impl::NetworkGraphBuilderIcePtr*>(__addr);
    assert(p);
    *p = ::rebecca::impl::NetworkGraphBuilderIcePtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::rebecca::impl::NetworkGraphBuilderIce::ice_staticId();
        throw e;
    }
}

bool
rebecca::impl::operator==(const ::rebecca::impl::NetworkGraphBuilderIce& l, const ::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
rebecca::impl::operator!=(const ::rebecca::impl::NetworkGraphBuilderIce& l, const ::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
rebecca::impl::operator<(const ::rebecca::impl::NetworkGraphBuilderIce& l, const ::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
rebecca::impl::operator<=(const ::rebecca::impl::NetworkGraphBuilderIce& l, const ::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return l < r || l == r;
}

bool
rebecca::impl::operator>(const ::rebecca::impl::NetworkGraphBuilderIce& l, const ::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return !(l < r) && !(l == r);
}

bool
rebecca::impl::operator>=(const ::rebecca::impl::NetworkGraphBuilderIce& l, const ::rebecca::impl::NetworkGraphBuilderIce& r)
{
    return !(l < r);
}
