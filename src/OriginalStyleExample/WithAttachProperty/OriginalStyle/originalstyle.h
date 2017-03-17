#ifndef ORIGINALSTYLE_H
#define ORIGINALSTYLE_H

#include <QObject>
#include <QtQml>
#include <QColor>

class OriginalStyle : public QObject
{
  Q_OBJECT
  //QMLに公開するプロパティ                   [1]
  Q_PROPERTY(Theme theme READ theme WRITE setTheme NOTIFY themeChanged)
  Q_PROPERTY(QColor basicColor READ basicColor NOTIFY basicColorChanged)

public:
  //テーマの名前                          [2]
  enum Theme {
    Red,
    Blue
  };
  Q_ENUM(Theme)   //QMLに公開

  explicit OriginalStyle(QObject *parent = nullptr);
  //アタッチするときにインスタンス作成
  static OriginalStyle *qmlAttachedProperties(QObject *object); //[3]

  //テーマ
  Theme theme() const;
  void setTheme(Theme theme);
  //基本色
  QColor basicColor() const;

signals:
  void themeChanged(int theme);
  void basicColorChanged(QColor basicColor);

public slots:

private:
  Theme m_theme;
};

QML_DECLARE_TYPEINFO(OriginalStyle, QML_HAS_ATTACHED_PROPERTIES) // [4]

#endif // ORIGINALSTYLE_H
