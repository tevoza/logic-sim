#include "logicsim.h"
#include <iostream>
using namespace std;

int main()
{
    Node electro;
    electro.defineNode(OFF, 10);
    electro.printInfo();
    return 0;
}
