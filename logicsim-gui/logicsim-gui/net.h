#ifndef NET_H
#define NET_H

#include "node.h"

class Net : public Node
{
public:
    Net(const int& id);
    bool calc_state();
};

#endif // NET_H
