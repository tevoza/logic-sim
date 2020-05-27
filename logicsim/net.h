#ifndef __NET_H_INCLUDED__
#define __NET_H_INCLUDED__

#include <vector>
#include "node.h"

//A net can be thought of as a wire, or points all "electrically" connected
class Net : public Node
{
    public:
    Net()
    {
        MAXINPUTS=-1; 
        STR_NODETYPE = "NET";
    }
    bool calc_state();
};
#endif //__NET_H_INCLUDED__
