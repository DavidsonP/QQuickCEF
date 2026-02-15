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
void CefClientHandler::GetViewRect(
    CefRefPtr<CefBrowser> browser,
    CefRect& rect
) {

}

bool CefClientHandler::GetScreenInfo(CefRefPtr<CefBrowser> browser ,CefScreenInfo& screen_info) {
    return false;
}


CefRefPtr<CefAccessibilityHandler> CefClientHandler::GetAccessibilityHandler(){
    CefRefPtr<CefAccessibilityHandler> temp;
    return temp;
}

bool CefClientHandler::GetRootScreenRect(CefRefPtr<CefBrowser> browser, CefRect& rect) { return false; }
bool CefClientHandler::GetScreenPoint(CefRefPtr<CefBrowser> browser, int viewX, int viewY, int& screenX, int& screenY) { return false; }
void CefClientHandler::OnPopupShow(CefRefPtr<CefBrowser> browser, bool show) { }
void CefClientHandler::OnPopupSize(CefRefPtr<CefBrowser> browser, const CefRect& rect) { }
void CefClientHandler::OnAcceleratedPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const CefAcceleratedPaintInfo& info) { }
void CefClientHandler::GetTouchHandleSize(CefRefPtr<CefBrowser> browser, cef_horizontal_alignment_t orientation, CefSize& size) { }
void CefClientHandler::OnTouchHandleStateChanged(CefRefPtr<CefBrowser> browser, const CefTouchHandleState& state) { }
bool CefClientHandler::StartDragging(CefRefPtr<CefBrowser> browser, CefRefPtr<CefDragData> drag_data, DragOperationsMask allowed_ops, int x, int y) { return false; }
void CefClientHandler::UpdateDragCursor(CefRefPtr<CefBrowser> browser, DragOperation operation) { }
void CefClientHandler::OnScrollOffsetChanged(CefRefPtr<CefBrowser> browser, double x, double y) { }
void CefClientHandler::OnImeCompositionRangeChanged(CefRefPtr<CefBrowser> browser, const CefRange& selected_range, const RectList& character_bounds) { }
void CefClientHandler::OnTextSelectionChanged(CefRefPtr<CefBrowser> browser, const CefString& selected_text, const CefRange& selected_range) { }
void CefClientHandler::OnVirtualKeyboardRequested(CefRefPtr<CefBrowser> browser, TextInputMode input_mode) { }
