/*************************************************************************************************
 **  FILENAME	      : main.c	
 **
 **  DESCRIPTION      : This file defines main function to test application
 ** 
 **
 **  REVISION HISTORY :
 **  
 **  DATE	    NAME		   REFERENCE	    		REASON
 **  -------------------------------------------------------------------------------------------
 **  8 Mar 2022     Shankar Karn            LL Assignment 1  	    Creation of the main.c
 **
 **
 **  Copyright @ 2022 Capgemini Engineering All Rights Reserved
 **
 ************************************************************************************************/
/* Include Header files */
# include <header.h>

/*******************************************************************
 **  FUNCTION NAME	: main
 **
 **  DESCRIPTION	: To test application
 **
 **  RETURN 		: EXIT_SUCCESS or EXIT_FAILURE
 **
 ******************************************************************/

int main(int argc, char *argv[]) {
	FILE *fptr = NULL;
	printf("Enter the file name \n");
	/* Take user input */
	char *name = NULL;
	name = (char *) malloc(1*sizeof(MAX));
	if(name == NULL) {
		printf("File does not exist\n");
		return EXIT_FAILURE;
	}
	fgets(name, MAX, stdin);
	name[strlen(name)-1] = 0;
	/* Opening the file */
	fptr = fopen(name, "r");
	if(fptr == NULL) {
		printf("Failed to open the file\n");
		return EXIT_FAILURE;
	}	
	/* Head of the linked list */
	node *head = NULL;	
	head = storell(&fptr, &head);    	/* store the words in singly linked list. */
	display(&head);			/* Display the linked list */
	printf("Enter the item you want to count\n");
	fgets(name, MAX, stdin);
	name[strlen(name)-1] = 0;
	printf("No of occurence of %s is %d\n", name, count_occurence(&head, name));	/* Return the occurence of a word in Linked List */
	printf("Enter the item you want to delete\n");
	fgets(name, MAX, stdin);
	name[strlen(name)-1] = 0;
	deletenode(&head, name);			/* Delete a node from the linked list */
	display(&head);				/* Display the Linked List */
	printf("Cloning the linked list\n");
	node *clonehead = NULL;			/* Head of the clone of the linked list */
	clonehead = duplicatelist(&head);	
	display(&clonehead);
	head = deletelist(&head);            	/* Delete the Linked List */
	display(&head);				/* Display the linked list */
	/* Free all the memories */
	free(head);
	free(clonehead);
	free(name);
	free(fptr);	
	return EXIT_SUCCESS;
}
