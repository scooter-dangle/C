#include <stdio.h>

//from stackoverflow:
#ifdef WIN32
#define LIST_CURR_DIR_CONTENTS "dir /p"
#else
#define LIST_CURR_DIR_CONTENTS "ls -a | less"
#endif

// Prototypes
void flush();
void print_menu();


// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );
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
