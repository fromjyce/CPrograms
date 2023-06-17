//Check for multiplicability of the matrix
#include <stdio.h>
int main () {
    int r1,c1,c2,r2;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d",&r2,&c2);
    if(c1==r2)
        {
           printf("The matrix is multiplicable");
        }
    else    
        {
            printf("The matrix is not multiplicable");
        }

}