/* @file str.c
 * @brief This file contains all the functions definitions calling in main
 * @author Shankar Karn
 * @date 22-02-2022
 */
#include "str.h"

char name[WORDLENGTH];
char gender;
int age = INITIALIZE;
float salary = INITIALIZE;
/*Function to read details from user*/
void getDetails() {
	printf("Enter Name: ");
	fgets(name, WORDLENGTH, stdin);
	name[strcspn(name, "\n")] = 0;

	printf("Enter Gender: ");
	scanf("%c", &gender);
	getc(stdin);

	printf("Enter Age: ");
	scanf("%d", &age);
	getc(stdin);

	if (age <= 0){
		printf("Invalid age!");
		exit(0);
	}

	printf("Enter Salary: ");
	scanf("%f", &salary);
	getc(stdin);
}
/*Function to display the details*/
void printDetails () {
	printf("\nName: %s\nGender: %c\nAge: %d\nSalary: %0.2f\n", name, gender, age, salary);
}
/*Function to read all the details in structure*/
void getDetailsStruct() {
	printf("Enter Name: ");
	fgets(name, WORDLENGTH, stdin);
	name[strcspn(name, "\n")] = 0;

	printf("Enter Gender: ");
	scanf("%c", &gender);
	getc(stdin);

	printf("Enter Age: ");
	scanf("%d", &age);
	getc(stdin);

	if (age <= 0){
		printf("Invalid age!");
		exit(0);
	}

	printf("Enter Salary: ");
	scanf("%f", &salary);
	getc(stdin);

	strcpy(emp.name, name);
	emp.gender = gender;
	emp.salary = salary;
	emp.age = age;
}
/*Function to display all the details from structure*/
void printDetailsStruct () {
	printf("\nName: %s\nGender: %c\nAge: %d\nSalary: %0.2f\n", emp.name, emp.gender, emp.age, emp.salary);
}
