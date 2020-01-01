/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for menu class
*****************************************************************************************/
#ifndef MENUS_HPP
#define MENUS_HHP
#include "Backpack.hpp"
#include <string>
using std::string;

class Menus
{
private:
public:
	int menuTakeTurn();
	int menuBackpack(Backpack *ptr);
	int menuYesNo();
	int menuMove();
	//int menuDelete();
	int validation(string);
};
#endif