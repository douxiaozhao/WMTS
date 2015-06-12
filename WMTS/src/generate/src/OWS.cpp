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
// Generated from file `OWS.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <OWS.h>
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

const ::std::string __OWSMODULE__DataOperation__CheckState_name = "CheckState";

const ::std::string __OWSMODULE__DataOperation__ReadData_name = "ReadData";

const ::std::string __OWSMODULE__DataOperation__shutdown_name = "shutdown";

}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::OWSMODULE::upCast(::IceProxy::OWSMODULE::DataOperation* p) { return p; }

void
::IceProxy::OWSMODULE::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::OWSMODULE::DataOperation>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::OWSMODULE::DataOperation;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::OWSMODULE::DataOperation::CheckState(const ::std::string& taskID, ::OWSMODULE::OWSTask& task, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __OWSMODULE__DataOperation__CheckState_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__OWSMODULE__DataOperation__CheckState_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::OWSMODULE::DataOperation* __del = dynamic_cast< ::IceDelegate::OWSMODULE::DataOperation*>(__delBase.get());
            __del->CheckState(taskID, task, __ctx, __observer);
            return;
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
IceProxy::OWSMODULE::DataOperation::begin_CheckState(const ::std::string& taskID, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__OWSMODULE__DataOperation__CheckState_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __OWSMODULE__DataOperation__CheckState_name, __del, __cookie);
    try
    {
        __result->__prepare(__OWSMODULE__DataOperation__CheckState_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(taskID);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::OWSMODULE::DataOperation::end_CheckState(::OWSMODULE::OWSTask& task, const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __OWSMODULE__DataOperation__CheckState_name);
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
        __is->read(task);
        __result->__endReadParams();
    }
    catch(const ::Ice::LocalException& ex)
    {
        __result->__getObserver().failed(ex.ice_name());
        throw;
    }
}

::Ice::Int
IceProxy::OWSMODULE::DataOperation::ReadData(const ::std::string& taskID, ::OWSMODULE::byteSeq& DataBlock, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __OWSMODULE__DataOperation__ReadData_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__OWSMODULE__DataOperation__ReadData_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::OWSMODULE::DataOperation* __del = dynamic_cast< ::IceDelegate::OWSMODULE::DataOperation*>(__delBase.get());
            return __del->ReadData(taskID, DataBlock, __ctx, __observer);
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
IceProxy::OWSMODULE::DataOperation::begin_ReadData(const ::std::string& taskID, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__OWSMODULE__DataOperation__ReadData_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __OWSMODULE__DataOperation__ReadData_name, __del, __cookie);
    try
    {
        __result->__prepare(__OWSMODULE__DataOperation__ReadData_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__startWriteParams(::Ice::DefaultFormat);
        __os->write(taskID);
        __result->__endWriteParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

::Ice::Int
IceProxy::OWSMODULE::DataOperation::end_ReadData(::OWSMODULE::byteSeq& DataBlock, const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __OWSMODULE__DataOperation__ReadData_name);
    ::Ice::Int __ret;
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
        __is->read(DataBlock);
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

void
IceProxy::OWSMODULE::DataOperation::shutdown(const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __OWSMODULE__DataOperation__shutdown_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::OWSMODULE::DataOperation* __del = dynamic_cast< ::IceDelegate::OWSMODULE::DataOperation*>(__delBase.get());
            __del->shutdown(__ctx, __observer);
            return;
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
IceProxy::OWSMODULE::DataOperation::begin_shutdown(const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __OWSMODULE__DataOperation__shutdown_name, __del, __cookie);
    try
    {
        __result->__prepare(__OWSMODULE__DataOperation__shutdown_name, ::Ice::Normal, __ctx);
        __result->__writeEmptyParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::OWSMODULE::DataOperation::end_shutdown(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __OWSMODULE__DataOperation__shutdown_name);
}

const ::std::string&
IceProxy::OWSMODULE::DataOperation::ice_staticId()
{
    return ::OWSMODULE::DataOperation::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::OWSMODULE::DataOperation::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::OWSMODULE::DataOperation);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::OWSMODULE::DataOperation::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::OWSMODULE::DataOperation);
}

::IceProxy::Ice::Object*
IceProxy::OWSMODULE::DataOperation::__newInstance() const
{
    return new DataOperation;
}

void
IceDelegateM::OWSMODULE::DataOperation::CheckState(const ::std::string& taskID, ::OWSMODULE::OWSTask& task, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __OWSMODULE__DataOperation__CheckState_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(taskID);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
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
        __is->read(task);
        __og.endReadParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::OWSMODULE::DataOperation::ReadData(const ::std::string& taskID, ::OWSMODULE::byteSeq& DataBlock, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __OWSMODULE__DataOperation__ReadData_name, ::Ice::Normal, __context, __observer);
    try
    {
        ::IceInternal::BasicStream* __os = __og.startWriteParams(::Ice::DefaultFormat);
        __os->write(taskID);
        __og.endWriteParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
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
        __is->read(DataBlock);
        __is->read(__ret);
        __og.endReadParams();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::OWSMODULE::DataOperation::shutdown(const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __OWSMODULE__DataOperation__shutdown_name, ::Ice::Normal, __context, __observer);
    __og.writeEmptyParams();
    bool __ok = __og.invoke();
    if(__og.hasResponse())
    {
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
            __og.readEmptyParams();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateD::OWSMODULE::DataOperation::CheckState(const ::std::string& taskID, ::OWSMODULE::OWSTask& task, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::std::string& __p_taskID, ::OWSMODULE::OWSTask& __p_task, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_taskID(__p_taskID),
            _m_task(__p_task)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::OWSMODULE::DataOperation* servant = dynamic_cast< ::OWSMODULE::DataOperation*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->CheckState(_m_taskID, _m_task, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::std::string& _m_taskID;
        ::OWSMODULE::OWSTask& _m_task;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __OWSMODULE__DataOperation__CheckState_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(taskID, task, __current);
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
}

::Ice::Int
IceDelegateD::OWSMODULE::DataOperation::ReadData(const ::std::string& taskID, ::OWSMODULE::byteSeq& DataBlock, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::std::string& __p_taskID, ::OWSMODULE::byteSeq& __p_DataBlock, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_taskID(__p_taskID),
            _m_DataBlock(__p_DataBlock)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::OWSMODULE::DataOperation* servant = dynamic_cast< ::OWSMODULE::DataOperation*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->ReadData(_m_taskID, _m_DataBlock, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        const ::std::string& _m_taskID;
        ::OWSMODULE::byteSeq& _m_DataBlock;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __OWSMODULE__DataOperation__ReadData_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, taskID, DataBlock, __current);
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

void
IceDelegateD::OWSMODULE::DataOperation::shutdown(const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::OWSMODULE::DataOperation* servant = dynamic_cast< ::OWSMODULE::DataOperation*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->shutdown(_current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __OWSMODULE__DataOperation__shutdown_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(__current);
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
}

::Ice::Object* OWSMODULE::upCast(::OWSMODULE::DataOperation* p) { return p; }

namespace
{
const ::std::string __OWSMODULE__DataOperation_ids[2] =
{
    "::Ice::Object",
    "::OWSMODULE::DataOperation"
};

}

bool
OWSMODULE::DataOperation::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__OWSMODULE__DataOperation_ids, __OWSMODULE__DataOperation_ids + 2, _s);
}

::std::vector< ::std::string>
OWSMODULE::DataOperation::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__OWSMODULE__DataOperation_ids[0], &__OWSMODULE__DataOperation_ids[2]);
}

const ::std::string&
OWSMODULE::DataOperation::ice_id(const ::Ice::Current&) const
{
    return __OWSMODULE__DataOperation_ids[1];
}

const ::std::string&
OWSMODULE::DataOperation::ice_staticId()
{
    return __OWSMODULE__DataOperation_ids[1];
}

::Ice::DispatchStatus
OWSMODULE::DataOperation::___CheckState(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::std::string taskID;
    __is->read(taskID);
    __inS.endReadParams();
    ::OWSMODULE::OWSTask task;
    CheckState(taskID, task, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(task);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
OWSMODULE::DataOperation::___ReadData(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.startReadParams();
    ::std::string taskID;
    __is->read(taskID);
    __inS.endReadParams();
    ::OWSMODULE::byteSeq DataBlock;
    ::Ice::Int __ret = ReadData(taskID, DataBlock, __current);
    ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
    __os->write(DataBlock);
    __os->write(__ret);
    __inS.__endWriteParams(true);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
OWSMODULE::DataOperation::___shutdown(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.readEmptyParams();
    shutdown(__current);
    __inS.__writeEmptyParams();
    return ::Ice::DispatchOK;
}

namespace
{
const ::std::string __OWSMODULE__DataOperation_all[] =
{
    "CheckState",
    "ReadData",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "shutdown"
};

}

::Ice::DispatchStatus
OWSMODULE::DataOperation::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__OWSMODULE__DataOperation_all, __OWSMODULE__DataOperation_all + 7, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __OWSMODULE__DataOperation_all)
    {
        case 0:
        {
            return ___CheckState(in, current);
        }
        case 1:
        {
            return ___ReadData(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
        case 6:
        {
            return ___shutdown(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
OWSMODULE::DataOperation::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
OWSMODULE::DataOperation::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
OWSMODULE::__patch(DataOperationPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::OWSMODULE::DataOperationPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::OWSMODULE::DataOperation::ice_staticId(), v);
    }
}