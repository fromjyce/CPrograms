//Write a program in C to display the multiplication table of a given integer
#include <stdio.h>
int main() {
    int n,i,j;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Enter the bottom limit: ");
    scanf("%d",&j);
    for (i=0; i<j; i++)
        {
            printf("\n%d * %d = %d", n,i+1, n*(i+1));
        }
    return 0;
}