// Josiah Larimer
// COSC 2425
// Program Set 1
// 
// this program is kind of an amalgamation of the twos complement program, the comprehensive problem, and the EC fencing problem from 2436
//

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// keeps track of what base each line should be in 
// can handle files up to 256 lines long
int base[] = {2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2,
3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 
5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5,
7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7,
2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2,
3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3,
5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7, 2, 3, 5, 7};


// takes in a single line of text from the file, and then encodes it in the passed base and prints each character
void toBaseN(int y, string line) {

    int x, t;    
    int strlenS1 = strlen(line.c_str());

    for (int k = 0; k < strlenS1; k++)
    {

        x = int(line[k]);

        t = 1;
        while (x >= t * y)
        {
            t = t * y;
        }

        while (t)
        {
            cout << x / t;
            x -= t * (x / t);
            t /= y;
        }
              
        // print '_' unless it is the last character
        if (k != strlenS1 -1)
            cout << '_';
    }
}


int main() {

    int numberOfCases = 0;		// how many cases are to be computed
    string numberOfCasesString;	// holds the string values of cases

    // getting the filename from the user
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    cout << endl << "Message:\n\n";

    // opening file
    string ch;
    fstream fin(filename, fstream::in);

    // getting how many cases there are from the file
    getline(fin, numberOfCasesString);
    numberOfCases = stoi(numberOfCasesString);

    // this runs once for each case there is
    for (int i = 0; i < numberOfCases; i++)
    {
        // what number base the line should be encoded in
        int y = base[i];

        // getting the line
        string line;
        getline(fin, line);

        // passing the line to the encoder
        toBaseN(y, line);
        cout << endl;
    }
}