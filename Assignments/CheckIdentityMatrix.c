//Write a program to Check if a Matrix is an Identity Matrix
#include <stdio.h>
int main() {
    int r,c,i,j;
    printf("Enter the row of the matrix: ");
    scanf("%d",&r);
    printf("Enter the column of the matrix: ");
    scanf("%d",&c);
    int a[r][c];
    printf("Enter the elements of the matrix: \n");
    for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                {
                    printf("Element %d%d: ", i+1, j+1);
                    scanf("%d",&a[i][j]);
                }
        }
    for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                {
                    if(i==j)
                        {
                            if(a[i][j]!=1)
                                {
                                    printf("The matrix is not an identity matrix.\n");
                                    return 0;
                                }
                            else    
                                {
                                    printf("The matrix is an identity matrix.\n");
                                    return 0;
                                }

                        }
                }
        }
    return 0;  
}
