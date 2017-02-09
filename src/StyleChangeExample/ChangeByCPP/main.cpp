#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

//  QQuickStyle::setStyle("Default");
  QQuickStyle::setStyle("Material");
//  QQuickStyle::setStyle("Universal");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));

//  QQuickStyle::setStyle("Material");

  return app.exec();
}
