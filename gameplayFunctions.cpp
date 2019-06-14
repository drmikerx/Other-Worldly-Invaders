/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This implementation file contains function definitions for the various
game play functions used by the program. Please see below for more details.
******************************************************************************************/


#include "Space.hpp"
#include "LightSwitch.hpp"
#include "LockerRoom.hpp"
#include "RiddleRoom.hpp"
#include "FinalRoom.hpp"
#include "Map.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;


/*****************************************************************************************
** Description: printInventory is called each time the player moves to a new room. It
accepts the vector of strings (player inventory) by value and simply displays all of the
contents of the vector on the screen. To display the number of slots still open in the
inventory, it uses size() - 2 because the first two positions are reserved for the two
required keys to open the final door.
*****************************************************************************************/

void printInventory(vector<string> playerInventory)
{
	// The first two slots of the inventory are reserved for the required weapon room keys
	cout << "\nYou are currently using " << playerInventory.size() - 2 << " of 3 optional "
		<< "spots in your inventory." << endl;
	cout << "\nYour inventory currently contains..." << endl;

	for (int index = 0; index < playerInventory.size(); index++)	// By design choice there are 5 slots in inventory
	{
		cout << playerInventory[index] << endl;
	}

	cout << endl;
}


/*****************************************************************************************
** Description: runGame is the primary function for the program. It is responsible for
instantiating and linking together all rooms of the map. It also puts the player into
the starting room, and initializes the player inventory. Once everything is set up, a
for loop is run for 15 times (if necessary) to represent the 15 minutes before weapon
firing. Each round, the map, inventory, timer, and specific room message are printed to
the screen. The player is then asked which direction to move and their input is validated
to make sure the character does not move out of bounds or into the locked room. If player 
reaches the center room, they win, and a bool gets set to true, which ends the for loop 
and causes the game to end.
*****************************************************************************************/

