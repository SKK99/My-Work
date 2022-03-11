/*@file struct_prg.c
 * @brief A console driver
 * @author Shankar Karn
 * @Date 25-02-2022
 * Program to demonstrate the usage of structures in C
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#define SIZE 80
#define ZERO 0
/*Structure Definition*/
struct Person {
   int age;
   float weight;
   char name[SIZE];
};
/*Driver Function */
int main()
{
   struct Person *ptr = NULL;
   int n;

   printf("Enter the number of persons: ");
   scanf("%d", &n);

   /*allocating memory for n numbers of struct person*/
   ptr = (struct Person*) malloc(n * sizeof(struct Person));
   if(ptr==NULL) {
	   printf("\nMemory Overflow\n");
	   return 0;
   }
   ptr = input(ptr,n);            /*take user input*/

   printf("\nDisplaying Information:\n");
   display(ptr,n);				/*Display the content of structure*/

   printf("\nCopying the last Node:\n");
   struct Person *last = copy(ptr+n-1);		/*Function call to copy the last node*/
   display(last,1);

   printf("\nMemory Free\n");
   freeMemory(ptr);				/*Free Memory*/
   return 0;
}
