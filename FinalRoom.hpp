/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the header file for the FinalRoom class. It is a derived class
from the Space class. There are no new variables beyond the inherited ones in this class.
It has a constructor (that uses the base class constructor) and an overloaded version of
the printMessage function that is used to display end game dialog. This class represents
the goal weapon room of the game.
******************************************************************************************/


#ifndef FINALROOM_HPP
#define FINALROOM_HPP

#include "Space.hpp"
#include <vector>
#include <string>

class FinalRoom : public Space
{
private:


public:
	FinalRoom();

	void printMessage(std::vector<std::string> &);

};


#endif