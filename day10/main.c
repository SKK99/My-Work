#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ptr.h"
#define SIZE 80

int main(int argc, char *argv[]) {
	char **ptr = NULL;
	char str[SIZE];
	char s[SIZE];
	printf("Enter the string\n");
	fgets(str,SIZE,stdin);
	int choice=0;
	int n=0;
	printf("1.) Count words\n");
	printf("2.) Extract and store word in heap\n");
	printf("3.) Find and replace\n");
	printf("4.) Display words\n");
	printf("5.) Free Memory\n");
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			printf("No of words in str is %d\n",countWords(str));
			break;
		case 2:
			strcpy(s, str);
			n = countWords(s);
			ptr = extractWords(str);
			display(ptr,n);
			free(ptr);
			break;
		case 3:
			findReplace(str);
			printf("%s\n",str);
			break;
		case 4:
			displayWords(str);
			break;
		case 5:
			freeMemory(str);
			break;
		default:
			printf("\nInvalid Choice\n");
	}
	return 0;
}
