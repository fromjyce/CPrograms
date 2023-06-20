/*If the total selling price of 15 items and the total profit earned on 
them is input through the keyboard, write a program to find the 
cost price of one item.*/
#include <stdio.h>
int main() {
    int sp,item,profit,cp;
    printf("Enter the number of items: ");
    scanf("%d",&item);
    printf("Enter the total selling price: ");
    scanf("%d", &sp);
    printf("Enter the total profit: ");
    scanf("%d", &profit);
    cp = (sp - profit)/item;
    printf("Cost Price: %d", cp);
    return 0;
}