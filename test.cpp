#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  engine.addImportPath(QString(PROJECT_PATH) + "/qml/");
  const QUrl url(QString(PROJECT_PATH) + "/qml/Main.qml");

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [&, url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
