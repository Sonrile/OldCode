/* Converts a string input to the same value, but in the base n (n being whatever you want < 35 ;D)*/
#include <stdio.h>
#include <stdint.h>
int8_t compare_strings(char s1[], char s2[]);			//Returns 1 if strings are identical.
int8_t string_is_number(char s[]);				//Returns 1 if string consists fully of numbers (can have '-' infront)
void get_string();						//Sets global variable "input" to user input.
int32_t string_to_int(char s[]);				//Returns it's input as an int ()
double powr(int x, int pow);					//returns x to the power of pow.
void int_to_base_n(int input, int base);			//sets global variable "output" to base n of input.

// Global so that every function can access them
char output[999];	/* 999 chars cuz a num in base 2 contains more chars than the input (base 9) */
char input[99];

int main()
{
	int base = 12;
	while(!compare_strings(input, "exit")) {
		get_string();					//set global variable "input" to user input.
		if (!string_is_number(input))
			printf("string isnt number");
		int_to_base_n(string_to_int(input), base);	//set global variable "output" to user input with base n.
		printf("%s\n", output);				//print result.
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

int8_t string_is_number(char s[])
{
	int count = 0;
	if (s[count] == '-')
		count++;
	
	for (; s[count] != '\0' && count < 999; count++)
		if (s[count] > '9' || s[count] < '0')
			return 0;
	return 1;
}

double powr(int x, int pow)
{
	double result = x;
	if (pow < 0)
		printf("the \"powr\" function cannot do negative powers, however you are trying to get %d to the powr of %d\n", x, pow);
	else
		for (int n = 1; n < pow; n++)
			result *= x;
	
	return (pow == 0)? 1 : result;
}

int32_t string_to_int(char s[])
{
	int length;
	int output = 0;
	int sign = (s[0] == '-')? -1 : 1;

	for (length = 0; s[length] != '\0' && length < 999; length++)
		;		/* find length of string */
	if (length == 0) {
		printf("length of input string in \"string_to_int\" is 0..\n");
		return 0;
	}
	if (length == 999) {
		printf("String inputted to function \"string_to_int\" doesnt conatin an end char ('\\0')\n");
		printf("(or is exactly 999 chars long haha, input gets capped to 999 chars so..)\n\n");
	}

	for (int n = 0; n < length && s[length-1 - n] != '-'; n++)
		output += (s[length-1 - n] - 48) * powr(10, n);

	return output * sign;
}

void int_to_base_n(int number, int base)			//sets global variable "output" to base n of input.
{
	const char nums[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int num = 1;
	int out_char = 0;

	for (int count = 0; count < number; count++) {
		if (num <= base) {
			output[out_char] = nums[num];
			num++;
		}
		else {
			num = 0;
			out_char++;
		}
	}
	output[out_char + 1] = '\0';
}
