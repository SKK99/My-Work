/* @file array.h
 * @brief Prototypes for the function called in main.c
 * @author Shankar Karn
 * @date 21-02-2022
 */
#define MAX_LEN 80
int getFirstNames(char arr[][MAX_LEN],int rowCount, char *firstNames[]);
int getLastNames(char arr[][MAX_LEN], int rowCount, char *lastNames[]);
char* tokenize(char *str);
