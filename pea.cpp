#include "pea.h"
#include "zombie.h"

Pea::Pea()
{
    atk = 25;
    speed = 360.0 * 33 / 1000;
}

QRectF Pea::boundingRect() const
{
     return QRectF(-12, -28, 24, 24);
}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap(":/img/Pea.png"));
}

bool Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

void Pea::advance(int phase)
{
    if (!phase)
        return;
    update();
    //碰到僵尸
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
        zombie->hp -= atk;
        delete this;
        return;
    }
    //子弹向右移动，超出边界销毁
    setX(x() + speed);
    if (x() > 1069)
        delete this;
}
