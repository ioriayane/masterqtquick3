#ifndef ORIGINALSTYLE_H
#define ORIGINALSTYLE_H

#include <QObject>
#include <QtQml>
#include "originalstyleattached.h"

class OriginalStyle : public OriginalStyleAttached
{
  Q_OBJECT
  Q_PROPERTY(int theme READ theme WRITE setTheme NOTIFY themeChanged)

public:
  explicit OriginalStyle(QObject *parent = nullptr);

  static OriginalStyle *qmlAttachedProperties(QObject *object);

  int theme() const;
  void setTheme(int theme);
  void setThemeByInherit(int theme);

signals:

  void themeChanged(int theme);

public slots:

protected:
  virtual void parentStyleChange(OriginalStyleAttached *style) override;

private:
  int m_theme;
  bool m_explicitTheme; //代入やバインディングで設定されたか

  void init();
  void propagateTheme();
};

QML_DECLARE_TYPEINFO(OriginalStyle, QML_HAS_ATTACHED_PROPERTIES)

#endif // ORIGINALSTYLE_H
