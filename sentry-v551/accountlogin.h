#ifndef ACCOUNTLOGIN_H
#define ACCOUNTLOGIN_H

#include <QObject>
#include "qtmosq.h"

//using namespace mosqpp;

class AccountLogin : public QObject, public mosqpp::mosquittopp
{
    Q_OBJECT
public:
    explicit AccountLogin(QObject *parent = nullptr);
    void initialize( QObject* qObj );

signals:
    void updateName( QString name );

public slots:
    void setName( QString name );
    void sendMessage(QString account, QString password);

private:
    QObject* viewItem;
    qtmosq* mosq = NULL;

private slots:
    void showMessage(QString);
};

#endif // ACCOUNTLOGIN_H
