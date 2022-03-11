/***************************************************************************
 * 	FILENAME     :    header.h
 * 	DESCRIPTION  :    Contains the node structure definition ,
 *                        header files and the function prototypes
 *      DATE       		NAME         	REFERENCE      		REASON
 *     -------------------------------------------------
 *		11-03-2022		Shankar Karn	Header File			Hashing Assignment
 *     Copyright @2022 Capgemini All rights reserved
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************************
 *		MACRO_DEFINITIONS
 ************************************************************************/
#define MAX 32
#define HASH_TABLE_SIZE 10
#define SUCCESS 1
#define FAILURE 0

/***************************************************************************
 *		STRUCTURE_DEFINITION
 * *************************************************************************/
typedef struct node
{
	char *data;
	struct node *next;
}HT_node;

/*******************************************************************
 * FUNCTION_PROTOTYPES
 ***********************************************************************/
int hashCode(char *);
int free_hash(HT_node **);
//HT_node* addnew_node(char *str);
void insert(HT_node **,char *);
HT_node* delete(HT_node **, char* item);
HT_node* search(HT_node **,char *key);
void display(HT_node **);
