// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//
//Implementation of the Score class
#include "Score.h"

Score::Score(string name_in, time_t time_in, int width_in, int height_in, int mines_in)
{
	name = name_in;
	time = time_in;
	width = width_in;
	height = height_in;
	mines = mines_in;
}

Score::~Score()
{}

string Score::get_name() const
{
	return name;
}

time_t Score::get_time() const
{
	return time;
}

int Score::get_width() const
{
	return width;
}

int Score::get_height() const
{
	return height;
}

int Score::get_mines() const
{
	return mines;
}