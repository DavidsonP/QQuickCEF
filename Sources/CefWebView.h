#ifndef CefWebView_H
#define CefWebView_H

#include <QQuickItem>

class CefWebView : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT

private:
protected:
    void componentComplete() override;

public:
    Q_PROPERTY(QString url READ getUrl WRITE changeUrl NOTIFY urlUpdated)

    QString getUrl();
    void changeUrl(QString url);
    void reload();
    void execJs(QString cmd);
    void zoom(int value);

    CefWebView();

signals:
    void urlUpdated();
};

#endif // CefWebView_H
