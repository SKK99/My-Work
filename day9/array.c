#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"
/*Function to initialise the array*/
void array() {
	printf("Enter the size of the array\n");
	int n;
	scanf("%d",&n);
	float *arr = NULL;
	arr = (float*) malloc(n*sizeof(float));
	printf("\nEnter the array elements\n");
	int i;
	for(i=0; i<n; i++){
		float e;
		scanf("%f",&e);
		*(arr+i) = e;
	}
	printf("1.Search\n2.Insert\n3.Delete\n4.Display\n5.Sort\n");
	printf("Enter your choice\n");
	int choice;
	scanf("%d",&choice);
	int pos;
	float val;
	switch(choice) {
		case 1:
			printf("Enter the key to search\n");
			scanf("%f",&val);
			pos = search(arr,n,val);
			if(pos == -1) {
				printf("Element Not found\n");
				break;
			}
			printf("Element found at index %d\n",pos);
			break;
		case 2:
			printf("Enter the position and element\n");
			scanf("%d %f",&pos,&val);
			insert(arr,n,pos,val);
			display(arr,n);
			break;
		case 3:
			printf("Enter the element to be deleted\n");
			scanf("%f",&val);
			pos = deletee(arr,n,val);
			if(pos<n) 
				printf("Element %f deleted successfully\n",val);
			display(arr,pos);
			printf("Enter the element to be deleted\n");
			break;
		case 4:
			display(arr,n);
			break;
		case 5:
			bubbleSort(arr,n);
			display(arr,n);
			break;
		default:
			printf("Invalid Choice\n");
	}
	free(arr);
}

/* Function to implement search operation */
int search(float a[], int n,float key) {
	int i;
	bool flag=false;	/*flag to check if the key is found*/
	int index=-1;		 /*Index to find the element position*/
	for(i=0; i<n; i++) {
		if(a[i] == key){
			flag = true;
			index = i;
			break;
		}
	}
	if(flag==true) {
		return index;
	}
	else {
		return -1;
	}
}
/* Function to implement insert operation at a given pos */
void insert(float a[], int n, int pos, float val) {
	n++;			// increase the size by 1
	int i;
	/* shift elements forward */
	for(i=n-1; i>=pos; i--) {
		a[i] = a[i-1];
	}

	a[pos-1] = val;		/* insert x at pos */
}	
/*Function to implement delete operation */
int deletee(float a[], int n, float val) {
	/*Find Position of element to be deleted */
	int pos = search(a,n,val);
	if(pos == -1) {
		printf("Element Not Found\n");
		return n;
	}
	/*Deleting Element*/
	int i;
	for(i=pos; i<n-1; i++)
		a[i] = a[i+1];
	n--;
	return n-1;

}
/*Function to display array elements*/
void display(float a[], int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("a[%d] = %.2f\n",i,*(a+i));
	}
}
/*Swap two elements*/
void swap(float *a, float *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*A function to implement bubble sort*/
void bubbleSort(float a[], int n) {
	int i,j;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-i-1; j++) {
			if(a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

void string() {
	char *str1 = NULL;
	char *str2 = NULL;
	printf("\nEnter the size of string1 ");
	int n1,n2;
	scanf("%d",&n1);
	str1 = (char*) malloc(n1*sizeof(char));
	printf("\nEnter string1 ");
	getc(stdin);
	scanf("%[^\n]s",str1);
	printf("\nEnter the size of string2 ");
	scanf("%d",&n2);
	str2 = (char*) malloc(n2*sizeof(char));
	printf("\nEnter string2 ");
	getc(stdin);
	scanf("%[^\n]s",str2);
	printf("\nLength of string 1 is %ld and length of string 2 is %ld ",strlen(str1),strlen(str2));
	strcat(str1, str2);
	printf("\nLength of concatenated string %ld and the content is %s \n",strlen(str1),str1);
	free(str1);
	free(str2);
}

