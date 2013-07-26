// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Header file for the Score class
#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <ctime>
#include <string>
using namespace std;

//name, time, size, and number of mines and get methods for each
class Score
{
public:
	//Score::Score(string name_in, time_t time_in, int width_in, int height_in, int mines_in)
	//	constructs a score object
	//
	//Description:
	// Constructor for the score class
	//
	//Inputs:
	//	string name_in - string representing the name of the person who played
	//	time_t time_in - time representing the time it took the player to win the game
	//	int width_in - integer representing  the width of the matrix the scorer played on
	//	int height_in - integer respresenting the height of the matrix the player played on.
	//	int mines - integer representing the number of mines that were on the field.
	//
	//Outputs:
	//	None, initializes all private members
	Score(string name_in, time_t time_in, int width_in, int height_in, int mines_in);

	//Score::~Score()
	//	destructs a score object
	//
	//Description:
	// destructor for the score class
	//
	//Inputs:
	//	none
	//Outputs:
	//	None
	~Score();

	//string Score::get_name() const
	//	returns the name of the player who's score this is
	//
	//Description:
	// Accessor for the name member variable
	//
	//Inputs:
	//	none
	//Outputs:
	//	A string, representing the name of the player who's score this is.
	string get_name() const;

	//time_tScore::get_time() const
	//	returns the name of the player who's score this is
	//
	//Description:
	// Accessor for the time member variable
	//
	//Inputs:
	//	none
	//Outputs:
	//	A time_t, representing the time to win the game
	time_t get_time() const;

	//int Score::get_width() const
	//	returns the the width of the board this match was played on
	//
	//Description:
	// Accessor for the width member variable
	//
	//Inputs:
	//	none
	//Outputs:
	//	An int, representing the width of the baord in this score
	int get_width() const;

	//int Score::get_height() const
	//	returns the the height of the board this match was played on
	//
	//Description:
	// Accessor for the height member variable
	//
	//Inputs:
	//	none
	//Outputs:
	//	An int, representing the height of the baord in this score
	int get_height() const;

	//int Score::get_mines() const
	//	returns the the number of mines on the board when this score was recorded
	//
	//Description:
	// Accessor for the mines member variable
	//
	//Inputs:
	//	none
	//Outputs:
	//	An int, representing the number of mines that were on the board for this score
	int get_mines() const;

private:
	string name;
	time_t time;
	int width;
	int height;
	int mines;
};

#endif