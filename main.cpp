/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the main function for the program. It starts by displaying the
welcome message and waits for the user to press enter to begin the game. After this,
control is turned over to the runGame function.
******************************************************************************************/


#include "Map.hpp"
#include "Space.hpp"
#include "LightSwitch.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void runGame();

int main()
{
	cout << "Welcome to Other-Worldly Invaders! \n\nYou are John Doe and have secretly boarded an alien"
		<< " space station." << endl;
	cout << "\nAliens are trying to destroy Earth and will fire a devastating weapon in 15 minutes "
		<< "unless you can stop them!" << endl;
	cout << "Find the two keys located in the station to unlock the central weapon room" 
		<< " (marked with an X) to stop the count down!" << endl;
	cout << "\n\nPress enter to begin when you are ready...";
	cin.get();


	runGame();
	
	return 0;
}