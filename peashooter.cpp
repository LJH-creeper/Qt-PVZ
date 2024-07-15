#include "peashooter.h"
#include <QGraphicsScene>
#include "pea.h"
#include "zombie.h"

Peashooter::Peashooter()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/img/Peashooter.gif");
}

void Peashooter::advance(int phase)
{
    if (!phase)
        return;
    update();
    //死亡销毁
    if (hp <= 0)
        delete this;
    //攻击计数器，
    else if (++counter >= time)
    {
        counter = 0;
        //当本排没有僵尸时，不发射子弹
        if (!collidingItems().isEmpty())
        {
            Pea *pea = new Pea;
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
