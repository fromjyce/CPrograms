/*Write a program in C which accepts three file names as command line
arguments, file1 , file2 and file3 . Copy the contents of file1 to file2 .
If file1 already exists copy the contents to file2 otherwise display as no
such file. If file2 already exists, ask the user whether to overwrite the
existing contents or to append the contents and do accordingly. Now,
append the details of file3 to file2 and count the number of word
occurrences in file2 .*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int countWordOccurrences(FILE *file, const char *word) {
    char line[MAX_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            if (strcmp(token, word) == 0) {
                count++;
            }
            token = strtok(NULL, " ");
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Insufficient arguments!\n");
        printf("Usage: ./program file1 file2 file3\n");
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];
    char *file3 = argv[3];

    FILE *fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("No such file: %s\n", file1);
        return 1;
    }

    FILE *fp2 = fopen(file2, "r");
    if (fp2 != NULL) {
        char choice;
        printf("File %s already exists. Do you want to (O)verwrite or (A)ppend? ", file2);
        scanf(" %c", &choice);

        if (choice == 'O' || choice == 'o') {
            fclose(fp2);
            fp2 = fopen(file2, "w");
        } else if (choice == 'A' || choice == 'a') {
            fclose(fp2);
            fp2 = fopen(file2, "a");
        } else {
            printf("Invalid choice!\n");
            fclose(fp1);
            return 1;
        }
    } else {
        fp2 = fopen(file2, "w");
    }

    char line[MAX_LENGTH];

    // Copy contents of file1 to file2
    while (fgets(line, sizeof(line), fp1) != NULL) {
        fputs(line, fp2);
    }

    fclose(fp1);

    FILE *fp3 = fopen(file3, "r");
    if (fp3 == NULL) {
        printf("No such file: %s\n", file3);
        fclose(fp2);
        return 1;
    }

    // Append details of file3 to file2
    while (fgets(line, sizeof(line), fp3) != NULL) {
        fputs(line, fp2);
    }

    fclose(fp3);
    fclose(fp2);

    // Count word occurrences in file2
    char word[MAX_LENGTH];
    printf("Enter a word to count its occurrences in file2: ");
    scanf("%s", word);

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("Error opening file: %s\n", file2);
        return 1;
    }

    int count = countWordOccurrences(fp2, word);
    printf("Number of occurrences of '%s' in file2: %d\n", word, count);

    fclose(fp2);

    return 0;
}
