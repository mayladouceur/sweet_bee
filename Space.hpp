/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for base Space class
*****************************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Backpack.hpp"
using std::string;

class Hive;
class Bee;
class Flower;
class Swatter;
class Normal;

class Space
{
protected:
	
	Space *top;
	Space *right;
	Space *left;
	Space *bottom;
	char fill;
	Bee *bee;

public:
	Space(){}
	Space(char star, Space * Stop, Space * Sright, Space * Sleft, Space * Sbottom )
		: fill(star), top(Stop), right(Sright), bottom(Sbottom) {}
	//virtual void printSpace() = 0;
	Space* getRight();
	Space* getLeft();
	Space* getTop();
	Space* getBottom();
	virtual void action(Bee *point, Backpack *ptr) = 0;
	void setLeft(Space *point);
	void setRight(Space * point);
	void setTop(Space * point);
	void setBottom(Space *point);
	virtual string getType() = 0;
	virtual char getFill() = 0;
};


#endif