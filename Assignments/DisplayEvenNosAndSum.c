//Write a program in C to display the n terms of even natural number and their sum



#include <stdio.h>
int main() {
    int n,i;
    int sum = 0;
    printf("Enter the N: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
            {
                printf("%d\n",i);
                sum+=i;
            }
    }
    printf("Sum of even natural number is %d",sum);
    return 0;
}