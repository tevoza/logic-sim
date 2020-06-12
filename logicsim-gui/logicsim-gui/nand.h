#ifndef NAND_H
#define NAND_H

#include "node.h"

class Nand : public Node
{
public:
    Nand(const int& id);
    bool calc_state();
};

#endif // NAND_H
