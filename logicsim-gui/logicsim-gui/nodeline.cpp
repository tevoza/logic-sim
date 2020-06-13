#include "nodeline.h"

NodeLine::NodeLine(Node *in, Node *out)
{
    this->src = in;
    this->dest = out;
    updateLine();
}

void NodeLine::updateLine()
{
    this->setLine(this->src->x(), this->src->y(), this->dest->x(), this->dest->y());
}
