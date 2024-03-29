QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buffers.cpp \
    connections.cpp \
    initmodule.cpp \
    main.cpp \
    packmanager.cpp \
    server.cpp \
    widget.cpp

HEADERS += \
    buffers.h \
    connections.h \
    initmodule.h \
    packmanager.h \
    server.h \
    widget.h

FORMS += \
    widget.ui

QMAKE_CXXFLAGS += -std=gnu++11 #отправка всем на указанный порт

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

