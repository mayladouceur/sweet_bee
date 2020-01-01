/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for derived class normal
*****************************************************************************************/
#include "Normal.hpp"
#include "Backpack.hpp"
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
Normal::Normal()
{
	fill = ' ';
}

/****************************************************************************************
virtual action function caled when she lands on a normal space
*****************************************************************************************/
void Normal::action(Bee* rBee, Backpack *pack)
{
	Menus menu1;
	//choose a random item on a normal space. higher chance of there being something than nothing
	int gen = rand() % 8 + 1;
	if (gen == 1)
	{
		cout << "No items were found in this space" << endl;
	}
	else
	{
		
	}
	if (gen == 2 || gen == 3)
	{
		cout << "What luck! Bee found a straw! This is a multi-use item that she will need to obtain nectar";
		cout << "Should she pick up the straw?" << endl;
		//call menu
		int choice = menu1.menuYesNo();
		if (choice == 1)
		{
			//add to pack
			pack->fillBackpack("straw");
		}
	}
	else if (gen == 4 || gen == 5)
	{
		cout << "Cool! She found antidote! This is a single-use item that will protect her from pesticides.";  
		cout << " She can use it at the beginning of a turn." << endl;
		cout << "Should she pick up antidote?" << endl;
		int choice = menu1.menuYesNo();
		if (choice == 1)
		{
			//add to pack
			pack->fillBackpack("antidote");
		}
	}
	else if (gen == 5 || gen == 6)
	{
		cout << "Can't be too careful! This extra stinger might come in handy in case of a run-in with a flyswatter" << endl;
		cout << "Should she pick up the extra stinger?" << endl;
		int choice = menu1.menuYesNo();
		if (choice == 1)
		{
			//add to pack
			pack->fillBackpack("stinger");
		}

	}
	else if (gen == 7 || gen == 8)
	{
		cout << "Nice! She found pheremone. She can't enter the hive without pheremone."; 
		cout << "The other bees need to be able to recognize your chemical scent" << endl;
		cout << "Should she pick up pheremone?" << endl;
		int choice = menu1.menuYesNo();
		if (choice == 1)
		{
			//add to pack
			pack->fillBackpack("pheremone");
		}
	}

}
/****************************************************************************************
getters
*****************************************************************************************/
char Normal::getFill()
{
	return fill;
}

string Normal::getType()
{
	string type = "Normal";
	return type;
}