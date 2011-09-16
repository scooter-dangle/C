#include <stdio.h>
#include <math.h>

void flush()
{
	char extraChar;
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );
}

int main(int argc, const char *argv[])
{
	// User input
	// fill symbols
	char fill_symbol_1;
	printf( "Please enter the first fill symbol and press Enter: " );
	scanf ( "%c", &fill_symbol_1 );
	flush ();

	char fill_symbol_2;
	printf( "Please enter the second fill symbol and press Enter: " );
	scanf ( "%c", &fill_symbol_2 );
	flush ();

	// columns & rows
	int num_columns;
	printf( "Please enter the number of columns: " );
	scanf ( "%d", &num_columns );
	flush ();

	int num_rows;
	printf( "Please enter the number of rows: " );
	scanf ( "%d", &num_rows );
	flush ();


	// Any necessary pre-processing
	// Formatting based on table entry with maximum number of digits
	int min_column_width;
	min_column_width = floor(log10( num_columns * num_rows )) + 1;
	int min_init_column_width;
	min_init_column_width = floor(log10( num_rows )) + 1;
		// getting an error that says floor and log10 unrecognized!
		// arg!!!
		// It's because I'm trying to call them on an int argument.
		// How do I turn those into doubles?
		// min_column_width = floor(log10( 10 * 100 )) + 1;
	// It turned out it had nothing to do with the casting. It works ok
	// if you add -lm to the end of the gcc command. Found on StackOverflow
	// but don't understand why it works.  :(

	// Conditional-based modification of strings to keep table within 80 cols
	char space_string_1[2] = " ";
	char space_string_2[2] = " ";
	// Need declaration of header row's lower border string here

	// Need code here to determine whether spacing should be reduced

	// Output
	// Header row
	int i;
	printf( "%s%*c", space_string_1, min_init_column_width, ' ' );
	for (i = 1; i <= num_columns; i++) {
		printf( "%s%c%s%*d", space_string_2, fill_symbol_1, space_string_1, min_column_width, i );
	}
	printf("\n");

	// Header lower border
	printf( "%s%*c", space_string_1, min_init_column_width, ' ' );
	for (i = 1; i <= num_columns; i++) {
		printf( " %c %*c", '+', min_column_width, fill_symbol_2 );
		// Still need to mess with the previous line
	}
	printf("\n");

	// Body rows
	int k;
	for (i = 1; i <= num_rows; i++) {
		printf( "%s%*d", space_string_1, min_init_column_width, i );
		for (k = 1; k <= num_columns; k++) {
			printf( "%s%c%s%*d%s", space_string_2, fill_symbol_1, space_string_1, min_column_width, i * k, "" );
		}
		printf("\n");
	}

	return 0;
}
