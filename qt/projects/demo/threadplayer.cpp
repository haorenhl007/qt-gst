#include "threadplayer.h"

#include <QDebug>
#include <QProcess>
#include <QDBusConnection>
#include <QDBusMessage>

#include <QDBusInterface>
#include <QDBusReply>

#include <QIODevice>
#include <QFile>
#include <QTextStream>

ThreadPlayer::ThreadPlayer(QObject *parent)
    : QThread(parent)
{
    QString program = "omxplayer";

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

    QString stream1 = "rtsp://10.10.3.152:554/user=admin&password=IUbPel2l&channel=1&stream=1.sdp";
    QString stream2 = "rtsp://10.10.2.152:554/user=admin&password=XBtDzot5&channel=1&stream=1.sdp";

    // rtsp://10.1.1.151:554/user-admin&password=87uG04O6&channel=1&stream=1.sdp

    int startX = 1280;
    int startY = 360;
    int endX = 1920;
    int endY = 720;

    QString dest1 = "org.mpris.MediaPlayer2.omxplayer3";
    // --avdict "rtsp_transport:tcp" --win "1280 360 1920 720" "rtsp://10.10.2.152:554/user=admin&password=XBtDzot5&channel=1&stream=1.sdp" --live -n -l
    QStringList arguments1;
    arguments1 << "--avdict"
              << "rtsp_transport:tcp"
              << "--win"
              << QString("%1 %2 %3 %4").arg(startX).arg(startY).arg(endX).arg(endY)
              << stream1
              << "--live"
              << "-n"
              << "-1"
              << "--alpha=255"
              << "--dbus_name"
              << QString("%1").arg(dest1);
//              << "-g"
//              << "/home/wen/test/omx.log";
//    arguments1 << "/home/wen/test/test-video.mp4"
//              << "--win"
//              << QString("%1 %2 %3 %4").arg(startX).arg(startY).arg(endX).arg(endY);
    qDebug() << "\n" << arguments1 << "\n";

    QProcess pPlayer1;
    pPlayer1.startDetached(program, arguments1);
//    qDebug() << pPlayer.error();

    startX = 640;
    startY = 360;
    endX = 1280;
    endY = 720;
    QString dest2 = "org.mpris.MediaPlayer2.omxplayer2";
    QStringList arguments2;
    arguments2 << "--avdict"
              << "rtsp_transport:tcp"
              << "--win"
              << QString("%1 %2 %3 %4").arg(startX).arg(startY).arg(endX).arg(endY)
              << stream2
              << "--live"
              << "-n"
              << "-1"
              << "--alpha=255"
              << "--dbus_name"
              << QString("%1").arg(dest2);
//              << "-g"
//              << "/home/wen/test/omx.log";
//    arguments2 << "/home/wen/test/test-video-2.mp4"
//              << "--win"
//              << QString("%1 %2 %3 %4").arg(startX).arg(startY).arg(endX).arg(endY);
    qDebug() << "\n" << arguments2 << "\n";

    QProcess pPlayer2;
    pPlayer2.startDetached(program, arguments2);
//    qDebug() << pPlayer.error();
}

ThreadPlayer::~ThreadPlayer()
{
    qDebug() << "PlayerThread::~PlayerThread()";
}


