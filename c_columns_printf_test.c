#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf( "%*c\n", 80, 'i' );
	printf( "%*c\n", 80, 'i' );
	printf( "---\n" );
	printf( "%*c\n", 81, 'i' );
	printf( "%*c\n", 81, 'i' );
	printf( "---\n" );
	printf( "%*c\n", 79, 'i' );
	printf( "%*c\n", 79, 'i' );
	printf( "---\n" );
	return 0;
}
