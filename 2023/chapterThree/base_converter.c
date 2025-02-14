/* Write a program that takes an int and converts it to base n (n being whatever the user wants) */
#include <stdio.h>
#include <stdint.h>
int string_to_int(char string[]);
int8_t compare_strings(char s1[], char s2[]);		//Returns 1 if strings are identical.
void get_string(); char input[99];			//Sets global variable "input" to user input.

int main()
{
	int number;
	while(!compare_strings(input, "exit")) {
		get_string();
		number = string_to_int(input);
		printf("%d\n", number);
	}
}

int string_to_int(char string[])
{
	int result = 0;
	int i, n;
	for (i = 0, n = 0; string[i] != '\0' && i < 999; i++, n++) {
		if (string[i] < 0)
			string[i] = -string[i];
		if(string[i] <= '9' && string[i] >= '0')
			result += (string[i] - 48) * (n * 10);
		else
			n--;	/* if the char isnt a number we dont want it to affect the power of the number */
	}
	return result;
}

//Sets global variable "input" to user input.
void get_string()
{
	int temp_char, i;
	for (i = 0; (temp_char = getchar()) != '\n'; i++)
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
	//If either of the strings are blank, the loop will be skipped and therefore we need this extra pass
	if ((s1[0] == '\0' && s2[0] != '\0') || (s1[0] != '\0' && s2[0] == '\0'))
			return 0;
	return 1;
}
