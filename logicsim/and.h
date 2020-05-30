#ifndef __AND_H_INCLUDED__
#define __AND_H_INCLUDED__

#include <iostream>
#include "node.h"

//AND GATE
class And : public Node
{
    public:
    And()
    {
        MAXINPUTS=-1; 
        STR_NODETYPE = "AND";
    }
    bool calc_state();
};
#endif //__AND_H_INCLUDED__
