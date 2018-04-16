#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

#include "accountlogin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/account.qml")));

    QObject* topLevel     = engine.rootObjects().first();
    QQuickWindow* rootWin = qobject_cast<QQuickWindow *>( topLevel );

    AccountLogin *accountLogin = new AccountLogin();
    accountLogin->initialize( rootWin );

    return app.exec();
}

