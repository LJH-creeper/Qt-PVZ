#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QString>
#include <QGraphicsSceneMouseEvent>

class Card : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Card(QGraphicsItem *parent = nullptr);
    Card(QString s);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QString text;
    //计数器，计算冷却
    int counter;
    void advance(int phase) override;
public:
    const static std::map<QString,int> cardMap;
    const static std::vector<int> catdCostVec;
    const static std::vector<int> catdCoolVec;
    const static std::vector<QString> name;
signals:

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CARD_H
