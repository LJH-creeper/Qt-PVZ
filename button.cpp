#include "button.h"
#include <QFont>

Button::Button(QSound *s, QTimer *t)
{
    sound = s;
    timer = t;
}

QRectF Button::boundingRect() const
{
    return QRectF(-80, -20, 160, 40);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-80, -20, 160, 40),QPixmap(":/img/Button.png"));
    QFont font("Calibri",20,QFont::Bold);
    painter->setFont(font);
    painter->setPen(Qt::green);
    if (timer->isActive()) {
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
    }
    else{
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE");
    }

}


void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if(timer->isActive()){
            sound->stop();
            timer->stop();
        }
        else{
            sound->play();
            timer->start();
        }
    }
    update();
}
