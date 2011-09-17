#include <stdio.h>

int main(int argc, const char *argv[])
{
	char rope[3] = "dd";
	printf( "%s\n", rope );
	rope[1] = '\0';
	printf( "%s\n", rope );
	rope[0] = '\0';
	printf( "%s\n", rope );
	return 0;
}

// Output:
// 	dd
// 	d
// 	
