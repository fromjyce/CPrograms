/*Program to calculate sum of n subjects and find percentage.*/
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of subjects: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int marks;
        printf("Enter the marks of subject %d: ", i);
        scanf("%d", &marks);
        sum = sum + marks;
    }
    float percentage = (float)sum / n;
    printf("The total is %d", sum);
    printf("\nThe percentage is %.2f", percentage);
    return 0;
}
