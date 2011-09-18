#include <stdio.h>

#define ROWS 2
#define COLS 2

void DisplayBoard(char[ROWS][COLS]);


int main(int argc, const char *argv[])
{
	char initialArray[ROWS][COLS] = { {'a', 'b'}, {'c', 'd'} };
	DisplayBoard( initialArray );

	return 0;
}


void DisplayBoard(char board[ROWS][COLS])
{
	void majorRow(char board[ROWS][COLS], int row) {
		for (int col = 1; col <= COLS; col++) {
			printf("%c ", board[row-1][col-1]);
		}
		printf("\n");
	}


	for (int row = 1; row <= ROWS; row++) {
		majorRow( board, row );
	}
}
