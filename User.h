#if !defined(__USER__)
#define __USER__

#include <iostream>
#include <list> 

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

        // constructor by default
        User(); 
        
        // getters 
        int getId(void); 
        list<int> getDataListRef(void); 
        int getNodeRef(void); 

        // Setters
        void setSystemNode(int); 

        // make the current user comminucate with a system node

        // Create a data and append it into list of data_id
        void add_new_data(int);

};



#endif

