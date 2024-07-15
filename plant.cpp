#include "plant.h"
#include "zombie.h"

Plant::Plant()
{
    movie = nullptr;
    atk = counter = state = time = 0;
}

Plant::~Plant()
{
    delete movie;
}

int Plant::type() const
{
    return Type;
}

QRectF Plant::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //movie->currentImage() 获得当前帧图像
    painter->drawImage(boundingRect(), movie->currentImage());
}

bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

void Plant::setMovie(QString path)
{
    if(movie){
        delete movie;
    }
    movie = new QMovie(path);
    movie->start();
}
