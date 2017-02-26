#include "originalstyleattached.h"
#include <QQuickItem>
#include <QQuickWindow>

OriginalStyleAttached::OriginalStyleAttached(QObject *parent)
  : QObject(parent)
{
}
//エレメントにアタッチしているスタイルを取得
static OriginalStyleAttached *attachedStyle(const QMetaObject *type, QObject *object, bool create = false)
{
  if (!object)  return nullptr;
  int idx = -1;
  return qobject_cast<OriginalStyleAttached *>(qmlAttachedPropertiesObject(&idx, object, type, create));
}
//親エレメントに設定されたスタイルを探す
static OriginalStyleAttached *findParentStyle(const QMetaObject *type, QObject *object)
{
  QObject *parent = object->parent();
  while (parent) {
    qDebug() << "classname:" << type->className()
             << "/" <<  parent->metaObject()->className();
    //大抵のエレメント
    OriginalStyleAttached *style = attachedStyle(type, parent);
    if (style)
      return style;
    //Windows系のエレメントの場合
    QQuickItem *parent_item = qobject_cast<QQuickItem *>(parent);
    if (parent_item) {
      style = attachedStyle(type, parent_item->window());
      if (style)
        return style;
    }
    parent = parent->parent();
  }

  return nullptr;
  QQuickItem *item = qobject_cast<QQuickItem *>(object);
//  if (!item) {
//    item = qobject_cast<QQuickItem *>(object->parent());
//  }
  if (item) {
    //親エレメント（Item）を探す
    QQuickItem *parent = item->parentItem();
    while (parent) {
      OriginalStyleAttached *style = attachedStyle(type, parent);
      if (style) {
        return style;
      }

      //Popupエレメントにアタッチしたスタイルを探す
      //parentItem()を辿ると  : QQuickItem->QQuickPopupItem->QQuickOverlay
      //parent()を辿ると      : QQuickItem->QQuickPopupItem->QQuickPopup_QML_2
      //なので、先に見極める
      //QQuickPopup_QML_2だったりQQuickPopupだったりするかもしれない・・・
      qDebug() << "1:classname:" << type->className()
               << "/" << parent->metaObject()->className()
               << "/" << parent->parent();
      if (parent->parent()) {
        QString name = QString(parent->parent()->metaObject()->className());
        if (name.indexOf(QStringLiteral("QQuickPopup_")) == 0
            || name == QStringLiteral("QQuickPopup")) {
          OriginalStyleAttached *style = attachedStyle(type, parent->parent());
          if (style)
            return style;
        }
      }
      parent = parent->parentItem();
    }
    //Window系エレメント（ApplicationWindow）
    OriginalStyleAttached *style = attachedStyle(type, item->window());
    if (style) {
      return style;
    }
  } else {
    qDebug() << "2:classname:" << type->className()
             << "/" <<  object->metaObject()->className();

    QObject *parent = object->parent();
    while (parent) {
      qDebug() << "3:classname:" << type->className()
               << "/" <<  parent->metaObject()->className();
      OriginalStyleAttached *style = attachedStyle(type, parent);
      if (style)
        return style;
      QQuickItem *parent_item = qobject_cast<QQuickItem *>(parent);
      if (parent_item) {
        style = attachedStyle(type, parent_item->window());
        if (style)
          return style;
      }
      parent = parent->parent();
    }

    //objectがQQuickItemにキャストできないクラスなので一旦QObjectのまま親を辿る
    //    QString name = QString(object->metaObject()->className());
    //    if (name.indexOf(QStringLiteral("QQuickPopup_")) == 0
    //        || name == QStringLiteral("QQuickPopup")) {
//    QQuickItem *item = qobject_cast<QQuickItem *>(object->parent());
//    if(item){
//      OriginalStyleAttached *style = attachedStyle(type, item->window());
//      if (style)
//        return style;
//    }

    // lookup popup's window
    //    QQuickPopup *popup = qobject_cast<QQuickPopup *>(object);
    //    if (popup)
    //      return attachedStyle(type, popup->popupItem()->window());
  }

  //??? ダイアログなどが別ウインドウになっているときの親ウインドウ でもない
  QQuickWindow *window = qobject_cast<QQuickWindow *>(object);
  if (window) {
    QQuickWindow *parentWindow = qobject_cast<QQuickWindow *>(window->parent());
    if (parentWindow) {
      OriginalStyleAttached *style = attachedStyle(type, window);
      if (style)
        return style;
    }
  }
  return nullptr;
}
//子供のエレメントでアタッチしているスタイルを探す
static QList<OriginalStyleAttached *> findChildStyles(const QMetaObject *type, QObject *object)
{
  QList<OriginalStyleAttached *> children;

  QQuickItem *item = qobject_cast<QQuickItem *>(object);
  if (!item) {
    QQuickWindow *window = qobject_cast<QQuickWindow *>(object);
    if (window) {
      item = window->contentItem();

      const auto windowChildren = window->children();
      for (QObject *child : windowChildren) {
        QQuickWindow *childWindow = qobject_cast<QQuickWindow *>(child);
        if (childWindow) {
          OriginalStyleAttached *style = attachedStyle(type, childWindow);
          if (style)
            children += style;
        }
      }
    }
  }

  if (item) {
    const auto childItems = item->childItems();
    for (QQuickItem *child : childItems) {
      OriginalStyleAttached *style = attachedStyle(type, child);
      if (style)
        children += style;
      else
        children += findChildStyles(type, child);
    }
  }

  return children;
}

QList<OriginalStyleAttached *> OriginalStyleAttached::childStyles() const
{
  return m_childStyles;
}
void OriginalStyleAttached::setChildStyles(const QList<OriginalStyleAttached *> &childStyles)
{
  m_childStyles = childStyles;
}
OriginalStyleAttached *OriginalStyleAttached::parentStyle() const
{
  return m_parentStyle;
}
//親が見つかったら、自分の親として記録しつつ、親の子供リストに自分を追加する
void OriginalStyleAttached::setParentStyle(OriginalStyleAttached *style)
{
  if(m_parentStyle != style){
    if (m_parentStyle) {
      m_parentStyle->m_childStyles.removeOne(this);
    }
    m_parentStyle = style;
    if (style) {
      style->m_childStyles.append(this);
    }
    parentStyleChange(style);
  }
}
//初期化（アタッチしている親と子供の情報を検索して登録する）
void OriginalStyleAttached::init()
{
  OriginalStyleAttached *style = findParentStyle(metaObject(), parent());
  if (style) {
    setParentStyle(style);
    qDebug() << "found parent";
  }

  const QList<OriginalStyleAttached *> children = findChildStyles(metaObject(), parent());
  for (OriginalStyleAttached *child : children) {
    //見つかった子供に自分が親だと登録させる
    child->setParentStyle(this);
  }
}
