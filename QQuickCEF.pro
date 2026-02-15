QT += quick
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Sources/CefAppHandler.cpp \
        Sources/CefClientHandler.cpp \
        Sources/CefWebView.cpp \
        Sources/QtBridgeV8Handler.cpp \
        Sources/main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Sources/CefAppHandler.h \
    Sources/CefClientHandler.h \
    Sources/CefWebView.h \
    Sources/QtBridgeV8Handler.h

INCLUDEPATH += \
    CEF + \
    CEF/include

LIBS += \
    $$PWD/CEF/libcef_dll_wrapper.lib

LIBS += \
    $$PWD/CEF/libcef.lib

LIBS += -luser32
