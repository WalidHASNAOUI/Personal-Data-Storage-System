#if !defined(__STP__)
#define __STP__

class Data
{		
	private:
		int id; 
		int size; 

	public:
		// static attribute 
		static int data_count;

		// constructor
		Data(int);

		// getters 
		int getId(void); 
		int getSize(void);  
	
};


#endif