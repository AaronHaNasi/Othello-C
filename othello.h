//***************************************************
// Filename: othello.h
//
// Author: Nandigam
//***************************************************

#ifndef OTHELLO_H_

#define OTHELLO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BLACK 'B'	// value used for BLACK disc

#define WHITE 'W'	// value used for WHITE disc

#define EMPTY '-'	// value used to indicate that a cell in the board is unoccupied

#define TIE 'T'	    // value used to indicate that game resulted in a tie

// Constructs and returns a string representation of the board
char *toString(int size, char board[][size]);

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(int size, char board[][size]);

// Returns true if moving the disc to location row,col is valid; false otherwise
bool isValidMove(int size, char board[][size], int row, int col, char disc);

// Places the disc at location row,col and flips the opponent discs as needed 
void placeDiscAt(int size, char board[][size], int row, int col, char disc);

// Returns true if a valid move for disc is available; false otherwise
bool isValidMoveAvailable(int size, char board[][size], char disc);

// Returns true if the board is fully occupied with discs; false otherwise
bool isBoardFull(int size, char board[][size]);

// Returns true if either the board is full or a valid move is not available for either disc; false otherwise
bool isGameOver(int size, char board[][size]);

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns TIE. When called before the game is over, it returns 0.
char checkWinner(int size, char board[][size]);

#endif /* OTHELLO_H_ */
