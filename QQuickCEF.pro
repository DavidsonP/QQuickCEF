QT += quick
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Sources/CefQuickItem.cpp \
        Sources/main.cpp \
        Sources/osr_renderer.cpp \
        Sources/osr_renderer_settings.cpp \
        Sources/osr_window_win.cpp

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
    Sources/CefQuickItem.h \
    Sources/osr_renderer.h \
    Sources/osr_renderer_settings.h \
    Sources/osr_window_win.h \
    Sources/osrrenderhandlerwin.h

INCLUDEPATH += \
    CEF + \
    CEF/include

LIBS += \
    $$PWD/CEF/libcef_dll_wrapper.lib

LIBS += \
    $$PWD/CEF/libcef.lib

