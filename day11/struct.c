/*@file struct.c
  @brief Function definitions for the console driver
 *Program to demo use of structure
  Author : Shankar Karn
  Date of Creation : 25-02-2022
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#define SIZE 80
#define ZERO 0

struct Person {
   int age;
   float weight;
   char name[SIZE];
};
/*Fuction to take user input */
struct Person* input(struct Person *ptr,int n) { 
	int i = ZERO;
	for(; i < n; i++) {	
       		printf("Enter Person[%d] name, age and weight respectively:\n",i+1);
       		scanf("%s", (ptr+i)->name);
		scanf("%d %f", &(ptr+i)->age, &(ptr+i)->weight);
       		while(strlen((ptr+i)->name) > SIZE) {
	       		printf("Your name length exceeded the max limit of 80 characters\n");
	       		printf("Please Enter Name Again\n");
			scanf("%s", (ptr+i)->name);
       		}	
   	}
	return ptr;
}
/*Function to display the content of structure */
int display(struct Person *ptr, int n) {
	if(ptr == NULL || n<=ZERO)
		return EXIT_FAILURE;
	int i = ZERO;
	for(; i<n; i++) {
		printf("Person[%d] name, age and weight respectively:\n",i+1);
		printf("%s %d %f\n",(ptr+i)->name, (ptr+i)->age, (ptr+i)->weight);
	}
	return EXIT_SUCCESS;
}
/*Function to copy the last node and return it */
struct Person* copy(struct Person *ptr) {
	struct Person *last = NULL;
	last = (struct Person *) malloc(1*sizeof(struct Person));
	if(last == NULL) {
		printf("Memory Not Available\n");
		return last;
	}
	last->age = ptr->age;
	strcpy(last->name, ptr->name);
	last->weight = ptr->weight;
	return last;
}
/*Function to free the memory given in input*/
int freeMemory(struct Person *ptr) {
	if(ptr==NULL)
		return EXIT_FAILURE;
	free(ptr);
	ptr = NULL;
	printf("Memeory Freed Successfully\n");
	return EXIT_SUCCESS;
}
