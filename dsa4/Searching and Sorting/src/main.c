
/**************************************************************************
 *
 * FILE NAME:     main.c
 *
 * DESCRIPTION:   contains the main function invoking sorting functions
 *
 *  DATE           		NAME            REFERENCE       REASON
 * -------------------------------------------------------------
 *  11-03-2022		Shankar Karn        Main function	Searching and Sorting
 * Copyrights 2022 Capgemini
 *
 ****************************************************************************/

/**************************************************************************
 *                       Header Files                                      *
 ***************************************************************************/
#include "header.h"

/***********************************************************************
 *       FUNCTION NAME :  main
 *       DESCRIPTION   :  invokes various sorting functions
 *************************************************************************/
int main(int argc, char *argv[])
{
	/* Checking for the correct no of arguments */
	if (argc < ARGC)
	{
		printf("Please enter atleast 3 arguments\n");
		return FAILURE;
	}
	/* Checking for size */
	if(isnumber(argv[1]) == false || atoi(argv[1]) < INITIALIZE)
	{
		printf("Size is not correct\n");
		return FAILURE;
	}
	/* Checking for numeric data type */
	int i = INITIALIZE;
	for(i=2; i<argc; i++) 
	{
		if(isnumber(argv[i]) == false) 
		{
			printf("Numeric value not found\n");
			return FAILURE;
		}
	}
	/* Checking for size of the array and entered array */
	if(argc-2 != atoi(argv[1]))
	{
		printf("Size is not correct\n");
		return FAILURE;
	}
	
	int n = atoi(argv[1]);  /* Size of the array */
	printf("%d\n", n);
	int *array = NULL;
	array = (int *)calloc(n, sizeof(int));
	if(array == NULL) {
		printf("Memory not available\n");
		return FAILURE;
	}
	int choice;
	int x;

	/* reading the elements into the array from command line argc */
	for (i = 2; i < argc; i++)
	{
		array[i - 2] = atoi(argv[i]);
	}

	/* displaying the array elements before sorting */

	printf("\nElements Before sorting :\n");
	printArray(array, n);
	printf("Enter the element you want to search in unsorted array\n");
	scanf("%d", &x);
	/* Linear Search */
	int index = linear_search(array, n, x);  
	if (index == FAILURE)
		printf("Element not found\n");
	else
		printf("Element found at index %d\n", index);

	printf("\nPlease enter your choice of sorting technique:");
	printf("\n1. Merge Sort");
	printf("\n2. Quick Sort");
	printf("\n3. Heap Sort\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		merge_sort(array, 0, n - 1);
		break;
	case 2:
		quick_sort(array, 0, n - 1);
		break;
	case 3:
		heap_sort(array, n);
		break;
	case 4:
		printf("Please enter the right choice\n");
		break;
	}

	/* displaying the array elements after sorting */

	printf("\n\nelements After sorting :\n");
	printArray(array, n);
	printf("Enter the element you want to search using binary search in sorted array\n");
	scanf("%d", &x);
	/* Binary Search */
	index = binary_search(array, 0, n - 1, x);
	if (index == FAILURE)
		printf("Element not found\n");
	else
		printf("Element found at index %d\n", index);

	/* Free all the memory */
	free(array);
	printf("\n");
	return EXIT_SUCCESS;
}
