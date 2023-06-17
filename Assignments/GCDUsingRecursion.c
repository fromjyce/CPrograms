//Find the GCD using Recursion
#include <stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
int main() {
    int n,m;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);
    printf("GCD of %d and %d is %d", n, m, gcd(n, m));
    return 0;
}