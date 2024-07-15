#include "bucketzombie.h"
#include "plant.h"

BucketZombie::BucketZombie()
{
    hp = 1370;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie(":/img/BucketZombieWalk.gif");
}

void BucketZombie::advance(int phase)
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
            setMovie(":/img/BucketZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/img/BucketZombieWalk.gif");

    }
    //移动
    setX(x() - speed);
}



