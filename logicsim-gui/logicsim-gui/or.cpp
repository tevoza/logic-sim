#include "or.h"

Or::Or(const int & id)
{
    this->set_state(node_state::UNDEFINED);
    this->set_id(id);
    MAXINPUTS=-1;
    STR_NODETYPE = "OR";
}

bool Or::calc_state()
{
    if (m_inputs.size()<2) //less than 2 inputs
    {
        std::cout<<"Warning: "<<m_name<<"("<<this->get_id()<<")calculating state from 1 input."<<std::endl;
        this->set_state(m_inputs[0]->get_state());//disconnected input is 0 so result is whatever this node is
        return false;
    }
    int off = 0;
    for (unsigned int i = 0; i<m_inputs.size(); i++)
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Warning: "<<this->get_id()<<" calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                this->set_state(node_state::UNDEFINED);
                return false;
                break;
            case node_state::ON:
                this->set_state(node_state::ON);
                return true;
                break;
            case node_state::OFF:
                off++;
                break;
        }
    }
    if (off == m_inputs.size())
    {
        this->set_state(node_state::OFF);//NAND MUST KNOW ALL INPUT STATES TO BE DEFINED
        return true;
    }
    else
    {
        this->set_state(node_state::ON);//NAND MUST KNOW ALL INPUT STATES TO BE DEFINED
        return true;
    }
}
