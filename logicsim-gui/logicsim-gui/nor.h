#ifndef NOR_H
#define NOR_H

#include "node.h"

class Nor : public Node
{
public:
    Nor(const int &id);
    bool calc_state();
};

#endif // NOR_H
