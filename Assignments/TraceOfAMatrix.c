//Find the trace of the matrix
#include <stdio.h>
int main() {
    int i,j,r,c,trace = 0;
    printf("Enter the row of the matrix: ");
    scanf("%d",&r);
    printf("Enter the column of the matrix: ");
    scanf("%d",&c);
    int a[r][c];
    if (r==c)
        {
            printf("Enter the elements of the matrix: \n");
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    printf("Element %d%d: ", i+1, j+1);
                    scanf("%d",&a[i][j]);
                }
            }
        }
    else
        {
            printf("The matrix is not square");
        }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==j)
                {
                    trace+=a[i][j];
                }
        }
    }
printf("Trace of the matrix is %d", trace);
return 0;
}