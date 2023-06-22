/*Generate the salary slip of a single employee using structure and functions.
Use separate functions for getting input, computing and displaying output.
Pass the structure by reference. Display the pay slip with proper formatting.
Use pointer notation.*/
#include <stdio.h>

// Structure to store employee details and salary information
struct Employee {
    char name[50];
    int employeeID;
    int hoursWorked;
    double hourlyRate;
    double basicPay;
    double overtimePay;
    double grossPay;
};

// Function to get input for employee details
void getInput(struct Employee *emp) {
    printf("Enter employee name: ");
    scanf("%s", emp->name);

    printf("Enter employee ID: ");
    scanf("%d", &(emp->employeeID));

    printf("Enter hours worked: ");
    scanf("%d", &(emp->hoursWorked));

    printf("Enter hourly rate: ");
    scanf("%lf", &(emp->hourlyRate));
}

// Function to compute salary information
void computeSalary(struct Employee *emp) {
    if (emp->hoursWorked <= 40) {
        emp->basicPay = emp->hoursWorked * emp->hourlyRate;
        emp->overtimePay = 0.0;
    } else {
        emp->basicPay = 40 * emp->hourlyRate;
        emp->overtimePay = (emp->hoursWorked - 40) * emp->hourlyRate * 1.5;
    }

    emp->grossPay = emp->basicPay + emp->overtimePay;
}

// Function to display the salary slip
void displaySalarySlip(struct Employee *emp) {
    printf("\nSalary Slip\n");
    printf("Employee Name: %s\n", emp->name);
    printf("Employee ID: %d\n", emp->employeeID);
    printf("Hours Worked: %d\n", emp->hoursWorked);
    printf("Hourly Rate: %.2lf\n", emp->hourlyRate);
    printf("Basic Pay: %.2lf\n", emp->basicPay);
    printf("Overtime Pay: %.2lf\n", emp->overtimePay);
    printf("Gross Pay: %.2lf\n", emp->grossPay);
}

int main() {
    struct Employee emp;

    // Get input for employee details
    getInput(&emp);

    // Compute salary
    computeSalary(&emp);

    // Display salary slip
    displaySalarySlip(&emp);

    return 0;
}
