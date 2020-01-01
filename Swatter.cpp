/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: contains functions for derived swater class
*****************************************************************************************/
#include "Swatter.hpp"
#include "Bee.hpp"
#include "Menus.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

/****************************************************************************************
constructor
*****************************************************************************************/
Swatter::Swatter()
{
	fill = ' ';
}
/****************************************************************************************
action function for derived class swatter
*****************************************************************************************/
void Swatter::action(Bee* rBee, Backpack *ptr)
{
	bool exists;
	Menus menu1;
	int choice;
	cout << "Oh no! Should she try and sting him?" << endl;
	choice = menu1.menuYesNo();
	//make sure bee has a stinger in backpack
	exists = ptr->searchList("stinger");
	if (exists == false)
	{
		//in case she has an extra stinger in pack
		exists = ptr->searchList("extra stinger");
		if (exists == false)
			cout << "Bee doesn't have any stingers to sting him with!" << endl;
		choice = 2;
	}
	//if chose to sting
	if (choice == 1)
	{
		cout << endl << "Bee is trying to sting the man!" << endl;
		cout << "..." << endl;
		std::cin.ignore();
		//66% chance of stinging him
		int gen = rand() % 3 + 1;
		if (gen == 1)
		{
			cout << "She wasn't able to sting him" << endl;
			choice = 2;
		}
		else
		{
			//if she stings him, need to erase the stinger from vector
			cout << "Yay!! She stung him and got away!" << endl;
			cout << "She lost her stinger, but it was worth it" << endl;
			ptr->searchList("stinger");
			ptr->remove(ptr->getIndex() + 1);
		}
	}
	//if choose not to sting, don't have stingers, or miss
	if (choice == 2)
	{
		int gen = 0;
		//knock off items
		//first make sure backpack not empty
		if (ptr->getBackpack().empty() == true && rBee->getHealth() > 0)
		{
			cout << "She doesnt't have any items to knock off" << endl;
		}
		//if it's not empty, generate random number zero to one less than size of vector
		//(don't want to take away all the items)
		else if (ptr->getBackpack().empty() == false)
		{
			gen = rand() % ptr->getBackpack().size();
		}
		//take away health from the swat
		rBee->setHealth(rBee->getHealth() - 5);
		cout << "Bee was hit with a fly swatter! She has " << rBee->getHealth() << " health remaining" << endl;
		//if number generated greater than 0
		if (gen > 0)
		{
			cout << "He also knocked off " << gen << " of her items" << endl;
			//erase items
			for (int i = 0; i < gen; i++)
			{
				int gen2 = rand() % ptr->getBackpack().size() + 1;
				ptr->remove(gen2);
			}
		}
		else if (gen == 0 && rBee->getHealth() > 0)
		{
			cout << "Luckily he didn't knock off any items!" << endl;
		}
	}
	cout << endl;
}

/****************************************************************************************
getters
*****************************************************************************************/
char Swatter::getFill()
{
	return fill;
}

string Swatter::getType()
{
	string type = "man with a fly swatter";
	return type;
}