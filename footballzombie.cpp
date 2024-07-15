#include "footballzombie.h"
#include "plant.h"

FootballZombie::FootballZombie()
{
    hp = 1670;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 2.5;
    setMovie(":/img/FootballZombieWalk.gif");
}


void FootballZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/img/FootballZombieDie.gif");
            setHead(":/img/ZombieHead.gif");

        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1){
            delete this;
        }
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if (state != 1)
        {
            state = 1;
            setMovie(":/img/FootballZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/img/FootballZombieWalk.gif");
    }
    setX(x() - speed);
}
