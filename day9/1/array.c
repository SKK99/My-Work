/*@file array.c
 * @brief Function definitions for Array Manipulation
 * @author Shankar Karn
 * @date 25-02-2022
 *
 */
#include <stdio.h>
#include "array.h"
#define ZERO 0

/*Function to display array elements*/
void display(int arr[], int n) {
	int i = ZERO;
	for( ; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/*Function to take user input in an array*/
int input(int arr[], int n, int size) {
	int i = ZERO;
	printf("Enter the size of array\n");
	scanf("%d", &n);
	if(n>size) {
		printf("Array Capacity Exceeded\n");
		return ZERO;
	}
	printf("Enter the array elements\n");
	for( ; i<n; i++)
		scanf("%d",&arr[i]);
	return n;
}
/*Function to calculate sum of Max and Min element in the array*/
int sumMaxMin(int arr[], int n) {
	int max = arr[0];
	int min = arr[0];
	int i = ZERO;
	for(i=1; i<n; i++) {
		if(max < arr[i])
			max = arr[i];
		if(min > arr[i])
			min = arr[i];
	}
	return max+min;
}
/*Function to count No of occurence of an element in the array */
int countOccurence(int arr[], int n, int item) {
	int count = ZERO;
	int i = ZERO;
	for( ; i<n; i++) {
		if(arr[i] == item)
			count++;
	}
	return count;
}
/*Function to reverse the array*/
void reverse(int arr[], int n) {
	int i = ZERO;
	for( ; i<n/2; i++) {
		swap(&arr[i],&arr[n-i-1]);
	}
}
/*Function to swap two elements*/
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
