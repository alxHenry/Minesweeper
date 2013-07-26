// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Header file for the Position class
#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

// Class representing a position on a two-dimensional board.
// Stores an x and y coordinate, with methods to return and
// set each coordinate, and a method to test whether the
// position falls within a given width and height.
class Position
{
public:
	//Position::Position()
	//	create a position object
	//
	//Description:
	// Create a Position object for the origin (0, 0).
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None, initializes the xcoord and ycoord private members
	Position();

	//Position::Position(int xc, int yc)
	//	create a position object
	//
	//Description:
	//	Create a Position object for the position (xc, yc).
	//
	//Inputs:
	//	int xc - integer (>= 0 and  < width) representing the x coordinate of a position
	//	int yc - integer (>= 0 and  < height) representing the y coordinate of a position
	//
	//Outputs:
	//	None, initializes the xcoord and ycoord private members
	Position(int xc, int yc);

	//int Position::x() const
	//	get x coord
	//
	//Description:
	// Get the position of the xcoord private member
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	An integer representing the xcoord of the position
	int x() const;

	//int Position::y() const
	//	get y coord
	//
	//Description:
	// Get the position of the ycoord private member
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	An integer representing the ycoord of the position
	int y() const;

	//void Position::set_x() const
	//	set x coord
	//
	//Description:
	// Set the position of the xcoord private member
	//
	//Inputs:
	//	int new_x - integer (>= 0 and  < width) representing the x coordinate of the position
	//
	//Outputs:
	//	None, modifies the xcoord private member
	void set_x(int new_x);

	//void Position::set_y() const
	//	set y coord
	//
	//Description:
	// Set the position of the ycoord private member
	//
	//Inputs:
	//	int new_y - integer (>= 0 and  < width) representing the y coordinate of the position
	//
	//Outputs:
	//	None, modifies the ycoord private member
	void set_y(int new_y);

	//bool Position::in_bounds(int width, int height) const
	//	test if the coordinates are in bounds
	//
	//Description:
	// Returns true if this position's coordinates are
	// within the given bounds: 0 <= x < width and
	// 0 <= y < height .	
	//
	//Inputs:
	//	int width - integer representing the x coordinate
	//	int height - integer representing the y coordinate
	//
	//Outputs:
	//	A bool representing whether the coordinate is in bounds
	bool in_bounds(int width, int height) const;

private:
	int xcoord;
	int ycoord;
};

#endif
