//Get basic communication between the user and program
#include <stdio.h>
#include <stdint.h>
int8_t compare_strings(char s1[], char s2[]);		//Returns 1 if strings are identical.
void get_string(); char input[99];			//Sets global variable "input" to user input.

int main()
{
	while(!compare_strings(input, "exit")) {
		get_string();
		printf("%s\n", input);
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
