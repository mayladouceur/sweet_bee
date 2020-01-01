/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for normal class
*****************************************************************************************/
#ifndef NORMAL_HPP
#define NORMAL_HPP
#include "Space.hpp"
#include "Backpack.hpp"

class Normal : public Space
{
private:
	char fill = ' ';
	Backpack *pack;
public:
	Normal();
	virtual void action(Bee *point, Backpack *ptr);
	virtual char getFill();
	virtual string getType();

};
#endif
