#include <stdio.h>


#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

#define ROWS 7
#define COLS 7
#if ROWS < COLS
#define MIN ROWS
#endif
#if ROWS >= COLS
#define MIN COLS
#endif

#define TESTING 0

#define MARKONE 'X'
#define MARKTWO 'O'
#define BLANK ' '

#if TESTING
#define BLANK 'B'
#endif

// Victory Codes
#define NOWIN 0
#define MARKONEVICTORY 1
#define MARKTWOVICTORY 2
#define TIE 3
#define ERROR 4
#define EPIC_FAIL 5

// Game Parameter Codes
#define CONSECUTIVE_MARKS_REQUIRED 3


#include "a08.h"


int main()
{
	char board[ROWS][COLS];


	InitializeBoard(board);
	PlayerMove(1, 1, board, MARKONE);
	PlayerMove(1, 2, board, MARKONE);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	return 0;
}

