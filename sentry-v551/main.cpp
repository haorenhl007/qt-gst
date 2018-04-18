#include <QApplication>
// 1
#include <QQmlApplicationEngine>
// 2
#include <QQuickView>
#include <QQuickItem>
// 3
#include <QQmlComponent>

// Gstreamer
#include "player.h"
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QGst/Init>
#include <QGst/Quick/VideoSurface>

#include <QDebug>

#include "accountlogin.h"

int main(int argc, char *argv[])
{
#if 1
    QGuiApplication app(argc, argv);

    // study: load qml methods, QQmlEngine, QQuickView, QQmlComponent
    // 1, no auto-create root window
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // if account qml has root window
//    engine.load(QUrl(QStringLiteral("qrc:/Account.qml")));
//    QObject* topLevel     = engine.rootObjects().first();
//    QQuickWindow* rootWin = qobject_cast<QQuickWindow *>( topLevel );
//    AccountLogin *accountLogin = new AccountLogin();
//    accountLogin->initialize( rootWin );

    // 2
//    QQuickView view;
//    view.setSource(QUrl(QStringLiteral("qrc:/Account.qml")));
//    view.show();

//    QObject *accountObj = qobject_cast<QObject *>(view.rootObject());
//    AccountLogin accountLogin;
//    accountLogin.initialize(accountObj);

    // 3
//    QQmlEngine engine;
//    QQmlComponent comp(&engine, QUrl(QStringLiteral("qrc:/Account.qml")));
//    QObject *accountObj = comp.create();

    // QQuickView using
//    QObject *accountObj = view.rootObject();
//    AccountLogin *accountLogin = new AccountLogin;
//    accountLogin->initialize(accountObj);

    // study: child qml signal/connection
    // refer to https://hackmd.io/s/ByZcnT7sl
//    QObject *qmlObj = engine.rootObjects().first();
//    QObject *childObj = qmlObj->findChild<QObject *>("pageLoader");
//    if (childObj)
//    {
//        qDebug() << "found";
//        childObj->setProperty("source", "qrc:/PopMessage.qml");
//        connect(childObj, SIGNAL(qmlMsg(QString)), this, SLOT(printData(QString)));
//    }

#else
    //    IP          Series          Password    MAC
    // 10.10.1.151  BC120A01LY195WD Vv5bVAl2    28F5375040C2
    // 10.10.1.152  BC120A01CP196OS Q$p9HG*4    28F5375040C3
    // 10.10.1.153  BC120A01TP116XU j26YCoJj    28F537504073
    // 10.10.1.154  BC120A01SH192OO NOeHPkIG    28F5375040BF
    // 10.10.2.151  BC120A01SB086WV yYeB!NFA    28F537504055
    // 10.10.2.152  BC120A01SC019XH XBtDzot5    28F537504012
    // 10.10.2.153  BC120A01BJ185GZ w8Mol&tI    28F5375040B8
    // 10.10.2.154  BC120A01OR178UA rWt3hDAh    28F5375040B1
    // 10.10.3.151  BC120A01DG062BY zG@!Px6B    28F53750403D
    // 10.10.3.152  BC120A01KM077NR IUbPel2l    28F53750404C
    // 10.10.3.153  BC120A01WQ014AB 7n8c9WMo    28F53750400D
    // 10.10.3.154  BC120A01MC002SE $zlFpF@%    28F537504001
    // 10.1.1.151   BC120A01KP083DP zG@!Px6B    28F537504052
    // 10.1.1.152   BC120A01FY089KA IUbPel2l    28F537504058
    // 10.1.1.153   BC120A01GP197TS I38O*dnx    28F5375040C4
    // 10.1.1.155   BC220A01BB001XX atomrock    28F537506000

//        QString stream1 = "rtsp://10.10.3.152:554/user=admin&password=IUbPel2l&channel=1&stream=1.sdp";
//        QString stream2 = "rtsp://10.10.2.152:554/user=admin&password=XBtDzot5&channel=1&stream=1.sdp";

    // Gstreamer
    QGuiApplication app(argc, argv);
    QGst::init(&argc, &argv);

    QQuickView view;
//    view.setFlags(Qt::FramelessWindowHint);

    QGst::Quick::VideoSurface *surface = new QGst::Quick::VideoSurface;
    view.rootContext()->setContextProperty(QLatin1String("videoSurface1"), surface);//qmlRegisterType<surface>("gst.surface", 1, 0, "surface");

    // video 1
    Player *player = new Player(&view);
    player->setVideoSink(surface->videoSink());
    player->setUri(QLatin1Literal("rtsp://10.10.3.151:554/user=admin&password=zG@!Px6B&channel=1&stream=1.sdp"));
    player->play();
    view.rootContext()->setContextProperty(QLatin1String("player"), player);

    // video 2
//    QGst::Quick::VideoSurface *surface2 = new QGst::Quick::VideoSurface;
//    view.rootContext()->setContextProperty(QLatin1String("videoSurface2"), surface2);

//    Player *player2 = new Player(&view);
//    player2->setVideoSink(surface2->videoSink());
//        player2->setUri(QLatin1Literal("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
//        player2->play();
//    view.rootContext()->setContextProperty(QLatin1String("player"), player2);

    // video 3
//    QGst::Quick::VideoSurface *surface3 = new QGst::Quick::VideoSurface;
//    view.rootContext()->setContextProperty(QLatin1String("videoSurface3"), surface3);

//    Player *player3 = new Player(&view);
//    player3->setVideoSink(surface3->videoSink());
//        player3->setUri(QLatin1Literal("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
//        player3->play();
//    view.rootContext()->setContextProperty(QLatin1String("player"), player3);

    // video 4
//    QGst::Quick::VideoSurface *surface4 = new QGst::Quick::VideoSurface;
//    view.rootContext()->setContextProperty(QLatin1String("videoSurface4"), surface4);

//    Player *player4 = new Player(&view);
//    player4->setVideoSink(surface4->videoSink());
//        player4->setUri(QLatin1Literal("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
//        player4->play();
//    view.rootContext()->setContextProperty(QLatin1String("player"), player4);

    // video 5
    QGst::Quick::VideoSurface *surface5 = new QGst::Quick::VideoSurface;
    view.rootContext()->setContextProperty(QLatin1String("videoSurface5"), surface5);

    Player *player5 = new Player(&view);
    player5->setVideoSink(surface5->videoSink());
        player5->setUri(QLatin1Literal("rtsp://10.10.3.152:554/user=admin&password=IUbPel2l&channel=1&stream=1.sdp"));
        player5->play();
    view.rootContext()->setContextProperty(QLatin1String("player"), player5);

    // video 6
//    QGst::Quick::VideoSurface *surface6 = new QGst::Quick::VideoSurface;
//    view.rootContext()->setContextProperty(QLatin1String("videoSurface6"), surface6);

//    Player *player6 = new Player(&view);
//    player6->setVideoSink(surface6->videoSink());
//        player6->setUri(QLatin1Literal("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
//        player6->play();
//    view.rootContext()->setContextProperty(QLatin1String("player"), player6);

    // video 7
//    QGst::Quick::VideoSurface *surface7 = new QGst::Quick::VideoSurface;
//    view.rootContext()->setContextProperty(QLatin1String("videoSurface7"), surface7);

//    Player *player7 = new Player(&view);
//    player7->setVideoSink(surface7->videoSink());
//        player7->setUri(QLatin1Literal("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
//        player7->play();
//    view.rootContext()->setContextProperty(QLatin1String("player"), player7);

    // video 8
//    QGst::Quick::VideoSurface *surface8 = new QGst::Quick::VideoSurface;
//    view.rootContext()->setContextProperty(QLatin1String("videoSurface8"), surface8);

//    Player *player8 = new Player(&view);
//    player8->setVideoSink(surface8->videoSink());
//        player8->setUri(QLatin1Literal("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
//        player8->play();
//    view.rootContext()->setContextProperty(QLatin1String("player"), player8);

    // video 9
    QGst::Quick::VideoSurface *surface9 = new QGst::Quick::VideoSurface;
    view.rootContext()->setContextProperty(QLatin1String("videoSurface9"), surface9);

    Player *player9 = new Player(&view);
    player9->setVideoSink(surface9->videoSink());
        player9->setUri(QLatin1Literal("http://download.blender.org/peach/bigbuckbunny_movies/big_buck_bunny_480p_surround-fix.avi"));
        player9->play();
    view.rootContext()->setContextProperty(QLatin1String("player"), player9);

    view.setSource(QUrl(QStringLiteral("qrc:/PlayStream.qml")));
    view.show();
#endif

    return app.exec();
}

