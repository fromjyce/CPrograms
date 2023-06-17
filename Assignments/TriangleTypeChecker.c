//Write a C program to check whether the triangle is equilateral, isosceles or scalene triangle.
#include <stdio.H>
int main()
{
    int a, b, c;
    printf("Enter the lengths of the sides of the triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
        printf("The triangle is equilateral.");
    else if (a == b || b == c || a == c)
        printf("The triangle is isosceles.");
    else
        printf("The triangle is scalene.");
    return 0;
}