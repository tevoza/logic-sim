#include "logicsim.h"
#include <iostream>
using namespace std;

void Node::defineNode(const node_state & state, const int & id)
{
    this->State = state;
    this->ID = id;
}

void Node::printInfo()
{
    cout << "Node " << this->ID <<endl;
} 
