#include <stdio.h>
int main(int argc, char *argv[]) {
	int var1 = 100;
	int var2 = 200;

	int *const ptr = &var1; 
	//const int* ptr;
	printf("Value of var1 is %d\n",var1);
	printf("Value of var2 is %d\n",var1);
	
	//ptr = &var1;
	printf("Value of var1 is %d\n",*ptr);
	
	//ptr = &var2;
	//*ptr = 300;
	printf("Value of var1 is %d\n",*ptr);
	return 0;
}
