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

int ReadStringFromFile(char* path, char* string) {
	FILE *stream;
	int i;
	stream = fopen(path, "r");
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (((string[i] = getc(stream)) == EOF) || (string[i] == '\0')) {
			string[i] = '\0';
			fclose(stream);
			return TRUE;
		}
	}
	string[i-1] = '\0';
	fclose(stream);
	fprintf(stderr, "The input file size exceeded %i bytes, the maximum accepted\nfile size. Some of the input file may not be processed.", BUFFER_SIZE);
	return FALSE;
}

int WriteStringToFile(char* path, char* string) {
	FILE *stream;
	stream = fopen(path, "w");
	fprintf(stream, "%s\n", string);
	fclose(stream);
	return TRUE;
}

int CleanString(char* string) {
	int i, k;
	k = 0;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if (string[i] >= 97 && string[i] < 123) {
			string[k++] = string[i];
		} else if (string[i] >= 65 && string[i] < 91) {
			string[k++] = string[i] + ASCII_UPPER_LOWER_OFFSET;
		} else if (string[i] == '\0') {
			string[k] = '\0';
			return TRUE;
		}
	}
	fprintf(stderr, "CleanString scanned through %i bytes without finding a null character.\nThe input string should be terminated by a null character", BUFFER_SIZE);
	return FALSE;
}

