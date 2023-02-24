// Josiah Larimer
// COSC 2436
// Program Set 1
// 
// used https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/ to learn how to use rand() and srand()
// viewed the MinRectangles.cpp you posted in the assignment page

#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

using namespace std;



// a structure that holds a lot of the important information about the matrix, including the 2d array itself
// this way I can pass and modify a large amount of data with just one variable
struct matrix {

	int s_numCols;
	int s_numRows;
	int s_matrix[5][5];

	// constructor for if passed the number of columns and rows
	matrix(int c_cols, int c_rows) {
		s_numCols = c_cols;
		s_numRows = c_rows;
	}

	// default constructor for if nothing is passed
	matrix() {}


	// it isn't neccessary that this be part of the structure, but since it is intended to 
	// manipulate data that is part of the structure I included it
	int value() {	// fills the matrix with a 1 or 0 randomly

		int oneOrZero;

		// if the number is even it is passed as a 0, and if it is odd it is returned as a 1
		if ((rand() % 2) == 0)
			oneOrZero = 0;
		else
			oneOrZero = 1;

		return oneOrZero;

	}


	// creates the 2d matrix and then uses the above value() function to fill each element with a 1 or 0
	void instantiate(matrix& i_matrix) {

		for (int i = 0; i < i_matrix.s_numRows; i++)
		{
			for (int j = 0; j < i_matrix.s_numCols; j++)
			{
				i_matrix.s_matrix[i][j] = i_matrix.value();
			}
		}

	}

};


// function prototypes
void printMatrix(matrix);
int getMaxWidth(matrix&, int, int);


