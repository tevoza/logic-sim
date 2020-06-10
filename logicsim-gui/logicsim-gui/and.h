#ifndef AND_H
#define AND_H

#include "node.h"

class And : public Node
{
public:
    And();
    bool calc_state();
    QRectF boundingRect() const;//coords around obj
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//draw object

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // AND_H
