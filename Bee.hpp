/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for bee class
*****************************************************************************************/
#ifndef BEE_HPP
#define BEE_HPP
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Backpack.hpp"
#include <vector>
using std::vector;

class Bee 
{
private:
	char fill = 'B';
	int health = 20;
	Backpack *backpack;
public:
	Bee();
	char getFill();
	void setHealth(int);
	int getHealth();
};

#endif
