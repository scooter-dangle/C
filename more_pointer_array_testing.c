#include <stdio.h>

int main(int argc, const char *argv[])
{
	int someIntArray[5] = {10, 20, 30, 40, 50};
	printf("The array contains: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", someIntArray[i]);
	}
	printf("\n");

	int* pSomeInteger;
	pSomeInteger = someIntArray;

	printf("The array contains: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", *pSomeInteger);
		pSomeInteger++;
	}
	printf("\n");

	int notherIntArray[4][2] = {
		{ 1, 2 },
		{ 3, 4 },
		{ 5, 6 },
		{ 7, 8 } };

	printf("The array contains: ");
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 2; k++) {
			printf("%d ", notherIntArray[i][k]);
		}
	}
	printf("\n");

	// There be errors here:
	int** notherInteger;
	notherInteger = notherIntArray;
	printf("The array contains: ");
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 2; k++) {
			printf("%d ", notherInteger[i][k]);
		}
	}
	printf("\n");


	return 0;
}
