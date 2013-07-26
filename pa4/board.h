// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Header file for the MineSweeperBoard class
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include "position.h"
#include "positionlist.h"
using namespace std;

//Class containing the Minesweeper board. Contains private members to represent the size of the board as well as
//dynamically allocated arrays to keep track of mine positions, flag positions, and revealed squares. Has member
//functions to get the sizes, set the characteristics of a square, test for a win or loss, to reveal positions, and
//to display the board.
class MineSweeperBoard
{
public:
	//MineSweeperBoard::MineSweeperBoard(int board_width, int board_height, int mine_count)
	//	constructor for the minesweeperboard class
	//
	//Description:
	//Initialize a board with a given width and height, containing the
	// given number of randomly-placed mines.  Nothing should be revealed
	// or flagged.  If there are more mines than spaces for them, fill
	// the entire board with mines. Dynamically allocates three vectors, flagged, mined, and revealed.
	//
	//Inputs:
	//	int board_width - integer (>= 0) representing board width
	//  int board_height - integer (>= 0) representing board height
	//  int mine_count - integer (>= 0) representing number of mines on the board
	//
	//Outputs:
	//	None
	MineSweeperBoard(int board_width, int board_height, int mine_count);

	//MineSweeperBoard::~MineSweeperBoard()
	//	destructor for the minesweeperboard class
	//
	//Description:
	// Clean up the board, freeing any dynamically allocated memory.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None, frees the dynamically allocated mined, flagged, and revealed vectors
	~MineSweeperBoard();

	//int MineSweeperBoard::get_width()
	//	get width
	//
	//Description:
	// get width of the board
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	an integer representing the width
	int get_width() const;

	//int MineSweeperBoard::get_height()
	//	get height
	//
	//Description:
	// get height of the board
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	an integer representing the height
	int get_height() const;

	//void MineSweeperBoard::reveal()
	//	recursively reveal squares
	//
	//Description:
	// Reveal a square.
	// If this square wasn't already revealed, and if the number of
	// adjacent mines equals the number of adjacent flags, recursively
	// reveal all the surrounding squares that aren't flagged.
	//
	//Inputs:
	//	Position p - a position object representing the position to reveal
	//
	//Outputs:
	//	None, changes the revealed vector
	void reveal(Position p);

	//bool MineSweeperBoard::flag()
	//	flag a square
	//
	//Description:
	// If this square wasn't already flagged, flag the square. Otherwise, unflag the square.
	//
	//Inputs:
	//	Position p - a position object representing the position to flag
	//
	//Outputs:
	//	None, changes the flagged member
	bool flag(Position p);

	//char MineSweeperBoard::appearance()
	//	get appearance of a single square
	//
	//Description:
	// Return the appearance of the square (what will be
	// displayed to the player) as a single character.
	//
	//Inputs:
	//	Position p - a position object representing the position
	//
	//Outputs:
	//	a char representing the appearance the square has
	char appearance(Position p) const;

	//void MineSweeperBoard::display()
	//	dispplay board
	//
	//Description:
	// Display the entire board to an output stream.  Prints
	// a header with the column numbers, and prints the row
	// number on each line.  For example,
	//     |  0  1  2  3  4
	//  ---+---------------
	//   0 |  1  /  .  .  .
	//   1 |  1  2  .  .  .
	//   2 |  0  1  .  .  .
	//   3 |  0  1  2  1  1
	//   4 |  0  0  0  0  0
	//
	//Inputs:
	//	ostream &out - an ostream called by reference that the output will be printed too
	//
	//Outputs:
	//	stream output of the board
	void display(ostream &out) const;

	//bool MineSweeperBoard::won()
	//	tell if player won
	//
	//Description:
	// Returns true if the player won (every square with a mine
	// is flagged, and every cell without a mine is revealed).
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	bool representing whether the player won
	bool won() const;

	//bool MineSweeperBoard::lost()
	//	tell if player lost
	//
	//Description:
	// Returns true if the player lost (there is a revealed
	// mine).
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	bool representing whether the player lost
	bool lost() const;

	//void MineSweeperBoard::give_up()
	//	player gives up
	//
	//Description:
	// reveals the whole board and the player loses in process.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	none, modifies the revealed member array
	void give_up();
private:
	//PositionList MineSweeperBoard::adjacent(Postion P) const
	//	find adjacent positions
	//
	//Description:
	// Returns a list of all the positions adjacent to p.  If p
	// is in the middle of the board, it has eight neighbors,
	// but if it is on an edge or corner it will have fewer.	
	//
	//Inputs:
	//	A position P to find the adjacent positions
	//
	//Outputs:
	//	A PositionList object that contains all of the adjacent 
	//	positions to the one inputted
	PositionList adjacent(Position p) const;

	//int MineSweeperBoard::adjacent_mines(Postion P) const
	//	find adjacent mines - private function
	//
	//Description:
	// Return the number of mines adjacent to a square.
	//
	//Inputs:
	//	A position P to find the adjacent mines
	//
	//Outputs:
	//	an integer representing the number of adjacent mines
	int adjacent_mines(Position p) const;

	//int MineSweeperBoard::adjacent_flags(Postion P) const
	//	find adjacent flags - private function
	//
	//Description:
	// Return the number of flags adjacent to a square.
	//
	//Inputs:
	//	A position P to find the adjacent flags
	//
	//Outputs:
	//	an integer representing the number of adjacent flags
	int adjacent_flags(Position p) const;

	// Size of the board.
	int width;
	int height;

	// Dynamically allocated 2D arrays indicating which squares are
	// revealed, which are mined, and which are flagged.
	bool **revealed;
	bool **mined;
	bool **flagged;
};
#endif
