#include "circuit.h"

#include <iostream>
using namespace std;
int testAdder();
void print_help();

//main function will just handle all input commands
int main(int argc, char** argv)
{    
    if (argc == 1)
    {
        cout << "error: logicsim expects arguments\n"; 
        print_help();
        return 0; 
    }
    return 0;
}

int testAdder()
{
    Circuit Adder("Adder");
    Adder.add_input("IN_A", Node::node_state::OFF);
    Adder.add_input("IN_B", Node::node_state::OFF);
    Adder.add_net("NET_A");
    Adder.add_net("NET_B");
    Adder.add_and("AND_CarryOut");
    Adder.add_xor("XOR_Sum");
    Adder.add_xor("XOR_HI");

    Adder.connect_nodes(Adder.get_node("IN_A"), Adder.get_node("NET_A"));
    Adder.connect_nodes(Adder.get_node("IN_B"), Adder.get_node("NET_B"));
    Adder.connect_nodes(Adder.get_node("NET_A"), Adder.get_node("AND_CarryOut"));
    Adder.connect_nodes(Adder.get_node("NET_A"), Adder.get_node("XOR_Sum"));
    Adder.connect_nodes(Adder.get_node("NET_B"), Adder.get_node("AND_CarryOut"));
    Adder.connect_nodes(Adder.get_node("NET_B"), Adder.get_node("XOR_Sum"));
    
    //Adder.list_nodes();
    Adder.calc_circuit();
    //Adder.list_nodes();
    return 0;
}

void print_help()
{
    cout << "usage:\n";
    cout << "logicsim new <CircuitName> \t\t\t\t-define new circuit for adding gates\n";
    cout << "logicsim <circuitName> add <gateType> <gateName> <state>(optional) -Add gate to circuit\n";
    cout << "logicsim <circuitName> delete <gateName>\t\t-Delete gate from circuit\n";
    cout << "logicsim <circuitName> connect <GateA> <GateB>\t\t-connects OUTPUT of gateA to INPUT of GateB\n";
    cout << "logicsim <circuitName> disconnect <GateA> <GateB>\t-disconnects OUTPUT of gateA to INPUT of GateB\n";
    cout << "logicsim <circuitName> info \t\t-list info about all connected nodes in circuit\n";
}
