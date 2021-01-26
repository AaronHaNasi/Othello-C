//***************************************************
// Filename: othello.c
//
// Author(s): Aaron Bager
//***************************************************
#define EMPTY '-'
#define WHITE 'W'
#define BLACK 'B'
#include "othello.h"

// Constructs and returns a string representation of the board
char *toString(int size, char board[][size])
{
	char *str = (char *) calloc(3 * (size+1) * (size+1), sizeof(char));
	char *ptr = str;

	for (int i = 0; i < size; i++) {
		ptr += sprintf(ptr,(i == 0 ? "%3d" : "%2d"),i+1);
	}
	sprintf(ptr,"\n");
	ptr++;

	for (int i = 0; i < size; i++) {
		sprintf(ptr,"%1d",i+1);
		ptr++;
		for (int j = 0; j < size; j++) {
			sprintf(ptr,"%2c",board[i][j]);
			ptr += 2;
		}
		sprintf(ptr,"\n");
		ptr++;
	}

	return str;
}

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(int size, char board[][size])
{
	int center = ( size / 2 ) - 1;
	for( int i = 0; i < size; i++) {
		for ( int j = 0; j < size; j++) {
			if ( i == center && j == center ) {
				board[i][j] = 'B';
			}
			else if ( i == center && j == (center + 1)) {
				board[i][j] = 'W';
			}
			else if ( i == (center + 1)  && j == center ) {
				board[i][j] = 'W';
			}
			else if ( i == (center + 1) && j == (center + 1)) {
				board[i][j] = 'B'; 
			}
			else {
				board[i][j] = '-';
			}

		}
	}
	// COMPLETED 
}

char getOpposite(char disc) {
	if (disc == 'B') 
		return 'W'; 
	else
		return 'B';
}

