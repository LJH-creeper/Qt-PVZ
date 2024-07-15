#include "wallnut.h"

WallNut::WallNut()
{
    hp = 4000;
    setMovie(":/img/WallNut.gif");
}

void WallNut::advance(int phase)
{
    if (!phase){
        return;
    }
    update();
    if (hp <= 0){
        delete this;
    }
    else if (hp <= 1333 && state != 2)
    {
        state = 2;
        setMovie(":/img/WallNut2.gif");
    }
    else if (1333 < hp && hp <= 2667 && state != 1)
    {
        state = 1;
        setMovie(":/img/WallNut1.gif");
    }
}
