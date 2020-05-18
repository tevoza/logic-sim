#include "input.h"
#include "node.h"
#include <iostream>
using namespace std;

int main()
{
    Node net1, net2;
    Input switch1;
    
    net1.define_node(1, Node::node_state::OFF);
    net1.set_state(Node::node_state::ON);
    net1.set_id(1);
    net1.print_info();


    net2.set_state(Node::node_state::UNDEFINED);
    net2.set_id(2);
    net2.print_info();


    switch1.set_state(Node::node_state::UNDEFINED);
    switch1.set_id(3);
    switch1.add_output(&net1);
    switch1.input_list();
    return 0;
}
