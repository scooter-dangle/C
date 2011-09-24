#include <stdio.h>


void flush();


int main(int argc, const char *argv[])
{
	// Getting all the inputs
	int grade_1;
	printf("Enter first grade: ");
	scanf("%i", &grade_1);
	flush();
	printf("\n");

	int grade_2;	// qjq
	printf("Enter second grade: ");
	scanf("%i", &grade_2);
	flush();
	printf("\n");

	// Calcurlashins
	// Output
	return 0;
}


void flush()
{
	char extraChar;
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );
}
