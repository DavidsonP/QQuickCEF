#include "QtBridgeV8Handler.h"

QtBridgeV8Handler::QtBridgeV8Handler() {}
bool QtBridgeV8Handler::Execute(const CefString& name,
             CefRefPtr<CefV8Value> object,
             const CefV8ValueList& arguments,
             CefRefPtr<CefV8Value>& retval,
             CefString& exception) {
    if (name == "postMessage" && arguments.size() >= 2) {
        // Send IPC message to browser process
        auto msg = CefProcessMessage::Create("cef_to_qt");
        auto args = msg->GetArgumentList();
        args->SetString(0, arguments[0]->GetStringValue()); // channel
        args->SetString(1, arguments[1]->GetStringValue()); // payload
        CefV8Context::GetCurrentContext()->GetFrame()->SendProcessMessage(
            PID_BROWSER, msg);
        return true;
    }
    return false;
}
