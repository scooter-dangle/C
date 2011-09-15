#include <stdio.h>

int main(int argc, const char *argv[])
{
	float ex, wy;
	float *fp, *fp2;

	ex = 6.5;

	printf("Value of ex is %f, address of ex %ld\n", ex, &ex);

	fp = &ex;

	printf("Value in memory location fp is %for\n", *fp);

	*fp = 9.2;
	printf("New value of ex is %f = %f \n", *fp, ex);

	*fp = *fp + 1.5;
	printf("Final value of ex is %f = %f \n", *fp, ex);

	wy = *fp;
	fp2 = fp;
	printf("Transferred value into wy = %f and fp2 = %f \n", wy, *fp2);
	return 0;
}
