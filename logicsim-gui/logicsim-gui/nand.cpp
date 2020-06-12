#include "nand.h"

Nand::Nand(const int &id)
{
    this->set_state(node_state::UNDEFINED);
    this->set_id(id);
    MAXINPUTS=-1;
    STR_NODETYPE = "NAND";
}

bool Nand::calc_state()
{
    if (m_inputs.size()<2) // AN NAND GATE WITH ONLY 1/LESS THAN 1 INPUT IS ALWAYS ON
    {
        std::cout<<"Warning: "<<m_name<<"("<<this->get_id()<<")has less than 2 inputs."<<std::endl;
        this->set_state(node_state::ON);
        return true;
    }

    int high = 0;

    for (int unsigned i = 0;i<m_inputs.size(); i++ )
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Warning: "<<this->get_id()<<" calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                this->set_state(node_state::UNDEFINED);//NAND MUST KNOW ALL INPUT STATES TO BE DEFINED
                return false;
                break;
            case node_state::OFF:
                this->set_state(node_state::ON);//NAND MUST KNOW ALL INPUT STATES TO BE DEFINED
                return true;
                break;
            case node_state::ON:
                high++;
                break;
        }
    }

    if (high == m_inputs.size())
    {
        this->set_state(node_state::OFF);
        return true;
    }
    else
    {
        this->set_state(node_state::ON);
        return true;
    }
}
