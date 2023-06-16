//Print the Natural Numbers upto N and their sum

#include <stdio.h>
int main() {
    int n,i,sum=0;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    printf("The Natural numbers upto %d : \n", n);
    for (i=0; i<n; i++)
        {
            printf("%d ", i+1);
            sum+=i;
        }
    printf("\nSum: %d", sum);
    return 0;
}