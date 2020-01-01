/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: Main file for final project. Game allows a bee to move through 25 randomized
spzces. The bee must get nectar and bring it back to his hive. 
*****************************************************************************************/
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "Space.hpp"
#include "Flower.hpp"
#include "Swatter.hpp"
#include "Normal.hpp"
#include "Board.hpp"
#include "Bee.hpp"
#include "Hive.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	int choice1 = 0;
	srand(time(0));
	Bee *bee = new Bee;
	Backpack *pack = new Backpack;
	pack->startingItems();
	//need to make a function to randomly send flower, swatter, etc;
	Board board1;
	board1.explainRules();
	//Menus *menu1 = board1.getMenu();
	int numFlowers = 0;
	int counter = 0;
	for (counter = 0; counter < 24; counter++)
	{
		//when you get to space 25, you have reached the hive
		//randomize which spaces are created
		int num = rand() % 3 + 1;
		if (num == 1)
		{
			//create new instance of class and add to board
			Space *flowers = new Flower;
			board1.makeBoard(flowers);
		}
		else if (num == 2)
		{
			Space *swatters = new Swatter;
			board1.makeBoard(swatters);
		}
		else if (num == 3)
		{
			Space *normal = new Normal;
			board1.makeBoard(normal);
		}
	}
	//hive will be the last space always
	Space *hive = new Hive;
	board1.makeBoard(hive);
	//function creates a grid of objects pointing to eachother in four directions
	board1.pointBoard();
	//bee starts out in the first square
	board1.placeBee(bee);
	cout << endl;
	//show board
	board1.displayBoard(bee);
	do
	{
		//print the HP and item list
		board1.displayStats(bee, pack);
		cout << endl;
		int choice = board1.getMenu()->menuTakeTurn();
		//if quit
		if (choice == 3)
		{
			cout << "Thank you for playing." << endl;
			delete bee;
			delete pack;
			return 0;
		}
		//if want to delete item or use antidote
		else if (choice == 2)
		{
			board1.getMenu()->menuBackpack(pack);

		}
		//take turn
		else if (choice == 1)
		{
			board1.moveBee(bee, pack);
			cout << endl;
			board1.displayBoard(bee);
			board1.printLocation(bee, pack);
		}
	} while (bee->getHealth() > 0 && pack->getWinner() == false);
	if (bee->getHealth() <= 0)
	{
		cout << "Bee is out of health, you lose." << endl;
	}
	delete bee;
	delete pack;
	//delete hive;
	cin.ignore();
}