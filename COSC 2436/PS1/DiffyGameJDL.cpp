// Josiah Larimer
// COSC 2436
// Program Set 1

#include<iostream>

using namespace std;


int main() {

	bool cont = false;

	do
	{

		// user inputs the initial values
		int intHolder[4];
		cout << endl << "Enter 4 integer numbers clockwise: ";

		for (int i = 0; i < 4; i++)
		{
			cin >> intHolder[i];
		}

		cout << endl << "The values for each of the corners: " << endl << endl;


		bool contMath = true;	// whether to continue the inside do while loop
		int a = 0, b = 0, c = 0, d = 0;
		int stepsIterator = 0;	// counts how many steps it took to finish the square

		do
		{

			// stand in variables to temprarily hold values so I can modify the original intHolder[] values
			a = intHolder[0];
			b = intHolder[1];
			c = intHolder[2];
			d = intHolder[3];

			// this and the following if else statements assign the greater of the difference between the two adjacent values
				if (a > b)
					intHolder[0] = (a - b);
				else
					intHolder[0] = (b - a);
						
				if (a > b)
					intHolder[1] = (b - c);
				else
					intHolder[1] = (c - b);
						
				if (c > d)
					intHolder[2] = (c - d);
				else
					intHolder[2] = (d - c);
						
				if (d > a)
					intHolder[3] = (d - a);
				else
					intHolder[3] = (a - d);
			

			// tests whether each value is negative, and if it is, makes it positive
			for (int i = 0; i < 4; i++)
			{
				if (intHolder[i] < 0)
					intHolder[i] = (intHolder[i] + (2 * (-intHolder[i])));
			}


			// ends the inner do while loop if all the values are 0
			if (intHolder[0] == 0 && intHolder[1] == 0 && intHolder[2] == 0 && intHolder[3] == 0)
				contMath = false;


			// keeps track of how many steps it has been
			stepsIterator++;


			// outputs the latest round of values
			for (int i = 0; i < 4; i++)
			{
				cout << intHolder[i] << " ";
			}

			cout << endl;


		} while (contMath == true);	// tests whether to continue inner do while loop


		// letting the user know the results

		cout << endl << "Number of steps: " << stepsIterator;

		// asking the user whether they want to go again or not
		char contHold;
		cout << endl << endl << "Run Again (Y/N): ";
		cin >> contHold;

		if (contHold == 'y' || contHold == 'Y')
			cont = true;
		else
			cont = false;

	} while (cont == true);		// tests whether to continue outer do while loop

}