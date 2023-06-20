//Write a program in C to display the n terms of odd natural number and their sum
#include <stdio.h>
int main() {
    int n,i,sum=0;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
        {
            if (i%2!=0)
                {
                    printf("%d ", i);
                    sum+=i;
                }
        }
    printf("\nSum: %d ", sum);
    return 0;
}