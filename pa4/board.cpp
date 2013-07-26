// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Implementation of the MineSweeperBoard class
#include <iostream>
#include <iomanip>
#include "board.h"
#include <vector>
#include <algorithm>
using namespace std;

MineSweeperBoard::MineSweeperBoard(int board_width, int board_height, int mine_count)
{
	width = board_width;
	height = board_height;

	//If more mines are asked for then possible then make mine_count = width * height (max).
	if (mine_count > board_width * board_height)
	{
		mine_count = board_width * board_height;
	}

	//Dynamically create the 3 arrays that keep track what is flagged, mined, and revealed.

	//Must randomly place the mines. Will create positions and add them to a vector, each time checking if a position
	//with those coordinates has already been added.
	vector<Position> mine_pos;

	//Code for randomly creating a position and then checking if it is already mined
	bool exist;
	int added_mines = 0;
	while (added_mines < mine_count)
	{
		exist = false;

		//Create the position of the mine using the random number generator
		Position temp_pos(rand() % board_width, rand() % board_height);

		//Loop over the mine_pos vector and check if the pos is a duplicate
		for (int i = 0; i < mine_pos.size(); i++)
		{
			if (temp_pos.x() == mine_pos[i].x() && temp_pos.y() == mine_pos[i].y())
			{
				exist = true;
			}
		}

		//Is not a duplicate, append to vector and update the count
		if (exist == false)
		{
			mine_pos.push_back(temp_pos);
			added_mines++;
		}
	}

	//Mine array
	mined = new bool* [board_height];

	for (int row = 0; row < board_height; row++)
	{
		//Create the 2x2 array
		mined[row] = new bool[board_width];
		for (int col = 0; col < board_width; col++)
		{
			bool mine_found = false;

			//Fill the values. Loop through mine_pos and see if this position is supposed to have a mine in it.
			for (int k = 0; k < mine_pos.size(); k++)
			{
				//Check if this location contains a mine. Use a bool 'mine_found' to keep track of
				//whether it found a mine there or not.
				if (mine_pos[k].x() == col && mine_pos[k].y() == row)
				{
					mine_found = true;
				}
			}
			if (mine_found)
			{
				mined[row][col] = true;
			}
			else
			{
				mined[row][col] = false;
			}
		}
	}

	//Flagged array
	flagged = new bool* [board_height];
	for (int row = 0; row < board_height; row++)
	{
		//Create the 2x2 array
		flagged[row] = new bool[board_width];
		for (int col = 0; col < board_width; col++)
		{
			//Fill the values. None will be flagged initially
			flagged[row][col] = false;
		}
	}

	//Revealed
	revealed = new bool* [board_height];
	for (int row = 0; row < board_height; row++)
	{
		//Create the 2x2 array
		revealed[row] = new bool[board_width];
		for (int col = 0; col < board_width; col++)
		{
			//Fill the values. None will be flagged initially
			revealed[row][col] = false;
		}
	}
}

MineSweeperBoard::~MineSweeperBoard()
{
	//Must loop through each of the three dynamically allocated arrays and remove the items.
	//First go to inner loop and remove from each column, then delete the array.

	//Free mine array
	for (int row = 0; row < height; row++)
	{
		delete[] mined[row];
	}
	delete[] mined;

	for (int row = 0; row < height; row++)
	{
		delete[]flagged[row];
	}
	delete[] flagged;

	for (int row = 0; row < height; row++)
	{
		delete[] revealed[row];
	}
	delete[] revealed;
}

int MineSweeperBoard::get_width() const
{
	return width;
}

int MineSweeperBoard::get_height() const
{
	return height;
}

void MineSweeperBoard::reveal(Position p)
{
	//First reveal the square at position
	if (!revealed[p.y()][p.x()] && !flagged[p.y()][p.x()])
	{
		revealed[p.y()][p.x()] = true;

		//Now find all adjacent positions and recursively call this function on them if
		//number of mines is equal to number flagged.
		if (adjacent_mines(p) == adjacent_flags(p))
		{
			PositionList adj;
			adj = adjacent(p);

			for (int i = 0; i < adj.size(); i++)
			{
				Position curr = adj.get(i);
				reveal(curr);
			}
		}
	}
}

