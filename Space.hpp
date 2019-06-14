/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the header file for the Space class. Space is the parent class of
all of the other room types in the game. It has 4 Space*'s so the rooms can be linked
together by their pointers. It also has a bool hasInteractedBefore that is present in all
derived classes, and it controls whether the player sees the room dialog (if player has
interacted with the room, then the dialog does not appear again). This is an abstract class
per program specifications because the printMessage function is pure virtual. The 
constructor sets all the Space*'s to nullptr at the beginning and sets the bool variable 
to false because the user has not interacted with the new rooms yet. Please see 
the implementation file for the details about the class member functions.
******************************************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP

enum Direction {Up, Down, Left, Right};

#include <vector>
#include <string>

class Space
{

private:
	Space* top;
	Space* right;
	Space* left;
	Space* bottom;

	bool hasInteractedBefore;

public:

	Space()
	{
		top = nullptr;
		right = nullptr;
		left = nullptr;
		bottom = nullptr;

		hasInteractedBefore = false;	// Will get set to true once player has interacted one time
	}

	void setTop(Space*);
	Space* getTop();

	void setRight(Space*);
	Space* getRight();

	void setLeft(Space*);
	Space* getLeft();

	void setBottom(Space*);
	Space* getBottom();

	void changeHasInteractedBefore();
	bool getHasInteractedBefore();

	Direction askForNextDirection();


	virtual void printMessage(std::vector<std::string> &) = 0;		// Pure virtual

};



#endif