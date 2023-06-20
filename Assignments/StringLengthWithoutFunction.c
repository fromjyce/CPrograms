//write a program to find string length without function in C
#include <stdio.h>

int main() {
    char inputString[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Calculate the length of the string
    while (inputString[length] != '\0' && inputString[length] != '\n') {
        length++;
    }

    printf("Length of the string: %d\n", length);

    return 0;
}
