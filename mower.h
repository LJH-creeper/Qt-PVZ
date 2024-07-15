#ifndef MOWER_H
#define MOWER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Mower : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Mower(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
private:
    bool flag;
    qreal speed;
signals:
};

#endif // MOWER_H
