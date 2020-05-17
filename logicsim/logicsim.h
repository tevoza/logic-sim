#ifndef __LOGICSIM_H_INCLUDED__
#define __LOGICSIM_H_INCLUDED__

#include <vector>

enum node_state {UNDEFINED, OFF, ON};

class Node
{
    private:
    node_state State = UNDEFINED;
    int ID;    
    
    public:
    void printInfo();
    void defineNode(const node_state & state, const int & id);
}; 

#endif //__LOGICSIM_H_INCLUDED__
