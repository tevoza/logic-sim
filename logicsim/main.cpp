#include "node.h"
#include <iostream>
using namespace std;

int main()
{
    Node electro;
    electro.set_state(Node::node_state::OFF);
    electro.set_id(10);
    electro.print_info();
    return 0;
}
