
#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif


#define NO_INVERSE -1
#define ERROR -2

#define A 19
#define B 4
#define ALPHABET_SIZE 26

#define ASCII_OFFSET 97

#define BUFFER_SIZE 10000
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define ASCII_UPPER_LOWER_OFFSET 32

	//from stackoverflow:
#ifdef WIN32
#define LIST_CURR_DIR_CONTENTS "dir /p"
#else
#define LIST_CURR_DIR_CONTENTS "ls -a | less"
#endif
