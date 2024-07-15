#include "snowpeashooter.h"
#include "snowpea.h"
#include "zombie.h"
#include <QGraphicsScene>

SnowPeashooter::SnowPeashooter()
{
    atk = 30;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/img/SnowPea.gif");
}

void SnowPeashooter::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            SnowPea* snowPea = new SnowPea;
            snowPea->setX(x() + 32);
            snowPea->setY(y());
            scene()->addItem(snowPea);
            return;
        }
    }
}

bool SnowPeashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
