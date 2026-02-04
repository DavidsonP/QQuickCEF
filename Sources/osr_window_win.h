#ifndef OSR_WINDOW_WIN_H
#define OSR_WINDOW_WIN_H

#include "include/cef_app.h"
#include "include/cef_client.h"
#include "osr_renderer.h"

class OsrWindowWin : public CefApp, public CefClient
{
public:
    OsrWindowWin();
};

#endif // OSR_WINDOW_WIN_H
