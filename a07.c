#include <stdio.h>

#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif


#define ROWS 7
#define COLS 7


#define MARKONE 'X'
#define MARKTWO 'O'
#define BLANK ' '


void InitializeBoard(char[ROWS][COLS]);
void DisplayBoard(char[ROWS][COLS]);
int PlayerMove(int, int, char[ROWS][COLS], char);


int main()
{
	// declare variables
	char board[ROWS][COLS];

	// initialize board
	InitializeBoard(board);

	// populate the board with moves
	PlayerMove( 1,  1, board, MARKONE );
	PlayerMove( 1,  2, board, MARKONE );
	PlayerMove( 4,  3, board, MARKONE );
	PlayerMove( 1,  1, board, MARKTWO );
	PlayerMove( 6,  2, board, MARKTWO );
	PlayerMove( 4, 12, board, MARKTWO );

	// display the board
	DisplayBoard(board);

	// exit program
	return 0;
}


// Function Implementations
void InitializeBoard(char board[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int k = 0; k < COLS; k++)
			board[i][k] = BLANK;
}

void DisplayBoard(char board[ROWS][COLS])
{
	// Your Implementation Goes Here
}

int PlayerMove(int row, int col, char board[ROWS][COLS], char symbol)
{
	// Check for move legality
	if ((row>0 && row<=ROWS) && (col>0 && col<=COLS)) {
		if (board[row-1][col-1] == BLANK) {
			board[row-1][col-1] = symbol;
			return TRUE;
		}
		else {
			printf( "That space is already occupied.\n", row, col );
			return FALSE;
		}
	}
	else {
		printf( "That move is not on the board.\n" );
		return FALSE;
	}
}

