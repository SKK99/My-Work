/* @file main.c
 * @brief Console for the main function. Demonstrates the arrays operation
 * @author Shankar Karn
 * @date 21-02-2022
 */
#include <stdio.h>
#include "array.h"
#define MAX_LEN 80
int main(int argc, char *argv[]) {
	char arr[][MAX_LEN] = {"Antony:Joseph","Lata:Mary","Rajesh:Kumar","Joly:Akbar"};
	char *firstNames[MAX_LEN];
	char *lastNames[MAX_LEN];
	int rowCount = 4;
	int i=0;
	printf("1.) Get First Names\n");
	printf("2.) Get Last Names\n");
	printf("\nEnter your choice\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			getFirstNames(arr, rowCount, firstNames);
			printf("\nFirst Names Are\n");
			for(i=0; i<rowCount; i++)
				printf("%s\n",firstNames[i]);
			break;
		case 2:
			printf("\nLast Names Are\n");
			getLastNames(arr, rowCount, lastNames);
			for(i=0; i<rowCount; i++)
				printf("%s\n",lastNames[i]);
			break;
		default:
			printf("\nInvalid Choice\n");
	}
	return 0;
}
