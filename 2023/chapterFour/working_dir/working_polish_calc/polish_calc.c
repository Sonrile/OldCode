#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
	int type;	/* The type of operand that s is */
	double op2;	/* placeholder variable */
	char s[MAXOP];	/* The input string (holds next operator or number) */

	while ((type = getop(s)) != EOF) {	// here, getop modifies s[] to only be
		switch (type) {			// the next number or operand
		case NUMBER:	/* If the string is a number, push it as a double */
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2!= 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
