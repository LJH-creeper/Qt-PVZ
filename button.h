#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QSound>
#include <QTimer>

class Button : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Button(QSound* s,QTimer* t);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QSound* sound;
    QTimer* timer;
signals:

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // BUTTON_H
