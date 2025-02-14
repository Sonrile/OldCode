// A function strrindex(string s, char c) that returns the position of the rightmost c in string s (-1 if none)
#include <stdio.h>
#include <stdint.h>
int8_t compare_strings(char s1[], char s2[]);		//Returns 1 if strings are identical.
int8_t strrindex(char str[], char ch);			//can be an 8 bit int since input char is capped to 99 chars.
void get_string(char s[99]);				//Sets string s to user input.
char get_char();					//Sets returns last char of user input (ignoring the final \n).

int main()
{
	char sentence[99];
	while(!compare_strings(sentence, "exit")) {
		printf("input sentence:\n");
		get_string(sentence);
		printf("input char to locate:\n");
		printf("\n%d\n", strrindex(sentence, get_char()));
	}
}

//Sets string s to user input
void get_string(char s[99])
{
	int temp_char, i;
	for (i = 0 ;(temp_char = getchar()) != '\n'; i++)
		s[i] = temp_char;
	s[i] = '\0';

	if (i > 99)
		printf("the input string was cut off (max input = 99 chars)\n");
}

//Sets char d to user input
char get_char()
{
	char temp;
	char output = '\n';	//if the input was a newline character, it would be skipped and
				//c would be unchanged, so we must set it beforehand.
	for (int i = 0 ;(temp = getchar()) != '\n'; i++)	//We set the input to a temp variable so that
		output = temp;					//c only gets set to the character before '\n'
	if (output == '\n')
		printf("input char was a newline character (\'\\n\')\n");

	return output;
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

//Returns the position of the rightmost char c in string s, -1 if none.
int8_t strrindex(char str[], char ch)
{
	int8_t output = -1;
	for (int n = 0; str[n] != '\0' && n < 99; n++)
		if (str[n] == ch)				// I think this code explains itself, not to brag
			output = n;
	return output;
}
