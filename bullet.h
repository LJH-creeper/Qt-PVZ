#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bullet();

signals:
};

#endif // BULLET_H
