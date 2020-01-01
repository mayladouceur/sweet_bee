/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for Board class
*****************************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include "Space.hpp"
#include "Flower.hpp"
#include "Menus.hpp"
#include <vector>
using std::vector;

class Menus;

class Board
{
private:
	const int sizeX = 5;
	const int sizeY = 5;
	vector<Space*> board;
	Space* currentLocation;
	Space* temp = NULL;
	Menus* menus;
	//Space* itemLocation;
public:
	//void addItem(Item* point, int);
	//string getItem();
	void displayStats(Bee *bee, Backpack *ptr);
	void printLocation(Bee *bee, Backpack *ptr);
	void makeBoard(Space *rSpace);
	//void remove();
	void pointBoard();
	void displayBoard(Bee *bee);
	void placeBee(Bee *bee);
	void moveBee(Bee *bee, Backpack *ptr);
	void explainRules();
	Menus* getMenu();
	~Board();
};
#endif // !BOARD_HPP

