#include "nodeline.h"

NodeLine::NodeLine(Node *in, Node *out)
{
    this->src = in;
    this->dest = out;
    updateLine();
}

void NodeLine::updateLine()
{
    this->setLine(this->src->x()+100, this->src->y()+50, this->dest->x(), this->dest->y()+50);
}
