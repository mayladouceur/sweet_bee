/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: header file for hive class
*****************************************************************************************/
#ifndef HIVE_HPP
#define HIVE_HPP
#include "Space.hpp"


class Hive: public Space
{
private:
	char fill = 'H';
public:
	Hive();
	virtual void action(Bee *point, Backpack *ptr);
	virtual char getFill();
	virtual string getType();
	virtual string getItem();
};
#endif