#include "originalstyle.h"

#include <QQuickItem>

OriginalStyle::OriginalStyle(QObject *parent)
  : QObject(parent)
  , m_theme(0)
{

}

OriginalStyle *OriginalStyle::qmlAttachedProperties(QObject *object)
{
  return new OriginalStyle(object);
}

int OriginalStyle::theme() const
{
  return m_theme;
}

void OriginalStyle::setTheme(int theme)
{
  if (m_theme == theme)
    return;

  m_theme = theme;
  emit themeChanged(theme);
}
