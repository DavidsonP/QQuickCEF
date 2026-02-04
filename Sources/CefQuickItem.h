#ifndef CEFQUICKITEM_H
#define CEFQUICKITEM_H

#include <QQuickItem>
#include "osr_window_win.h"

class CefQuickItem : public QQuickItem, public OsrWindowWin
{
    Q_OBJECT
    QML_ELEMENT

private:
    CefMainArgs m_mainArgsCef;
    CefSettings m_cefSettings;
    CefRefPtr<OsrWindowWin> m_osrPointer;

    void loadSettings();
    IMPLEMENT_REFCOUNTING(CefQuickItem);
protected:
    void componentComplete() override;

public:
    enum CefSettingFlags {
        None = 0,
        NoSandbox = 1 << 1,
        MultiThreadedMessageLoop = 1 << 2,
        ExternalMessagePump = 1 << 3,
        CommandLineArgsDisabled = 1 << 4,
        PersistSessionCookies = 1 << 5,
        CookieableSchemesExcludeDefaults = 1 << 6,
        Incognito = 1 << 7
    };
    Q_DECLARE_FLAGS(CefSettingFlag, CefSettingFlags)
    static CefMainArgs cefMainArgs; // Move to INIT + TBD

    CefSettingFlags cefSettingFlags;
    QString cachePath;

    Q_PROPERTY(CefSettingFlags cefSettings MEMBER cefSettingFlags)
    Q_PROPERTY(QString cachePath MEMBER cachePath)
    Q_PROPERTY(QString url READ getUrl WRITE changeUrl NOTIFY urlUpdated)

    QString getUrl();
    void changeUrl(QString url);
    void reload();
    void execJs(QString cmd);
    void zoom(int value);

    CefQuickItem();

signals:
    void urlUpdated();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(CefQuickItem::CefSettingFlag)

#endif // CEFQUICKITEM_H
