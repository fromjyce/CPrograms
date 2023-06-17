//Check positive or negative number
#include <stdio.h>
int main() {
    int a;
    printf("Enter number: ");
    scanf("%d",&a);
    if(a>0)
        {
            printf("%d is a positive number",a);
        }
    else if (0>a)
        {
            printf("%d is a negative number",a);
        }
    else
        {
            printf("%d is neither positive nor negative",a);
        }    
    return 0;
}