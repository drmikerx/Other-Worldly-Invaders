/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the implementation file for the LightSwitch class. Please see
below for more details about the member functions defined here.
******************************************************************************************/


#include "LightSwitch.hpp"
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
** Description: The constructor calls on the base class constructor to initialize the
inherited member variables. It also sets the derived class member variable lightIsOn to
false. This variable is used to determine if the player has interacted with the light
switch yet.
*****************************************************************************************/

LightSwitch::LightSwitch() : Space()
{
	// Base class constructor sets up all inherited variables

	lightIsOn = false;		// Will get set to true if player turns on light
}


/*****************************************************************************************
** Description: turnLightsOn gets called once the player has used the light switch in this
room type. It sets the member variable lightIsOn to true so that the interaction
dialog does not appear after the lights are on.
*****************************************************************************************/

void LightSwitch::turnLightsOn()
{
	lightIsOn = true;
}


/*****************************************************************************************
** Description: getLightIsOn returns the current value of the lightIsOn variable. This
function will return either true or false.
*****************************************************************************************/

bool LightSwitch::getLightIsOn()
{
	return lightIsOn;
}


/*****************************************************************************************
** Description: This version of the printMessage function accepts a vector of strings
by reference. This vector represents the player inventory. Passing by reference allows
the function to add an item to the inventory if appropriate. First, the function checks
to see whether the player has interacted with this particular room before. If yes, a
message saying so is displayed. If no, the player is asked if they want to turn the light
on. Once player says yes to this, hasInteractedBefore becomes true and lightIsOn becomes
true. Once the light is on, the player is asked if they want to pick up the item on the
floor. Saying yes to this will add the item to the inventory if possible. Once this has
been accomplished, there is nothing more to do in this room.
*****************************************************************************************/

void LightSwitch::printMessage(vector<string> & inventory)
{
	if (this->getHasInteractedBefore() == false)
	{

		cout << "\nYou have entered a dark room but can make out what appears to be a light switch on the wall..." << endl;
		cout << "Would you like to use it?" << endl;

		cout << "\n1. Yes" << endl;
		cout << "2. No" << endl;

		string lightChoice;
		int lightChoiceValidated;

		getline(cin, lightChoice);

		while (lightChoice.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, lightChoice);
		}

		lightChoiceValidated = inputValidation1Or2(lightChoice);

		if (lightChoiceValidated == 1)	// Player has turned the lights on
		{
			this->turnLightsOn();
			this->changeHasInteractedBefore();		// Player has now interacted, so this choice will not appear again
		}

		if (this->lightIsOn)
		{
			cout << "\nNow that the lights are on, you see an item on the floor..." << endl;
			cout << "Would you like to pick it up? (it's not required to win)" << endl;

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
				cout << "\nIt's a copy of HG Wells' The War of the Worlds...that's not ironic at all..." << endl;
				cout << "It has been added to your inventory!" << endl;
				inventory.push_back("The War of the Worlds Book");
			}

			else if (itemChoiceValidated == 1 && inventory.size() == 5)
			{
				cout << "\nIt's a copy of HG Wells' The War of the Worlds...that's not ironic at all..." << endl;
				cout << "Sorry, your inventory is full! You'll have to leave the book here...poor you" << endl;
			}

			else
			{
				cout << "\nRight! You've ignored the item!" << endl;
			}
		}

		else
		{
			cout << "The room remains dark" << endl;
		}

	}

	else
	{
		cout << "You have done everything in this room" << endl;
	}
}