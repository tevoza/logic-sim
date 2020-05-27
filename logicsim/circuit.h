#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__

#include <vector>
#include <string>

#include "input.h"
#include "net.h"

class Circuit
{
    private:
    std::vector<Node> m_nodes;
    int m_nodeCount = 0;

    public:
    bool add_input();
    bool add_net();

    bool list_nodes();
}

#endif //__CIRCUIT_H__
