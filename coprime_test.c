#include <stdio.h>

#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

int CoprimeTest(int, int);

int main(int argc, const char *argv[])
{
	printf("%d\n", CoprimeTest( 10, 11 ));
	printf("%d\n", CoprimeTest( 11, 11 ));
	printf("%d\n", CoprimeTest( 15, 11 ));
	printf("%d\n", CoprimeTest( 15, 18 ));
	printf("%d\n", CoprimeTest( 30, 33 ));
	printf("%d\n", CoprimeTest( 40, 60 ));
	return 0;
}

int CoprimeTest(int numOne, int numTwo) {
	// got the following from en.literateprograms.org
	int em;
	while (numTwo != 0) {
		em = numOne % numTwo;
		numOne = numTwo;
		numTwo = em;
	}
	if (numOne == 1) return TRUE;
	return FALSE;
}
