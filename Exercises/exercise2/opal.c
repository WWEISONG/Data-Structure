#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	typedef struct 
	{
		int year;          // 4
		int month;		   // 4
		int day;          // 4
		int hour;         // 4
		int minute;       // 4
		int secs;         // 4   
	}Date;

	typedef struct 
	{	
		int tran_number;       // 4 
		Date date;            
		char mode;             // 1 + 3
		char *stops;          // 3 + 28 // *stops  8
		int jour_number;       // 4 + 4padding
		char *fare_app;      // 8 + 2 + 2padding  // *fare_app 8
		int fare;              // 4
		int discount;          // 4
		int amount;            // 4     // goes to the end, should have a full 
	}Record;							// word if necessary 8

	Record r;
	printf("Record struct need %ld  %ldbytes\n", sizeof(r), sizeof(Date));

	return EXIT_SUCCESS;
}


// the struct has finished on a word boundary, that mean far end
// the memory of pointer pointing should not be counted, that not
// belong the struct, the pointer itself (8 bytes 64-bit PC)
// belong to the struct




// 1 + 3padding 60-63
// 4 64-67

// 8  68-75


// 1 + 7padding
// 8
// 4 + 4padding

