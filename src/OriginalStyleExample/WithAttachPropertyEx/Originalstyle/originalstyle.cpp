#include "originalstyle.h"
#include <QQuickItem>
#include <QQuickWindow>

OriginalStyle::OriginalStyle(QObject *parent)
  : OriginalStyleAttached(parent)
  , m_theme(0)
  , m_explicitTheme(false)
{
  init();
}
//アタッチするときにインスタンス作成
OriginalStyle *OriginalStyle::qmlAttachedProperties(QObject *object)
{
  return new OriginalStyle(object);
}
//値の取得
int OriginalStyle::theme() const
{
  return m_theme;
}
//通常の値設定
void OriginalStyle::setTheme(int theme)
{
  m_explicitTheme = true;
  if (m_theme == theme)  return;

  m_theme = theme;
  propagateTheme();
  emit themeChanged(theme);
}
//継承によって値を設定
void OriginalStyle::setThemeByInherit(int theme)
{
  if (m_explicitTheme || m_theme == theme) return;

  m_theme = theme;
  propagateTheme();
  emit themeChanged(theme);
}
//親の情報が変更されたときに呼び出されて自分の情報を変更
void OriginalStyle::parentStyleChange(OriginalStyleAttached *style)
{
  OriginalStyle *original = qobject_cast<OriginalStyle *>(style);
  if (original)
    setThemeByInherit(original->theme());
}
//初期化
void OriginalStyle::init()
{
  //この辺に環境変数の呼び出し
  OriginalStyleAttached::init();
}
//自分に設定した内容を子供へ伝える
void OriginalStyle::propagateTheme()
{
  for (OriginalStyleAttached *child : childStyles()) {
    OriginalStyle *original = qobject_cast<OriginalStyle *>(child);
    if (original)
      original->setThemeByInherit(theme());
  }
}
