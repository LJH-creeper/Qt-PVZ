#ifndef BUCKETZOMBIE_H
#define BUCKETZOMBIE_H

#include "zombie.h"

class BucketZombie : public Zombie
{
public:
    BucketZombie();


    // QGraphicsItem interface
public:
    virtual void advance(int phase) override;
};

#endif // BUCKETZOMBIE_H
