#include "circuit.h"

#include <iostream>
using namespace std;

int main()
{
    Circuit Adder;
    Adder.add_input("IN_A", Node::node_state::ON);
    Adder.add_input("IN_B", Node::node_state::ON);
    Adder.add_net("NET_A");
    Adder.add_net("NET_B");
    Adder.add_and("AND_CarryOut");
    Adder.add_xor("XOR_Sum");

    Adder.connect_nodes(Adder.get_node("IN_A"), Adder.get_node("NET_A"));
    Adder.connect_nodes(Adder.get_node("IN_B"), Adder.get_node("NET_B"));
    Adder.connect_nodes(Adder.get_node("NET_A"), Adder.get_node("AND_CarryOut"));
    Adder.connect_nodes(Adder.get_node("NET_A"), Adder.get_node("XOR_Sum"));
    Adder.connect_nodes(Adder.get_node("NET_B"), Adder.get_node("AND_CarryOut"));
    Adder.connect_nodes(Adder.get_node("NET_B"), Adder.get_node("XOR_Sum"));
    
    Adder.list_nodes();
    Adder.calc_circuit();
    Adder.list_nodes();
    return 0;
}
