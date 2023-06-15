//Print the Address of the Array elements
#include <stdio.h>
int main () {
    int i;
    int n;
    int a[] = {1,2,3,4,5,6};
    n = sizeof(a);
    for (i=0; i<n; i++)
        {
            printf("\n%d -> %p", a[i], &a[i]);
        }
}