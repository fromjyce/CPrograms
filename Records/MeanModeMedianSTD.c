//Functions to find mean, mode, range, variance, and standard deviation
#include <stdio.h>
#include <math.h>

void makeUnique(int arr[], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;) {
            if (arr[j] == arr[i]) {
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }
}

float calculateMean(int arr[], int n) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    return (float)sum / n;
}

int calculateMode(int arr[], int n) {
    int maxValue = 0;
    int maxCount = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        int count = 0;
        for (j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxValue = arr[i];
        }
    }

    return maxValue;
}

int calculateRange(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];
    int i;

    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max - min;
}

float calculateVariance(int arr[], int n) {
    float mean = calculateMean(arr, n);
    float variance = 0;
    int i;

    for (i = 0; i < n; i++) {
        variance += pow(arr[i] - mean, 2);
    }

    return variance / n;
}

float calculateStandardDeviation(int arr[], int n) {
    float variance = calculateVariance(arr, n);
    return sqrt(variance);
}

int main() {
    int arr[100];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    makeUnique(arr, n);

    float mean = calculateMean(arr, n);
    int mode = calculateMode(arr, n);
    int range = calculateRange(arr, n);
    float variance = calculateVariance(arr, n);
    float stdDeviation = calculateStandardDeviation(arr, n);

    printf("Mean: %.2f\n", mean);
    printf("Mode: %d\n", mode);
    printf("Range: %d\n", range);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stdDeviation);

    return 0;
}
