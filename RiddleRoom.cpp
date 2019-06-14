/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This is the implementation file for the RiddleRoom class. Please see below
for details about the member functions defined here.
******************************************************************************************/


#include "RiddleRoom.hpp"
#include "Space.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

int inputValidation1Or2(string dataToCheck);
int inputValidationRiddleRoom(string dataToCheck);

int RiddleRoom::riddleNumber = 1;	// This static member variable controls which riddle the user receives


/*****************************************************************************************
** Description: The constructor calls upon the base class constructor to initialize the
inherited member variables. It also sets the derived class specific variable
riddleIsAnswered to false. This variable is used to determine if the player has answered
the riddle in that particular room yet.
*****************************************************************************************/

RiddleRoom::RiddleRoom() : Space()
{
	// Base class constructor sets up all inherited variables
	riddleIsAnswered = false;
}


/*****************************************************************************************
** Description: setRiddleToAnswered gets called when the player answers the riddle
correctly. It sets the value of this member variable to true so the riddle is not asked
again.
*****************************************************************************************/

void RiddleRoom::setRiddleToAnswered()
{
	riddleIsAnswered = true;
}


/*****************************************************************************************
** Description: getRiddleIsAnswered returns the value currently stored in the
riddleIsAnwered member variable. The function will either return true or false.
*****************************************************************************************/

bool RiddleRoom::getRiddleIsAnswered()
{
	return riddleIsAnswered;
}


/*****************************************************************************************
** Description: increaseRiddleNumber is a static member function because it interacts
with only a static member variable. It gets called once when the player correctly
answers the first riddle. It increments the riddleNumber variable so that the next time
they encounter a riddle room, they get the second question.
*****************************************************************************************/

void RiddleRoom::increaseRiddleNumber()
{
	riddleNumber++;	// If riddle number becomes 2, player gets the second riddle variation in next riddle room
}


/*****************************************************************************************
** Description: This version of the printMessage function accepts a vector of strings
by reference that represents the player inventory. Passing by reference allows the
function to update the inventory if appropriate. It starts by checking whether the
player has already interacted with this room before. If yes, a message saying so is
displayed. If no, then they are asked if they want to answer a riddle. If they say yes
to this, then they are asked the riddle in a loop until they get the correct answer.
The question asked is dependant on the current value of the riddleNumber static variable.
Once the question is answered correctly, a weapon room key is added to the inventory, and
the hasInteractedBefore variable becomes true.
*****************************************************************************************/

void RiddleRoom::printMessage(vector<string> & inventory)
{
	if (this->getHasInteractedBefore() == false)
	{

		cout << "\nA computer screen lights up in this new room it says: Welcome to a riddle room! " << endl;
		cout << "Answer my question and get a weapon room key! Would you like to try?" << endl;

		cout << "\n1. Yes" << endl;
		cout << "2. No" << endl;

		string riddleChoice;
		int riddleChoiceValidated;

		getline(cin, riddleChoice);

		while (riddleChoice.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, riddleChoice);
		}

		riddleChoiceValidated = inputValidation1Or2(riddleChoice);

		if (riddleChoiceValidated == 1)	// Player is asked the question
		{
			bool answeredCorrectly = false;

			if (riddleNumber == 1)	// Player gets first riddle variation
			{
				do
				{

					cout << "\nOh brave human! My first riddle is this..." << endl;
					cout << "\nWhich one of these characters was once known as Jump Man?" << endl;
					cout << "1. Sonic the Hedgehog" << endl;
					cout << "2. Mario" << endl;
					cout << "3. Mega Man" << endl;
					cout << "4. None of these" << endl;

					string answerChoice;
					int answerChoiceValidated;

					getline(cin, answerChoice);

					while (answerChoice.empty())
					{
						cout << "No data input. Try again." << endl;
						getline(cin, answerChoice);
					}

					answerChoiceValidated = inputValidationRiddleRoom(answerChoice);

					if (answerChoiceValidated == 2)	// Got it right
					{
						cout << "\nOh that one was too easy. As promised here is your key..." << endl;
						answeredCorrectly = true;	// end the do while loop
						cout << "\nRed Weapon Room Key added to inventory!" << endl;
						inventory[0] = "Red Weapon Room Key";	// Red Key is always position 0 by design choice
					}

					else
					{
						cout << "\nNope! You need to try again!" << endl;
					}

				} while (!answeredCorrectly);

				this->setRiddleToAnswered();	// This particular room won't ask another riddle
				this->changeHasInteractedBefore();		// Player has now interacted, so this choice will not appear again
				increaseRiddleNumber();	// Next time they'll get the second variation
			}

			else if (riddleNumber == 2)	// They get second variation now
			{
				do
				{
					cout << "\nOh...it's you again... Well there's no way you'll get two "
						<< "in a row...My second riddle is this..." << endl;
					cout << "\nWhat language are my higher functions programmed in?" << endl;
					cout << "1. Subspace Python" << endl;
					cout << "2. Jupiter Java" << endl;
					cout << "3. Intergalactic C++" << endl;
					cout << "4. None of these" << endl;

					string answerChoice;
					int answerChoiceValidated;

					getline(cin, answerChoice);

					while (answerChoice.empty())
					{
						cout << "No data input. Try again." << endl;
						getline(cin, answerChoice);
					}

					answerChoiceValidated = inputValidationRiddleRoom(answerChoice);

					if (answerChoiceValidated == 3)	// Got it right
					{
						cout << "\n...I don't believe it...I'll be decommissioned for sure..."
							<< "Well, as promised here is your second key..." << endl;
						answeredCorrectly = true;	// end the do while loop
						cout << "\nBlue Weapon Room Key added to inventory! Now go open the final door!" << endl;
						inventory[1] = "Blue Weapon Room Key";	// Blue Key is always position 1 by design
					}

					else
					{
						cout << "\nNope! You need to try again!" << endl;
					}

				} while (!answeredCorrectly);

				this->setRiddleToAnswered();	// This particular room won't ask another riddle
				this->changeHasInteractedBefore();		// Player has now interacted, so this choice will not appear again
			}
		}

		else
		{
			// They don't want to be asked a question
			cout << "Well fine then, no key for you!" << endl;
		}
	}

	else
	{
		cout << "\nYou have done everything in this room" << endl;
	}
}