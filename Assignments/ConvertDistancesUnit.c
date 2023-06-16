/*The distance between two cities (in km.) is input through the
keyboard. Write a program to convert and print this distance in 
metres, feet, inches and centimetres*/
#include <stdio.h>
int main() {
    int dist;
    printf("Enter the distance [ in km ]: ");
    scanf("%d", &dist);
    printf("\nDistance in Meter: %d \nDistance in Feet: %d \nDistance in Inches: %d \nDistance in Centimetres: %d", dist*1000, dist*3281, dist*39370, dist*100000);
    return 0;
}