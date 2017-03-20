#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include <QSettings>                            // [1]
#include "originalstyle.h"

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
  //設定の保存で使用する情報                          // [2]
  app.setOrganizationName("Relog");
  app.setOrganizationDomain("relog.xii.jp");
  app.setApplicationName("ChooseStyleExample");

  qmlRegisterUncreatableType<OriginalStyle>(
        "OriginalStyle"
        , 1, 0
        , "OriginalStyle"
        , "OriginalStyle is an attached property");

  //設定の読み込み
  QSettings settings(qobject_cast<QObject *>(&app));                // [3]
  QString styleName = settings.value(QStringLiteral("styleName")
                                     , QStringLiteral("Default")).toString(); // [4]
  QQuickStyle::setStyle(styleName);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));

  return app.exec();
}
