#include "originalstyle.h"
#include <QQuickItem>
#include <QQuickWindow>

OriginalStyle::OriginalStyle(QObject *parent)
  : OriginalStyleAttached(parent)
  , m_theme(Theme::Red)
  , m_explicitTheme(false)
{
  init();
}
//アタッチするときにインスタンス作成
OriginalStyle *OriginalStyle::qmlAttachedProperties(QObject *object)
{
  return new OriginalStyle(object);
}
//テーマの取得
OriginalStyle::Theme OriginalStyle::theme() const
{
  return m_theme;
}
//テーマ（通常の値設定）                                 [1]
void OriginalStyle::setTheme(Theme theme)
{
  m_explicitTheme = true;
  if (m_theme == theme)
    return;
  m_theme = theme;
  propagateTheme();
  emit themeChanged(theme);
  emit basicColorChanged(basicColor());
}
//テーマ（受け継ぎによって値を設定）                            [2]
void OriginalStyle::setThemeByInherit(Theme theme)
{
  if (m_explicitTheme || m_theme == theme)
    return;
  m_theme = theme;
  propagateTheme();
  emit themeChanged(theme);
  emit basicColorChanged(basicColor());
}
//基本色
QColor OriginalStyle::basicColor() const
{
  if (theme() == Red)
    return QColor(0x5d, 0x15, 0x0a);
  else
    return QColor(0x0a, 0x15, 0x5d);
}
//親の情報が変更されたときに呼び出されて自分の情報を変更       [3]
void OriginalStyle::parentStyleChange(OriginalStyleAttached *style)
{
  OriginalStyle *original = qobject_cast<OriginalStyle *>(style);
  if (original)
    setThemeByInherit(original->theme());
}
//初期化
void OriginalStyle::init()
{
  //もし環境変数で設定したいなら、このあたりで読み込む
  OriginalStyleAttached::init();
}
//自分に設定したテーマを子供へ伝える                      [4]
void OriginalStyle::propagateTheme()
{
  for (OriginalStyleAttached *child : childStyles()) {
    OriginalStyle *original = qobject_cast<OriginalStyle *>(child);
    if (original)
      original->setThemeByInherit(theme());
  }
}
