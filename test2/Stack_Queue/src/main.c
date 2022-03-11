/*******************************************************************************
*
*     FILENAME       :    main.c
*
*     DESCRIPTION    :    This file defines the main function.
*       It is used for performing different operations on a queue.
*
*     Revision History    :
*     DATE              NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     09-03-2022        Shankar Karn            Main Function       Stack with linked list
*     Copyright @ 2022 Capgemini  All Rights Reserved
*
*******************************************************************************/

#include "header.h"
/******************************************************************************
*
*     FUNCTION NAME   :    main
*
*     DESCRIPTION     :    This function calls different functions to perform
*                          operations like push, pop, display etc on
*                          a stack.
*
*     RETURNS         : SUCCESS
*
*******************************************************************************/
int main(int argc, char *argv[])
{
    printf("Enter the no of stacks you want to use\n");
    int n;
    scanf("%d", &n);
    if(n==1) {
        printf("Please enter atleast 2 stacks to perform the operation\n");
        return FAILURE;
    }
    node **top = (node **) malloc(n* sizeof(node *));
    int status; /* Variable to check the return status */
    int choice;  /* variable to take the user choice */
    int i = 0;
    for( ; i<n-1; i++) {
        top[i] = NULL;
        printf("Push the elements in stack %d \n", i+1);
        while(1) {
            printf("Enter 0 to exit from the current stack or 1 to continue\n");
            scanf("%d", &choice);
            if(choice == 0)
                break;
            printf("Enter the element to be inserted ");
            int num;
            scanf("%d", &num);
            push(&top[i], num);
        }
    }
    top[n-1] = NULL;
    int temp;
    for(i=0 ; i<n-1; i++) {
        printf("Popping all the elements from stack %d \n", i+1);
        while(isempty(top[i]) != SUCCESS) {
            temp = pop(&top[i]);
            push(&top[n-1], temp);
        }
    }
    printf("\nDisplaying last stack\n");
    display(&top[n-1]);

    nodeq *front = NULL;
    nodeq *rear = NULL;
    printf("Entering the nth stack into the queue\n");
    while(isempty(top[n-1]) != SUCCESS){
        temp = pop(&top[n-1]);
        enqueue(&front, &rear, temp);
    }
    printf("Showing the contents of Queue");
    display_q(&front);

    /* Free the memory allocated to the stack */
    for(i = 0; i<n; i++) {
        free(top[i]);
    }
    free(top);

    /* Free the memory allocated to queue */
    status = free_queue(&front, &rear);
    if(status == FAILURE)
        printf("Memory not freed\n");
    else
        printf("\nMemory freed\n");
    return SUCCESS;
}
