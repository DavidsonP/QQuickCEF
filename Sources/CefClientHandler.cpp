#include "CefClientHandler.h"

CefClientHandler::CefClientHandler() {}
void CefClientHandler::OnPaint(
    CefRefPtr<CefBrowser> browser,
    PaintElementType type,
    const RectList& dirtyRects,
    const void* buffer,
    int width,
    int height
) {

}
bool CefClientHandler::GetViewRect(
    CefRefPtr<CefBrowser> browser,
    CefRect& rect
) {

}
bool CefClientHandler::GetScreenInfo(CefRefPtr<CefBrowser> browser ,CefScreenInfo& screen_info) {
    screen_info.Set(0.0, 0, 0, false, nullptr, nullptr);
    return false;
}
