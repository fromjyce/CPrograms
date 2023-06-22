/*Define a data type for Date having 3 members namely day, month and year.
Define a data type for Student with members rollnum , name , marks[5] ,
totalMarks , rank , dateofbirth (of type Date), age , gender . Use an
enumerated data type for gender with values MALE, FEMALE,
TRANSGENDER. Write a C program that gets data for N students,
computes and displays the rank of the students. Use array of structures.
Write a C function that takes an array of structures of students and compute their rank. If total marks of M students are same and get the same rank R,
then assign R+M as the rank for next student. Write another C function that
prints the mark sheet of a particular student with all the details in a proper
format designed by you.*/
#include <stdio.h>

// Enumeration for gender
enum Gender {
    MALE,
    FEMALE,
    TRANSGENDER
};

// Structure for Date
struct Date {
    int day;
    int month;
    int year;
};

// Structure for Student
struct Student {
    int rollnum;
    char name[50];
    int marks[5];
    int totalMarks;
    int rank;
    struct Date dateofbirth;
    int age;
    enum Gender gender;
};

// Function to compute rank of students
void computeRank(struct Student students[], int N) {
    int rank = 1;
    int totalMarks = students[0].totalMarks;

    students[0].rank = rank;

    for (int i = 1; i < N; i++) {
        if (students[i].totalMarks == totalMarks) {
            students[i].rank = rank;
        } else {
            rank += i;
            students[i].rank = rank;
            totalMarks = students[i].totalMarks;
        }
    }
}

// Function to print mark sheet of a particular student
void printMarkSheet(struct Student student) {
    printf("Roll Number: %d\n", student.rollnum);
    printf("Name: %s\n", student.name);
    printf("Date of Birth: %02d/%02d/%d\n", student.dateofbirth.day, student.dateofbirth.month, student.dateofbirth.year);
    printf("Age: %d\n", student.age);
    printf("Gender: ");

    switch (student.gender) {
        case MALE:
            printf("Male\n");
            break;
        case FEMALE:
            printf("Female\n");
            break;
        case TRANSGENDER:
            printf("Transgender\n");
            break;
        default:
            printf("Unknown\n");
    }

    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student.marks[i]);
    }
    printf("\n");
    printf("Total Marks: %d\n", student.totalMarks);
    printf("Rank: %d\n", student.rank);
}

int main() {
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);

    struct Student students[N];

    // Get data for each student
    for (int i = 0; i < N; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &(students[i].rollnum));

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Date of Birth (day month year): ");
        scanf("%d %d %d", &(students[i].dateofbirth.day), &(students[i].dateofbirth.month), &(students[i].dateofbirth.year));

        printf("Age: ");
        scanf("%d", &(students[i].age));

        printf("Gender (0 - Male, 1 - Female, 2 - Transgender): ");
        scanf("%d", &(students[i].gender));

        printf("Marks (5 subjects): ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &(students[i].marks[j]));
            students[i].totalMarks += students[i].marks[j];
        }
    }

    // Compute ranks of students
    computeRank(students, N);

    // Display rank of each student
    printf("\nRank of Students:\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d - Rank %d\n", i + 1, students[i].rank);
    }

    // Print mark sheet of a particular student
    int studentIndex;
    printf("\nEnter the student index to print the mark sheet (1-%d): ", N);
    scanf("%d", &studentIndex);

    if (studentIndex >= 1 && studentIndex <= N) {
        printf("\nMark Sheet:\n");
        printMarkSheet(students[studentIndex - 1]);
    } else {
        printf("\nInvalid student index!\n");
    }

    return 0;
}
