/*************************************************************************
*
*  FILE NAME    : cmc_line.h
*
*  DESCRIPTION  : Contains header files and function prototypes for command
*		  line arguments program
*
*  DATE      NAME
*
*  1-Mar-22  Shankar Karn
*
*
**************************************************************************/

/* Avoiding multiple inclusions of header file */
#ifndef CMD_LINE_HEADER_H
  #define CMD_LINE_HEADER_H
/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
/*******************************************************************************
*                       MACROS
*******************************************************************************/
#define FAILURE 0
#define SUCCESS 1
#define INITIALIZE 0
#define cmd_ret int
#define MAX 32

/*******************************************************************************
*                       FUCNTION PROTOTYPES
*******************************************************************************/
extern char* extractServerPort(char *);
extern char* concatenateServer(char **, int);
extern int freeMemory(char **,int, char*);
#endif

