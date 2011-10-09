#include <stdio.h>

void flush();

int main(int argc, const char *argv[])
{
	
	return 0;
}

// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	do {
		scanf("%c", &extraChar);
	} while ( extraChar != '\n' && extraChar != EOF );
}
