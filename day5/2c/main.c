/* @file main.c
 * @brief A console driver from where all the functions will be called
 * @author Shankar Karn
 * @date 22-02-2022
 */

#include "str.h"

int main(int argc, char** argv) {
	printf("\n**********Normal Variable***********\n");
	getDetails();
	printDetails();

	printf("\n\n*********In Structure********\n\n");
	getDetailsStruct();
	printDetailsStruct();
}
