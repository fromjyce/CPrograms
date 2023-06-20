//Write a program in C to read 10 numbers from keyboard and find their sum and average
#include <stdio.h>
int main() {
    int i,n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: \n");
    for (i=0; i<n; i++)
        {
            printf("Element %d: ", i+1);
            scanf("%d", &a[i]);
        }
    int sum = 0;
    for (i=0; i<n; i++)
        {
            sum+=a[i];
        }
    int avg = sum/n;
    printf("Average: %d \nSum: %d", avg, sum);
    return 0;
}