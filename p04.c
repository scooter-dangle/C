#include <stdlib.h>
#include <stdio.h>
#include "p04_preprocessor.h"
#include "a10.h"
#include "a11.h"



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
