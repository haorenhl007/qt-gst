TEMPLATE = app

QT += qml quick widgets

QMAKE_CXXFLAGS += -std=c++0x
LIBS += -lmosquittopp -lmosquitto

# produce nice compilation output
CONFIG += silent

# Tell qmake to use pkg-config to find QtGStreamer.
CONFIG += link_pkgconfig

# Now tell qmake to link to QtGStreamer and also use its include path and Cflags.
#PKGCONFIG += Qt5GStreamerQuick-1.0

# Now tell qmake to link to QtGStreamer and also use its include path and Cflags.
contains(QT_VERSION, ^4\\..*) {
  PKGCONFIG += QtGStreamer-1.0 QtGStreamerUi-1.0
}
contains(QT_VERSION, ^5\\..*) {
  PKGCONFIG += Qt5GStreamer-1.0 Qt5GStreamerUi-1.0 Qt5GStreamerQuick-1.0
#  QT += widgets
}

SOURCES += main.cpp \
    accountlogin.cpp \
    player.cpp \
    playstream.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES +=

HEADERS += \
    accountlogin.h \
    qtmosq.h \
    player.h \
    playstream.h
