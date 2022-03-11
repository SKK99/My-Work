/***********************************************************************
*    FILENAME    : functions.c
*    DESCRIPTION : contains functions to open file, close file, read file
*                  search hash table, write file, hash function
*                  and  free the hash table
*
*    DATE         	NAME          	REFERENCE        		REASON
*    -----------------------------------------------------
	11-03-2022		Shankar Karn	Function Definition		Hashing Assignment
***************************************************************************/

/**************************HEADER FILE**************************************/
#include "header.h"

/************************FUNCTION DEFINITIONS******************************/

/**************************************************************************
 *    	FUNCTION NAME  	: hash_function
 *    	DESCRIPTION    	: Calculates index value
 *	RETURN 		: int
 **************************************************************************/
int hashCode(char *str)
{
	int index = 0;
	int str_len = strlen(str);
	int sum = 0;
	for (index = 0; index < str_len; index += 1)
	{
		sum += str[index];
	}

	return sum % HASH_TABLE_SIZE;
}
/**************************************************************************
 *    	FUNCTION NAME  	: search
 *    	DESCRIPTION    	: Searches a key
 *	RETURN 		: HT_node *
 **************************************************************************/


HT_node *search(HT_node **hashArray, char *str)
{
	/* get the hash */
	int hashIndex = hashCode(str);

	/* move in array until an empty or deleted cell */
	while (hashArray[hashIndex] != NULL)
	{

		if (strcmp(hashArray[hashIndex]->data, str) == 0)
			return hashArray[hashIndex];

		/* go to next cell */
		++hashIndex;

		/* wrap around the table */
		hashIndex %= HASH_TABLE_SIZE;
	}

	return NULL;
}
/**************************************************************************
 *    	FUNCTION NAME  	: insert
 *    	DESCRIPTION    	: Insert a node into hash table
 *	RETURN 		: void
 **************************************************************************/

void insert(HT_node **hashArray, char *str)
{
	/* Allocate a new node */
	HT_node *new = NULL;
	new = (HT_node *)calloc(1, sizeof(HT_node));
	if (NULL == new)
	{
		printf("Memory Allocation Failure\n");
		return;
	}

	new->data = (char *)calloc(strlen(str) + 1, sizeof(char));
	if (NULL == new->data)
	{
		printf("Memory Allocation Failure\n");
		free(new);
		return;
	}
	strcpy(new->data, str);
	new->next = NULL;

	/* Get the hash index */
	int hashIndex = hashCode(str);

	/* move in array until an empty or deleted cell */
	while (hashArray[hashIndex] != NULL)
	{
		/* go to next cell */
		++hashIndex;

		/* wrap around the table */
		hashIndex %= HASH_TABLE_SIZE;
	}

	hashArray[hashIndex] = new;
}
/**************************************************************************
 *    	FUNCTION NAME  	: delete
 *    	DESCRIPTION    	: Deletes an entry from hash table
 *	RETURN 		: HT_node *
 **************************************************************************/

HT_node *delete (HT_node **hashArray, char *key)
{
	/* get the hash  */
	int hashIndex = hashCode(key);

	/* move in array until an empty */
	while (hashArray[hashIndex] != NULL)
	{

		if (strcmp(hashArray[hashIndex]->data, key) == 0)
		{
			HT_node *temp = hashArray[hashIndex];

			/* assign a dummy item at deleted position */
			hashArray[hashIndex] = NULL; // changed dummy
			return temp;
		}

		/* go to next cell */
		++hashIndex;

		/* wrap around the table  */
		hashIndex %= HASH_TABLE_SIZE;
	}

	return NULL;
}
/**************************************************************************
 *    	FUNCTION NAME  	: display
 *    	DESCRIPTION    	: Shows the entry in the hash table
 *	RETURN 		: void
 **************************************************************************/

void display(HT_node **hashArray)
{
	int i = 0;

	for (i = 0; i < HASH_TABLE_SIZE; i++)
	{

		if (hashArray[i] != NULL)
			printf(" (%s)", hashArray[i]->data);
		else
			printf(" ____ ");
	}

	printf("\n");
}

/*************************************************************************
 *   FUNCTION NAME : free_hash
 *   DESCRIPTION   : frees  hash table for allocated memoey
 *   RETURN        : SUCCESS/FAILURE
 **************************************************************************/
int free_hash(HT_node **hash_table)
{
	int index = 0;
	HT_node *temp = NULL;
	for (index = 0; index < HASH_TABLE_SIZE; index += 1)
	{
		while (NULL != hash_table[index])
		{
			temp = hash_table[index];
			hash_table[index] = temp->next;
			free(temp->data);
			temp->data = NULL;
			free(temp);
			temp = NULL;
		}
	}
	return SUCCESS;
}
