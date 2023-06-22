/*Consider a number sequence generation approach as follows:
a) Assume we start with number n.
b) If n is even, divide by 2 and update value of n with new result.
c) If n is odd, then multiply by 3 and add 1. Update the value of n with this new result.
d) Repeat steps 2 and 3 until the updated value of n is 1.
For an input n, the cycle-length of n is the number of numbers generated up to and 
including the 1.
As an example, if the input number for n is 22, then the sequence of number generated 
according to the above-mentioned rule is:
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
The cycle length is 16 when n is 22.
Another example:
n = 13
Sequence is: 13 40 20 10 5 16 8 4 2 1
Cycle length : 10*/
#include <stdio.h>

int calculateCycleLength(int n) {
    int cycleLength = 1;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (n * 3) + 1;
        }
        cycleLength++;
    }

    return cycleLength;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int cycleLength = calculateCycleLength(n);
    printf("Cycle length for %d is %d\n", n, cycleLength);

    return 0;
}
