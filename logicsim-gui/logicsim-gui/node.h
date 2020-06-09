#ifndef NODE_H
#define NODE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Node : public QGraphicsItem
{
public:
    Node();

    bool pressed;

};

#endif // NODE_H
