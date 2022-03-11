/****************************************************************************
 * *
 * *FILE NAME:     function.c
 * *
 * *DESCRIPTION:   includes all the functions of queue 
 *
 * DATE             NAME            REFERENCE               REASION
 * 09-03-2022       Shankar Karn    Function Defintion     Queue Array Assignment
 * 
 * Copyrights @2022  Capgemini All rights reserved
 ***************************************************************************/


/***************************************************************************
 *                       Header Files                                      *
 ***************************************************************************/
#include "header.h"


/**************************************************************************
 *        FUNCTION NAME:          init_queue
 *        DESCRIPTION:            Initialize queue to empty
 *        RETURNS:                None
 **************************************************************************/
void init_queue(queue_t *q)
{
   q->front = END;
   q->rear = END;
}

/**************************************************************************
 *        FUNCTION NAME:          check_empty
 *        DESCRIPTION:            Check queue if empty
 *        RETURNS:                SUCCESS or FAILURE
 **************************************************************************/
int check_empty(queue_t *q)
{
   if (END == q->front)
   {
      return SUCCESS;
   }
   else
   { 
      return FAILURE;
   }
}

/**************************************************************************
 *        FUNCTION NAME:          check_full
 *        DESCRIPTION:            Check queue if full
 *        RETURNS:                SUCCESS or FAILURE
 **************************************************************************/
int check_full(queue_t *q)
{
   if (q->front == ((q->rear +1) % MAX_QUEUE_SIZE))
   {
      return SUCCESS;
   }
   else
   { 
      return FAILURE;
   }
}

/**************************************************************************
 * *       FUNCTION NAME:          enqueue
 * *       DESCRIPTION:            inserts an element into the queue
 * *       RETURNS:                SUCCESS or FAILURE
 **************************************************************************/
int enqueue(queue_t *q, int elem)
{
   if (check_full(q))
   {
      return FAILURE; /* Failure */
   }

    /* Increment rear. Then store the element */

   if (check_empty(q))
   {
      q->front = 0;
      q->rear = 0;
   }
   else
   { 
      q->rear =  (q->rear + 1) %MAX_QUEUE_SIZE;
   }
   q->arr[q->rear] = elem;
 
   return SUCCESS;

}

/**************************************************************************
 *        FUNCTION NAME:   dequeue
 *        DESCRIPTION:     removes an element from the queue
 *        ARGUMENTS:       array holding the queue address
 *                         pointer to the returned element
 *        RETURNS:         result item incase of success or else failure
 *************************************************************************/
int dequeue(queue_t *q, int *p_elem)
{
   if (check_empty(q))
   {
      return FAILURE; /* Failure */
   }
   *p_elem = q->arr[q->front];
   if (q->front == q->rear)
   {
      q->front = END;
      q->rear = END;

   }
   else
   {
      q->front = (q->front + 1)%MAX_QUEUE_SIZE;
   }
   return SUCCESS; /* Success */
}

/*****************************************************************************
 *        FUNCTION NAME:  display
 *        DESCRIPTION:    displays the contents of queue
 *        ARGUMENTS:      array holding the queue 
 *******************************************************************/
void display(queue_t *q)
{
   int index, save_index;

   printf("q->front = %d\n", q->front);
   printf("q->rear = %d\n", q->rear);

   if (check_empty(q))
   {
      printf("Queue is empty\n");
      return;
   } 

    /* If Queue is not empty, we print from index + 1 till rear */
   index = q->front;
   save_index = q->front;
   do
   {
      printf("q->arr[%d]=%d\n", index, q->arr[index]);
      if (q->front == q->rear)
      {
         return;
      }
      index = (index + 1)%MAX_QUEUE_SIZE;
   } while (index != q->rear);
   
   if (index != save_index)
   {
      printf("q->arr[%d]=%d\n", index, q->arr[index]);
   }
   printf("\n");
}
