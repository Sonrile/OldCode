#define NUMBER '0'	/* signal that a number was found */

// File "../calc_tools.c"
int getop(char []);
void push(double);
double pop(void);

// File "../getch.c"
int getch(void);	/* get a (possibly pushed back) character */
void ungetch(int halabalalabaloo);	/* push character back on input */
