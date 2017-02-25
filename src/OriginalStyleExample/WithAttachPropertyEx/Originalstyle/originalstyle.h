#ifndef ORIGINALSTYLE_H
#define ORIGINALSTYLE_H

#include <QObject>
#include <QtQml>

class OriginalStyle : public QObject
{
  Q_OBJECT
  Q_PROPERTY(int theme READ theme WRITE setTheme NOTIFY themeChanged)

public:
  explicit OriginalStyle(QObject *parent = 0);

  static OriginalStyle *qmlAttachedProperties(QObject *object);

  int theme() const;

  QList<OriginalStyle *> childStyles() const;
  void setChildStyles(const QList<OriginalStyle *> &childStyles);

signals:

  void themeChanged(int theme);

public slots:
  void setTheme(int theme);

private:
  int m_theme;

  OriginalStyle *m_parentStyle;
  QList<OriginalStyle *> m_childStyles;
  void init();
  void setParentStyle(OriginalStyle *style);
  void parentStyleChange(OriginalStyle *newParent, OriginalStyle *oldParent);
  void propagateTheme();
};

QML_DECLARE_TYPEINFO(OriginalStyle, QML_HAS_ATTACHED_PROPERTIES)

#endif // ORIGINALSTYLE_H
