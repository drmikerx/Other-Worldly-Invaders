/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the header file for the LightSwitch class. It is a derived class
from the Space class. Beyond the inherited variables and functions from Space, it has a
bool variable called lightIsOn, its own constructor, functions that deal with the derived
bool variable, and an overloaded version of the printMessage function.
******************************************************************************************/


#ifndef LIGHTSWITCH_HPP
#define LIGHTSWITCH_HPP

#include "Space.hpp"
#include <vector>
#include <string>

class LightSwitch : public Space
{
private:
	bool lightIsOn;

public:
	LightSwitch();		// Will call base class constructor

	void turnLightsOn();
	bool getLightIsOn();

	void printMessage(std::vector<std::string> &);

};


#endif