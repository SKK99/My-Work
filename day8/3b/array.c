/* @file array.c
 * @brief Function definitions for the array operations
 * @author Shankar Karn
 * @date 27-02-2022
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "array.h"
#define MAX_LEN 20
#define ZERO 0
#define SIZE 4
/*Function to check vowel */
int isVowel(char ch) {
    ch = toupper(ch);
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}
/*swap the content of first element (at index 0) with contents of element at  given index and return a pointer to the element at given index*/
char *swap_elements(char arr[][MAX_LEN], int index) {
    char *temp = NULL;
    if(strlen(arr[0]) > strlen(arr[index]))
    	temp = (char *)malloc(sizeof(char)*strlen(arr[0]));
    else
    	temp = (char *)malloc(sizeof(char)*strlen(arr[index]));
    strcpy(temp,arr[0]);
    strcpy(arr[0],arr[index]);
    strcpy(arr[index],temp);
    return arr[index];
}
/*Function to display the contents of array*/
void display(char arr[][MAX_LEN]) {
	int i = ZERO;
	for( ; i<SIZE; i++) 
		printf("%s  ",arr[i]);
	printf("\n");
}
/*Function to concatenate string s1 with string s2 */
char* mystrcat(char *s1, char *s2) {
	int i = ZERO;
	int j = ZERO;
	while(s1[i] != '\0')
	       i++;
	i--;
	while(s2[j] != '\0') {
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return s1;
}
/* Function to process the string at given index and remove all vowel characters, shift the remaining non-vowel characters and return the pointer to the updated string*/
char *remove_vowels(char arr[][MAX_LEN], int index) {
	int i = ZERO;
	int j = ZERO;
	char str[MAX_LEN];
	for(; arr[index][i]; i++) {
		if(isVowel(arr[index][i])==EXIT_FAILURE) {
			str[j++] = arr[index][i];
		}
	}
	str[j] = '\0';
	strcpy(arr[index], str);
	return arr[index];
}

