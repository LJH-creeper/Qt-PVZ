#ifndef SNOWPEASHOOTER_H
#define SNOWPEASHOOTER_H

#include "plant.h"

class SnowPeashooter : public Plant
{
public:
    SnowPeashooter();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // SNOWPEASHOOTER_H
