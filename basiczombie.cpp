#include "basiczombie.h"
#include "plant.h"
#include <QDebug>

BasicZombie::BasicZombie()
{
    hp = 270;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    // speed = 10;
    setMovie(":/img/ZombieWalk1.gif");
}

void BasicZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/img/ZombieDie.gif");
            setHead(":/img/ZombieHead.gif");
        }
        //检查是否播放到了最后一帧
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
            setMovie(":/img/ZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/img/ZombieWalk1.gif");

    }
    //移动
    setX(x() - speed);
}
