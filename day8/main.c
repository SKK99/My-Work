/* 
 * Driver program to demonstrate the use of 1-D array and string manipulation
 * Author : Shankar Kumar Karn
 * Date of creation : 22-02-2022
 */
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define SIZE 20
#define N 10
#define ZERO 0
// This is the main function from where all other functions will be called
int main(int argc, char *argv[]) {
	printf("Welcome\n1.Array\n2.String\n3.Add two Matrices\n4.Enter employee details\n");
	printf("Enter your choice ");
	int ch;
	scanf("%d",&ch);
	float arr[SIZE] = {ZERO};		// Array to store the array elements
	int n,i,j,choice;			// n-> size, i->counter variable, choice->user choice
	char str[SIZE];			// char array to store string input given by user
	float a[N][N];			// matrix a
	float b[N][N];			// matrix b
	char emp[SIZE][SIZE];			// employee userid
	int num;			// num of employees
	int size;			// size of matrix
	switch(ch){
		case 1:
			printf("\nEnter the size of the array ");
			scanf("%d", &n);
			printf("\nEnter the elements of the array\n");
			for(i=0; i<n; i++)
				scanf("%f",&arr[i]);
			printf("\n1.Search in 1-D array");
			printf("\n2.Insert in 1-D array");
			printf("\n\nEnter your choice ");
			scanf("%d",&choice);
			switch(choice) {
				case 1:
					search(arr,n);
					break;
				case 2:
					insert(arr,n);
					break;
				default:
					printf("\nInvalid Choice. Please try again.\n");
			}
			break;
		case 2: 	
			printf("\nEnter the string ");
			getchar();
			fgets(str,SIZE,stdin);
			countVowelConsonant(str);
			break;
		case 3:
			printf("\nEnter the size of Matrix ");
			scanf("%d",&size);
			printf("\nEnter the elements of 1st matrix\n");
			for(i=0; i<size; i++)
				for(j=0; j<size; j++)
					scanf("%f",&a[i][j]);
			printf("\nEnter the elements of 2nd matrix\n");
			for(i=0; i<size; i++)
				for(j=0; j<size; j++)
					scanf("%f",&b[i][j]);
			add(a,b,size);
			break;
		case 4:
			
			printf("\nEnter the number of employees ");
			scanf("%d",&num);
			while((getchar()) != '\n');
			for(i=0; i<num; i++) {
				printf("\nEnter userid[%d] ",i+1);
				fgets(emp[i],SIZE,stdin);
			}
			employee(emp,num);
			break;
		default:
			printf("\nInvalid Choice\n");
	}
	return 0;
}

