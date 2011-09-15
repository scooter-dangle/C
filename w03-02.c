#include <stdio.h>

int main()
{
	char keystroke1 = ' ';
	char keystroke2 = ' ';
	char keystroke3 = ' ';
	printf( "Please enter a single character: " );
	scanf ( "%c", &keystroke1 );
	printf( "You pressed .................: %c\n", keystroke1 );
	printf( "The ASCII code for that is ..: %d\n", keystroke1 );
	printf( "Please enter a single character: " );
	scanf ( "%c", &keystroke2 );
	printf( "You pressed .................: %c\n", keystroke2 );
	printf( "The ASCII code for that is ..: %d\n", keystroke2 );
	printf( "Please enter a single character: " );
	scanf ( "%c", &keystroke3 );
	printf( "You pressed .................: %c\n", keystroke3 );
	printf( "The ASCII code for that is ..: %d\n", keystroke3 );
	return 0;
}
