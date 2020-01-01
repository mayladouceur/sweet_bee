/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: Board.cpp contains functions for board class including making the board,
setting pointers, and printing the board
*****************************************************************************************/
#include "Board.hpp"
#include "Space.hpp"
#include "Flower.hpp"
#include "Bee.hpp"
#include "Normal.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/****************************************************************************************
makeboard function adds an object pointer to the vector
*****************************************************************************************/
void Board::makeBoard(Space * rSpace)
{
	board.push_back(rSpace);
}
/****************************************************************************************
function makes all the object pointers point to eachother, making a grid of pointers
*****************************************************************************************/
void Board::pointBoard()
{
	//set pointers to the right
	for (int i = 0; i < board.size() - 1; i++)
	{
		//if it's on the edge, set right to null
		if ((i + 1) % 5 == 0)
		{
			board[i]->setRight(NULL);
		}
		else
		{
			board[i]->setRight(board[i + 1]);
		}
	}
	//set pointers to the left
	for (int i = 0; i < board.size(); i++)
	{
		//if it's on the edge, set to NULL
		if (i % 5 == 0)
		{
			board[i]->setLeft(NULL);
		}
		else
		{
			board[i]->setLeft(board[i - 1]);
		}
	}
	//set pointers to top
	for (int i = 0; i < board.size() - 1; i++)
	{
		//if it's on the top row, set to null
		if (i < 5)
		{
			board[i]->setTop(NULL);
		}
		else
		{
			board[i]->setTop(board[i - 5]);
		}
	}
	//setpointers to bottom
	for (int i = 0; i < board.size(); i++)
	{
		//unless on the bottom row, then set to null
		if (i > 19)
		{
			board[i]->setBottom(NULL);
		}
		else
		{
			board[i]->setBottom(board[i + 5]);
		}
	}

}
/****************************************************************************************
function displays grid, created a box to make the appearance of the game easier to understand
*****************************************************************************************/
void Board::displayBoard(Bee *rBee)
{
	int counter = 0;

	cout << "_______________________________" << endl;
	cout << "|     |     |     |     |     |" << endl;
	cout << "|";
	for (int i = 0; i < board.size(); i += sizeX)
	{
		for (int j = i; j < sizeY + i && j < board.size(); j++)
		{
			if (board[j] == currentLocation)
			{
				//print out the character of the object in that space (@, B, H)
				cout << "  " << rBee->getFill() << "  |";
			}

			else
			{
				cout << "  " << board[j]->getFill() << "  |";
			}
		}
		cout << endl;
		cout << "|_____|_____|_____|_____|_____|" << endl;
		if (counter < 4)
		{
			cout << "|     |     |     |     |     |" << endl;
			cout << "|";
			counter++;
		}
	}
	cout << endl;
}

/****************************************************************************************
function displays the health and baackpack items of the character
*****************************************************************************************/
void Board::displayStats(Bee *rBee, Backpack *bpack)
{
	cout << "Bee currently has " << rBee->getHealth() << " health points" << endl;
	cout << "She has the following items: " << endl;
	bpack->printList();
}

/****************************************************************************************
function tells what space was landed on and calls its action
*****************************************************************************************/
void Board::printLocation(Bee *rBee, Backpack *bpack)
{

	cout << "She has landed on a " << temp->getType() << endl;
	temp->action(rBee, bpack);
}

