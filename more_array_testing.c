#include <stdio.h>

int main(int argc, const char *argv[])
{
	char a[5] = { 'a', 'b', 'c', 'd', 'e' };

	for (int i = 0; i < 5; i++) {
		printf("%c", *( a + i ));
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%c", a[i]);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%c", i[a]);
	}
	printf("\n");

	char k[5][2] = { 
		{ 'a', 'b' },
		{ 'c', 'd' },
		{ 'e', 'f' },
		{ 'g', 'h' },
		{ 'i', 'j' } };

	for (int i = 0; i < 5; i++) {
		for (int jay = 0; jay < 2; jay++) {
			printf( "%c ", *(jay + *(k+i)) );
		}
	}
	printf("\n");
	printf("%i\n", sizeof(     k    ));  // 10
	printf("%i\n", sizeof(   *(k+1) ));  //  2
	printf("%i\n", sizeof(    *k    ));  //  2
	printf("%i\n", sizeof( &*&*k    ));  //  4
	printf("%i\n", sizeof(  *&*k    ));  //  2
	printf("%i\n", sizeof(   **k    ));  //  1

	int i = 3;
	int jay = 5;
	char ell[i][jay];
	printf("%i\n", sizeof(     ell  ));  // 15
	// Apparently the above is illegal in Microsoft Visual C.
	// kinda totally lame, right?
	// C99 (I think) is what allows for variable-sized arrays, but
	// Microsoft hasn't felt like implementing it.
	// It works just fine in gcc (with -std=c99).
	// Maybe it's just that Microsoft doesn't allow for variable-sized
	// multi-dimensional arrays? Not sure.

	return 0;
}
