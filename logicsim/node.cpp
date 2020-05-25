#include "node.h"
#include <iostream>

void Node::set_state(const node_state& state)
{
    this->m_state = state;
}

void Node::set_id(const int& id)
{
    this->m_id = id;
}

void Node::define_node(const int& id,const node_state& state)
{
    this->m_id = id;
    this->m_state = state;
}

void Node::print_info()
{
    std::cout << "[NODE " << this->m_id << "](NODE)\n STATE: ";
    switch(this->m_state)
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
    std::cout << std::endl;
}

Node::node_state Node::get_state()
{
    return this->m_state;
}

int Node::get_id()
{
    return this->m_id;
}
