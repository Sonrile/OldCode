//Create a binary search function with only one test inside the loop
#include <stdio.h>
int binsearch(int target, int array[], int length);

int main()
{
	int array[] = {9, 17, 29, 38, 40, 54};
	int length = 6;

	printf("Result:\t%d\n", binsearch(54, array, length));
}

int binsearch(int target, int array[], int length)
{
	int low, high, mid;
	high = length - 1;
	low = 0;

	//Loop untill match is found, or low <= high
	while (array[(mid = (low+high) / 2)] != target && low <= high)
		if (target < array[mid])
			high = mid - 1;
		else
			low = mid + 1;
	return (array[mid] != target)? -1 : mid ;
}
