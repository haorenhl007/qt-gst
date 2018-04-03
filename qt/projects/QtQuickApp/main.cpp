#include <QApplication>
#include <QQuickView>
#include <QColor>
#include <QQmlContext>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

int main(int argc, char *argv[])
{

//    QApplication app(argc, argv);
    QGuiApplication app(argc, argv);

// test1
    QQuickView viwer;
//    viwer.setFlags(Qt::FramelessWindowHint);
    viwer.setFlags(Qt::Window|Qt::FramelessWindowHint);
//    viwer.setOpacity(0.5);
//    viwer.setColor(QColor(Qt::transparent));
    viwer.setSource(QUrl("qrc:/main.qml"));
    viwer.show();
    viwer.rootContext()->setContextProperty("mainwindow", &viwer);

// test2
//    QQuickView view;
//    view.setSurfaceType(QSurface::OpenGLSurface);
//    QSurfaceFormat format;
//    format.setAlphaBufferSize(8);
//    format.setRenderableType(QSurfaceFormat::OpenGL);
//    qDebug()<<format.hasAlpha();
//    view.setFormat(format);
//    QColor color;
//    color.setRedF(0.0);
//    color.setGreenF(0.0);
//    color.setBlueF(0.0);
//    color.setAlphaF(0.0);
//    view.setColor(color);
//    view.setClearBeforeRendering(true);
//    view.setSource(QUrl("qrc:/main.qml"));
//    view.show();

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
