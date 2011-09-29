#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("%c[1;31mHello, world!\n", 27 ); // red
	printf("%c[1;32mHello, world!\n", 27 ); // green
	printf("%c[1;33mHello, world!\n", 27 ); // yellow
	printf("%c[1;34mHello, world!\n", 27 ); // blue
	printf("%c[0mHello, world!\n", 27 ); // reset color
	return 0;
}
