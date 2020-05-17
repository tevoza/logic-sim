#ifndef __SWITCH_H_INCLUDED__
#define __SWITCH_H_INCLUDED__

#include "node.h"

class Switch : public Node
{
    public:
    void getState(const node_state & state);    

    private:
    *Node Outputs[];
};

#endif //__SWITCH_H_INCLUDED__
