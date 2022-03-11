/*************************************************************************************************
 **  FILENAME	      : source.c	
 **
 **  DESCRIPTION      : This file defines functions of three functions as three thread 
 **			processes that will be cancelled and detached according to scenarios
 ** 
 **
 **  REVISION HISTORY :
 **  
 **  DATE	    NAME		   REFERENCE	    REASON
 **  -------------------------------------------------------------------------------------------
 **  8 Mar 2022     Shankar Karn             Test          Creation of the source.c
 **
 **
 **  Copyright @ 2022 Capgemini Engineering All Rights Reserved
 **
 ************************************************************************************************/

# include <header.h>
#define LEN 20
/*******************************************************************
 *   FUNCTION NAME      : storell
 * 
 *   DESCRIPTION        : Store the words in a linked list
 *   
 *   RETURN             : node pointer
 *      
 *  ******************************************************************/
node* storell(FILE **fptr, node **head) {
	char *line = NULL;
	line = (char *) malloc(1*sizeof(LEN));
	while(fscanf(*fptr, "%s", line) != EOF) {
		node *newnode = (node *) malloc(sizeof(node));
		if(newnode == NULL) {
			printf("Node cannot be created\n");
			return NULL;
		}
		node *tail = *head;		/* Tail of the linked list */
		newnode->data = (char *) malloc(sizeof(MAX));
		strcpy(newnode->data, line);
		newnode->next = NULL;

		if(*head == NULL) {
			*head = newnode;
			tail = newnode;
		}
		else {
			while(tail->next != NULL)
				tail = tail->next;
			tail->next = newnode;
		}
	}
	free(line);	
	return *head;
}
/*******************************************************************
 *   FUNCTION NAME      : display
 * 
 *   DESCRIPTION        : Display the linked list
 *   
 *   RETURN             : void
 *      
 *  ******************************************************************/
void display(node **head) {
	if(*head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	node *ptr = *head;
	while(ptr != NULL) {
		printf("%s -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
	free(ptr);
	return;
}
/*******************************************************************
 *   FUNCTION NAME      : count_occurence
 * 
 *   DESCRIPTION        : count the no of occurence of a word in the linked list
 *   
 *   RETURN             : no of occurence
 *      
 *  ******************************************************************/
int count_occurence(node **head, char *str) {
	if(*head == NULL) {
		printf("Linked List is empty\n");
		return -1;
	}
	int count = 0;
	node *ptr = *head;
	while(ptr !=  NULL) {
		if(strcmp(ptr->data, str) == 0)
			count++;
		ptr = ptr->next;
	}
	free(ptr);
	return count;
}
/*******************************************************************
 *   FUNCTION NAME      : deletenode
 * 
 *   DESCRIPTION        : delete the word in the linked list
 *   
 *   RETURN             : void
 *      
 *  ******************************************************************/
void deletenode(node **head,char *str) {
	/* Store head node */
	node *temp = *head;
	node *prev = NULL;   /*Store previous node */
	/* If head node holds the word to be deleted */
	if(temp != NULL && strcmp(temp->data, str)==0) {
		*head = temp->next;  /* Change head */
		free(temp);		/*free old head*/
		return;
	}
	/* Search for the word to be deleted, keep track of the previous node */
	while(temp != NULL && strcmp(temp->data, str) != 0) {
		prev = temp;
		temp = temp->next;
	}
	/*If word is not found */
	if(temp == NULL) {
		printf("Word is not present\n");
		return;
	}
	/* Unlink the node from linked list */
	prev->next = temp->next;
	free(temp);  /*Free memory*/
	return;
}
/*******************************************************************
 *   FUNCTION NAME      : duplicatelist
 * 
 *   DESCRIPTION        : Clone the linked list
 *   
 *   RETURN             : node *
 *      
 *  ******************************************************************/
node* duplicatelist(node **head) {
	/*  used to iterate over the original list */
    	node* current = *head;   
	/* head of the new list */ 
    	node* newList = NULL;    
	/* point to the last node in a new list */
    	node* tail = NULL;       
   	 while (current != NULL){
        	/* special case for the first new node */
        	if (newList == NULL) {
            		newList = (node*)malloc(sizeof(node));
            		newList->data = current->data;
            		newList->next = NULL;
            		tail = newList;
        	}
        	else {
            		tail->next = (node*)malloc(sizeof(node));
            		tail = tail->next;
            		tail->data = current->data;
            		tail->next = NULL;
        	}
        	current = current->next;
    	}
 	return newList;
}
/*******************************************************************
 *   FUNCTION NAME      : deletelist
 * 
 *   DESCRIPTION        : Delete the entire linked list
 *   
 *   RETURN             : void
 *      
 *  ******************************************************************/
node* deletelist(node **head) {
	node *current = *head;
	node *next;

	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	/* set head to NULL to affect it in the real head in main */
	*head = NULL;
	printf("Deleted the entire list\n");
	return *head;
}
