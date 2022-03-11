/**************************************************************************
*
*      FILE NAME:     bst_main.c
*
*      DESCRIPTION:   contains the main function for various operations on
                      binary search tree
*      DATE             NAME            REFERENCE               REASION
*      09-03-2022      Shankar Karn     Driver Function         BST Implementation
*      Copyrights 2022 Capgemini All rights reserved
*    
***************************************************************************/

#include "bst.h"
/**********************************************************
                   MAIN FUNCTION 
**********************************************************/
int main()
{
        bst_node *root = NULL;
        int choice;
        int item;
        do
        {
                printf("\n\n1: Insert an element in the tree ");
                printf("\n2: Display inorder traversal ");
                printf("\n3: Delete a node from tree ");
                printf("\n4: Display preorder traversal ");
                printf("\n5: Display postorder traversal ");
                printf("\n6: exit\n");
                printf("\n\nPlease Enter your choice ");
                scanf("\n%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("\nEnter a node to be inserted ");
                                scanf("%d",&item);
                                insert(&root,item);
                                break;
                                
                        case 2: 
                                inorder(root);
                                break;
                        case 3:
                                printf("\nEnter a node to be deleted ");
                                scanf("%d",&item);
                                delete(&root,item);
                                break;
                                
                        case 4:
                                preorder(root);
                                break;
                                
                        case 5:
                                postorder(root);
                                break;
                        case 6:
                                printf("Thank You \n");
                                break;
                        default:
                                printf("Please enter the right choice\n");
                }
        }while(choice!=6);
        free_bst(root);
        return 0;
}

