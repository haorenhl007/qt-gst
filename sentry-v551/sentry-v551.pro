TEMPLATE = app

QT += widgets declarative opengl

# produce nice compilation output
CONFIG += silent \
# Tell qmake to use pkg-config to find QtGStreamer.
        link_pkgconfig \
        c++11

# Now tell qmake to link to QtGStreamer and also use its include path and Cflags.
contains(QT_VERSION, ^4\\..*) {
  PKGCONFIG += QtGStreamer-1.0 QtGStreamerUi-1.0
}
contains(QT_VERSION, ^5\\..*) {
  PKGCONFIG += Qt5GStreamerQuick-1.0
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -lmosquittopp -lmosquitto

DISTFILES +=

HEADERS += \
    qtmosq.h \
    player.h \
    playstream.h \
    playerview.h \
    qmlinfo.h \
    adapterdemo.h

SOURCES += main.cpp \
    player.cpp \
    playstream.cpp \
    playerview.cpp \
    qmlinfo.cpp \
    adapterdemo.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