// this funtion is very shy due to how ugly it is
// please don't look at it for too long
// this is the function that does the lions share of the calculations
void calcArea(matrix& mat, int i, int j, int& numPoints)
{

	int j2 = j;
	int i2 = i;
	string rectCase = "none"; // this exists to keep track of what kind of rectangle we are working with
	int numOfOnes = 0; // keeps track of how many ones are in a rectangle, used to calculate how many cases should be truncated when calculating area

	// gets the width
	int w = getMaxWidth(mat, i, j);

	do {
		i2++;
	} while (mat.s_matrix[i2][j2] == 1 || mat.s_matrix[i2][j2] == 2);
	int maxHeight = (i2 - i);

	int maxArea = maxHeight * w;

	// calulates how many 1s were overwritten
	if (maxArea == 2 || maxArea == 4 || maxArea == 8) {
		numOfOnes--;	// the negative iteration is required for the math to work out
		for (int i3 = i; i3 < i + maxHeight; i3++) {
			for (int j3 = j; j3 < j + w; j3++) {
				if (mat.s_matrix[i3][j3] == 1)
					numOfOnes++;
			}
		}
	}


	// might be used if I want to introduce different ways to process everything
	bool normalComputation = true;

	// the standard style of processing the rectangles
	if (normalComputation == true)
	{
		// cases where area neatly fits into powers of two
		// each statement turns the points of interest to twos and records the type of rectangle for debugging purposes
		// have introduced wraparound statements for 1x1
		if (maxHeight == 1 && w == 1)
		{
			mat.s_matrix[i][j] = 2;
			rectCase = "1x1";
			// a very crude method of reaching around the matrix to look for another 1 under very specific circumstances
			if ((w == 1 && mat.s_numCols > 2) || (w == 3 && mat.s_numCols > 4))
			{
				if (j == 0 && mat.s_matrix[i][mat.s_numCols - 1] == 1)
				{
					mat.s_matrix[i][mat.s_numCols - 1] = 2;
					numOfOnes++;
					rectCase = "wraparound horizontally";
				}
			}
		}
		else if (maxHeight == 2 && w == 1)
		{
			mat.s_matrix[i][j] = 2;
			mat.s_matrix[i + 1][j] = 2;
			rectCase = "2x1";
		}
		else if (maxHeight == 1 && w == 2)
		{
			mat.s_matrix[i][j] = 2;
			mat.s_matrix[i][j + 1] = 2;
			rectCase = "1x2";
		}
		else if (maxHeight == 2 && w == 2)
		{
			if (mat.s_matrix[i + 1][j + 1] == 1 || mat.s_matrix[i + 1][j + 1] == 2)
			{
				mat.s_matrix[i][j] = 2;
				mat.s_matrix[i][j + 1] = 2;
				mat.s_matrix[i + 1][j] = 2;
				mat.s_matrix[i + 1][j + 1] = 2;
				rectCase = "2x2 : standard";
			}
			else if (mat.s_matrix[i + 1][j + 1] == 0)
			{
				mat.s_matrix[i][j] = 2;
				mat.s_matrix[i][j + 1] = 2;
				mat.s_matrix[i + 1][j] = 2;
				rectCase = "2x2 : 2x1 && 1x2";
				numOfOnes--;	// to account for the fact that it is really two 2x1 rectangles
			}
		}
		else if (maxHeight == 4 && w == 1)
		{
			mat.s_matrix[i][j] = 2;
			mat.s_matrix[i + 1][j] = 2;
			mat.s_matrix[i + 2][j] = 2;
			mat.s_matrix[i + 3][j] = 2;
			rectCase = "4x1";
		}
		else if (maxHeight == 1 && w == 4)
		{
			mat.s_matrix[i][j] = 2;
			mat.s_matrix[i][j + 1] = 2;
			mat.s_matrix[i][j + 2] = 2;
			mat.s_matrix[i][j + 3] = 2;
			rectCase = "1x4";
		}
		else if (maxHeight == 4 && w == 2)
		{
			mat.s_matrix[i][j] = 2;
			mat.s_matrix[i + 1][j] = 2;
			mat.s_matrix[i + 2][j] = 2;
			mat.s_matrix[i + 3][j] = 2;
			mat.s_matrix[i][j + 1] = 2;
			mat.s_matrix[i + 1][j + 1] = 2;
			mat.s_matrix[i + 2][j + 1] = 2;
			mat.s_matrix[i + 3][j + 1] = 2;
			rectCase = "4x2";
		}
		else if (maxHeight == 2 && w == 4)
		{
			mat.s_matrix[i][j] = 2;
			mat.s_matrix[i][j + 1] = 2;
			mat.s_matrix[i][j + 2] = 2;
			mat.s_matrix[i][j + 3] = 2;
			mat.s_matrix[i + 1][j] = 2;
			mat.s_matrix[i + 1][j + 1] = 2;
			mat.s_matrix[i + 1][j + 2] = 2;
			mat.s_matrix[i + 1][j + 3] = 2;
			rectCase = "2x4";
		}
		else if (maxHeight == 4 && w == 4)
		{

			for (int i3 = i; i3 < 4; i3++) {
				for (int j3 = j; j3 < 4; j3++) {

					mat.s_matrix[i3][j3] = 2;
				}
			}
			rectCase = "4x4";
		}

		// cases where I want something to happen despite not being a power of two
		if (maxHeight == 3 && w == 2)
		{
			if (mat.s_matrix[i + 1][j + 1] == 1 || mat.s_matrix[i + 1][j + 1] == 2)
			{
				mat.s_matrix[i][j] = 2;
				mat.s_matrix[i][j + 1] = 2;
				mat.s_matrix[i + 1][j] = 2;
				mat.s_matrix[i + 1][j + 1] = 2;
				rectCase = "2x2 : semi-standard 3x2";
				numOfOnes--;
				for (int i3 = i; i3 < i + 2; i3++) {
					for (int j3 = j; j3 < i + 2; j3++) {
						if (mat.s_matrix[i3][j3] == 1)
							numOfOnes++;
					}
				}
			}
			else if (mat.s_matrix[i + 1][j + 1] == 0)
			{
				if (mat.s_matrix[i][j + 1] == 1)
					numOfOnes++;
				mat.s_matrix[i][j] = 2;
				mat.s_matrix[i][j + 1] = 2;
				rectCase = "1x2 : non-standard 3x2";
			}
		}

	}


	// these lines print various features of the logic for debugging purposes
	/*
	cout << "maxHeight: " << maxHeight;
	cout << " (" << i << ", " << j << ") : 0" << endl;

	cout << "rectCase: " << rectCase;
	cout << " (" << i << ", " << j << ") : 0" << endl;
	*/


	// the second line subtracts however many points of interest that are accounted for by the chosen rectangle\
	cout << "numPoints--  " << numOfOnes << "  (" << i << ", " << j << ")" << endl;
	numPoints -= numOfOnes;		// a very important line
}


