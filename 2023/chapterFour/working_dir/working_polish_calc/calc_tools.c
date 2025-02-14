#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 100	/* maximum depth of val stack */
#define NUMBER '0'	/* signal that a number was found */

int getch(void);	/* get a (possibly pushed back) character */
void ungetch(int c);	/* push character back on input */

int sp = 0;		/* next free stack position */
double stack[MAXSTACK];	/* value stack */

/* push:	push f onto value stack */
void push (double f)
{
	if (sp < MAXSTACK)
		stack[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop:	pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return stack[--sp];
	else {
		printf("error: stack empty%d\n", sp);
		return 0.0;
	}
}

/* getop:	sets s[] to be the next operator or number while */
/* also returning the value of the newly set operator or number. */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
