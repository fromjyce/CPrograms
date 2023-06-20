//write a program to count character occurrent in C
#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    char target = 'o';
    int count = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] == target) {
            count++;
        }
        i++;
    }
    
    printf("Occurrences of '%c' in the string: %d\n", target, count);
    
    return 0;
}
