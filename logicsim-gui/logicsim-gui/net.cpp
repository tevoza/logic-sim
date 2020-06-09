#include "net.h"

Net::Net()
{

}
QRectF Net::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void Net::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if (pressed)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::black);
    }
    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}

void Net::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Net::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
