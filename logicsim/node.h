#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

class Node
{
    public:
    enum class node_state {UNDEFINED, OFF, ON};

    private:
    node_state m_state = node_state::UNDEFINED;
    int m_id = 0;    

    public:
    node_state get_state();
    int get_id();
    void set_state(const node_state & state);
    void set_id(const int & id);
    void print_info();
}; 

#endif //__NODE_H_INCLUDED__
