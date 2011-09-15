#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	printf( "%.0f\n", floor(log10(3)) );
	printf( "%.0f\n", floor(log10(10)) );
	printf( "%.0f\n", floor(log10(11)) );
	printf( "%.0f\n", floor(log10(51)) );
	return 0;
}
