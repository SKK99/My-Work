/*
 * Solution to the problems on 1-D array and 2-D arrays
 * Author : Shankar Kumar Karn
 * Date of creation : 21-02-2022
 */
#include <stdio.h>
#include <stdlib.h>
#include "ptr2.h"
#define LIMIT 10
/*Function to print triple of the previous element till n*/
void printArray(int n) {
	int i;			//Counter variable for loop
	int num[LIMIT] = {0};
	num[0] = n;
	for(i=1; i<7; i++) {
		num[i] = num[i-1]*3;
	}

	for(i=0; i<7; i++) {
		printf("num[%d]=%d\n",i,num[i]);
	}
}
// Function to print the triangular pattern of row size n
void printPattern(int n) {
	char a[LIMIT][LIMIT];
	int i,j;		//Counter variables for loop
	for(i=0; i<n; i++){
		for(j=0;j<n;j++) {
			if(j<=i){
				a[i][j] = '*';
			}
			else {
				a[i][j] = ' ';
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++) {
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}
// Function to print triple of the previous element using dma
void printDynamicArray(int n) {
	int i;						//Counter Variable
	int *num = NULL; 	//Dynamic memory allocation
	num = (int*)malloc(n*sizeof(int)); 	//Dynamic memory allocation
	num[0] = n;

	for(i=1; i<7; i++) {
		num[i] = num[i-1]*3;
	}

	for(i=0; i<7; i++) {
		printf("num[%d]=%d\n",i,num[i]);
	
	}
	free(num);
}

//Function to print pattern of size n using DMA
void printDynamicPattern(int n) {
	int i,j; 					//Counter Variables
	char **a = NULL;	//2D Array Allocation
	a = (char**) malloc(n*sizeof(char*));	//2D Array Allocation
	for(i=0; i<n; i++) {
		a[i] = (char*)malloc(n*sizeof(char));
	}
	for(i=0; i<n; i++){
		for(j=0;j<n;j++) {
			if(j<=i){
				a[i][j] = '*';
			}
			else {
				a[i][j] = ' ';
			}
		}
	}
	printf("\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++) {
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<n; i++)
		free(a[i]);
	free(a);
}
// Function to swap to variables
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
