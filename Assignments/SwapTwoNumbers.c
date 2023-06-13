// Write a function to swap 2 numbers. The parameters should be pointer variables
#include <stdio.h>
void swap(int * a, int * b);
int main (){
    int a,b;
    printf ("Enter two numbers: ");
    scanf ("%d %d", &a, &b);
    swap(&a, &b);
}
void swap(int * a, int * b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
    printf ("First number: %d \nSecond Number: %d",*a, *b);
}

