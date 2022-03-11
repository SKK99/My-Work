/************************************************************************
*    FILENAME     : main.c
*    DESCRIPTION  : Use of Hashing
*    DATE	        NAME                REFERENCE           REASON
*    --------------------------------------------------
    11-03-2022      Shankar Karn        Main function       Hash Assignment
    Copyright @2022 Capgemini All copyrights reserved
***************************************************************************/
#include "header.h"

/***************************************************************************
 *    FUNCTION NAME : main
 *    DESCRIPTION   : create hash table and  free the hash table
 *    RETURNS       : SUCCESS/FAILURE
 ***************************************************************************/
int main(int argc, char *argv[])
{
    HT_node *hash_table[HASH_TABLE_SIZE] = {NULL}; /*hash table*/
    HT_node *temp = NULL;
    int ret_val;
    /*words from user are read into the hash table */
    char *str = NULL;
    str = (char *)malloc(MAX * sizeof(char));
    int choice;
    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("0. Enter 0 to exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        getc(stdin);
        switch (choice)
        {
        case 1:
            printf("Enter the word\n");
            fgets(str, MAX, stdin);
            str[strlen(str) - 1] = 0;
            insert(hash_table, str);
            break;
        case 2:
            printf("Enter the word to delete\n");
            fgets(str, MAX, stdin);
            str[strlen(str) - 1] = 0;
            temp = delete(hash_table, str);
            if(temp != NULL)
                printf("\nItem deleted successfully\n");
	    else
		    printf("\nItem not present\n");
            break;
        case 3:
            printf("Enter the word to search\n");
            fgets(str, MAX, stdin);
            str[strlen(str) - 1] = 0;
            temp = search(hash_table, str);
	    if(temp != NULL)
		    printf("\nItem found %s\n",temp->data);
	    else
		    printf("\nItem not found\n");
            break;
        case 4:
            printf("Displaying the hash table\n");
            display(hash_table);
            break;
        case 0:
            printf("Thank You !\n");
            break;
        default:
            printf("\nPlease enter the right choice\n");
            break;
        }
    }while(choice !=0);
    /* Free all the allocated memories */
    free(temp);
    free(str);
    ret_val = free_hash(hash_table);
    if(ret_val == SUCCESS)
        printf("Memory freed successfully\n");
    else    
        printf("Memory not freed\n");
    return SUCCESS;
}
