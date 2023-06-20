//Concatenate Two Strings Lexically
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    if (strcmp(str1, str2) > 0) {
        strcat(str1, str2);
        printf("Concatenated string lexically: %s\n", str1);
    } else {
        strcat(str2, str1);
        printf("Concatenated string lexically: %s\n", str2);
    }

    return 0;
}
