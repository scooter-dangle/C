#include <stdio.h>
#include <limits.h>

#if CHAR_MAX != SCHAR_MAX
// Plain "char" is unsigned
int main(int argc, const char *argv[])
{
	printf( "Plain \"char\" is unsigned.\n" );
	return 0;
}
#else
// Plain "char" is signed
int main(int argc, const char *argv[])
{
	printf( "Plain \"char\" is signed.\n" );
	return 0;
}
#endif
