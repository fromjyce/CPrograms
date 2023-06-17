#include <stdio.h>

int main() {
    int c, i, j;
    int a[2][2];
    int b[3][3];
    int ch;

    printf("1. 2X2 Matrix\n2. 3X3 Matrix\nEnter your choice: ");
    scanf("%d", &c);

    if (c == 1) {
        printf("Enter your elements:\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("Element %d%d: ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }

        ch = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        if (ch == 0) {
            printf("There is no inverse matrix");
            return 0;
        } else {
            b[0][0] = a[1][1] / ch;
            b[0][1] = -a[0][1] / ch;
            b[1][0] = -a[1][0] / ch;
            b[1][1] = a[0][0] / ch;

            printf("The inverse of the matrix is:\n");
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 2; j++) {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }
        }
    } else if (c == 2) {
        printf("Enter your elements:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("Element %d%d: ", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
        }

        ch = b[0][0] * b[1][1] * b[2][2] + b[0][1] * b[1][2] * b[2][0] + b[0][2] * b[1][0] * b[2][1] -
             b[0][2] * b[1][1] * b[2][0] - b[0][0] * b[1][2] * b[2][1] - b[0][1] * b[1][0] * b[2][2];

        if (ch == 0) {
            printf("There is no inverse matrix");
            return 0;
        } else {
            a[0][0] = (b[1][1] * b[2][2] - b[1][2] * b[2][1]) / ch;
            a[0][1] = (b[0][2] * b[2][1] - b[0][1] * b[2][2]) / ch;
            a[0][2] = (b[0][1] * b[1][2] - b[0][2] * b[1][1]) / ch;
            a[1][0] = (b[1][2] * b[2][0] - b[1][0] * b[2][2]) / ch;
            a[1][1] = (b[0][0] * b[2][2] - b[0][2] * b[2][0]) / ch;
            a[1][2] = (b[0][2] * b[1][0] - b[0][0] * b[1][2]) / ch;
            a[2][0] = (b[1][0] * b[2][1] - b[1][1] * b[2][0]) / ch;
            a[2][1] = (b[0][1] * b[2][0] - b[0][0] * b[2][1]) / ch;
            a[2][2] = (b[0][0] * b[1][1] - b[0][1] * b[1][0]) / ch;

            printf("The inverse of the matrix is:\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
        }
    } else {
        printf("Invalid choice");
    }

    return 0;
}
