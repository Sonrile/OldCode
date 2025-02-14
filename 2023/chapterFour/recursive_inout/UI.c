//Get basic communication between the user and program
#include <stdio.h>
#include <stdint.h>
#include "recursive_inout.h"
int8_t compare_strings(char s1[], char s2[]);		//Returns 1 if strings are identical.
void get_string(); 					//Sets global variable "input" to user input.

static char input[STRING_SIZE];
char output[STRING_SIZE];
static int8_t getstr_overflow = 0;
static long input_as_int;				//Input, converted to int

int main()
{
	int loop_limit = 0;
	while(loop_limit++ < 999) {
		printf("\nEnter an integer to be converted, or type \"exit\" to exit:\n");
		get_string();
		if (compare_strings(input, "exit"))
			break;
		if ((input_as_int = string_to_int(input)) == -1)
			continue;	//Input has contained letters, string_to_int has printed an error
					//and we must skip this itteration.
		printf("This is your string as an int:\n%ld\n", input_as_int);
		int_to_string(input_as_int);
		printf("This is that int as a string:\n%s\n", output);
	}

	if (loop_limit >= 999)
		printf("This program is limited to 999 conversions\nRun again to continue.");
}
//Sets global variable "input" to user input.
//Has a limit of 999 chars inputted
void get_string()
{
	if (getstr_overflow) {		//Check to see if get_string has overflowed
		getstr_overflow = 0;	//If it has, then the current input data is overflowed
		return;			//from the user's last input and must be ignored.
	}
	int temp_char, i;
	for (i = 0 ;(temp_char = getchar()) != '\n'; i++)
			if (i >= 0 && i <= STRING_SIZE)
				input[i] = temp_char;
			
	if (i >= STRING_SIZE || i < 0) {	//If i is not within 0-999 threshold, assume get_string has overflowed
		printf("Input has been truncated to %d chars\n", STRING_SIZE - 1);
		getstr_overflow = 1;
		i = STRING_SIZE;		//Set i to the size of the input string so that "input[i] = '\0'" isnt out of bounds
	}
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
