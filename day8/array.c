#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"
#define N 10
#define SIZE 20
#define ZERO 0
// Function to implement search operation
void search(float a[], int n) {
	float key;		// Key to search
	printf("\nEnter the element to search ");
	scanf("%f", &key);
	int i;
	bool flag=false;	// flag to check if the key is found
	int index=-1;		// Index to find the element position
	for(i=0; i<n; i++) {
		if(a[i] == key){
			flag = true;
			index = i;
			break;
		}
	}
	if(flag==true) {
		printf("\nKey found at the index %d\n",index);
	}
	else {
		printf("\nKey not found\n");
	}
}
// Function to implement insert operation at a given pos
void insert(float a[], int n) {
	int pos;		// Position at which element is to be inserted
	float x;			// Element to be inserted
	printf("\nEnter the position and value to insert in array ");
	scanf("%d %f", &pos, &x);
	n++;			// increase the size by 1
	int i;
	// shift elements forward
	for(i=n-1; i>=pos; i--) {
		a[i] = a[i-1];
	}

	a[pos-1] = x;		// insert x at pos
	
	//print the updated array
	for(i=0; i<n; i++) {
		printf("%f ",a[i]);
	}
}
// Function to count no of vowels and consonant
void countVowelConsonant(char a[]) {
	int vowels = 0;
	int consonants = 0;	
	int i;
	char ch;
	// Take each character from this string
	for(i=0; a[i] != '\0'; i++) {
		ch = a[i];
		//If this is a vowel then increment vowel count
		if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' 
		   || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
			vowels++;
		}
		// If this is a space the skip it
		else if(ch == ' ')
			continue;
		// Else increment the consonant count
		else
			consonants++;
	}
	// Print the total count of vowels and consonants
	printf("\nVowels: %d", vowels);
	printf("\nConsonants: %d", consonants);
}
// This function adds a[][] and b[][], and stores the result in c[][]
void add(float a[][N], float b[][N], int n) {
	int i,j;				// Loop counter variables
	float c[N][N] = {ZERO};			// Resultant Matrix
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			c[i][j] = a[i][j] + b[i][j];
	//Printing the resultant matrix
	printf("\nThe resultant matrix is\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++) {
			printf("%.2f ",c[i][j]);
		}
		printf("\n");
	}
}
// This function checks the employee's user id condition
void employee(char emp[][SIZE], int n) {
	int i,j;				// Loop variables
	for(i=0; i<n; i++) {
		if(strlen(emp[i]) < 8) {	// Minimum character checking
			printf("\nUser ID %d violates minimum character condition\n",i+1);
		}
		for(j=i+1; j<n; j++) {
			if(strcmp(emp[i],emp[j]) == 0) {	// Check duplicates
				printf("User ID %d and %d are same\n",(i+1),(j+1));
			}
			if(strcmp(emp[i],emp[j]) > 0 ) {	// Organise in Ascending order
				char temp[SIZE];
				strcpy(temp,emp[i]);
				strcpy(emp[i],emp[j]);
				strcpy(emp[j],temp);	
			}
		}
	}
	// Printing in order
	printf("\nEmployee ID in order\n");
	for(i=0; i<n; i++) {
		printf("%s\n",emp[i]);
	}
}
