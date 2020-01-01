/****************************************************************************************
functions for base space class
*****************************************************************************************/
#include "Space.hpp"

/****************************************************************************************
getters/setters
*****************************************************************************************/
void Space::setTop(Space *point)
{
	top = point;
}

void Space::setRight(Space *point)
{
	right = point;
}


Space * Space::getRight()
{
	return right;
}

Space * Space::getLeft()
{
	return left;
}

Space * Space::getTop()
{
	return top;
}

Space * Space::getBottom()
{
	return bottom;
}

void Space::setLeft(Space *point)
{
	left = point;
}

void Space::setBottom(Space *point)
{
	bottom = point;
}