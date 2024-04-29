#if !defined(__USER__)
#define __USER__

#include <iostream>
#include <list> 
#include "SystemNode.h"

using namespace std; 

class User
{
    private:
        int id;                    // user id
        list<int> data_list_ref;  // list of "data-id" accessible by the current user
        int node_ref;            // system node reference "id" where user data are stored 
         
    public:
        // static member {to generate user's id}
        static int user_count; 

        // static member {to store all system users}
        static list<User> all_system_users; 

        // constructor by default
        User(int ); 
        
        // getters 
        int getId(void); 
        list<int> getDataListRef(void); 
        int getNodeRef(void); 

        // Setters
        void setSystemNode(int); 

        // Create a data and append it into list of data_id
        void add_new_data(int);

        // Add new user to the storage system
        static bool create_new_user(SystemNode);

        // Get user by its id 
        static User& get_user_by_id(int );
        
};



#endif

