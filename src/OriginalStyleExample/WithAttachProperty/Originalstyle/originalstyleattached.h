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

  QList<OriginalStyleAttached *> childStyles() const;
  void setChildStyles(const QList<OriginalStyleAttached *> &childStyles);
  OriginalStyleAttached *parentStyle() const;
  void setParentStyle(OriginalStyleAttached *style);

signals:
public slots:
protected:
  void init();
  virtual void parentStyleChange(OriginalStyleAttached *style);

private:
  QPointer<OriginalStyleAttached> m_parentStyle;
  QList<OriginalStyleAttached *> m_childStyles;

  OriginalStyleAttached *attachedStyle(const QMetaObject *type,
                                       QObject *object,
                                       bool create = false);
  OriginalStyleAttached *findParentStyle(const QMetaObject *type,
                                         QObject *object);
  QList<OriginalStyleAttached *> findChildStyles(const QMetaObject *type,
                                                 QObject *object);
};

#endif // ORIGINALSTYLEATTACHED_H
