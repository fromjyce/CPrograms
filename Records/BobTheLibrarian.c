/*Write an interactive C program to maintain a list of names, addresses and
telephone numbers. Store the information as records in a file by representing
each record as a structure. By using   fread  and  fwrite  functions for reading and writing, 
perform the following operations:
Computer Science Lab Exercises 7
i) Insert a new record in mth  position
ii) Delete a record based upon the given name
iii) Display nt h record
Hint: Existing records should not get affected during insertion and
deletion operation. Use  fseek function*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20

struct Record {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

void insertRecord(FILE *file, int position) {
    struct Record newRecord;

    printf("Enter name: ");
    fgets(newRecord.name, sizeof(newRecord.name), stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = '\0'; // Remove newline character

    printf("Enter address: ");
    fgets(newRecord.address, sizeof(newRecord.address), stdin);
    newRecord.address[strcspn(newRecord.address, "\n")] = '\0'; // Remove newline character

    printf("Enter phone: ");
    fgets(newRecord.phone, sizeof(newRecord.phone), stdin);
    newRecord.phone[strcspn(newRecord.phone, "\n")] = '\0'; // Remove newline character

    fseek(file, position * sizeof(struct Record), SEEK_END);
    fwrite(&newRecord, sizeof(struct Record), 1, file);
}

void deleteRecord(FILE *file, const char *name) {
    FILE *tempFile = fopen("temp.dat", "wb");
    struct Record currentRecord;

    while (fread(&currentRecord, sizeof(struct Record), 1, file)) {
        if (strcmp(currentRecord.name, name) != 0) {
            fwrite(&currentRecord, sizeof(struct Record), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("records.dat");
    rename("temp.dat", "records.dat");
    file = fopen("records.dat", "rb");
}

void displayRecord(FILE *file, int position) {
    struct Record currentRecord;

    fseek(file, position * sizeof(struct Record), SEEK_SET);
    fread(&currentRecord, sizeof(struct Record), 1, file);

    printf("Name: %s\n", currentRecord.name);
    printf("Address: %s\n", currentRecord.address);
    printf("Phone: %s\n", currentRecord.phone);
}

int main() {
    FILE *file = fopen("records.dat", "ab+");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int choice;
    int position;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\n*** Menu ***\n");
        printf("1. Insert new record\n");
        printf("2. Delete record\n");
        printf("3. Display record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter the position to insert the new record: ");
                scanf("%d", &position);
                getchar(); // Consume newline character
                insertRecord(file, position);
                printf("Record inserted successfully!\n");
                break;
            case 2:
                printf("Enter the name of the record to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                deleteRecord(file, name);
                printf("Record deleted successfully!\n");
                break;
            case 3:
                printf("Enter the position of the record to display: ");
                scanf("%d", &position);
                getchar(); // Consume newline character
                displayRecord(file, position);
                break;
            case 4:
                fclose(file);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
