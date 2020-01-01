/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: contains functions for the derived flower class
*****************************************************************************************/
#include "Flower.hpp"
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
Flower::Flower()
{
	fill = '@';
}
/****************************************************************************************
action virtual function
*****************************************************************************************/
void Flower::action(Bee* rBee, Backpack *ptr)
{
	Menus menu1;
	bool hasStraw = false;
	int num;
	int choice;
	cout << "would you like to drink nectar?" << endl;
	//call menu to get yes/no
	choice = menu1.menuYesNo();
	if (choice == 1)
	{
		hasStraw = ptr->searchList("straw");
		if (hasStraw == true)
		{
			//can't drink without a straw
			num = rand() % 3 + 1;
			//66% chance of being a good flower
			if (num < 3)
			{
				rBee->setHealth(rBee->getHealth() + 5);
				cout << "Bee is revitalized. She has gained 5 points of health and now has " << rBee->getHealth() << " health" << endl;
				ptr->fillBackpack("nectar");
			}
			//33% chance of being poisonous
			else if (num == 3)
			{
				cout << "The flower was fertilized with pesticides!!" << endl; 
				cout << "bee has been poisoned and she will lose 2 extra points of health for each space unless she finds an antidote" << endl;
				ptr->setPoisoned(true);
			}
		}
		else
		{
			cout << "Sorry, you do not have a straw to drink nectar. Please find a straw on the ground and come back!" << endl;
		}
	}
	//if chooses not to drink, do nothing
	else if (choice == 2)
	{ 
	}
}
/****************************************************************************************
gettesr/setters
*****************************************************************************************/
char Flower::getFill()
{
	return fill;
}

string Flower::getType()
{
	string type = "Flower";
	return type;
}

string Flower::getItem()
{
	return string();
}
