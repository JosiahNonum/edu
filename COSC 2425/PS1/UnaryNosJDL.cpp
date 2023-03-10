// Josiah Larimer
// COSC 2425
// Program Set 1
//

#include<iostream>

using namespace std;


int main() {

	bool cont = true;

	do
	{


		// getting input
		int userNumHold;
		cout << endl << "Enter a positive number: ";
		cin >> userNumHold;


		// Error Checking
		if (userNumHold > 80 || userNumHold < 1)
		{
			cout << "ERROR: please enter a positive interger between 1 and 80." << endl;
			continue;
		}


		// printing the result
		cout << endl << userNumHold << " in unary is: ";
		for (int i = 0; i < userNumHold - 1; i++)
			cout << '1';
		cout << '0';	// the trailing 0


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