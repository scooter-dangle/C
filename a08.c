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

// Prototypes
char* flat_char_matrix(char[],int,int,int,int);
void flatten_char_matrix(char[ROWS][COLS],char[],int,int);
void fill_char_matrix(char[],char[ROWS][COLS],int,int);
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
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKONE);
	PlayerMove(1, 2, board, MARKONE);
	PlayerMove(1, 3, board, MARKONE);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	// Produce a vertical victory
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKTWO);
	PlayerMove(2, 1, board, MARKTWO);
	PlayerMove(3, 1, board, MARKTWO);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	// Produce a diagonal-down victory
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKONE);
	PlayerMove(2, 2, board, MARKONE);
	PlayerMove(3, 3, board, MARKONE);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	// Produce a diagonal-up victory
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(3, 1, board, MARKTWO);
	PlayerMove(2, 2, board, MARKTWO);
	PlayerMove(1, 3, board, MARKTWO);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	// Produce a multiple player victory
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(4, 1, board, MARKONE);
	PlayerMove(4, 2, board, MARKONE);
	PlayerMove(4, 3, board, MARKONE);
	PlayerMove(3, 1, board, MARKTWO);
	PlayerMove(2, 2, board, MARKTWO);
	PlayerMove(1, 3, board, MARKTWO);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	// Produce a tie
	// initialize board
	InitializeBoard(board);
	// populate board
	int row;
	for (row = 0; row < ROWS; row++) {
		int offset = (row % 2) * 2;
		int col;
		for (col = offset; col < COLS; ) {
			PlayerMove(row+1, col+1, board, MARKONE);
			(col % 2) == 0 ? (col += 1) : (col += 3);
		}
	}

	for (row = 0; row < ROWS; row++) {
		int offset = ((row+1) % 2) * 2;
		int col;
		for (col = offset; col < COLS; ) {
			PlayerMove(row+1, col+1, board, MARKTWO);
			(col % 2) == 0 ? (col += 1) : (col += 3);
		}
	}
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage( VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board) );

	// exit program
	return 0;
}


// Function Implementations
char* flat_char_matrix(char array[], int Rows, int Cols, int row, int col) {
	return &array[ row*Cols + col ];
}

void flatten_char_matrix(char matrix[ROWS][COLS], char array[], int Rows, int Cols) {
	int i;
	for (i = 0; i < Rows; i++) {
		int k;
		for (k = 0; k < Cols; k++) {
			*flat_char_matrix(array, Rows, Cols, i, k) = matrix[i][k];
		}
	}
}

void fill_char_matrix(char array[], char matrix[ROWS][COLS], int Rows, int Cols) {
	int i;
	for (i = 0; i < Rows; i++) {
		int k;
		for (k = 0; k < Cols; k++) {
			matrix[i][k] = *flat_char_matrix(array, Rows, Cols, i, k);
		}
	}
}

void InitializeBoard(char board[ROWS][COLS]) {
	int i;
	for (i = 0; i < ROWS; i++) {
		int k;
		for (k = 0; k < COLS; k++)
			board[i][k] = BLANK;
	}
}


void DisplayBoard(char board[ROWS][COLS]) {
	int row;
	// Display function components
	void top() {
		printf("\tTICK ATTACKS TOE\n\n");
		printf(" ");
		int col;
		for (col = 1; col <= COLS; col++) {
			printf(" %1d", col );
		}
		printf("\n\n");
	}

	void middleRow() {
		printf("  -");
		int col;
		for (col = 2; col <= COLS; col++) {
			printf("+-");
		}
		printf("\n");
	}

	void majorRow(char board[ROWS][COLS], int row) {
		printf("%d %c", row, board[row-1][0] );
		int col;
		for (col = 2; col <= COLS; col++) {
			printf("|%c", board[row-1][col - 1]);
		}
		printf("\n");
	}

	// The actual display
	top();
	majorRow(board, 1);
	for (row = 2; row <= ROWS; row++) {
		middleRow();
		majorRow( board, row );
	}
}


