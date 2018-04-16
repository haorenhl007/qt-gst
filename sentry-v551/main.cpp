#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

// PlayStream test
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QGst/Init>
#include <QGst/Quick/VideoSurface>

#include <QUrl>
#include <QDebug>
#include <QGlib/Connect>
#include <QGlib/Error>
#include <QGst/ElementFactory>
#include <QGst/Bus>
// PlayStream test

#include "accountlogin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if 1
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/account.qml")));

    QObject* topLevel     = engine.rootObjects().first();
    QQuickWindow* rootWin = qobject_cast<QQuickWindow *>( topLevel );

    AccountLogin *accountLogin = new AccountLogin();
    accountLogin->initialize( rootWin );
#else
#endif
    return app.exec();
}

