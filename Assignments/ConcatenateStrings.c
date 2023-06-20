//write a program to Concatenate Two Strings
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';  // Remove the newline character from str1

    strcat(str1, str2);

    printf("Concatenated string: %s\n", str1);

    return 0;
}
