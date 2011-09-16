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
	double min_column_width;
	double dub_columns;
	double dub_rows;
	dub_columns = (double)num_columns;
	dub_rows = (double)num_rows;
	min_column_width = floor(log10( dub_columns * dub_rows ));
	// getting an error that says floor and log10 unrecognized!
	// arg!!!
	// It's because I'm trying to call them on an int argument.
	// How do I turn those into doubles?
	// min_column_width = floor(log10( 10 * 100 )) + 1;
	printf( "%.0f", min_column_width );


	// Output
	// Header row
	int i;
	for (i = 0; i <= num_columns; i++) {
		/* code */
	}
	
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
