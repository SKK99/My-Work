/*Utility functions for array manipulations*/
#include <stdio.h>
#include <string.h>
#include "array.h"
#define LIMIT 20
/*Function definition to take employee names input and print on console*/
void printArray(int size) {
       	char employee[size][LIMIT];
        int i;					 // Counter variable for loop
        printf("Enter the employee names\n");

	for(i=0; i<size; i++) {
		fgets(employee[i],LIMIT,stdin);
	 }
	for(i=0; i<size; i++){
		printf("Employee[%d]=%s\n",i,employee[i]);
	}
	printf("Enter the index to know the employee names");
	int idx;				 //Index to find employee
	scanf("%d",&idx);
	printf("\nEmployee at ith index is %s",employee[idx]);
	return;
}
/*Function definition to iniitialise the array and print on console*/
void arrayFun() {
	int n[10]; 				 //Integer array of 10 elements
	int i,j;				//Loop counter variables
	for(i=0; i<10; i++) {
		n[i] = i+100;
	}
	for(j=0; j<10; j++) {
		printf("Element[%d]=%d\n",j,n[j]);
	}
}

