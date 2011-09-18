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


// Victory Codes
#define NOWIN 0
#define MARKONEVICTORY 1
#define MARKTWOVICTORY 2
#define TIE 3
#define ERROR 4
#define EPIC_FAIL 5

// Game Parameter Codes
#define CONSECUTIVE_MARKS_REQUIRED 3

// Prototypes
void InitializeBoard(char[ROWS][COLS]);
void DisplayBoard(char[ROWS][COLS]);
int PlayerMove(int, int, char[ROWS][COLS], char);
int VictoryCheck(int, char[ROWS][COLS]);
void DisplayVictoryMessage(int);



int main()
{
	// declare variables
	char board[ROWS][COLS];

	// Produce a NoWin condition
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKONE);
	PlayerMove(1, 2, board, MARKONE);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	// Produce a horizontal victory
	// initialize board
//	InitializeBoard(board);
//	// populate board
//	PlayerMove(1, 1, board, MARKONE);
//	PlayerMove(1, 2, board, MARKONE);
//	PlayerMove(1, 3, board, MARKONE);
//	// display the board
//	DisplayBoard(board);
//	// display victory message
//	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );
//
//	// Produce a vertical victory
//	// initialize board
//	InitializeBoard(board);
//	// populate board
//	PlayerMove(1, 1, board, MARKTWO);
//	PlayerMove(2, 1, board, MARKTWO);
//	PlayerMove(3, 1, board, MARKTWO);
//	// display the board
//	DisplayBoard(board);
//	// display victory message
//	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );
//
//	// Produce a diagonal-down victory
//	// initialize board
//	InitializeBoard(board);
//	// populate board
//	PlayerMove(1, 1, board, MARKONE);
//	PlayerMove(2, 2, board, MARKONE);
//	PlayerMove(3, 3, board, MARKONE);
//	// display the board
//	DisplayBoard(board);
//	// display victory message
//	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );
//
//	// Produce a diagonal-up victory
//	// initialize board
//	InitializeBoard(board);
//	// populate board
//	PlayerMove(3, 1, board, MARKTWO);
//	PlayerMove(2, 2, board, MARKTWO);
//	PlayerMove(1, 3, board, MARKTWO);
//	// display the board
//	DisplayBoard(board);
//	// display victory message
//	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );
//
//	// Produce a multiple player victory
//	// initialize board
//	InitializeBoard(board);
//	// populate board
//	PlayerMove(4, 1, board, MARKONE);
//	PlayerMove(4, 2, board, MARKONE);
//	PlayerMove(4, 3, board, MARKONE);
//
//	PlayerMove(3, 1, board, MARKTWO);
//	PlayerMove(2, 2, board, MARKTWO);
//	PlayerMove(1, 3, board, MARKTWO);
//	// display the board
//	DisplayBoard(board);
//	// display victory message
//	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

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
	// Display function components
	void top() {
		printf("\tTICK ATTACKS TOE\n\n");
		printf(" ");
		for (int col = 1; col <= COLS; col++) {
			printf(" %1d", col );
		}
		printf("\n\n");
	}

	void middleRow() {
		printf("  -");
		for (int col = 2; col <= COLS; col++) {
			printf("+-");
		}
		printf("\n");
	}

	void majorRow(char board[ROWS][COLS], int row) {
		printf("%d %c", row, board[row-1][0] );
		for (int col = 2; col <= COLS; col++) {
			printf("|%c", board[row-1][col - 1]);
		}
		printf("\n");
	}

	// The actual display
	top();
	majorRow(board, 1);
	for (int row = 2; row <= ROWS; row++) {
		middleRow();
		majorRow( board, row );
	}
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


int VictoryCheck(int winRequirement, char board[ROWS][COLS])
{
	// Your Implementation Goes Here
	int victoryCode = 5;
	
	return victoryCode;
}


void DisplayVictoryMessage(int victoryCode)
{
	// display the victory condition results
	switch(victoryCode) {
		case NOWIN:
			printf("There is still no winner.\n");
			break;
		case MARKONEVICTORY:
			printf("MARKONE has won the game.\n");
			break;
		case MARKTWOVICTORY:
			printf("MARKTWO has won the game.\n");
			break;
		case TIE:
			printf("The game is a draw.\n");
			break;
		case ERROR:
			printf("Something bad happened... MARKONE and MARKTWO have both won.\n");
			break;
		case EPIC_FAIL:
			printf("Something bad happened... VictoryCheck() has produced an impossible\ncombination of return code indicators.\n");
			break;
		default:
			printf("DisplayVictoryMessage() was passed an invalid victoryCode.\n");
			break;
	}
}
