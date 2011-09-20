#include <stdio.h>

char* flat_char_matrix(char[],int,int,int,int);
void flatten_char_matrix(char[3][2],char[],int,int);
void fill_char_matrix(char[],char[3][2],int,int);

int main(int argc, const char *argv[])
{
	char array_1[][2] = {{'a','b'},{'c','d'},{'e','f'}};
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			printf("%c ", array_1[i][k]);
		}
	}
	printf("\n");

	char array_2[3*2];
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			*flat_char_matrix(array_2, 3, 2, i, k) = array_1[i][k];
		}
	}

	array_1[0][0] = 'o';

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			printf("%c ", *flat_char_matrix(array_2, 3, 2, i, k));
		}
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			printf("%c ", array_1[i][k]);
		}
	}
	printf("\n");

	char array_3[3*2];
	flatten_char_matrix(array_1, array_3, 3, 2);

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			printf("%c ", *flat_char_matrix(array_3, 3, 2, i, k));
		}
	}
	printf("\n");

	*flat_char_matrix(array_3, 3, 2, 0, 1) = 'j';

	fill_char_matrix(array_3, array_1, 3, 2);

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			printf("%c ", array_1[i][k]);
		}
	}
	printf("\n");

	return 0;
}

char* flat_char_matrix(char array[], int Rows, int Cols, int row, int col)
{
	return &array[ row*Cols + col ];
}

void flatten_char_matrix(char matrix[3][2], char array[], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++) {
		for (int k = 0; k < Cols; k++) {
			*flat_char_matrix(array, Rows, Cols, i, k) = matrix[i][k];
		}
	}
}

void fill_char_matrix(char array[], char matrix[3][2], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++) {
		for (int k = 0; k < Cols; k++) {
			matrix[i][k] = *flat_char_matrix(array, Rows, Cols, i, k);
		}
	}
}
