#ifndef ORIGINALSTYLEATTACHED_H
#define ORIGINALSTYLEATTACHED_H

#include <QObject>
#include <QPointer>

class OriginalStyleAttached : public QObject
{
  Q_OBJECT
public:
  explicit OriginalStyleAttached(QObject *parent = nullptr);

  QList<OriginalStyleAttached *> childStyles() const;
  void setChildStyles(const QList<OriginalStyleAttached *> &childStyles);

  OriginalStyleAttached *parentStyle() const;
  void setParentStyle(OriginalStyleAttached *style);

signals:

public slots:

protected:
  void init();
  virtual void parentStyleChange(OriginalStyleAttached *style) = 0;

private:
  QPointer<OriginalStyleAttached> m_parentStyle;
  QList<OriginalStyleAttached *> m_childStyles;
};

#endif // ORIGINALSTYLEATTACHED_H
