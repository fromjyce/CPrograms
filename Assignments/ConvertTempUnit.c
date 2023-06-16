/*Temperature of a city in Fahrenheit degrees is input through the 
keyboard. Write a program to convert this temperature into 
Centigrade degrees.*/

#include <stdio.h>
int main() {
    int temp;
    printf("Enter the temperature [ in fahrenheit ]: ");
    scanf("%d", &temp);
    printf("Temperature in Centigrade: %d", ((temp-32)*5)/9);
    return 0;
}