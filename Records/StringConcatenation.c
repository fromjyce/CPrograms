/*[String concatenation] Read two strings str1 and str2 from the user. The size
of each string should be allocated dynamically which is entered by the user.
A new string str3 should concatenate the first half of str1 and second half of
str2. The size of str3 should also be estimated in runtime and allocated
sufficient memory dynamically to hold relevant parts of str1 and str2.
Note: If length is odd, then first half is integer part of division by 2 and
second half is length minus integer part (i.e, if length is 5, then first half is 2
chars, and 3 chars (i.e., 5-2) is the second half).
Example 1
Input:
str1 = abcde
str2 = wxyz
str3 = abyz
Example 2:
Input:
str1 = abcd
str2 = vwxyz
str3 = abxyz*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Calculate the size of the first half of str1 and second half of str2
    int half1 = len1 / 2;
    int half2 = len2 - (len1 - half1);

    // Allocate memory for str3
    int size3 = half1 + half2 + 1; // Add 1 for the null character
    char* str3 = (char*)malloc(size3 * sizeof(char));

    // Copy the first half of str1 to str3
    strncpy(str3, str1, half1);

    // Copy the second half of str2 to str3
    strncpy(str3 + half1, str2 + (len2 - half2), half2);

    // Add null character at the end
    str3[size3 - 1] = '\0';

    return str3;
}

int main() {
    int size1, size2;

    printf("Enter the size of str1: ");
    scanf("%d", &size1);

    printf("Enter the size of str2: ");
    scanf("%d", &size2);

    // Allocate memory for str1 and str2
    char* str1 = (char*)malloc((size1 + 1) * sizeof(char));
    char* str2 = (char*)malloc((size2 + 1) * sizeof(char));

    printf("Enter str1: ");
    scanf("%s", str1);

    printf("Enter str2: ");
    scanf("%s", str2);

    // Concatenate str1 and str2
    char* str3 = concatenateStrings(str1, str2);

    printf("Concatenated string (str3): %s\n", str3);

    // Free the dynamically allocated memory
    free(str1);
    free(str2);
    free(str3);

    return 0;
}
