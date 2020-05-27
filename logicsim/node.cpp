#include "node.h"
#include <iostream>

void Node::set_name(const char* name)
{
    m_name = name;
}

void Node::set_state(const node_state& state)
{
    this->m_state = state;
}

void Node::set_id(const int& id)
{
    this->m_id = id;
}

void Node::define_node(const int& id, const char* name, const node_state& state)
{
    this->m_id = id;
    this->m_name = name;
    this->m_state = state;
}

Node::node_state Node::get_state()
{
    return this->m_state;
}

int Node::get_id()
{
    return this->m_id;
}

std::string Node::get_name()
{
    return this->m_name;
}

void Node::print_info()
{    
    std::cout << "[" << this->get_id() << "]["<<STR_NODETYPE <<"] "<<m_name;
    std::cout <<"\n STATE: ";
    switch(this->get_state())
    {
        case node_state::UNDEFINED:
            std::cout << "UNDEFINED" << std::endl;
            break;
        case node_state::OFF:
            std::cout << "OFF" << std::endl;
            break;
        case node_state::ON:
            std::cout << "ON" << std::endl;
            break;
    }
    
    std::cout << " INPUTS("<<m_inputs.size()<<"): ";
    for (int i = 0; i<m_inputs.size(); i++)
    {
        std::cout <<(m_inputs[i]->get_name())<<"("<< (m_inputs[i]->get_id()) << "), ";
    }
    std::cout << std::endl;   

    std::cout << " OUTPUTS("<<m_outputs.size()<<"): ";
    for (int i = 0; i<m_outputs.size(); i++)
    {
        std::cout <<(m_outputs[i]->get_name())<<"("<< (m_outputs[i]->get_id()) << "), ";
    }
    
    std::cout << std::endl << std::endl;
}

bool Node::add_input(Node *in_node)
{
    //Check if reached limit cap
    if (MAXINPUTS != -1)//-1 implies unlimited inputs
    {
        if (m_inputs.size() >= MAXINPUTS)
        {
            std::cout<<"Error: cannot add more inputs" << std::endl;
            return false;
        }
    }
        
    //check if node already set as input
    bool nodeExists = false;
    int i=0;
    while((i < m_inputs.size()) && (nodeExists == false))
    {
        if (in_node == m_inputs[i])
        {
            nodeExists = true;
        }
        i++;
    }
    
    if (nodeExists == false)
    {
        m_inputs.push_back(in_node);
        //in_node->add_output(this);
        return true;
    }
    else
    {
        std::cout<<"Error: node already input"<<std::endl;
        return false;
    }
}

bool Node::rem_input(Node *in_node)
{
    bool nodeExists = false;
    int nodeID = -1;
    //check if node doesn't exist and find ID of deletion query
    int i=0;
    while((i < m_inputs.size()) && (nodeExists == false))
    {
        if (in_node == m_inputs[i])
        {
            nodeExists = true;
            nodeID = i;
        }
        i++;
    }
    
    if (nodeExists == true)
    {
        m_inputs.erase(m_inputs.begin()+nodeID);
        return true;
    }
    else
    {
        std::cout<<"Error: Node not found"<<std::endl;
        return false;
    }
}

bool Node::add_output(Node *out_node)
{
    //check if node already set as output
    bool nodeExists = false;
    int i=0;
    while((i < m_outputs.size()) && (nodeExists == false))
    {
        if (out_node == m_outputs[i])
        {
            nodeExists = true;
        }
        i++;
    }
    
    if (nodeExists == false)
    {
        m_outputs.push_back(out_node);
        return true;
    }
    else
    {
        std::cout<<"Error: Node not found"<<std::endl;
        return false;
    }
}

bool Node::rem_output(Node *out_node)
{
    bool nodeExists = false;
    int nodeID = -1;
    //check if node doesn't exist and find ID of deletion query
    int i=0;
    while((i < m_outputs.size()) && (nodeExists == false))
    {
        if (out_node == m_outputs[i])
        {
            nodeExists = true;
            nodeID = i;
        }
        i++;
    }
    
    if (nodeExists == true)
    {
        m_outputs.erase(m_outputs.begin()+nodeID);
        return true;
    }
    else
    {
        std::cout<<"Error: Node not found"<<std::endl;
        return false;
    }
}
