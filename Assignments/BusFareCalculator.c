/*Bus fare calculator: 								
You are provided with an array with the following details:

stops =['T','K','N','S','A','G','L']

 where : 'T' - 'Tiruporur', 'K'-'Kelambakkam', 'N' - 'Navalur','S' - 'Shollinganallur', 'A' - 'Adyar', 'G' 'Guindy','L'- 'Little mount'


Assume the distance between two consecutive stops as 5 kms .(for example, Distance between Tiruporur and Navalur is 10 kms).

You are also provided with a string as below:

coupons="10OFF"
 

Get source and destination from the user and calculate the distance to be travelled. Source and destination can take any of the values from the array ‘stops’ mentioned above.  Get the number of tickets also as input. Now according to the distance and no of tickets, the fare has to be calculated as follows:

Distance ( in kms)	Rate per ticket(in Rs)
0 to 5	10
6 to 10	20
11 to 15	30
16 to 20	40

If the distance to be travelled is more than 10 kms, ask the user to enter coupon code if he has any.

Create a function to validate the coupon using the coupon string as mentioned above. If the coupon is valid, provide 10 percent discount on total fare and display the
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to validate the coupon
bool validateCoupon(char* coupon) {
    char validCoupon[] = "10OFF";
    if (strcmp(coupon, validCoupon) == 0) {
        return true;
    }
    return false;
}

// Function to calculate the fare based on distance and number of tickets
int calculateFare(int distance, int numTickets, bool hasCoupon) {
    int fare = 0;

    if (distance <= 5) {
        fare = 10;
    } else if (distance <= 10) {
        fare = 20;
    } else if (distance <= 15) {
        fare = 30;
    } else if (distance <= 20) {
        fare = 40;
    }

    int totalFare = fare * numTickets;

    if (distance > 10 && hasCoupon) {
        totalFare = totalFare - (totalFare * 0.1); // 10% discount
    }

    return totalFare;
}

int main() {
    char stops[] = {'T', 'K', 'N', 'S', 'A', 'G', 'L'};
    int numStops = sizeof(stops) / sizeof(stops[0]);

    char source, destination;
    int numTickets, distance;
    char coupon[10];

    printf("Enter source: ");
    scanf(" %c", &source);

    printf("Enter destination: ");
    scanf(" %c", &destination);

    printf("Enter number of tickets: ");
    scanf("%d", &numTickets);

    // Calculate the distance based on the source and destination
    int sourceIndex = -1, destinationIndex = -1;
    for (int i = 0; i < numStops; i++) {
        if (stops[i] == source) {
            sourceIndex = i;
        }
        if (stops[i] == destination) {
            destinationIndex = i;
        }
    }

    if (sourceIndex == -1 || destinationIndex == -1) {
        printf("Invalid source or destination!\n");
        return 0;
    }

    distance = abs(destinationIndex - sourceIndex) * 5;

    int totalFare;

    if (distance <= 0) {
        totalFare = 0;
    } else {
        if (distance > 10) {
            printf("Enter coupon code (if any): ");
            scanf("%s", coupon);

            bool isValidCoupon = validateCoupon(coupon);

            totalFare = calculateFare(distance, numTickets, isValidCoupon);
        } else {
            totalFare = calculateFare(distance, numTickets, false);
        }
    }

    printf("Total fare: Rs %d\n", totalFare);

    return 0;
}
