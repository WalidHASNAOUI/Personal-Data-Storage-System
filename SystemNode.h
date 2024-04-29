#if !defined(__SYSNODE__)
#define __SYSNODE__
#include <iostream>
#include <list>
#include "Data.h"
#include "SystemNode.h"

using namespace std; 


class SystemNode 
{
    private:
        int id;                         // system node id 
        int memory_capacity;            // system node memory capacity
        int remaining_memory_space;     // system node memory remaining space 
        list<int> data_list_ref;        // list of "data-id" accessible by the current user
        list<int> sytem_node_list_ref;  // list of "system-node-id" which can communicate with the current one

    public: 
        // constructor 
        SystemNode(int); 

        // static member to generate system-node ids
        static int system_node_count; 
        static list<SystemNode> all_system_nodes; 

        // Getters 
        int getId(void);
        int getMemoryCapacity(void); 
        int getRemainingMemorySpace(void); 
        list<int> getDataListRef(void); 
        list<int> getSystemNodeListRef(void); 

        // Setters 
        void setRemainingMemorySpace(int ); 

        // check the availibity of space in the current node in order to insert new data
        bool is_space_available(int); 

        // add new data into the current system node
        bool add_new_data(Data); 

        // Add new accesible system node 
        void add_new_system_node(SystemNode);

        // get system_node by its id 
        static SystemNode get_system_node_by_id(int); 

};




#endif