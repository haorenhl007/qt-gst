#include "adapterdemo.h"

// Gstreamer
#include <QQuickView>
#include "player.h"
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QGst/Init>
#include <QGst/Quick/VideoSurface>

#include <QDebug>

AdapterDemo::AdapterDemo(QObject *parent)
    : QObject(parent)
{
    QString mqttHost = "mqtt-fallback.atomrock.com";
    QByteArray host = mqttHost.toLocal8Bit();
    QString user = "admin";
    QByteArray id = user.toLocal8Bit();
    QString port = "1883";

    mosqpp::lib_init();

    mMqtt = new qtmosq(id, false);
    mMqtt->username_pw_set(id.data(), "Atom2Rock");
    mMqtt->connect_async(host.data(), port.toInt());
    mMqtt->loop_start();

    QString currentTopic = "ar/dev/display/91be768cfa27dc35/status/online";
    QByteArray topic = currentTopic.toLocal8Bit();
    mMqtt->subscribe(mMqtt->getMID(), topic.data(), 2);

    qDebug() << LIBMOSQUITTO_VERSION_NUMBER;
    qDebug() << host << id << port;
}

void AdapterDemo::setRootObject(QObject *qmlObj)
{
    // disconnect from previous root
    if (mRoot != 0) mRoot->disconnect(this);

    mRoot = qmlObj;

    if (mRoot) {
        // setup connection
        QObject::connect(mRoot, SIGNAL(sendMessage(QString, QString)), this, SLOT(mqttSend(QString, QString)));
        QObject::connect(mMqtt, SIGNAL(messageReceived(QString)), this, SLOT(mqttReceived(QString)));
        QObject::connect(this, SIGNAL(updateQml(QString)), mRoot, SIGNAL(updateMessage(QString)));
    }
}

void AdapterDemo::mqttSend(QString account, QString password)
{
    // mosquitto_pub -u 91be768cfa27dc35 -P atomrock -p 1883 --insecure -t ar/dev/display/91be768cfa27dc35/status/online -h mqtt-fallback.atomrock.com -m 0
    QByteArray payload = QString("[" + account + "] " + password).toLocal8Bit();
    QString currentTopic = "ar/dev/display/91be768cfa27dc35/status/online";
    QByteArray topic = currentTopic.toLocal8Bit();

    mMqtt->publish(mMqtt->getMID(), topic.data(), payload.size(), payload.data(), 2, false);
}

void AdapterDemo::mqttReceived(QString message)
{
    qDebug() << message;
    emit updateQml("qrc:/Configure.qml");
}

void AdapterDemo::setVideoUrl(void)
{
    // video 1
//    Player *player = new Player(mRoot);
//    player->setVideoSink(surface->videoSink());
//    player->setUri(QLatin1Literal("rtsp://10.10.3.151:554/user=admin&password=zG@!Px6B&channel=1&stream=1.sdp"));
//    player->play();
//    view.rootContext()->setContextProperty(QLatin1String("player"), player);
}
