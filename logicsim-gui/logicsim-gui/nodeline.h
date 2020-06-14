#ifndef NODELINE_H
#define NODELINE_H

#include <QGraphicsLineItem>
#include "node.h"

//class derived from QgraphicsLineItem for easier handling lines between nodes in the circuit.
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
