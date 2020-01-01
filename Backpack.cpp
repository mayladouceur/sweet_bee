/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: contains function for backpack class
*****************************************************************************************/
#include "Backpack.hpp"
#include "Menus.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//constructor for vector
Backpack::Backpack()
{
	vector <string> backpack;
}
/****************************************************************************************
start out with 3 items
*****************************************************************************************/
void Backpack::startingItems()
{
	backpack.push_back("pheremone");
	backpack.push_back("stinger");
	backpack.push_back("straw");
}
/****************************************************************************************
print the list of items currently in backpack
*****************************************************************************************/
void Backpack::printList()
{
	int counter = 1;
	for (auto i = backpack.begin(); i != backpack.end(); ++i)
	{
		//print a numbered list
		cout << counter << ".) ";
		std::cout << *i << endl;
		counter++;
	}
}
/****************************************************************************************
player can use antidote if they have it
*****************************************************************************************/
void Backpack::useAntidote()
{
	cout << "You've chosen to use your antidote, Bee is healed and will only take 1 damage point for each space!" << endl;
	remove(index + 1);
	//turn off the poison
	setPoisoned(false);
	cin.ignore();
}
/****************************************************************************************
search  the vector of strings for a specific string
*****************************************************************************************/
bool Backpack::searchList(string item)
{
	//citation thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/
	bool exists = false;
	auto i = find(backpack.begin(), backpack.end(), item);
	if (i != backpack.end())
	{
		//index is where the specific item is lovated
		index = std::distance(backpack.begin(), i);
		exists = true;
	}
	else
	{
		exists = false;
	}
	return exists;
}
/****************************************************************************************
setters/getters
*****************************************************************************************/
bool Backpack::getWinner()
{
	return wonGame;
}

void Backpack::setWinner(bool winner)
{ 
	wonGame = winner;
}

bool Backpack::getPoisoned()
{
	return isPoisoned;
}

void Backpack::setPoisoned(bool uPoisoned)
{
	isPoisoned = uPoisoned;
}
/****************************************************************************************
fillbackpack function takes a string and adds it to the vector
*****************************************************************************************/
void Backpack::fillBackpack(std::string item)
{
	if (backpack.size() < 4)
	{
		backpack.push_back(item);
	}
	else
	{
		//if there are already 4 items, need to delete one
		editItems();
		fillBackpack(item);
	}
}
/****************************************************************************************
edititems fucntion allows user to delete an item
*****************************************************************************************/
void Backpack::editItems()
{
	string unvalidated;
	int itemNum;
	printList();
	cout << "Which item would you like to delete? Please input the corresponding number." << endl;
	std::cin >> unvalidated;
	itemNum = menu->validation(unvalidated);
	//calls remove function
	remove(itemNum);
}
/****************************************************************************************
function takes an int and deletes that item in the vector
*****************************************************************************************/
void Backpack::remove(int itemNum)
{
	backpack.erase(backpack.begin() + itemNum - 1);
}
/****************************************************************************************
getters/setters
*****************************************************************************************/
int Backpack::getIndex()
{
	return index;
}

vector<string> Backpack::getBackpack()
{
	return backpack;
}
