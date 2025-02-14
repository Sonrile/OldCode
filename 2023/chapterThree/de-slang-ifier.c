//A program that expands all shorthand-notations like a-z into abc...xyz
#include <stdio.h>
#include <stdint.h>
#define INPUT_SIZE 999

int8_t compare_strings(char s1[], char s2[]);		//Returns 1 if strings are identical.
void get_string(); char input[INPUT_SIZE]; int8_t getstr_overflow = 0;		//Sets global variable "input" to user input.
void deslang();	char temp_str[INPUT_SIZE];		//Expands all shorthand-notations in "input" string
int8_t expand(char c1, char c2, int temp_iteration);	//Adds expanded letters to the temp_str string
int8_t is_letter(char c);
int8_t is_number(char c);

void str_to_str(char s1[], char s2[]);

int main()
{
	/* while(!compare_strings(input, "exit")) { */
		/* get_string();	//Sets global "input" string to user input. */
		str_to_str(input, "a-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-za-z");
		deslang();	//Expands all shorthand notations in "input" string.
		printf("%s\n", input);	//Print result to screen.
	/* } */
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

//Sets global variable "input" to user input.
//Has a limit of 999 chars inputted
void get_string()
{
	if (getstr_overflow) {		//Check to see if get_string has overflowed
		getstr_overflow = 0;	//If it has, then the current input data is overflowed
		return;			//from the user's last input and must be ignored.
	}
	int temp_char, i;
	for (i = 0 ;(temp_char = getchar()) != '\n'; i++) //Set input string to user input, only stopping after '\n' is found
			if (i >= 0 && i <= INPUT_SIZE)	  //but only setting the char to the input string if it is within the input
				input[i] = temp_char;	  //string's range
			
	if (i >= INPUT_SIZE || i < 0) {	//If i is not within 0-INPUT_SIZE threshold, assume get_string has overflowed
		printf("Input has been truncated to %d chars\n", INPUT_SIZE - 1);
		getstr_overflow = 1;
		i = INPUT_SIZE;		//Set i to the size of the input string so that "input[i] = '\0'" isnt out of bounds
	}
	input[i] = '\0';
}

//Expands all shorthand-notations in "input" string
void deslang()
{
	int i, t;		//"i" is the count for the input string, and t is the count for the temp string
	int8_t print_char = 1;	//Tells us if we should print the current char or not.
	int8_t need_repeat = 0;	//If this is true, the function is repeated so that sequences such as "a-g-j" can be expanded

	//Loop over every char, looking for x-x so that we can expand them
	for (i = 0, t = 0; input[i] != '\0'; i++, t++) {
		if ((is_letter(input[i]) == 1) && input[i+1] == '-' && (is_letter(input[i+2]) == 1) && input[i] <= input[i+2]) {
			if (expand(input[i], input[i+2], t) != 1) {	/* send the chars to be expanded to the expand function */
				printf("Error: Output cannot be larger than %d chars", INPUT_SIZE - 1);	//If expand throws error, cancel expansion
				return;
			}
			t+=input[i+2] - input[i];		/* increase the temp string count by the amound of chars just expanded */
			need_repeat=1;
			print_char=0;
			i+=2;		/* Increase the input string's count by 2 so that the two chars "-x" of "x-x" are skipped */
		}
		else if ((is_letter(input[i]) == 2) && input[i+1] == '-' && (is_letter(input[i+2]) == 2) && input[i] <= input[i+2]) {
			if (expand(input[i], input[i+2], t) != 1) {
				printf("Error: Output cannot be larger than %d chars", INPUT_SIZE - 1);
				return;
			}
			t+=input[i+2] - input[i];
			need_repeat=1;
			print_char=0;
			i+=2;
		}
		else if (is_number(input[i]) && input[i+1] == '-' && is_number(input[i+2]) && input[i] <= input[i+2]) {
			if (expand(input[i], input[i+2], t) != 1) {
				printf("Error: Output cannot be larger than %d chars", INPUT_SIZE - 1);
				return;
			}
			t+=input[i+2] - input[i];
			need_repeat=1;
			print_char=0;
			i+=2;
		}
		if (print_char)
			temp_str[t] = input[i];	
		print_char = 1;
	}

	temp_str[t] = '\0';
	//Set input string to temp_str
	for (int i = 0; temp_str[i] != '\0'; i++)
		input[i] = temp_str[i];
	input[t] = '\0';
	if (need_repeat) deslang();
}

//Adds letters between "c1" and "c2" to the global temp_str string, starting at the end of the string
int8_t expand(char c1, char c2, int temp_iteration)
{
	if (temp_iteration > INPUT_SIZE - (c2 - c1 + 1)) {
		//Output is trying to exceed the input_size char limit; clear all strings and return 0.
		for (int n = 0; n < 100; n++)
			input[n] = temp_str[n] = '\0';
		return 0;
	}
	for (int i = 0; i <= (c2 - c1); i++) {
		temp_str[(temp_iteration + i)] = i + c1;
	}
	return 1;
}

//Returns 1 if lowercase, 2 if uppercase and 0 if not a letter
int8_t is_letter(char c)
{
	if (c <= 'z' && c >= 'a')
		return 1;
	if (c <= 'Z' && c >= 'A')
		return 2;
	return 0;
}

int8_t is_number(char c)
{
	if((c <= '9' && c >= '0'))
		return 1;
	return 0;
}

void str_to_str(char s1[], char s2[])
{
	for(int n = 0; n < INPUT_SIZE; n++)
		s1[n] = s2[n];
}
