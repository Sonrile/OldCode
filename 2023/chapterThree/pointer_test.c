#include <stdio.h>
char ** pointer_function(char array[]);		/* A function that returns a pointer to a value */

int main()
{
	char array[] = "abcdefg";
	printf("Result:\t%s\n", pointer_function(array));
}

char ** pointer_function(char array[])
{
	char ** result = &array;
	return ** result;
}
