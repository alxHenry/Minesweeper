// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Implementation of the HighScores class
#include "HighScores.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include "Score.h"

using namespace std;

vector<string> split_string(string to_split, char delim)
{
	vector<string> words;
	
	//Find first @, if npos is returned there is an error
	int i1 = to_split.find('@');

	if (i1 == string::npos){
		cout << "The QuestionPool file is not formatted correctly!" << endl;}
	else{
		words.push_back(to_split.substr(0, i1));}

	int index = i1;

	for (int i = i1 + 1; i < to_split.length(); i++){
		if (to_split[i] == delim){
			words.push_back(to_split.substr(index + 1, i - (index + 1)));
			index = i;}}

	//Add last word to vector
	words.push_back(to_split.substr(index + 1));

	return words;
}

//Use this function as a third parameter to feed sort so it knows how to sort
//a score object. Allows us to make use of the standard library's sort function.
//Referenced http://www.cplusplus.com/reference/algorithm/sort/ example
bool score_sort(Score i, Score j)
{
	//Sort by the lowest time to complete
	return (i.get_time() < j.get_time());
}

HighScores::HighScores()
{
	filename = "high_scores.txt";
}

HighScores::~HighScores()
{}

//Create file if it doesn't exist
void HighScores::create_file()
{
	fstream hs;
	hs.open(filename);
	if (hs.fail() == true)
	{
		//Create file
		ofstream score_file(filename);
		score_file.close();
	}
	else
	{
		hs.close();
	}
}

void HighScores::read_scores()
{
	fstream hs;
	hs.open(filename);
	string entry;
	while (getline(hs, entry))
	{
		vector<string> fields;
		fields = split_string(entry, '@');

		//Convert fields from string to the correct types
		//Time
		istringstream strm_time;
		strm_time.str(fields[1]);
		time_t time;
		strm_time >> time;

		//Width
		istringstream strm_width;
		strm_width.str(fields[2]);
		int width;
		strm_width >> width;

		//Height
		istringstream strm_height;
		strm_height.str(fields[3]);
		int height;
		strm_height >> height;

		//Mines
		istringstream strm_mines;
		strm_mines.str(fields[4]);
		int mines;
		strm_mines >> mines;

		//Create Score objects with these values
		score_vec.push_back(Score(fields[0], time, width, height, mines));
	}
	hs.close();
}

void HighScores::add_score(Score new_score)
{
	//Add score to vector, will write it to the text file in another function
	score_vec.push_back(new_score);
}

//Will overrwrite the previous file
void HighScores::write_scores()
{
	ofstream hs;
	hs.open(filename);

	//Sort vector
	sort(score_vec.begin(), score_vec.end(), score_sort);

	//Now write scores to file
	for (int i = 0; i < score_vec.size(); i++)
	{
		hs << score_vec[i].get_name() << '@' << score_vec[i].get_time() << '@' << score_vec[i].get_width() << '@'
			<< score_vec[i].get_height() << '@' << score_vec[i].get_mines() << endl;
	}
	hs.close();
}

void HighScores::display_scores() const
{
	for (int i = 0; i < score_vec.size(); i++)
	{
		cout << setw(3) << i + 1 << ". " << setw(12) << score_vec[i].get_name() << "     " << setw(5) << score_vec[i].get_time() 
			<< " seconds    " << setw(2) <<score_vec[i].get_width() << "x" << setw(2) <<score_vec[i].get_height() 
				<< "     " << score_vec[i].get_mines() << " mines" << endl;
	}
}