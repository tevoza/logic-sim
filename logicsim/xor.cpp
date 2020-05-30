#include "xor.h"

bool Xor::calc_state()
{
    if (m_inputs.size() != 2)
    {
        std::cout<<"Error: "<<m_name<<"("<<this->get_id()<<")requires 2 inputs."<<std::endl;   
        this->set_state(node_state::OFF);
        return false;    
    }

    bool undefined = false;
    int on = 0;
    int off = 0;

    for (int i = 0;i<m_inputs.size(); i++ )
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Warning: "<<this->get_id()<<" calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                undefined = true;
                break;
            case node_state::OFF:
                off++;
                break;
            case node_state::ON:
                on++;
        }
        
    }
    
    if (undefined == true)
    {
        std::cout<<"Error: "<<m_name<<"("<<this->get_id()<<") cannot calculate state due to unresolved inputs"<<std::endl;
        this->set_state(node_state::UNDEFINED);
        return false;
    }

    if ((on == 1) && (off == 1))
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
