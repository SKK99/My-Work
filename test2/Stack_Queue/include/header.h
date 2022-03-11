/*******************************************************************************
*
*     FILENAME      :    header.h
*
*     DESCRIPTION   :    This file defines the macros and the structure of the
*                       node used for the queue.
*
*     Revision History    :
*     DATE          NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     09-03-2022    Shankar Karn           Header file          Stack with linked list
*     Copyright @ 2022 Capgemini  All Rights Reserved
*
*******************************************************************************/

/********************** Header File Inclusions ********************************/
#include <stdio.h>
#include <stdlib.h>

/********************** Macro definitions *************************************/
# define SUCCESS 1
# define FAILURE 0

/********************** Structure Definition for Stack**********************************/
typedef struct s_node
{
    int data;
    struct s_node *next;
}node;

/********************** Function Declaration for Stack**********************************/
int push(node **, int);
int pop(node **);
int peep(node **);
int isempty(node *);
void display(node **);

/********************** Structure Definition For Queue **********************************/
typedef struct node_q
{
    int data;
    struct node_q *next;
}nodeq;

/********************** Function Declaration for Queue **********************************/
void enqueue(nodeq **,nodeq **,int);
int dequeue(nodeq **,nodeq **);
int isempty_q(nodeq *);
void display_q(nodeq **);
int free_queue(nodeq** , nodeq**);

