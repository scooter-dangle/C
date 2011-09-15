#include <stdio.h>

int main()
{
	// declare and initialize variables
	char name[30];
	char dogName[30];
	int age;
	long favNum;
	double favDec;
	printf( "Please enter a man's name: " );
	scanf ( "%s", name );
	printf( "Please enter a male dog's name: " );
	scanf ( "%s", dogName );
	printf( "Please enter the man's age: " );
	scanf ( "%d", &age );
	printf( "Please enter the man's favorite number: " );
	scanf ( "%ld", &favNum );
	printf( "Please enter the man's favorite decimal: " );
	scanf ( "%lf", &favDec );
	//display story
	printf( "Hello, my name is %s.\n\n", name                                 );
	printf( "As I'm sure you already know, my best friend\n"                  );
	printf( "is a dog\n\n"                                                    );
	printf( "His name is \"%s\"... can you say \"%s\"?\n\n", dogName, dogName );
	printf( "I know it's quite pathetic for a man of %d\n", age               );
	printf( "years to have a dog as a best friend, but I\n"                   );
	printf( "can't really help it. You see, I have terrible\n"                );
	printf( "hygiene and don't really have much luck with the\n"              );
	printf( "ladies. It probably doesn't help that I insist\n"                );
	printf( "on \"impressing\" them with my god-given talent to\n"            );
	printf( "convert base-10 numbers to octal and hexadecimal.\n\n"           );
	printf( "For instance, my favorite number, %ld, is %lo\n", favNum, favNum );
	printf( "in octal. If I took that same number and converted it to\n"      );
	printf( "hexadecimal, it would be %lx.\n\n", favNum                       );
	printf( "My favorite decimal is %g, but I can't seem to convert\n", favDec);
	printf( "that one into octal or hexadecimal.\n"                           );
	printf( "I'm pretty sure you can do it, but I'm not 100%% sure.\n"        );
	return 0;
}
