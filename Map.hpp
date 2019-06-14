/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the header file for the Map class. It serves as the map to
display the current location of the player in the game. It consists of a 2D array of
characters, and has int variables to store the player's current row and column within the
array. Please see the implementation file for details about the class member functions.
******************************************************************************************/


#ifndef MAP_HPP
#define MAP_HPP

class Map
{

private:
	char mapArray[7][7];		// 2D array represents the map grid, there will be 9 playable rooms
	int playerRow;
	int playerCol;

public:
	Map();		// Constructor

	void setPlayerRow(int);
	int getPlayerRow();

	void setPlayerCol(int);
	int getPlayerCol();

	void updateMap(int, int, int, int);

	void printMap();

};



#endif