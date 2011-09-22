#include <stdio.h>

int main(int argc, const char *argv[])
{
	for (int i = -50; i < 50; i++) {
		int k = i % 26;
		printf("%i ", k );
	}
	return 0;
}
