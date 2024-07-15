#ifndef PLANT_H
#define PLANT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

class Plant : public QObject, public QGraphicsItem
{
public:
    int hp;     //生命值
    int state;  //状态
    int atk;    //攻击力
    int counter; //计时
    int time;   //判断是否行动
    QMovie* movie;  //加载gif
    void setMovie(QString path);
    Plant();
    ~Plant() override;
    enum { Type = UserType + 1};
    int type() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    //碰撞判定
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;


signals:
};

#endif // PLANT_H
