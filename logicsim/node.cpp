#include "node.h"
#include <iostream>

void Node::set_state(const node_state & state);
{
    this->m_state = state;
}

void Node::set_id(const int & id);
{
    this->m_id = id;
}

void Node::print_info()
{
    std::cout << "NODE " << this->ID << " CURRENTLY IN STATE: ";
    switch(this->m_state)
    {
        case UNDEFINED:
            std::cout << "UNDEFINED";
            break;
        case OFF:
            std:cout << "OFF";
            break;
        case ON:
            std:cout << "ON";
            break;
    }
}
