#include <stdio.h>
int main() {
    int n,i;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    printf("The Natural numbers upto %d : \n", n);
    for (i=0; i<n; i++)
        {
            printf("%d ", i+1);
        }
    return 0;
}