// calculates how many continuous 1s there are from the starting point to the end of the row
int getMaxWidth(matrix& mat, int i, int j)
{
	int j2 = j;

	do {
		j2++;
	} while (mat.s_matrix[i][j2] == 1 || mat.s_matrix[i][j2] == 2);


	int maxWidth = j2 - j;

	// prints the value for maxWidth for debugging purposes\
	cout << "maxWidth: " << maxWidth << " (" << i << ", " << j << ")" << endl;
	return maxWidth;
}


// the first function called from main(), it mostly just calls other functions
// I am really proud that this only has to be passed one variable
int minRectangles(matrix mat) {

	int numPoints = 0, numRectangles = 0;

	// how many 1s there are in the matrix
	// I subtract from this number to decide how many rectangles will be formed
	for (int i = 0; i < mat.s_numRows; i++)
	{
		int count = 0, s_rCount = 0, s_cCount = 0;
		for (int j = 0; j < mat.s_numCols; j++)
		{
			if (mat.s_matrix[i][j] == 1)
			{
				numPoints++;
			}
		}
	}

	// I found it helpful for my sanity to have the various for loops in different functions, 
	// instead of having a huge function with something like a 6 layered for loop
	for (int i = 0; i < mat.s_numRows; i++)
	{
		int count = 0, s_rCount = 0, s_cCount = 0;
		for (int j = 0; j < mat.s_numCols; j++)
		{
			if (mat.s_matrix[i][j] == 1)
			{
				// for each point of interest (ie. there is a 1), calculate the area and print the updated matrix
				calcArea(mat, i, j, numPoints);
				//printMatrix(mat);
				//cout << endl;
			}
		}
	}

	return numPoints;
}


// prints the matrix that was passed to it
void printMatrix(matrix mat) {

	cout << endl << "Generated grid: " << endl << endl;
	for (int i = 0; i < mat.s_numRows; i++)
	{
		for (int j = 0; j < mat.s_numCols; j++)
		{
			cout << mat.s_matrix[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {


	srand(time(0));		// seeds the random number generator

	bool cont = true;
	do
	{
		// get input
		int numRows, numCols;

		cout << endl << "Enter the number of rows (2 - 5): ";
		cin >> numRows;
		cout << "Enter the number of cols (2 - 5): ";
		cin >> numCols;


		// error checking input size
		if ((numRows > 5 || numRows < 2) || (numCols > 5 || numCols < 2))
		{
			cout << "ERROR: the value entered is outside of the accepted range (2 - 5)" << endl;
			return 1;
		}


		// creating the myMatrix object and filling the 2d array
		matrix myMatrix(numCols, numRows);
		//cout << "numsRows: " << myMatrix.s_numRows << " numCols: " << myMatrix.s_numCols << endl;
		myMatrix.instantiate(myMatrix);


		// this allows for the entering  of a custom matrix for error testing purposes
		// the custom matrix must be the same dimensions as initially indicated by the users input
		/*
		char qur;
		cout << "would you like to rewrite the matrix?" << endl;
		cin >> qur;
		if (qur == 'y')
		{
			cout << endl;
			for (int i = 0; i < myMatrix.s_numRows; i++)
			{
				for (int j = 0; j < myMatrix.s_numCols; j++)
				{
					cin >> myMatrix.s_matrix[i][j];
				}
			}
		}
		*/

		// printing the matrix
		printMatrix(myMatrix);

		// outputing the results
		cout << endl << "The least number of rectangles/squares formed is " << endl;
		cout << endl << minRectangles(myMatrix);
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
