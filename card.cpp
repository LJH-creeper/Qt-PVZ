#include "card.h"
#include <QFont>
#include <QDebug>
#include <QCursor>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include "shop.h"

const std::map<QString,int> Card::cardMap = {
    {"SunFlower", 0},   //向日葵
    {"Peashooter", 1},  //单发豌豆
    {"CherryBomb", 2},  //樱桃炸弹
    {"WallNut", 3},     //坚果
    {"SnowPea", 4},     //寒冰豌豆
    {"PotatoMine", 5},  //土豆雷
    {"Repeater", 6}     //双发豌豆
};
const std::vector<QString> Card::name = {"SunFlower",
                                   "Peashooter",
                                   "CherryBomb",
                                   "WallNut",
                                   "SnowPea",
                                   "PotatoMine",
                                   "Repeater"};
//植物价格
const std::vector<int> Card::catdCostVec = {50,100,150,50,175,25,200};
//植物冷却时间
const std::vector<int> Card::catdCoolVec = {200, 200, 600, 400, 200, 400, 200};
// const std::vector<int> Card::catdCoolVec = {0, 0, 0, 0, 0, 0, 0};

Card::Card(QGraphicsItem *parent)
{

}

Card::Card(QString s)
{
    text = s;
    counter = 0;
}

QRectF Card::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(":/img/Card.png"));
    painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap(":/img/"+ text +".png"));
    QFont font("黑体",12,QFont::Bold);
    painter->setFont(font);
    painter->drawText(-30, 60,QString().asprintf("%3d", catdCostVec[cardMap.at(text)]));

    //冷却
    if (counter < catdCoolVec[cardMap.at(text)])
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / catdCoolVec[cardMap.at(text)])));
    }
}

void Card::advance(int phase)
{
    if(!phase){
        return;
    }
    update();
    if(counter < catdCoolVec[cardMap.at(text)]){
        counter++;
    }
}


void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //判断是否冷却完毕
    if(counter < catdCoolVec[cardMap.at(text)]){
        event->setAccepted(false);
    }
    //判断阳光是否够
    Shop *shop = qgraphicsitem_cast<Shop *>(parentItem());
    if(catdCostVec[cardMap.at(text)] > shop->sun){
        event->setAccepted(false);
    }
    setCursor(Qt::ArrowCursor);
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
        < QApplication::startDragDistance())
    {
        return;
    }
    QDrag *drag = new QDrag(this);
    QMimeData *mime = new QMimeData;
    QImage image(":/img/" + text + ".png");
    mime->setText(text);
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}
