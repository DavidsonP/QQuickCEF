#include "CefQuickItem.h"

CefMainArgs CefQuickItem::cefMainArgs;
CefQuickItem::CefQuickItem() {}

void CefQuickItem::loadSettings() {
    this->m_cefSettings.windowless_rendering_enabled = true;

    if(this->cefSettingFlags & CefSettingFlags::NoSandbox){
        this->m_cefSettings.no_sandbox = 1;
    }

    if(this->cefSettingFlags & CefSettingFlags::MultiThreadedMessageLoop){
        this->m_cefSettings.multi_threaded_message_loop = 1;
    }

    if(this->cefSettingFlags & CefSettingFlags::ExternalMessagePump){
        this->m_cefSettings.external_message_pump = 1;
    }

    if(this->cefSettingFlags & CefSettingFlags::CommandLineArgsDisabled){
        this->m_cefSettings.command_line_args_disabled = 1;
    }

    if(this->cefSettingFlags & CefSettingFlags::PersistSessionCookies){
        this->m_cefSettings.persist_session_cookies = 1;
    }

    if(this->cefSettingFlags & CefSettingFlags::CookieableSchemesExcludeDefaults){
        this->m_cefSettings.cookieable_schemes_exclude_defaults = 1;
    }

    if(!(this->cefSettingFlags & CefSettingFlags::Incognito)) {
        CefString(&this->m_cefSettings.cache_path).FromString16(cachePath.toStdU16String());
    }
}

void CefQuickItem::componentComplete() {
    QQuickItem::componentComplete();
    this->loadSettings();

    this->m_osrPointer = this; // TBD for correct way with QT
    CefExecuteProcess(this->m_mainArgsCef, this->m_osrPointer.get(), nullptr);
}

QString CefQuickItem::getUrl(){return nullptr;}
void CefQuickItem::changeUrl(QString url){}
void CefQuickItem::reload(){}
void CefQuickItem::execJs(QString cmd){}
void CefQuickItem::zoom(int value){}
