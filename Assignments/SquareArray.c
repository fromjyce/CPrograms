//Print squared of the elements of the array
#include <stdio.h>
int main () {
    int i,n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for (i=0; i<n; i++)
        {
            printf("Element %d: ",i+1);
            scanf("%d",&a[i]);
        }
    printf("Squared Elements of the array: \n");
    for (i=0; i<n; i++)
        {
            printf("\nElement %d: %d \n",i+1,a[i]*a[i]);
        }
    return 0;
}