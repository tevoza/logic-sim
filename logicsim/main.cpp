#include "input.h"
#include "node.h"
#include "net.h"
#include <iostream>
using namespace std;

int main()
{
    Net net1, net2;
    Input switch1;
 
    switch1.define_node(3, Node::node_state::ON);;
    switch1.set_id(3);
    switch1.print_info();

    net1.define_node(1, Node::node_state::UNDEFINED);
    net1.add_input(&switch1);
    net1.print_info();

    net2.define_node(2, Node::node_state::UNDEFINED);
    net2.print_info();

    net1.calc_state();
    net1.print_info();


    return 0;
}
