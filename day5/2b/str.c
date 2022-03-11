/*@file str.c
 *@brief Function definition for the console
 * @author Shankar Karn
 * @date 23-02-2022
 * */
#include "str.h"
/*function to accept a sentence (that is a line) from the user.*/
void getSentence(char *line) {
	printf("Enter the sentence: ");
	fgets(line, MAXLENGTH, stdin);
	line[strcspn(line, "\n")] = 0;
}
/*function which accepts the sentence and prints one word in a line. */
void printWordsInLine(char *line) {
	int i = INITIALIZE, linelength = INITIALIZE;
	
	linelength = strlen(line);

	for(i = 0; i < linelength; i++) {
		if(line[i] == ' ')
			printf("\n");
		else
			printf("%c", line[i]);
	}
	printf("\n");
}
/*function to print the longest word in the sentence*/
int sizeLongestWord(char *line) {
	int i = INITIALIZE, curr = INITIALIZE, max = INITIALIZE, linelength = INITIALIZE;

	linelength = strlen(line);
	
	for(i = 0; i < linelength; i++) {
		if(line[i] != ' ') {
			curr++;
			if(curr>max)
				max = curr;
		}
		else {
			curr = 0;
		}
	}
	return max;
}
/*function to prompt and read a search sub string, search for the first word and remove the word and display the sentence after update*/
void removeWordContainingSubstring(char* str) {
	char substring[WORDLENGTH], copy[MAXLENGTH];
	char output[MAXLENGTH] = {'\0'};
	char *searchResult, *currentword=NULL;

	printf("Enter the substring: ");
	fgets(substring, WORDLENGTH, stdin);
	substring[strcspn(substring, "\n")] = 0;
	strcpy(copy, str);

	currentword = strtok(copy, " ");

	while(currentword != NULL) {
		searchResult = strstr(currentword, substring);

		if(searchResult == NULL) {
			printf("%s ", currentword);
			strcat(output, currentword);
			strcat(output, " ");
		}
		currentword = strtok(NULL, " ");
	}
	printf("\n");
}
/*Function to Print all words in one line without printing any whitespace*/
void printLineWithoutWhitespace(char *line) {
	int i = INITIALIZE, linelength = INITIALIZE;
	linelength = strlen(line);

	for(i = 0; i < linelength; i++) {
		if(line[i] != ' ')
			printf("%c", line[i]);
	}
	printf("\n");
}
/*function to replace all the whitespaces with "!" */
int replaceWhitespace(char* str) {
	int i = INITIALIZE, linelength = INITIALIZE, count = INITIALIZE;
	linelength = strlen(str);

	for(i = 0; i < linelength; i++) {
		if(str[i] == ' ') {
			printf("%c", '!');
			str[i] = '!';
			count++;
		}
		else
			printf("%c", str[i]);
	}
	printf("\n");
	return count;
}
