#ifndef AND_H
#define AND_H

#include "node.h"

class And : public Node
{
public:
    And(const int& id);
    bool calc_state();
};

#endif // AND_H
