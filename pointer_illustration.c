#include <stdio.h>

#define SIZE 3

int main(int argc, const char *argv[])
{
	float	ex[SIZE];
	float	*fp;
	int	i;


	for (i = 0; i < SIZE; i++) {
		ex[i] = 0.5*(float)i;
	}

	for (i = 0; i < SIZE; i++) {
		printf("  %d  %f \n", i, ex[i]);
	}

	fp = ex;


	for (i = 0; i < SIZE; i++) {
		printf("  %d  %f \n", i, *(fp+i));
	}


	return 0;
}
