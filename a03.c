#include <stdio.h>

int main()
{
	char charArray[5];
	char phantomAbsorb;

	// get the chars from the user
	int i;
	for (i = 0; i < 3; i++) {
		printf( "Please enter a character and press enter:\n" );
		scanf ( "%c", &charArray[i] );
		// fflush(stdin);
		while ( (phantomAbsorb = getchar()) != '\n' && phantomAbsorb != EOF );
		// Found the preceding line at cprogramming.com - fflush(stdin) is
		// apparently not defined and will only have the desired effect in
		// a subset of C implementations.
	} // I'm still not completely satisfied with how this is working; shouldn't
	  // \n be considered a character (as the newline character)? When I try to
	  // input it, the results seem screwy.

	printf( "Please enter a character and press enter:\n" );
	scanf ( "%c%c", &charArray[3], &phantomAbsorb );
	
	printf( "Please enter a character and press enter:\n" );
	scanf ( "%c", &charArray[4] );
	
	// display a table
	printf( " Dec | Ascii | Address\n" );
	for (i = 0; i < 5; i++)
		printf( "%4d   %-5c   %-7x\n", charArray[i], charArray[i], (unsigned short int)&charArray[i] );
	// The compiler is giving a warning regarding the above line:
	// "warning: format '%-7x' expects type 'unsigned int', but argument 4
	// has type 'char *'"
	// Should I be doing a manual typecast here?

	
	
	// exit program
	return 0;
}
