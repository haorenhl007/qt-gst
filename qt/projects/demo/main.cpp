#include "dialogaccount.h"
#include "threadplayer.h"

#include <QDebug>
#include <QApplication>
#include <QMainWindow>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // get screen size
    qDebug() << QApplication::desktop()->width()
             << " x "
             << QApplication::desktop()->height();
    qDebug() << QApplication::desktop()->availableGeometry().width()
             << " x "
             << QApplication::desktop()->availableGeometry().height();
    qDebug() << QString("%1 x %2").arg(QApplication::desktop()->screenGeometry().width()).arg(QApplication::desktop()->screenGeometry().height());


    QMainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground, true);

//    w.showFullScreen();
    w.show();

    DialogAccount dlgAccount;

    if (dlgAccount.exec() == DialogAccount::Accepted) {

        dlgAccount.show();

        ThreadPlayer tplayer;
    }

    return app.exec();
}
