#ifndef ORIGINALSTYLE_H
#define ORIGINALSTYLE_H

#include <QObject>
#include <QtQml>
#include <QColor>
#include "originalstyleattached.h"

class OriginalStyle : public OriginalStyleAttached
{
  Q_OBJECT
  //QMLに公開するプロパティ
  Q_PROPERTY(Theme theme READ theme WRITE setTheme NOTIFY themeChanged)
  Q_PROPERTY(QColor basicColor READ basicColor NOTIFY basicColorChanged)

public:
  enum Theme {
    Red,
    Blue
  };
  Q_ENUM(Theme)

  explicit OriginalStyle(QObject *parent = nullptr);
  //アタッチするときにインスタンス作成
  static OriginalStyle *qmlAttachedProperties(QObject *object);

  //テーマ
  Theme theme() const;
  void setTheme(Theme theme);
  void setThemeByInherit(Theme theme);
  //基本色
  QColor basicColor() const;

signals:
  void themeChanged(int theme);
  void basicColorChanged(QColor basicColor);

public slots:
protected:
  //親のスタイル変化を反映
  void parentStyleChange(OriginalStyleAttached *style) override;

private:
  Theme m_theme;
  bool m_explicitTheme; //代入やバインディングで設定されたか

  void init();
  void propagateTheme();
};

QML_DECLARE_TYPEINFO(OriginalStyle, QML_HAS_ATTACHED_PROPERTIES)

#endif // ORIGINALSTYLE_H
