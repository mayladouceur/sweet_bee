/****************************************************************************************
Name: May LaDouceur
Date: 6/11/19
Description: menus function contains several menus for the game as well as validation function
*****************************************************************************************/
#include "Menus.hpp"
#include "Backpack.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

/****************************************************************************************
menu function asks what user wants to do before turn
*****************************************************************************************/
int Menus::menuTakeTurn()
{
	int choice;
	string unvalidated;
	do {
		cout << "Please choose one of the following " << endl << "1.) Move bee to a new space";
		cout << endl << "2.) Use and edit items" << endl << "3.) Quit game" << endl;
		cin >> unvalidated;
		choice = validation(unvalidated);
	} while (choice < 1 || choice > 3);
	return choice;
}
/****************************************************************************************
menu backpack function is for editing items in the backpack 
*****************************************************************************************/
int Menus::menuBackpack(Backpack *pack)
{
	int choice;
	string unvalidated;
	bool found = false;
	do {
		cout << "Would you like to use an item or delete an item?" << endl;
		cout << "1.) Use antidote" << endl << "2.) Delete item" << endl;
		cin >> unvalidated;
		choice = validation(unvalidated);
		//need to check and make sure don't have 5 items already
	} while (choice < 1 || choice > 2);
	if (choice == 1)
	{
		//if user wants to use antidote, need to make sure you have it
		found = pack->searchList("antidote");
		if (found == true)
		{
			pack->useAntidote();
		}
	}
	// if they want to delete items and items exist
	else if (choice == 2 && pack->getBackpack().empty() == false)
	{
		pack->editItems();
	}
	return choice;
}
/****************************************************************************************
simple yes/no menu used multiple times
*****************************************************************************************/
int Menus::menuYesNo()
{
	int choice;
	string unvalidated;
	do {
		cout << "1.) Yes" << endl << "2.) No" << endl;
		cin >> unvalidated;
		choice = validation(unvalidated);
		//need to check and make sure don't have 5 items already
	} while (choice < 1 || choice > 2);
	return choice;
}
/****************************************************************************************
validation function returns -1 if user chooses a number that is not an int
*****************************************************************************************/
int Menus::validation(string unvalidated)
{
	{
		int validated = 0;
		int length = unvalidated.length();
		//create dynamically allocated array of ints
		int *len;
		len = new int[length];
		//if input starts with a negative symbol, do the following
		if (unvalidated[0] == '-')
		{
			//if the next thing after the negative sign is a digit, then convert the string to an int
			for (int i = 1; i < length; i++)
			{
				if (isdigit(unvalidated[i]))
				{
					len[i] = unvalidated[i] - '0';
					validated = unvalidated[i];
				}
				else
				{
					validated = -1;
					return validated;
				}
			}
			{
				//convery the array of negative integers into an integer (i.e. if more than one digit)
				//citation stackoverflow.com/questions/19599364/how-to-convert-array-of-integers-into-an-integer-in-c/19599419
				int i, k = 0;
				for (i = 1; i < length; i++)
					k = 10 * k + len[i];
				validated = k - (2 * k);
			}
		}
		//if iniput starts with a number, do the following
		else if (isdigit(unvalidated[0]))
		{
			//citation: stackoverflow.com/questions/43697363/how-can-i-convert-char-to-int-in-c-to-get-correct-values-of-numbers
			for (int i = 0; i < length; i++)
			{
				//convert the string into an int, used in lab1
				if (isdigit(unvalidated[i]))
				{
					len[i] = unvalidated[i] - '0';
					validated = unvalidated[i];
				}
				else
				{
					validated = -1;
					return validated;
				}
			}
			//convery the array of integers into an integer (i.e. if more than one digit)
			int i, k = 0;
			for (i = 0; i < length; i++)
			{
				k = 10 * k + len[i];
			}
			validated = k;
		}
		//if input does not start with a number or negative sign, return -1 
		else
		{
			validated = -1;
		}
		//deallocate pointer to the array
		delete[] len;
		return validated;
	}
}
