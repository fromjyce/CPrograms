/*In a gated community, there are four styles of apartment such as 1BHK, 2BHK, 3BHK and villa style. 
If the size is between 500 to 700 sq.feet  it belongs to 1BHK,  700 to 1000 sq.feet belongs to 2BHK,1000 - 1500 sq.feet belongs to 3BHK  and 1500-2400 sq.feet belongs to villa style. 
Apparently, the maintenance is calculated based on the size and sq.feet of the apartment. The Association charge Rs.3.0 per sq.feet for a month. 
However, the owners or tenants must pay the bill every quarterly. 
Write a program to get the sq.feet value of the house from user and calculate the maintenance bill for quarterly and annually depending on the size of the apartment.*/
#include <stdio.h>

int main() {
    int squareFeet;
    float maintenanceRate = 3.0;  // Rs.3.0 per sq.feet
    float quarterlyBill, annualBill;

    printf("Enter the square footage of the apartment: ");
    scanf("%d", &squareFeet);

    if (squareFeet >= 500 && squareFeet <= 700) {
        quarterlyBill = maintenanceRate * squareFeet * 3;  // Quarterly bill (3 months)
        annualBill = quarterlyBill * 4;  // Annual bill (12 months)
    } else if (squareFeet > 700 && squareFeet <= 1000) {
        quarterlyBill = maintenanceRate * squareFeet * 3;  // Quarterly bill (3 months)
        annualBill = quarterlyBill * 4;  // Annual bill (12 months)
    } else if (squareFeet > 1000 && squareFeet <= 1500) {
        quarterlyBill = maintenanceRate * squareFeet * 3;  // Quarterly bill (3 months)
        annualBill = quarterlyBill * 4;  // Annual bill (12 months)
    } else if (squareFeet > 1500 && squareFeet <= 2400) {
        quarterlyBill = maintenanceRate * squareFeet * 3;  // Quarterly bill (3 months)
        annualBill = quarterlyBill * 4;  // Annual bill (12 months)
    } else {
        printf("Invalid square footage. Please enter a value between 500 and 2400.\n");
        return 0;
    }

    printf("\n--- Maintenance Bill ---\n");
    printf("Quarterly Bill: Rs. %.2f\n", quarterlyBill);
    printf("Annual Bill: Rs. %.2f\n", annualBill);

    return 0;
}
