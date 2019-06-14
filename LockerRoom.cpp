/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the implementation file for the LockerRoom class. Please see below
for details about the member functions defined here.
******************************************************************************************/


#include "LockerRoom.hpp"
#include "Space.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

int inputValidation1Or2(string dataToCheck);


/*****************************************************************************************
** Description: The constructor calls upon the base class constructor to initialize the
inherited member variables. It also sets the derived class specific member variable
lockerIsOpen to false. This variable is used to determine if the user has opened the
locker in this particular room yet.
*****************************************************************************************/

LockerRoom::LockerRoom() : Space()
{
	// Base class constructor sets up all inherited variables
	lockerIsOpen = false;
}


/*****************************************************************************************
** Description: setLockerToOpen gets called if the player decides to open the locker. It
sets the lockerIsOpen member variable to true.
*****************************************************************************************/

void LockerRoom::setLockerToOpen()
{
	lockerIsOpen = true;
}


/*****************************************************************************************
** Description: getLockerIsOpen returns the current value of the lockerIsOpen member
variable. It will either return true or false.
*****************************************************************************************/

bool LockerRoom::getLockerIsOpen()
{
	return lockerIsOpen;
}


/*****************************************************************************************
** Description: This version of the printMessage function accepts a vector of strings
by reference. This vector represents the player inventory. Passing by reference allows
the function to add an item to the inventory if appropriate. First, the function checks
to see whether the player has interacted with this particular room before. If yes, a
message saying so is displayed. If no, the player is asked if they want to open the 
locker. Once player says yes to this, hasInteractedBefore becomes true and lockerIsOpen 
becomes true. Once the locker is open, the player is asked if they want to pick up the 
item inside. Saying yes to this will add the item to the inventory if possible. Once 
this has been accomplished, there is nothing more to do in this room.
*****************************************************************************************/

void LockerRoom::printMessage(vector<string> & inventory)
{
	if (this->getHasInteractedBefore() == false)
	{

		cout << "\nYou have entered a room with what appears to be a locker..." << endl;
		cout << "Would you like to open it?" << endl;

		cout << "\n1. Yes" << endl;
		cout << "2. No" << endl;

		string lockerChoice;
		int lockerChoiceValidated;

		getline(cin, lockerChoice);

		while (lockerChoice.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, lockerChoice);
		}

		lockerChoiceValidated = inputValidation1Or2(lockerChoice);

		if (lockerChoiceValidated == 1)	// Player has opened the locker
		{
			this->setLockerToOpen();
			this->changeHasInteractedBefore();		// Player has now interacted, so this choice will not appear again
		}

		if (this->lockerIsOpen)
		{
			cout << "\nInside the locker you see an item..." << endl;
			cout << "Would you like to pick it up? (It's not required to win)" << endl;

			cout << "\n1. Yes" << endl;
			cout << "2. No" << endl;

			string itemChoice;
			int itemChoiceValidated;

			getline(cin, itemChoice);

			while (itemChoice.empty())
			{
				cout << "No data input. Try again." << endl;
				getline(cin, itemChoice);
			}

			itemChoiceValidated = inputValidation1Or2(itemChoice);

			// Can't have more than 4 items in the inventory
			if (itemChoiceValidated == 1 && inventory.size() < 5)
			{
				cout << "\nIt's the 19th century painting \"The Scream\" by Edvard Munch!" 
					<< " \nYou don't know what it's doing here, but that thing gets stolen a lot!" 
					<< "\nApparently these aliens are cultured conquerors!" << endl;
				cout << "It has been added to your inventory!" << endl;
				inventory.push_back("The Scream Painting");
			}

			else if (itemChoiceValidated == 1 && inventory.size() == 5)
			{
				cout << "\nIt's the 19th century painting \"The Scream\" by Edvard Munch!" 
					<< " \nYou don't know what it's doing here, but that thing gets stolen a lot!" 
					<< "\nApparently these aliens are cultured conquerors!" << endl;
				cout << "Sorry, your inventory is full! You'll have to leave the painting here...poor you" << endl;
			}

			else
			{
				cout << "\nRight! You've ignored the item!" << endl;
			}
		}

		else
		{
			cout << "\nThe locker remains closed" << endl;
		}

	}

	else
	{
		cout << "\nYou have done everything in this room" << endl;
	}
}