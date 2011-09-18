#include <stdio.h>

#define ROWS 2
#define COLS 2

void DisplayBoard(char* [ROWS][COLS]);


int main(int argc, const char *argv[])
{
	char initialArray[ROWS][COLS] = { {'a', 'b'}, {'c', 'd'} };
	char* pointerArray[ROWS][COLS];
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			pointerArray[row][col] = &initialArray[row][col];
		}
	}
	DisplayBoard( pointerArray );

//	int min;
//	ROWS < COLS ? (min = ROWS) : (min = COLS);
//	char* diagonalArray1[ROWS + COLS - 1][min];
//	char* diagonalArray2[ROWS + COLS - 1][min];
//
//	diagonalArray1[0][0] = &initialArray[0][0];
//	printf( "%c\n", *diagonalArray1[0][0] );
//	printf( "%c\n", *diagonalArray1[0][1] );
//	DisplayBoard( *diagonalArray1 );

	return 0;
}


void DisplayBoard(char* board[ROWS][COLS])
{
	void majorRow(char* board[ROWS][COLS], int row) {
		for (int col = 1; col <= COLS; col++) {
			printf("%c ", *board[row-1][col-1]);
		}
		printf("\n");
	}


	for (int row = 1; row <= ROWS; row++) {
		majorRow( board, row );
	}
}
