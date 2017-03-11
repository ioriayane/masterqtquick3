#ifndef ORIGINALSTYLEATTACHED_H
#define ORIGINALSTYLEATTACHED_H

#include <QObject>
#include <QPointer>

class OriginalStyleAttached : public QObject
{
  Q_OBJECT
public:
  explicit OriginalStyleAttached(QObject *parent = nullptr);
  ~OriginalStyleAttached();

  // setter/getter
  QList<OriginalStyleAttached *> childStyles() const;
  void setChildStyles(const QList<OriginalStyleAttached *> &childStyles);
  OriginalStyleAttached *parentStyle() const;
  void setParentStyle(OriginalStyleAttached *style);

signals:
public slots:
protected:
  void init();
  //親の変更を通知
  virtual void parentStyleChange(OriginalStyleAttached *style);

private:
  //親子関係を記憶
  QPointer<OriginalStyleAttached> m_parentStyle;
  QList<OriginalStyleAttached *> m_childStyles;
  //親子関係を調査
  OriginalStyleAttached *attachedStyle(const QMetaObject *type,
                                       QObject *object,
                                       bool create = false);
  OriginalStyleAttached *findParentStyle(const QMetaObject *type,
                                         QObject *object);
  QList<OriginalStyleAttached *> findChildStyles(const QMetaObject *type,
                                                 QObject *object);
};

#endif // ORIGINALSTYLEATTACHED_H