bool MineSweeperBoard::flag(Position p)
{
	if (flagged[p.y()][p.x()] == false)
	{
		//Place flag
		flagged[p.y()][p.x()] = true;
		return true;
	}
	else
	{
		//Remove flag
		flagged[p.y()][p.x()] = false;
		return false;
	}
}

void MineSweeperBoard::display(ostream &out) const
{
	out << endl;
	out << setw(5) << "|";
	//Now print the column headers
	for (int col=0; col < width; col++)
	{
		out << setw(3) << col;
	}
	out << endl;

	out << "----+";
	//Print line of dashes
	for (int i=0; i < width;i++)
	{
		out << "---";
	}
	out << endl;

	//Loop through each position on the board and display it's appearance
	//Must also display the row headers
	for (int row=0; row < height; row++)
	{
		out << setw(3) << row << setw(2) << "|";
		for (int col=0; col < width; col++)
		{
			Position temp_pos(col, row);
			out << setw(3) << appearance(temp_pos);
		}
		out << endl << endl;
	}
}

void MineSweeperBoard::give_up()
{
	//Just loop through every square, reveal if it has not been flagged or revealed already. This will cause
	//the player to lose when a mine is revealed.

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++) 
		{
			if (!revealed[y][x] && !flagged[y][x])
			{
				Position to_reveal(x, y);
				reveal(to_reveal);
			}
			//Check if it is incorrectly flagged
			else if(flagged[y][x] && !mined[y][x])
			{
				//Incorrectly flagged, change it then reveal
				flagged[y][x] = false;
				Position to_reveal(x, y);
				reveal(to_reveal);
			}
		}
	}
}

bool MineSweeperBoard::lost() const
{
	//Check every square, if we see one that is both revealed and mined return true immediately.
	//If it makes it through all checks then return false.
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (mined[y][x] && revealed[y][x]) {
				return true;
			}
		}
	}
	//Will only get here if all squares pass
	return false;
}

char MineSweeperBoard::appearance(Position p) const
{
	int x = p.x();
	int y = p.y();

 	if (flagged[y][x]) {
		return '/';
	} else if (revealed[y][x]) {
		if (mined[y][x]) {
			// Boom!
			return '*';
		} else {
			// At most 8 adjacent mines, so one digit.
			int adjmines = adjacent_mines(p);
			// Convert a number to a digit character.
			return '0' + adjmines;
		}
	} else {
		// Unrevealed, unflagged.
		return '.';
	}
}

bool MineSweeperBoard::won() const
{
	// Check every square.  If we see a square that is mined but
	// not flagged, or unmined but not revealed, return false
	// immediately.  If we get to the end, every square is correct,
	// so the user won and we return true.
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (mined[y][x] && !flagged[y][x]) {
				return false;
			} else if (!mined[y][x] && !revealed[y][x]) {
				return false;
			}
		}
	}
	return true;
}


PositionList MineSweeperBoard::adjacent(Position p) const
{
	PositionList result;

	// Loop over the 3x3 block centered around p.
	for (int adj_y = p.y() - 1; adj_y <= p.y() + 1; adj_y++) {
		for (int adj_x = p.x() - 1; adj_x <= p.x() + 1; adj_x++) {
			// Make a position out of the new coordinates.
			Position adj(adj_x, adj_y);
			// Skip out-of-bounds squares
			if (!adj.in_bounds(width, height))
				continue;
			// Also skip the center.
			if (adj.x() == p.x() && adj.y() == p.y())
				continue;

			// If we get here, it's really adjacent, so add it to the list.
			result.push_front(adj);
		}
	}
	return result;
}

int MineSweeperBoard::adjacent_mines(Position p) const
{
	PositionList neighbors = adjacent(p);

	// Loop over the neighbors.
	int adjacent_count = 0;
	for (int i = 0; i < neighbors.size(); i++) {
		Position adj = neighbors.get(i);
		// If it's mined, increase the count.
		if (mined[adj.y()][adj.x()])
			adjacent_count++;
	}
	return adjacent_count;
}

int MineSweeperBoard::adjacent_flags(Position p) const
{
	PositionList neighbors = adjacent(p);

	// Loop over the neighbors.
	int adjacent_count = 0;
	for (int i = 0; i < neighbors.size(); i++) {
		Position adj = neighbors.get(i);
		// If it's mined, increase the count.
		if (flagged[adj.y()][adj.x()])
			adjacent_count++;
	}
	return adjacent_count;
}



