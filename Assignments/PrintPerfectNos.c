/*Print Perfect Numbers*/
#include <stdio.h>

int isPerfectNumber(int number) {
    int sum = 0;

    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return (sum == number);
}

int main() {
    printf("Perfect numbers between 1 and 50 are:\n");

    for (int i = 1; i <= 50; i++) {
        if (isPerfectNumber(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
