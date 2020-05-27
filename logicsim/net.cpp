#include "net.h"
#include <iostream>

bool Net::calc_state()
{ 
    bool onFound = false;
    for (int i = 0; i<m_inputs.size(); i++)
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                return false;
                break;
            case node_state::ON:
                onFound = true;
                break;
        }
    }

    if (onFound == true)
    {
        this->set_state(node_state::ON);
        return true;
    }
    else
    {
        this->set_state(node_state::OFF);
        return false;
    }
}
