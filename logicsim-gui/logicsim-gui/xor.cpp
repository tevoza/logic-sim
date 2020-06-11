#include "xor.h"

Xor::Xor(const int & id)
{
    this->set_state(node_state::UNDEFINED);
    this->set_id(id);
    MAXINPUTS=2;
    STR_NODETYPE = "XOR";
}

bool Xor::calc_state()
{
    if (m_inputs.size()<2) //
    {
        std::cout<<"Warning: "<<m_name<<"("<<this->get_id()<<")requires 2 inputs."<<std::endl;
        this->set_state(node_state::UNDEFINED);
        return false;
    }

    bool onFound = false;
    bool offFound = false;

    for(int i = 0; i<m_inputs.size(); i++)
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Warning: "<<this->get_id()<<" calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                this->set_state(node_state::UNDEFINED);
                return false;
                break;
            case node_state::OFF:
                offFound = true;
                break;
            case node_state::ON:
                onFound = true;
            break;
        }
    }

    if ((onFound) && (offFound))
    {
        this->set_state(node_state::ON);
        return true;
    }
    else
    {
        this->set_state(node_state::OFF);
        return true;
    }
}
