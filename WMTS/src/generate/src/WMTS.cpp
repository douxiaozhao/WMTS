// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.0
//
// <auto-generated>
//
// Generated from file `WMTS.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <WMTS.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __WMTSMODULE__WMTS__GetCapabilities_name = "GetCapabilities";

const ::std::string __WMTSMODULE__WMTS__GetTile_name = "GetTile";

const ::std::string __WMTSMODULE__WMTS__GetFeatureInfo_name = "GetFeatureInfo";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::WMTSMODULE::upCast(::IceProxy::WMTSMODULE::WMTS* p) { return p; }

void
::IceProxy::WMTSMODULE::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::WMTSMODULE::WMTS>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::WMTSMODULE::WMTS;
        v->__copyFrom(proxy);
    }
}

::OWSMODULE::OWSTask
IceProxy::WMTSMODULE::WMTS::GetCapabilities(const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __WMTSMODULE__WMTS__GetCapabilities_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__WMTSMODULE__WMTS__GetCapabilities_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::WMTSMODULE::WMTS* __del = dynamic_cast< ::IceDelegate::WMTSMODULE::WMTS*>(__delBase.get());
            return __del->GetCapabilities(__ctx, __observer);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::WMTSMODULE::WMTS::begin_GetCapabilities(const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__WMTSMODULE__WMTS__GetCapabilities_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __WMTSMODULE__WMTS__GetCapabilities_name, __del, __cookie);
    try
    {
        __result->__prepare(__WMTSMODULE__WMTS__GetCapabilities_name, ::Ice::Normal, __ctx);
        __result->__writeEmptyParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

::OWSMODULE::OWSTask
IceProxy::WMTSMODULE::WMTS::end_GetCapabilities(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __WMTSMODULE__WMTS__GetCapabilities_name);
    ::OWSMODULE::OWSTask __ret;
    bool __ok = __result->__wait();
    try
    {
        if(!__ok)
        {
            try
            {
                __result->__throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::IceInternal::BasicStream* __is = __result->__startReadParams();
        __is->read(__ret);
        __result->__endReadParams();
        return __ret;
    }
    catch(const ::Ice::LocalException& ex)
    {
        __result->__getObserver().failed(ex.ice_name());
        throw;
    }
}

::OWSMODULE::OWSTask
IceProxy::WMTSMODULE::WMTS::GetTile(const ::WMTSMODULE::GetTileParameter& parameter, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __WMTSMODULE__WMTS__GetTile_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__WMTSMODULE__WMTS__GetTile_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::WMTSMODULE::WMTS* __del = dynamic_cast< ::IceDelegate::WMTSMODULE::WMTS*>(__delBase.get());
            return __del->GetTile(parameter, __ctx, __observer);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::WMTSMODULE::WMTS::begin_GetTile(const ::WMTSMODULE::GetTileParameter& parameter, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__WMTSMODULE__WMTS__GetTile_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __WMTSMODULE__WMTS__GetTile_name, __del, __cookie);
    try
    {
        __result->__prepare(__WMTSMODULE__WMTS__GetTile_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(parameter);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

::OWSMODULE::OWSTask
IceProxy::WMTSMODULE::WMTS::end_GetTile(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __WMTSMODULE__WMTS__GetTile_name);
    ::OWSMODULE::OWSTask __ret;
    bool __ok = __result->__wait();
    try
    {
        if(!__ok)
        {
            try
            {
                __result->__throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::IceInternal::BasicStream* __is = __result->__startReadParams();
        __is->read(__ret);
        __result->__endReadParams();
        return __ret;
    }
    catch(const ::Ice::LocalException& ex)
    {
        __result->__getObserver().failed(ex.ice_name());
        throw;
    }
}

::OWSMODULE::OWSTask
IceProxy::WMTSMODULE::WMTS::GetFeatureInfo(const ::WMTSMODULE::GetTileParameter& parameter, ::Ice::Int I, ::Ice::Int J, const ::std::string& information, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __WMTSMODULE__WMTS__GetFeatureInfo_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__WMTSMODULE__WMTS__GetFeatureInfo_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::WMTSMODULE::WMTS* __del = dynamic_cast< ::IceDelegate::WMTSMODULE::WMTS*>(__delBase.get());
            return __del->GetFeatureInfo(parameter, I, J, information, __ctx, __observer);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::WMTSMODULE::WMTS::begin_GetFeatureInfo(const ::WMTSMODULE::GetTileParameter& parameter, ::Ice::Int I, ::Ice::Int J, const ::std::string& information, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__WMTSMODULE__WMTS__GetFeatureInfo_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __WMTSMODULE__WMTS__GetFeatureInfo_name, __del, __cookie);
    try
    {
        __result->__prepare(__WMTSMODULE__WMTS__GetFeatureInfo_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(parameter);
        __os->write(I);
        __os->write(J);
        __os->write(information);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

::OWSMODULE::OWSTask
IceProxy::WMTSMODULE::WMTS::end_GetFeatureInfo(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __WMTSMODULE__WMTS__GetFeatureInfo_name);
    ::OWSMODULE::OWSTask __ret;
    bool __ok = __result->__wait();
    try
    {
        if(!__ok)
        {
            try
            {
                __result->__throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::IceInternal::BasicStream* __is = __result->__startReadParams();
        __is->read(__ret);
        __result->__endReadParams();
        return __ret;
    }
    catch(const ::Ice::LocalException& ex)
    {
        __result->__getObserver().failed(ex.ice_name());
        throw;
    }
}

const ::std::string&
IceProxy::WMTSMODULE::WMTS::ice_staticId()
{
    return ::WMTSMODULE::WMTS::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::WMTSMODULE::WMTS::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::WMTSMODULE::WMTS);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::WMTSMODULE::WMTS::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::WMTSMODULE::WMTS);
}

::IceProxy::Ice::Object*
IceProxy::WMTSMODULE::WMTS::__newInstance() const
{
    return new WMTS;
}

::OWSMODULE::OWSTask
IceDelegateM::WMTSMODULE::WMTS::GetCapabilities(const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __WMTSMODULE__WMTS__GetCapabilities_name, ::Ice::Normal, __context, __observer);
    __og.writeEmptyParams();
    bool __ok = __og.invoke();
    ::OWSMODULE::OWSTask __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.startReadParams();
        __is->read(__ret);
        __og.endReadParams();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::OWSMODULE::OWSTask
IceDelegateM::WMTSMODULE::WMTS::GetTile(const ::WMTSMODULE::GetTileParameter& parameter, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __WMTSMODULE__WMTS__GetTile_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(parameter);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::OWSMODULE::OWSTask __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.startReadParams();
        __is->read(__ret);
        __og.endReadParams();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::OWSMODULE::OWSTask
IceDelegateM::WMTSMODULE::WMTS::GetFeatureInfo(const ::WMTSMODULE::GetTileParameter& parameter, ::Ice::Int I, ::Ice::Int J, const ::std::string& information, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __WMTSMODULE__WMTS__GetFeatureInfo_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(parameter);
        __os->write(I);
        __os->write(J);
        __os->write(information);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::OWSMODULE::OWSTask __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.startReadParams();
        __is->read(__ret);
        __og.endReadParams();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::OWSMODULE::OWSTask
IceDelegateD::WMTSMODULE::WMTS::GetCapabilities(const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::OWSMODULE::OWSTask& __result, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::WMTSMODULE::WMTS* servant = dynamic_cast< ::WMTSMODULE::WMTS*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->GetCapabilities(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::OWSMODULE::OWSTask& _result;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __WMTSMODULE__WMTS__GetCapabilities_name, ::Ice::Normal, __context);
    ::OWSMODULE::OWSTask __result;
    try
    {
        _DirectI __direct(__result, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::OWSMODULE::OWSTask
IceDelegateD::WMTSMODULE::WMTS::GetTile(const ::WMTSMODULE::GetTileParameter& parameter, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::OWSMODULE::OWSTask& __result, const ::WMTSMODULE::GetTileParameter& __p_parameter, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_parameter(__p_parameter)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::WMTSMODULE::WMTS* servant = dynamic_cast< ::WMTSMODULE::WMTS*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->GetTile(_m_parameter, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::OWSMODULE::OWSTask& _result;
        const ::WMTSMODULE::GetTileParameter& _m_parameter;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __WMTSMODULE__WMTS__GetTile_name, ::Ice::Normal, __context);
    ::OWSMODULE::OWSTask __result;
    try
    {
        _DirectI __direct(__result, parameter, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::OWSMODULE::OWSTask
IceDelegateD::WMTSMODULE::WMTS::GetFeatureInfo(const ::WMTSMODULE::GetTileParameter& parameter, ::Ice::Int I, ::Ice::Int J, const ::std::string& information, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::OWSMODULE::OWSTask& __result, const ::WMTSMODULE::GetTileParameter& __p_parameter, ::Ice::Int __p_I, ::Ice::Int __p_J, const ::std::string& __p_information, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_parameter(__p_parameter),
            _m_I(__p_I),
            _m_J(__p_J),
            _m_information(__p_information)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::WMTSMODULE::WMTS* servant = dynamic_cast< ::WMTSMODULE::WMTS*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->GetFeatureInfo(_m_parameter, _m_I, _m_J, _m_information, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::OWSMODULE::OWSTask& _result;
        const ::WMTSMODULE::GetTileParameter& _m_parameter;
        ::Ice::Int _m_I;
        ::Ice::Int _m_J;
        const ::std::string& _m_information;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __WMTSMODULE__WMTS__GetFeatureInfo_name, ::Ice::Normal, __context);
    ::OWSMODULE::OWSTask __result;
    try
    {
        _DirectI __direct(__result, parameter, I, J, information, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Object* WMTSMODULE::upCast(::WMTSMODULE::WMTS* p) { return p; }

namespace
{
const ::std::string __WMTSMODULE__WMTS_ids[3] =
{
    "::Ice::Object",
    "::OWSMODULE::DataOperation",
    "::WMTSMODULE::WMTS"
};

}

bool
WMTSMODULE::WMTS::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__WMTSMODULE__WMTS_ids, __WMTSMODULE__WMTS_ids + 3, _s);
}

::std::vector< ::std::string>
WMTSMODULE::WMTS::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__WMTSMODULE__WMTS_ids[0], &__WMTSMODULE__WMTS_ids[3]);
}

const ::std::string&
WMTSMODULE::WMTS::ice_id(const ::Ice::Current&) const
{
    return __WMTSMODULE__WMTS_ids[2];
}

const ::std::string&
WMTSMODULE::WMTS::ice_staticId()
{
    return __WMTSMODULE__WMTS_ids[2];
}

::Ice::DispatchStatus
WMTSMODULE::WMTS::___GetCapabilities(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.readEmptyParams();
    ::OWSMODULE::OWSTask __ret = GetCapabilities(__current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
WMTSMODULE::WMTS::___GetTile(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::WMTSMODULE::GetTileParameter parameter;
    __is->read(parameter);
    __inS.endReadParams();
    ::OWSMODULE::OWSTask __ret = GetTile(parameter, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
WMTSMODULE::WMTS::___GetFeatureInfo(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::WMTSMODULE::GetTileParameter parameter;
    ::Ice::Int I;
    ::Ice::Int J;
    ::std::string information;
    __is->read(parameter);
    __is->read(I);
    __is->read(J);
    __is->read(information);
    __inS.endReadParams();
    ::OWSMODULE::OWSTask __ret = GetFeatureInfo(parameter, I, J, information, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __WMTSMODULE__WMTS_all[] =
{
    "CheckState",
    "GetCapabilities",
    "GetFeatureInfo",
    "GetTile",
    "ReadData",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "shutdown"
};

}

::Ice::DispatchStatus
WMTSMODULE::WMTS::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__WMTSMODULE__WMTS_all, __WMTSMODULE__WMTS_all + 10, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __WMTSMODULE__WMTS_all)
    {
        case 0:
        {
            return ___CheckState(in, current);
        }
        case 1:
        {
            return ___GetCapabilities(in, current);
        }
        case 2:
        {
            return ___GetFeatureInfo(in, current);
        }
        case 3:
        {
            return ___GetTile(in, current);
        }
        case 4:
        {
            return ___ReadData(in, current);
        }
        case 5:
        {
            return ___ice_id(in, current);
        }
        case 6:
        {
            return ___ice_ids(in, current);
        }
        case 7:
        {
            return ___ice_isA(in, current);
        }
        case 8:
        {
            return ___ice_ping(in, current);
        }
        case 9:
        {
            return ___shutdown(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
WMTSMODULE::WMTS::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
WMTSMODULE::WMTS::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
WMTSMODULE::__patch(WMTSPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::WMTSMODULE::WMTSPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::WMTSMODULE::WMTS::ice_staticId(), v);
    }
}
