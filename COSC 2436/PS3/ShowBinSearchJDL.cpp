// Josiah Larimer
// COSC 2436
// Programming set 3

#include<iostream>

using namespace std;


int main() {


	bool cont = true;


	do
	{

		int low = 1;
		bool found = false;

		// getting range from user
		int high;
		cout << endl << "Enter largest range value [1-100000]: ";
		cin >> high;

		// getting target from user
		int target;
		cout << "Enter search target: ";
		cin >> target;


		// error checking the input
		if (target < 1 || target > 100000)
		{
			cout << "ERROR: That was outside the range of acceptable inputs [1-100000]";
			return 1;
		}


		int mid = (low + high) / 2;

		cout << endl << low << "-" << mid << "-" << high;


		while (mid != target && low != high)
		{

			if (mid == target)
				;
			else if (target > mid)
				low = mid + 1;
			else if (target < mid)
				high = mid - 1;

			mid = (low + high) / 2;


			cout << endl << low << "-" << mid << "-" << high;

			if(mid == target)
			{
				found = true;
			}
			else if (low == high)
			{
				found = false;
			}
			
		}


		if (found == true)
			cout << endl << "GOT IT!" << endl;
		else if (found == false)
			cout << endl << "NOT GOT IT!" << endl;


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