/* Converts a string input to an int output */
#include <stdio.h>
#include <stdint.h>

static double powr(int x, int pow)
{
	double result = x;
	for (int n = 1; n < pow; n++)
		result *= x;
	
	return (pow == 0)? 1 : result;
}

long string_to_int(char s[])
{
	int length;
	int output = 0;
	int sign = (s[0] != '-')? 1 : -1;

	for (length = 0; s[length] != '\0' && length < 999; length++)
		;		/* find length of string */
	if (length > 9) {
		printf("Info:\tSTRING_TO_INT FUNCTION WILL ONLY CONVERT 9 CHARS, INPUT TRUNCATED\n");
		length = 9;	//Truncate string by limiting the length to 9
	}

	for (int n = 0; n < length && s[length-1 - n] != '-'; n++) {
		output += (s[length-1 - n] - 48) * powr(10, n);

		if (s[length-1 - n] < '0' || s[length-1 - n] > '9') {
			printf("Input contains non-numbers.. don't do that\n");
			return -1;
		}
	}
	return output * sign;
}
