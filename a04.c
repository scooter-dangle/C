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
	char extraChar;
	int typeCode = -1, subTypeCode = -1;

	// Get the keystroke
	printf( "Please to enter a character for analysis so fast:\n" );
	scanf ( "%c", &keyStroke );
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );

	// Analyze the keystroke (if, if-else, if-else-chain here)
	if ( (keyStroke >= 128) || (keyStroke<0) ) subTypeCode = UPPER_ASCII;


	if ( keyStroke >= 48 && keyStroke < 58 ) {
		typeCode = NUMBER;
		if ( keyStroke % 2 == 0 ) {
			subTypeCode = EVEN;
		}
		else {
			subTypeCode = ODD;
		}
	}

	if ( (keyStroke>=65 && keyStroke<91) || (keyStroke>=97 && keyStroke<123) ) {
		typeCode = LETTER;
		if (
				keyStroke == 65 ||
				keyStroke == 69 ||
				keyStroke == 73 ||
				keyStroke == 79 ||
				keyStroke == 85
				) {
			subTypeCode = VOWEL;
		}
		else {
			if (
					keyStroke ==  97 ||
					keyStroke == 101 ||
					keyStroke == 105 ||
					keyStroke == 111 ||
					keyStroke == 117
					) {
				subTypeCode = VOWEL;
			}
			else {
				subTypeCode = CONSONANT;
			}
		}
	}

	if ( subTypeCode == -1 && keyStroke < 128 && keyStroke >= 0 ) {
		typeCode = SYMBOL;
		subTypeCode = LOWER_ASCII;
	}
	// lowercase letters are at 97--122
	// uppercase letters are at 65--90
	// lowercase vowels are at 97, 101, 105, 111, 117
	// uppercase vowels are at 65, 69, 73, 79, 85
	// numbers are at 48--57 and begin with 0

	// Display results based on set codes (switch-case)
	switch( subTypeCode ) {
		case VOWEL:
			printf( "Hey! You typed an unaccented vowel! w00t!\n" );
			break;
		case CONSONANT:
			printf( "K it was a consonant... just a latin one, though...\n" );
			break;
		case ODD:
			printf( "It's an odd number, k?\n" );
			break;
		case EVEN:
			printf( "Nnnkay you typed an even number.\n" );
			break;
		case UPPER_ASCII:
			printf( "Maybe a forn' character? Somewhere in the upper Ascii's?\n" );
			break;
		case LOWER_ASCII:
			printf( "Kinda boring character from the lower ascii set.\n" );
			break;
		default:
			printf( "Couldn't quite figger it... Sorries  :(\n" );
			break;
	}

	return 0;
}
