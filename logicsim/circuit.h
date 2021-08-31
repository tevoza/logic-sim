#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__

#include <vector>
#include <string>

#include "input.h"
#include "net.h"
#include "and.h"
#include "xor.h"

class Circuit
{
    private:
    std::vector<Node*> m_nodes;
    int m_nodeCount = 0;
    std::string m_name;
        
    public:
    Circuit(const char* name);
    bool add_input(const char* name, Node::node_state state);
    bool add_net(const char* name);
    bool add_and(const char* name);
    bool add_xor(const char* name);
    Node* get_node(int id);
    Node* get_node(const char* name);
    bool connect_nodes(Node* src, Node* dest);
    bool calc_circuit(); 
    bool list_nodes();
};

#endif //__CIRCUIT_H__
