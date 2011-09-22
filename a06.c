#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_DIE 1 // LOWER_DIE must be at least 1
#define UPPER_DIE 10
#define TRIALS 100000


int genRand(int, int);
int getTwoDieSum(int, int);


int main(int argc, const char *argv[])
{
	int numberArray[2 * UPPER_DIE + 1]; // holds frequency of rolls

	// initialize numberArray
	for (int i = 0; i <= 2 * UPPER_DIE; i++) {
		numberArray[i] = 0;
	}

	// seed the random number generator
	srand((unsigned int)time(NULL));

	// roll the dice and keep track of what was rolled in the array
	int i;
	for (i = 0; i < TRIALS; i++) numberArray[getTwoDieSum( LOWER_DIE, UPPER_DIE )]++;

	// display results
	printf( "Roll Value | Frequency\n" );
	for (i = 2 * LOWER_DIE; i <= 2 * UPPER_DIE; i++) {
		printf( "%10d | %d\n", i, numberArray[i] );
	}

	return 0;
}


// Function Implementations
int genRand(int lower, int upper)
{
	int range = (upper - lower) + 1;
	return rand() % range + lower;
}

int getTwoDieSum(int lower, int upper)
{
	return genRand(lower,upper) + genRand(lower,upper);
}
