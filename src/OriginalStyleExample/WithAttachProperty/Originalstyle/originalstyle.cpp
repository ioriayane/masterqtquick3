#include "originalstyle.h"
#include <QQuickItem>
#include <QQuickWindow>

OriginalStyle::OriginalStyle(QObject *parent)
  : QObject(parent)
  , m_theme(Theme::Red)
{
}
//アタッチするときにインスタンス作成                       [1]
OriginalStyle *OriginalStyle::qmlAttachedProperties(QObject *object)
{
  return new OriginalStyle(object);
}
//テーマの取得
OriginalStyle::Theme OriginalStyle::theme() const
{
  return m_theme;
}
//テーマ（通常の値設定）                             [2]
void OriginalStyle::setTheme(Theme theme)
{
  if (m_theme == theme)
    return;
  m_theme = theme;
  emit themeChanged(theme);
  emit basicColorChanged(basicColor());
}
//基本色                                        [3]
QColor OriginalStyle::basicColor() const
{
  if (theme() == Red)
    return QColor(0x5d, 0x15, 0x0a);
  else
    return QColor(0x0a, 0x15, 0x5d);
}
