#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ptr.h"
#define SIZE 80
/*Function for splitting a string and return the no of words in it */
int countWords(char str[]) {
	char *token = strtok(str, " "); /*Returns first token*/
	int count = 0; 			/*Counts no of words*/
	/*Keep finding tokens while one of the delimiters present in str[]*/
	while(token != NULL) {
		token = strtok(NULL, " ");
		count++;		/*Increment the counter*/	
	}
	return count;
}
void displayWords(char *str) {
	char *token = strtok(str, " ");
	while(token != NULL) {
		printf("%s\n",token);
		token = strtok(NULL, " ");
	}
	return;
}
int findReplace(char *str) {
	char new[SIZE];
	char old[SIZE];
	printf("Enter the old string\n");
	scanf("%s",old);
	printf("Enter the new string\n");
	scanf("%s",new);

	char* pos = strstr(str, old);
	int idx = -1;
        if(pos) {
		idx = pos-str;
        } 
	else {
		printf("the string '%s' was not found in '%s'\n", old, str);
		return EXIT_FAILURE;
	}
	char result[SIZE];
	int i = 0, j=0;
	strncpy(result, str, idx);
	strcat(result,new);
	int nextSpaceIdx = -1;
	for(i=idx; str[i]; i++){
		if(str[i] == ' '){
			nextSpaceIdx = i;
			break;
		}
	}
	if(nextSpaceIdx != -1) {
		i = nextSpaceIdx;
		j = strlen(result);
		while(str[i]){
			result[j++] = str[i++];
		}
		result[j++] = '\0';
		strcpy(str, result);
	}
	return EXIT_SUCCESS;
}
char** extractWords(char str[]) {
	char **heap = NULL;
	char strc[SIZE];
	strcpy(strc,str);
	int n = countWords(strc);
	heap = (char **) malloc(n*sizeof(char *));
	if(heap == NULL) {
		printf("No Memory\n");
		exit(0);
	}
	char *token = strtok(str, " ");
	int i=0;
	while(token != NULL) {
		heap[i] = (char *) malloc(strlen(token) * sizeof(char));
		strcpy(heap[i],token);
		token = strtok(NULL, " ");
		i++;
	}
	return heap;
}
void display(char **ptr, int n) {
       	int i = 0;
 	for( ; i<n; i++)
		printf("%s ",*(ptr+i));
	return;		
}
int freeMemory(char *str){
	if(str==NULL)
		return EXIT_FAILURE;
	free(str);
	return EXIT_SUCCESS;	
}

