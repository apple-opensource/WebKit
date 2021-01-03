/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#if USE(PLUGIN_HOST_PROCESS)

#ifndef ProxyRuntimeObject_h
#define ProxyRuntimeObject_h

#include <WebCore/JSDOMBinding.h>
#include <WebCore/runtime_object.h>

namespace WebKit {

class ProxyInstance;

class ProxyRuntimeObject final : public JSC::Bindings::RuntimeObject {
public:
    using Base = JSC::Bindings::RuntimeObject;

    static ProxyRuntimeObject* create(JSC::VM& vm, JSC::Structure* structure, Ref<ProxyInstance>&& instance)
    {
        ProxyRuntimeObject* object = new (JSC::allocateCell<ProxyRuntimeObject>(vm.heap)) ProxyRuntimeObject(vm, structure, WTFMove(instance));
        object->finishCreation(vm);
        return object;
    }

    ProxyInstance* getInternalProxyInstance() const;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    DECLARE_INFO;

private:
    ProxyRuntimeObject(JSC::VM&, JSC::Structure*, Ref<ProxyInstance>&&);
    void finishCreation(JSC::VM&);
};

}

#endif
#endif
