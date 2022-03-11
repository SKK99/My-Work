/****************************************************************************
 * *
 * FILE NAME:     header.h
 * 
 * DESCRIPTION:   all declarations of the function for various sorting tech
 *
 *  DATE           		NAME            REFERENCE       REASON
 * -------------------------------------------------------------
 *  11-03-2022		Shankar Karn        Header File 	Searching and Sorting                                     
 * Copyrights 2022 Capgemini
 *
 ***************************************************************************/

/***************************************************************************
 *			Header Files					   *
 ***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>


/***************************************************************************
 *			MACRO DECLARATIONS  				   *
 ***************************************************************************/
#define MAX 30
#define SUCCESS 1
#define FAILURE -1
#define ARGC 3
#define INITIALIZE 0

/***************************************************************************
 *			Function declarations  				   *
 ***************************************************************************/
bool isnumber(char *);
void printArray(int *, int);
void quick_sort(int *,int, int);
void merge_sort(int *,int, int);
void heap_sort(int *, int);
int linear_search(int *, int, int);
int binary_search(int *, int, int, int);