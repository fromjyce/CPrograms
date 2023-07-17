/*Given a year, return the century it is in. 
The first century spans from the year 1 up to and including the year 100, the second - from the year 101 up to and including the year 200, etc.*/
#include <stdio.h>
int ReturnCentury(int year) {
    return (year - 1) / 100 + 1;
}
int main() {
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Century: %d", ReturnCentury(year));
}
