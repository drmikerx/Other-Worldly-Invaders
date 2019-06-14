/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the header file for the LockerRoom class. It is a derived class
from the Space class. Beyond the variables and functions inherited from Space, it has a
bool variable called lockerIsOpen, it's own constructor, functions that deal with the
derived class bool variable, and an overloaded version of the printMessage function.
******************************************************************************************/


#ifndef LOCKERROOM_HPP
#define LOCKERROOM_HPP

#include "Space.hpp"
#include <vector>
#include <string>

class LockerRoom : public Space
{
private:
	bool lockerIsOpen;

public:
	LockerRoom();

	void setLockerToOpen();

	bool getLockerIsOpen();

	void printMessage(std::vector<std::string> &);

};

#endif