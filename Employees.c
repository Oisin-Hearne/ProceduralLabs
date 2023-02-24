#include<stdio.h>;
#include<string.h>;

//Lab 2 - Structs
typedef struct {
	char employeeFirstName[30];
	char employeeSecondName[30];
	int employeeNum;
	int hoursPerWeek;
	float hourlyRate;
}employeeT;

void display(employeeT e);


void main() {
	employeeT currentEmployee;
	int employees;
	FILE* fp;

	fp = fopen("Employees.txt", "a+");
	printf(" = EMPLOYEES = \n");

	if (fp != NULL)
	{
		printf(" * Previous file found! Displaying employees...\n\n");

		while (feof(fp) == 0) { //Assign currentEmployees values to the values read from Employees.txt
			fscanf(fp, "%s %s %d %d %f",
				currentEmployee.employeeFirstName, currentEmployee.employeeSecondName, &currentEmployee.employeeNum, &currentEmployee.hoursPerWeek, &currentEmployee.hourlyRate);

			display(currentEmployee);
		}
	}
	else
	{
		printf(" * No file found!\n");
		exit(0);
	}
	
	printf("\n * How many employees would you like to enter?\n");
	scanf(" %d", &employees);

	for (int i = 0; i < employees; i++) //Save the current employee being entered by the user into the Employees.txt
	{
		printf(" * Enter the first name of employee %d: ", i+1);
		scanf(" %s", currentEmployee.employeeFirstName);

		printf(" * Enter the second name of employee %d: ", i + 1);
		scanf(" %s", currentEmployee.employeeSecondName);

		printf(" * Enter the number, hours and hourly rate of employee %d: ", i+1);
		scanf("%d %d %f", &currentEmployee.employeeNum, &currentEmployee.hoursPerWeek, &currentEmployee.hourlyRate);

		fprintf(fp, "\n%s %s %d %d %f", 
			currentEmployee.employeeFirstName, currentEmployee.employeeSecondName, currentEmployee.employeeNum, currentEmployee.hoursPerWeek, currentEmployee.hourlyRate);

		printf(" * Employee saved!\n");
	}

	printf(" * Employees.txt succesfully saved.\n");
	fclose(fp);
}

void display(employeeT e) { //Display the employee struct in a formatted way.
	printf(" - EMPLOYEE %d -\n * Name: %s %s\n * Hours: %d\n * Rate: %.2f\n\n",
		e.employeeNum, e.employeeFirstName, e.employeeSecondName, e.hoursPerWeek, e.hourlyRate);
}