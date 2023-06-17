//Write a C program to calculate profit or loss.
#include <stdio.h>
int main() {
    int profit, loss, sp, cp;
    printf("Enter selling price: ");
    scanf("%d", &sp);
    printf("Enter cost price: ");
    scanf("%d", &cp);
    profit = sp - cp;
    loss = cp - sp;
    if (sp>cp)
        {
            printf("Profit: %d", profit);
        }
    else
        {
            printf("Loss: %d", loss);
        }
    return 0;
}