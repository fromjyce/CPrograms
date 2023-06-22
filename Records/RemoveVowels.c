//Remove all vowels from a given string using an array
#include <stdio.h>

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void removeVowels(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    removeVowels(str);

    printf("String without vowels: %s\n", str);

    return 0;
}
