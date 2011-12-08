#include <stdio.h>

//from stackoverflow:
#ifndef CLEAR_SCREEN
#ifdef WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif
#endif

// Prototypes
void flush();
void print_line();
void print_clear_screen();
void print_menu();
void print_exit();
void print_invalid_input();

// For testing purposes only:
// int main(int argc, const char *argv[])
// {
// 	print_menu();
// 	print_exit();
// 	print_invalid_input();
// 	print_clear_screen();
// 	return 0;
// }

// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );
}

void print_line()
{
	printf("\n");
}

void print_clear_screen()
{
	system(CLEAR_SCREEN);
}

void print_menu()
{
	printf("Please select an option...\n"                  );
	printf(" 1  Select input file name\n"                  );
	printf(" 2  Select output file name\n"                 );
	printf(" 3  Select affine cipher key\n"                );
	printf(" 4  Encrypt input file\n"                      );
	printf(" 5  Decrypt input file\n"                      );
	printf(" 6  Get directory listing\n"                   );
	printf(" 7  Exit\n"                                    );
	printf(":"                                             );
}

void print_exit()
{
	printf("Have such a good day!!!!!!!\n\n"               );
}

void print_invalid_input()
{
	printf("Your input was not recognized as a valid "     );
	printf("option.\n\n"                                   );
}
