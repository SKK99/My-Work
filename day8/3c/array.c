/* @file array.c
 * @brief Function defintions for the the functions called in main
 * @author Shankar Karn
 * @date 21-02-2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#define MAX_LEN 80
/*Function definition to get the first name of the string before : */
int getFirstNames(char arr[][MAX_LEN], int rowCount, char *firstNames[]) {
	int i = 0;
	char temp[MAX_LEN];
	for( ; i<rowCount; i++) {
		char *token = strtok(arr[i], ":");
		if(token == NULL)
			return EXIT_FAILURE;
		strcpy(temp, token);
		firstNames[i] = (char *) malloc(sizeof(char) * strlen(temp));
		strcpy(firstNames[i], temp);
	}
	return EXIT_SUCCESS;
}
/*Function definition to get the last name of the string after : */
int getLastNames(char arr[][MAX_LEN], int rowCount, char *lastNames[]) {
	int i = 0;
	char temp[MAX_LEN];
	for( ; i<rowCount; i++) {
		char *token = strtok(arr[i], ":");
		token = strtok(NULL, ":");
		if(token == NULL)
			return EXIT_FAILURE;
		strcpy(temp, token);
		lastNames[i] = (char *) malloc(sizeof(char) * strlen(temp));
		strcpy(lastNames[i], temp);
	}
	return EXIT_SUCCESS;
}
