//Write a function "lower" which converts all upper case characters in a string
//to lowercase using a conditional expression instead of if-else.
#include <stdio.h>
void lower();

char str[] = "NoThIng ThAt YoU iNpUt InTo HeRe WiLl Be CaPiTaLiZeD :L";

int main()
{
	lower();
	printf("%s\n", str);
}

//"Lower" converts all upper case chars in the global char[] "string" string to lower case chars.
void lower()
{
	for(int n = 0; str[n] != '\0'; ++n)
		str[n] += (str[n] <= 90 && str[n] >= 65)? 32 : 0;
}
