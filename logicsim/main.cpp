#include "node.h"
#include "net.h"
#include "input.h"
#include <iostream>
using namespace std;

int main()
{
    Input input1, input2;
    Net net1, net2 ;

    input1.define_node(1, "INPUT A", Node::node_state::ON);
    input2.define_node(2, "INPUT B", Node::node_state::OFF);
    net1.define_node(3, "NET 1", Node::node_state::UNDEFINED);
    net2.define_node(4, "NET 2", Node::node_state::UNDEFINED);

    net1.add_input(&input1);
    net2.add_input(&input2);

    input1.print_info();
    input2.print_info();
    net1.print_info();
    net2.print_info();
    
    net1.calc_state();
    net2.calc_state();

    input1.print_info();
    input2.print_info();
    net1.print_info();
    net2.print_info();

    std::cout<<"net size: "<<sizeof(Input)<<std::endl;
    return 0;
}
