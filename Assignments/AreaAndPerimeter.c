/*The length & breadth of a rectangle and radius of a circle are
input through the keyboard. Write a program to calculate the
area & perimeter of the rectangle, and the area & circumference 
of the circle. */
#include <stdio.h>
int main() {
    int len, breadth, radius;
    printf("Enter the length and breadth of a rectangle and radius of a circle: ");
    scanf ("%d %d %d", &len, &breadth, &radius);
    printf("\nArea of the rectangle: %d", len*breadth);
    printf("\nPerimeter of the rectangle: %d", 2*(len*breadth));
    printf("\nCircumference of the Circle: %d", 2*3.14*radius);
    printf("\nArea of the circle: %d", 3.14*radius*radius);
    return 0;
}