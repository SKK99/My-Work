#include <stdio.h>
#include "ptr2.h"
// This is the main function from where all other functions will be called
int main(int argc, char *argv[]) {
	printf("Welcome\n");
	printf("1. Enter the first number to print array elements (sma)\n");
	printf("2. Enter the size of pattern (sma)\n");
	printf("3. Enter the first number to printf array elements (dma)\n");
	printf("4. Enter the size of pattern (dma)\n");
	printf("5. Swap two values\n");
	printf("Enter the choice\n");
	int choice;
	scanf("%d",&choice);
	int a,n,n1,n2;
	switch(choice) {
		case 1: 
			scanf("%d",&a);
			printArray(a);
			break;
		case 2:
			scanf("%d",&n);
			printPattern(n);
			break;
		case 3:
			scanf("%d",&a);
			printDynamicArray(a);
			break;
		case 4:
			scanf("%d",&n);
			printDynamicPattern(n);
			break;
		case 5:
			scanf("%d %d",&n1,&n2);
			printf("Value before swapping is %d and %d\n",n1,n2);
			swap(&n1,&n2);
			printf("Value after swapping is %d and %d\n",n1,n2);
			break;

		default:
			printf("\nYou have entered wrong choice. Please try again.");
	}
	return 0;
}
