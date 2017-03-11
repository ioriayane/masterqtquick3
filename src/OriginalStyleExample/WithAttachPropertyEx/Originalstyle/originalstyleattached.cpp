#include "originalstyleattached.h"
#include <QQuickItem>
#include <QQuickWindow>

OriginalStyleAttached::OriginalStyleAttached(QObject *parent)
  : QObject(parent)
{
}
OriginalStyleAttached::~OriginalStyleAttached()
{
  //登録情報を破棄（親から自分を消す）                         [1]
  setParentStyle(nullptr);
}
QList<OriginalStyleAttached *> OriginalStyleAttached::childStyles() const
{
  return m_childStyles;
}
void OriginalStyleAttached::setChildStyles(
    const QList<OriginalStyleAttached *> &childStyles)
{
  m_childStyles = childStyles;
}
OriginalStyleAttached *OriginalStyleAttached::parentStyle() const
{
  return m_parentStyle;
}

//親が見つかったら、自分の親として記録しつつ、親の子リストに自分を追加する   [2]
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

//初期化（アタッチしている親と子の情報を探索して登録する）              [3]
void OriginalStyleAttached::init()
{
  OriginalStyleAttached *style = findParentStyle(metaObject(), parent());
  if (style) {
    //親を登録
    setParentStyle(style);
  }
  const QList<OriginalStyleAttached *> children = findChildStyles(metaObject(),
                                                                  parent());
  for (OriginalStyleAttached *child : children) {
    //見つかった子に自分が親だと登録させる
    child->setParentStyle(this);
  }
}
void OriginalStyleAttached::parentStyleChange(OriginalStyleAttached *style)
{
  Q_UNUSED(style);
}

//エレメントにアタッチしているスタイルを取得
OriginalStyleAttached* OriginalStyleAttached::attachedStyle(
    const QMetaObject *type, QObject *object, bool create)
{
  if (!object)  return nullptr;
  int idx = -1;
  return qobject_cast<OriginalStyleAttached *>(
        qmlAttachedPropertiesObject(&idx, object, type, create)
        );
}
//親エレメントに設定されたスタイルを探す                         [4]
OriginalStyleAttached* OriginalStyleAttached::findParentStyle(
    const QMetaObject *type, QObject *object)
{
  QObject *parent = object->parent();
  while (parent) {
    //大抵のエレメントの場合                               [5]
    OriginalStyleAttached *style = attachedStyle(type, parent);
    if (style)
      return style;
    //今回が最後のとき                                    [6]
    //（Popupの子供はitem->window()==nullだけど辿ると見える）
    if (parent->parent() == nullptr) {
      QQuickItem *parent_item = qobject_cast<QQuickItem *>(parent);
      if (parent_item) {
        style = attachedStyle(type, parent_item->window());
        if (style)
          return style;
      }
    }
    parent = parent->parent();
  }
  return nullptr;
}

//子エレメントでアタッチしているスタイルを探す                      [7]
QList<OriginalStyleAttached *> OriginalStyleAttached::findChildStyles(
    const QMetaObject *type, QObject *object)
{
  QList<OriginalStyleAttached *> children;
  QQuickItem *item = qobject_cast<QQuickItem *>(object);
  if (!item) {
    //Window系エレメントの子を探す                         [8]
    QQuickWindow *window = qobject_cast<QQuickWindow *>(object);
    if (window) {
      //Window系エレメントの子エレメント
      item = window->contentItem();
      //子になっているWindow系エレメント
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
  //その他のエレメントの場合                                [9]
  if (item) {
    const auto childItems = item->childItems();
    for (QQuickItem *child : childItems) {
      OriginalStyleAttached *style = attachedStyle(type, child);
      if (style)
        children += style;
      else
        children += findChildStyles(type, child); // [10]
    }
  }
  return children;
}
