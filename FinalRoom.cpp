/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the implementation file for the FinalRoom class. Please see below
for details about the member functions defined here.
******************************************************************************************/


#include "FinalRoom.hpp"
#include "Space.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;


/*****************************************************************************************
** Description: The constructor uses the base class constructor to initialize all of the
member variables.
*****************************************************************************************/

FinalRoom::FinalRoom() : Space()
{
	// Base class constructor sets up all inherited variables
}


/*****************************************************************************************
** Description: This version of the printMessage function accepts the vector of strings
(player inventory) by reference. This particular derived class does not have any items
to add. Once the player has reached this room, they have won the game. This function
simply displays the end game dialog on the screen.
*****************************************************************************************/

void FinalRoom::printMessage(vector<string> & inventory)
{
	cout << "\nOh my...see I just knew you'd come in here. It's me, the riddle bot. Please just turn around now." << endl;
	cout << "\nPress enter to take a step forward...";
	cin.get();

	cout << "\nFine, fine, go ahead and walk up to the console and press the off button. See if I care!" << endl;
	cout << "\nPress enter to press the off button...";
	cin.get();

	cout << "\nHow rude! Well congratulations you've saved your planet! I'll end up in the scrap heap, but whatever!" << endl;
	cout << "\nI'm obligated to inform you that your adventure is now complete, thanks for playing!" << endl;
}