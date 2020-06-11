#ifndef NET_H
#define NET_H

#include "node.h"

class Net : public Node
{
public:
    Net(const int& id);
    bool calc_state();

    QRectF boundingRect() const;//coords around obj
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//draw object
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NET_H
