// Josiah Larimer
// COSC 2436
// program set 3
#include<iostream>

using namespace std;



// draws each row
void drawLine(int x, int y, int size)
{
	if (y == size)
	{
		cout << endl;
		return;
	}


	// decides whether an X or a space is printed
	if (
		   (x == 0 || x == size - 1) 
		|| (y == 0 || y == size - 1) 
		|| ((x == 2 || x == size - 3) && !(y == 1 || y == size - 2))
		|| ((size > 6) && ((y == 2 || y == size - 3) && !(x == 1 || x == size - 2)))
		|| ((size > 8) && ((y == 4 || y == size - 5) && !(x == 1 || x == 3 || x == size - 2 || x == size - 4)))
		|| ((size > 10) && (( y == 6 || y == size - 7) && !(x == 1 || x == 3 || x == 5|| x == size - 2 || x == size - 4 || x == size - 6)))
		|| ((size > 10) && (( x == 4) || x == size - 5) && !(y == 1 || y == size - 2 || y == 3 || y == size - 4))		
		|| (( size > 14) && (( y == 8 || y == size - 9) && !(x == 1 || x == 3 || x == 5 || x == 7|| x == size - 2 || x == size - 4 || x == size - 6 || x == size - 8)))
		|| (( size > 14) && ((x == 6 || x == size - 7) && !(y == 1 || y == size - 2 || y == 3 || y == size - 4 || y == 5 || y == size - 6)))
		|| (( size > 18) && ((y == 9 || y == size - 10 ) && !(x == 1 || x == 3 || x == 5 || x == 7 || x == size - 2 || x == size - 4 || x == size - 6 || x == size - 8 || x ==9 || x == size - 10)))
	   )
	{
		cout << 'X';
		y++;
		drawLine(x, y, size); // RECURSION!!!!!
	}
	else
	{
		cout << ' ';
		y++;
		drawLine(x, y, size); // RECURSION!!!!!
	}

}



int main() {


	bool cont = true;
	
	do
	{
		// getting input
		int numSquares = 0;
		cout << "\nEnter size [5-20]: ";
		cin >> numSquares;
		cout << endl;

		// error checking the input
		if (numSquares < 5 || numSquares > 20)
		{
			cout << "ERROR: That was outside the range of acceptable inputs [5-20]";
			return 1;
		}


		// calls the recursive function drawLine for each row
		for (int x = 0; x < numSquares; x++)
		{
			drawLine(x, 0, numSquares);

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
