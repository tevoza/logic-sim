#include "node.h"

Node::Node()
{
    m_pressed = false;
    setFlag(ItemIsMovable);
}

void Node::set_name(const char *name)
{
    m_name = name;
}

void Node::set_state(const Node::node_state &state)
{
    this->m_state = state;
}

void Node::set_id(const int &id)
{
    this->m_id = id;
}

void Node::define_node(const int &id, const char *name, const Node::node_state &state)
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

std::string Node::get_type_name()
{
    return this->STR_NODETYPE;
}

std::string Node::mstate_to_string(node_state state)
{
    std::string res;
    switch(state)
    {
        case node_state::UNDEFINED:
            res = "UNDEFINED";
            break;
        case node_state::OFF:
            res = "OFF";
            break;
        case node_state::ON:
            res = "ON";
            break;
    }
    return res;
}

std::string Node::print_info()
{
    std::string str = "";

    str += "["+std::to_string(this->get_id())+"]["+STR_NODETYPE+"] "+m_name;
    str += "\n STATE: "+mstate_to_string(this->get_state());
    str += "\n INPUTS("+std::to_string(m_inputs.size())+"): ";

    for (unsigned int i = 0; i<m_inputs.size(); i++)
    {
        str += (m_inputs[i]->get_name())+"("+ std::to_string(m_inputs[i]->get_id()) + "), ";
    }

    str += "\n OUTPUT("+std::to_string(m_outputs.size())+"): ";
    for (unsigned int i = 0; i<m_outputs.size(); i++)
    {
        str += (m_outputs[i]->get_name())+"("+ std::to_string(m_outputs[i]->get_id()) + "), ";
    }

    std::cout <<str<<std::endl;
    return str;
}

bool Node::add_output(Node *out_node)
{
    //check if node is self
    if (this == out_node)
    {
        std::cout<<"Error: Cannot set self to output"<<std::endl;
        return false;
    }

    //check if node already set as output
    bool alreadySet = false;
    unsigned int i=0;
    while((i < m_outputs.size()) && (alreadySet == false))
    {
        if (out_node == m_outputs[i])
        {
            alreadySet = true;
        }
        i++;
    }

    if (alreadySet == false)
    {
        m_outputs.push_back(out_node);
        return true;
    }
    else
    {
        std::cout<<"Error: Node already set"<<std::endl;
        return false;
    }
}

bool Node::rem_output(Node *out_node)
{
    bool nodeExists = false;
    int nodeID = -1;
    //check if node doesn't exist and find ID of deletion query
    unsigned int i=0;
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

bool Node::add_input(Node *in_node)
{
    //check if self
    if (this == in_node)
    {
        std::cout<<"Error: cannot add self as input"<<std::endl;
        return false;
    }

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
    unsigned int i=0;
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
    unsigned int i=0;
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


