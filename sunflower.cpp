#include "sunflower.h"
#include "sun.h"
#include <QGraphicsScene>

SunFlower::SunFlower()
{
    hp = 300;
    //产阳光时间
    time = int(10.0 * 1000 / 33);
    setMovie(":/img/SunFlower.gif");
}

void SunFlower::advance(int phase)
{
    if (!phase){
        return;
    }
    update();
    if (hp <= 0){
        delete this;
    }
    else if (++counter >= time)
    {
        counter = 0;
        //pos()表示在其父项或scene中的位置
        scene()->addItem(new Sun(pos()));
    }
}


