#include <stdio.h>
#include <math.h>

// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );
}


int main(int argc, const char *argv[])
{
	int num_columns;
	int num_rows;
	int min_column_width;
	int min_init_column_width;
	int border_string_length;
	int a;
	int i;
	int k;
	// User input
	// fill symbols
	char fill_symbol_1;
	char fill_symbol_2;
	char space_string_1[2] = " ";
	char space_string_2[2] = " ";
	char border_string[ 10 ];
	printf( "Please enter the first fill symbol and press Enter: " );
	scanf ( "%c", &fill_symbol_1 );
	flush ();

	printf( "Please enter the second fill symbol and press Enter: " );
	scanf ( "%c", &fill_symbol_2 );
	flush ();

	// columns & rows
	printf( "Please enter the number of columns: " );
	scanf ( "%d", &num_columns );
	flush ();

	printf( "Please enter the number of rows: " );
	scanf ( "%d", &num_rows );
	flush ();


	// Any necessary pre-processing
	// Widths based on table entry with maximum number of digits
	min_column_width = floor(log10( num_columns * num_rows )) + 1;
	min_init_column_width = floor(log10( num_rows )) + 1;
		// getting an error that says floor and log10 unrecognized!
		// arg!!!
		// It's because I'm trying to call them on an int argument.
		// How do I turn those into doubles?
		// min_column_width = floor(log10( 10 * 100 )) + 1;
	// It turned out it had nothing to do with the casting. It works ok
	// if you add -lm to the end of the gcc command. Found on StackOverflow
	// but don't understand why it works.  :(

	// Initial definition of strings/lengths before extra spacing calcs
	border_string_length = min_column_width + 2;
	// Determine whether spacing should be reduced
	if ( ((1+min_init_column_width+1) +
				(1+1+min_column_width+1)*num_columns) > 80 ) {
		space_string_2[0] = '\0';
		border_string_length--;

		if ( ((1+min_init_column_width) +
				(1+1+min_column_width)*num_columns) > 80 ) {
			space_string_1[0] = '\0';
			border_string_length--;
			if ( ((min_init_column_width) +
					(1+min_column_width)*num_columns) > 80 ) {
				printf( "Note: It looks like your table might not fit properly on this screen.\n" );
				printf( "To fix, try creating a table with fewer columns.\n" );
				printf( "To continue, press Enter...\n" );
				flush();
			}
		}
	}

	// Declaration of header row's lower border string here
	for (a = 0; a < border_string_length; a++) {
		border_string[a] = fill_symbol_2;
	}
	border_string[ border_string_length ] = '\0';

	// End of pre-processing


	// Output
	// Header row
	printf( "%s%*c%s", space_string_1, min_init_column_width, ' ', space_string_2 );
	for (i = 1; i <= num_columns; i++) {
		printf( "%c%s%*d%s", fill_symbol_1, space_string_1, min_column_width, i, space_string_2 );
	}
	printf("\n");

	// Header lower border
	printf( "%s%*c%s", space_string_1, min_init_column_width, ' ', space_string_2 );
	for (i = 1; i <= num_columns; i++) {
		printf( "%c%s", '+', border_string );
	}
	printf("\n");

	// Body rows
	for (i = 1; i <= num_rows; i++) {
		printf( "%s%*d%s", space_string_1, min_init_column_width, i, space_string_2 );
		for (k = 1; k <= num_columns; k++) {
			printf( "%c%s%*d%s", fill_symbol_1, space_string_1, min_column_width, i * k, space_string_2 );
		}
		printf("\n");
	}

	return 0;
}
