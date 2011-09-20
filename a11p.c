#include <stdio.h>
#include <string.h>


#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

#define BUFFER_SIZE 10000
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define ASCII_UPPER_LOWER_OFFSET 32


int ReadStringFromFile(char*, char*);
int WriteStringToFile(char*, char*);
int CleanString(char*);


int main(int argc, const char *argv[])
{
	char buffer[BUFFER_SIZE] = "";

	ReadStringFromFile(INPUT_FILE, buffer);
	CleanString(buffer);
	WriteStringToFile(OUTPUT_FILE, buffer);

	return 0;
}
