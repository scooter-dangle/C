#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	int i = 24;
	int k = -28;
	int a = 0;
	printf("%i\n", (int) copysign(1,i));
	printf("%i\n", (int) copysign(1,k));
	printf("%i\n", (int) copysign(1,a));
	return 0;
}