// Returns true if moving the disc to location row,col is valid; false otherwise
bool isValidMove(int size, char board[][size], int row, int col, char disc)
{
	char opposite = getOpposite(disc); 
 	bool nextToOpposite = false; 
	if ( row > size || col > size || row < 0 || col < 0 ) 
		return false; 

	if ( board[row][col] != EMPTY ) {
		return false; 
	}
	
	if( row < size ) {
		if ( board[row+1][col] == opposite ) {
			for ( int i = row + 1 ; i < size; i++) {// check to right
				if ( board[i][col] == disc && nextToOpposite) 
					return true; 
				else if ( board[i][col] == EMPTY )
					break;
				else if ( board[i][col] == opposite )
					nextToOpposite = true; 	
			}
		}
	}
	
	nextToOpposite = false; 

	if ( row > 0 ) { // check left
		if ( board[row-1][col] == opposite ) {
			for (int i = row - 1; i > 0; i--) {
				if (board[i][col] == disc && nextToOpposite)
					return true; 
				else if ( board[i][col] == EMPTY ) 
					break; 
				else if ( board[i][col] == opposite )
					nextToOpposite = true; 
			}
		}
	}
	
	nextToOpposite = false; 

	if( col < size ) { // check down 
		if ( board[row][col+1] == opposite ) {
			for ( int i = col + 1; i < size; i++ ) {
				if (board[row][i] == disc && nextToOpposite)
					return true; 
				else if ( board[row][i] == EMPTY ) 
					break; 
				else if ( board[row][i] == opposite )
					nextToOpposite = true; 
			}
		}
	}
	
	nextToOpposite = false; 

	if ( col > 0 ) { // check up 
		if ( board[row][col-1] == opposite ) {
			for ( int i = col - 1; i > 0 ; i--) {
				if( board[row][i] == disc /* && nextToOpposite*/ ) 
					return true;
				else if ( board[row][i] == EMPTY )
					break; 
				else if ( board[row][i] == opposite )
					nextToOpposite = true; 
			}	
		}
	}
	
	nextToOpposite = false; 

	if ( row > 0 && col > 0) { // up & left
		if ( board[row-1][col-1] == opposite ) {
			for (int i = row - 1, j = col -1; i > 0 && j > 0; i--, j--) {
				if ( board[i][j] == disc && nextToOpposite ) 
					return true;
				else if ( board[i][j] == EMPTY ) 
					break; 
				else if ( board[i][j] == opposite )
					nextToOpposite = true; 
			}
		}
	}

	nextToOpposite = false; 

	if ( row < size && col > 0 ) {
		for ( int i = row + 1, j = col - 1; i < size && j > 0; i++, j--) {
			if ( board[i][j] == disc && nextToOpposite)
				return true; 
			else if ( board[i][j] == EMPTY ) 
				break;  
			else if ( board[i][j] == opposite )
				nextToOpposite = true; 

		}
	}

	nextToOpposite = false; 

	if ( row > 0 && col < size) {
		for ( int i = row - 1, j = col + 1; i > 0 && j < size; i--, j++) {
			if ( board[i][j] == disc && nextToOpposite ) 
				return true; 
			else if ( board[i][j] == EMPTY ) 
				break;  
			else if ( board[i][j] == opposite ) 
				nextToOpposite = true; 
		}
	}

	nextToOpposite = false; 

	if ( row < size && col < size) {
		for ( int i = row + 1, j = col + 1; i < size && j < size; i++, j++) {
			if ( board[i][j] == disc && nextToOpposite ) 
				return true;
			else if ( board[i][j] == EMPTY)
				break;
			else if ( board[i][j] == opposite )
				nextToOpposite = true; 	
		}
	}	
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(int size, char board[][size], int row, int col, char disc)
{
	char oppositeDisc = getOpposite(disc);
       	int piecesToFlip = 0; 

	if (!isValidMove(size,board,row,col,disc)) {
		return;
	}
	else {
		board[row][col] = disc; // place disc
		if ( row < size ) {
		       	// make sure to not cause a segfault, make sure it is not on side
			for ( int i = row + 1; i < size; i++ ) { // flip right
				if ( board[i][col] == oppositeDisc ) {
					piecesToFlip++; 
				}
				else if ( board[i][col] == disc ) {
					for ( int j = row + 1; j < i; j++ ) {
						board[j][col] = disc; 
					}
				}
				else 
					break; 
			}
		}
		if ( row > 0 ) {
			for ( int i = row - 1; i > 0; i-- ) { // flip left
				if ( board[i][col] == oppositeDisc ) {
					continue; 
				}
				else if ( board[i][col] == disc ) {
					for ( int j = row - 1; j > i; j-- ) {
						board[j][col] = disc; 
					}
				}
				else
					break; 
			}
		}
		if ( col < size ) {
			for ( int i = col + 1; i < size; i++ ) { // flip down
				if ( board[row][i] == oppositeDisc )
					continue;
				else if ( board[row][i] == disc ) {
					for ( int j = col + 1; j < i; j++ ) {
						board[row][j] = disc; 
					}
				}
				else
					break; 
			}
		}
		if ( col > 0 ) { // flip up
			for ( int i = col - 1; i > 0; i-- ) {
				if ( board[row][i] == oppositeDisc )
					continue; 
			       	else if ( board[row][i] == disc ) {
					for ( int j = col - 1; j > i; j-- ) {
						board[row][j] = disc;
					}
				}	
				else
					break; 
			}
		}
		if ( row > 0 && col > 0) {
			for ( int i = row - 1, j = col - 1; i > 0 && j > 0; i--, j-- ) {
				if ( board[i][j] == oppositeDisc) 
					continue; 
				else if ( board[i][j] == disc) {
					for ( int k = row, l = col; k > i && l > j; k--, l--) {
						board[k][l] = disc; 
					}
				}
				else
					break; 
			}
		}
		if ( row < size && col > 0) {
			for ( int i = row + 1, j = col - 1; i < size && j > 0; i++, j-- ) {
				if ( board[i][j] == oppositeDisc)
					continue; 
				else if ( board[i][j] == disc) {
					for ( int k = row, l = col; k < i && l > j; k++, l--) {
						board[k][l] = disc; 
					}
				}
				else
					break; 
			}
		}
		if ( row > 0 && col < size ) {
			for ( int i = row - 1, j = col + 1; i > 0 && j < size; i--, j++ ) {
				if ( board[i][j] == oppositeDisc) 
					continue; 
				else if ( board[i][j] == disc) {
					for ( int k = row, l = col; k > i && l < j; k--, l++ ) {
						board[k][l] = disc; 
					}
				}
				else 
					break; 
			}
		}
		if ( row < size && col < size ) {
			for ( int i = row + 1, j = col + 1; i < size && j < size; i++, j++ ) {
				if ( board[i][j] == oppositeDisc)
					continue; 
				else if ( board[i][j] == disc) 
					for ( int k = row, l = col; k < i && l < j; k++, l++) {
						board[k][l] = disc; 
					}
				else 
					break; 
			}
		}
	}
	// COMPLETE REST OF THIS FUNCTION
}

// Returns true if a valid move for disc is available; false otherwise
bool isValidMoveAvailable(int size, char board[][size], char disc)
{
	for ( int i = 0; i < size; i++ ) {
		for ( int j = 0; j < size; j++ ) {
			if(isValidMove(size, board, i, j, disc))
			       return true; 	
		}	
	}
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Returns true if the board is fully occupied with discs; false otherwise
bool isBoardFull(int size, char board[][size])
{
	for ( int i = 0; i < size; i++ ) {
		for ( int j = 0; j < size; j++ ) {
			if ( board[i][j] == '-' ) {
				return false; 
			}
		}
	}
	return true;	// REPLACE THIS WITH YOUR IMPLEMENTATION	
}

// Returns true if either the board is full or a valid move is not available for either disc; false otherwise
bool isGameOver(int size, char board[][size])
{	
	if ( isBoardFull( size, board )) {
		return true; 
	}
	else if ( !isValidMoveAvailable(size, board, 'W') && !isValidMoveAvailable(size, board, 'B'))
		return true; 
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns TIE. When called before the game is over, it returns 0.
char checkWinner(int size, char board[][size])
{
	int white = 0;
	int black = 0; 
	if (!isGameOver(size,board)) {
		return 0;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ( board[i][j] == WHITE )
				white++; 
			else if ( board[i][j] == BLACK )
				black++; 
		}
	}
	
	if ( white > black )
		return WHITE;
	else if ( white < black )
		return BLACK; 
	return TIE;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Used in GDB to print specific values in the array using GDB
char printValue(int size, char board[][size], int row, int col) {
	printf("%c", board[row][col]);
}
