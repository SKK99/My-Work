#include <stdio.h>
#include "ptr.h"
const int size=3;
const int size1=3;
// Function definition to demo the use of pointer to pointer
void pointerToPointer(int var) 
{
	int *ptr=NULL;
	int **pptr=NULL;

	ptr = &var;	//take the addtess of ptr
	pptr = &ptr;	//take the address of ptr using address of opertator &
	/*Take the value using var, ptr and pptr*/
	printf("Value of var = %d\n",var);
	printf("Value available at *ptr=%d\n", *ptr);
	printf("Value available at *pptr=%d\n", **pptr);
	printf("Address of var is %p and %p\n", &var, ptr);
	printf("Address of ptr is %p and %p\n", &ptr, pptr);
	printf("Address of pptr is %p\n", &pptr);
}
//Function definition to demo the use of pointer
void usePointer(int a) {
	int *ptr;
	ptr = &a;
	printf("Value of a is %d\n", a);
	printf("Address of a is %p\n", &a);
	printf("Address of a is %p\n", ptr);
	printf("Value of a is %d\n",*ptr);

}
// Function definition to use array of pointers
void useArrayPointer(int arr[]) {
	int *ptr[size];
	int i;
        for(i=0; i<size; i++) {
		 ptr[i] = &arr[i];
	 }
	 printf("ARRAY POINTER\n");
	 for(i=0; i<size; i++) {
		 printf("Value of arr[%d] is %d\n",i,arr[i]);
		 printf("Address of arr[%d] is %p\n",i,&arr[i]);
		 printf("Address of arr[%d] is %p\n",i,ptr[i]);
		 printf("Value of arr[%d] is %d\n",i,*ptr[i]);
	 }
}
									  
// Function definition to demonstrate the use of char pointer
void useCharPointer(char *arr[]) {
	int i;
	printf("Char POINTER\n");
	for(i=0; i<size1; i++) {
		 printf("Value of arr[%d] is %s\n",i,arr[i]);
		 printf("Address of arr[%d] is %p\n",i,&arr[i]);
	 }
}
