#include "Data.h"
#include <iostream>
#include <list>

using namespace std; 

// Initialize static attribute "data_count"
int Data::data_count = 0; 

// Initialize list of all system data 
list<Data> Data::all_data;

// definition of the constructor 
Data::Data (int in_size)
{
    
    Data::data_count++;

    this->id = Data::data_count;

    this->size = in_size; 

    Data::all_data.push_back(*this);
}

// define Getters 
int Data::getId ()
{
    return this->id; 
}

int Data::getSize()
{
    return this->size; 
}


// --------------------------------------------------------------------//
//                       Get System Data by id                         // 
// --------------------------------------------------------------------//
Data Data::get_data_by_id(int in_id)
{
    // declare an iterator over the list of all system data
    list<Data>::iterator ptr = Data::all_data.begin();

    // iterate over the list of all system data to found a data with requested id 
    for (ptr; ptr != Data::all_data.end() ; ++ptr)
    {
        if (ptr->getId() == in_id)
            return *ptr; 
    }
}



