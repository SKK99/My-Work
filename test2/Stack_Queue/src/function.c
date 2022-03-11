/*******************************************************************************
*
*     FILENAME       :    functions.c
*
*     DESCRIPTION    :    This file defines the various functions on stack.
*
*     Revision History    :
*     DATE              NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     09-03-2022    Shankar Karn        Function definitions    Stack with Linked List
*
*       Copyright @ 2022 Capgemini  All Rights Reserved
*******************************************************************************/

#include "header.h"

/*****************************************************************************
*     FUNCTION NAME   :   isempty
*
*     DESCRIPTION   :   This function checks whether the stack is empty or not
*
*     RETURNS         : SUCCESS, if stack is empty
*                       FAILURE, if stack is not empty
*****************************************************************************/
int isempty(node *top) /* Parameter for the front end of the stack */
{
    if (NULL == top)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/**************************************************************************
*     FUNCTION NAME : push
*
*     DESCRIPTION   :This function pushes a new node at the top of the stack
*
*     RETURNS       :SUCCESS/FAILUE
*
*****************************************************************************/
int push(node **top, int value) 
{
    node *newnode;      /*Node pointer for the new node to be inserted */

    /* Allocate memory to the new node */
    newnode = (node*) malloc (sizeof(node));

    /* Check if memory is allocated or not */
    if (NULL ==newnode)
    {
        printf("Memory not available");
        return FAILURE;
    }

    /* Insert the new node in the stack */
    newnode->data = value;
    newnode->next = NULL;

       /* Check whether stack is empty or not */
    if (isempty(*top))
    {
       newnode->next = NULL;
    }
    else
    {
        /* Node's exist in the stack so insert at the top end */
        (newnode)->next = *top;
    }
    *top = newnode;
    return SUCCESS;

}

/***************************************************************************
*  FUNCTION NAME : pop
*
*  DESCRIPTION   :  This function deletes a node from the top of the stack
*
*  RETURNS      : SUCCESS, if element is deleted
*	          FAILURE, if stack is empty
*
*****************************************************************************/
int pop(node **top)
{
    node *temp_node; /* Temporary node pointer */
    int value;      /* Variable to represent the data which is deleted */
    
    /* Check if the stack is empty or not */     
    if (isempty(*top))
    {
        printf("\nStack Underflow");
        return FAILURE;
    }
 
    temp_node = *top;
    *top = (*top)->next;

    value = temp_node->data;
    free (temp_node);
    return value;
}

/***************************************************************************
*  FUNCTION NAME : peep
*
*  DESCRIPTION   : This function reads a node from the top of the stack
*
*  RETURNS      : SUCCESS, if element is read
*	          FAILURE, if stack is empty
*****************************************************************************/
int peep(node **top)
{
    node *temp_node;    /* Temporary node pointer */
    int value;          /* Variable to represent the data which is deleted */
    
    /* Check if the stack is empty or not */     
    if (isempty(*top))
    {
        printf("\nStack Underflow");
        return FAILURE;
    }
 
    temp_node = *top;

    value = temp_node->data;
    printf("\nElement at top is %d",value);
    return SUCCESS;
}

/******************************************************************************
*
*     FUNCTION NAME   :    display
*
*     DESCRIPTION     :    This function displays the data in the stack
*
*     RETURNS         : void
*
*******************************************************************************/
void display(node **top) /* Parameter for the front end of the stack */
{
    node *current; /* Temporary node pointer to traverse the stack */

    /* Check if the stack is empty or not */
    if (isempty(*top))
    {
        printf("\nThe stack is empty") ;
    }
    else
    {
        printf("\nstack is \n");
  
        /* Traverse the stack and display the elements */
        for( current = *top ; current != NULL ; current = current->next)
        {
            printf("%d -> ",current->data);
        }
        printf("NULL\n");
    }
}


/******************************************************************************
*
*     FUNCTION NAME   :   isempty_q
*
*     DESCRIPTION     :   This function checks whether the queue is empty or not
*
*     RETURNS         : SUCCESS, if queue is empty
*                       FAILURE, if queue is not empty
*
*******************************************************************************/
int isempty_q(nodeq *front) /* Parameter for the front end of the Queue */
{
    if (NULL == front)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/******************************************************************************
*
*     FUNCTION NAME   : enqueue
*
*     DESCRIPTION     :This function inserts a new nodeq at the rear end of the  *		       queue
*
*     RETURNS         : void
*
*******************************************************************************/
void enqueue(nodeq **front, nodeq ** rear,int value)
{
    /* nodeq pointer for the new nodeq which needs to be inserted */
    nodeq *newnode;

    /* Allocate memory to the new nodeq */
    newnode = (nodeq*) malloc (sizeof(nodeq));

    /* Check if memory is allocated or not */
    if (NULL ==newnode)
    {
        printf("Memory not available");
        exit(FAILURE);
    }

    /* Insert the new nodeq in the queue */
    newnode->data = value;
    newnode->next = NULL;

       /* Check whether queue is empty or not */
    if (isempty_q(*front))
    {
        /* This is the first nodeq */
       *front = newnode;
       *rear = newnode;
    }
    else
    {
        /* nodeq's exist in the queue so insert at the rear end */
        (*rear)->next = newnode;
        *rear = newnode;
    }

}

/******************************************************************************
*
*     FUNCTION NAME   : dequeue
*
*     DESCRIPTION     :  This function deletes a nodeq from the front end of the *			queue
*
*     RETURNS         : SUCCESS, if element is deleted
*			FAILURE, if queue is empty
*
*******************************************************************************/
int dequeue(nodeq **front, nodeq **rear)
{
    /* Temporary nodeq pointer */
    nodeq *temp_node; 
    /* Variable to represent the data which is deleted */
    int value; 
    
    /* Check if the queue is empty or not */     
    if (isempty_q(*front))
    {
        printf("\nQueue Underflow");
        return FAILURE;
    }

    if (*rear == *front)
    {
        /* Only one nodeq is available in the queue */
        temp_node = *front;
        *front = NULL;
        *rear =NULL;
    }        
    else
    {
        /* Delete the nodeq from the front end of the queue */
        temp_node = *front;
        *front = (*front)->next;
    }

    value = temp_node->data;
    free (temp_node);
    printf("\nElement deleted is %d",value);
    return SUCCESS;
}

/******************************************************************************
*
*     FUNCTION NAME   :    display_q
*
*     DESCRIPTION     :This function displays the data in the queue
*
*     RETURNS         : nothing
*
*******************************************************************************/
void display_q(nodeq **front)
{
    /* Temporary nodeq pointer to traverse the queue */
    nodeq *current; 

    /* Check if the queue is empty or not */
    if (isempty_q(*front))
    {
        printf("\nThe Queue is empty") ;
    }
    else
    {
        printf("\nQueue is \n");
  
        /* Traverse the queue and display_q the elements */
        for( current = *front ; current != NULL ; current = current->next)
        {
            printf("%d -> ",current->data);
        }
        printf("NULL\n");
    }
}

/******************************************************************************
*
*     FUNCTION NAME   :    free_queue
*
*     DESCRIPTION     :    This function frees the memory which is allocated to
*                       the nodes of the queue.
*
*     RETURNS         : SUCCESS if memory is freed,
*                       FAILURE if queue is already empty
*
*******************************************************************************/
int free_queue(nodeq **front, nodeq **rear)
{
    /* Temporary nodeq pointer to traverse the queue */
    nodeq *current; 

    /* Check if the queue is already empty i.e. does not exist */
    if (isempty_q(*front))
    {
        return FAILURE;
    }
    /* Traverse the queue to free each nodeq */
    while (*front != NULL)
    {
        current = (*front)->next;
        free(*front);
        *front = current;
    }
    
    *rear= NULL;
    return SUCCESS;
}

