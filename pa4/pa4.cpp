// Alex Henry
// CS 215, Spring 2013
// Programming assignment 4
// 17 April, 2013
//Attempted the bonus
//
//Driver .cpp file
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"
#include <string>
#include "HighScores.h"
#include "Score.h"

#include <fstream>
#include <vector>

using namespace std;

void pause_215(bool have_newline);

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	//Check if high scores list file exists. If not, create.
	HighScores hs_list;
	hs_list.create_file();

	//Read high scores into vector
	hs_list.read_scores();

	// TODO: Ask for the board size (between 5 and 20 in each direction)
	// and the number of mines.

	//Values to store
	int mines = -1;
	int width = -1;
	int height = -1;

	//Initialize player time
	time_t start = time(NULL);

	//Board size
	bool fail = false;
	do
	{
		fail = false;
		cout << "How large should the board be (width and height)? ";
		cin >> width >> height;
		cin.ignore(200, '\n');

		if (cin.fail())
		{
			cout << "Please enter two integers seperated by a space." << endl;
			cin.clear();
			cin.ignore(200, '\n');
			fail = true;

		}
		else
		{
			if (width < 5 || width > 20)
			{
				cout << "Sorry, the width cannot be smaller than 5 or greater than 20." << endl;
				fail = true;
			}
			else if (height < 5 || height > 20)
			{
				cout << "Sorry, the height cannot be smaller than 5 or greater than 20." << endl;
				fail = true;
			}
		}
	}
	while (fail);

	//Mine Count
	do
	{
		fail = false;
		cout << "How many mines should be placed (maximum " << height * width << ")? ";
		cin >> mines;
		cin.ignore(200, '\n');

		if (cin.fail())
		{
			cout << "Please enter an integer." << endl;
			cin.clear();
			cin.ignore(200, '\n');
			fail = true;
		}
		else
		{
			if (mines < 0 || mines > (height * width))
			{
				cout << "Sorry, there cannot be less than 0 or more than " << height * width << " mines." << endl;
				fail = true;
			}
		}
	}
	while(fail);

	// Create a board of that size.
	// TODO: change these numbers.
	MineSweeperBoard board(width, height, mines);

	while (!board.lost() && !board.won())
	{
		char input;

		board.display(cout);
		// TODO: Ask the user to [R]eveal, [F]lag, or [G]ive up.
		// The first two commands also require a Position, so
		// you may need to ask for x and y coordinates as well.


		int x = -1;
		int y = -1;

		do
		{
			fail = false;

			cout << "[r]eveal, [f]lag, or [g]ive up? ";
			cin >> input;
			cin.ignore(200, '\n');

			if (cin.fail())
			{
				cout << "Enter a single character representing your choice." << endl;
				cin.clear();
				cin.ignore(200, '\n');
				fail = true;
			}
			
			//Have a valid character, now ask for positions if necessary
			else
			{
				if (input == 'r')
				{
					cout << "What position (x, y)? ";
					cin >> x >> y;
					cin.ignore(200, '\n');

					if (cin.fail())
					{
						cout << "Enter two integers seperated by a space." << endl;
						cin.clear();
						cin.ignore(200, '\n');
						fail = true;
					}
					else
					{
						//Test validity of the entered position. Test without creating a position object for efficiency
						if (x < 0 || x >= width || y < 0 || y >= height)
						{
							cout << "The entered position is out of bounds." << endl;
							fail = true;
						}
					}

					if (fail == false)
					{
						//Input passed. Create Position object and reveal the position.
						Position to_reveal(x, y);
						board.reveal(to_reveal);
					}
				}

				else if (input == 'f')
				{
					cout << "What position (x, y)? ";
					cin >> x >> y;
					cin.ignore(200, '\n');

					if (cin.fail())
					{
						cout << "Enter two integers seperated by a space." << endl;
						cin.clear();
						cin.ignore(200, '\n');
						fail = true;
					}
					else
					{
						//Test validity of the entered position. Test without creating a position object for efficiency
						if (x < 0 || x >= width || y < 0 || y >= height)
						{
							cout << "The entered position is out of bounds." << endl;
							fail = true;
						}
					}

					if (fail == false)
					{
						//Input passed. Create Position object and flag the position.
						Position to_flag(x, y);
						board.flag(to_flag);
					}
				}

				else if (input == 'g')
				{
					board.give_up();
				}
				else
				{
					cout << "I don't recognize that input. Please input a single character representing your choice." << endl;
					fail = true;
				}
			}
		}
		while(fail);
	}

	// TODO: Tell the user whether they won or lost and display the final board
	if (board.lost())
	{
		cout << endl;
		cout << "*** You lost! ***" << endl << endl;;

		//Use the give up function to display a losing board. The function will loop over
		//and reveal all unrevealed squares
		board.give_up();
		board.display(cout);
	}
	else
	{
		cout << endl;
		cout << "               *** You won! ***" << endl << endl;
		board.display(cout);
	}
	// TODO: Compute and display how much time the game took.
	time_t end = time(NULL);
	time_t elapsed = end - start;
	cout << "Your game took " << elapsed << " seconds." << endl;

	if (board.won())
	{
		//***High score processing***

		//Ask user for their name to store
		cout << "What name would you like to use for the high score list? : ";
		string win_name;
		cin >> win_name;
		cin.ignore(200, '\n');

		//Add score to vector of others
		hs_list.add_score(Score(win_name, elapsed, width, height, mines));

		//Write scores to the file
		hs_list.write_scores();

		//Display the info to the user
		hs_list.display_scores();
	}

	pause_215(false);
	return 0;
}

void pause_215(bool have_newline)
{
    if (have_newline) {
        // Ignore the newline after the user's previous input.
        cin.ignore(200, '\n');
    }

    // Prompt for the user to press ENTER, then wait for a newline.
    cout << endl << "Press ENTER to continue." << endl;
    cin.ignore(200, '\n');
}
