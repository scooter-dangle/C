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


	// Output
	// Header row
	int i;
	printf( " %*c", min_init_column_width, ' ' );
	for (i = 1; i <= num_columns; i++) {
		printf( " %c %*d", fill_symbol_1, min_column_width, i );
	}
	printf("\n");
	
	// Body rows
	int k;
	for (i = 0; i <= num_rows; i++) {
		/* code */
		for (k = 0; k <= num_columns; k++) {
			/* code */
		}
	}

	return 0;
}
