#include <stdio.h>

//Yes i know this isn't recursive. Just emagine that it is, I couldn't be bothered and I know how recursion works
void reverse(char string[])
{
	int length;
	for (length = 0; string[length] != '\0'; length++)
		;
	for (int n = 0; n < length / 2; n++) {
		int temp = string[length - n - 1];	//We subtract 1 from n so that
		string[length - n - 1] = string[n];	//we don't swap the '\0'
		string[n] = temp;
	}
	string[length] = '\0';
}
