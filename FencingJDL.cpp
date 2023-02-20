#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main() {


	int numberOfCases = 0;		// how many cases are to be computed
	string numberOfCasesString;	// holds the string values of cases


	// getting filename from the user
	string filename;
	// cout << "Enter the file name: "; //should always be fence.txt
	// cin >> filename;
	filename = "fence.txt";


	// opening file
	string ch;
	fstream fin(filename, fstream::in);
	

	// getting how many cases there are from the file
	getline(fin, numberOfCasesString);
	numberOfCases = stoi(numberOfCasesString);
	cout << numberOfCases << endl << endl << endl;


	//fileArrayFiller(numRows, numColumns, fin);

	//cin >> ch;


	for (int i = 0; i < numberOfCases; i++)
	{




		// getting the number of rows and columns
		string rowsColumns;
		getline(fin, rowsColumns);
		
		int rows, columns;

		rows = int(rowsColumns[0] - 48);
		columns = int(rowsColumns[2] - 48);
		//cout << rows << " " << columns;


		bool firstColumnFound = false;
		int columnsToBeFenced = 0, firstColumn = 0, lastColumn = 0;
		int rowsToBeFenced = 0;
		string hold;

		int firstRow = 9999, lastRow = 0;


		for (int r = 0; r < rows ; r++)
		{
			

			bool firstRowFound = false;
			getline(fin, hold);
			
			// (number of rows to be fenced) = (last rows with X - first row with X)
			

			for (int j = 0; j < columns; j++)
			{

				int firstRowTemp = 9999, lastRowTemp = 0;


				if ((hold[j] == 'x') && firstRowFound == false)
				{
					firstRowTemp = j;
					firstRowFound = true;
					//cout << "firstRow: /n" << j << endl;
					
					lastRowTemp = j;
					
			
				}
				else if (hold[j] == 'x')
				{
					lastRowTemp = j;
			
					//cout << "lastRow: \n" << j << endl;

				
				}
				//else
					//cout << "		round r= " << r << " and j= " << j << " " << hold[j] << endl;
				//(number of columns to be fenced) = (last column with X - first column with X)
				
				if (firstRowTemp < firstRow && firstRowTemp != 9999)
				{
					firstRow = firstRowTemp;
					//cout << "first column in row " << r << " is " << j << endl;
				}
				if (lastRowTemp > lastRow)
				{
					lastRow = lastRowTemp;
					//cout << "last column in row " << r << " is " << j << endl;
				}
				

			}

			if (firstRowFound && firstColumnFound == false)
			{
				firstColumn = r;
				//cout << "first row is " << firstColumn << endl;
				firstColumnFound = true;
			}
			else if (firstRowFound && firstColumnFound == true)
			{
				lastColumn = r;
				//cout << "last row is " << lastColumn << endl;
			}



		}

		if (firstRow == 9999)
			firstRow = 0;
		rowsToBeFenced = (lastRow - firstRow);
		//cout <<endl<< "last colomn is " << lastRow << " first column is " << firstRow;
				
		columnsToBeFenced = (lastColumn - firstColumn);

		//cout << endl << "last row is " << lastColumn << " first row is " << firstColumn;



	//	if (firstRow == 0)
			rowsToBeFenced++;
		//if (firstColumn == 0)
		    columnsToBeFenced++;


	//	if (rowsToBeFenced == 0)
	//		rowsToBeFenced = 1;
	//	if (columnsToBeFenced == 0)
	//		columnsToBeFenced = 1;


		cout << endl << "Case " << i + 1 << ": " << columnsToBeFenced << " " << rowsToBeFenced <<endl;


	}





	// write something to close the file






}

// check for columns

// check for rows






/*
void fileArrayFiller(int numRows, int numColumns, fstream fin) {

	string rowsAndColumns[8];


	for (int i = 0 ; i < numRows ; i++)
		fin >> rowsAndColumns[i];

	for (int j = 0; j < numRows; j++)
	{

		for (int i = 0; i < numColumns ; i++)
		{

			cout << rowsAndColumns[j][i];

		}

	}
}
*/
