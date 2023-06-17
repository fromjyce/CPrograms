/*1.	Pass an integer array consisting of five elements to a void function named reverseCubeArray(  ). 
Modify the contents of the array in such a way that the original array is reversed and the contents cubed by making use of a swapCube(  ) function called within reverseCubeArray(  ). 
The swapCube(  ) function takes the pointer to two elements which should be swapped so as to reverse the original array with its cube. 
You may use the pow( ) function defined in math.h 
Example:
Input: [1, 2, 3, 4, 5] 
Output: [125, 64, 27, 8, 1]
*/

#include <stdio.h>
#include <math.h>

void swapCube(int* a, int* b) {
    int temp = *a;
    *a = pow(*b, 3);
    *b = pow(temp, 3);
}

void reverseCubeArray(int array[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swapCube(&array[i], &array[size - 1 - i]);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Input: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    reverseCubeArray(array, size);

    printf("Output: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

