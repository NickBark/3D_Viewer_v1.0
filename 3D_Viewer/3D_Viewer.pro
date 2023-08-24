QT       += core gui opengl
include(gifLib/QtGifImage/src/gifimage/qtgifimage.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controlpanel.cpp \
    edge.cpp \
    glview.cpp \
    main.cpp \
    mainframe.cpp \
    mainwindow.cpp \
    record.cpp \
    settings.cpp

HEADERS += \
    controlpanel.h \
    dependencies.hpp \
    edge.h \
    glview.h \
    mainframe.h \
    mainwindow.h \
    record.h \
    settings.h

LIBS += -lGLEW -lglfw -lOpenGL
LIBS += -lglut -lGLU


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../release/ -ls21_viewer_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../debug/ -ls21_viewer_core
else:unix: LIBS += -L$$PWD/../ -ls21_viewer_core

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../release/libs21_viewer_core.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../debug/libs21_viewer_core.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../release/s21_viewer_core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../debug/s21_viewer_core.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libs21_viewer_core.a

LIBS += -lm -lpcre


