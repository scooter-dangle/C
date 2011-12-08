// #define NO_INVERSE -1
// #define ERROR -2

#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

#ifndef INPUT_FILE
#define INPUT_FILE "input.txt"
#endif

#ifndef OUTPUT_FILE
#define OUTPUT_FILE "output.txt"
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000
#endif

#ifndef NUM_RUNS
#define NUM_RUNS 3
#endif

//from stackoverflow:
#ifndef LIST_CURR_DIR_CONTENTS
#ifdef WIN32
#define LIST_CURR_DIR_CONTENTS "dir /p"
#else
#define LIST_CURR_DIR_CONTENTS "ls -a | less"
#endif
#endif
