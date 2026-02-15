#ifndef QTBRIDGEV8HANDLER_H
#define QTBRIDGEV8HANDLER_H
#include "cef_v8.h"

class QtBridgeV8Handler : public CefV8Handler {
public:
    bool Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception) override;
    QtBridgeV8Handler();

    IMPLEMENT_REFCOUNTING(QtBridgeV8Handler);
};
#endif // QTBRIDGEV8HANDLER_H
