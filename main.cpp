#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mainviewmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication  app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("model", new MainViewModel(CustomerModel()));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}

/*
 *
 *
 *  ScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);

    MainModel mainModel;

    viewer.rootContext()->setContextProperty("model", new MainViewModel(mainModel));
    viewer.setMainQmlFile(QLatin1String("qml/QtQuickMvvmExample/MainView.qml"));
    viewer.showExpanded();

    return app->exec();

*/
