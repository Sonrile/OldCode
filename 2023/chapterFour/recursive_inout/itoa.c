//Create a function that converts an int to a string using a function that calls itself recursively
#include <stdio.h>
#include "recursive_inout.h"
extern char output[];
static int i = 0;

//Converts external string output to 'n'
void int_to_string(int n)	//I is the iteration of output.
{
	if (n < 0) {
		output[i++] = '-';
		n = -n;
	}

	if (n / 10)
		int_to_string(n / 10);
	else {
		i = 0;
		for (int x = 0; x < STRING_SIZE; x++)
			output[x] = '\0';
	}
	output[i++] = n % 10 + '0';
}
