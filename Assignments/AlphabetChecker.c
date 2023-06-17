//Check for alphabet
#include <stdio.h>
#include <ctype.h>
int main() {
    char a;
    printf("Enter a character: ");
    scanf("%c",&a);
    if(isalpha(a))
        {
            printf("%c is an alphabet character",a);
        }
    else
        {
            printf("%c is not an alphabet character",a);
        }    
    return 0;
}