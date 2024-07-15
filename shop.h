#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Shop : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int sun; //初始阳光
    explicit Shop(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addPlant(QString s, QPointF pos);
    void advance(int phase) override;
    //计数器，阳光掉落频率
    int counter;
    int time;
signals:
};

#endif // SHOP_H
