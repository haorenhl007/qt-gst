#ifndef ADAPTERDEMO_H
#define ADAPTERDEMO_H

#include <QObject>
#include "qtmosq.h"

class AdapterDemo : public QObject
{
    Q_OBJECT
public:
    explicit AdapterDemo(QObject *parent = nullptr);

    void setRootObject(QObject *qmlObj);

signals:
    void updateQml(QString);

public slots:
    void mqttSend(QString account, QString password);
    void mqttReceived(QString message);
    void setVideoUrl(void);

private:
    QObject *mRoot;
    qtmosq *mMqtt = NULL;

};

#endif // ADAPTERDEMO_H
