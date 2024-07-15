#include "snowpea.h"
#include "zombie.h"

SnowPea::SnowPea()
{
    atk = 30;
    speed = 360.0 * 33 / 1000;
}

QRectF SnowPea::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}

void SnowPea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap(":/img/PeaSnow.png"));
}

bool SnowPea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

void SnowPea::advance(int phase)
{
    if (!phase)
        return;
    update();
    //减速
    //碰到僵尸
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[0]);
        zombie->hp -= atk;
        //判断是否被减速了
        if(zombie->speed > 0.55){
            zombie->speed /= 2;
        }
        delete this;
        return;
    }
    //子弹向右移动，超出边界销毁
    setX(x() + speed);
    if (x() > 1069)
        delete this;
}
