#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "custommodel.h"
#include "custommodel2.h"
#include "custommodel3.h"
#include "custommodel3singleton.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // intialisining the  instance of the  model with the  set Context
    // Create and populate the model
    // CustomModel2 *model = new CustomModel2();

    // // Adding data to the model
    // model->addItem(1, "Item 1");
    // model->addItem(2, "Item 2");
    // model->addItem(3, "Item 3");

    // // // Expose the model to QML
    // engine.rootContext()->setContextProperty("customM", model);


    qmlRegisterType<CustomModel>("com.example",1,0,"CustomModel");

    qmlRegisterSingletonType<CustomModel3>("com.example",1,0,"CustomModel3",CustomModel3Singleton::instanceProvider);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);


    engine.load(url);

    return app.exec();
}
