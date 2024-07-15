#include "shop.h"
#include "card.h"
#include "plant.h"
#include "peashooter.h"
#include "sun.h"
#include "sunflower.h"
#include "repeater.h"
#include "snowpeashooter.h"
#include "cherrybomb.h"
#include "wallnut.h"
#include "potatomine.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsScene>


Shop::Shop(QGraphicsItem *parent)
{
    sun = 20000;
    counter = 0;
    time = int(7.0 * 1000 / 33);
    int n = Card::name.size();
    Card* card = nullptr;
    for(int i=0;i<n;i++){
        card = new Card(Card::name[i]);
        card->setParentItem(this);
        card->setPos(-157 + 65 * i, -2);
    }
}

QRectF Shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-270, -45, 540, 90),QPixmap(":/img/Shop.png"));
    QFont font("黑体",16,QFont::Bold);
    painter->setFont(font);
    //Qt::AlignCenter居中
    painter->drawText(QRectF(-255, 18, 65, 22),Qt::AlignCenter,QString::number(sun));
}

void Shop::addPlant(QString s, QPointF pos)
{
    //找位于pos的所有item对象
    QList<QGraphicsItem *> items = scene()->items(pos);
    //判断此地是否已存在植物
    for (QGraphicsItem *item : items){
        if (item->type() == Plant::Type){
            return;
        }
    }
    //不存在植物，种植扣除阳光
    sun -= Card::catdCostVec[Card::cardMap.at(s)];
    Plant* plant = nullptr;
    switch (Card::cardMap.at(s))
    {
    case 0:
        plant = new SunFlower; break;
    case 1:
        plant = new Peashooter; break;
    case 2:
        plant = new CherryBomb; break;
    case 3:
        plant = new WallNut; break;
    case 4:
        plant = new SnowPeashooter; break;
    case 5:
        plant = new PotatoMine; break;
    case 6:
        plant = new Repeater; break;
    }
    //设置位置
    plant->setPos(pos);
    //添加到scene
    scene()->addItem(plant);
    //获得shop的子item
    QList<QGraphicsItem *> child = childItems();
    for (QGraphicsItem* item : child){
        //将item指针转化为Card类型，如果item不是Card类型的，则card将为nullptr
        Card *card = qgraphicsitem_cast<Card *>(item);
        if(card->text == s){
            //重新冷却
            card->counter = 0;
        }
    }
}

void Shop::advance(int phase)
{
    if(!phase){
        return;
    }
    update();
    //出阳光
    if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun);
    }
}
