/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the implementation file for the Map class. Please see below for
details about the member functions defined here.
******************************************************************************************/


#include "Map.hpp"

#include <iostream>
using std::cout;
using std::endl;


/*****************************************************************************************
** Description: The constructor is responsible for setting the member variables for
playerRow and playerCol to 5 and 3 respectively. This means that the player will start
in the lower middle room by design choice. The function then begins making the map for 
the game including the line dividers. It then sets up the rooms as empty spaces and puts
an X on the goal and a * at the current player location.
*****************************************************************************************/

Map::Map()
{
	playerRow = 5;	// player starts in bottom middle room
	playerCol = 3;

	for (int row = 0; row < 7; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if (row == 0 || row == 2 || row == 4 || row == 6)
			{
				mapArray[row][col] = '-';
			}
		}
	}

	for (int row = 0; row < 7; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if (col == 0 || col == 2 || col == 4 || col == 6)
			{
				mapArray[row][col] = '|';
			}
		}
	}

	// empty spaces represent the rooms on the map

	mapArray[1][1] = ' ';
	mapArray[1][3] = ' ';
	mapArray[1][5] = ' ';
	mapArray[3][1] = ' ';
	mapArray[3][3] = 'X';	// This is the final destination
	mapArray[3][5] = ' ';
	mapArray[5][1] = ' ';
	mapArray[5][3] = '*';	// Player starts in bottom middle room
	mapArray[5][5] = ' ';

	// these were included so the map would appear square

	mapArray[0][0] = '-';
	mapArray[6][0] = '-';
	mapArray[0][2] = '-';
	mapArray[0][4] = '-';
	mapArray[0][6] = '-';
	mapArray[6][2] = '-';
	mapArray[6][4] = '-';
	mapArray[6][6] = '-';
	
}


/*****************************************************************************************
** Description: setPlayerRow is called after the player makes a move. It accepts an int
parameter that it uses to update the current row within the 2D array where the * will be
displayed.
*****************************************************************************************/

void Map::setPlayerRow(int updatedRow)
{
	playerRow = updatedRow;
}


/*****************************************************************************************
** Description: getPlayerRow returns the current value stored in the playerRow member
variable.
*****************************************************************************************/

int Map::getPlayerRow()
{
	return playerRow;
}


/*****************************************************************************************
** Description: setPlayerCol is called after the player makes a move. It accepts an int
parameter that it uses to update the current column within the 2D array where the * will 
be displayed.
*****************************************************************************************/

void Map::setPlayerCol(int updatedCol)
{
	playerCol = updatedCol;
}


/*****************************************************************************************
** Description: getPlayerCol returns the value currently stored in the playerCol member
variable.
*****************************************************************************************/

int Map::getPlayerCol()
{
	return playerCol;
}


/*****************************************************************************************
** Description: updateMap gets called each time the player makes a move. It accepts 4 ints
as arguments. The first is the current row of the array the player occupies, the second
is the current column of the array the player occupies, the third is the new row the
player will occupy after the move, and the fourth is the new column the player will
occupy after the move. It uses this data to change the old location to an empty space
and the new one to a '*'.
*****************************************************************************************/

void Map::updateMap(int originalRow, int originalCol, int updatedRow, int updatedCol)
{
	mapArray[originalRow][originalCol] = ' ';	// Player has left the room
	mapArray[updatedRow][updatedCol] = '*';	// Player now shows up in the new room
}


/*****************************************************************************************
** Description: printMap steps through each element of the array and prints the
character stored there. It is printed in such a way that a grid is displayed. It also
prints a legend so the player knows how to interpret the map. This function gets called
before and after every move.
*****************************************************************************************/

void Map::printMap()
{
	cout << "\n";

	for (int row = 0; row < 7; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			cout << mapArray[row][col] << " ";
		}

		cout << endl;
	}

	cout << "\nLegend: X is your goal destination. You are currently located in room marked *" << endl;
}