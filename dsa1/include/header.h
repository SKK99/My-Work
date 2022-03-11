/*************************************************************************************************
 **  FILENAME	      : header.h	
 **
 **  DESCRIPTION      : This file defines macros and method signatures for source.c
 ** 
 **
 **  REVISION HISTORY :
 **  
 **  DATE	    NAME		   REFERENCE	    REASON
 **  -------------------------------------------------------------------------------------------
 **  8 Mar 2022     Shankar Karn            Linked List  	Creation of the header.h
 **
 **
 **  Copyright @ 2022 Capgemini Engineering All Rights Reserved
 **
 ************************************************************************************************/
/* Header files */
# include <pthread.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>

# define handle_error_en(en,msg)\
         do{errno= en; perror(msg) ; exit(EXIT_FAILURE);} while(0)

#define MAX 20
/* Structure of a node */         
struct NODE {
	char *data;
	struct NODE *next;
};
typedef struct NODE node;

/* Function prototypes */
node* storell(FILE **fptr, node **head);
void display(node **head);
int count_occurence(node **head, char *str);
void deletenode(node **head, char *str);
node* duplicatelist(node **head);
node* deletelist(node **head);
