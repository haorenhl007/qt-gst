#include "qmlinfo.h"
#include "mqttclient.h"

#include <QDebug>

QmlInfo::QmlInfo(QObject *parent) : QObject(parent)
{
}

QString QmlInfo::qmlName()
{
//    MqttClient *mqtt = new MqttClient;
    qDebug() << this->qmlRoot->objectName();
    return m_qmlName;
}

void QmlInfo::initialize(QObject *qObj)
{
    this->qmlRoot = qObj;
}

void QmlInfo::setQmlName(const QString &qmlName)
{
    m_qmlName = qmlName;
    emit qmlNameChanged();
}