ThreadControler::ThreadControler(QObject *parent)
    : QThread(parent)
{

    QProcess process;
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

//    qDebug() << "\n" << process.systemEnvironment() << "\n";

    // dbus environment variables
    // OMXPLAYER_DBUS_ADDR, /tmp/omxplayerdbus.${USER:-root}
    // OMXPLAYER_DBUS_PID, /tmp/omxplayerdbus.${USER:-root}.pid
    // DBUS_SESSION_BUS_ADDRESS, cat /tmp/omxplayerdbus.wen
    // DBUS_SESSION_BUS_PID, cat /tmp/omxplayerdbus.wen.pid

    // get DBus socket info
    QString path = "/tmp/";
    QString name = "omxplayerdbus";

//    qDebug() << env.value("USER");

    QString fileDBus;
    fileDBus = path + name + "." + env.value("USER");
    qDebug() << fileDBus;

//    qputenv("OMXPLAYER_DBUS_ADDR", "/tmp/omxplayer.wen");
    qputenv("OMXPLAYER_DBUS_ADDR", fileDBus.toUtf8());

    QFile fileDBusSocket(fileDBus);
    qDebug() << fileDBusSocket.error();

    if (!fileDBusSocket.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can't open file:" << fileDBus;
    }

    QTextStream out(&fileDBusSocket);
    QString outString = out.readLine();
    qDebug() << outString;
//    qputenv("DBUS_SESSION_BUS_ADDRESS",
//               "unix:abstract=/tmp/dbus-GRR0M3UzA5,guid=47d11e3599b493a03e20318b5aab3110");
    qputenv("DBUS_SESSION_BUS_ADDRESS", outString.toUtf8());
    fileDBusSocket.close();

    QString filePIDName;
    filePIDName = path + name + "." + env.value("USER") + ".pid";
    qDebug() << filePIDName;

//    qputenv("OMXPLAYER_DBUS_PID", "/tmp/omxplayer.wen.pid");
    qputenv("OMXPLAYER_DBUS_PID", filePIDName.toUtf8());

    QFile filePID(filePIDName);
    qDebug() << filePID.error();

    if (!filePID.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can't open file:" << filePIDName;
    }

    QTextStream pid(&filePID);
    QString pidString = pid.readLine();
    qDebug() << pidString;
//    qputenv("DBUS_SESSION_BUS_PID", "18091");
    qputenv("DBUS_SESSION_BUS_PID", pidString.toUtf8());
    filePID.close();

#if 1
    QString cmd("dbus-send");
    QStringList args;

    args << "--print-reply=literal"
         << "--session"
         << "--dest=org.mpris.MediaPlayer2.omxplayer2"
         << "/org/mpris/MediaPlayer2"
         << "org.mpris.MediaPlayer2.Player.SetAlpha"
         << "objpath:/not/used"
         << "int64:128";

//    int startX = 1280;
//    int startY = 720;
//    int endX = 1920;
//    int endY = 1080;

//    args << "--print-reply=literal"
//         << "--session"
//         << "--dest=org.mpris.MediaPlayer2.omxplayer2"
//         << "/org/mpris/MediaPlayer2"
//         << "org.mpris.MediaPlayer2.Player.VideoPos"
//         << "objpath:/not/used"
//         << QString("string:%1 %2 %3 %4").arg(startX).arg(startY).arg(endX).arg(endY);

    qDebug() << args;
    process.start(cmd, args, QIODevice::ReadOnly);
    process.waitForFinished();

    qDebug() << process.readAllStandardOutput();
    qDebug() << process.readAllStandardError();

#else
#if 1
    QString dest = "org.mpris.MediaPlayer2.omxplayer";
    QString pathDBus = "/org/mpris/MediaPlayer2";
    QString interface = "org.mpris.MediaPlayer2.Player";
    QDBusConnection *_dbus;

    _dbus = new QDBusConnection(QDBusConnection::sessionBus());
    _dbus->connectToBus("/tmp/omxplayerdbus.wen", "org.mpris.MediaPlayer2.omxplayer");

    if( !_dbus->isConnected() ) {

        qDebug() << "not connected";

    }


//    QDBusMessage msg = QDBusMessage::createSignal(dest, path, interface, name);
//    QList<QVariant> args;
//    args.append("int64:128");
//    args.append("--print-replay=literal");
//    args.append("--session");
    QList<QVariant> args;
#if 0 // not work
    QVariant value = 128;
    QString valueStr = "128";
    QString property = "SetAlpha";
    bool ok;
    args.append("objpath:/not/used");
    long abc = valueStr.toLong(&ok, 10);
    QVariant valueTest(abc);
    args.append(valueTest);//args.append(value.toLongLong(&ok));
#elif 0 // not work
    QString property = "VideoPos";
    QString a = "objpath:/not/used";
    QString b = "640 720 1280 1080";
    QString c = "--print-reply=literal";
    QString d = "--session";
//    args.append("objpath:/not/used");
//    args.append("640 720 1280 1080");
    args << a << b << c << d;
#else
    QString property = "Action";
    args.append(16); // play/pause
//    args.append(17); // volume-
//    args.append(18); // volume+
//    args.append(28); // hide
//    args.append(29); // unhide
#endif

    QDBusMessage msg = QDBusMessage::createMethodCall(dest, pathDBus, interface, property);
    msg.setArguments(args);

//    QDBusMessage msg = QDBusMessage::createSignal("/", "org.example.chat", "message");
//    msg << m_nickname << messageLineEdit->text();
//    QDBusConnection::sessionBus().send(msg);

    if(!_dbus->send(msg)) {
        qWarning() << "error: " << _dbus->lastError().message();
    }
#else
    QString hostname("kde.org");
    QDBusConnection bus = QDBusConnection::sessionBus();
    QDBusInterface *interface = new QDBusInterface("org.foo.bar",
                                                   "/network",
                                                   "org.foo.bar.network",
                                                   bus,
                                                   this);
    interface->call("ping");
    interface->call("ping", hostname);

    QList<QVariant> args;
    args.append("kde.org");
    interface->callWithArgumentList("ping", args);

    QDBusReply<int> reply = interface->call("ping",
                                            hostname);

    if (reply.isValid()) {
        KMessageBox::information(winId(),
                                 i18n("Ping to %1 took %2s")
                                 .arg(hostname)
                                 .arg(reply.value()),
                                 i18n("Pinging %1")
                                 .arg(hostname));
    }
    args.clear();
    interface->callWithCallback("listInterfaces",
                                args,
                                this,
                                SLOT(interfaceList(QDBusMessage)));
    connect(interface, SIGNAL(interfaceUp(QString)), this, SLOT(interfaceUp(QString)));
#endif
#endif
}

ThreadControler::~ThreadControler()
{
    qDebug() << "ThreadControler::~ThreadControler()";
}
