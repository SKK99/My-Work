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
 **  8 Mar 2022     Shankar Karn            Test  	Creation of the header.h
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
         
struct filedetail {
	char *fname;
	int wordcount;
	int charcount;
};
typedef struct filedetail file;
/* Function prototypes */
file* readWrite(char *name);
void* process(void *);
