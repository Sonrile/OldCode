/* A program that converts an int to a string */
#include <stdio.h>
#include <stdint.h>
void int_to_string(int8_t input);	/* sets global string "output" to integer input */
void reverse();				/* reverses global string "output" */
char output[99];

int main()
{
	int_to_string(-128);
	printf("%s\n", output);
}

/* convert input to characters in global string "output" */
void int_to_string(int8_t input)
{
	int i, sign;
	int16_t num = input;		/* we set the 8 bit input to a 16 bit int because otherwise there are bit overflow problems. */
	if ((sign = num) < 0)		/* record sign */
		num = ~num + 1;		/* make num positive */
	i = 0;
	do {		/* generate digits in reverse order */
		output[i++] = num % 10 + '0';	/* get next digit */
	} while ((num /= 10) > 0);
	if (sign < 0)
		output[i++] = '-';
	output[i] = '\0';
	reverse();	/* at this point the global string "output" is inversed, so we must reverse it. */
}

/* reverses global string "output" */
void reverse()
{
	int string_size;
	for (string_size = 0; output[string_size] != '\0' && string_size < 999; string_size++)
		;					/* find size of global string "output" */
	for (int i = 0; 2 * i < string_size / 2; i++) {
		int temp = output[string_size-1 - i];
		output[string_size-1 - i] = output[i];	/* reverse the string :D */
		output[i] = temp;
	}
	output[string_size] = '\0';
}
