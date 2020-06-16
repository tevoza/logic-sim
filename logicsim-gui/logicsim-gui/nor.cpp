#include "nor.h"

Nor::Nor(const int &id)
{
    this->set_state(node_state::UNDEFINED);
    this->set_id(id);
    MAXINPUTS=-1;
    STR_NODETYPE = "NOR";
}

bool Nor::calc_state()
{
    //OUTPUT IS "ON" UNTILL AT LEAST 1 HIGH IS FOUND, IN WHICH CASE IT IS OFF
    bool highFound = false;
    for (int unsigned i = 0;i<m_inputs.size(); i++ )
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Warning: "<<this->get_id()<<" calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                this->set_state(node_state::UNDEFINED);
                return false;
            break;
            case node_state::OFF:
            break;
            case node_state::ON:
                highFound = true;
                this->set_state(node_state::OFF);
                return true;
            break;
        }
    }

    if (highFound == false)
    {
        this->set_state(node_state::ON);
    }
    else
    {
        this->set_state(node_state::OFF);
    }
    return true;
}
