/*Convert Decimal To Octal*/
#include <stdio.h>

long long decimalToOctal(int decimalNumber) {
    long long octalNumber = 0;
    int placeValue = 1;

    while (decimalNumber != 0) {
        int remainder = decimalNumber % 8;
        octalNumber += remainder * placeValue;
        decimalNumber /= 8;
        placeValue *= 10;
    }

    return octalNumber;
}

int main() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    long long octalNumber = decimalToOctal(decimalNumber);

    printf("Octal equivalent: %lld\n", octalNumber);

    return 0;
}
