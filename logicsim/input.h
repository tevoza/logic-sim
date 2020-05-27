#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

#include "node.h"

class Input : public Node
{
    public:
    Input()
    {
        MAXINPUTS = 0;
        STR_NODETYPE = "INPUT";
    };
    bool calc_state();
};

#endif //__INPUT_H_INCLUDED__
