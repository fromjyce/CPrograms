//Display corresponding ASCII characters for a given string
#include <stdio.h>

void displayAsciiCharacters(char *str) {
    printf("ASCII characters:\n");
    int i = 0;
    while (str[i] != '\0') {
        printf("%c: %d\n", str[i], str[i]);
        i++;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    displayAsciiCharacters(str);

    return 0;
}
