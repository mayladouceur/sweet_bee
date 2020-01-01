/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for flower class
*****************************************************************************************/
#ifndef FLOWER_HPP
#define FLOWER_HPP
#include "Space.hpp"

class Flower : public Space
{
private:
	char fill = '@';
public:
	Flower();
	virtual void action(Bee *point, Backpack *ptr);
	virtual char getFill();
	virtual string getType();
	virtual string getItem();

};

#endif