int PlayerMove(int row, int col, char board[ROWS][COLS], char symbol) {
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


int VictoryCheck(int winRequirement, char board[ROWS][COLS]) {
	// Create 2 arrays to check for diagonal wins
	char diagArray1[(ROWS + COLS - 1)*MIN];
	char diagArray2[(ROWS + COLS - 1)*MIN];
	char verticalArray[COLS*ROWS];
	char flat_board[ROWS*COLS];
	// Could eventually use CONSECUTIVE_MARKS_REQUIRED to make diagonal-
	// check arrays smaller.

	// And then fill them with blanks.
	int i;
	int kay;
	int eye;
	int markOneScore, markTwoScore;
	int victoryCode = EPIC_FAIL;
	for (i = 0; i < (ROWS + COLS - 1); i++) {
		int k;
		for (k = 0; k < MIN; k++) {
			*flat_char_matrix(diagArray1, ROWS + COLS - 1, MIN, i, k ) = BLANK;
			*flat_char_matrix(diagArray2, ROWS + COLS - 1, MIN, i, k ) = BLANK; 
		}
	}

	// Calculate diagArray1
	// First set
	for (i = 0; i < ROWS; i++) {
		int k;
		for (k = 0; (k <= i) && (k < COLS); k++) {
			*flat_char_matrix(diagArray1, ROWS + COLS - 1, MIN, i, k ) = board[i-k][k];
		}
	}
	// Second set
	for (i = ROWS; i < (ROWS + COLS - 1); i++) {
		int jay = i - ROWS + 1;
		int k;
		for (k = 0; (ROWS - k - 1 >= 0) && (k+jay < COLS); k++) {
			*flat_char_matrix(diagArray1, ROWS + COLS - 1, MIN, i, k ) = board[ROWS-k-1][k+jay];
		}
	}

	// Calculate diagArray2
	// First set
	i = 0;
	for (kay = COLS - 1; kay >= 0; kay--) {
		int k = 0;
		int eye;
		for (eye = 0; kay + eye < COLS; eye++) {
			*flat_char_matrix(diagArray2, ROWS + COLS - 1, MIN, i, k ) = board[eye][kay + eye];
			k++;
		}
		i++;
	}
	// Second set
	for (eye = 1; eye < ROWS; eye++) {
		int k = 0;
		for (kay = 0; kay+eye < ROWS; kay++) {
			*flat_char_matrix(diagArray2, ROWS + COLS - 1, MIN, i, k ) = board[kay + eye][kay];
			k++;
		}
		i++;
	}

#if TESTING
	// print test of diagArray1
	for (i = 0; i < (ROWS + COLS - 1); i++) {
		int k;
		for (k = 0; k < MIN; k++) {
			printf("%c ", *flat_char_matrix(diagArray1, ROWS + COLS - 1, MIN, i, k ) );
		}
		printf("\n");
	}
	printf("\n");

	// print test of diagArray2
	for (i = 0; i < (ROWS + COLS - 1); i++) {
		int k;
		for (k = 0; k < MIN; k++) {
			printf("%c ", *flat_char_matrix(diagArray2, ROWS + COLS - 1, MIN, i, k ) );
		}
		printf("\n");
	}
	printf("\n");
#endif

	// Create an array to check for vertical wins

	// Fill it with a transposed version of main board
	for (i = 0; i < COLS; i++) {
		int k;
		for (k = 0; k < ROWS; k++)
			*flat_char_matrix(verticalArray, COLS, ROWS, i, k ) = board[k][i];
	}

#if TESTING
	// print test of verticalArray
	for (i = 0; i < COLS; i++) {
		int k;
		for (k = 0; k < ROWS; k++) {
			printf("%c ", *flat_char_matrix(verticalArray, COLS, ROWS, i, k ) );
		}
		printf("\n");
	}
	printf("\n");
#endif

	int lineVictoryCheck(char array[], int Rows, int Cols, int row, int winRequirement, char mark) {
		int ticker = 0;
		int col;
		for (col = 0; col < Cols; col++) {
			if (*flat_char_matrix(array, Rows, Cols, row, col)==mark) {
				++ticker;
			}
			else {
				ticker = 0;
			}
			if(ticker >= winRequirement) return 1;
		}
		return 0;
	}

	int arrayVictoryCheck(char array[], int Rows, int Cols, int winRequirement, char mark) {
		int row;
		for (row = 0; row < Rows; row++) {
			if (lineVictoryCheck(array, Rows, Cols, row,  winRequirement, mark) == 1) return 1;
		}
		return 0;
	}
	// Your Implementation Goes Here
	markOneScore = 0;
	markTwoScore = 0;
	flatten_char_matrix(board, flat_board, ROWS, COLS);

	markOneScore += arrayVictoryCheck(flat_board, ROWS, COLS, CONSECUTIVE_MARKS_REQUIRED, MARKONE);
	markOneScore += arrayVictoryCheck(verticalArray, COLS, ROWS, CONSECUTIVE_MARKS_REQUIRED, MARKONE);
	markOneScore += arrayVictoryCheck(diagArray1, ROWS + COLS -1, MIN, CONSECUTIVE_MARKS_REQUIRED, MARKONE);
	markOneScore += arrayVictoryCheck(diagArray2, ROWS + COLS -1, MIN, CONSECUTIVE_MARKS_REQUIRED, MARKONE);
	markTwoScore += arrayVictoryCheck(flat_board, ROWS, COLS, CONSECUTIVE_MARKS_REQUIRED, MARKTWO);
	markTwoScore += arrayVictoryCheck(verticalArray, COLS, ROWS, CONSECUTIVE_MARKS_REQUIRED, MARKTWO);
	markTwoScore += arrayVictoryCheck(diagArray1, ROWS + COLS -1, MIN, CONSECUTIVE_MARKS_REQUIRED, MARKTWO);
	markTwoScore += arrayVictoryCheck(diagArray2, ROWS + COLS -1, MIN, CONSECUTIVE_MARKS_REQUIRED, MARKTWO);

	for (i = 0; i < ROWS; i++) {
		int k;
		for (k = 0; k < COLS; k++) {
			if (board[i][k]==BLANK) {
				victoryCode=NOWIN;
				k=COLS;
				i=ROWS;
			}
		}
	}

	if (markTwoScore>0) {
		victoryCode=MARKTWOVICTORY;
	}

	if (markOneScore>0) {
		if (markTwoScore>0) {
			victoryCode=ERROR;
		}
		else {
			victoryCode=MARKONEVICTORY;
		}
	}

	if (victoryCode==EPIC_FAIL) {
		victoryCode=TIE;
	}

	// Scan for remaining blanks

	// Run a However-Many-In-a-Row function on all four arrays
	
	return victoryCode;
}


void DisplayVictoryMessage(int victoryCode) {
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
