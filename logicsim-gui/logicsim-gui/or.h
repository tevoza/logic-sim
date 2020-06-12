#ifndef OR_H
#define OR_H

#include "node.h"

class Or : public Node
{
public:
    Or(const int & id);
    bool calc_state();
};

#endif // OR_H
