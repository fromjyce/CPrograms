//C Program to find the sum of two matrices
#include <stdio.h>
int main () {
    int n,m,i,j;
    printf("Enter the row of the two matrices: ");
    scanf("%d", &n);
    printf("Enter the column of the two matrices: ");
    scanf("%d", &m);
    int a[n][m];
    int b[n][m];
    printf("Enter the elements of the first matrix: \n");
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("Enter Element %d%d: ",i+1,j+1);
                scanf("%d", &a[i][j]);
            }
        }
    printf("Enter the elements of the second matrix: \n");
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("Enter Element %d%d: ",i+1,j+1);
                scanf("%d", &b[i][j]);
            }
        }
    int c[n][m];
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                c[i][j]=a[i][j]+b[i][j];
            }
        }
    printf("The sum of the two matrices is: \n");
    for (i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
}
