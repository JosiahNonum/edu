// Josiah Larimer
// COSC 2436
// Programming Set 1
// 
// I've left a lot of the debugging stuff in the code

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main() {


	int numberOfCases = 0;		// how many cases are to be computed
	string numberOfCasesString;	// holds the string values of cases


	// getting filename from the user
	string filename;
	// cout << "Enter the file name: ";
	// cin >> filename;
	filename = "fence.txt";


	// opening file
	string ch;
	fstream fin(filename, fstream::in);


	// getting how many cases there are from the file
	getline(fin, numberOfCasesString);
	numberOfCases = stoi(numberOfCasesString);
	cout << numberOfCases << endl << endl << endl;


	// this runs once for each case there is
	for (int i = 0; i < numberOfCases; i++)
	{

		// getting the number of rows and columns
		string rowsColumns;
		getline(fin, rowsColumns);

		int rows, columns;

		rows = int(rowsColumns[0] - 48);
		columns = int(rowsColumns[2] - 48);
		//cout << rows << " " << columns;


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
					//cout << "firstRow: /n" << j << endl;

					lastColumnTemp = j;
				}
				else if (hold[j] == 'x')
				{
					lastColumnTemp = j;
					//cout << "lastRow: \n" << j << endl;
				}

				if (firstColumnTemp < firstColumn && firstColumnTemp != 9999)
				{
					firstColumn = firstColumnTemp;
					//cout << "first column in row " << r << " is " << j << endl;
				}
				if (lastColumnTemp > lastColumn)
				{
					lastColumn = lastColumnTemp;
					//cout << "last column in row " << r << " is " << j << endl;
				}
			}


			// the logic for deciding which is the first and last rows to contain an x
			if (firstColumnFound && firstRowFound == false)
			{
				firstRow = r;
				//cout << "first row is " << firstColumn << endl;
				firstRowFound = true;
			}
			else if (firstColumnFound && firstRowFound == true)
			{
				lastRow = r;
				//cout << "last row is " << lastColumn << endl;
			}

		}



		// the number of rows and columns is just bottom minus top and right minus left
		if (firstColumn == 9999)
			firstColumn = 0;
		ColumnsToBeFenced = (lastColumn - firstColumn);
		//cout <<endl<< "last colomn is " << lastColumn << " first column is " << firstColumn;

		rowsToBeFenced = (lastRow - firstRow);
		//cout << endl << "last row is " << lastRow << " first row is " << firstRow;

		ColumnsToBeFenced++;
		rowsToBeFenced++;

		cout << endl << "Case " << i + 1 << ": " << rowsToBeFenced << " " << ColumnsToBeFenced << endl;
	}

	// closing the file
	fin.close();
}