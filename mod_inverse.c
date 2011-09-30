#include <stdio.h>

int ModInverse(int, int);


int main(int argc, const char *argv[])
{
	int eigh, bee;
	scanf ("%d", &eigh);
	scanf ("%d", &bee);
	printf("%d ", ModInverse(eigh, bee));
	return 0;
}


int ModInverse(int target, int mod)
{
	int i;
	for (i = 1; i < mod; i++) {
		if (i * target % mod == 1) {
			target = i;
			i = mod;
		}
	}
	return target;
}
