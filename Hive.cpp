/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: Hive is a derived class from space. once a player arrives at the hive space,
if they have pheremone and nectar, they win
*****************************************************************************************/
#include "Hive.hpp"
#include "Bee.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

/****************************************************************************************
constructor for fill
*****************************************************************************************/
Hive::Hive()
{
	fill = 'H';
}
/****************************************************************************************
virtual action function for hive class, accept or refuse bee
*****************************************************************************************/
void Hive::action(Bee* rBee, Backpack *ptr)
{
	bool exists = false;
	cout << "Yay!! You have finally arrived at the hive with your nectar!" << endl;
	//search for pheremone
	exists = ptr->searchList("pheremone");
	if (exists == false)
	{
		//if bee doesn't have pheremone, game is over
		cout << "..." << endl;
		std::cin.ignore();
		cout << "Oh no! You lost your pheremone. The other bees in the hive are unable to recognize your chemical scent" << endl;
		cout << "The other bees have killed you. The game is over" << endl;
		rBee->setHealth(-5);
	}
	//if bee has it
	else if (exists == true)
	{
		//make sure they have nectar
		exists = ptr->searchList("nectar");
		if (exists == true)
		{			
			cout << "You've won the game! You returned to the hive with enough nectar to support your fellow bees!" << endl;
			//set bool to know that game is over
			ptr->setWinner(exists);
		}
		if (exists == false)
		{
			cout << "You returned to the hive without enough nectar! Do you want your hive to starve? Please get some nectar and you can return" << endl;
		}
	}
}
/****************************************************************************************
setters/getters
*****************************************************************************************/
char Hive::getFill()
{
	return fill;
}

string Hive::getType()
{
	string type = "Hive";
	return type;
}

string Hive::getItem()
{
	return string();
}
