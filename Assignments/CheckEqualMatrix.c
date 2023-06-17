//Check for Equal matrix
#include <stdio.h>
int main() {
    int i1,j1,r1,c1,i2,j2,r2,c2,flag;
    printf("Enter the row and column of first matrix: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter the row and column of second matrix: ");
    scanf("%d%d",&r2,&c2);
    int m1[r1][c1],m2[r2][c2];
    if(r1==r2 && c1==c2)
        {
            printf("Enter the elements of the first matrix: \n");
            for(i1=0; i1<r1; i1++)
                {
                    for(j1=0; j1<c1; j1++)
                        {
                            printf("Element %d%d: ", i1+1, j1+1);
                            scanf("%d",&m1[i1][j1]);
                        }
                }
            printf("Enter the elements of the second matrix: \n");
            for(i2=0; i2<r2; i2++)
                {
                    for(j2=0; j2<c2; j2++)
                        {
                            printf("Element %d%d: ", i2+1, j2+1);
                            scanf("%d",&m2[i2][j2]);
                        }
                }
            for(i1=0; i1<r1; i1++)
                {
                    for(j1=0; j1<c1;j1++)
                        {
                            if(m1[i1][j1]!=m2[i1][j1])
                                {
                                    flag = 1;
                                }

                            else
                                {
                                    flag = 0;
                                }
                        }
                }
            if(flag==1)
                {
                    printf("The matrices are not equal");
                }
            else
                {
                    printf("The matrices are equal");
                }
        }
    else    
        {
            printf("Matrices doesn't have equal dimensions.\n");
            return 0;
        }
}