//Write a program that converts user input from scientific notation to a double.
#include <math.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 100 

double powr(double val, int exp);

//Converts string with optional scientific notation into a double
//E.g 192.1234e4 --> 1921234
double atof(char s[])
{
	printf("atof input:\t%s\n", s);
	double val, pow;
	int sign, i;
	for (i = 0; isspace(s[i]); i++)	/* ignore spaces */
		;
	sign = (s[i] != '-')? 1 : -1;
	pow = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = val * 10 + (s[i] - '0');
	if (s[i] == '.') {
		i++;
		for (; isdigit(s[i]); i++) {
			val = val * 10 + (s[i] - '0');
			pow /= 10;
		}
	}
	
	int sci_sign, sci_pow, sci_val;
	if (s[i] == 'e' || s[i] == 'E') {	/* check for exponent */
		i++;
		sci_sign = (s[i] == '-')? -1 : 1;	/* Collect information */
		if (s[i] == '+' || s[i] == '-')
			i++;
		sci_val = 0;
		for (; isdigit(s[i]); i++)
			sci_val = sci_val * 10 + (s[i] - '0');
		sci_pow = powr(10, sci_val);

		if (sci_sign == 1) {			/* return information */
			printf("atof result:\t%f\n", (sign * pow * val) * sci_pow);
			return (sign * pow * val) * sci_pow;
		}
		printf("atof result:\t%f\n", (sign * pow * val) / sci_pow);
		return (sign * pow * val) / sci_pow;
	}
	printf("atof result:\t%f\n", sign * pow * val);
	return sign * pow * val;
}

double powr(double val, int exp)
{
	if (val < 0 || exp < 0)
		printf("inputs in the powr funtion cannot be negative.\n");
	if (exp == 0)
		return 1;

	double output = val;
	for (int i = 0; i < exp - 1; i++)
		output *= val;
	return output;
}