void runGame()
{
	// Create the game world by making rooms and linking them together via their Space*'s

	// Instantiate all rooms

	LightSwitch roomA;
	RiddleRoom roomB;
	LightSwitch roomC;
	LockerRoom roomD;
	LightSwitch roomE;
	RiddleRoom roomF;
	LightSwitch roomG;
	LockerRoom roomH;
	FinalRoom roomX;

	Direction wayToMove;

	Space* playerRoom = &roomA;		// Player starts in roomA

	vector<string> playerInventory;

	playerInventory.push_back("You still need to collect the Red Weapon Room Key");
	playerInventory.push_back("You still need to collect the Blue Weapon Room Key");

	// Link all rooms together

	roomA.setLeft(&roomB);
	roomA.setRight(&roomH);
	roomA.setTop(&roomX);

	roomB.setTop(&roomC);
	roomB.setRight(&roomA);

	roomC.setTop(&roomD);
	roomC.setRight(&roomX);
	roomC.setBottom(&roomB);

	roomD.setBottom(&roomC);
	roomD.setRight(&roomE);

	roomE.setLeft(&roomD);
	roomE.setBottom(&roomX);
	roomE.setRight(&roomF);

	roomF.setLeft(&roomE);
	roomF.setBottom(&roomG);

	roomG.setTop(&roomF);
	roomG.setLeft(&roomX);
	roomG.setBottom(&roomH);

	roomH.setTop(&roomG);
	roomH.setLeft(&roomA);

	roomX.setTop(&roomE);
	roomX.setLeft(&roomC);
	roomX.setBottom(&roomA);
	roomX.setRight(&roomG);


	Map gameMap;
	int originalRow;
	int originalCol;

	bool hasWon = false;	// gets set to true once player enters the central room


	for (int count = 15; count > 0; count--)
	{
		if (hasWon == false)	// If player wins this should no longer occur
		{
			gameMap.printMap();
			printInventory(playerInventory);
			cout << "The weapon will fire in " << count << " minutes!" << endl;
			playerRoom->printMessage(playerInventory);
			cout << "\nPlease press enter to continue...";
			cin.get();
			gameMap.printMap();

			bool validMove = false;		// protects playerRoom from becoming nullptr / seg faults

			do
			{
				wayToMove = playerRoom->askForNextDirection();

				// Keep the central room locked until player collects the room keys

				if (wayToMove == Up && gameMap.getPlayerRow() == 5 && gameMap.getPlayerCol() == 3 &&
					(playerInventory[0] != "Red Weapon Room Key" || playerInventory[1] != "Blue Weapon Room Key"))
				{
					cout << "\nYou don't have the required keys to access that room yet!" << endl;
				}

				else if (wayToMove == Down && gameMap.getPlayerRow() == 1 && gameMap.getPlayerCol() == 3 &&
					(playerInventory[0] != "Red Weapon Room Key" || playerInventory[1] != "Blue Weapon Room Key"))
				{
					cout << "\nYou don't have the required keys to access that room yet!" << endl;
				}

				else if (wayToMove == Left && gameMap.getPlayerRow() == 3 && gameMap.getPlayerCol() == 5 &&
					(playerInventory[0] != "Red Weapon Room Key" || playerInventory[1] != "Blue Weapon Room Key"))
				{
					cout << "\nYou don't have the required keys to access that room yet!" << endl;
				}

				else if (wayToMove == Right && gameMap.getPlayerRow() == 3 && gameMap.getPlayerCol() == 1 &&
					(playerInventory[0] != "Red Weapon Room Key" || playerInventory[1] != "Blue Weapon Room Key"))
				{
					cout << "\nYou don't have the required keys to access that room yet!" << endl;
				}

				else if (wayToMove == Up)
				{
					if (playerRoom->getTop() != nullptr)
					{
						playerRoom = playerRoom->getTop();

						originalRow = gameMap.getPlayerRow();
						originalCol = gameMap.getPlayerCol();

						gameMap.updateMap(originalRow, originalCol, originalRow - 2, originalCol);	// * moves up a room

						gameMap.setPlayerRow(originalRow - 2);

						validMove = true;	// Will allow do-while loop to end
					}
				}

				else if (wayToMove == Down)
				{
					if (playerRoom->getBottom() != nullptr)
					{
						playerRoom = playerRoom->getBottom();

						originalRow = gameMap.getPlayerRow();
						originalCol = gameMap.getPlayerCol();

						gameMap.updateMap(originalRow, originalCol, originalRow + 2, originalCol);	// * moves down a room

						gameMap.setPlayerRow(originalRow + 2);

						validMove = true;
					}
				}

				else if (wayToMove == Left)
				{
					if (playerRoom->getLeft() != nullptr)
					{
						playerRoom = playerRoom->getLeft();

						originalRow = gameMap.getPlayerRow();
						originalCol = gameMap.getPlayerCol();

						gameMap.updateMap(originalRow, originalCol, originalRow, originalCol - 2);	// * moves left a room

						gameMap.setPlayerCol(originalCol - 2);

						validMove = true;
					}
				}

				else if (wayToMove == Right)
				{
					if (playerRoom->getRight() != nullptr)
					{
						playerRoom = playerRoom->getRight();

						originalRow = gameMap.getPlayerRow();
						originalCol = gameMap.getPlayerCol();

						gameMap.updateMap(originalRow, originalCol, originalRow, originalCol + 2);	// * moves right a room

						gameMap.setPlayerCol(originalCol + 2);

						validMove = true;
					}
				}

				if (validMove == false)
				{
					cout << "You can't move that way try again!" << endl;
				}

				// If this point reached while count was 1, the player has lost
				if (count == 1)
				{
					cout << "\nUh oh the planet has been destroyed...needless to say, it's Game Over!" << endl;
				}

			} while (validMove == false);

			if (gameMap.getPlayerRow() == 3 && gameMap.getPlayerCol() == 3 && hasWon == false)
			{
				hasWon = true;	// If player has reached the central room they've won the game
				
				// Display the room gameplay options one last time
				gameMap.printMap();
				printInventory(playerInventory);
				cout << "The weapon will fire in " << count << " minutes!" << endl;
				playerRoom->printMessage(playerInventory);
			}

		}
	}

	



}