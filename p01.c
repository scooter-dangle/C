#include <stdio.h>


// Prototypes
void flush();


int main(int argc, const char *argv[])
{
	// Variable declarations (damn you, MSVS! damn you and your non-c99-ness!)
	// Getting all the inputs
	printf( "CIS 111 Grade Calculator\n"                                      );
	printf( "========================\n"                                      );
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

	int final_exam;	// qjq
	final_exam = 150;

	int aPts, bPts, cPts, dPts;		// qjq
	float aPercent, bPercent, cPercent, dPercent;		// qjq

	int min_a, min_b, min_c, min_d;		// qjq

	min_a = 900;
	min_b = 800;
	min_c = 700;
	min_d = 600;

	aPts = min_a - sub_total;
	bPts = min_b - sub_total;
	cPts = min_c - sub_total;
	dPts = min_d - sub_total;

	aPercent = 100 * aPts / (float) final_exam;
	bPercent = 100 * bPts / (float) final_exam;
	cPercent = 100 * cPts / (float) final_exam;
	dPercent = 100 * dPts / (float) final_exam;

	// Output
	printf( "                             Total Points So Far: %i", sub_total );
	printf( "\n\n\n" );

	printf("Minimum final exam scores needed to earn each course grade\n"     );
	printf("----------------------------------------------------------\n"     );
	printf(" Course Grade   :   Points Needed   :   Percentage Needed\n"      );
	printf("            A   :   %5i           :   %7.2f %%\n", aPts, aPercent );
	printf("            B   :   %5i           :   %7.2f %%\n", bPts, bPercent );
	printf("            C   :   %5i           :   %7.2f %%\n", cPts, cPercent );
	printf("            D   :   %5i           :   %7.2f %%\n", dPts, dPercent );
	printf( "\n\n" );

	printf("Any score below %i points (%.2f%%) on the final",   dPts, dPercent);
	printf(" exam will result in a\nfailing grade for the course.\n\n"        );
	printf("NOTE: The Final Exam is worth %i points.\n", final_exam           );

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
