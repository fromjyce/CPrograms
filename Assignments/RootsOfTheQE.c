//Write a C program to find all roots of a quadratic equation.
#include <stdio.h>
int main() {
    int a, b, c, x1, x2;
    printf("Enter the coefficients of the quadratic equation ax^2 + bx + c = 0\n");
    scanf("%d %d %d", &a, &b, &c);
    int d = sqrt(b * b - 4 * a * c);
    x1 = (-b + d) / (2 * a);
    x2 = (-b - d) / (2 * a);
    if (d==0)
        {
            printf("Roots are real and equal\n");
            printf("%d %d", x1, x2);
        }
    else if (d>0)
        {
            printf("Roots are real and unequal\n");
            printf("%d %d", x1, x2);
        }
    else
        {
            printf("Roots are imaginary\n");
        }
    return 0;
}