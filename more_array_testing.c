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
			printf("%c\n", *(*(k+i)+jay) );
		}
	}

	return 0;
}
