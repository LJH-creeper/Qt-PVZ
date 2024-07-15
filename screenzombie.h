#ifndef SCREENZOMBIE_H
#define SCREENZOMBIE_H

#include "zombie.h"

class ScreenZombie : public Zombie
{
public:
    ScreenZombie();

    // QGraphicsItem interface
public:
    virtual void advance(int phase) override;
};

#endif // SCREENZOMBIE_H
