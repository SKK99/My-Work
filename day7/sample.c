#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("This is the pointer lecture!\n");
	int a=10;
	int *ptr;
	ptr = &a;
	printf("Value of a is %d\n", a);
	printf("Address of a is %p\n", &a);
	printf("Address of a is %p\n", ptr);
	printf("Address of a is %d\n",*ptr);
	return 0;
}
