/*A restaurant has 5 waiters (Waiter IDs: 1 to 5) and has 5 items (Item IDs: 1
to 5) in the menu. Each waiter writes a slip for each customer (Assume 1
customer orders only 1 item). The slip contains the following information:
a) Waiter ID
b) Item ID
c) Cost of the item (in Rupees)
At the end of the day, all the slips are consolidated. Write a program to read
the information from each slip and summarize the data into a table (2D
array). Print the results in tabular format with each column representing a
waiter and each row representing an item. Total each row to find the total
sales (in Rupees) of an item on that day. Total each column to find the total
sales (in Rupees) by each waiter. Column totals should be printed below
each column and row totals should be printed to the right of each row.*/
#include <stdio.h>

#define NUM_WAITERS 5
#define NUM_ITEMS 5

int main() {
    int sales[NUM_ITEMS][NUM_WAITERS] = {0}; // 2D array to store sales information
    int waiterID, itemID, cost;

    // Read slip information until the end-of-file is reached (Ctrl+D on Unix/Linux, Ctrl+Z on Windows)
    while (scanf("%d %d %d", &waiterID, &itemID, &cost) == 3) {
        // Increment the sales for the corresponding waiter and item
        sales[itemID - 1][waiterID - 1] += cost;
    }

    // Print the table header
    printf("Item\t");
    for (int i = 0; i < NUM_WAITERS; i++) {
        printf("Waiter %d\t", i + 1);
    }
    printf("Total\n");

    // Print the table rows
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Item %d\t", i + 1);
        int rowTotal = 0;
        for (int j = 0; j < NUM_WAITERS; j++) {
            printf("%d\t\t", sales[i][j]);
            rowTotal += sales[i][j];
        }
        printf("%d\n", rowTotal);
    }

    // Print the column totals
    printf("Total\t");
    int grandTotal = 0;
    for (int j = 0; j < NUM_WAITERS; j++) {
        int colTotal = 0;
        for (int i = 0; i < NUM_ITEMS; i++) {
            colTotal += sales[i][j];
        }
        printf("%d\t\t", colTotal);
        grandTotal += colTotal;
    }
    printf("%d\n", grandTotal);

    return 0;
}

