#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H

#include <QThread>

class ThreadPlayer : public QThread
{
    Q_OBJECT

public:
    ThreadPlayer(QObject *parent = 0);
    ~ThreadPlayer();
};

class ThreadControler: public QThread
{
    Q_OBJECT

public:
    ThreadControler(QObject *parent = 0);
    ~ThreadControler();
};

#endif // PLAYERTHREAD_H
