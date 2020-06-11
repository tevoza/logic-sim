#ifndef XOR_H
#define XOR_H

#include "node.h"

class Xor : public Node
{
public:
    Xor(const int & id);
    bool calc_state();
};

#endif // XOR_H
