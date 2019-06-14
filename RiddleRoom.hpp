/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the header file for the RiddleRoom class. This is a derived class
of the Space class. Beyond the inherited member variables from Space, it has a bool
called riddleIsAnswered and a static int called riddleNumber. This static variable needs
to maintain its value among all of the RiddleRoom objects so the program can keep record
of the fact that the player might already have answered a question. There are two variations
of the dialog for this room that are controlled by this variable's value. Please see the
implementation file for the details about the class member functions.
******************************************************************************************/


#ifndef RIDDLEROOM_HPP
#define RIDDLEROOM_HPP

#include "Space.hpp"
#include <vector>
#include <string>

class RiddleRoom : public Space
{
private:
	bool riddleIsAnswered;
	static int riddleNumber;	// Need this value to be maintained over all instances of the class

public:
	RiddleRoom();

	void setRiddleToAnswered();

	bool getRiddleIsAnswered();

	static void increaseRiddleNumber();		// This function only interacts with static member variable

	void printMessage(std::vector<std::string> &);


};


#endif