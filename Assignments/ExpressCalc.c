//Write a program to execute the following expression ++a*b – where a =5 and b =10.
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;

    int result = ++a * b;

    printf("Result: %d\n", result);

    return 0;
}
