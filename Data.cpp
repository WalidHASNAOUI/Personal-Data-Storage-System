#include "Data.h"
#include <iostream>

// Initialize static attribute "data_count"
int Data::data_count = 0; 

// definition of the constructor 
Data::Data (int in_size)
{

    Data::data_count++;

    this->id = Data::data_count;

    this->size = in_size; 
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


