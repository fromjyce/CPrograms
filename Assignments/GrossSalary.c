/* Priya basic salary is input through the keyboard. Her dearness 
allowance is 40% of basic salary, and house rent allowance is 
20% of basic salary. Write a program to calculate her gross 
salary*/
#include<stdio.h>
int main()
{
    float basic_salary, dallowance, house_rent, gross_salary;
    printf("Enter Basic Salary: ");
    scanf("%f",&basic_salary);

    dallowance = 0.4 * basic_salary;
    house_rent = 0.2 * basic_salary;

    gross_salary = basic_salary + dallowance + house_rent;

    printf("\n Basic Salary: %.2f",  basic_salary);
    printf("\n Dearness Allowance: %.2f", dallowance);
    printf("\n House Rent: %.2f", house_rent);
    printf("\n\n Gross Salary: %.2f", gross_salary);

    getch();
    return (0);
}
