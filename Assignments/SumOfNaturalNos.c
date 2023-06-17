/*Find the sum of natural numbers using recursion*/
#include <stdio.h>

int sumOfNaturalNumbers(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumOfNaturalNumbers(n - 1);
    }
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    int sum = sumOfNaturalNumbers(number);

    printf("The sum of natural numbers up to %d is: %d\n", number, sum);

    return 0;
}
