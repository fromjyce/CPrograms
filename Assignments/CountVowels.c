//write a program to count vowels occurrent in C
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    int count = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        i++;
    }
    
    printf("Occurrences of vowels in the string: %d\n", count);
    
    return 0;
}
