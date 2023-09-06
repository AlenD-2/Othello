
#include "OthelloModel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Othello::OthelloModel>("OthelloModel",1,0,"OthelloModel");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Othello/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
