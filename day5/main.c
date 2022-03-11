/*This is the main function from where all the functions will be called*/
#include<stdio.h>
#include "array.h"
#define SIZE 5
int main(int argc, char *argv[]) {
	printf("Calling printArray() from main\n");
	printArray(SIZE);
	return 0;
}
