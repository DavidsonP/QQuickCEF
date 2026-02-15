#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Sources/CefWebView.h>
#include <windows.h>
#include "CefAppHandler.h"
#include <qDebug>

int LoadCEF(CefRefPtr<CefAppHandler> CefAppHandler) {
    #if defined(OS_WIN)
        CefMainArgs cefMainArgs = CefMainArgs(::GetModuleHandle(NULL));
    #else
        CefMainArgs cefMainArgs = CefMainArgs(argc, argv);
    #endif
    int exit_code = CefExecuteProcess(cefMainArgs, CefAppHandler.get(), nullptr);
    if (exit_code >= 0) {
        return exit_code;
    }

    // Populate this structure to customize CEF behavior.
    CefSettings settings;
    settings.windowless_rendering_enabled = true;
    settings.multi_threaded_message_loop = true;
    settings.external_message_pump = false;

    // Initialize CEF in the main process.
    if(!CefInitialize(cefMainArgs, settings, CefAppHandler.get(), nullptr))
        return CefGetExitCode();

    return 0;
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    CefRefPtr<CefAppHandler> CefAppHandler(new CefAppHandler);
    int exitCode = LoadCEF(CefAppHandler);
    if(exitCode) return exitCode;

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
