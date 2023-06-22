/*Write a program in C to make such a pyramid pattern like a pyramid with numbers increased by 1*/
#include <stdio.h>

int main() {
    int rows, i, j, number = 1;

    printf("Enter the number of rows for the pyramid pattern: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) {
            printf("%d ", number);
            number++;
        }

        printf("\n");
    }

    return 0;
}
