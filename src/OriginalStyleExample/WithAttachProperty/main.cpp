#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "originalstyle.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  //普通のエレメントとは違う扱いで登録   [1]
  qmlRegisterUncreatableType<OriginalStyle>(
        "OriginalStyle"
        , 1, 0
        , "OriginalStyle"
        , "OriginalStyle is an attached property");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));

  return app.exec();
}
