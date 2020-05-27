#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <vector>
#include <string>

//Represents the base class for any circuit element.
class Node
{
    public:
    enum class node_state {UNDEFINED, OFF, ON};

    private:
    node_state m_state = node_state::UNDEFINED;
    int m_id = 0;

    protected:
    int MAXINPUTS=-1; 
    std::string STR_NODETYPE = "NODE";
    std::vector<Node*> m_outputs;
    std::vector<Node*> m_inputs;

    public:
    void set_state(const node_state& state);
    void set_id(const int& id);
    void define_node(const int& id, const node_state& state);
    node_state get_state();
    int get_id();
    void print_info();

    bool add_output(Node *out_node);
    bool rem_output(Node *out_node);
    bool add_input(Node *in_node);
    bool rem_input(Node *in_node);
    bool calc_state();
};

#endif //__NODE_H_INCLUDED__
