/* @file str.h
 * @brief Function prototypes for the functions called in main
 * It shows the basic input output demonstration
 * @author Shankar Karn
 * @date 22-02-2022
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLENGTH 80
#define WORDLENGTH 20
#define TRUE 1
#define FALSE 0
#define INITIALIZE 0

void getDetails();
void printDetails();
void getDetailsStruct();
void printDetailsStruct();

struct Employee {
	char name[WORDLENGTH];
	char gender;
	int age;
	float salary;
} emp;

