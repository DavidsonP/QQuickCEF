#ifndef CEFAPPHANDLER_H
#define CEFAPPHANDLER_H

#include "cef_app.h"
#include "QtBridgeV8Handler.h"

class CefAppHandler : public CefApp, public CefRenderProcessHandler
{
private:
    QtBridgeV8Handler handler;

public:
    CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;
    void OnContextCreated(CefRefPtr<CefBrowser>, CefRefPtr<CefFrame>, CefRefPtr<CefV8Context> context) override;
    CefAppHandler();

    IMPLEMENT_REFCOUNTING(CefAppHandler);
};

#endif // CEFAPPHANDLER_H
