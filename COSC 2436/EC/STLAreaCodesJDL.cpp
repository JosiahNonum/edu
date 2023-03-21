// Josiah Larimer
// COSC 2436
// Quiz 2 extra credit
// 
//
// I found this to allow me to print from the map using only a partial key match
// https://stackoverflow.com/questions/9349797/partial-match-for-the-key-of-a-stdmap
// specifically, I used a modification of honk's code snippet,
//	"for (auto it = myMap.lower_bound(prefix); it != std::end(myMap) && it->first.compare(0, prefix.size(), prefix) == 0; ++it)
//		 std::cout << it->first << ": " << it->second << std::endl;"
//

#include<iostream>
#include<fstream>
#include<string>
#include<map>


using namespace std;


int main() {


	bool cont = true;

	// getting the filename from the user
	string filename;
	cout << endl << "Enter file name: ";
	cin >> filename;

	// opening file
	fstream fin(filename, fstream::in);

	// dumping the file's data into a map
	// one map has the area codes as the key, and the other map has the state/province names as the key
	string hold;
	multimap<string, string> areaCodesStates;
	multimap<string, string> areaCodesNumbers;
	while (getline(fin, hold))
	{
		string areaCode = "666";

		// copying over the area code
		areaCode[0] = hold[0];
		areaCode[1] = hold[1];
		areaCode[2] = hold[2];

		// copying over the state/provincial name
		// I couldn't think of a way to do the state names better than this, unless I were to use a c style string or something similar
		// due to the way this works, there is a bunch of whitespaces which hang out at the end of the stateName string
		string stateName = "                                        ";
		for (int i = 4; i < strlen(hold.c_str()); i++)
		{
			stateName[i - 4] = hold[i];
		}

		stateName[strlen(hold.c_str()) - 3] = '\0';

		areaCodesStates.emplace(areaCode, stateName);
		areaCodesNumbers.emplace(stateName, areaCode);
	}


	do
	{
		// asking what the user wants to look up
		string ch2;
		cout << endl << "Enter area code or state/provincial name: ";
		cin >> ch2;
		cout << endl;

		
		// retreiving and printing the requested data
		if (ch2[0] > '0' && ch2[0] <= '9')
		{
			for (auto it = areaCodesStates.lower_bound(ch2); it != end(areaCodesStates) && it->first.compare(0, ch2.size(), ch2) == 0; ++it)
				cout << it->second << endl;
		}
		else
		{
			for (auto it = areaCodesNumbers.lower_bound(ch2); it != end(areaCodesNumbers) && it->first.compare(0, ch2.size(), ch2) == 0; ++it)
				cout << it->second << endl;
		}


		// asking the user whether they want to go again or not
		char contHold;
		cout << endl << "Run Again (Y/N): ";
		cin >> contHold;

		if (contHold == 'y' || contHold == 'Y')
			cont = true;
		else
			cont = false;

	} while (cont == true);		// tests whether to continue outer do while loop

	// closing the file
	fin.close();

}