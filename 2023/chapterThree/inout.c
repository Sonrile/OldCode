//Get basic communication between the user and program
#include <stdio.h>
#include <stdint.h>
#define INPUT_SIZE 999
int8_t compare_strings(char s1[], char s2[]);		//Returns 1 if strings are identical.
void get_string(); char input[INPUT_SIZE];			//Sets global variable "input" to user input.

int8_t getstr_overflow = 0;

int main()
{
	while(!compare_strings(input, "exit")) {
		get_string();
		printf("%s\n", input);
	}
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
			if (i >= 0 && i <= INPUT_SIZE)
				input[i] = temp_char;
			
	if (i >= INPUT_SIZE || i < 0) {	//If i is not within 0-999 threshold, assume get_string has overflowed
		printf("Input has been truncated to %d chars\n", INPUT_SIZE - 1);
		getstr_overflow = 1;
		i = INPUT_SIZE;		//Set i to the size of the input string so that "input[i] = '\0'" isnt out of bounds
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
