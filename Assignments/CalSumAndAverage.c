//Write a program in C to read 10 numbers from keyboard and find their sum and average
#include <stdio.h>
int main() {
    int n,i;
    int sum=0;
    printf("Enter the number of integers that you want to add: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the integers: \n");
    for(i=0;i<n;i++)
        {
                printf("Integer %d: ", i+1);
                scanf("%d",&a[i]);
                sum+=a[i];
        }
    printf("The sum of the integers is: %d\n",sum);
    printf("The Average of the integers is: %d\n",sum/n);
}