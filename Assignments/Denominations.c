/*A cashier has currency notes of denominations 10, 50 and 100. 
If the amount to be withdrawn is input through the keyboard in 
hundreds, find the total number of currency notes of each 
denomination the cashier will have to give to the withdrawer.*/
#include <stdio.h>

int main() {
    int amount, note10 = 0, note50 = 0, note100 = 0;

    printf("Enter the amount to be withdrawn (in hundreds): ");
    scanf("%d", &amount);

    // Calculate number of 100s
    note100 = amount;
    amount %= 100;

    // Calculate number of 50s
    note50 = amount / 50;
    amount %= 50;

    // Calculate number of 10s
    note10 = amount / 10;

    // Display the result
    printf("Currency breakdown:\n");
    printf("100s: %d\n", note100);
    printf("50s: %d\n", note50);
    printf("10s: %d\n", note10);

    return 0;
}
