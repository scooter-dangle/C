#include <stdio.h>

int increment(int*, int);

int main(int argc, const char *argv[])
{
	int k;
	k = 3;
	increment(&k, 4);
	printf("%i", k);
	return 0;
}

int increment(int* first, int second)
{
	*first+=second;
}
