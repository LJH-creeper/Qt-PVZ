#include "shovel.h"
#include "plant.h"
#include <QCursor>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QGraphicsScene>
#include <QWidget>
#include <QDebug>

Shovel::Shovel(QGraphicsItem *parent)
{

}

QRectF Shovel::boundingRect() const
{
    return QRectF(-40, -40, 80, 80);
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-40, -40, 80, 80),QPixmap(":/img/ShovelBank.png"));
    painter->drawPixmap(QRect(-35, -35, 70, 70),QPixmap(":/img/Shovel.png"));
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
        < QApplication::startDragDistance())
    {
        return;
    }
    //拖动
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/img/Shovel.png");
    mime->setText("shovel");
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(70, 70));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}

void Shovel::removePlant(QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    for (QGraphicsItem *item : items){
        if (item->type() == Plant::Type)
        {
            delete item;
            return;
        }
    }
}
