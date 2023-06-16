#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10], m, n, p, q, sum = 0, i, j, k;
    printf("Enter the number of rows of the first matrix\n");
    scanf("%d", &m);
    printf("Enter the number of columns of the first matrix\n");
    scanf("%d", &n);
    printf("Enter the number of rows of the second matrix\n");
    scanf("%d", &p);
    printf("Enter the number of columns of the second matrix\n");
    scanf("%d", &q);

    // Check whether matrix multiplication is applicable
    if (n != p) {
        printf("\nMatrices with entered orders can't be multiplied with each other.\n");
        printf("\nThe column of the first matrix must be equal to the row of the second.\n");
    } else {
        printf("Enter the elements of the first matrix\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("Enter the element of [%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        printf("The first matrix is: \n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("\t%d", a[i][j]);
            }
            printf("\n");
        }

        printf("Enter the elements of the second matrix\n");
        for (i = 0; i < p; i++) {
            for (j = 0; j < q; j++) {
                printf("Enter the element of [%d][%d]: ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        printf("The second matrix is: \n");
        for (i = 0; i < p; i++) {
            for (j = 0; j < q; j++) {
                printf("\t%d", b[i][j]);
            }
            printf("\n");
        }

        // Multiplication
        for (i = 0; i < m; i++) {
            for (j = 0; j < q; j++) {
                for (k = 0; k < p; k++) {
                    sum = sum + a[i][k] * b[k][j];
                }
                c[i][j] = sum;
                sum = 0;
            }
        }

        printf("\nThe product of the entered matrices is:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < q; j++) {
                printf("\t%d", c[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
