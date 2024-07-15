#ifndef SUN_H
#define SUN_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QGraphicsSceneMouseEvent>

class Sun : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    Sun();
    //向日葵使用
    Sun(QPointF pos);
    ~Sun();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
private:
    int dest;
    QMovie *movie;
    int counter;
    //停留时间
    int time;
    qreal speed;

signals:

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SUN_H
