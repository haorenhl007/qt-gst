#include "dialogaccount.h"

#include <iostream>
#include <QGridLayout>

#include <QDebug>
#include <QProcess>
#include <QFile>

DialogAccount::DialogAccount(QWidget *parent)
    : QDialog(parent)
{
    labelUserName = new QLabel(this);
    labelUserName->setText(tr("User: "));
    labelPassWord = new QLabel(this);
    labelPassWord->setText(tr("Password: "));

    lineEditUserName = new QLineEdit(this);
    lineEditPassWord = new QLineEdit(this);
    lineEditPassWord->setEchoMode(QLineEdit::Password);

    pushButtonLogin = new QPushButton(this);
    pushButtonLogin->setText(tr("Login"));

    setAlpha1 = new QPushButton(this);
    setAlpha1->setText(tr("Alpha 1"));

    setAlpha2 = new QPushButton(this);
    setAlpha2->setText(tr("Alpha 2"));

    QGridLayout *loginLayout = new QGridLayout(this);

    loginLayout->addWidget(labelUserName, 0, 0);
    loginLayout->addWidget(lineEditUserName, 0, 1);
    loginLayout->addWidget(labelPassWord, 1, 0);
    loginLayout->addWidget(lineEditPassWord, 1, 1);
    loginLayout->addWidget(pushButtonLogin, 2, 1);

    loginLayout->addWidget(setAlpha1, 3, 0);
    loginLayout->addWidget(setAlpha2, 3, 1);

    connect(pushButtonLogin, SIGNAL(clicked()), this, SLOT(on_pushButtonLogin_clicked()));

    connect(setAlpha1, SIGNAL(clicked()), this, SLOT(on_setAlpha_clicked()));
    connect(setAlpha2, SIGNAL(clicked()), this, SLOT(on_setPos_clicked()));
}

DialogAccount::~DialogAccount()
{
    qDebug() << "~DialogAccount";
}

void DialogAccount::on_pushButtonLogin_clicked()
{
    QString id = lineEditUserName->text();
    QString ps = lineEditPassWord->text();

    if (!id.isEmpty() && id.compare(QString("admin")) == 0)
    {
        DialogAccount::accept();
    }
}

void DialogAccount::on_setAlpha_clicked()
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

    QString cmd("dbus-send");
    QStringList args;

    args << "--print-reply=literal"
         << "--session"
         << "--dest=org.mpris.MediaPlayer2.omxplayer3"
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
//         << "--dest=org.mpris.MediaPlayer2.omxplayer1"
//         << "/org/mpris/MediaPlayer2"
//         << "org.mpris.MediaPlayer2.Player.VideoPos"
//         << "objpath:/not/used"
//         << QString("string:%1 %2 %3 %4").arg(startX).arg(startY).arg(endX).arg(endY);

    qDebug() << args;
    process.start(cmd, args, QIODevice::ReadOnly);
    process.waitForFinished();

    qDebug() << process.readAllStandardOutput();
    qDebug() << process.readAllStandardError();
}

void DialogAccount::on_setPos_clicked()
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
//         << "--dest=org.mpris.MediaPlayer2.omxplayer1"
//         << "/org/mpris/MediaPlayer2"
//         << "org.mpris.MediaPlayer2.Player.VideoPos"
//         << "objpath:/not/used"
//         << QString("string:%1 %2 %3 %4").arg(startX).arg(startY).arg(endX).arg(endY);

    qDebug() << args;
    process.start(cmd, args, QIODevice::ReadOnly);
    process.waitForFinished();

    qDebug() << process.readAllStandardOutput();
    qDebug() << process.readAllStandardError();
}
