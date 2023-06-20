//write a program to print a string character by character in C
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
    
    printf("\n");
    return 0;
}
