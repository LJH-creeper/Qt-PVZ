#include "map.h"
#include "shovel.h"
#include "shop.h"
#include <QMimeData>
#include <QGraphicsScene>
#include <QDebug>

Map::Map()
{
    dragOver = false;
    //接受拖放事件
    setAcceptDrops(true);
}

QRectF Map::boundingRect() const
{
    return QRectF(-369, -235, 738, 470);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

//拖拽进入Scene
void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    //判断拖动的数据是否包含纯文本数据
    if(event->mimeData()->hasText()){
        event->setAccepted(true); //接受事件
        dragOver = true;
        update();
    }
    else{
        event->setAccepted(false); //拒绝事件
    }
}
//拖拽离开Scene
void Map::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    update();
}

void Map::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if(event->mimeData()->hasText()){
        QString s = event->mimeData()->text();
        QPointF pos = mapToScene(event->pos()); //将鼠标在项上的坐标转化为场景的坐标
        pos.setX((int(pos.x()) - 249) / 82 * 82 + 290);
        pos.setY((int(pos.y()) - 81) / 98 * 98 + 130);
        if (s == "Shovel")
        {
            Shovel *shovel = qgraphicsitem_cast<Shovel *>(scene()->items(QPointF(830, 15))[0]);
            shovel->removePlant(pos);
        }
        else
        {
            Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(300, 15))[0]);
            shop->addPlant(s, pos);
        }
    }
    update();
}
