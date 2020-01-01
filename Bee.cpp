/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: contains functions for the bee class
*****************************************************************************************/
#include <iostream>
#include <string>
#include "Bee.hpp"

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::vector;
/****************************************************************************************
constructor
*****************************************************************************************/
Bee::Bee()
{
	fill = 'B';
	health = 20;
}
/****************************************************************************************
getters/setters
*****************************************************************************************/
void Bee::setHealth(int uHealth)
{
	health = uHealth;
}
int Bee::getHealth()
{
	return health;
}
char Bee::getFill()
{
	return fill;
}