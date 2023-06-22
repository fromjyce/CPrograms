/*Write a C program to find the transpose of a given matrix. Dynamically
create a 2-D array of type double. The dimension of the array should be read
from the user. The data should be also read from the user. The 2-D array for
storing the transpose matrix should be dynamically created. Write a function
swap() that takes two arguments to perform the transpose operation by
using pass by reference. The individual elements of the transposed matrix
should be cubed and stored. Print the final result*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(double **matrix, double **transpose, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = pow(matrix[i][j], 3); // Cube each element and store in transpose matrix
        }
    }
}

int main() {
    int rows, cols;
    int i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the original matrix
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }

    // Read data for the original matrix from the user
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Dynamically allocate memory for the transpose matrix
    double **transpose = (double **)malloc(cols * sizeof(double *));
    for (i = 0; i < cols; i++) {
        transpose[i] = (double *)malloc(rows * sizeof(double));
    }

    // Perform the transpose operation and cube the elements
    swap(matrix, transpose, rows, cols);

    // Print the final result
    printf("Transposed matrix with cubed elements:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%.2lf ", transpose[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (i = 0; i < cols; i++) {
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}
