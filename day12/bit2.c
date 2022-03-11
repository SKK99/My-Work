#include <stdio.h>
typedef struct {
	unsigned int age : 7;
	char name[100];
}person;
int main(int argc, char *argv[]) {
	person p;
	unsigned int temp;
	printf("Enter the name\n");
	fgets(p.name, 100, stdin);
	printf("Enter the age\n");
	scanf("%u",&temp);
	p.age = temp;
	printf("\nName is %s and age is %d\n",p.name, p.age);
	return 0;
}