/****************************************************************************************
Function asks what direction bee wants to move in and performs that move
*****************************************************************************************/
void Board::moveBee(Bee *rBee, Backpack *bpack)
{
	Menus menu1;
	string unvalidated;
	int direction = 0;
	bool acceptable = false;
	do {
		//menu for the move function
		do {
			cout << endl;
			cout << "Which direction should she move?" << endl;
			cout << "1.) Right" << endl << "2.) Left" << endl << "3.) Up " << endl << "4.) Down" << endl;
			cin >> unvalidated;
			direction = menu1.validation(unvalidated);
		} while (direction < 1 || direction > 4);
		//right
		if (direction == 1)
		{
			//if it's possible to move that way, do it
			if (currentLocation->getRight() != NULL)
			{
				temp = currentLocation->getRight();
				currentLocation = currentLocation->getRight();
				acceptable = true;
			}
			//if not, use a bool
			else acceptable = false;
		}
		//left
		else if (direction == 2)
		{
			//if possible to move that way
			if (currentLocation->getLeft() != NULL)
			{
				temp = currentLocation->getLeft();
				currentLocation = currentLocation->getLeft();
				acceptable = true;
			}
			//if not
			else acceptable = false;
		}
		//up
		else if (direction == 3)
		{
			//if possible to move that way
			if (currentLocation->getTop() != NULL)
			{
				temp = currentLocation->getTop();
				currentLocation = currentLocation->getTop();
				acceptable = true;
			}
			//if not
			else acceptable = false;
		}
		//down
		else
		{
			//if possible
			if (currentLocation->getBottom() != NULL)
			{
				temp = currentLocation->getBottom();
				currentLocation = currentLocation->getBottom();
				acceptable = true;
			}
			//if not possible
			else acceptable = false;
		}
		//reprompt until player is not tryign to get to a null space
	} while (acceptable == false);
	//if playe rhas been poisoned by a flower, they lose 2 points per square
	if (bpack->getPoisoned() == false)
	{
		//otherwise they lose 1 point
		rBee->setHealth(rBee->getHealth() - 1);
	}
	else if (bpack->getPoisoned() == true)
	{
		rBee->setHealth(rBee->getHealth() - 2);
	}
}

/****************************************************************************************
getter for the menu object pointer
*****************************************************************************************/
Menus* Board::getMenu()
{
	return menus;
}
/****************************************************************************************
destructor
*****************************************************************************************/
Board::~Board()
{
	for (auto i = board.begin(); i != board.end(); ++i)
		delete *i;
}
/****************************************************************************************
place the first bee in the 1, 1 spot
*****************************************************************************************/
void Board::placeBee(Bee *rBee)
{
	currentLocation = board.front();
}
/****************************************************************************************
lists the rules for a new player
*****************************************************************************************/
void Board::explainRules()
{
	cout << endl << endl << endl;
	cout << "			" << "   \\//     " << "    \\//     " << "    \\//     " << "    \\//     " << endl;
	cout << "			" << " -<(((**)   " << " -<(((**)   " << " -<(((**)   " << " -<(((**)   " << endl;
	cout << "			" << "   '''     " << "    '''     " << "    '''     " << "    '''     " << endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cin.ignore();
	cout << "Bee is a lowly worker bee (B). Her job is to collect nectar from at least one flower (@) and bring it to her hive (H)." << endl;
	cout << "Traveling wears her out, and for each space that she moves, Bee will lose a health point. She starts out with 20 HP." << endl;
	cin.ignore();
	cout << "To extract nectar, Bee will need to use a straw." << endl;
	cout << "She starts out with one, but if she loses it, straws and other items can be randomly found on ground" << endl << "(spaces which appear blank)." << endl;
	cin.ignore();
	cout << "Unfortunately some flowers contain pesticides that can poison her." << endl << "If poisoned, Bee will lose two health points per space instead of one." << endl;
	cout << "This can be cured with antidote, another item found on the ground (she does not start with antidote)." << endl;
	cin.ignore();
	cout << "Watch out for jerks with flyswatters! These spaces also appear blank. ";
	cout << "If they hit her, she will lose 5 points." << endl << "They can also knock off her important items." << endl;
	cin.ignore();
	cout << "Bee can defend herself by trying to sting. If she succeeds, she will protect herself," << endl << "But she will also lose her stinger." << endl;
	cout << "She may be able to find a replacement stinger on the normal spaces as well." << endl;
	cin.ignore();
	cout << "To get into the hive, she will need bee pheremone. Like the stinger, she starts out with bee pheremone, " << endl << "but it can be ";
	cout << "knocked off by the flyswatter." << endl << "If that's the case, she will need to find some on the ground before she returns to the hive, " << endl;
	cout << "or the other bees will kill her when she arrives and you will lose the game.";
	cin.ignore();
	cout << endl << "You are able to return to spaces and go backwards, sometimes with new items and different results." << endl;
	cin.ignore();
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cin.ignore();
}

