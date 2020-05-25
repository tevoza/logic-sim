#ifndef __NET_H_INCLUDED__
#define __NET_H_INCLUDED__

#include <vector>
#include "node.h"

//A net can be thought of as a wire, or points all "electrically" connected
class Net : public Node
{
    private:
    std::vector<Node*> m_outputs;
    std::vector<Node*> m_inputs;

    public:
    bool add_output(Node *out_node);
    bool rem_output(Node *out_node);
    bool add_input(Node *in_node);
    bool rem_input(Node *in_node);
    void print_info();
};

#endif //__NET_H_INCLUDED__
