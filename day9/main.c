#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#define SIZE 20

int main(int argc, char *argv[]) {
	printf("1.) 1-D array\n2.) String\n");
	printf("Enter your choice\n");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			array();
			break;
		case 2:
			string();
			break;
		default:
			printf("\nInvalid Choice\n");
	}
	return 0;
}
