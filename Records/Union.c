/*Write a program to create an array of numbers. The numbers may be of any
format (number name, whole number, floating point number, etc.). For this,
create a union named 'Number' with fields char[] number , int num , float fnum ,
double dnum . Each number may be stored and retrieved in any of the above
formats depending on the choice of the user*/
#include <stdio.h>

// Union for storing numbers in different formats
union Number {
    char numberName[50];
    int num;
    float fnum;
    double dnum;
};

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Create an array of unions
    union Number numbers[size];

    // Read the numbers from the user
    printf("Enter the numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%s", numbers[i].numberName);
    }

    // Display the numbers in different formats based on user's choice
    printf("\nDisplay Options:\n");
    printf("1. Number Name\n");
    printf("2. Whole Number\n");
    printf("3. Floating Point Number\n");
    printf("4. Double\n");

    int choice;
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);

    printf("\nResult:\n");
    switch (choice) {
        case 1:
            printf("Number Name:\n");
            for (int i = 0; i < size; i++) {
                printf("%s\n", numbers[i].numberName);
            }
            break;

        case 2:
            printf("Whole Numbers:\n");
            for (int i = 0; i < size; i++) {
                printf("%d\n", numbers[i].num);
            }
            break;

        case 3:
            printf("Floating Point Numbers:\n");
            for (int i = 0; i < size; i++) {
                printf("%.2f\n", numbers[i].fnum);
            }
            break;

        case 4:
            printf("Doubles:\n");
            for (int i = 0; i < size; i++) {
                printf("%.2lf\n", numbers[i].dnum);
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
