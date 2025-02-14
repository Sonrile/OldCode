/* Converts a string input to an int output */
#include <stdio.h>
#include <stdint.h>
int8_t compare_strings(char s1[], char s2[]);			//Returns 1 if strings are identical.
void get_string(); char input[99];				//Sets global variable "input" to user input.
int32_t string_to_int(char s[]);				//Converts all numbers (and letters) in input to an int.
double powr(int x, int pow);					//returns x to the power of pow.

int main()
{
	int base = 10;
	while(!compare_strings(input, "exit")) {
		get_string();					//set global variable "input" to user input.
		printf("%d\n", string_to_int(input));		//print result as an int.
	}
}

//Sets global variable "input" to user input.
void get_string()
{
	int temp_char, i;
	for (i = 0 ;(temp_char = getchar()) != '\n'; i++)
		input[i] = temp_char;
	input[i] = '\0';
}

//Returns 1 if strings are identical.
//strings must be <999 chars, or else for loop breaks. (To prevent crashes obviously)
int8_t compare_strings(char s1[], char s2[])
{
	for (int i = 0; s1[i] != '\0' || s2[i] != '\0' && i < 999; i++)
		if (s1[i] != s2[i])
			return 0;
	return 1;
}

double powr(int x, int pow)
{
	double result = x;
	for (int n = 1; n < pow; n++)
		result *= x;
	
	return (pow == 0)? 1 : result;
}

int32_t string_to_int(char s[])
{
	int length;
	int output = 0;
	int sign = (s[0] != '-')? 1 : -1;
	printf("sign:	%d\n", sign);

	for (length = 0; s[length] != '\0' && length < 999; length++)
		;		/* find length of string */

	for (int n = 0; n < length && s[length-1 - n] != '-'; n++) {
		output += (s[length-1 - n] - 48) * powr(10, n);
		printf("output%d += %f\n", n, (s[length-1 - n] - 48) * powr(10, n));
		/* printf("s[length-1 - n] - 48 = %d\n", s[length-1 - n] - 48); */
		/* printf("pow = %f\n", powr(10, n)); */
	}

	return output * sign;
}
