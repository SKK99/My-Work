/* @file main.c
 * @brief console for the main function
 * @author Shankar Karn
 * @date 21-02-2022
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#define MAX_LEN 20
#define ZERO 0
#define A ' '

int main(int argc, char *argv[]) {
    char arr[][MAX_LEN] = {"user1", "user2", "user3", "user4"};
    char *ptr = NULL;
    int choice = ZERO;
    int index = ZERO;
    char ch = A;
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    do {
        printf("\n1.Swap elements\n");
        printf("2.Check vowel\n");
        printf("3.Remove vowel\n");
        printf("4.Concatenate strings\n");
        printf("5.Display\n");
        printf("Press 0 to Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the swapping index\n");
                scanf("%d",&index);
                ptr = swap_elements(arr,index); 
                printf("Element at the given index %d after swapping is %s\n",index,ptr);
                break;
            case 2:
                printf("Enter character to check vowel\n");
                scanf(" %c",&ch);
                printf("Exit status is %d\n",isVowel(ch));
                break;
	    case 3:
                printf("Enter the index\n");
                scanf("%d",&index);
                ptr = remove_vowels(arr,index); 
                printf("Element at the given index %d after removing vowel is %s\n",index,ptr);
		break;
	    case 4:
		printf("Enter string 1\n");
		fgetc(stdin);
		fgets(s1, MAX_LEN, stdin);
		printf("Enter string 2\n");
		fgets(s2, MAX_LEN, stdin);
		ptr = mystrcat(s1,s2);
		printf("\nConcatenated string is s1 %s\n",ptr);
		break;
	    case 5:
		display(arr);
		break;
            default:
		printf("\nProgram Ends!\n");
                break;
        }
    }while(choice != 0);
    return 0;
}
