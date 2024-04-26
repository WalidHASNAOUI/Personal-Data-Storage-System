#include "Data.h"
#include "User.h"
#include "SystemNode.h"
#include <iostream>

using namespace std; 

int main()
{
    Data d1(20);
    Data d2(12); 
    Data d3(40); 
    Data d4(50); 

    // checking the generating data objects 
    cout << "id: " << d1.getId() << " size : " << d1.getSize() << endl;
    cout << "id: " << d2.getId() << " size : " << d2.getSize() << endl;
    cout << "id: " << d3.getId() << " size : " << d3.getSize() << endl;
    cout << "id: " << d4.getId() << " size : " << d4.getSize() << endl;

    SystemNode node1(50);
    SystemNode node2(30);
    SystemNode node3(40);

    // checking the generating system nodes 
    cout << " ------------------ " << endl; 
    cout << "id: " << node1.getId() << " memory capacity : " << node1.getMemoryCapacity() << endl;
    cout << "id: " << node2.getId() << " memory capacity : " << node2.getMemoryCapacity() << endl;
    cout << "id: " << node3.getId() << " memory capacity : " << node3.getMemoryCapacity() << endl;

    
    User u1; 

    // SystemNode syn1; 
}
