//Program to remove all characters in a string
#include <stdio.h>

int main() {
    char str[100], ch;
    int i, j;

    printf("Enter a string: ");
    gets(str);

    printf("Enter the character to remove: ");
    scanf("%c", &ch);

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf("String after removing '%c': %s\n", ch, str);

    return 0;
}
