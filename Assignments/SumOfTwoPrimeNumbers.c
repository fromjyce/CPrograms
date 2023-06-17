#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int isSumOfPrimes(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num - i)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isSumOfPrimes(number)) {
        printf("%d can be expressed as the sum of two prime numbers.\n", number);
    } else {
        printf("%d cannot be expressed as the sum of two prime numbers.\n", number);
    }

    return 0;
}
