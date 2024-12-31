#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    char designation[50];
    float basic_salary;
    float hra;
    float da;
};

int main() {
    int n;
    printf("Enter no. of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);  

        scanf("%s %s %f %f %f", employees[i].name, employees[i].designation, &employees[i].basic_salary, &employees[i].hra, &employees[i].da);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        float hra_amount = employees[i].basic_salary * (employees[i].hra / 100);
        float da_amount = employees[i].basic_salary * (employees[i].da / 100);
        float gross_salary = employees[i].basic_salary + hra_amount + da_amount;

        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA : %.2f\n", employees[i].hra); 
        printf("DA : %.2f\n", employees[i].da);
        printf("Gross Salary: %.2f\n\n", gross_salary);
    }
}