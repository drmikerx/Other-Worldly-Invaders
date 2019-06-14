/******************************************************************************************
** Program name: Final Project - Other-Worldly Invaders
** Author: Michael Childress
** Date: 6/7/2018
** Description: This implementation file contains function definitions for the various
input validation functions used throughout the program. Please see below for more details.
******************************************************************************************/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::stoi;



/******************************************************************************************
** Description: inputValidation1Or2 is called anytime the final data
must be an integer and the final value should be 1 or 2. It accepts the user input as a
string, and first checks that something was actually entered. If not, the user is
re-prompted. It then checks that all characters entered are digits. If not, the user is
re-prompted. If they are all digits then the string is converted to an integer via stoi.
It is then checked to make sure it is in the appropriate range, and finally, is returned
to the calling function if everything is ok.
******************************************************************************************/

int inputValidation1Or2(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}


		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error, this was not a correct integer. It must be 1 or 2." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData < 1 || checkedData > 2)
			{
				cout << "Error, this integer was not in range. It must be 1 or 2." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;
}


/*****************************************************************************************
** Description: inputValidationMovement is called everytime the user selects which
direction to move. The final data must be an int and between 1 and 4. It accepts the 
user input as a string, and first checks that something was actually entered. If not, 
the user is re-prompted. It then checks that all characters entered are digits. If not, 
the user is re-prompted. If they are all digits then the string is converted to an 
integer via stoi. It is then checked to make sure it is in the appropriate range, and 
finally, is returned to the calling function if everything is ok.
*****************************************************************************************/

int inputValidationMovement(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}


		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error, this was not a correct integer. It must be between 1 and 4." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData < 1 || checkedData > 4)
			{
				cout << "Error, this integer was not in range. It must be between 1 and 4." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;
}


/*****************************************************************************************
** Description: inputValidationRiddleRoom is called when the user makes an answer 
selection in the riddle room. The final data must be an int and between 1 and 4. It 
accepts the user input as a string, and first checks that something was actually entered. 
If not, the user is re-prompted. It then checks that all characters entered are digits. 
If not, the user is re-prompted. If they are all digits then the string is converted to 
an integer via stoi. It is then checked to make sure it is in the appropriate range, and 
finally, is returned to the calling function if everything is ok.
*****************************************************************************************/

int inputValidationRiddleRoom(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}


		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error, this was not a correct integer. It must be between 1 and 4." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData < 1 || checkedData > 4)
			{
				cout << "Error, this integer was not in range. It must be between 1 and 4." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;
}