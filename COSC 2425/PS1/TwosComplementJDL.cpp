// Josiah Larimer
// COSC 2425
// Program Set 1
//
// I figured out how to do the binary conversion and addition from the Null and Lobur powerpoints

#include<iostream>

using namespace std;


// converts positive decimal to positive binary
string toBinary(int n) {
	string r;
	if (n == 0) return "0";
	while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
	return r;
}


// ninth tenths converting a positive binary number to a twos complement negative binary number
// basically ones complement, just missing the +1 for twos complement
string toBinaryNegative(string s) {
	if (s == "1") return "0";
	else
	{
		string newStr;
		for (int i = 0; i < strlen(s.c_str()); i++)
		{
			if (s[i] == '1')
				newStr += '0';
			else if (s[i] == '0')
				newStr += '1';
		}
		return newStr;
	}
}


// adds 1 in order to go from 1s complement to 2s complement
string binaryAdding(string s1) {

	int strlenS1 = strlen(s1.c_str());
	int carry = 1;

	for (int i = strlenS1 - 1; i >= 0; i--)
	{
		if (s1[i] == '0' && carry == 0)
		{
			return s1;
		}
		else if ((s1[i] == '0' && carry == 1) || (s1[i] == '1' && carry == 0))
		{
			s1[i] = '1';
			carry = 0;
			return s1;
		}		
		else if (s1[i] == '1' && carry == 1)
		{
			s1[i] = '0';
			carry = 1;
		}
	}
}


// basically just calls the different functions, with some logic to decide which functions to call
int main() {

	bool cont = true;

	do
	{
		// getting input
		int userNumHold;
		cout << endl << "Enter a value: ";
		cin >> userNumHold;
		cout << endl << endl << userNumHold << " = ";

		// Error Checking
		if (userNumHold > 127 || userNumHold < -128)
		{ 
			cout << "ERROR: please enter a value between -128 and 127." << endl;
			return 2;
		}

		// converting
		if (userNumHold >= 0)	// if the number to be converted is positive
		{
			string posBinary = toBinary(userNumHold);

			for (int i = 0; i < (8 - strlen(posBinary.c_str())) ; i++)
			{
				cout << '0';
			}
			cout << posBinary;
		}
		else				   // if the number to be converted is negative
		{
			string negBinHold = toBinaryNegative(toBinary(abs(userNumHold)));	
			negBinHold = binaryAdding(negBinHold);
			for (int i = 0; i < (8 - strlen(negBinHold.c_str())); i++)
			{
				cout << '1';
			}
			cout << negBinHold;
		}
			
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