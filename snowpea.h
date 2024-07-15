#ifndef SNOWPEA_H
#define SNOWPEA_H

#include "bullet.h"
#include <QPainter>

class SnowPea : public Bullet
{
public:
    SnowPea();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
private:
    //伤害
    int atk;
    //速度
    qreal speed;
};

#endif // SNOWPEA_H
