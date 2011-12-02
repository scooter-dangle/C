#include <stdlib.h>
#include <stdio.h>
#include "p04_preprocessor.h"
#include "a10.h"
#include "a11.h"


	//from stackoverflow:
#ifdef WIN32
#define LIST_CURR_DIR_CONTENTS "dir /p"
#else
#define LIST_CURR_DIR_CONTENTS "ls -a | less"
#endif


void flush();


int main()
{
	
	return 0;
}


// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	while ( (extraChar = getchar()) != '\n' && extraChar != EOF );
}
