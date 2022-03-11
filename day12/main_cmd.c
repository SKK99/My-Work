/*************************************************************************
*
*  FILE NAME    : main_cmd.c
*
*  DESCRIPTION  : Demonstrates how to use command line arguments
*
*  DATE      NAME   
*
*  1-Mar-22  Shankar Karn
*
**************************************************************************/
/*************************************************************************
*                       Header Files
**************************************************************************/
#include "cmd_line.h"

/**************************************************************************
*                       LOCAL MACROS
**************************************************************************/
#define ARG_MIN 3

/****************************************************************************
*
*       Function Name   : main
*       Description     : Accepts a number and strings as command line
*			  arguments.
*       Returns         : Success or Failure
*
****************************************************************************/
int main(
	 int argc, /* Number of command line arguments */
	 char *argv[] /* Command line arguments */
        ) {

	char temp1[MAX];
	char temp2[MAX];
	char *server=NULL;
	char **ptrservers = NULL;
	char *token = NULL;
	/* Check for correct number of command line arguments */ 
 	if(argc < ARG_MIN) {
   		printf("Invalid number of arguments\n");
		printf("Only %d arguments found. Please enter atleast 3 arguments\n",argc);
   		exit(EXIT_FAILURE);
 	}
	/* Check for correct server name and port number */
	int i = INITIALIZE;
	int j = INITIALIZE;
	bool flag = true;
	for(i=1; i<argc; i++) {
		strcpy(temp1, argv[i]);
		token = strtok(temp1, ":");
		strcpy(temp2, token);
		while(temp2[j]) {
			if(isalpha(temp2[j]) == 0) {
				printf("\nserver name is not alphabetic for argv[%d]\n", i);
				flag = false;
				break;
			}
			j++;
		}
		token = strtok(NULL, ":");
		strcpy(temp2, token);
		j = INITIALIZE;
		while(temp2[j]) {
			if(isdigit(temp2[j]) == 0) {
				printf("\nport number is not numeric for argv[%d]\n",i);
				flag = false;
				break;
			}
			j++;
		}
	}
	if(flag == false)
		exit(EXIT_FAILURE);
	ptrservers = (char**) calloc(argc-1, sizeof(char*));
	/* Display server names and port number */
	for(i=1; i<argc; i++) {
		printf("Port number and server name for %dth argument is\n",i);
 		server = extractServerPort(argv[i]);
		printf("Server name function is %s\n",server);
		ptrservers[i-1] = (char*) calloc(MAX, sizeof(char));
		strcpy(ptrservers[i-1], server);
	}
	/* Display concatenated server names */
	server = concatenateServer(ptrservers,argc-1);
	printf("Concatenated server name is %s\n",server);
	/* Free allocated memory */
	freeMemory(ptrservers,argc-1,server);
	free(token);
	return 0; 
}
