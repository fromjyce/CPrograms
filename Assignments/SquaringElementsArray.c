/*Take an int array as an input from the user along with the size of the array, apply the following logic and print the output.
[4,5,3,2] => 4 to the power 5 + 5 power 3 + 3 power 2 + 2 power 4*/
#include <stdio.h>
#include <math.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i], arr[(i + 1) % size]);
    }

    printf("Output: %d\n", sum);

    return 0;
}
