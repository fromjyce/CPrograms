//Apply bubble sort to an array and search for an element
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Element found
        }

        if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key); // Search in left half
        }

        return binarySearch(arr, mid + 1, high, key); // Search in right half
    }

    return -1; // Element not found
}

int main() {
    int arr[100];
    int n, i, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, 0, n - 1, key);
    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
