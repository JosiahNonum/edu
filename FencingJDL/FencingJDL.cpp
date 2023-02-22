// Josiah Larimer
// COSC 2436
// Programming Set 1
// 

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main() {

	int numberOfCases = 0;		// how many cases are to be computed
	string numberOfCasesString;	// holds the string values of cases

	// getting filename from the user
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;

	// opening file
	string ch;
	fstream fin(filename, fstream::in);

	// getting how many cases there are from the file
	getline(fin, numberOfCasesString);
	numberOfCases = stoi(numberOfCasesString);

	// this runs once for each case there is
	for (int i = 0; i < numberOfCases; i++)
	{

		// getting the number of rows and columns
		string rowsColumns;
		getline(fin, rowsColumns);

		int rows, columns;

		rows = int(rowsColumns[0] - 48);
		columns = int(rowsColumns[2] - 48);

		bool firstRowFound = false;
		int rowsToBeFenced = 0, firstRow = 0, lastRow = 0;
		int ColumnsToBeFenced = 0;
		string hold;

		int firstColumn = 9999, lastColumn = 0;

		// runs once for each row there is
		for (int r = 0; r < rows; r++)
		{

			bool firstColumnFound = false;
			getline(fin, hold);

			// looks through each row to find the first and last columns with an x
			for (int j = 0; j < columns; j++)
			{

				int firstColumnTemp = 9999, lastColumnTemp = 0;

				if ((hold[j] == 'x') && firstColumnFound == false)
				{
					firstColumnTemp = j;
					firstColumnFound = true;
					lastColumnTemp = j;
				}
				else if (hold[j] == 'x')
				{
					lastColumnTemp = j;
				}

				if (firstColumnTemp < firstColumn && firstColumnTemp != 9999)
				{
					firstColumn = firstColumnTemp;
				}

				if (lastColumnTemp > lastColumn)
				{
					lastColumn = lastColumnTemp;
				}
			}


			// the logic for deciding which is the first and last rows to contain an x
			if (firstColumnFound && firstRowFound == false)
			{
				firstRow = r;
				firstRowFound = true;
			}
			else if (firstColumnFound && firstRowFound == true)
			{
				lastRow = r;
			}
		}


		// the number of rows and columns is just bottom minus top and right minus left
		if (firstColumn == 9999)
			firstColumn = 0;

		// +1 in each case since the value is inclusize
		ColumnsToBeFenced = (lastColumn - firstColumn + 1);
		rowsToBeFenced = (lastRow - firstRow + 1);

		// displaying the results
		cout << endl << "Case " << i + 1 << ": " << rowsToBeFenced << " " << ColumnsToBeFenced;
	}


	// closing the file
	fin.close();
}