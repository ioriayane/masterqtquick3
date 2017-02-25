#include "originalstyle.h"

#include <QQuickItem>
#include <QDebug>
#include <QQuickWindow>

OriginalStyle::OriginalStyle(QObject *parent)
  : QObject(parent)
  , m_theme(0)
{
  init();
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
  propagateTheme();
  emit themeChanged(theme);
}

QList<OriginalStyle *> OriginalStyle::childStyles() const
{
  return m_childStyles;
}

void OriginalStyle::setChildStyles(const QList<OriginalStyle *> &childStyles)
{
  m_childStyles = childStyles;
}



static OriginalStyle *attachedStyle(const QMetaObject *type, QObject *object, bool create = false)
{
  if (!object)
    return nullptr;
  int idx = -1;
  return qobject_cast<OriginalStyle *>(qmlAttachedPropertiesObject(&idx, object, type, create));
}

static OriginalStyle *findParentStyle(const QMetaObject *type, QObject *object)
{
  QQuickItem *item = qobject_cast<QQuickItem *>(object);
  if (item) {
    // lookup parent items and popups
    QQuickItem *parent = item->parentItem();
    while (parent) {
      OriginalStyle *style = attachedStyle(type, parent);
      if (style)
        return style;

      //      QQuickPopup *popup = qobject_cast<QQuickPopup *>(parent->parent());
      //      if (popup)
      //        return attachedStyle(type, popup);

      parent = parent->parentItem();
    }

    // fallback to item's window
    //    OriginalStyle *style = attachedStyle(type, item->window());
    //    if (style)
    //      return style;
  } else {
    // lookup popup's window
    //    QQuickPopup *popup = qobject_cast<QQuickPopup *>(object);
    //    if (popup)
    //      return attachedStyle(type, popup->popupItem()->window());
  }

  // lookup parent window
  //  QQuickWindow *window = qobject_cast<QQuickWindow *>(object);
  //  if (window) {
  //    QQuickWindow *parentWindow = qobject_cast<QQuickWindow *>(window->parent());
  //    if (parentWindow) {
  //      QQuickStyleAttached *style = attachedStyle(type, window);
  //      if (style)
  //        return style;
  //    }
  //  }

  // fallback to engine (global)
  //  if (object) {
  //    QQmlEngine *engine = qmlEngine(object);
  //    if (engine) {
  //      QByteArray name = QByteArray("_q_") + type->className();
  //      QQuickStyleAttached *style = engine->property(name).value<QQuickStyleAttached*>();
  //      if (!style) {
  //        style = attachedStyle(type, engine, true);
  //        engine->setProperty(name, QVariant::fromValue(style));
  //      }
  //      return style;
  //    }
  //  }

  return nullptr;
}

static QList<OriginalStyle *> findChildStyles(const QMetaObject *type, QObject *object)
{
  QList<OriginalStyle *> children;

  QQuickItem *item = qobject_cast<QQuickItem *>(object);
  if (!item) {
    QQuickWindow *window = qobject_cast<QQuickWindow *>(object);
    if (window) {
      item = window->contentItem();

      const auto windowChildren = window->children();
      for (QObject *child : windowChildren) {
        QQuickWindow *childWindow = qobject_cast<QQuickWindow *>(child);
        if (childWindow) {
          OriginalStyle *style = attachedStyle(type, childWindow);
          if (style)
            children += style;
        }
      }
    }
  }

  if (item) {
    const auto childItems = item->childItems();
    for (QQuickItem *child : childItems) {
      OriginalStyle *style = attachedStyle(type, child);
      if (style)
        children += style;
      else
        children += findChildStyles(type, child);
    }
  }

  return children;
}

void OriginalStyle::init()
{
  OriginalStyle *style = findParentStyle(metaObject(), parent());
  if(style){
    qDebug() << "theme:" << this->theme() << ", parent theme:" << style->theme();
    setParentStyle(style);
  }else{
    qDebug() << "theme:" << this->theme() << ", not found parent";
  }

  const QList<OriginalStyle *> children = findChildStyles(metaObject(), parent());
  for (OriginalStyle *child : children){
    //見つかった子供に自分が親だと登録させる
    child->setParentStyle(this);
    qDebug() << "theme:" << this->theme() << ", child theme:" << child->theme();
  }
}

//親が見つかったら、自分の親として記録しつつ、親の子供リストに自分を追加する
void OriginalStyle::setParentStyle(OriginalStyle *style)
{
  if (m_parentStyle != style) {
    OriginalStyle *oldParent = m_parentStyle;
    if (m_parentStyle)
      m_parentStyle->m_childStyles.removeOne(this);
    m_parentStyle = style;
    if (style)
      style->m_childStyles.append(this);
    parentStyleChange(style, oldParent);
  }
}

void OriginalStyle::parentStyleChange(OriginalStyle *newParent, OriginalStyle *oldParent)
{
  Q_UNUSED(oldParent);
  //  QQuickMaterialStyle *material = qobject_cast<QQuickMaterialStyle *>(newParent);
  //  if (material) {
  //      inheritPrimary(material->m_primary, material->m_customPrimary);
  //      inheritAccent(material->m_accent, material->m_customAccent);
  //      inheritForeground(material->m_foreground, material->m_customForeground, material->m_hasForeground);
  //      inheritBackground(material->m_background, material->m_customBackground, material->m_hasBackground);
  //      inheritTheme(material->theme());
  //  }
}



void OriginalStyle::propagateTheme()
{
  qDebug() << "propagateTheme:" << m_theme;

  const auto styles = childStyles();
  for (OriginalStyle *child : styles) {
    OriginalStyle *original = qobject_cast<OriginalStyle *>(child);
    if (original){
      original->setTheme(m_theme);
      //      original->inheritTheme(m_theme);
    }
  }
}
