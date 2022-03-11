/************************************************************************
 *       FILENAME     : function.c
 *       DESCRIPTION  : definition of various sorting functions and searching functions
 *         
 *  DATE           		NAME            REFERENCE       		REASON
 * -------------------------------------------------------------
 *  11-03-2022		Shankar Karn       Function declaration		Searching and Sorting
 * Copyrights 2022 Capgemini
 ***********************************************************************/

#include "header.h"

/****************************************************************
 *         Function Prototypes
 ******************************************************************/
static void merge(int *, int, int, int);
static int partition(int *, int, int);
static void heapify(int *, int, int);
static void swap(int *, int *);

/*********************************************************************
 *	FUNCTION NAME	:	quick_sort
 *	DESCRIPTION	:	It is a recursive function that implements QuickSort
 *	RETURN VALUE		:	the function return NULL.
 ***********************************************************************/

void quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now at right place */
		int pi = partition(arr, low, high);

		/* Separately sort elements before partition and after partition */
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

/**************************************************************************
 *	FUNCTION NAME	: Partition
 *	DESCRIPTION	: This function takes last element as pivot, places
					the pivot element at its correct position in sorted
					array, and places all smaller (smaller than pivot)
					to left of pivot and all greater elements to right of pivot
 *	RETURN VALUE : it returns the position of the pivot element
 * **********************************************************************/
static int partition(int *arr, int low, int high)
{
	int pivot = arr[high]; /* pivot element */
	int i = (low - 1);	   /* Index of smaller element and indicates the right position of pivot found so far */
	int j;
	for (j = low; j <= high - 1; j++)
	{
		/* If current element is smaller than the pivot */
		if (arr[j] < pivot)
		{
			i++; /* increment index of smaller element */
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/************************************************************************
 * 	FUNCTION NAME : swap
 * 	DESCRIPTION   : a utility function to swap two elements by pointer technique
 * 	RETURNS	      :  void
 *
 ************************************************************************/
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/************************************************************************
 * 	FUNCTION NAME : mergesort
 * 	DESCRIPTION   : accepts array elements and divides the list till
 * 			the each list contains two elements using recursive
 * 			functions
 * 	RETURNS	      :  void
 *
 ************************************************************************/

void merge_sort(int *arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		/* Sort first and second halves */
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		/* Merge them */
		merge(arr, l, m, r);
	}
}

/**********************************************************************
 * 	FUNCTTION NAME : merge
 * 	DESCRIPTION    : merges the elements of two sorted lists
 * 	RETURNS        : void
 *********************************************************************/

static void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; /*Initial index of first subarray */
	j = 0; /* Initial index of second subarray */
	k = l; /* Initial index of merged subarray */
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/**********************************************************************
 * 	FUNCTTION NAME : heapify
 * 	DESCRIPTION    : To heapify a subtree rooted with node i which is an index in arr[].
 * 					 n is size of heap
 * 	RETURNS        : void
 *********************************************************************/
static void heapify(int *arr, int n, int i)
{
	int largest = i;   /* Initialize largest as root */
	int l = 2 * i + 1; /* left = 2*i + 1 */
	int r = 2 * i + 2; /* right = 2*i + 2 */

	/* If left child is larger than root */
	if (l < n && arr[l] > arr[largest])
		largest = l;

	/* If right child is larger than largest so far */
	if (r < n && arr[r] > arr[largest])
		largest = r;

	/* If largest is not root */
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		/* Recursively heapify the affected sub-tree */
		heapify(arr, n, largest);
	}
}
/**********************************************************************
 * 	FUNCTTION NAME : heap_sort
 * 	DESCRIPTION    : main function to do heap sort
 * 	RETURNS        : void
 *********************************************************************/
void heap_sort(int *arr, int n)
{
	/* Build heap (rearrange array) */
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	/* One by one extract an element from heap */
	for (int i = n - 1; i > 0; i--)
	{
		/* Move current root to end */
		swap(&arr[0], &arr[i]);

		/* call max heapify on the reduced heap */
		heapify(arr, i, 0);
	}
}
/**********************************************************************
 * 	FUNCTTION NAME : printArray
 * 	DESCRIPTION    : A utility function to print array of size n
 * 	RETURNS        : void
 *********************************************************************/
void printArray(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
/**********************************************************************
 * 	FUNCTTION NAME : linear_search
 * 	DESCRIPTION    : A function to search in the array linearly
 * 	RETURNS        : int
 *********************************************************************/
int linear_search(int *arr, int n, int x)
{
	int counter = 0; /* No of comparision */
	int i = INITIALIZE;
	for (; i < n; i++) {
		counter++;
		if (arr[i] == x) {
			printf("No of comarisions made by linear search is %d\n", counter);
			return i;
		}
	}
	printf("No of comarisions made by linear search is %d\n", counter);
	return FAILURE;
}
/**********************************************************************
 * 	FUNCTTION NAME : binary_search
 * 	DESCRIPTION    : A function to search in the array (binary)
 * 	RETURNS        : int
 *********************************************************************/
int binary_search(int *arr, int l, int r, int x)
{
	int counter = 0; 	/* No of comparision */
	while (l <= r)
	{
		counter++;
		int m = l + (r - l) / 2;

		/* Check if x is present at mid */
		if (arr[m] == x) {
			printf("No of comarisions made by binary search is %d\n", counter);
			return m;
		}

		/* If x greater, ignore left half */
		if (arr[m] < x)
			l = m + 1;

		/* If x is smaller, ignore right half */
		else
			r = m - 1;
	}

	/* if we reach here, then element was not present */
	printf("No of comarisions made by binary search is %d\n", counter);
	return FAILURE;
}

/**********************************************************************
 * 	FUNCTTION NAME : isnumber
 * 	DESCRIPTION    : A function to check if a string is a number
 * 	RETURNS        : bool
 *********************************************************************/
bool isnumber(char *number)
{
    int i = 0;

    /* checking for negative numbers */
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        /* if (number[i] > '9' || number[i] < '0') */
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}
