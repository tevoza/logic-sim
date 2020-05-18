#include "input.h"
#include <iostream>

void Input::add_output(Node *out_node)
{
    m_outputs.push_back(out_node);
}

void Input::input_list()
{
    this->print_info();   
    std::cout << "connects to nodes: ";
    for (int i = 0; i < m_outputs.size(); i++)
    {
        m_outputs[i]->print_info();
    }
}
