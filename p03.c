#include <stdio.h>


#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

#define ROWS 4
#define COLS 4
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
#define CONSECUTIVE_MARKS_REQUIRED 4


#include "a08.h"

// (More) Prototypes
void clear_screen();
int turn(char[ROWS][COLS],char,int);
int enter_row();
int enter_col();
int run_again_query();
void flush();


int main()
{
	char board[ROWS][COLS];
	int status;
	char marks[2] = { MARKONE, MARKTWO };

	InitializeBoard(board);

	status = 1;

	while ( status == 1 ) {
		if ( status = turn(board, marks[0], 0) ) {
			status = turn(board, marks[1], 0);
		}
	}

	if ( !run_again_query() ) {
		return 0;
	}

	main();
}


void clear_screen()
{
	int i;
	for (i = 0; i < 80; i++) {
		printf("\n");
	}
}

int turn( char board[ROWS][COLS], char mark, int cumulative_tries )
{
	int row;
	int col;
	int status;

	// Display current board
	// Query message before entering rows and cols
	clear_screen();
	printf("%c's turn! Go go go, %c!\n\n", mark, mark);
	DisplayBoard(board);
	printf("\n");
	row = enter_row();
	col = enter_col();

	printf("\n");
	status = 0;
	status = PlayerMove(row, col, board, mark);

	printf("\n");
	if ( status == 0 ) {
		if ( cumulative_tries == 3 ) {
			// Print something about not having forfeited turn
			return 1;
		}
		clear_screen();
		return turn( board, mark, cumulative_tries + 1 );
	}
	// Push back if invalid position was entered

	// display the board
	clear_screen();
	DisplayBoard(board);
	// display victory message
	return DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );
}

int enter_row()
{
	int row;
	printf("Enter a row number for your next move: "                          );

	scanf("%i", &row);
	flush();
	if (row <= 0 || row > ROWS) {
		printf("Invalid row entry.\n");
		return enter_row();
	}
	return row;
}

int enter_col()
{
	int col;
	printf("Enter a column number for your next move: "                       );

	scanf("%i", &col);
	flush();
	if (col <= 0 || col > COLS) {
		printf("Invalid column entry.\n");
		return enter_col();
	}
	return col;
}

int run_again_query()
{
	char status;
	printf("\n"                                                               );
	printf("Run program again?\n"                                             );
	printf("(To run again, enter Y or y. To quit, enter any other key.)\n"    );
	printf(":"                                                                );
	scanf ("%c", &status);
	flush ();
	if (status == 'Y' || status == 'y') {
		printf("\n\n\n"                                                       );
		return 1;
	}
	return 0;
}

// This function flushes stdin (especially for use following scanf())
void flush()
{
	char extraChar;
	do {
		scanf("%c", &extraChar);
	} while ( extraChar != '\n' && extraChar != EOF );
}
