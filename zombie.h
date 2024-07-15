#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QObject>
#include <QGraphicsItem>
#include <QMovie>
#include <QPainter>

class Zombie : public QObject, public QGraphicsItem
{
public:
    int hp; //血量
    int atk; //攻击
    int state; //状态 0行走，1攻击，2死亡
    qreal speed; //速度
    QMovie* movie;
    QMovie* head;
    Zombie();
    ~Zombie() override;
    enum { Type = UserType + 2};
    int type() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void setMovie(QString path); //移动动画
    void setHead(QString path); //掉头动画
signals:
};

#endif // ZOMBIE_H
