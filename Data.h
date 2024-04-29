#if !defined(__STP__)
#define __STP__

#include <iostream>
#include <list>
#include "Data.h"

using namespace std; 

class Data
{		
	private:
		int id; 
		int size; 

	public:
		// static attribute 
		static int data_count;	

		// static member {to store all system node}	
		static list<Data> all_data; 

		// constructor
		Data(int);

		// getters 
		int getId(void); 
		int getSize(void);  

		// get data object by id 
		static Data get_data_by_id(int );
	
};


#endif