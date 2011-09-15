#include <stdio.h>

#ifndef __CHARCODES__
#define __CHARCODES__
// type codes
#define LETTER 1
#define NUMBER 2
#define SYMBOL 3
// sub-type codes
#define VOWEL 4
#define CONSONANT 5
#define ODD 6
#define EVEN 7
#define UPPER_ASCII 8
#define LOWER_ASCII 9
#endif

int main()
{
	char keyStroke = 0;
	int typeCode = -1, subTypeCode = -1;

	// Get the keystroke

	// Analyze the keystroke (if, if-else, if-else-chain here)
	// lowercase letters are at 97--122
	// uppercase letters are at 65--90
	// lowercase vowels are at 97, 101, 105, 111, 117
	// uppercase vowels are at 65, 69, 73, 79, 85
	// numbers are at 48--57 and begin with 0

	// Display results based on set codes (switch-case)

	return 0;
}
