#include "Data.h"
#include "User.h"
#include "SystemNode.h"
#include <iostream>

using namespace std; 

int main()
{

    cout << " ---------Users--------- " << endl; 

    Data d1(20);
    Data d2(12); 
    Data d3(40); 
    Data d4(50); 

    // checking the generating data objects 
    cout << "id: " << d1.getId() << " size : " << d1.getSize() << endl;
    cout << "id: " << d2.getId() << " size : " << d2.getSize() << endl;
    cout << "id: " << d3.getId() << " size : " << d3.getSize() << endl;
    cout << "id: " << d4.getId() << " size : " << d4.getSize() << endl;

    cout << "Our storage system has " << Data::all_data.size() << " saved data !" << endl; 

    cout << "The size of data with id = 3 is " << Data::get_data_by_id(2).getSize() << endl; 


    cout << " ---------System nodes--------- " << endl; 

    SystemNode node1(10);
    SystemNode node2(30);
    SystemNode node3(40);
    
    // checking the generating system nodes 
    cout << "id: " << node1.getId() << " memory capacity : " << node1.getMemoryCapacity() << endl;
    cout << "id: " << node2.getId() << " memory capacity : " << node2.getMemoryCapacity() << endl;
    cout << "id: " << node3.getId() << " memory capacity : " << node3.getMemoryCapacity() << endl;

    // check the size of all_system_nodes 
    cout << "Their are : " << SystemNode::all_system_nodes.size() << " system nodes" << endl; 
    cout << "the id the first system node is :: " <<SystemNode::all_system_nodes.front().getId() << endl; 

    cout << " ---------Users--------- " << endl; 
    User::create_new_user(node1); 
    User::create_new_user(node1); 

    // check the get sytem node by id 

    cout << " ---------Users operation--------- " << endl; 

    // add new data by a user 
    cout << "the size of the system node with id = 1 is : " << SystemNode::get_system_node_by_id(User::get_user_by_id(1).getNodeRef()).getRemainingMemorySpace() << endl; 
    User::get_user_by_id(1).add_new_data(5); 
    cout << "the size of the system node with id = 1 is : " << SystemNode::get_system_node_by_id(1).getRemainingMemorySpace() << endl; 





}
