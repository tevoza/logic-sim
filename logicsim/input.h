#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

#include <vector>
#include "node.h"

class Input : public Node
{
    private:
    std::vector<Node*> m_outputs;

    public:
    void add_output(Node *out_node);
    void rem_output(Node *out_node);
    void input_list();
};

#endif //__INPUT_H_INCLUDED__
