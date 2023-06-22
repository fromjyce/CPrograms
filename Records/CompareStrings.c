//Implement strcmpi(str1, str2) function without using the strings library
#include <stdio.h>

int strcmpi(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (tolower(*str1) != tolower(*str2)) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int result = strcmpi(str1, str2);

    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("First string is less than the second string.\n");
    } else {
        printf("First string is greater than the second string.\n");
    }

    return 0;
}
