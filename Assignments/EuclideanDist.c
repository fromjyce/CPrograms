/*Given four integers x1, y1, x2 and y2, which represents two 
coordinates (x1, y1) and (x2, y2) of a two-dimensional graph. 
The task is to find the Euclidean distance between these two 
points*/
// C program for the above approach

#include <math.h>
#include <stdio.h>

// Function to calculate distance
float distance(int x1, int y1, int x2, int y2)
{
	// Calculating distance
	return sqrt(pow(x2 - x1, 2)
				+ pow(y2 - y1, 2) * 1.0);
}

// Driver Code
int main()
{
	printf("%.2f", distance(3, 4, 4, 3));
	return 0;
}
