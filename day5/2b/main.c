/*@file main.c
 * @brief A console function to demonstrate the use of string
 * @author Shankar Karn
 * @date 23=02-2022
 */
#include "str.h"

int main(int argc, char** argv) {
	int n = INITIALIZE;
	char line[MAXLENGTH];
	getSentence(line);
	printf("Printing the words in Line\n");
	printWordsInLine(line);
	printf("The longest word is of length %d.\n", sizeLongestWord(line));
	printf("Printing the line without white space\n");
	printLineWithoutWhitespace(line);
	printf("Printing the line after removing the substring\n");
	removeWordContainingSubstring(line);
	printf("Printing the line after replacing whitespace with !\n");
	n = replaceWhitespace(line);
	printf("Total no of replace done is %d\n",n);
}
