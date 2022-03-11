/*@file str.h
 * @brief Function prototypes for the functions called in main
 * @author Shankar Karn
 * @date 23-02-2022
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLENGTH 80
#define WORDLENGTH 20
#define TRUE 1
#define FALSE 0
#define INITIALIZE 0

void getSentence(char *);
void printWordsInLine(char *);
int sizeLongestWord(char *);
void removeWordContainingSubstring(char *);
void printLineWithoutWhitespace(char *);
int replaceWhitespace(char *);
