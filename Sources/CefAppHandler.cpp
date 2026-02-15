#include "CefAppHandler.h"

CefRefPtr<CefRenderProcessHandler> CefAppHandler::GetRenderProcessHandler() {
    return this;
}

// Inject window.qt object into every new JS context (every page/frame)
void CefAppHandler::OnContextCreated(CefRefPtr<CefBrowser>,
                      CefRefPtr<CefFrame>,
                      CefRefPtr<CefV8Context> context)
{
    CefRefPtr<CefV8Value> global = context->GetGlobal();

    // Create window.qt = { postMessage: function(channel, payload){} }
    CefRefPtr<CefV8Value> qtObj = CefV8Value::CreateObject(nullptr, nullptr);
    CefRefPtr<CefV8Value> func = CefV8Value::CreateFunction("postMessage", &this->handler);
    qtObj->SetValue("postMessage", func, V8_PROPERTY_ATTRIBUTE_READONLY);
    global->SetValue("qt", qtObj, V8_PROPERTY_ATTRIBUTE_READONLY);
}

CefAppHandler::CefAppHandler(){}
