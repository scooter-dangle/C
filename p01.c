#include <stdio.h>


// Prototypes
void flush();


int main(int argc, const char *argv[])
{
	// Variable declarations (damn you, MSVS! damn you and your non-c99-ness!)
	int prog_assign_1;	// qjq
	int prog_assign_2;	// qjq
	int prog_assign_3;	// qjq
	int mid_term;	// qjq
	int attendance_and_participation;	// qjq
	int sub_total;	// qjq
	int final_exam;	// qjq
	int aPts, bPts, cPts, dPts;		// qjq
	float aPercent, bPercent, cPercent, dPercent;		// qjq
	int min_a, min_b, min_c, min_d;		// qjq
	int guidance_code_max, guidance_code_min;	// qjq
	// Getting all the inputs
	printf( "CIS 111 Grade Calculator\n"                                      );
	printf( "========================\n\n"                                    );
	printf( "Instructions\nPlease enter your grade (in points) after each "   );
	printf( "prompt and press the enter key.\n\n"                             );

	printf( "Programming Assignment No. 1 (200 point maximum): "              );
	scanf ( "%i", &prog_assign_1 );
	flush ();

	printf( "Programming Assignment No. 2 (200 point maximum): "              );
	scanf ( "%i", &prog_assign_2 );
	flush ();

	printf( "Programming Assignment No. 3 (200 point maximum): "              );
	scanf ( "%i", &prog_assign_3 );
	flush ();

	printf( "               Mid-term exam (150 point maximum): "              );
	scanf ( "%i", &mid_term );
	flush ();

	printf( "    Attendance/Participation (100 point maximum): "              );
	scanf ( "%i", &attendance_and_participation );
	flush ();

	printf( "\n" );

	// Calcurlashins
	sub_total = prog_assign_1 + prog_assign_2 + prog_assign_3 + mid_term + attendance_and_participation;

	final_exam = 150;

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

	guidance_code_max = -1;
	guidance_code_min = -1;
	if (aPts <= 0) {
		guidance_code_max = 0;
		guidance_code_min = 0;
	}
	else {
	if (aPts <  final_exam) guidance_code_max = 1;
	else {
	if (aPts == final_exam) guidance_code_max = 2;
	else {
	if (bPts <  final_exam) guidance_code_max = 3;
	else {
	if (bPts == final_exam) guidance_code_max = 4;
	else {
	if (cPts <  final_exam) guidance_code_max = 5;
	else {
	if (cPts == final_exam) guidance_code_max = 6;
	else {
	if (dPts <  final_exam) guidance_code_max = 7;
	else {
	if (dPts == final_exam) guidance_code_max = 8;
	else {
		guidance_code_max = 9;
	}}}}}}}}}

	// Output
	printf( "                             Total Points So Far: %i", sub_total );
	printf( "\n\n\n" );

	printf("DETAILED OUTPUT\n"                                                );
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

	printf( "\n\n" );

	printf("GUIDANCE\n\n"                                                     );

	switch(guidance_code_max) {
		case 0:
			printf("Dude, you can get an A without taking the test! (Don't "  );
			printf("tell Mark I told you, k?)\n"                             );
			break;
		default:
			break;
	}

	switch(guidance_code_min) {
		case 0:
			break;
		default:
			if (guidance_code_max = -1) printf("No guidance available, please contact the lazy programmer who wrote this to\nclaim your refund.\n");
			break;
	}

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
