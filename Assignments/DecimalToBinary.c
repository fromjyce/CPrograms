/*Convert Decimal To Binary*/
#include <stdio.h>

long long decimalToBinary(int decimalNumber) {
    long long binaryNumber = 0;
    long long placeValue = 1;

    while (decimalNumber != 0) {
        int remainder = decimalNumber % 2;
        binaryNumber += remainder * placeValue;
        decimalNumber /= 2;
        placeValue *= 10;
    }

    return binaryNumber;
}

int main() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    long long binaryNumber = decimalToBinary(decimalNumber);

    printf("Binary equivalent: %lld\n", binaryNumber);

    return 0;
}
