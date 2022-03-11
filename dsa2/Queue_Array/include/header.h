/****************************************************************************
 * 
 * FILE NAME:     header.h
 * 
 * DESCRIPTION:   all declarations of the queue function 
 *
 * DATE             NAME            REFERENCE       REASION
 * 09-03-2022       Shankar Karn    Header file     Queue Array Assignment
 * 
 * Copyrights @2022  Capgemini All rights reserved
 *
 ***************************************************************************/

/***************************************************************************
 *			Header Files					   *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/***************************************************************************
 *			MACRO DECLARATIONS  				   *
 ***************************************************************************/

#define SUCCESS 1
#define FAILURE 0
#define END -1

#define MAX_QUEUE_SIZE 10

/* Data Type for Queue ADT */

typedef struct queue
{
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
}queue_t;



/***************************************************************************
 *			Function declarations  				   *
 ***************************************************************************/
void init_queue(queue_t *q);
int check_empty(queue_t *q);
int check_full(queue_t *q);
int enqueue(queue_t *q, int elem);
int dequeue(queue_t *q, int *p_elem);
void display(queue_t *q);
