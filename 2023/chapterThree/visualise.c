//Create two functions, one that converts all newline and tab chars into visable '\n' and '\t's
//and another that reverses this effect.
#include <stdio.h>
void visualise();
void encode();

char string1[] = "hello\tworld\nThsi is a new line\t and this is a tab space";
char string2[] = "Hello\\tworld\\nThsi is a new line\\t and this is a tab space";
char output1[55 + 3 + 1];
char output2[55 + 1];

int main()
{
	visualise();
	encode();
	printf("Output1:\t%s\nOutput2:\t%s\n", output1, output2);
}

//Converts all newline and tab chars in a string to "\n" and "\t"
void visualise()
{
	int out_count = 0;	//Keeping track of which output char we are on

	for(int n = 0; string1[n] != '\0'; n++) {
		switch (string1[n]){
			case '\t': output1[out_count++] = '\\';
				   output1[out_count++] = 't';
				   break;

			case '\n': output1[out_count++] = '\\';
				   output1[out_count++] = 'n';
				   break;

			default:   output1[out_count++] = string1[n];
		}
	}
	output1[out_count] = '\0';
}

//Converts all instances of "\\n" in string2 to "\n" and "\\t" to "\t"
void encode()
{
	int out_count = 0;	//Keeping track of which output char we are on

	for(int n = 0; string2[n] != '\0'; n++) {
		if(string2[n] == '\\' && string2[n+1] == 'n'){
			output2[out_count++] = '\n';
			n++;
		} else if (string2[n] == '\\' && string2[n+1] == 't'){
			output2[out_count++] = '\t';
			n++;
		} else
			/* printf("hi"); */
			output2[out_count++] = string2[n];
	}
	output2[out_count] = '\0';

}
