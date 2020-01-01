/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for swatter class
*****************************************************************************************/
#ifndef SWATTER_HPP
#define SWATTER_HPP
#include "Space.hpp"

class Swatter : public Space
{
private:
	char fill;
public:
	Swatter();
	virtual void action(Bee *point, Backpack *ptr);
	virtual char getFill();
	virtual string getType();

};
#endif