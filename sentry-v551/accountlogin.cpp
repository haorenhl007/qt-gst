#include "accountlogin.h"

#include <QDebug>
#include <QString>

#include <QMessageBox>

AccountLogin::AccountLogin(QObject *parent)
    : QObject(parent)
{
    QString mqttHost = "mqtt-fallback.atomrock.com";
    QByteArray host = mqttHost.toLocal8Bit();
    QString user = "admin";
    QByteArray id = user.toLocal8Bit();
    QString port = "1883";

    mosqpp::lib_init();

    mosq = new qtmosq(id, false);
    mosq->username_pw_set(id.data(), "Atom2Rock");
    mosq->connect_async(host.data(), port.toInt());
    mosq->loop_start();

    qDebug() << LIBMOSQUITTO_VERSION_NUMBER;
    qDebug() << host << id << port;
}

void AccountLogin::initialize(QObject *qObj)
{
    this->viewItem = qObj;

    QObject::connect( viewItem, SIGNAL( qmlSetName(QString, QString)), this, SLOT( sendMessage(QString, QString)) );
    QObject::connect( this, SIGNAL( updateName(QString)), viewItem, SIGNAL( qmlUpdateName(QString)) );

    QObject::connect(mosq, SIGNAL(messageReceived(QString)), this, SLOT(showMessage(QString)));
}

void AccountLogin::setName(QString name)
{
    qDebug()<<"C++ : "<<name;
    emit updateName("Modified Marc");
}

void AccountLogin::showMessage(QString message)
{
    //mosquitto_sub -u 91be768cfa27dc35 -P atomrock -p 8883 --cafile /home/firefly/.mqtt_fallback.ca --insecure -t ar/dev/display/91be768cfa27dc35/# -h mqtt-fallback.atomrock.com -d
//    QMessageBox dia;
//    dia.setText(message + tr("\n"));
//    dia.exec();
    qDebug() << message;
}

void AccountLogin::sendMessage(QString account, QString password)
{
    // mosquitto_pub -u 91be768cfa27dc35 -P atomrock -p 1883 --insecure -t ar/dev/display/91be768cfa27dc35/status/online -h mqtt-fallback.atomrock.com -m 0
    QByteArray payload = QString("[" + account + "] " + password).toLocal8Bit();
    QString currentTopic = "ar/dev/display/91be768cfa27dc35/status/online";
    QByteArray topic = currentTopic.toLocal8Bit();

    mosq->publish(mosq->getMID(), topic.data(), payload.size(), payload.data(), 2, false);
}
