//Fix the warnings in the code. Then Complete the TBD sections
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 5
#define MAX_COLS 3


void access_array()
{
    int arr[][MAX_COLS] = {
                    {1,2,3}, 
                    {4,5,6}
    };
    
    int *ptr;
    ptr = &arr[0][0];
	 /* TBD 4. Add code to
      * a) display the address of each element in array  and address of
      * arr[0], arr[1], ptr*/
      	int i = 0,j=0;
	for( ; i<2; i++) {
		for( ; j<MAX_COLS; j++) {
			printf("Address of %d is %p\n",arr[i][j], &arr[i][j]);
		}
		printf("\nAdrress of arr[%d] is %p\n", i, &arr[i]);
	}
	/* b) access and display each  row elements using ptr
     */
	for( ; ptr<=&arr[1][MAX_COLS-1]; ptr++)
		printf("%d ",*ptr);
}

int main()
{
    char arr[]="ABC";
    char *ptr2;
	
	char *ptr3 = "AB";
	char *ptr4[2];
	char **ptr5 = {NULL};
	
	char *ptr = (char*)&arr;
    //TBD1. Add code to display the address of every character in array
    	int i = 0;
	while(arr[i]) {
		printf("Address of %c is %p\n",arr[i],(ptr+i));
		i++;
	}
	
    char msg[][MAX_LENGTH] = {"AB", "gh", "er"};
	
	//TBD2. Add code to print size of variables ptr2, ptr3, ptr4, ptr[5] and give reason to justify the same
	

	
	printf("\n%lu %lu %lu %lu\n", sizeof(ptr2),sizeof(ptr3), sizeof(ptr4), sizeof(ptr5));
	
	
	ptr2 = msg[0];

	access_array();
}
