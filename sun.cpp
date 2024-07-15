#include "sun.h"
#include "shop.h"
#include <QRandomGenerator>
#include <QGraphicsScene>

Sun::Sun()
{
    dest = QRandomGenerator::global()->bounded(600)+320;
    setPos(dest, 70);
    speed = 60.0 * 50 / 1000;
    counter = 0;
    time = int(10.0 * 1000 / 33);
    movie = new QMovie(":/img/Sun.gif");
    movie->start();
    //该视图只接受鼠标左键的点击事件
    setAcceptedMouseButtons(Qt::LeftButton);
}

Sun::Sun(QPointF pos)
{
    int x = pos.x() + 10;
    int y = pos.y() + 10;
    setPos(x,y);
    speed = 0;
    counter = 0;
    time = int(10.0 * 1000 / 33);
    movie = new QMovie(":/img/Sun.gif");
    movie->start();
    setAcceptedMouseButtons(Qt::LeftButton);
}

Sun::~Sun()
{
    if(movie){
        delete movie;
    }
}

QRectF Sun::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void Sun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect(), movie->currentImage());
}



void Sun::advance(int phase)
{
    if (!phase)
        return;
    update();
    //超时销毁
    if (++counter >= time){
        delete this;
    }
    else if (y() < 500){
        setY(y() + speed);
    }
}


void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //(300, 15)[0]找离最近的对象
    Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(300, 15))[0]);
    shop->sun += 25;
    //销毁
    counter = time;
    //接受事件
    event->setAccepted(true);
}
