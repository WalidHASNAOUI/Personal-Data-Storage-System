#include "User.h"
#include "Data.h"
#include "SystemNode.h"
#include <iostream>

using namespace std; 

// Initialize the static member to 0 
int User::user_count = 0;

// ----------------------------------------------------------------------
//                      Constructor without arguments                   // 
//       I use it to generate auto-increment id for each user          //
// ----------------------------------------------------------------------
User::User()
{
    User::user_count ++;
    this->id = User::user_count; 
}

// Definition of getters 
// ----------------------------------------------------------------------
//                              Getters                                //
// ----------------------------------------------------------------------
 int User::getId()
 {
    return this->id; 
 } 

list<int> User::getDataListRef()
{
    return this->data_list_ref; 
}

int User::getNodeRef(void)
{
    return this->node_ref; 
}

// ----------------------------------------------------------------------
//         Connect the current user to a specific system node          // 
// ----------------------------------------------------------------------

void User::setSystemNode(int in_system_node_id)
{
    this->node_ref = in_system_node_id; 
} 

// ----------------------------------------------------------------------
//    Create new data and append it to list of user's personal data    // 
//      Info :                                                         //
// ----------------------------------------------------------------------

void User::add_new_data(int in_data_size)
{
    // create new data with a specific size 
    Data d(in_data_size); 

    // try to store the created data into users's system node
    

    // append its reference(id) to data_list_ref 
    this->getDataListRef().push_back(d.getId());

    
}





