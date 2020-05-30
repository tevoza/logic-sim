#include <iostream>
#include "circuit.h"

bool Circuit::add_input(const char* name, Node::node_state state)
{
    Input* input = new Input();
    input->define_node(m_nodeCount, name, state);
    m_nodes.push_back(input);
    m_nodeCount++;
    return true;
}

bool Circuit::add_net(const char* name)
{
    Net* net = new Net();
    net->define_node(m_nodeCount, name, Node::node_state::UNDEFINED);
    m_nodes.push_back(net);
    m_nodeCount++;
    return true;
}
    
bool Circuit::add_and(const char* name)
{
    And* new_and = new And();
    new_and->define_node(m_nodeCount, name, Node::node_state::UNDEFINED);
    m_nodes.push_back(new_and);
    m_nodeCount++;
    return true;
}
    
bool Circuit::add_xor(const char* name)
{
    Xor* new_xor = new Xor();
    new_xor->define_node(m_nodeCount, name, Node::node_state::UNDEFINED);
    m_nodes.push_back(new_xor);
    m_nodeCount++;
    return true;
}

Node* Circuit::get_node(int id)
{    
    Node *res = nullptr;
    bool found = false;
    int i = 0;
    while ((found == false) && (i < m_nodes.size()))
    {
        if (id == (m_nodes[i]->get_id()))
        {
            found = true;
            res = m_nodes[i];
        }
        i++;
    }

    if (found == false)
    {
        std::cout<<"Error: Node id not recognized"<<std::endl;
        return res;
    }
    else
    {
        return res;
    }    
}


Node* Circuit::get_node(const char* name)
{    
    Node *res = nullptr;
    bool found = false;
    int i = 0;
    while ((found == false) && (i < m_nodes.size()))
    {
        std::string nodeName = m_nodes[i]->get_name();
        if (nodeName.compare(name) == 0)
        {
            found = true;
            res = m_nodes[i];
        }
        i++;
    }

    if (found == false)
    {
        std::cout<<"Error: Node string not recognized"<<std::endl;
        return res;
    }
    else
    {
        return res;
    }    
}

bool Circuit::list_nodes()
{
    for (int i = 0; i < m_nodes.size(); i++)
    {
        m_nodes[i]->print_info();
    }
    return true;
}

bool Circuit::connect_nodes(Node* src, Node* dest)//order is important, src node outputs to dest
{
    src->add_output(dest);
    dest->add_input(src);
    return true;
}

bool Circuit::calc_circuit()
{
    std::cout<<"solving circuit..."<<std::endl;
    for (int i = 0; i < m_nodes.size(); i++)
    {
        m_nodes[i]->calc_state();     
    }
    return true;
}
