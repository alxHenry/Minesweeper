// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Header file for the HighScores class
#ifndef HIGHSCORES_H_INCLUDED
#define HIGHSCORES_H_INCLUDED

#include <string>
#include <vector>
#include "Score.h"
using namespace std;

//vector<string> split_string(string to_split, char delim) - splits a given string by the given delimiter
//
// Description:
// Used to split a string into words. Useful when reading in information from a file.
//
// Inputs:
//  Takes in the string to be split and the char delimiter to split it by.
//   
// Outputs:
//   Returns a vector, each field is a segment of the given string split by the character delimiter
//
vector<string> split_string(string to_split, char delim);

//Class that keeps track of high score data. Has member functions to create a file, read a file, add
// a score to the file, write the data to a file, and to display the information to the user.
class HighScores
{
public:
	//HighScores::HighScores()
	//	create a HighScores object
	//
	//Description:
	// Holds the filename of the high scores list and the vector the list is read into
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None, initializes the filename private member
	HighScores();

	//HighScores::~HighScores()
	//	HighScores destructor
	//
	//Description:
	// frees the HighScores class, is here for completeness, has no implementation.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None
	~HighScores();

	//void HighScores::create_file()
	//	create a high scores .txt file
	//
	//Description:
	// Checks if a high scores file exists, if not it creates the file
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None, creates a .txt file in the default directory. Named high_scores.txt.
	void create_file();

	//void HighScores::read_scores()
	//	read high score data from high_scores.txt
	//
	//Description:
	// Reads in high score data from the default text file, stores it in a vector of Score objects created
	//	from the data.
	//
	//Inputs:
	//	none, reads from high_scores.txt
	//
	//Outputs:
	//	None, assigns the score_vec private member
	void read_scores();

	//void HighScores::add_score(Score score_in)
	//	records a high score
	//
	//Description:
	// Adds a Score object to the score_vec private member.
	//
	//Inputs:
	//	Score score_in - a score object representing the data from the current run of minewseeper
	//
	//Outputs:
	//	None, modifies the score_vec private member
	void add_score(Score score_in);

	//void HighScores::write_scores()
	//	write the high scores data to a text file
	//
	//Description:
	// Sorts the score_vec vector so when we store the high scores data it is ordered in the file. Then
	// it writes the data to high_scores.txt for storage. Overwrites any old file that is there because that
	// file has the potential to be out of date.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None, overwrites high_scores.txt
	//
	//Notes:
	//	Since the sort is implemented here this should be called before display_scores().
	void write_scores();

	//void HighScores::display_scores()
	//	disp;ay high score information to the user
	//
	//Description:
	// loops through the score_vec vector and outputs the information to cout so the user can read it.
	// Should be called after write_scores() because this function does not sort the data.
	//
	//Inputs:
	//	none
	//
	//Outputs:
	//	None, stream output to cout of the high score data.
	void display_scores() const;

private:
	string filename;
	vector<Score> score_vec;
};

#endif