#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QObject>

class PlayerView : public QObject
{
    Q_OBJECT
public:
    explicit PlayerView(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PLAYERVIEW_H