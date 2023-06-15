//Find the size of the size of number of elements in the array
#include <stdio.h>
int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    int len = 0 ;
    len = sizeof(a) / sizeof(a[0]);
    print("%d",len);
    return 0;
}