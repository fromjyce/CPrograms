/*3.	Write a program in C to display the pattern like a pyramid using asterisk and each row contain an odd number of asterisks. */
#include <stdio.h>

int main()
{
	int rows = 5;

	// first loop to print all rows
	for (int i = 0; i < rows; i++) {

		// inner loop 1 to print white spaces
		for (int j = 0; j < 2 * (rows - i) - 1; j++) {
			printf(" ");
		}

		// inner loop 2 to print star numbers
		for (int k = 0; k < 2 * i + 1; k++) {
			printf("%d ", k + 1);
		}
		printf("\n");
	}
	return 0;
}
