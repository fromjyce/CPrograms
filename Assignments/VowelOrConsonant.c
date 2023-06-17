//Check for Vowel or Consonant
#include <stdio.h>
int main() {
    char a;
    int i;
    char b[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    printf("Enter a character: ");
    scanf("%c",&a);
    int isVowel = 0;
    for (i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
    if (a == b[i]) {
        isVowel = 1; // Set the flag to indicate a vowel is found
        break;
        }
    }
    if (isVowel) {
    printf("%c is a vowel", a);
    } 
    else {
    printf("%c is a consonant", a);
    }
    return 0;
}

