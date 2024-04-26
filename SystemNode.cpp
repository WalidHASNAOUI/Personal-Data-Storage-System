#include "SystemNode.h"
#include <iostream>
#include <list>

using namespace std;

// Initialize the static member to "0"
int SystemNode::system_node_count = 0;
// list<SystemNode> all_system_nodes; 


// Define the constructor 
SystemNode::SystemNode(int in_memory_capacity) 
{
    SystemNode::system_node_count++; 

    this->id = SystemNode::system_node_count; 
    this->memory_capacity = in_memory_capacity; 
    this->remaining_memory_space = 0 ; 

    // SystemNode::all_system_nodes.push_back(*this);
} 


// --------------------------------------------------------------------//
//                       Basic  Getters                                // 
// --------------------------------------------------------------------//
int SystemNode::getId()
{
    return this->id; 
}

int SystemNode::getMemoryCapacity()
{
    return this->memory_capacity; 
}

int SystemNode::getRemainingMemorySpace(void)
{
    return this->remaining_memory_space; 
}
  
list<int> SystemNode::getDataListRef()
{
    return this->data_list_ref; 
}
        
list<int> SystemNode::getSystemNodeListRef()
{
    return this->sytem_node_list_ref; 
}

// --------------------------------------------------------------------//
//                       Get SystemNode by id                          // 
// --------------------------------------------------------------------//
SystemNode getSystemNodeById(int in_id)
{

}



// --------------------------------------------------------------------//
//                              Setters                                // 
// --------------------------------------------------------------------//

void SystemNode::setRemainingMemorySpace(int new_space)
{
    this->remaining_memory_space = new_space; 
}




// --------------------------------------------------------------------//
//          Check the availibity of space in the current node          //
//                        in order to insert new data                  // 
// ------------------------------------------------ -------------------//

bool SystemNode::is_space_available(int data_size)
{
    return (this->getRemainingMemorySpace() > data_size); 
}

// --------------------------------------------------------------------//
//                Add new data into the current system node            //
//      Important : this function check the availabillity of space     // 
// ------------------------------------------------ -------------------//

bool SystemNode::add_new_data(Data in_data)
{
    // check if their is available space 
    if ( this->is_space_available(in_data.getSize()) )
    {
        // if yes : append the data's id  into the "data_list_ref"
        this->getDataListRef().push_back(in_data.getId()); 

        // update reamaining space of the current node 
        this->setRemainingMemorySpace(this->getRemainingMemorySpace() - in_data.getSize());

        // return "True" to be sure that the operation has succefully done 
        return true; 
    }else {
        cout << "There is not enought space on this node system (id = " << this->getId() << " )" << endl;
        return false; 
    }

}


// --------------------------------------------------------------------//
//         Add new neighbor system node (acessible system node)        //
//      Important :                                                    // 
// ------------------------------------------------ -------------------//

void SystemNode::add_new_system_node(SystemNode in_sys_node)
{
    this->getSystemNodeListRef().push_back(in_sys_node.getId()); 
}



