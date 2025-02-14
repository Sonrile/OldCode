#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define MAXSTACK 100	/* maximum depth of val stack */
#define BUFSIZE 100

static char buf[BUFSIZE];	/* buffer for ungetch */
static int bufp = 0;		/* next free position in buf */
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
	if (c != EOF) {
		if (bufp >= BUFSIZE)
			printf("ungetch: too many characters\n");
		else 
			buf[bufp++] = c;
	}
	return NUMBER;
}

int getch(void)	/* get a (possibly pushed back) character */
{
	return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int halabalalabaloo)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = halabalalabaloo;
}
