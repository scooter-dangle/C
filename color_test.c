#include <stdio.h>

int main(int argc, const char *argv[])
{
	// Note: the following lines do not work on windows
	// On windows, one would have to #include <windows.h>
	// And then switch output colors with lines like this:
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
	//     background|FOREGROUND_INTENSITY|FOREGROUND_RED
	//     |FOREGROUND_GREEN|FOREGROUND_BLUE);
	// Where background was previously declared like this:
	// int background = 0x0000;
	printf("%c[1;31mHello, world!\n", 27 ); // red
	printf("%c[1;32mHello, world!\n", 27 ); // green
	printf("%c[1;33mHello, world!\n", 27 ); // yellow
	printf("%c[1;34mHello, world!\n", 27 ); // blue
	printf("%c[0mHello, world!\n", 27 ); // reset color
	return 0;
}
