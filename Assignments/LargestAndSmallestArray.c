//Write a program to find the largest and smallest element of an array.
#include <stdio.h>
int main () {
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
    int max = a[0];
    int min = a[0];
    for (i=1; i<n; i++)
        {
            if (a[i] > max)
                {
                    max = a[i];
                }
        }
    for (i=1; i<n; i++)
        {
            if(a[i] < min)
                {
                    min = a[i];
                }
        
    printf("\nMaximum Element: %d", max);
    printf("\nMinimum Element: %d", min);
    return 0;
}