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
        bst_node *temp;
        int choice;
        int retval;
        int k1, k2;
        int item;
        do
        {
                printf("\n\n1: Insert an element in the tree ");
                printf("\n2: Delete a node from tree ");
                printf("\n3: Display inorder traversal ");
                printf("\n4: Display preorder traversal ");
                printf("\n5: Display postorder traversal ");
                printf("\n6. Display the height of the tree ");
                printf("\n7. Display the max element of the tree ");
                printf("\n8. Display the min element of the tree ");
                printf("\n9. Display the values in range ");
                printf("\n10. Search a node in tree ");
                printf("\n0: Enter 0 to exit\n");
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
                                printf("\nEnter a node to be deleted ");
                                scanf("%d",&item);
                                delete(&root,item);
                                break;
                                
                        case 3: 
                                inorder(root);
                                break;
                                
                        case 4:
                                preorder(root);
                                break;
                                
                        case 5:
                                postorder(root);
                                break;
                        case 6:
                                retval = height(root);
                                if(retval != -1)
                                        printf("Height is %d \n",retval);
                                else    
                                        printf("Tree is empty\n");
                                break;
                        case 7:
                                retval = findMax(root);
                                if(retval != -1)
                                        printf("Max element is %d \n",retval);
                                else    
                                        printf("Tree is empty\n");
                                break;
                        case 8:
                                retval = findMin(root);
                                if(retval != -1)
                                        printf("Min element is %d \n",retval);
                                else    
                                        printf("Tree is empty\n");
                                break;
                        case 9:
                                printf("Enter k1 and k2\n");
                                scanf("%d %d", &k1, &k2);
                                if(k1 > k2)
                                        printInRange(root, k2, k1);
                                else
                                        printInRange(root, k1, k2);
                                break;
                        case 10:
                                printf("Enter the key to search ");
                                scanf("%d", &k1);
                                temp = search(root, k1);
                                if(temp==NULL)
                                        printf("Not found\n");
                                else    
                                        printf("Node found %d\n",temp->data);
                                break;
                        case 0:
                                printf("Thank You \n");
                                break;
                        default:
                                printf("Please enter the right choice\n");
                }
        }while(choice!=0);
        free_bst(root);
        return 0;
}

