#ifndef __XOR_H_INCLUDED__
#define __XOR_H_INCLUDED__

#include <iostream>
#include "node.h"

//XOR GATE - ONLY 2 INPUTS
class Xor : public Node
{
    public:
    Xor()
    {
        MAXINPUTS=2; 
        STR_NODETYPE = "XOR";
    }
    bool calc_state();
};
#endif //__XOR_H_INCLUDED__
