/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the implementation file for the parent Space class. Please see
below for more details about the member functions defined here.
******************************************************************************************/


#include "Space.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

int inputValidationMovement(string dataToCheck);


/*****************************************************************************************
** Description: setTop accepts a Space* as an argument which it uses to update the value
of the top member variable.
*****************************************************************************************/

void Space::setTop(Space* topPtr)
{
	top = topPtr;
}


/*****************************************************************************************
** Description: getTop returns the current value stored in the top member variable.
*****************************************************************************************/

Space* Space::getTop()
{
	return top;
}


/*****************************************************************************************
** Description: setRight accepts a Space* as an argument which it uses to update the value
of the right member variable.
*****************************************************************************************/

void Space::setRight(Space* rightPtr)
{
	right = rightPtr;
}


/*****************************************************************************************
** Description: getRight returns the current value stored in the right member variable.
*****************************************************************************************/

Space* Space::getRight()
{
	return right;
}


/*****************************************************************************************
** Description: setLeft accepts a Space* as an argument which it uses to update the value
of the left member variable.
*****************************************************************************************/

void Space::setLeft(Space* leftPtr)
{
	left = leftPtr;
}


/*****************************************************************************************
** Description: getLeft returns the current value stored in the left member variable.
*****************************************************************************************/

Space* Space::getLeft()
{
	return left;
}


/*****************************************************************************************
** Description: setBottom accepts a Space* as an argument which it uses to update the value
of the bottom member variable.
*****************************************************************************************/

void Space::setBottom(Space* bottomPtr)
{
	bottom = bottomPtr;
}


/*****************************************************************************************
** Description: getBottom returns the current value stored in the bottom member variable.
*****************************************************************************************/

Space* Space::getBottom()
{
	return bottom;
}


/*****************************************************************************************
** Description: changeHasInteractedBefore gets called whenever the player interacts with
one of the rooms. It sets that room's instance of the hasInteractedBefore variable to 
true so that the prompts do not appear more than once.
*****************************************************************************************/

// This function will get called when user chooses to interact with the room successfully
void Space::changeHasInteractedBefore()
{
	hasInteractedBefore = true;
}


/*****************************************************************************************
** Description: getHasInteractedBefore returns the current value stored in the
hasInteractedBefore member variable. The function will return either true or false.
*****************************************************************************************/

bool Space::getHasInteractedBefore()
{
	return hasInteractedBefore;
}


/*****************************************************************************************
** Description: askForNextDirection gets called each turn after the player has chosen
whether to interact with their current room. It asks the player which direction they
want to travel. Depending on their answer a different enum value is returned to the
calling function for processing.
*****************************************************************************************/

Direction Space::askForNextDirection()
{
	cout << "\nYou are finished in this room. Which direction would you like to travel next?" << endl;
	cout << "\n1. Up" << endl;
	cout << "2. Down" << endl;
	cout << "3. Left" << endl;
	cout << "4. Right" << endl;

	string directionToMove;
	int directionToMoveValidated;

	getline(cin, directionToMove);
	
	while (directionToMove.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, directionToMove);
	}

	directionToMoveValidated = inputValidationMovement(directionToMove);

	if (directionToMoveValidated == 1)
	{
		return Up;
	}

	else if (directionToMoveValidated == 2)
	{
		return Down;
	}

	else if (directionToMoveValidated == 3)
	{
		return Left;
	}

	else if (directionToMoveValidated == 4)
	{
		return Right;
	}
}