// Josiah Larimer
// COSC 2425
// Program Set 1
//

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;


// this is used in conjuction with the ersatzString[] int array
// simplifies some stuff down the line and a bit easier to work with then ascii
char numeral[17] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A','B', 'C', 'D', 'E', 'F', '.'};


// converts ascii char values to their equivalent numeral[] values
float charToFloat(char value){	
	if (int(value) > 47 && int(value) < 58)
		return (float(value) - 48);
	else if (int(value) > 64 && int(value) < 71)
		return (float(value) - 55);
	else if (int(value) == 46)
		return (17);

	return -666;
}


// the function called by main()
void rounder(string value, float baseOfValue,  int decimalPlaces) {
	
	float valueFloat = stof(value);
	int length = strlen(value.c_str());
	int* ersatzString = new int[length];

	// instantiates the ersatzString with values compatible with the numerals[] char array
	for (int j = 0; j < length; j++)
	{
		ersatzString[j] = charToFloat(value[j]);
	}
	
	// finds where the decimal place is
	char ch = '6';
	int i = 0;
	while (ch != '.')
	{
		ch = value[i];
		i++;
	}

	// the location of the thing to be rounded
	int ii = (i + decimalPlaces);
	float roundedThing = ersatzString[ii];

	int strlenS1 = strlen(value.c_str());
	int carry = 0;
	bool firstRound;

	// if the thing should be rounded up, round it up
	if ((roundedThing / baseOfValue) >= 0.5)
	{
		value[ii - 1] = (numeral[ersatzString[ii - 1] + 1]);
		ersatzString[ii - 1] += 1;
		firstRound = true;
		if (ersatzString[ii - 1] >= baseOfValue)
		{
			carry = 1;
			value[ii - 1] = '0';
			ersatzString[ii - 1] = 0;
		}
		else
			carry = 0;
	}

	// if the value in any element exceeds what is allowed by that base, carry the 1
	// it can't handle carrying stuff across the decimal point
	for (int k = 2; k < strlenS1 - ii + 2; k++)
	{
		if (carry == 1)
		{
			value[ii - k] = (numeral[ersatzString[ii - k] + 1]);
			ersatzString[ii - k] += 1;
			if (ersatzString[ii - k] >= baseOfValue)
			{
				carry = 1;
				value[ii - 1] = '0';
				ersatzString[ii - 1] = 0;
			}
			else
				carry = 0;
		}
	}

	// outputing the results
	cout << "The result in base " << baseOfValue << " : ";
	for (int iii = 0; iii < ii; iii++)
		cout << value[iii];	

	// deallocating the memory for ersatzString
	delete[] ersatzString;
}


int main() {

	bool cont = true;

	do
	{
		string value;
		float baseOfValue = 0;
		int decimalPlaces = 0;

		// getting input
		cout << endl << "Enter a value: ";
		cin >> value;

		cout<< "Enter the base of the value: ";
		cin >> baseOfValue;

		cout<< "Number of decimal places to round: ";
		cin >> decimalPlaces;
		cout << endl;

		// hands all the relevent data over to the rounder() function
		rounder(value, baseOfValue, decimalPlaces);


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