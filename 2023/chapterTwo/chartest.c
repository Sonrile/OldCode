#include <stdio.h>

int main(){
	for(char c = 0; c < 0b1111111; c++)
		printf("Int: %d  \tChar: %c\n", c, c);
}
