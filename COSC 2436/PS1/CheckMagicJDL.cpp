// Josiah Larimer
// COSC 2436
// Program Set 1

#include<iostream>

using namespace std;


int main() {


	int hold[9];	// an array that holds the values inputed by the user
	bool r1 = false, r2 = false, r3 = false, c1 = false, c2 = false, c3 = false, d1 = false, d2 = false; // a value for each feature of the square
	bool cont = false;	// use for the do while continue? (Y/N) loop


	do {

		// user input
		cout << endl << "Enter the 3 by 3 magic square: ";

		// fills the array
		for (int i = 0; i < 9; i++)
		{
			cin >> hold[i];
		}

		// chunk of if statements that check whether a row, column, or diagonal add up to 15
		if ((hold[0] + hold[1] + hold[2]) == 15)
			r1 = true;
		else
			r1 = false;

		if ((hold[3] + hold[4] + hold[5]) == 15)
			r2 = true;
		else
			r2 = false;

		if ((hold[6] + hold[7] + hold[8]) == 15)
			r3 = true;
		else
			r3 = false;

		if ((hold[0] + hold[3] + hold[6]) == 15)
			c1 = true;
		else
			c1 = false;

		if ((hold[1] + hold[4] + hold[7]) == 15)
			c2 = true;
		else
			c2 = false;

		if ((hold[2] + hold[5] + hold[8]) == 15)
			c3 = true;
		else
			c3 = false;

		if ((hold[0] + hold[4] + hold[8]) == 15)
			d1 = true;
		else
			d1 = false;

		if ((hold[2] + hold[4] + hold[6]) == 15)
			d2 = true;
		else
			d2 = false;


		// output
		cout << endl << "Magic Square: " << endl << endl;

		
		// displays the square
		for (int i = 0; i < 9; i++)
		{
			if (i == 3 || i == 6)
			{
				cout << endl << hold[i] << " ";
			}
			else
				cout << hold[i] << " ";

		}

		cout << endl << endl << "Missing: ";

		// checks which, if any, features do not add up to 15
		if (r1 != true)
			cout << "R1 ";
		if (r2 != true)
			cout << "R2 ";
		if (r3 != true)
			cout << "R3 ";
		if (c1 != true)
			cout << "C1 ";
		if (c2 != true)
			cout << "C2 ";
		if (c3 != true)
			cout << "C3 ";
		if (d1 != true)
			cout << "D1 ";
		if (d2 != true)
			cout << "D2 ";
		if (r1 == true && r2 == true && r3 == true && c1 == true && c2 == true && c3 == true && r1 == true && r2 == true)
			cout << "NONE";

		// asks the user whether they want to continue
		char contHold;
		cout << endl << endl << "Run Again (Y/N): ";
		cin >> contHold;

		if (contHold == 'y' || contHold == 'Y')
			cont = true;
		else
			cont = false;

	} while (cont == true);

}
