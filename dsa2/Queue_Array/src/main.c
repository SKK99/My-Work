/**************************************************************************
 * 
 * FILE NAME:     main.c
 * 
 * DESCRIPTION:   contains the main function for various operations on 
 *                queue 
 *  DATE           NAME            REFERENCE       REASION
 *  09-03-2022    Shankar Karn      Main function  Queue Array Assignment  
 *                                            
 * Copyrights @2022 Capgemini All rights reserved
 *                                                                 
 ****************************************************************************/

/**************************************************************************
 *                       Header Files                                      *
 ***************************************************************************/
#include"header.h"

/**************************************************************************
 * *
 * *       FUNCTION NAME:          main
 * *       DESCRIPTION:            invokes all the function of  the queue
 * *       RETURNS:                 Success or Failure
 *
 *************************************************************************/
int main(int argc, char *argv[])
{
   queue_t q1;
   int option;
   int status; /* success/failure return */
   int elem;   /* element value */

   /* Initialize the Queue */
   init_queue(&q1);

   /* Main Input loop (or driver loop) */
   while(1)
   {
       printf("Please enter your choice.\n");
       printf("1) Insert an element\n");
       printf("2) Remove an element\n");
       printf("3) Check Empty\n");
       printf("4) Check Full\n");
       printf("5) Display the queue  data\n");
       printf("6) Exit\n");
  
       scanf("%d", &option);

       switch (option)
       {
           case 1: /* Insert an element */
                   printf("Enter the element\n");
                   scanf("%d", &elem);
                   status = enqueue(&q1, elem);
                   if (SUCCESS == status)
                   {
                      printf(" Element inserted Successfully \n");
                   }
                   else
                   {
                      printf(" Queue full, can not insert \n");
                   }
                   break;

           case 2: /* Remove the front element */
                   status = dequeue(&q1, &elem);
                   if (SUCCESS == status)
                   {
                      printf(" Element %d removed Successfully \n", elem);
                   }
                   else
                   {
                      printf(" Queue Empty, can not remove \n");
                   }
                   break;
 
           case 3: /* Check Empty */
                   status = check_empty(&q1);
                   if (SUCCESS == status)
                   {
                      printf(" Queue is Empty \n");
                   }
                   else
                   {
                      printf(" Queue is not Empty \n");
                   }
                   break;

           case 4: /* Check Full */
                   status = check_full(&q1);
                   if (SUCCESS == status)
                   {
                      printf(" Queue is Full \n");
                   }
                   else
                   {
                      printf(" Queue is not Full \n");
                   }
                   break;

           case 5: /* Print the stack */ 
                   display(&q1);
                   break;

           case 6: /* Exit*/ 
                   exit(0);
                   break;

       }
 
   }
   exit(0);
}

