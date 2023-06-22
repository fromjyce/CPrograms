/*Palindrome check after reversing and adding. Take any positive integer of two digits or 
more, reverse the digits, and add to the original number. This is the operation of the 
reverse-then-add sequence. Now repeat the procedure with the sum so obtained until a 
palindromic number is obtained.
For example,
57 becomes palindromic after two iterations: 57+75 = 132, 132+231 = 363.
59 becomes a palindrome after three iterations: 59+95 = 154, 154+451 = 605, 605+506 
= 1111
Write a C program to get a positive integer input between 10 and 1000 and print the 
final palindrome and after how many iterations of reverse-then-add, the input number
becomes palindromic.
If the user input 59, then the output should be:
Original input: 59
Final palindrome: 1111
Number of iterations: 3
Note: There are some exceptions to this problem. Avoid using the following numbers as 
input:
196, 295, 394, 493, 592, 689, 691, 788, 790, 879, 887, 978, 986.
If a user inputs any of these numbers which are exceptions, then the program should 
print a message that the input number is exception. Also it should print what are the 
numbers which should not be tried only if the user enters any one of the above 
mentioned 13 exceptions*/
#include <stdio.h>

int reverseNumber(int n) {
    int reversed = 0;

    while (n > 0) {
        reversed = (reversed * 10) + (n % 10);
        n /= 10;
    }

    return reversed;
}

int isPalindrome(int n) {
    int original = n;
    int reversed = reverseNumber(n);

    return (original == reversed);
}

int isException(int n) {
    int exceptions[] = {196, 295, 394, 493, 592, 689, 691, 788, 790, 879, 887, 978, 986};
    int numExceptions = sizeof(exceptions) / sizeof(exceptions[0]);

    for (int i = 0; i < numExceptions; i++) {
        if (n == exceptions[i]) {
            return 1;
        }
    }

    return 0;
}

void printExceptionNumbers() {
    int exceptions[] = {196, 295, 394, 493, 592, 689, 691, 788, 790, 879, 887, 978, 986};
    int numExceptions = sizeof(exceptions) / sizeof(exceptions[0]);

    printf("Exception numbers: ");
    for (int i = 0; i < numExceptions; i++) {
        printf("%d ", exceptions[i]);
    }
    printf("\n");
}

void findPalindrome(int n) {
    int iterations = 0;

    while (!isPalindrome(n)) {
        int reversed = reverseNumber(n);
        n += reversed;
        iterations++;
    }

    printf("Original input: %d\n", n);
    printf("Number of iterations: %d\n", iterations);
}

int main() {
    int input;

    printf("Enter a positive integer between 10 and 1000: ");
    scanf("%d", &input);

    if (input < 10 || input > 1000) {
        printf("Invalid input! Please enter a number between 10 and 1000.\n");
        return 0;
    }

    if (isException(input)) {
        printf("Input number is an exception.\n");
        printExceptionNumbers();
    } else {
        findPalindrome(input);
    }

    return 0;
}
