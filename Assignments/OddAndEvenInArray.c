//Print Even and Odd numbers in the array
#include <stdio.h>
int main() {
    int i,n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: \n");
    for (i=0; i<n; i++)
        {
            printf("Element %d: ", i+1);
            scanf("%d", &a[i]);
        }
    printf("\nEven Elements of the array: \n");
    for (i=0; i<n; i++)
        {
            if(a[i]%2==0)
                {
                    printf("%d ", a[i]);
                }
        }
    printf("\nOdd Elements of the array: \n");
    for(i=0; i<n; i++)
        {
            if (a[i]%2!=0)
                {
                    printf("%d ", a[i]);
                }
        }
    return 0;
}