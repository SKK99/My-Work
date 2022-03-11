/*@file main.c
 * @brief console for the driver function
 * Demo for few operations on array
 * @author Shankar Karn
 * @date 25=02-2022
 */
#include <stdio.h>
#include "array.h"
#define ZERO 0
#define SIZE 20

int main(int argc, char *argv[]) {
	int arr[SIZE] = {ZERO};
	int choice = ZERO;
	int sum = ZERO;
	int count = ZERO;
	int item = ZERO;
	int n = ZERO;
	do {
		printf("\n1.Display the array\n");
		printf("2.Enter Array Element\n");
		printf("3.Sum of Max and Min\n");
		printf("4.Count an element in the array\n");
		printf("5.Reverse the array\n");
		printf("6. Enter 0 to exit\n");
		printf("\n\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			display(arr, n);
			break;
		case 2:
			n = input(arr, n, SIZE);
			break;
		case 3:
			sum = sumMaxMin(arr, n);
			printf("Sum of Max and Min elements %d\n",sum);
			break;
		case 4:
			printf("Enter the element\n");
			scanf("%d", &item);
			count = countOccurence(arr, n, item);
			printf("Element %d found at %d places\n",item,count);
			break;
		case 5:
			reverse(arr, n);
			display(arr,n);
			break;
		case 0:
			printf("\nProgram ends !\n");
			break;
		default:
			printf("Invalid Choice\n");
		}	
	}while(choice != 0);
	return 0;
}
