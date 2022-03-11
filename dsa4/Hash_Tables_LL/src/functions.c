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
 *    	FUNCTION NAME  	: insert
 *    	DESCRIPTION    	: Insert a node into hash table
 *		RETURN 		: void
 **************************************************************************/
void insert(HT_node **chain, char *value)
{
	/* create a newnode with value */
	struct node *newNode = malloc(sizeof(struct node));
	if (newNode == NULL)
	{
		printf("Node allocation failed \n");
		return;
	}
	newNode->data = (char *)malloc(MAX * sizeof(char));
	if (newNode->data == NULL)
	{
		printf("Node allocation failed\n");
		return;
	}
	strcpy(newNode->data, value);
	newNode->next = NULL;

	/* get the hash */
	int key = hashCode(value);

	/* check if chain[key] is empty */
	if (chain[key] == NULL)
		chain[key] = newNode;
	/* Handle collision */
	else
	{
		/* add the node at the end of chain[key] */
		HT_node *temp = chain[key];
		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
}
/**************************************************************************
 *    	FUNCTION NAME  	: delete
 *    	DESCRIPTION    	: Deletes an entry from hash table
 *		RETURN 		: int
 **************************************************************************/

int delete (HT_node **chain, char *value)
{
	/* get the hash */
	int key = hashCode(value);
	HT_node *temp = chain[key];
	HT_node *dealloc = NULL;
	if (temp != NULL)
	{
		if (strcmp(temp->data, value) == 0)
		{
			dealloc = temp;
			temp = temp->next;
			free(dealloc);
			return 1;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (strcmp(temp->next->data, value) == 0)
				{
					dealloc = temp->next;
					temp->next = temp->next->next;
					free(dealloc);
					return 1;
				}
				temp = temp->next;
			}
			if(strcmp(temp->data, value) == 0) {
				temp = temp->next;
				return 1;
			}
		}
	}

	return 0;
}
/**************************************************************************
 *  FUNCTION NAME  	: display
 *  DESCRIPTION    	: Shows the entry in the hash table
 *	RETURN 		: void
 **************************************************************************/

void display(HT_node **chain)
{
	int i;

	for (i = 0; i < HASH_TABLE_SIZE; i++)
	{
		HT_node *temp = chain[i];
		printf("chain[%d]-->", i);
		while (temp)
		{
			printf("%s -->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

/**************************************************************************
 * FUNCTION NAME  	: search
 *  DESCRIPTION    	: Searches a key
 *	RETURN 		: 		int
 **************************************************************************/
int search(HT_node **chain, char *str)
{
	/* get the hash */
	int key = hashCode(str);
	struct node *temp = chain[key];
	while (temp)
	{
		if (strcmp(temp->data, str) == 0)
			return 1;
		temp = temp->next;
	}
	return 0;
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
