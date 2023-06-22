/*Write a function that calculates the sum of all the even numbers between
two given numbers using recursion*/
#include <stdio.h>

int sumEvenNumbers(int start, int end) {
    if (start > end) {
        return 0;
    }

    if (start % 2 != 0) {
        // If the start number is odd, increment it by 1
        start++;
    }

    return start + sumEvenNumbers(start + 2, end);
}

int main() {
    int start, end;

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    int sum = sumEvenNumbers(start, end);

    printf("Sum of even numbers between %d and %d is: %d\n", start, end, sum);

    return 0;
}
