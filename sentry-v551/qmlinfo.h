#ifndef QMLINFO_H
#define QMLINFO_H

#include <QObject>
#include <QQmlApplicationEngine>

class QmlInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString qmlName READ qmlName WRITE setQmlName NOTIFY qmlNameChanged)
public:
    explicit QmlInfo(QObject *parent = nullptr);
    void initialize(QObject *qObj);
    QString qmlName();
    void setQmlName(const QString &qmlName);

signals:
    void qmlNameChanged();

private:
    QString m_qmlName;
    QObject *qmlRoot;

};

#endif // QMLINFO_H
