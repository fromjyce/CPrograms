/*A recent event was conducted by an NGO for women and those who were part of the event are provided with a participation certificate.
The user must enter the name and check on marital status as married with a yes or no. 
Depending on the marital status, the program must print her name with Miss or Mrs on the certificate.*/

#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char maritalStatus[4];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character from the input

    printf("Are you married? (yes/no): ");
    fgets(maritalStatus, sizeof(maritalStatus), stdin);

    // Remove the newline character and convert the input to lowercase
    maritalStatus[strcspn(maritalStatus, "\n")] = '\0';
    for (int i = 0; maritalStatus[i]; i++) {
        maritalStatus[i] = tolower(maritalStatus[i]);
    }

    printf("\n--- Participation Certificate ---\n");

    if (strcmp(maritalStatus, "yes") == 0) {
        printf("This is to certify that Mrs. %s\n", name);
    } else if (strcmp(maritalStatus, "no") == 0) {
        printf("This is to certify that Miss %s\n", name);
    } else {
        printf("Invalid marital status. Please enter 'yes' or 'no'.\n");
    }

    return 0;
}
