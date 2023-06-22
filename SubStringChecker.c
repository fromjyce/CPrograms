//Find substring occurrences in a given string
#include <stdio.h>
#include <string.h>

int countSubstring(char *str, char *subStr) {
    int count = 0;
    int subStrLen = strlen(subStr);

    while ((str = strstr(str, subStr)) != NULL) {
        count++;
        str += subStrLen;
    }

    return count;
}

int main() {
    char str[100];
    char subStr[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter the substring to find: ");
    scanf("%s", subStr);

    if (strstr(str, subStr) != NULL) {
        printf("The substring is present in the main string.\n");
        int occurrences = countSubstring(str, subStr);
        printf("Number of occurrences: %d\n", occurrences);
    } else {
        printf("The substring is not present in the main string.\n");
    }

    return 0;
}
