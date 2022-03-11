#include <stdio.h>
#include <stdbool.h>
struct traffic {
	bool red : 1;
	bool green : 1;
	bool orange : 1;
};

int main(int argc, char *argv[]) {
	struct traffic t;
	t.red = 1;
	t.green = 0;
        t.orange = 0;
	printf("size of struct is %ld\n",sizeof(t));
	if(t.red) 
		printf("Red light is on\n");
	else if(t.green)
		printf("Green light is on\n");
	else
		printf("Orange light is on\n");
}	
	
