//Write a C program to input any character and check whether it is alphabet, digit or special character
#include <stdio.h>
#include <ctype.h>
int main() {
    char ch;
    printf("Enter any character: ");
    scanf("%c", &ch);
    if (isalpha(ch))
        printf("It is alphabet");
    else if (isdigit(ch))
        printf("It is digit");
    else
        printf("It is special character");
    return 0;
}