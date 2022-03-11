#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int a=10;
	int *ptr=NULL;
	int *ptr1=NULL;

	ptr = (int *) malloc(1*sizeof(int));
	ptr1 = (int *) malloc(1*sizeof(int));

	*ptr = a;
	ptr1 = ptr;
	printf("Value at ptr1 before free is %d\n",*ptr1);
	free(ptr);
	printf("Value at ptr2 after free is %d\n",*ptr1);
	return 0;
}

