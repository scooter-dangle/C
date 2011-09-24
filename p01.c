#include <stdio.h>


// Prototypes
void flush();


int main(int argc, const char *argv[])
{
	// Variable declarations (damn you, MSVS! damn you and your non-c99-ness!)
	// Getting all the inputs
	printf( "Instructions\nPlease enter your grade (in points) after each "   );
	printf( "prompt and press the enter key.\n\n"                             );
	int prog_assign_1;	// qjq
	printf( "Programming Assignment No. 1 (200 point maximum): "              );
	scanf ( "%i", &prog_assign_1 );
	flush ();

	int prog_assign_2;	// qjq
	printf( "Programming Assignment No. 2 (200 point maximum): "              );
	scanf ( "%i", &prog_assign_2 );
	flush ();

	int prog_assign_3;	// qjq
	printf( "Programming Assignment No. 3 (200 point maximum): "              );
	scanf ( "%i", &prog_assign_3 );
	flush ();

	int mid_term;	// qjq
	printf( "               Mid-term exam (150 point maximum): "              );
	scanf ( "%i", &mid_term );
	flush ();

	int attendance_and_participation;	// qjq
	printf( "    Attendance/Participation (100 point maximum): "              );
	scanf ( "%i", &attendance_and_participation );
	flush ();

	printf( "\n" );

	// Calcurlashins
	int sub_total;	// qjq
	sub_total = prog_assign_1 + prog_assign_2 + prog_assign_3 + mid_term + attendance_and_participation;
	// Output
	printf( "                             Total Points So Far: %i", sub_total );
	printf( "\n" );
	return 0;
}


void flush()
{
	char extraChar;
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );
}

void getGrade(int grade, int max_grade, char* assignment, int max_grade_width, int assignment_width) // work in progress for grade input section
{
	printf( "%*s (150 point maximum): ", assignment_width, assignment         );
	scanf ( "%i", &grade );
	flush ();
}
