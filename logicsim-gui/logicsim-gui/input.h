#ifndef INPUT_H
#define INPUT_H

#include "node.h"

class Input : public Node
{
public:
    Input(const int &id);
    bool calc_state();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
};

#endif // INPUT_H
