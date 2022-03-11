/*************************************************************************
*
*  FILE NAME    : cmd_line_functions.c
*
*  DESCRIPTION  : Function Definitions for command line argument processing
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*  Copyright 2010, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/*************************************************************************
*                       Header Files
**************************************************************************/
#include "cmd_line.h"

/*************************************************************************
*                       LOCAL MACROS
**************************************************************************/
#define IN
#define OUT

/* Function to extract server and port */
char* extractServerPort(char *str) {
	char *token = NULL;
	char *server = NULL;
	server = (char*) calloc(MAX, sizeof(char));
	token = strtok(str,":");
	strcpy(server, token);
	token = strtok(NULL, ":");
	printf("The port no is %s\n",token);
	return server;
}
/*Function to concatenate server names */
char* concatenateServer(char **ptrserver, int n) {
	int i = INITIALIZE;
	char *str = NULL;
	str = (char*) calloc(MAX, sizeof(char));
	for(i=0; i<n; i++)
		strcat(str, ptrserver[i]);
	return str;
}
/* Function to free all the memory */
int freeMemory(char **ptrserver,int n, char *str) {
	if(str==NULL)
		exit(EXIT_FAILURE);
	free(str);
	int i = INITIALIZE;
	for( ; i<n; i++) {
		if(ptrserver[i] == NULL)
			exit(EXIT_FAILURE);
		free(ptrserver[i]);
	}
	free(ptrserver);
	exit(EXIT_SUCCESS);
}
