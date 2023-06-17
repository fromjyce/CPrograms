/*ConvertBinarytoDecimal*/
#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0;
    int exponent = 0;

    while (binaryNumber != 0) {
        int remainder = binaryNumber % 10;
        decimalNumber += remainder * pow(2, exponent);
        binaryNumber /= 10;
        exponent++;
    }

    return decimalNumber;
}

int main() {
    long long binaryNumber;

    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);

    int decimalNumber = binaryToDecimal(binaryNumber);

    printf("Decimal equivalent: %d\n", decimalNumber);

    return 0;
}
