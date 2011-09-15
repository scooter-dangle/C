#include <stdio.h>

int main()
{
	char k;
	printf( "My name is %s, and I am %d years old.\n", "Scott", 25 );
	printf( "Press Enter to continue\n" );
	scanf( "%c", &k ); // Not sure why the program doesn't get upset when
					   // input is longer than one character. I know it
					   // drops any characters after the first one in the
					   // input buffer, but that seems way too user-friendly
					   // for c.
					   // Also, I have no clue why I have to assign to &k
					   // rather than just plain k.
	return 0;
}
