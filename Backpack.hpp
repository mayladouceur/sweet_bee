/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for backpack class
*****************************************************************************************/
#ifndef BACKPACK_HPP
#define BACKPACK_HPP
#include <vector>
#include <string>
//#include "Menus.hpp"
using std::vector;
using std::string;

class Menus;

class Backpack
{
private:
	Menus *menu;
	vector <string> backpack;
	int index;
	bool wonGame;
	bool isPoisoned;
public:
	Backpack();
	void fillBackpack(string);
	vector <string> getBackpack();
	void printList();
	void editItems();
	void startingItems();
	void useAntidote();
	void remove(int);
	int getIndex();
	bool searchList(string);
	bool getWinner();
	void setWinner(bool);
	bool getPoisoned();
	void setPoisoned(bool);
};
#endif