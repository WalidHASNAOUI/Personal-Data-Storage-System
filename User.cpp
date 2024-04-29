#include "User.h"
#include "Data.h"
#include "SystemNode.h"
#include <iostream>

using namespace std; 

// --------------------------------------------------------------------//
//               Initialize the static member to 0                     //
// --------------------------------------------------------------------//
int User::user_count = 0;

// --------------------------------------------------------------------//
//               Initialize the list of all system user                //
// --------------------------------------------------------------------//
list<User> User::all_system_users; 

// --------------------------------------------------------------------//
//                      Constructor without arguments                  // 
//       I use it to generate auto-increment id for each user          //
// --------------------------------------------------------------------//
User::User(int in_node_ref)
{
    // generate an auto-increment id for each new system user
    User::user_count ++;
    this->id = User::user_count; 
    this->node_ref = in_node_ref;

    // add new user to the list where all users are stored 
    User::all_system_users.push_back(*this);
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

    // add the generated data into the user's system node {this operation return true (if it's successfuly passed) or false (if not) }
    if ( SystemNode::get_system_node_by_id(this->getNodeRef()).add_new_data(d) ) 
    {
        // add this data to the list of user's data 
        this->getDataListRef().push_back(d.getId());

        // informe user that the operation was successfully passed 
        cout << "The data has been successfully added to our storage system"; 
    }

}


bool User::create_new_user(SystemNode in_sytem_node)
 {
    // check the availablity of the system node {is their is enough space}
    if ( in_sytem_node.getRemainingMemorySpace() > 0 )
    {
        // create new user {generate new user}
        User u(in_sytem_node.getId()); 

        return true; 
    }else {
        // the requested system node is not fulled : {return "false"}
        cout << "Error :: the requested node is full !" << endl; 
        return false; 
    }
}       


// --------------------------------------------------------------------//
//                       Get SystemNode by id                          // 
// --------------------------------------------------------------------//

User& User::get_user_by_id(int in_id)
{
    // declare an iterator over the list of users
    list<User>::iterator ptr = User::all_system_users.begin(); 

    // iterate over each element {each user object}
    for (ptr; ptr != User::all_system_users.end() ; ptr++)
    {
        // check if the current system node's id is the same as the argument one 
        if (ptr->getId() == in_id)
            return *ptr;  
    }
}






