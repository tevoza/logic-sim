#ifndef NODELINE_H
#define NODELINE_H

#include <QGraphicsLineItem>
#include "node.h"

class NodeLine : public QGraphicsLineItem
{
private:
    Node *src;
    Node *dest;

public:
    NodeLine(Node *in, Node *out);
    void updateLine();
};

#endif // NODELINE_H
