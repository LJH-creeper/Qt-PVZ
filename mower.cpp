#include "mower.h"
#include "zombie.h"

Mower::Mower(QGraphicsItem *parent)
{
    flag = false;
    speed = 270.0 * 33 / 1000;
}

QRectF Mower::boundingRect() const
{
    return QRectF(-30, -30, 60, 60);
}

void Mower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-30, -30, 60, 60), QPixmap(":/img/LawnMower.png"));
}

bool Mower::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

void Mower::advance(int phase)
{
    if(!phase){
        return;
    }
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.empty())
    {
        flag = true;
        foreach (QGraphicsItem *item, items)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            zombie->hp = 0;
        }
    }
    if (flag){
        setX(x() + speed);
    }
    if (x() > 1069){
        delete this;
    }
}
